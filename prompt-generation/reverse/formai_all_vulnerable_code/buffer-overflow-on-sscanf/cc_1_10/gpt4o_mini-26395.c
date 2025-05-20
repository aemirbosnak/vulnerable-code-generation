//GPT-4o-mini DATASET v1.0 Category: Data mining ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CUSTOMERS 100
#define MAX_LINE_LENGTH 256

typedef struct {
    int customerId;
    double totalSpent;
    int purchaseCount;
} Customer;

void processCustomerData(const char *filename, Customer customers[], int *customerCount) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Unable to open file");
        exit(EXIT_FAILURE);
    }

    char line[MAX_LINE_LENGTH];
    fgets(line, sizeof(line), file); // Skip header line

    while (fgets(line, sizeof(line), file)) {
        int customerId;
        double purchaseAmount;
        sscanf(line, "%d,%lf", &customerId, &purchaseAmount);

        // Check if customer already exists
        int found = 0;
        for (int i = 0; i < *customerCount; i++) {
            if (customers[i].customerId == customerId) {
                customers[i].totalSpent += purchaseAmount;
                customers[i].purchaseCount++;
                found = 1;
                break;
            }
        }

        // If not found, create a new customer
        if (!found) {
            customers[*customerCount].customerId = customerId;
            customers[*customerCount].totalSpent = purchaseAmount;
            customers[*customerCount].purchaseCount = 1;
            (*customerCount)++;
        }
    }

    fclose(file);
}

void writeCustomerSummary(const char *outputFilename, Customer customers[], int customerCount) {
    FILE *file = fopen(outputFilename, "w");
    if (!file) {
        perror("Unable to open output file");
        exit(EXIT_FAILURE);
    }

    fprintf(file, "CustomerID,TotalSpent,AverageSpent\n");
    for (int i = 0; i < customerCount; i++) {
        double averageSpent = customers[i].totalSpent / customers[i].purchaseCount;
        fprintf(file, "%d,%.2f,%.2f\n", customers[i].customerId, customers[i].totalSpent, averageSpent);
    }

    fclose(file);
}

int main() {
    Customer customers[MAX_CUSTOMERS];
    int customerCount = 0;

    processCustomerData("customer_data.csv", customers, &customerCount);
    writeCustomerSummary("customer_summary.csv", customers, customerCount);

    printf("Customer summary has been written to customer_summary.csv\n");

    return 0;
}
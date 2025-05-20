//MISTRAL-7B DATASET v1.0 Category: Data mining ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FIELDS 10
#define MAX_FIELD_LEN 50
#define MAX_LINES 1000

typedef struct {
    char name[MAX_FIELD_LEN];
    float spending;
} Customer;

int main() {
    FILE *inputFile, *outputFile;
    Customer customers[MAX_LINES];
    int numCustomers = 0;

    inputFile = fopen("customers.csv", "r");
    if (inputFile == NULL) {
        fprintf(stderr, "Error: Unable to open input file.\n");
        return 1;
    }

    outputFile = fopen("averages.csv", "w");
    if (outputFile == NULL) {
        fprintf(stderr, "Error: Unable to open output file.\n");
        fclose(inputFile);
        return 1;
    }

    while (fscanf(inputFile, "%[^,],%f", customers[numCustomers].name, &customers[numCustomers].spending) != EOF) {
        numCustomers++;
    }

    fprintf(outputFile, "Customer Name,Average Spending\n");
    for (int i = 0; i < numCustomers; i++) {
        float sum = 0;
        for (int j = 0; j < numCustomers; j++) {
            sum += customers[j].spending;
        }
        float avgSpending = sum / numCustomers;
        fprintf(outputFile, "%s,%.2f\n", customers[i].name, avgSpending);
    }

    fclose(inputFile);
    fclose(outputFile);

    return 0;
}
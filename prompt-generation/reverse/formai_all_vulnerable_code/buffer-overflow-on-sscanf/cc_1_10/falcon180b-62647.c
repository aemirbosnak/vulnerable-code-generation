//Falcon-180B DATASET v1.0 Category: Personal Finance Planner ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>

// Define the structure for a transaction
typedef struct {
    char date[11];
    char description[51];
    float amount;
} transaction;

// Function to print a transaction
void print_transaction(transaction t) {
    printf("Date: %s\nDescription: %s\nAmount: $%.2f\n", t.date, t.description, t.amount);
}

// Function to read transactions from a file
void read_transactions(FILE *file, transaction *transactions, int *count) {
    char line[1024];
    while (fgets(line, sizeof(line), file)!= NULL) {
        sscanf(line, "%s %s $%f", transactions[*count].date, transactions[*count].description, &transactions[*count].amount);
        (*count)++;
    }
}

// Function to write transactions to a file
void write_transactions(FILE *file, transaction *transactions, int count) {
    for (int i = 0; i < count; i++) {
        fprintf(file, "%s %s $%.2f\n", transactions[i].date, transactions[i].description, transactions[i].amount);
    }
}

// Function to calculate the total amount spent in a category
float calculate_total(transaction *transactions, int count, char *category) {
    float total = 0;
    for (int i = 0; i < count; i++) {
        if (strcmp(transactions[i].description, category) == 0) {
            total += transactions[i].amount;
        }
    }
    return total;
}

int main() {
    // Initialize variables
    transaction transactions[100];
    int count = 0;
    char filename[51] = "transactions.txt";
    char category[51];

    // Read transactions from file
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Unable to open file.\n");
        return 1;
    }
    read_transactions(file, transactions, &count);
    fclose(file);

    // Print all transactions
    printf("All Transactions:\n");
    for (int i = 0; i < count; i++) {
        print_transaction(transactions[i]);
    }

    // Prompt user for category to calculate total
    printf("\nEnter a category to calculate total amount spent:\n");
    scanf("%s", category);

    // Calculate and print total amount spent in category
    float total = calculate_total(transactions, count, category);
    printf("\nTotal amount spent in %s: $%.2f\n", category, total);

    return 0;
}
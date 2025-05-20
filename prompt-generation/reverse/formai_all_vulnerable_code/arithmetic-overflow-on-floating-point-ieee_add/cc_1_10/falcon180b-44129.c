//Falcon-180B DATASET v1.0 Category: Personal Finance Planner ; Style: beginner-friendly
#include <stdio.h>

// Define a structure to store transaction information
typedef struct {
    char date[10];
    char description[50];
    float amount;
    char category[20];
} Transaction;

// Function to print a transaction
void printTransaction(Transaction t) {
    printf("%s - %s - $%.2f - %s\n", t.date, t.description, t.amount, t.category);
}

// Function to add a transaction
void addTransaction(Transaction* transactions, int size, int* count, Transaction t) {
    if (*count == size) {
        printf("Error: Transaction list is full.\n");
        return;
    }
    transactions[*count] = t;
    (*count)++;
}

// Function to delete a transaction
void deleteTransaction(Transaction* transactions, int size, int* count, int index) {
    if (index >= *count) {
        printf("Error: Invalid transaction index.\n");
        return;
    }
    for (int i = index; i < *count - 1; i++) {
        transactions[i] = transactions[i + 1];
    }
    (*count)--;
}

// Function to display all transactions
void displayTransactions(Transaction* transactions, int count) {
    printf("Transactions:\n");
    for (int i = 0; i < count; i++) {
        printTransaction(transactions[i]);
    }
}

// Function to calculate total income and expenses
float calculateTotal(Transaction* transactions, int count) {
    float totalIncome = 0.0;
    float totalExpenses = 0.0;
    for (int i = 0; i < count; i++) {
        if (strcmp(transactions[i].category, "Income") == 0) {
            totalIncome += transactions[i].amount;
        } else {
            totalExpenses += transactions[i].amount;
        }
    }
    return totalIncome - totalExpenses;
}

int main() {
    Transaction transactions[10];
    int transactionCount = 0;

    // Add some sample transactions
    addTransaction(transactions, 10, &transactionCount, (Transaction){
       .date = "2021-01-01",
       .description = "Salary",
       .amount = 3000.00,
       .category = "Income"
    });
    addTransaction(transactions, 10, &transactionCount, (Transaction){
       .date = "2021-01-05",
       .description = "Groceries",
       .amount = 150.00,
       .category = "Expense"
    });
    addTransaction(transactions, 10, &transactionCount, (Transaction){
       .date = "2021-01-10",
       .description = "Rent",
       .amount = 1000.00,
       .category = "Expense"
    });

    // Display all transactions
    displayTransactions(transactions, transactionCount);

    // Calculate total income and expenses
    float total = calculateTotal(transactions, transactionCount);
    printf("Total Income: $%.2f\n", total);

    return 0;
}
//Falcon-180B DATASET v1.0 Category: Personal Finance Planner ; Style: immersive
#include <stdio.h>
#include <stdlib.h>

// Define structure for transactions
struct transaction {
    char description[50];
    float amount;
    char category[20];
};

// Function to add transaction
void addTransaction(struct transaction* t) {
    printf("Enter transaction description: ");
    scanf("%s", t->description);
    printf("Enter transaction amount: ");
    scanf("%f", &t->amount);
    printf("Enter transaction category: ");
    scanf("%s", t->category);
}

// Function to display transactions
void displayTransactions(struct transaction* t, int n) {
    printf("\nTransactions:\n");
    for (int i = 0; i < n; i++) {
        printf("%s | $%.2f | %s\n", t[i].description, t[i].amount, t[i].category);
    }
}

// Function to calculate total income and expenses
float calculateTotal(struct transaction* t, int n) {
    float total = 0.0;
    for (int i = 0; i < n; i++) {
        if (strcmp(t[i].category, "Income") == 0) {
            total += t[i].amount;
        } else if (strcmp(t[i].category, "Expense") == 0) {
            total -= t[i].amount;
        }
    }
    return total;
}

int main() {
    int n;
    printf("Enter number of transactions: ");
    scanf("%d", &n);
    struct transaction t[n];

    // Add transactions
    for (int i = 0; i < n; i++) {
        addTransaction(&t[i]);
    }

    // Display transactions
    displayTransactions(t, n);

    // Calculate total income and expenses
    float total = calculateTotal(t, n);
    printf("\nTotal Income: $%.2f\n", total);

    return 0;
}
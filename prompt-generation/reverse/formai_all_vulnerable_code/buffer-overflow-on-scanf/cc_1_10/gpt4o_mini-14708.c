//GPT-4o-mini DATASET v1.0 Category: Personal Finance Planner ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

#define MAX_ENTRIES 100

typedef struct {
    char name[50];
    float amount;
    char category[50];
} Transaction;

void addTransaction(Transaction transactions[], int *count) {
    if (*count >= MAX_ENTRIES) {
        printf("Transaction limit reached!\n");
        return;
    }
    
    printf("Enter transaction name: ");
    scanf("%s", transactions[*count].name);
    printf("Enter transaction amount: ");
    scanf("%f", &transactions[*count].amount);
    printf("Enter transaction category: ");
    scanf("%s", transactions[*count].category);
    
    (*count)++;
    printf("Transaction added successfully!\n");
}

void displayTransactions(Transaction transactions[], int count) {
    if (count == 0) {
        printf("No transactions to display.\n");
        return;
    }
    
    printf("\nTransaction List:\n");
    for (int i = 0; i < count; i++) {
        printf("Transaction %d: Name: %s, Amount: %.2f, Category: %s\n", 
                i + 1, transactions[i].name, transactions[i].amount, transactions[i].category);
    }
}

void calculateTotal(Transaction transactions[], int count) {
    float total = 0.0;
    for (int i = 0; i < count; i++) {
        total += transactions[i].amount;
    }
    printf("Total amount spent: %.2f\n", total);
}

void categorizeExpenses(Transaction transactions[], int count) {
    float totalAmount[10] = {0};
    int categoryCount = 0;

    printf("Categorizing expenditures...\n");
    
    for (int i = 0; i < count; i++) {
        int found = 0;
        for (int j = 0; j < categoryCount; j++) {
            if (strcmp(transactions[i].category, transactions[j].name) == 0) {
                totalAmount[j] += transactions[i].amount;
                found = 1;
                break;
            }
        }
        if (!found) {
            strcpy(transactions[categoryCount].name, transactions[i].category);
            totalAmount[categoryCount] = transactions[i].amount;
            categoryCount++;
        }
    }
    
    printf("\nExpenses by Category:\n");
    for (int i = 0; i < categoryCount; i++) {
        printf("Category: %s, Total: %.2f\n", transactions[i].name, totalAmount[i]);
    }
}

int main() {
    Transaction transactions[MAX_ENTRIES];
    int count = 0;
    int choice;

    do {
        printf("\nPersonal Finance Planner");
        printf("\n1. Add Transaction");
        printf("\n2. Display Transactions");
        printf("\n3. Calculate Total Expenses");
        printf("\n4. Categorize Expenses");
        printf("\n5. Exit");
        printf("\nChoose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addTransaction(transactions, &count);
                break;
            case 2:
                displayTransactions(transactions, count);
                break;
            case 3:
                calculateTotal(transactions, count);
                break;
            case 4:
                categorizeExpenses(transactions, count);
                break;
            case 5:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid option! Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}
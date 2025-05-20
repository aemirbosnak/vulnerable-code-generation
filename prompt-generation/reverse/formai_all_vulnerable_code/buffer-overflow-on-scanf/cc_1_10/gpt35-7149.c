//FormAI DATASET v1.0 Category: Expense Tracker ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TRANSACTIONS 1000
#define MAX_CATEGORY_LEN 50

typedef struct {
    float amount;
    char category[MAX_CATEGORY_LEN];
    char details[100];
} transaction;

void add_transaction(transaction* transactions, int* num_transactions) {
    float amount;
    char category[MAX_CATEGORY_LEN];
    char details[100];
    
    printf("Enter amount: ");
    scanf("%f", &amount);
    
    printf("Enter category: ");
    scanf("%s", category);
    
    printf("Enter details: ");
    scanf("%s", details);
    
    transaction t = {amount, category, details};
    
    transactions[(*num_transactions)++] = t;
}

void print_transactions(transaction* transactions, int num_transactions) {
    printf("Transactions:\n");
    for (int i = 0; i < num_transactions; i++) {
        transaction t = transactions[i];
        printf("Amount: %.2f, Category: %s, Details: %s\n", t.amount, t.category, t.details);
    }
}

float calculate_total(transaction* transactions, int num_transactions) {
    float total = 0;
    for (int i = 0; i < num_transactions; i++) {
        total += transactions[i].amount;
    }
    return total;
}

float calculate_category_total(transaction* transactions, int num_transactions, char* category) {
    float total = 0;
    for (int i = 0; i < num_transactions; i++) {
        if (strcmp(transactions[i].category, category) == 0) {
            total += transactions[i].amount;
        }
    }
    return total;
}

int main() {
    transaction transactions[MAX_TRANSACTIONS];
    int num_transactions = 0;
    int choice = 0;
    
    while (1) {
        printf("Enter 1 to add transaction\n");
        printf("Enter 2 to view all transactions\n");
        printf("Enter 3 to view total amount spent\n");
        printf("Enter 4 to view total amount spent in a category\n");
        printf("Enter 5 to exit\n");
        printf("Choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                add_transaction(transactions, &num_transactions);
                break;
            case 2:
                print_transactions(transactions, num_transactions);
                break;
            case 3:
                printf("Total amount spent: %.2f\n", calculate_total(transactions, num_transactions));
                break;
            case 4: {
                char category[MAX_CATEGORY_LEN];
                printf("Enter category: ");
                scanf("%s", category);
                printf("Total amount spent in category %s: %.2f\n", category, calculate_category_total(transactions, num_transactions, category));
                break;
            }
            case 5:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    
    return 0;
}
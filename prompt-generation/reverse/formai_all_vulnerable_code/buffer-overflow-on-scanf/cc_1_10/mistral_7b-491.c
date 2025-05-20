//MISTRAL-7B DATASET v1.0 Category: Personal Finance Planner ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    float amount;
} Transaction;

void add_transaction(Transaction transactions[], int* size, char* description, float amount);
void print_transactions(Transaction transactions[], int size);

int main() {
    Transaction transactions[10];
    int size = 0;

    while (1) {
        printf("\n1. Add transaction\n2. Print transactions\n3. Quit\nEnter your choice: ");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                char description[50];
                float amount;
                printf("Enter transaction description: ");
                scanf("%s", description);
                printf("Enter transaction amount: ");
                scanf("%f", &amount);
                add_transaction(transactions, &size, description, amount);
                break;
            }
            case 2: {
                print_transactions(transactions, size);
                break;
            }
            case 3: {
                printf("Quitting...\n");
                exit(0);
            }
            default: {
                printf("Invalid choice! Try again.\n");
            }
        }
    }

    return 0;
}

void add_transaction(Transaction transactions[], int* size, char* description, float amount) {
    if (*size >= 10) {
        printf("Transaction limit reached!\n");
        return;
    }

    strcpy(transactions[*size].name, description);
    transactions[*size].amount = amount;
    (*size)++;
}

void print_transactions(Transaction transactions[], int size) {
    printf("\nTransaction history:\n");
    for (int i = 0; i < size; i++) {
        printf("%s: %.2f\n", transactions[i].name, transactions[i].amount);
    }
}
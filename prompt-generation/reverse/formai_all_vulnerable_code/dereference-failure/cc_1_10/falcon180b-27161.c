//Falcon-180B DATASET v1.0 Category: Personal Finance Planner ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    float amount;
    char category[50];
} transaction;

transaction newTransaction(char* name, float amount, char* category) {
    transaction t;
    strcpy(t.name, name);
    t.amount = amount;
    strcpy(t.category, category);
    return t;
}

void printTransaction(transaction t) {
    printf("Name: %s\n", t.name);
    printf("Amount: $%.2f\n", t.amount);
    printf("Category: %s\n\n", t.category);
}

void addTransaction(transaction* transactions, int size, transaction t) {
    transactions[size] = t;
    size++;
}

int main() {
    int size = 0;
    transaction* transactions = (transaction*)malloc(sizeof(transaction));

    while(1) {
        printf("1. Add transaction\n2. Print transactions\n3. Exit\n");
        int choice;
        scanf("%d", &choice);

        switch(choice) {
            case 1: {
                char name[50];
                float amount;
                char category[50];
                printf("Enter name: ");
                scanf("%s", name);
                printf("Enter amount: ");
                scanf("%f", &amount);
                printf("Enter category: ");
                scanf("%s", category);
                addTransaction(transactions, size, newTransaction(name, amount, category));
                size++;
                break;
            }
            case 2: {
                for(int i=0; i<size; i++) {
                    printTransaction(transactions[i]);
                }
                break;
            }
            case 3: {
                free(transactions);
                exit(0);
            }
            default: {
                printf("Invalid choice.\n");
            }
        }
    }

    return 0;
}
//Falcon-180B DATASET v1.0 Category: Personal Finance Planner ; Style: Donald Knuth
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

#define MAX_SIZE 100
#define MAX_NAME_SIZE 50
#define MAX_AMOUNT_SIZE 12

typedef struct {
    char name[MAX_NAME_SIZE];
    float amount;
} transaction;

transaction transactions[MAX_SIZE];
int num_transactions = 0;

void add_transaction(char* name, float amount) {
    strcpy(transactions[num_transactions].name, name);
    transactions[num_transactions].amount = amount;
    num_transactions++;
}

void print_transactions() {
    printf("Transaction Name\t| Amount\n");
    for(int i=0; i<num_transactions; i++) {
        printf("%s\t\t| %.2f\n", transactions[i].name, transactions[i].amount);
    }
}

int main() {
    char name[MAX_NAME_SIZE];
    float amount;
    int choice;

    printf("Personal Finance Planner\n");
    printf("1. Add Transaction\n2. Print Transactions\n3. Exit\n");
    while(1) {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter transaction name: ");
                scanf("%s", name);
                printf("Enter transaction amount: ");
                scanf("%f", &amount);
                add_transaction(name, amount);
                break;

            case 2:
                print_transactions();
                break;

            case 3:
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
//Code Llama-13B DATASET v1.0 Category: Personal Finance Planner ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_BUFFER_SIZE 1024

typedef struct {
    char* name;
    double amount;
} Transaction;

void print_menu() {
    printf("Welcome to the personal finance planner!\n");
    printf("1. Add transaction\n");
    printf("2. Print transactions\n");
    printf("3. Calculate balance\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
}

void add_transaction(Transaction** transactions, int* size) {
    char name[MAX_BUFFER_SIZE];
    double amount;

    printf("Enter name: ");
    fgets(name, MAX_BUFFER_SIZE, stdin);
    printf("Enter amount: ");
    scanf("%lf", &amount);

    transactions[*size] = (Transaction*)malloc(sizeof(Transaction));
    transactions[*size]->name = strdup(name);
    transactions[*size]->amount = amount;

    *size += 1;
}

void print_transactions(Transaction** transactions, int size) {
    for (int i = 0; i < size; i++) {
        printf("%s: %f\n", transactions[i]->name, transactions[i]->amount);
    }
}

void calculate_balance(Transaction** transactions, int size) {
    double balance = 0.0;
    for (int i = 0; i < size; i++) {
        balance += transactions[i]->amount;
    }
    printf("Balance: %f\n", balance);
}

int main() {
    int choice;
    int size = 0;
    Transaction** transactions = (Transaction**)malloc(sizeof(Transaction*));

    while (1) {
        print_menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_transaction(transactions, &size);
                break;
            case 2:
                print_transactions(transactions, size);
                break;
            case 3:
                calculate_balance(transactions, size);
                break;
            case 4:
                free(transactions);
                return 0;
        }
    }

    return 0;
}
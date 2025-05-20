//MISTRAL-7B DATASET v1.0 Category: Banking Record System ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for account records
typedef struct {
    char name[50];
    int account_number;
    float balance;
} account;

// Function to search for an account by name or account number
account* find_account(account list[], int size, char search[50], int search_type) {
    for (int i = 0; i < size; i++) {
        if (strcmp(list[i].name, search) == 0 || list[i].account_number == search_type) {
            return &list[i];
        }
    }
    return NULL;
}

// Function to display account information
void display_account(account acc) {
    printf("\nName: %s", acc.name);
    printf("\nAccount Number: %d", acc.account_number);
    printf("\nBalance: %.2f\n", acc.balance);
}

// Function to deposit money into an account
void deposit(account* acc, float amount) {
    acc->balance += amount;
}

// Function to withdraw money from an account
void withdraw(account* acc, float amount) {
    if (acc->balance >= amount) {
        acc->balance -= amount;
    } else {
        printf("Insufficient funds.\n");
        return;
    }
}

// Function to add a new account to the list
void add_account(account list[], int* size, char name[50], int number) {
    if (*size == 10) {
        printf("List is full.\n");
        return;
    }
    account new_acc = {name, number, 0.0};
    list[*size] = new_acc;
    (*size)++;
}

// Function to process transactions
void process_transaction(account* list, int size, char search[50], int search_type, float amount, int type) {
    account* acc = find_account(list, size, search, search_type);
    if (acc != NULL) {
        if (type == 1) { // Deposit
            deposit(acc, amount);
        } else if (type == 2) { // Withdraw
            withdraw(acc, amount);
        }
    } else {
        printf("Account not found.\n");
    }
}

int main() {
    account my_list[10];
    int size = 0;
    char name[50];
    int number;
    char search[50];
    int search_type;
    float amount;
    int type;

    while (1) {
        printf("\n1. Deposit\n2. Withdraw\n3. Search\n4. Add Account\n5. Quit\n");
        scanf("%d", &type);

        switch (type) {
            case 1:
                printf("Enter account name or number: ");
                scanf("%s", name);
                printf("Enter account number (if applicable): ");
                scanf("%d", &number);
                printf("Enter amount to deposit: ");
                scanf("%f", &amount);
                process_transaction(my_list, size, name, number, amount, type);
                break;
            case 2:
                printf("Enter account name or number: ");
                scanf("%s", name);
                printf("Enter account number (if applicable): ");
                scanf("%d", &number);
                printf("Enter amount to withdraw: ");
                scanf("%f", &amount);
                process_transaction(my_list, size, name, number, amount, type);
                break;
            case 3:
                printf("Enter account name or number to search: ");
                scanf("%s", search);
                printf("Enter search type (name or number): ");
                scanf("%d", &search_type);
                account* found = find_account(my_list, size, search, search_type);
                if (found != NULL) {
                    display_account(*found);
                }
                break;
            case 4:
                printf("Enter account name: ");
                scanf("%s", name);
                printf("Enter account number: ");
                scanf("%d", &number);
                add_account(my_list, &size, name, number);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid option.\n");
        }
    }

    return 0;
}
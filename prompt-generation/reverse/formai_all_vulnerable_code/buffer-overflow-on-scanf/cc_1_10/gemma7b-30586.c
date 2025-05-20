//Gemma-7B DATASET v1.0 Category: Banking Record System ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Record {
    char name[50];
    int account_number;
    double balance;
    struct Record* next;
};

void deposit(struct Record* head) {
    struct Record* new_record = (struct Record*)malloc(sizeof(struct Record));
    printf("Enter your name: ");
    scanf("%s", new_record->name);
    printf("Enter your account number: ");
    scanf("%d", &new_record->account_number);
    printf("Enter the amount you want to deposit: ");
    scanf("%lf", &new_record->balance);
    new_record->next = head;
    head = new_record;
}

void withdraw(struct Record* head) {
    struct Record* current_record = head;
    printf("Enter your account number: ");
    int account_number;
    scanf("%d", &account_number);
    while (current_record) {
        if (current_record->account_number == account_number) {
            printf("Enter the amount you want to withdraw: ");
            double amount;
            scanf("%lf", &amount);
            current_record->balance -= amount;
            printf("Your new balance is: $%lf", current_record->balance);
            break;
        }
        current_record = current_record->next;
    }
    if (current_record == NULL) {
        printf("Account not found");
    }
}

int main() {
    struct Record* head = NULL;
    char choice;

    printf("Welcome to the C Banking Record System!\n");
    printf("Please select an option:\n");
    printf("1. Deposit\n");
    printf("2. Withdraw\n");
    printf("3. Exit\n");

    scanf("%c", &choice);

    switch (choice) {
        case '1':
            deposit(head);
            break;
        case '2':
            withdraw(head);
            break;
        case '3':
            exit(0);
            break;
        default:
            printf("Invalid input");
    }

    return 0;
}
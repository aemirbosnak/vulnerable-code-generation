//Falcon-180B DATASET v1.0 Category: Banking Record System ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100

typedef struct {
    char name[50];
    char account_number[10];
    float balance;
} BANK_RECORD;

BANK_RECORD records[MAX_RECORDS];
int num_records = 0;

void display_menu() {
    printf("\nHappy Banking System\n");
    printf("1. Create Account\n");
    printf("2. Deposit Money\n");
    printf("3. Withdraw Money\n");
    printf("4. Check Balance\n");
    printf("5. Exit\n");
}

void create_account() {
    char name[50];
    char account_number[10];
    int i;

    printf("Enter your name: ");
    scanf("%s", name);

    for (i = 0; i < num_records; i++) {
        if (strcmp(records[i].name, name) == 0) {
            printf("You already have an account with us!\n");
            return;
        }
    }

    printf("Enter your account number: ");
    scanf("%s", account_number);

    strcpy(records[num_records].name, name);
    strcpy(records[num_records].account_number, account_number);
    records[num_records].balance = 0.0;

    num_records++;

    printf("Account created successfully!\n");
}

void deposit_money() {
    char account_number[10];
    int i;

    printf("Enter your account number: ");
    scanf("%s", account_number);

    for (i = 0; i < num_records; i++) {
        if (strcmp(records[i].account_number, account_number) == 0) {
            printf("Enter amount to deposit: ");
            scanf("%f", &records[i].balance);
            printf("Deposit successful!\n");
            return;
        }
    }

    printf("Account not found.\n");
}

void withdraw_money() {
    char account_number[10];
    int i;

    printf("Enter your account number: ");
    scanf("%s", account_number);

    for (i = 0; i < num_records; i++) {
        if (strcmp(records[i].account_number, account_number) == 0) {
            printf("Enter amount to withdraw: ");
            scanf("%f", &records[i].balance);
            printf("Withdrawal successful!\n");
            return;
        }
    }

    printf("Account not found.\n");
}

void check_balance() {
    char account_number[10];
    int i;

    printf("Enter your account number: ");
    scanf("%s", account_number);

    for (i = 0; i < num_records; i++) {
        if (strcmp(records[i].account_number, account_number) == 0) {
            printf("Your current balance is: $%.2f\n", records[i].balance);
            return;
        }
    }

    printf("Account not found.\n");
}

int main() {
    int choice;

    system("clear");
    display_menu();

    while (1) {
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                create_account();
                break;
            case 2:
                deposit_money();
                break;
            case 3:
                withdraw_money();
                break;
            case 4:
                check_balance();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
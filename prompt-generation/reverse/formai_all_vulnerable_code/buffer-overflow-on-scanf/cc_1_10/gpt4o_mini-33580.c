//GPT-4o-mini DATASET v1.0 Category: File handling ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ACCOUNTS 100
#define FILENAME "accounts.txt"

typedef struct {
    int id;
    char name[50];
    float balance;
} Account;

// Function declarations
void create_account();
void deposit_money();
void withdraw_money();
void display_accounts();
void load_accounts(Account accounts[], int *count);
void save_accounts(Account accounts[], int count);

int main() {
    int choice;

    while (1) {
        printf("\n=== Simple Banking System ===\n");
        printf("1. Create Account\n");
        printf("2. Deposit Money\n");
        printf("3. Withdraw Money\n");
        printf("4. Display Accounts\n");
        printf("5. Exit\n");
        printf("Choose an option: ");
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
                display_accounts();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid option, please try again.\n");
        }
    }
    return 0;
}

void create_account() {
    FILE *file = fopen(FILENAME, "a");
    if (!file) {
        perror("Unable to open file!");
        return;
    }

    Account acc;
    printf("Enter account ID: ");
    scanf("%d", &acc.id);
    printf("Enter account holder's name: ");
    scanf(" %[^\n]", acc.name);
    acc.balance = 0.0;

    fwrite(&acc, sizeof(Account), 1, file);
    fclose(file);
    printf("Account created successfully!\n");
}

void deposit_money() {
    FILE *file = fopen(FILENAME, "r+b");
    if (!file) {
        perror("Unable to open file!");
        return;
    }

    int id;
    printf("Enter account ID to deposit money: ");
    scanf("%d", &id);

    Account acc;
    int found = 0;
    while (fread(&acc, sizeof(Account), 1, file)) {
        if (acc.id == id) {
            float deposit;
            printf("Enter amount to deposit: ");
            scanf("%f", &deposit);
            acc.balance += deposit;
            fseek(file, -sizeof(Account), SEEK_CUR);
            fwrite(&acc, sizeof(Account), 1, file);
            found = 1;
            break;
        }
    }

    fclose(file);
    if (found) {
        printf("Deposited successfully! New balance: %.2f\n", acc.balance);
    } else {
        printf("Account ID not found.\n");
    }
}

void withdraw_money() {
    FILE *file = fopen(FILENAME, "r+b");
    if (!file) {
        perror("Unable to open file!");
        return;
    }

    int id;
    printf("Enter account ID to withdraw money: ");
    scanf("%d", &id);

    Account acc;
    int found = 0;
    while (fread(&acc, sizeof(Account), 1, file)) {
        if (acc.id == id) {
            float withdraw;
            printf("Enter amount to withdraw: ");
            scanf("%f", &withdraw);
            if (withdraw > acc.balance) {
                printf("Insufficient funds!\n");
            } else {
                acc.balance -= withdraw;
                fseek(file, -sizeof(Account), SEEK_CUR);
                fwrite(&acc, sizeof(Account), 1, file);
                found = 1;
                printf("Withdrawn successfully! New balance: %.2f\n", acc.balance);
            }
            break;
        }
    }

    fclose(file);
    if (!found) {
        printf("Account ID not found.\n");
    }
}

void display_accounts() {
    FILE *file = fopen(FILENAME, "rb");
    if (!file) {
        perror("Unable to open file!");
        return;
    }

    Account acc;
    printf("\n=== List of Accounts ===\n");
    printf("ID\tName\t\tBalance\n");
    printf("----------------------------\n");
    while (fread(&acc, sizeof(Account), 1, file)) {
        printf("%d\t%s\t%.2f\n", acc.id, acc.name, acc.balance);
    }

    fclose(file);
}
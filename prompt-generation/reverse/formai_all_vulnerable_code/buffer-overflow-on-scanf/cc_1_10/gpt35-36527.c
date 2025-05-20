//FormAI DATASET v1.0 Category: Banking Record System ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void createAccount();
void displayAccount();
void deleteAccount();
void searchAccount();

typedef struct bankAccount {
    int accountNumber;
    char name[50];
    float balance;
} BankAccount;

int main() {
    int choice;
    srand(time(NULL));
    printf("\n*** Welcome to Banking Record System ***\n");
    printf("\nEnter your choice: \n");
    printf("1. Create Account\n");
    printf("2. Display Account\n");
    printf("3. Delete Account\n");
    printf("4. Search Account\n");
    printf("5. Exit\n");
    printf("\n");

    while (1) {
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                createAccount();
                break;
            case 2:
                displayAccount();
                break;
            case 3:
                deleteAccount();
                break;
            case 4:
                searchAccount();
                break;
            case 5:
                printf("\nThank you for using Banking Record System. Goodbye!");
                exit(0);
            default:
                printf("\nInvalid choice. Please try again.\n\n");
                break;
        }
    }
    return 0;
}

void createAccount() {
    BankAccount account;
    account.accountNumber = rand() % 10000;

    printf("\nEnter name of account holder: ");
    scanf("%s", account.name);
    printf("Enter opening balance: ");
    scanf("%f", &account.balance);

    FILE *fp = fopen("account.txt", "ab");
    if (fp == NULL) {
        printf("\nError opening file.");
        return;
    }
    fwrite(&account, sizeof(BankAccount), 1, fp);
    fclose(fp);
    printf("\nAccount created successfully.\n\n");
}

void displayAccount() {
    BankAccount account;
    int found = 0;
    int accountNumber;

    printf("\nEnter account number: ");
    scanf("%d", &accountNumber);

    FILE *fp = fopen("account.txt", "rb");
    if (fp == NULL) {
        printf("\nError opening file.");
        return;
    }

    while (fread(&account, sizeof(BankAccount), 1, fp)) {
        if (account.accountNumber == accountNumber) {
            printf("\nAccount Number: %d", account.accountNumber);
            printf("\nAccount Holder Name: %s", account.name);
            printf("\nAccount Balance: %.2f\n\n", account.balance);
            found = 1;
            break;
        }
    }
    if (found == 0) {
        printf("\nAccount not found.\n\n");
    }
    fclose(fp);
}

void deleteAccount() {
    BankAccount account;
    int found = 0;
    int accountNumber;

    printf("\nEnter account number: ");
    scanf("%d", &accountNumber);

    FILE *fp = fopen("account.txt", "rb");
    if (fp == NULL) {
        printf("\nError opening file.");
        return;
    }

    FILE *temp = fopen("temp.txt", "wb");
    if (temp == NULL) {
        printf("\nError opening file.");
        return;
    }

    while (fread(&account, sizeof(BankAccount), 1, fp)) {
        if (account.accountNumber != accountNumber) {
            fwrite(&account, sizeof(BankAccount), 1, temp);
        } else {
            found = 1;
        }
    }
    fclose(fp);
    fclose(temp);
    remove("account.txt");
    rename("temp.txt", "account.txt");

    if (found == 1) {
        printf("\nAccount deleted successfully.\n\n");
    } else {
        printf("\nAccount not found.\n\n");
    }
}

void searchAccount() {
    BankAccount account;
    int found = 0;
    char name[50];

    printf("\nEnter name of account holder: ");
    scanf("%s", name);

    FILE *fp = fopen("account.txt", "rb");
    if (fp == NULL) {
        printf("\nError opening file.");
        return;
    }

    while (fread(&account, sizeof(BankAccount), 1, fp)) {
        if (strcmp(account.name, name) == 0) {
            printf("\nAccount Number: %d", account.accountNumber);
            printf("\nAccount Holder Name: %s", account.name);
            printf("\nAccount Balance: %.2f\n\n", account.balance);
            found = 1;
        }
    }
    if (found == 0) {
        printf("\nAccount not found.\n\n");
    }
    fclose(fp);
}
//FormAI DATASET v1.0 Category: Banking Record System ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for bank account details
struct account {
    char name[50];
    int accno;
    float balance;
};

// Function to add account details to file
void add_account() {
    FILE *fp;
    struct account a;
    fp = fopen("accounts.dat", "ab");
    if (fp == NULL) {
        printf("Error opening file!");
        return;
    }
    printf("Enter name: ");
    scanf("%s", a.name);
    printf("Enter account number: ");
    scanf("%d", &a.accno);
    printf("Enter balance: ");
    scanf("%f", &a.balance);
    fwrite(&a, sizeof(struct account), 1, fp);
    fclose(fp);
}

// Function to display all account details
void display_all() {
    FILE *fp;
    struct account a;
    fp = fopen("accounts.dat", "rb");
    if (fp == NULL) {
        printf("Error opening file!");
        return;
    }
    printf("%-20s %-15s %s\n", "Name", "Account Number", "Balance");
    printf("--------------------------------------------------\n");
    while (fread(&a, sizeof(struct account), 1, fp) == 1) {
        printf("%-20s %-15d %.2f\n", a.name, a.accno, a.balance);
    }
    fclose(fp);
}

// Function to search for account details based on account number
void search_account() {
    FILE *fp;
    struct account a;
    int accno, found = 0;
    fp = fopen("accounts.dat", "rb");
    if (fp == NULL) {
        printf("Error opening file!");
        return;
    }
    printf("Enter account number: ");
    scanf("%d", &accno);
    while (fread(&a, sizeof(struct account), 1, fp) == 1) {
        if (a.accno == accno) {
            found = 1;
            printf("Account details:\n");
            printf("Name: %s\n", a.name);
            printf("Account Number: %d\n", a.accno);
            printf("Balance: %.2f\n", a.balance);
        }
    }
    if (!found) {
        printf("Account not found!\n");
    }
    fclose(fp);
}

// Function to deposit amount to account
void deposit() {
    FILE *fp;
    struct account a;
    int accno, found = 0;
    float amount;
    fp = fopen("accounts.dat", "rb+");
    if (fp == NULL) {
        printf("Error opening file!");
        return;
    }
    printf("Enter account number: ");
    scanf("%d", &accno);
    while (fread(&a, sizeof(struct account), 1, fp) == 1) {
        if (a.accno == accno) {
            found = 1;
            printf("Account details:\n");
            printf("Name: %s\n", a.name);
            printf("Account Number: %d\n", a.accno);
            printf("Balance: %.2f\n", a.balance);
            printf("Enter amount to deposit: ");
            scanf("%f", &amount);
            a.balance += amount;
            fseek(fp, -sizeof(struct account), SEEK_CUR);
            fwrite(&a, sizeof(struct account), 1, fp);
            printf("Amount deposited successfully!\n");
        }
    }
    if (!found) {
        printf("Account not found!\n");
    }
    fclose(fp);
}

// Function to withdraw amount from account
void withdraw() {
    FILE *fp;
    struct account a;
    int accno, found = 0;
    float amount;
    fp = fopen("accounts.dat", "rb+");
    if (fp == NULL) {
        printf("Error opening file!");
        return;
    }
    printf("Enter account number: ");
    scanf("%d", &accno);
    while (fread(&a, sizeof(struct account), 1, fp) == 1) {
        if (a.accno == accno) {
            found = 1;
            printf("Account details:\n");
            printf("Name: %s\n", a.name);
            printf("Account Number: %d\n", a.accno);
            printf("Balance: %.2f\n", a.balance);
            printf("Enter amount to withdraw: ");
            scanf("%f", &amount);
            if (amount > a.balance) {
                printf("Insufficient balance!\n");
            } else {
                a.balance -= amount;
                fseek(fp, -sizeof(struct account), SEEK_CUR);
                fwrite(&a, sizeof(struct account), 1, fp);
                printf("Amount withdrawn successfully!\n");
            }
        }
    }
    if (!found) {
        printf("Account not found!\n");
    }
    fclose(fp);
}

// Function to update account details based on account number
void update() {
    FILE *fp;
    struct account a;
    int accno, found = 0;
    fp = fopen("accounts.dat", "rb+");
    if (fp == NULL) {
        printf("Error opening file!");
        return;
    }
    printf("Enter account number: ");
    scanf("%d", &accno);
    while (fread(&a, sizeof(struct account), 1, fp) == 1) {
        if (a.accno == accno) {
            found = 1;
            printf("Account details:\n");
            printf("Name: %s\n", a.name);
            printf("Account Number: %d\n", a.accno);
            printf("Balance: %.2f\n", a.balance);
            printf("Enter new name: ");
            scanf("%s", a.name);
            printf("Enter new balance: ");
            scanf("%f", &a.balance);
            fseek(fp, -sizeof(struct account), SEEK_CUR);
            fwrite(&a, sizeof(struct account), 1, fp);
            printf("Account details updated successfully!\n");
        }
    }
    if (!found) {
        printf("Account not found!\n");
    }
    fclose(fp);
}

// Main function
int main() {
    printf("Welcome to the Banking Record System!\n");
    while (1) {
        printf("\nWhat would you like to do?\n");
        printf("1. Add account\n2. Display all accounts\n3. Search for account\n4. Deposit\n5. Withdraw\n6. Update account\n7. Exit\n");
        int choice;
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_account();
                break;
            case 2:
                display_all();
                break;
            case 3:
                search_account();
                break;
            case 4:
                deposit();
                break;
            case 5:
                withdraw();
                break;
            case 6:
                update();
                break;
            case 7:
                printf("Thank you for using the Banking Record System!\n");
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}
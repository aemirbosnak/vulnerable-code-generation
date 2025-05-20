//FormAI DATASET v1.0 Category: Banking Record System ; Style: decentralized
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Defining the structure for bank account details
struct account {
    char name[50];
    int acc_no;
    float balance;
};

// Function to create a new account and write it to file
void create_account() {
    struct account acc;
    FILE *fp;
    fp = fopen("bank_records.txt", "a+");
    printf("Enter name: ");
    scanf("%s", acc.name);
    printf("Enter account number: ");
    scanf("%d", &acc.acc_no);
    printf("Enter balance: ");
    scanf("%f", &acc.balance);
    fprintf(fp, "%s %d %f\n", acc.name, acc.acc_no, acc.balance);
    printf("\nAccount created successfully!\n");
    fclose(fp);
}

// Function to display all account details
void display_all_accounts() {
    FILE *fp;
    fp = fopen("bank_records.txt", "r");
    printf("Name\t\t\tAccount No\t\tBalance\n");
    while(!feof(fp)) {
        struct account acc;
        fscanf(fp, "%s %d %f\n", acc.name, &acc.acc_no, &acc.balance);
        printf("%-20s %-20d %-20.2f\n", acc.name, acc.acc_no, acc.balance);
    }
    fclose(fp);
}

// Function to display account details by account number
void display_account_by_acc_no(int acc_no) {
    FILE *fp;
    fp = fopen("bank_records.txt", "r");
    int found = 0;
    while(!feof(fp)) {
        struct account acc;
        fscanf(fp, "%s %d %f\n", acc.name, &acc.acc_no, &acc.balance);
        if(acc.acc_no == acc_no) {
            printf("\nName: %s\nAccount Number: %d\nBalance: %.2f\n", acc.name, acc.acc_no, acc.balance);
            found = 1;
            break;
        }
    }
    if(!found) {
        printf("\nAccount not found!\n");
    }
    fclose(fp);
}

// Function to withdraw money from account
void withdraw(int acc_no, float amount) {
    FILE *fp;
    fp = fopen("bank_records.txt", "r+");
    int found = 0;
    while(!feof(fp)) {
        long int pos = ftell(fp);
        struct account acc;
        fscanf(fp, "%s %d %f\n", acc.name, &acc.acc_no, &acc.balance);
        if(acc.acc_no == acc_no) {
            if(amount > acc.balance) {
                printf("\nNot enough balance!\n");
            } else {
                acc.balance -= amount;
                fseek(fp, pos, SEEK_SET);
                fprintf(fp, "%s %d %f\n", acc.name, acc.acc_no, acc.balance);
                printf("\nWithdrawal successful! New balance: %.2f\n", acc.balance);
            }
            found = 1;
            break;
        }
    }
    if(!found) {
        printf("\nAccount not found!\n");
    }
    fclose(fp);
}

// Function to deposit money to account
void deposit(int acc_no, float amount) {
    FILE *fp;
    fp = fopen("bank_records.txt", "r+");
    int found = 0;
    while(!feof(fp)) {
        long int pos = ftell(fp);
        struct account acc;
        fscanf(fp, "%s %d %f\n", acc.name, &acc.acc_no, &acc.balance);
        if(acc.acc_no == acc_no) {
            acc.balance += amount;
            fseek(fp, pos, SEEK_SET);
            fprintf(fp, "%s %d %f\n", acc.name, acc.acc_no, acc.balance);
            printf("\nDeposit successful! New balance: %.2f\n", acc.balance);
            found = 1;
            break;
        }
    }
    if(!found) {
        printf("\nAccount not found!\n");
    }
    fclose(fp);
}

// Main function
int main() {
    int option, acc_no;
    float amount;
    do {
        printf("\n1. Create Account\n2. Display All Accounts\n3. Display Account By Account Number\n4. Withdraw Money\n5. Deposit Money\n6. Exit\n");
        printf("Enter your option: ");
        scanf("%d", &option);
        switch(option) {
            case 1:
                create_account();
                break;
            case 2:
                display_all_accounts();
                break;
            case 3:
                printf("Enter account number: ");
                scanf("%d", &acc_no);
                display_account_by_acc_no(acc_no);
                break;
            case 4:
                printf("Enter account number: ");
                scanf("%d", &acc_no);
                printf("Enter withdrawal amount: ");
                scanf("%f", &amount);
                withdraw(acc_no, amount);
                break;
            case 5:
                printf("Enter account number: ");
                scanf("%d", &acc_no);
                printf("Enter deposit amount: ");
                scanf("%f", &amount);
                deposit(acc_no, amount);
                break;
            case 6:
                exit(0);
            default:
                printf("\nInvalid option!\n");
        }
    } while(1);
    return 0;
}
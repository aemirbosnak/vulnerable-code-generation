//FormAI DATASET v1.0 Category: Banking Record System ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure for account
struct account {
    char name[50];
    int acc_no;
    float balance;
};

// Function to display account information
void display_account(struct account acc) {
    printf("\nName: %s\nAccount No.: %d\nBalance: $%.2f\n", acc.name, acc.acc_no, acc.balance);
}

// Function to write account information to file
void write_account(struct account acc) {
    FILE *fp;
    fp = fopen("accounts.txt", "a");
    fprintf(fp, "%s %d %.2f\n", acc.name, acc.acc_no, acc.balance);
    fclose(fp);
}

// Function to read account information from file
struct account read_account(int acc_no) {
    struct account acc;
    FILE *fp;
    fp = fopen("accounts.txt", "r");
    while (fscanf(fp, "%s %d %f", acc.name, &acc.acc_no, &acc.balance) != EOF) {
        if (acc.acc_no == acc_no) {
            fclose(fp);
            return acc;
        }
    }
    fclose(fp);
    printf("\nAccount not found!\n");
    exit(1);
}

// Function to deposit money to an account
void deposit(int acc_no, float amount) {
    struct account acc = read_account(acc_no);
    acc.balance += amount;
    printf("\nSuccessfully deposited $%.2f to account no. %d\n", amount, acc_no);
    display_account(acc);
    FILE *fp;
    fp = fopen("accounts.txt", "r+");
    char line[100];
    long int pos;
    while (fgets(line, sizeof(line), fp)) {
        sscanf(line, "%*s%d", &acc.acc_no);
        if (acc.acc_no == acc_no) {
            pos = ftell(fp) - strlen(line);
            fseek(fp, pos, SEEK_SET);
            fprintf(fp, "%s %d %.2f\n", acc.name, acc.acc_no, acc.balance);
            break;
        }
    }
    fclose(fp);
}

// Function to withdraw money from an account
void withdraw(int acc_no, float amount) {
    struct account acc = read_account(acc_no);
    if (acc.balance < amount) {
        printf("\nInsufficient balance to withdraw $%.2f from account no. %d\n", amount, acc_no);
        display_account(acc);
        return;
    }
    acc.balance -= amount;
    printf("\nSuccessfully withdrawn $%.2f from account no. %d\n", amount, acc_no);
    display_account(acc);
    FILE *fp;
    fp = fopen("accounts.txt", "r+");
    char line[100];
    long int pos;
    while (fgets(line, sizeof(line), fp)) {
        sscanf(line, "%*s%d", &acc.acc_no);
        if (acc.acc_no == acc_no) {
            pos = ftell(fp) - strlen(line);
            fseek(fp, pos, SEEK_SET);
            fprintf(fp, "%s %d %.2f\n", acc.name, acc.acc_no, acc.balance);
            break;
        }
    }
    fclose(fp);
}

// Function to delete an account
void delete_account(int acc_no) {
    struct account acc = read_account(acc_no);
    printf("\nDeleting account no. %d\n", acc_no);
    FILE *fp, *tmp_fp;
    fp = fopen("accounts.txt", "r");
    tmp_fp = fopen("temp.txt", "w");
    char line[100];
    while (fgets(line, sizeof(line), fp)) {
        sscanf(line, "%*s%d", &acc.acc_no);
        if (acc.acc_no != acc_no) {
            fputs(line, tmp_fp);
        }
    }
    fclose(fp);
    fclose(tmp_fp);
    remove("accounts.txt");
    rename("temp.txt", "accounts.txt");
}

int main() {
    int choice;
    float amount;
    int acc_no;

    printf("Welcome to ABC Banking Record System\n");

    while (1) {
        printf("\nMenu:\n1. Create account\n2. Display account information\n3. Deposit money\n4. Withdraw money\n5. Delete account\n6. Quit\n\nEnter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                {
                    struct account acc;
                    printf("\nEnter account name: ");
                    scanf("%s", acc.name);
                    printf("Enter account no.: ");
                    scanf("%d", &acc.acc_no);
                    printf("Enter opening balance: ");
                    scanf("%f", &acc.balance);
                    write_account(acc);
                    printf("\nAccount created successfully.\n");
                    display_account(acc);
                }
                break;

            case 2:
                {
                    printf("\nEnter account no.: ");
                    scanf("%d", &acc_no);
                    struct account acc = read_account(acc_no);
                    display_account(acc);
                }
                break;

            case 3:
                {
                    printf("\nEnter account no.: ");
                    scanf("%d", &acc_no);
                    printf("Enter deposit amount: ");
                    scanf("%f", &amount);
                    deposit(acc_no, amount);
                }
                break;

            case 4:
                {
                    printf("\nEnter account no.: ");
                    scanf("%d", &acc_no);
                    printf("Enter withdraw amount: ");
                    scanf("%f", &amount);
                    withdraw(acc_no, amount);
                }
                break;

            case 5:
                {
                    printf("\nEnter account no.: ");
                    scanf("%d", &acc_no);
                    delete_account(acc_no);
                }
                break;
            
            case 6:
                {
                    printf("\nThank you for using ABC Banking Record System.\n");
                    return 0;
                }
                break;

            default:
                printf("\nInvalid choice. Please enter a valid choice.\n");
                break;
        }
    }

    return 0;
}
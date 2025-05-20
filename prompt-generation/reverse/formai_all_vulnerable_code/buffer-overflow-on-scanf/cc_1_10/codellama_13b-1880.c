//Code Llama-13B DATASET v1.0 Category: Banking Record System ; Style: calm
// Banking Record System in C

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store customer information
struct customer {
    char name[50];
    char email[50];
    char address[100];
    int account_number;
    float balance;
};

// Function to create a new customer record
void create_customer(struct customer *cust) {
    printf("Enter customer name: ");
    scanf("%s", cust->name);
    printf("Enter customer email: ");
    scanf("%s", cust->email);
    printf("Enter customer address: ");
    scanf("%s", cust->address);
    printf("Enter customer account number: ");
    scanf("%d", &cust->account_number);
    printf("Enter customer balance: ");
    scanf("%f", &cust->balance);
}

// Function to display all customer records
void display_customers() {
    FILE *fp;
    struct customer cust;
    fp = fopen("customers.txt", "r");
    if (fp == NULL) {
        printf("Error opening file!\n");
        return;
    }
    while (fread(&cust, sizeof(cust), 1, fp) == 1) {
        printf("Name: %s\n", cust.name);
        printf("Email: %s\n", cust.email);
        printf("Address: %s\n", cust.address);
        printf("Account Number: %d\n", cust.account_number);
        printf("Balance: %f\n", cust.balance);
    }
    fclose(fp);
}

// Function to deposit money into a customer's account
void deposit(int account_number, float amount) {
    FILE *fp;
    struct customer cust;
    fp = fopen("customers.txt", "r+");
    if (fp == NULL) {
        printf("Error opening file!\n");
        return;
    }
    while (fread(&cust, sizeof(cust), 1, fp) == 1) {
        if (cust.account_number == account_number) {
            cust.balance += amount;
            fseek(fp, -sizeof(cust), SEEK_CUR);
            fwrite(&cust, sizeof(cust), 1, fp);
            break;
        }
    }
    fclose(fp);
}

// Function to withdraw money from a customer's account
void withdraw(int account_number, float amount) {
    FILE *fp;
    struct customer cust;
    fp = fopen("customers.txt", "r+");
    if (fp == NULL) {
        printf("Error opening file!\n");
        return;
    }
    while (fread(&cust, sizeof(cust), 1, fp) == 1) {
        if (cust.account_number == account_number) {
            cust.balance -= amount;
            fseek(fp, -sizeof(cust), SEEK_CUR);
            fwrite(&cust, sizeof(cust), 1, fp);
            break;
        }
    }
    fclose(fp);
}

// Function to display a customer's balance
void display_balance(int account_number) {
    FILE *fp;
    struct customer cust;
    fp = fopen("customers.txt", "r");
    if (fp == NULL) {
        printf("Error opening file!\n");
        return;
    }
    while (fread(&cust, sizeof(cust), 1, fp) == 1) {
        if (cust.account_number == account_number) {
            printf("Balance: %f\n", cust.balance);
            break;
        }
    }
    fclose(fp);
}

// Main function
int main() {
    int choice;
    float amount;
    int account_number;
    struct customer cust;

    while (1) {
        printf("1. Create a new customer record\n");
        printf("2. Display all customer records\n");
        printf("3. Deposit money into a customer's account\n");
        printf("4. Withdraw money from a customer's account\n");
        printf("5. Display a customer's balance\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                create_customer(&cust);
                break;
            case 2:
                display_customers();
                break;
            case 3:
                printf("Enter account number: ");
                scanf("%d", &account_number);
                printf("Enter amount to deposit: ");
                scanf("%f", &amount);
                deposit(account_number, amount);
                break;
            case 4:
                printf("Enter account number: ");
                scanf("%d", &account_number);
                printf("Enter amount to withdraw: ");
                scanf("%f", &amount);
                withdraw(account_number, amount);
                break;
            case 5:
                printf("Enter account number: ");
                scanf("%d", &account_number);
                display_balance(account_number);
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice\n");
                break;
        }
    }
    return 0;
}
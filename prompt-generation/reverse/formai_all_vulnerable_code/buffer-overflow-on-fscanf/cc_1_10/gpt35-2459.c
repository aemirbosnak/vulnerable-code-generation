//FormAI DATASET v1.0 Category: Banking Record System ; Style: single-threaded
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct customer {
    char name[50];
    char account_no[10];
    float balance;
};

void create_account();
void deposit();
void withdraw();
void display();

int main() {
    int choice;
    printf("\n\n************MENU************\n");
    printf("1. Create a new account\n2. Deposit amount\n3. Withdraw amount\n4. Display account details\n5. Exit\n");

    do {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1: create_account();
                    break;
            case 2: deposit();
                    break;
            case 3: withdraw();
                    break;
            case 4: display();
                    break;
            case 5: printf("\nThank you for using our service!\n");
                    exit(0);
            default: printf("\nInvalid choice! Please choose from the menu.\n");
        }
    } while(choice != 5);

    return 0;
}

void create_account() {
    struct customer c;
    printf("\nEnter name: ");
    fflush(stdin);
    fgets(c.name,50,stdin);
    printf("Enter account number: ");
    scanf("%s", c.account_no);
    printf("Enter initial balance: ");
    scanf("%f", &c.balance);
    FILE *fptr = fopen("accounts.txt", "a");
    fprintf(fptr, "%s %s %.2f\n", c.account_no, c.name, c.balance);
    fclose(fptr);
    printf("\nNew account created successfully!\n\n");
}

void deposit() {
    char account[10];
    float amount;
    int found = 0;
    printf("\nEnter account number: ");
    scanf("%s", account);
    FILE *fptr = fopen("accounts.txt", "r");
    struct customer c;
    while(fscanf(fptr, "%s %[^\n] %f", c.account_no, c.name, &c.balance) != EOF) {
        if(strcmp(c.account_no,account) == 0) {
            found = 1;
            printf("Enter amount to deposit: ");
            scanf("%f", &amount);
            c.balance += amount;
            fseek(fptr, ftell(fptr) - sizeof(struct customer), SEEK_SET);
            fprintf(fptr, "%s %s %.2f\n", c.account_no, c.name, c.balance);
            printf("\nRs. %.2f deposited successfully.\nNew balance is Rs. %.2f\n\n", amount, c.balance);
            break;
        }
    }

    if(found == 0)
        printf("\nAccount not found! Please enter a valid account number.\n");

    fclose(fptr);
}

void withdraw() {
    char account[10];
    float amount;
    int found = 0;
    printf("\nEnter account number: ");
    scanf("%s", account);
    FILE *fptr = fopen("accounts.txt", "r");
    struct customer c;
    while(fscanf(fptr, "%s %[^\n] %f", c.account_no, c.name, &c.balance) != EOF) {
        if(strcmp(c.account_no, account) == 0) {
            found = 1;
            printf("Enter amount to withdraw: ");
            scanf("%f", &amount);
            if(amount > c.balance || amount <= 0) {
                printf("\nInsufficient balance or invalid amount! Please enter a valid amount.\n");
                break;
            }
            c.balance -= amount;
            fseek(fptr, ftell(fptr) - sizeof(struct customer), SEEK_SET);
            fprintf(fptr, "%s %s %.2f\n", c.account_no, c.name, c.balance);
            printf("\nRs. %.2f withdrawn successfully.\n");
            printf("New balance is Rs. %.2f\n\n", c.balance);
            break;
        }
    }

    if(found == 0)
        printf("\nAccount not found! Please enter a valid account number.\n");

    fclose(fptr);
}

void display() {
    char account[10];
    int found = 0;
    printf("\nEnter account number: ");
    scanf("%s", account);
    FILE *fptr = fopen("accounts.txt", "r");
    struct customer c;
    while(fscanf(fptr, "%s %[^\n] %f", c.account_no, c.name, &c.balance) != EOF) {
        if(strcmp(c.account_no, account) == 0) {
            found = 1;
            printf("\nCustomer details:\n");
            printf("Name: %s", c.name);
            printf("Account number: %s\n", c.account_no);
            printf("Balance: Rs. %.2f\n\n", c.balance);
            break;
        }
    }

    if(found == 0)
        printf("\nAccount not found! Please enter a valid account number.\n");

    fclose(fptr);
}
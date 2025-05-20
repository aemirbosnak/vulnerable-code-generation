//FormAI DATASET v1.0 Category: Banking Record System ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>

// struct to hold customer information
typedef struct customer {
    int id;
    char name[50];
    float balance;
} Customer;

// function prototypes
void printMenu();
void createAccount();
void viewAccount();
void depositMoney();
void withdrawMoney();
void deleteAccount();

// global variables
Customer customers[100];
int numCustomers = 0;

int main() {
    int choice;
    do {
        printMenu();
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                createAccount();
                break;
            case 2:
                viewAccount();
                break;
            case 3:
                depositMoney();
                break;
            case 4:
                withdrawMoney();
                break;
            case 5:
                deleteAccount();
                break;
            case 6:
                printf("Thank you for using our Banking Record System!\n");
                break;
            default:
                printf("Invalid choice. Please enter a number between 1 and 6.\n");
                break;
        }
    } while (choice != 6);
    return 0;
}

void printMenu() {
    printf("========== Banking Record System ==========\n");
    printf("1. Create an account\n");
    printf("2. View account information\n");
    printf("3. Deposit money\n");
    printf("4. Withdraw money\n");
    printf("5. Delete account\n");
    printf("6. Exit\n");
    printf("Please enter your choice: ");
}

void createAccount() {
    Customer c;
    printf("Enter customer name: ");
    scanf("%s", c.name);
    printf("Enter initial balance: ");
    scanf("%f", &c.balance);
    c.id = numCustomers + 1;
    customers[numCustomers] = c;
    numCustomers++;
    printf("Account created successfully. Your customer ID is %d.\n", c.id);
}

void viewAccount() {
    int id;
    printf("Enter customer ID: ");
    scanf("%d", &id);
    for (int i = 0; i < numCustomers; i++) {
        if (customers[i].id == id) {
            printf("Name: %s\n", customers[i].name);
            printf("Balance: $%.2f\n", customers[i].balance);
            return;
        }
    }
    printf("Customer not found.\n");
}

void depositMoney() {
    int id;
    float amount;
    printf("Enter customer ID: ");
    scanf("%d", &id);
    for (int i = 0; i < numCustomers; i++) {
        if (customers[i].id == id) {
            printf("Enter amount to deposit: ");
            scanf("%f", &amount);
            customers[i].balance += amount;
            printf("Deposit successful. New balance is $%.2f\n", customers[i].balance);
            return;
        }
    }
    printf("Customer not found.\n");
}

void withdrawMoney() {
    int id;
    float amount;
    printf("Enter customer ID: ");
    scanf("%d", &id);
    for (int i = 0; i < numCustomers; i++) {
        if (customers[i].id == id) {
            printf("Enter amount to withdraw: ");
            scanf("%f", &amount);
            if (amount > customers[i].balance) {
                printf("Insufficient funds.\n");
                return;
            }
            customers[i].balance -= amount;
            printf("Withdrawal successful. New balance is $%.2f\n", customers[i].balance);
            return;
        }
    }
    printf("Customer not found.\n");
}

void deleteAccount() {
    int id;
    printf("Enter customer ID: ");
    scanf("%d", &id);
    for (int i = 0; i < numCustomers; i++) {
        if (customers[i].id == id) {
            for (int j = i; j < numCustomers-1; j++) {
                customers[j] = customers[j+1];
            }
            numCustomers--;
            printf("Account deleted successfully.\n");
            return;
        }
    }
    printf("Customer not found.\n");
}
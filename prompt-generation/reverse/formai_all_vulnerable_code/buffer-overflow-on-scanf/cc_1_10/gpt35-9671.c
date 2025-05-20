//FormAI DATASET v1.0 Category: Banking Record System ; Style: cheerful
// Welcome to our cheerful Banking Record System!

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store customer information
struct customer {
    char name[50];
    int account_number;
    float balance;
};

// Function to display menu options
void display_menu() {
    printf("\nWelcome to our Banking Record System!\n");
    printf("===================================\n");
    printf("1. Add a new customer\n");
    printf("2. Display customer information\n");
    printf("3. Update account balance\n");
    printf("4. Exit\n");
}

// Function to add a new customer
void add_customer(struct customer *cust) {
    printf("Enter customer name: ");
    scanf("%s", cust->name);
    printf("Enter account number: ");
    scanf("%d", &cust->account_number);
    printf("Enter opening balance: ");
    scanf("%f", &cust->balance);
    printf("Customer added successfully!\n");
}

// Function to display customer information
void display_customer(struct customer cust) {
    printf("Name: %s\n", cust.name);
    printf("Account number: %d\n", cust.account_number);
    printf("Balance: %.2f\n", cust.balance);
}

// Function to update account balance
void update_balance(struct customer *cust) {
    float amount;
    printf("Enter amount to add/subtract: ");
    scanf("%f", &amount);
    cust->balance += amount;
    printf("Balance updated successfully!\n");
}

int main() {
    int option;
    struct customer cust;
    
    // Loop until user chooses to exit
    while (1) {
        display_menu();
        printf("Enter your choice: ");
        scanf("%d", &option);
        
        switch(option) {
            case 1:
                add_customer(&cust);
                break;
            case 2:
                display_customer(cust);
                break;
            case 3:
                update_balance(&cust);
                break;
            case 4:
                printf("Thank you for using our Banking Record System!\n");
                exit(0);
            default:
                printf("Invalid option! Please try again.\n");
        }
    }
    
    return 0;
}
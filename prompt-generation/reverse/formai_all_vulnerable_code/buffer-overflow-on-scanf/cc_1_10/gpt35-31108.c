//FormAI DATASET v1.0 Category: Banking Record System ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CUSTOMERS 100

struct Customer {
    char name[50];
    int accountNumber;
    float balance;
};

struct Customer customers[MAX_CUSTOMERS];
int numCustomers = 0; // number of customers in the system

// Function prototypes
void displayMenu();
void addCustomer();
void displayCustomers();
void deposit();
void withdraw();

int main() {
    int choice;
    
    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addCustomer();
                break;
            case 2:
                displayCustomers();
                break;
            case 3:
                deposit();
                break;
            case 4:
                withdraw();
                break;
            case 5:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);
    
    return 0;
}

// Display the banking menu
void displayMenu() {
    printf("\nBanking Record System\n");
    printf("1. Add a new customer\n");
    printf("2. Display all customers\n");
    printf("3. Make a deposit\n");
    printf("4. Make a withdrawal\n");
    printf("5. Quit\n");
}

// Add a new customer to the system
void addCustomer() {
    struct Customer newCustomer;
    
    if (numCustomers >= MAX_CUSTOMERS) {
        printf("Sorry, the maximum number of customers has been reached.\n");
        return;
    }
    
    printf("\nEnter customer name: ");
    scanf("%s", newCustomer.name);
    printf("Enter account number: ");
    scanf("%d", &newCustomer.accountNumber);
    printf("Enter opening balance: ");
    scanf("%f", &newCustomer.balance);
    
    customers[numCustomers] = newCustomer;
    numCustomers++;
    
    printf("\nCustomer added successfully!\n");
}

// Display all customers currently in the system
void displayCustomers() {
    if (numCustomers == 0) {
        printf("\nNo customers in the system.\n");
        return;
    }
    
    printf("\nName\tAccount Number\tBalance\n");
    for (int i = 0; i < numCustomers; i++) {
        printf("%s\t%d\t%.2f\n", customers[i].name, customers[i].accountNumber, customers[i].balance);
    }
}

// Make a deposit for a specified customer
void deposit() {
    int accountNum;
    float amount;
    
    printf("\nEnter account number: ");
    scanf("%d", &accountNum);
    
    for (int i = 0; i < numCustomers; i++) {
        if (customers[i].accountNumber == accountNum) {
            printf("Enter amount to deposit: ");
            scanf("%f", &amount);
            
            customers[i].balance += amount;
            printf("\nDeposit successful. New balance is %.2f\n", customers[i].balance);
            return;
        }
    }
    
    printf("Sorry, account number %d not found.\n", accountNum);
}

// Make a withdrawal for a specified customer
void withdraw() {
    int accountNum;
    float amount;
    
    printf("\nEnter account number: ");
    scanf("%d", &accountNum);
    
    for (int i = 0; i < numCustomers; i++) {
        if (customers[i].accountNumber == accountNum) {
            printf("Enter amount to withdraw: ");
            scanf("%f", &amount);
            
            if (amount > customers[i].balance) {
                printf("Withdrawal unsuccessful. Insufficient funds.\n");
                return;
            }
            
            customers[i].balance -= amount;
            printf("\nWithdrawal successful. New balance is %.2f\n", customers[i].balance);
            return;
        }
    }
    
    printf("Sorry, account number %d not found.\n", accountNum);
}
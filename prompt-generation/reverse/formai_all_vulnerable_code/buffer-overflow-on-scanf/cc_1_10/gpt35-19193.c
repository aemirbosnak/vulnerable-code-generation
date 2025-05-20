//FormAI DATASET v1.0 Category: Banking Record System ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CUSTOMERS 1000

struct Customer {
    char name[30];
    int accountNumber;
    double balance;
};

struct Customer customers[MAX_CUSTOMERS];
int numCustomers = 0;

void printHeader() {
    printf("-------------------------------------------------\n");
    printf("|           Banking Record System               |\n");
    printf("-------------------------------------------------\n");
}

void displayMenu() {
    printf("1. Add customer\n");
    printf("2. View all customers\n");
    printf("3. Search customer by account number\n");
    printf("4. Update customer balance\n");
    printf("5. Delete customer\n");
    printf("6. Exit\n");
}

void addCustomer() {
    char name[30];
    int accountNumber;
    double balance;

    printf("Enter customer name: ");
    scanf("%s", name);
    printf("Enter account number: ");
    scanf("%d", &accountNumber);
    printf("Enter current balance: ");
    scanf("%lf", &balance);

    struct Customer newCustomer = { 
        .accountNumber = accountNumber, 
        .balance = balance 
    };

    strcpy(newCustomer.name, name);

    customers[numCustomers] = newCustomer;
    numCustomers++;

    printf("Successfully added customer: %s\n", name);
}

void viewCustomers() {
    printf("Displaying all customers...\n");
    printf("-------------------------------------------------\n");
    printf("|   Name            |   Account Number  |  Balance |\n");
    printf("-------------------------------------------------\n");

    for (int i = 0; i < numCustomers; i++) {
        printf("|   %-15s|   %-15d|  $%.2lf   |\n", 
               customers[i].name, 
               customers[i].accountNumber, 
               customers[i].balance);
    }
    printf("-------------------------------------------------\n");
}

void searchCustomer() {
    int accountNumber;
    printf("Enter account number: ");
    scanf("%d", &accountNumber);

    for (int i = 0; i < numCustomers; i++) {
        if (customers[i].accountNumber == accountNumber) {
            printf("-------------------------------------------------\n");
            printf("|   Name            |   Account Number  |  Balance |\n");
            printf("-------------------------------------------------\n");
            printf("|   %-15s|   %-15d|  $%.2lf   |\n", 
                   customers[i].name, 
                   customers[i].accountNumber, 
                   customers[i].balance);
            printf("-------------------------------------------------\n");

            return;
        }
    }

    printf("No customer found with account number: %d\n", accountNumber);
}

void updateBalance() {
    int accountNumber;
    printf("Enter account number: ");
    scanf("%d", &accountNumber);

    for (int i = 0; i < numCustomers; i++) {
        if (customers[i].accountNumber == accountNumber) {
            double newBalance;
            printf("Enter new balance: ");
            scanf("%lf", &newBalance);
            customers[i].balance = newBalance;

            printf("Successfully updated balance for customer: %s\n", customers[i].name);

            return;
        }
    }

    printf("No customer found with account number: %d\n", accountNumber);
}

void deleteCustomer() {
    int accountNumber;
    printf("Enter account number: ");
    scanf("%d", &accountNumber);

    for (int i = 0; i < numCustomers; i++) {
        if (customers[i].accountNumber == accountNumber) {
            for (int j = i; j < numCustomers - 1; j++) {
                customers[j] = customers[j + 1];
            }

            numCustomers--;
            printf("Successfully deleted customer with account number: %d\n", accountNumber);

            return;
        }
    }

    printf("No customer found with account number: %d\n", accountNumber);
}

int main() {
    int choice;

    do {
        printHeader();
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addCustomer();
                break;
            case 2:
                viewCustomers();
                break;
            case 3:
                searchCustomer();
                break;
            case 4:
                updateBalance();
                break;
            case 5:
                deleteCustomer();
                break;
            case 6:
                printf("Exiting program...\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }

        printf("Press Enter to continue...");
        getchar();
        getchar();

    } while (choice != 6);

    return 0;
}
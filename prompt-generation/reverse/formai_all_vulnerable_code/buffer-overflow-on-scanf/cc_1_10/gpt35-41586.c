//FormAI DATASET v1.0 Category: Banking Record System ; Style: relaxed
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_CUSTOMER 50
#define MAX_TRANSACTIONS 100

/* Structure Definition */
struct Transaction {
    char transactionType[10];
    float amount;
};

struct Customer {
    char name[50];
    int accountNumber;
    float balance;
    struct Transaction transactionList[MAX_TRANSACTIONS];
    int numTransactions;
};

/* Function Prototypes */
void displayMenu();
void addCustomer(struct Customer* customers, int* numCustomers);
void performTransaction(struct Customer* customers, int numCustomers);
void displayAllCustomers(struct Customer* customers, int numCustomers);
void displayCustomerDetails(struct Customer* customers, int numCustomers);

/* Main function */
int main() {
    struct Customer customers[MAX_CUSTOMER];
    int numCustomers = 0;
    int choice;

    while (1) {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addCustomer(customers, &numCustomers);
                break;
            case 2:
                performTransaction(customers, numCustomers);
                break;
            case 3:
                displayAllCustomers(customers, numCustomers);
                break;
            case 4:
                displayCustomerDetails(customers, numCustomers);
                break;
            case 0:
                printf("\nExiting the program...");
                exit(0);
            default:
                printf("\nInvalid choice! Please try again.");
                break;
        }
    }

    return 0;
}

/* Function to display the menu */
void displayMenu() {
    printf("\n===== BANKING RECORD SYSTEM =====\n");
    printf("1. Add a new customer\n");
    printf("2. Perform a transaction on a customer's account\n");
    printf("3. Display all customers\n");
    printf("4. Display details of a specific customer\n");
    printf("0. Exit\n");
}

/* Function to add a new customer */
void addCustomer(struct Customer* customers, int* numCustomers) {
    if (*numCustomers >= MAX_CUSTOMER) {
        printf("\nCannot add more customers!");
        return;
    }

    struct Customer newCustomer;
    printf("\nEnter details of the new customer:\n");
    printf("Name: ");
    scanf("%s", newCustomer.name);
    printf("Account number: ");
    scanf("%d", &newCustomer.accountNumber);
    printf("Initial balance: ");
    scanf("%f", &newCustomer.balance);

    customers[*numCustomers] = newCustomer;
    (*numCustomers)++;

    printf("\nCustomer added successfully!");
}

/* Function to perform a transaction on a customer's account */
void performTransaction(struct Customer* customers, int numCustomers) {
    int accountNumber;
    float amount;
    char transactionType[10];

    printf("\nEnter account number: ");
    scanf("%d", &accountNumber);

    int found = 0;
    for (int i = 0; i < numCustomers; i++) {
        if (customers[i].accountNumber == accountNumber) {
            printf("\nEnter transaction type ('deposit' or 'withdraw'): ");
            scanf("%s", transactionType);
            if (strcmp(transactionType, "deposit") == 0) {
                printf("Enter amount to deposit: ");
                scanf("%f", &amount);
                customers[i].balance += amount;
                strcpy(customers[i].transactionList[customers[i].numTransactions].transactionType, transactionType);
                customers[i].transactionList[customers[i].numTransactions].amount = amount;
                customers[i].numTransactions++;
                printf("\nTransaction completed successfully!");
            }
            else if (strcmp(transactionType, "withdraw") == 0) {
                printf("Enter amount to withdraw: ");
                scanf("%f", &amount);
                if (customers[i].balance >= amount) {
                    customers[i].balance -= amount;
                    strcpy(customers[i].transactionList[customers[i].numTransactions].transactionType, transactionType);
                    customers[i].transactionList[customers[i].numTransactions].amount = amount;
                    customers[i].numTransactions++;
                    printf("\nTransaction completed successfully!");
                }
                else {
                    printf("\nInsufficient balance! Transaction aborted.");
                }
            }
            else {
                printf("\nInvalid transaction type! Please try again.");
            }
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("\nCustomer not found!");
    }
}

/* Function to display all customers */
void displayAllCustomers(struct Customer* customers, int numCustomers) {
    printf("\n===== CUSTOMER DETAILS =====\n");
    printf("Name\tAccount Number\tBalance\n");
    for (int i = 0; i < numCustomers; i++) {
        printf("%s\t%d\t\t%.2f\n", customers[i].name, customers[i].accountNumber, customers[i].balance);
    }
}

/* Function to display details of a specific customer */
void displayCustomerDetails(struct Customer* customers, int numCustomers) {
    int accountNumber;

    printf("\nEnter account number: ");
    scanf("%d", &accountNumber);

    int found = 0;
    for (int i = 0; i < numCustomers; i++) {
        if (customers[i].accountNumber == accountNumber) {
            printf("\n===== DETAILS OF %s =====\n", customers[i].name);
            printf("Account Number: %d\n", customers[i].accountNumber);
            printf("Balance: %.2f\n", customers[i].balance);
            printf("\nTransaction List:\n");
            if (customers[i].numTransactions == 0) {
                printf("\tNo transactions made.");
            }
            for (int j = 0; j < customers[i].numTransactions; j++) {
                printf("\t%s of %.2f\n", customers[i].transactionList[j].transactionType, customers[i].transactionList[j].amount);
            }
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("\nCustomer not found!");
    }
}
//FormAI DATASET v1.0 Category: Banking Record System ; Style: Claude Shannon
//Welcome to the C Banking Record System.
//Developed by Claude Shannon.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char firstName[20];
    char lastName[20];
    char accountNumber[10];
    float balance;
} CUSTOMER;

int menu();
void addCustomer(CUSTOMER *customer, int *numCustomers);
void displayCustomer(CUSTOMER customer);
void saveToFile(CUSTOMER *customer, int numCustomers);
void readFromFile(CUSTOMER *customer, int *numCustomers);
void updateCustomer(CUSTOMER *customer, int numCustomers);

int main() {
    int choice, numCustomers = 0;
    CUSTOMER customer[100];

    readFromFile(customer, &numCustomers);

    do {
        choice = menu();

        switch(choice) {
            case 1:
                addCustomer(&customer[numCustomers], &numCustomers);
                break;
            case 2:
                displayCustomer(customer[numCustomers-1]);
                break;
            case 3:
                updateCustomer(customer, numCustomers);
                break;
            case 4:
                saveToFile(customer, numCustomers);
                break;
            case 5:
                printf("Thank you for using the C Banking Record System.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while(choice != 5);

    return 0;
}

int menu() {
    int choice;

    printf("\nC BANKING RECORD SYSTEM\n");
    printf("-----------------------\n");
    printf("1. Add new customer\n");
    printf("2. Display latest customer\n");
    printf("3. Update customer information\n");
    printf("4. Save records to file\n");
    printf("5. Exit program\n");
    printf("-----------------------\n");

    printf("Enter choice: ");
    scanf("%d", &choice);

    return choice;
}

void addCustomer(CUSTOMER *customer, int *numCustomers) {
    printf("\nADD NEW CUSTOMER\n");
    printf("----------------\n");

    printf("Enter first name: ");
    scanf("%s", customer->firstName);

    printf("Enter last name: ");
    scanf("%s", customer->lastName);

    printf("Enter account number (max 10 characters): ");
    scanf("%s", customer->accountNumber);

    printf("Enter opening balance: ");
    scanf("%f", &customer->balance);

    (*numCustomers)++;
}

void displayCustomer(CUSTOMER customer) {
    printf("\nLATEST CUSTOMER\n");
    printf("---------------\n");

    printf("First name: %s\n", customer.firstName);
    printf("Last name: %s\n", customer.lastName);
    printf("Account number: %s\n", customer.accountNumber);
    printf("Balance: $%.2f\n", customer.balance);
}

void saveToFile(CUSTOMER *customer, int numCustomers) {
    FILE *fout;
    int i;

    fout = fopen("customers.txt", "w");

    for(i=0; i<numCustomers; i++) {
        fprintf(fout, "%s %s %s %.2f\n", customer[i].firstName, customer[i].lastName, customer[i].accountNumber, customer[i].balance);
    }

    fclose(fout);

    printf("\nRecords saved to file.\n");
}

void readFromFile(CUSTOMER *customer, int *numCustomers) {
    FILE *fin;
    int i;

    fin = fopen("customers.txt", "r");

    if(fin != NULL) {
        while(fscanf(fin, "%s %s %s %f", customer[*numCustomers].firstName, customer[*numCustomers].lastName, customer[*numCustomers].accountNumber, &customer[*numCustomers].balance) == 4) {
            (*numCustomers)++;
        }

        fclose(fin);

        printf("Records loaded from file.\n");
    } else {
        printf("No records found.\n");
    }
}

void updateCustomer(CUSTOMER *customer, int numCustomers) {
    char accountNumber[10];
    int i, found = 0;

    printf("\nUPDATE CUSTOMER\n");
    printf("----------------\n");

    printf("Enter account number of customer to update: ");
    scanf("%s", accountNumber);

    for(i=0; i<numCustomers; i++) {
        if(strcmp(accountNumber, customer[i].accountNumber) == 0) {
            printf("Enter new balance: ");
            scanf("%f", &customer[i].balance);

            printf("Customer record updated.\n");

            found = 1;
            break;
        }
    }

    if(!found) {
        printf("Customer record not found.\n");
    }
}
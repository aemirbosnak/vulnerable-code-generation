//FormAI DATASET v1.0 Category: Banking Record System ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Creating a structure for holding customer information
struct customer {
    char name[50];
    int accountNumber;
    float balance;
};

// Function to add customer information to the system
void addCustomerInfo(struct customer *c) {
    printf("Enter customer name: ");
    scanf("%s", c->name);
    printf("Enter account number: ");
    scanf("%d", &c->accountNumber);
    printf("Enter account balance: ");
    scanf("%f", &c->balance);
    printf("Customer information added successfully!\n");
}

// Function to display customer information from the system
void displayCustomerInfo(struct customer *c) {
    printf("Customer Name: %s\nAccount Number: %d\nAccount Balance: $%.2f\n", c->name, c->accountNumber, c->balance);
}

int main() {
    // Creating an array of 100 customers
    struct customer customers[100];
    int count = 0; // To keep track of number of customers in the system

    int choice;
    while(1) {
        printf("\n1. Add customer information\n2. Display customer information\n3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                if(count == 100) {
                    printf("Error: Max number of customers reached!\n");
                } else {
                    addCustomerInfo(&customers[count]);
                    count++;
                }
                break;

            case 2:
                if(count == 0) {
                    printf("No customer information available!\n");
                } else {
                    printf("Enter account number to display information: ");
                    int accNo;
                    scanf("%d", &accNo);
                    int i;
                    for(i=0; i<count; i++) {
                        if(customers[i].accountNumber == accNo) {
                            displayCustomerInfo(&customers[i]);
                            break;
                        }
                    }
                    if(i == count) {
                        printf("Customer with account number %d not found!\n", accNo);
                    }
                }
                break;

            case 3:
                printf("Goodbye!\n");
                exit(0);

            default:
                printf("Error: Invalid choice!\n");
        }
    }

    return 0;
}
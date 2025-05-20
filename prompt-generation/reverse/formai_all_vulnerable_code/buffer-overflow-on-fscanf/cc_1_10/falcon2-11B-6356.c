//Falcon2-11B DATASET v1.0 Category: Banking Record System ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    float balance;
} Account;

int main() {
    // Create an array to store customer accounts
    Account customers[10];

    // Prompt user to enter customer details
    printf("Enter customer details:\n");
    printf("Name: ");
    fgets(customers[0].name, sizeof(customers[0].name), stdin);

    printf("Balance: ");
    fscanf(stdin, "%f", &customers[0].balance);

    printf("\nAccount details entered successfully!\n");

    // Display customer details
    printf("Customer Name: %s\n", customers[0].name);
    printf("Account Balance: %.2f\n", customers[0].balance);

    printf("\nSelect an operation:\n");
    printf("1. Deposit\n");
    printf("2. Withdrawal\n");
    printf("3. Exit\n");

    int choice;
    fscanf(stdin, "%d", &choice);

    switch (choice) {
        case 1:
            printf("Enter deposit amount: ");
            fscanf(stdin, "%f", &customers[0].balance);
            printf("Deposit successful!\n");
            break;
        case 2:
            printf("Enter withdrawal amount: ");
            fscanf(stdin, "%f", &customers[0].balance);
            if (customers[0].balance >= 0) {
                customers[0].balance -= customers[0].balance;
                printf("Withdrawal successful!\n");
            } else {
                printf("Insufficient funds!\n");
            }
            break;
        case 3:
            printf("Thank you for using the Banking Record System!\n");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
    }

    return 0;
}
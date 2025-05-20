//FormAI DATASET v1.0 Category: Banking Record System ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct customer {
    char name[50];
    char account_number[20];
    float balance;
};

int main()
{
    int choice, n = 0;
    struct customer *customers = NULL;
    
    printf("Welcome to the Banking Record System!\n\n");
    
    while (1) { // infinite loop until user quits
        
        printf("1. Add a customer\n");
        printf("2. View all customers\n");
        printf("3. Search for a customer\n");
        printf("4. Exit\n");
        printf("Enter your choice (1-4): ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1: // add a customer
                n++; // increase number of customers
                customers = realloc(customers, sizeof(struct customer) * n); // re-allocate memory for customers
                printf("\nEnter the customer name: ");
                scanf("%s", customers[n-1].name);
                printf("Enter the account number: ");
                scanf("%s", customers[n-1].account_number);
                printf("Enter the balance: ");
                scanf("%f", &customers[n-1].balance);
                printf("\nCustomer added successfully!\n\n");
                break;
            case 2: // view all customers
                if (n == 0) {
                    printf("\nNo customers found!\n\n");
                } else {
                    printf("\nAll customers:\n");
                    for (int i=0; i<n; i++) {
                        printf("Name: %s\n", customers[i].name);
                        printf("Account number: %s\n", customers[i].account_number);
                        printf("Balance: %.2f\n\n", customers[i].balance);
                    }
                }
                break;
            case 3: // search for a customer
                if (n == 0) {
                    printf("\nNo customers found!\n\n");
                } else {
                    char query[50];
                    printf("\nEnter the name or account number of the customer to search: ");
                    scanf("%s", query);
                    
                    int found = 0;
                    for (int i=0; i<n; i++) {
                        if (strcmp(query, customers[i].name) == 0 || strcmp(query, customers[i].account_number) == 0) {
                            printf("\nCustomer found:\n");
                            printf("Name: %s\n", customers[i].name);
                            printf("Account number: %s\n", customers[i].account_number);
                            printf("Balance: %.2f\n\n", customers[i].balance);
                            found = 1;
                            break;
                        }
                    }
                    
                    if (!found) {
                        printf("\nCustomer not found!\n\n");
                    }
                }
                break;
            case 4: // exit
                printf("\nThank you for using the Banking Record System!\n");
                exit(0);
            default:
                printf("\nInvalid choice, please try again!\n\n");
        }
    }
    
    return 0;
}
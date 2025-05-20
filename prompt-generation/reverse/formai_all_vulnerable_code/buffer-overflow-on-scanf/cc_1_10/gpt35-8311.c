//FormAI DATASET v1.0 Category: Banking Record System ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Customer {
    char name[50];
    char address[100];
    char phone_number[20];
    int account_num;
    float balance;
} Customer;

int main() {
    int num_customers = 0;
    int option = 0;

    Customer *bank_customers = NULL;
    bank_customers = (Customer*) malloc(sizeof(Customer));

    while (option != 4) {
        printf("Welcome to the C Banking Record System.\n");
        printf("Please select an option:\n");
        printf("1. Add a customer\n");
        printf("2. Search for a customer\n");
        printf("3. View all customers\n");
        printf("4. Exit\n");
        printf("Option: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                printf("\n");
                printf("Enter customer name: ");
                scanf(" %[^\n]s", bank_customers[num_customers].name);
                printf("Enter customer address: ");
                scanf(" %[^\n]s", bank_customers[num_customers].address);
                printf("Enter customer phone number: ");
                scanf(" %[^\n]s", bank_customers[num_customers].phone_number);
                printf("Enter customer account number: ");
                scanf("%d", &bank_customers[num_customers].account_num);
                printf("Enter customer balance: ");
                scanf("%f", &bank_customers[num_customers].balance);
                printf("\n");

                num_customers++;
                bank_customers = (Customer*) realloc(bank_customers, (num_customers+1) * sizeof(Customer));
                break;

            case 2:
                printf("\n");
                int search_account_num;
                int found = 0;
                printf("Enter customer account number: ");
                scanf("%d", &search_account_num);
                for (int i = 0; i < num_customers; i++) {
                    if (bank_customers[i].account_num == search_account_num) {
                        printf("Name: %s\n", bank_customers[i].name);
                        printf("Address: %s\n", bank_customers[i].address);
                        printf("Phone number: %s\n", bank_customers[i].phone_number);
                        printf("Account number: %d\n", bank_customers[i].account_num);
                        printf("Balance: $%.2f\n", bank_customers[i].balance);
                        found = 1;
                        break;
                    }
                }
                if (!found) {
                    printf("Customer not found.\n");
                }
                printf("\n");
                break;

            case 3:
                printf("\n");
                printf("Total number of customers: %d\n", num_customers);
                for (int i = 0; i < num_customers; i++) {
                    printf("\nCustomer %d:\n", i+1);
                    printf("Name: %s\n", bank_customers[i].name);
                    printf("Address: %s\n", bank_customers[i].address);
                    printf("Phone number: %s\n", bank_customers[i].phone_number);
                    printf("Account number: %d\n", bank_customers[i].account_num);
                    printf("Balance: $%.2f\n", bank_customers[i].balance);
                }
                printf("\n");
                break;

            case 4:
                printf("\n");
                printf("Thank you for using the C Banking Record System.\n");
                break;

            default:
                printf("\n");
                printf("Invalid option. Please try again.\n");
                printf("\n");
                break;
        }
    }

    free(bank_customers);
    return 0;
}
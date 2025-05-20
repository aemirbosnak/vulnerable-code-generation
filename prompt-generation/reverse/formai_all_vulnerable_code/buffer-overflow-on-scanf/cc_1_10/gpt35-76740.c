//FormAI DATASET v1.0 Category: Banking Record System ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CUSTOMERS 100

struct Customer {
    char name[50];
    char account_number[10];
    int balance;
};

void print_menu() {
    printf("\n1. Add customer\n");
    printf("2. Display all customers\n");
    printf("3. Search accounts by balance\n");
    printf("4. Delete customer\n");
    printf("5. Exit\n");
}

int main() {
    struct Customer customers[MAX_CUSTOMERS];
    int num_customers = 0;

    while (1) {
        print_menu();

        int option;
        printf("\nEnter an option: ");
        scanf("%d", &option);

        switch (option) {
            case 1: {
                printf("\nAdding customer...\n");
                getchar(); // Flush newline character from previous input
                printf("Enter name: ");
                fgets(customers[num_customers].name, 50, stdin);
                customers[num_customers].name[strcspn(customers[num_customers].name, "\n")] = 0; // Trim newline character
                printf("Enter account number: ");
                fgets(customers[num_customers].account_number, 10, stdin);
                customers[num_customers].account_number[strcspn(customers[num_customers].account_number, "\n")] = 0; // Trim newline character
                printf("Enter balance: ");
                scanf("%d", &customers[num_customers].balance);
                num_customers++;
                break;
            }
            case 2: {
                printf("\nDisplaying all customers...\n");

                printf("%-20s %-15s Balance\n", "Name", "Account #");
                printf("-------------------------------------------------\n");
                for (int i = 0; i < num_customers; i++) {
                    printf("%-20s %-15s $%d\n", customers[i].name, customers[i].account_number, customers[i].balance);
                }
                break;
            }
            case 3: {
                printf("\nSearching accounts by balance...\n");

                int balance_search;
                printf("Enter balance: ");
                scanf("%d", &balance_search);

                printf("%-20s %-15s Balance\n", "Name", "Account #");
                printf("-------------------------------------------------\n");
                for (int i = 0; i < num_customers; i++) {
                    if (customers[i].balance == balance_search) {
                        printf("%-20s %-15s $%d\n", customers[i].name, customers[i].account_number, customers[i].balance);
                    }
                }
                break;
            }
            case 4: {
                printf("\nDeleting customer...\n");

                char account_num_delete[10];
                printf("Enter account number of customer to delete: ");
                fgets(account_num_delete, 10, stdin);
                account_num_delete[strcspn(account_num_delete, "\n")] = 0; // Trim newline character

                int found_customer = 0;
                for (int i = 0; i < num_customers; i++) {
                    if (strcmp(customers[i].account_number, account_num_delete) == 0) {
                        printf("Deleting customer with account number %s and balance $%d...\n", customers[i].account_number, customers[i].balance);
                        for (int j = i; j < num_customers - 1; j++) {
                            customers[j] = customers[j+1]; // Shift all customers after deleted customer over one spot
                        }
                        num_customers--;
                        found_customer = 1;
                        break;
                    }
                }

                if (!found_customer) {
                    printf("Customer not found.\n");
                }
                break;
            }
            case 5: {
                printf("\nExiting...\n");
                exit(0);
            }
            default: {
                printf("\nInvalid option. Try again.\n");
                break;
            }
        }
    }

    return 0;
}
//FormAI DATASET v1.0 Category: Banking Record System ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct customer {
    char name[50];
    int account_number;
    float balance;
};

int main() {
    int choice;
    int i, j, flag;
    int num_of_customers = 0;
    struct customer c[50];
    char search_name[50];
    int search_account_num;

    while (1) {
        printf("1. Create a new account\n");
        printf("2. Search for an account\n");
        printf("3. Display customer details\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nCreating a new account:\n");
                printf("Enter name: ");
                scanf("%s", c[num_of_customers].name);
                printf("Enter account number: ");
                scanf("%d", &c[num_of_customers].account_number);
                c[num_of_customers].balance = 0;
                printf("Account created successfully!\n");
                num_of_customers++;
                break;

            case 2:
                printf("\nSearching for an account:\n");
                printf("Enter name or account number: ");
                scanf("%s", search_name);
                search_account_num = atoi(search_name);
                flag = 0;

                for (i = 0; i < num_of_customers; i++) {
                    if (strcmp(search_name, c[i].name) == 0 || search_account_num == c[i].account_number) {
                        flag = 1;
                        printf("Customer found!\n");
                        printf("Name: %s\n", c[i].name);
                        printf("Account number: %d\n", c[i].account_number);
                        printf("Balance: %.2f\n", c[i].balance);
                        break;
                    }
                }

                if (flag == 0) {
                    printf("Customer not found!\n");
                }
                break;

            case 3:
                printf("\nDisplaying customer details:\n");

                for (i = 0; i < num_of_customers; i++) {
                    printf("Customer %d:\n", i+1);
                    printf("Name: %s\n", c[i].name);
                    printf("Account number: %d\n", c[i].account_number);
                    printf("Balance: %.2f\n", c[i].balance);
                }

                break;

            case 4:
                printf("\nExiting the program. Goodbye!\n");
                exit(0);

            default:
                printf("\nInvalid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}
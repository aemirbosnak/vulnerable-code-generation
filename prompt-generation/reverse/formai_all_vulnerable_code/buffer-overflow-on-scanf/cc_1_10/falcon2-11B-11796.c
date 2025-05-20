//Falcon2-11B DATASET v1.0 Category: Cafe Billing System ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>

struct customer {
    char name[30];
    char phone[20];
    int balance;
};

struct customer customer_list[100];
int num_customers = 0;

int main() {
    int choice, i;
    char name[30];

    while (1) {
        printf("Cafe Billing System\n");
        printf("1. Make Payment\n");
        printf("2. Generate Bill\n");
        printf("3. Manage Customer Accounts\n");
        printf("0. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the amount of payment: ");
                scanf("%d", &customer_list[num_customers].balance);
                printf("Payment successful! Your balance is now %d.\n", customer_list[num_customers].balance);
                break;
            case 2:
                printf("Enter the name of the customer for whom you want to generate a bill: ");
                scanf("%s", name);
                for (i = 0; i < num_customers; i++) {
                    if (strcmp(customer_list[i].name, name) == 0) {
                        printf("%s\n", customer_list[i].name);
                        printf("Balance: %d\n", customer_list[i].balance);
                        printf("Total bill: %d\n", customer_list[i].balance * 100);
                    }
                }
                break;
            case 3:
                printf("Enter the name of the customer you want to view: ");
                scanf("%s", name);
                for (i = 0; i < num_customers; i++) {
                    if (strcmp(customer_list[i].name, name) == 0) {
                        printf("%s\n", customer_list[i].name);
                        printf("Balance: %d\n", customer_list[i].balance);
                        printf("Total spent: %d\n", customer_list[i].balance);
                    }
                }
                break;
            case 0:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}
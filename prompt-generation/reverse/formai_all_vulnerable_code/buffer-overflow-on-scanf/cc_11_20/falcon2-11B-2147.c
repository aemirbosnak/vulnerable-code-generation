//Falcon2-11B DATASET v1.0 Category: Banking Record System ; Style: accurate
#include <stdio.h>
#include <stdlib.h>

struct Customer {
    char name[50];
    int id;
    float balance;
};

int main() {
    struct Customer customers[10];
    int num_customers = 0;

    while (num_customers < 10) {
        printf("Enter customer details:\n");
        printf("Name: ");
        scanf("%s", customers[num_customers].name);
        printf("ID: ");
        scanf("%d", &customers[num_customers].id);
        printf("Balance: $");
        scanf("%f", &customers[num_customers].balance);
        num_customers++;
    }

    printf("Customer Records:\n");
    for (int i = 0; i < num_customers; i++) {
        printf("Customer %d:\n", i + 1);
        printf("Name: %s\n", customers[i].name);
        printf("ID: %d\n", customers[i].id);
        printf("Balance: $%.2f\n", customers[i].balance);
    }

    printf("Enter an operation (d/w/e):\n");
    char operation;
    scanf(" %c", &operation);

    int choice;
    while (choice!= 0) {
        switch (operation) {
            case 'd': {
                int customer_id;
                printf("Enter customer ID: ");
                scanf("%d", &customer_id);
                if (customer_id < 0 || customer_id >= num_customers) {
                    printf("Invalid customer ID\n");
                    break;
                }
                float amount;
                printf("Enter deposit amount: $");
                scanf("%f", &amount);
                customers[customer_id].balance += amount;
                printf("Deposit successful!\n");
                break;
            }
            case 'w': {
                int customer_id;
                printf("Enter customer ID: ");
                scanf("%d", &customer_id);
                if (customer_id < 0 || customer_id >= num_customers) {
                    printf("Invalid customer ID\n");
                    break;
                }
                float amount;
                printf("Enter withdrawal amount: $");
                scanf("%f", &amount);
                if (amount > customers[customer_id].balance) {
                    printf("Insufficient balance\n");
                    break;
                }
                customers[customer_id].balance -= amount;
                printf("Withdrawal successful!\n");
                break;
            }
            case 'e': {
                int customer_id;
                printf("Enter customer ID: ");
                scanf("%d", &customer_id);
                if (customer_id < 0 || customer_id >= num_customers) {
                    printf("Invalid customer ID\n");
                    break;
                }
                printf("Customer %d's balance: $%.2f\n", customer_id + 1, customers[customer_id].balance);
                break;
            }
            default: {
                printf("Invalid operation\n");
                break;
            }
        }
        printf("Enter an operation (d/w/e): ");
        scanf(" %c", &operation);
    }

    return 0;
}
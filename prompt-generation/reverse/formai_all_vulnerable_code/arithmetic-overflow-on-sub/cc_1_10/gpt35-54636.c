//FormAI DATASET v1.0 Category: Banking Record System ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct customer {
    char name[50];
    int account_number;
    float balance;
} Customer;

void deposit(Customer* customer, float amount) {
    customer->balance += amount;
    printf("Deposit successful!\n");
    printf("New balance: %.2f\n", customer->balance);
}

void withdraw(Customer* customer, float amount) {
    if (amount > customer->balance) {
        printf("Withdrawal failed! Insufficient funds.\n");
    } else {
        customer->balance -= amount;
        printf("Withdrawal successful!\n");
        printf("New balance: %.2f\n", customer->balance);
    }
}

void print_customer(Customer* customer) {
    printf("Name: %s\n", customer->name);
    printf("Account number: %d\n", customer->account_number);
    printf("Balance: %.2f\n", customer->balance);
}

int main() {
    int num_customers;
    printf("Enter the number of customers: ");
    scanf("%d", &num_customers);

    Customer* customers = (Customer*) malloc(num_customers * sizeof(Customer));

    for (int i = 0; i < num_customers; i++) {
        printf("\nCustomer #%d\n", i+1);
        printf("Name: ");
        scanf("%s", customers[i].name);
        printf("Account number: ");
        scanf("%d", &customers[i].account_number);
        printf("Balance: ");
        scanf("%f", &customers[i].balance);
    }

    int customer_index;
    char action[10];
    float amount;

    do {
        printf("Enter customer number (1-%d), action (deposit/withdraw), and amount: ", num_customers);
        scanf("%d %s %f", &customer_index, action, &amount);

        if (strcmp(action, "deposit") == 0) {
            deposit(&customers[customer_index-1], amount);
        } else if (strcmp(action, "withdraw") == 0) {
            withdraw(&customers[customer_index-1], amount);
        } else {
            printf("Invalid action. Please try again.\n");
        }

        printf("Customer info:\n");
        print_customer(&customers[customer_index-1]);

        printf("Do you want to perform another transaction? (y/n) ");
        char response[2];
        scanf("%s", response);

        if (strcmp(response, "n") == 0) {
            break;
        }

    } while (1);

    free(customers);

    return 0;
}
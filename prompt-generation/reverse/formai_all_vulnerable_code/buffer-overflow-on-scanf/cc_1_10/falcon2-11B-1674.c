//Falcon2-11B DATASET v1.0 Category: Cafe Billing System ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct bill {
    char name[50];
    float total_amount;
};

struct bill customers[100];
int num_customers = 0;

void add_customer(char *name, float amount) {
    struct bill new_customer;
    strcpy(new_customer.name, name);
    new_customer.total_amount = amount;

    if (num_customers >= 100) {
        printf("Sorry, we cannot add any more customers.\n");
        return;
    }

    customers[num_customers] = new_customer;
    num_customers++;
}

void print_bill(int index) {
    if (index < 0 || index >= num_customers) {
        printf("Invalid customer index.\n");
        return;
    }

    struct bill customer = customers[index];
    printf("Name: %s\n", customer.name);
    printf("Total amount: %.2f\n", customer.total_amount);
}

int main() {
    char name[50];
    float amount;

    printf("Welcome to the Cafe Billing System!\n");

    while (1) {
        printf("Enter customer name: ");
        scanf("%s", name);

        printf("Enter amount: ");
        scanf("%f", &amount);

        add_customer(name, amount);

        printf("Do you want to add another customer? (y/n): ");
        char answer;
        scanf(" %c", &answer);

        if (answer == 'n') {
            break;
        }
    }

    printf("\nBills:\n");
    for (int i = 0; i < num_customers; i++) {
        print_bill(i);
    }

    return 0;
}
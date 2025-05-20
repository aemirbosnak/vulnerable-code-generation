//Falcon2-11B DATASET v1.0 Category: Cafe Billing System ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Item {
    char* name;
    float price;
};

struct Customer {
    char* name;
    char* address;
    float balance;
};

int main() {
    struct Item items[] = {
        {"Tea", 2.5},
        {"Coffee", 3.0},
        {"Pastry", 1.5},
    };

    struct Customer customers[] = {
        {"John", "123 Main St", 50.0},
        {"Jane", "456 Elm St", 75.0},
        {"Bob", "789 Oak St", 30.0},
    };

    int numItems = sizeof(items) / sizeof(struct Item);
    int numCustomers = sizeof(customers) / sizeof(struct Customer);

    printf("Welcome to the Peaceful Cafe!\n");
    printf("Here are today's specials:\n");
    for (int i = 0; i < numItems; i++) {
        printf("%s - $%.2f\n", items[i].name, items[i].price);
    }

    int choice;
    printf("What would you like to order? (Enter 0 to exit)\n");
    scanf("%d", &choice);

    if (choice == 0) {
        return 0;
    }

    int quantity = 1;
    float total = 0.0;

    while (choice < numItems) {
        printf("How many %s would you like? (Enter 0 to exit)\n", items[choice].name);
        scanf("%d", &quantity);

        if (quantity == 0) {
            break;
        }

        total += quantity * items[choice].price;
        choice++;
    }

    struct Customer* customer = customers;
    while (customer->name!= NULL) {
        if (strcmp(customer->name, "John") == 0 && strcmp(customer->address, "123 Main St") == 0) {
            break;
        }
        customer++;
    }

    if (customer->name == NULL) {
        printf("Customer not found\n");
        return 1;
    }

    printf("Your total bill is $%.2f\n", total);
    printf("Customer Name: %s\n", customer->name);
    printf("Customer Address: %s\n", customer->address);
    printf("Customer Balance: $%.2f\n", customer->balance - total);

    return 0;
}
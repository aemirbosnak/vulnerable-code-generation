//Falcon-180B DATASET v1.0 Category: Cafe Billing System ; Style: brave
#include <stdio.h>
#include <stdlib.h>

struct Menu {
    char name[100];
    float price;
};

struct Customer {
    char name[100];
    int tableNumber;
    int orderCount;
    struct Menu orderedItems[10];
};

void displayMenu() {
    struct Menu menuItems[5] = {
        {"Coffee", 2.50},
        {"Tea", 1.50},
        {"Cake", 3.50},
        {"Cookies", 1.00},
        {"Sandwich", 4.50}
    };

    printf("MENU\n");
    for (int i = 0; i < 5; i++) {
        printf("%d. %s - $%.2f\n", i+1, menuItems[i].name, menuItems[i].price);
    }
}

void placeOrder(struct Customer *customer) {
    printf("Enter the item number you want to order: ");
    scanf("%d", &customer->orderCount);

    for (int i = 0; i < customer->orderCount; i++) {
        printf("Enter the name of the %dth item: ", i+1);
        scanf("%s", customer->orderedItems[i].name);

        printf("Enter the price of the %dth item: ", i+1);
        scanf("%f", &customer->orderedItems[i].price);
    }
}

void printBill(struct Customer customer) {
    printf("\nBILL\n");
    printf("Name: %s\n", customer.name);
    printf("Table Number: %d\n", customer.tableNumber);
    printf("Order Count: %d\n", customer.orderCount);

    if (customer.orderCount > 0) {
        printf("Ordered Items:\n");
        for (int i = 0; i < customer.orderCount; i++) {
            printf("%s - $%.2f\n", customer.orderedItems[i].name, customer.orderedItems[i].price);
        }
    } else {
        printf("No items ordered.\n");
    }

    printf("Total Bill: $%.2f\n", customer.orderCount * 10.00);
}

int main() {
    struct Customer customer;

    printf("Enter your name: ");
    scanf("%s", customer.name);

    printf("Enter your table number: ");
    scanf("%d", &customer.tableNumber);

    displayMenu();
    placeOrder(&customer);

    printBill(customer);

    return 0;
}
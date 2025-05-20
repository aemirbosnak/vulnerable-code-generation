//Falcon-180B DATASET v1.0 Category: Cafe Billing System ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>

struct MenuItem {
    char name[50];
    float price;
};

struct Order {
    int quantity;
    struct MenuItem item;
};

void displayMenu(struct MenuItem menuItems[], int numItems) {
    printf("Welcome to C Cafe!\n\n");
    for (int i = 0; i < numItems; i++) {
        printf("%d. %s - $%.2f\n", i+1, menuItems[i].name, menuItems[i].price);
    }
}

int getOrder(struct Order order) {
    printf("Enter the quantity of the item you want to order:\n");
    scanf("%d", &order.quantity);
    printf("Enter the name of the item you want to order:\n");
    scanf("%s", order.item.name);
    return 0;
}

float calculateTotal(struct Order order, struct MenuItem menuItems[], int numItems) {
    for (int i = 0; i < numItems; i++) {
        if (strcmp(order.item.name, menuItems[i].name) == 0) {
            return order.quantity * menuItems[i].price;
        }
    }
    printf("Item not found.\n");
    exit(1);
}

int main() {
    struct MenuItem menuItems[] = {{"Coffee", 2.50}, {"Tea", 1.75}, {"Cake", 3.25}};
    int numItems = sizeof(menuItems)/sizeof(menuItems[0]);

    struct Order order;
    getOrder(order);

    float total = calculateTotal(order, menuItems, numItems);

    printf("Your order is: %d %s - $%.2f\n", order.quantity, order.item.name, total);

    return 0;
}
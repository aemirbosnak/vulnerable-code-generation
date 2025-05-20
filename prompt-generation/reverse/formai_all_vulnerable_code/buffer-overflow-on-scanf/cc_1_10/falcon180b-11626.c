//Falcon-180B DATASET v1.0 Category: Cafe Billing System ; Style: retro
#include <stdio.h>
#include <stdlib.h>

#define MAX_ITEMS 10
#define MAX_CUSTOMERS 50

typedef struct {
    char name[20];
    int customer_id;
    int order_id;
    char order[100];
    float total_price;
} CustomerOrder;

typedef struct {
    char name[20];
    int id;
    float price;
} MenuItem;

void addMenuItem(MenuItem menuItems[], int *numItems) {
    printf("Enter menu item name: ");
    scanf("%s", menuItems[*numItems].name);
    printf("Enter menu item price: ");
    scanf("%f", &menuItems[*numItems].price);
    (*numItems)++;
}

void displayMenu(MenuItem menuItems[], int numItems) {
    printf("\nMenu:\n");
    for (int i = 0; i < numItems; i++) {
        printf("%d. %s - $%.2f\n", i+1, menuItems[i].name, menuItems[i].price);
    }
}

void addCustomerOrder(CustomerOrder customerOrders[], int *numOrders) {
    printf("Enter customer name: ");
    scanf("%s", customerOrders[*numOrders].name);
    printf("Enter customer ID: ");
    scanf("%d", &customerOrders[*numOrders].customer_id);
    printf("Enter order ID: ");
    scanf("%d", &customerOrders[*numOrders].order_id);
    printf("Enter order: ");
    scanf("%s", customerOrders[*numOrders].order);
    printf("Enter total price: ");
    scanf("%f", &customerOrders[*numOrders].total_price);
    (*numOrders)++;
}

void displayCustomerOrders(CustomerOrder customerOrders[], int numOrders) {
    printf("\nCustomer Orders:\n");
    for (int i = 0; i < numOrders; i++) {
        printf("%s (%d) - Order %d - %s - $%.2f\n", customerOrders[i].name, customerOrders[i].customer_id, customerOrders[i].order_id, customerOrders[i].order, customerOrders[i].total_price);
    }
}

int main() {
    MenuItem menuItems[MAX_ITEMS];
    int numMenuItems = 0;
    addMenuItem(menuItems, &numMenuItems);
    addMenuItem(menuItems, &numMenuItems);
    addMenuItem(menuItems, &numMenuItems);

    CustomerOrder customerOrders[MAX_CUSTOMERS];
    int numCustomerOrders = 0;
    addCustomerOrder(customerOrders, &numCustomerOrders);
    addCustomerOrder(customerOrders, &numCustomerOrders);

    int choice;
    while (1) {
        printf("\nCafe Billing System\n");
        printf("1. Display menu\n");
        printf("2. Place order\n");
        printf("3. Display customer orders\n");
        printf("4. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displayMenu(menuItems, numMenuItems);
                break;
            case 2:
                printf("Enter customer name: ");
                scanf("%s", customerOrders[numCustomerOrders].name);
                printf("Enter customer ID: ");
                scanf("%d", &customerOrders[numCustomerOrders].customer_id);
                printf("Enter order ID: ");
                scanf("%d", &customerOrders[numCustomerOrders].order_id);
                printf("Enter order: ");
                scanf("%s", customerOrders[numCustomerOrders].order);
                printf("Enter total price: ");
                scanf("%f", &customerOrders[numCustomerOrders].total_price);
                numCustomerOrders++;
                break;
            case 3:
                displayCustomerOrders(customerOrders, numCustomerOrders);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
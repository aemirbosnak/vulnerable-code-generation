//Falcon-180B DATASET v1.0 Category: Cafe Billing System ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_CUSTOMERS 50

typedef struct {
    char name[50];
    int quantity;
    float price;
} Item;

typedef struct {
    char name[50];
    int customerId;
    float totalPrice;
} Customer;

int numItems;
Item items[MAX_ITEMS];
int numCustomers;
Customer customers[MAX_CUSTOMERS];

void addItem() {
    printf("Enter item name: ");
    scanf("%s", items[numItems].name);
    printf("Enter quantity: ");
    scanf("%d", &items[numItems].quantity);
    printf("Enter price: ");
    scanf("%f", &items[numItems].price);
    numItems++;
}

void viewItems() {
    printf("\nItem List:\n");
    for (int i = 0; i < numItems; i++) {
        printf("%d. %s - %d units - $%.2f\n", i+1, items[i].name, items[i].quantity, items[i].price);
    }
}

void addCustomer() {
    printf("\nEnter customer name: ");
    scanf("%s", customers[numCustomers].name);
    customers[numCustomers].customerId = numCustomers + 1;
    numCustomers++;
}

void viewCustomers() {
    printf("\nCustomer List:\n");
    for (int i = 0; i < numCustomers; i++) {
        printf("%d. %s\n", i+1, customers[i].name);
    }
}

void addToOrder(int customerId, int itemId) {
    printf("\nEnter quantity: ");
    scanf("%d", &items[itemId].quantity);
    customers[customerId-1].totalPrice += items[itemId].price * items[itemId].quantity;
}

void viewOrder(int customerId) {
    printf("\nOrder for %s:\n", customers[customerId-1].name);
    for (int i = 0; i < numItems; i++) {
        if (items[i].quantity > 0) {
            printf("%s - %d units - $%.2f\n", items[i].name, items[i].quantity, items[i].price);
        }
    }
    printf("\nTotal Price: $%.2f\n", customers[customerId-1].totalPrice);
}

int main() {
    printf("Welcome to Cafe Billing System!\n");
    while (1) {
        printf("\n1. Add Item\n2. View Items\n3. Add Customer\n4. View Customers\n5. Add to Order\n6. View Order\n7. Exit\n");
        int choice;
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addItem();
                break;
            case 2:
                viewItems();
                break;
            case 3:
                addCustomer();
                break;
            case 4:
                viewCustomers();
                break;
            case 5:
                printf("\nEnter customer ID: ");
                int customerId;
                scanf("%d", &customerId);
                printf("\nEnter item ID: ");
                int itemId;
                scanf("%d", &itemId);
                addToOrder(customerId, itemId);
                break;
            case 6:
                printf("\nEnter customer ID: ");
                int orderCustomerId;
                scanf("%d", &orderCustomerId);
                viewOrder(orderCustomerId);
                break;
            case 7:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}
//Falcon-180B DATASET v1.0 Category: Medical Store Management System ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_CUSTOMERS 50

struct Item {
    char name[50];
    int quantity;
    float price;
};

struct Customer {
    char name[50];
    int customer_id;
};

void addItem(struct Item items[], int *num_items) {
    printf("Enter item name: ");
    scanf("%s", items[*num_items].name);

    printf("Enter item quantity: ");
    scanf("%d", &items[*num_items].quantity);

    printf("Enter item price: ");
    scanf("%f", &items[*num_items].price);

    (*num_items)++;
}

void displayItems(struct Item items[], int num_items) {
    printf("\nItem List:\n");
    printf("--------------------\n");
    for (int i = 0; i < num_items; i++) {
        printf("%-20s %-10d %-10.2f\n", items[i].name, items[i].quantity, items[i].price);
    }
}

void addCustomer(struct Customer customers[], int *num_customers) {
    printf("Enter customer name: ");
    scanf("%s", customers[*num_customers].name);

    customers[*num_customers].customer_id = (*num_customers) + 1;

    (*num_customers)++;
}

void displayCustomers(struct Customer customers[], int num_customers) {
    printf("\nCustomer List:\n");
    printf("--------------------\n");
    for (int i = 0; i < num_customers; i++) {
        printf("%-20s %d\n", customers[i].name, customers[i].customer_id);
    }
}

void purchaseItem(struct Item items[], struct Customer customers[], int num_items, int num_customers, int customer_id) {
    int item_id;

    printf("\nEnter item ID to purchase: ");
    scanf("%d", &item_id);

    if (item_id >= 0 && item_id < num_items) {
        printf("Item %s purchased by customer %s.\n", items[item_id].name, customers[customer_id - 1].name);

        items[item_id].quantity--;
    } else {
        printf("Invalid item ID.\n");
    }
}

int main() {
    struct Item items[MAX_ITEMS];
    int num_items = 0;

    struct Customer customers[MAX_CUSTOMERS];
    int num_customers = 0;

    int choice;

    do {
        printf("\nMedical Store Management System\n");
        printf("---------------------------------\n");
        printf("1. Add item\n");
        printf("2. Display items\n");
        printf("3. Add customer\n");
        printf("4. Display customers\n");
        printf("5. Purchase item\n");
        printf("6. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addItem(items, &num_items);
                break;

            case 2:
                displayItems(items, num_items);
                break;

            case 3:
                addCustomer(customers, &num_customers);
                break;

            case 4:
                displayCustomers(customers, num_customers);
                break;

            case 5:
                printf("Enter customer ID: ");
                scanf("%d", &choice);

                purchaseItem(items, customers, num_items, num_customers, choice);
                break;

            case 6:
                printf("Exiting program...\n");
                break;

            default:
                printf("Invalid choice.\n");
        }
    } while (choice!= 6);

    return 0;
}
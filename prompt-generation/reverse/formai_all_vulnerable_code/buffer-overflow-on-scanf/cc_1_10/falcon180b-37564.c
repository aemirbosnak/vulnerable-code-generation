//Falcon-180B DATASET v1.0 Category: Medical Store Management System ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_CUSTOMERS 50

struct item {
    int id;
    char name[50];
    float price;
    int quantity;
};

struct customer {
    int id;
    char name[50];
    char address[100];
    int phone;
};

void add_item(struct item* items, int count) {
    printf("Enter item ID: ");
    scanf("%d", &items[count].id);
    printf("Enter item name: ");
    scanf("%s", items[count].name);
    printf("Enter item price: ");
    scanf("%f", &items[count].price);
    printf("Enter item quantity: ");
    scanf("%d", &items[count].quantity);
}

void display_items(struct item* items, int count) {
    printf("Item ID\tItem Name\tPrice\tQuantity\n");
    for (int i = 0; i < count; i++) {
        printf("%d\t%s\t%.2f\t%d\n", items[i].id, items[i].name, items[i].price, items[i].quantity);
    }
}

void add_customer(struct customer* customers, int count) {
    printf("Enter customer ID: ");
    scanf("%d", &customers[count].id);
    printf("Enter customer name: ");
    scanf("%s", customers[count].name);
    printf("Enter customer address: ");
    scanf("%s", customers[count].address);
    printf("Enter customer phone number: ");
    scanf("%d", &customers[count].phone);
}

void display_customers(struct customer* customers, int count) {
    printf("Customer ID\tCustomer Name\tAddress\tPhone Number\n");
    for (int i = 0; i < count; i++) {
        printf("%d\t%s\t%s\t%d\n", customers[i].id, customers[i].name, customers[i].address, customers[i].phone);
    }
}

int main() {
    struct item items[MAX_ITEMS];
    int item_count = 0;

    struct customer customers[MAX_CUSTOMERS];
    int customer_count = 0;

    int choice;
    while (1) {
        printf("Medical Store Management System\n");
        printf("1. Add item\n");
        printf("2. Display items\n");
        printf("3. Add customer\n");
        printf("4. Display customers\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (item_count >= MAX_ITEMS) {
                    printf("Cannot add more items. Maximum limit reached.\n");
                } else {
                    add_item(items, item_count);
                    item_count++;
                }
                break;
            case 2:
                display_items(items, item_count);
                break;
            case 3:
                if (customer_count >= MAX_CUSTOMERS) {
                    printf("Cannot add more customers. Maximum limit reached.\n");
                } else {
                    add_customer(customers, customer_count);
                    customer_count++;
                }
                break;
            case 4:
                display_customers(customers, customer_count);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
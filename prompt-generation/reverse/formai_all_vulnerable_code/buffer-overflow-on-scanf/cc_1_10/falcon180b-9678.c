//Falcon-180B DATASET v1.0 Category: Cafe Billing System ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_CUSTOMERS 100

struct item {
    char name[50];
    int price;
};

struct customer {
    int id;
    char name[50];
    int orders[MAX_ITEMS];
};

void create_item(struct item *item) {
    printf("Enter item name: ");
    scanf("%s", item->name);
    printf("Enter item price: ");
    scanf("%d", &item->price);
}

void display_item(struct item item) {
    printf("Item name: %s\n", item.name);
    printf("Item price: %d\n", item.price);
}

void create_customer(struct customer *customer) {
    printf("Enter customer name: ");
    scanf("%s", customer->name);
    printf("Enter customer id: ");
    scanf("%d", &customer->id);
}

void display_customer(struct customer customer) {
    printf("Customer name: %s\n", customer.name);
    printf("Customer id: %d\n", customer.id);
}

void add_order(struct customer *customer, struct item *item) {
    int i;
    for(i = 0; i < MAX_ITEMS; i++) {
        if(customer->orders[i] == 0) {
            customer->orders[i] = item->price;
            break;
        }
    }
}

void display_order(struct customer customer, struct item item) {
    int i;
    for(i = 0; i < MAX_ITEMS; i++) {
        if(customer.orders[i] == item.price) {
            printf("Order %d: %s - %d\n", i+1, item.name, item.price);
            break;
        }
    }
}

void main() {
    int choice, id;
    char name[50];
    struct item item;
    struct customer customer;

    printf("Welcome to Cafe Billing System\n");

    do {
        printf("\n");
        printf("1. Create item\n");
        printf("2. Display item\n");
        printf("3. Create customer\n");
        printf("4. Display customer\n");
        printf("5. Add order\n");
        printf("6. Display order\n");
        printf("7. Exit\n");
        printf("\n");

        scanf("%d", &choice);

        switch(choice) {
            case 1:
                create_item(&item);
                printf("\nItem created successfully\n");
                break;
            case 2:
                printf("Enter item id: ");
                scanf("%d", &id);
                display_item(item);
                break;
            case 3:
                create_customer(&customer);
                printf("\nCustomer created successfully\n");
                break;
            case 4:
                printf("Enter customer id: ");
                scanf("%d", &id);
                display_customer(customer);
                break;
            case 5:
                printf("Enter item id: ");
                scanf("%d", &id);
                printf("Enter customer id: ");
                scanf("%d", &customer.id);
                add_order(&customer, &item);
                printf("\nOrder added successfully\n");
                break;
            case 6:
                printf("Enter customer id: ");
                scanf("%d", &id);
                display_order(customer, item);
                break;
            case 7:
                printf("\nExiting Cafe Billing System\n");
                break;
            default:
                printf("\nInvalid choice\n");
        }
    } while(choice!= 7);
}
//Code Llama-13B DATASET v1.0 Category: Medical Store Management System ; Style: Linus Torvalds
// Medical Store Management System
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[100];
    char address[100];
    char phone[10];
    char email[50];
    float balance;
} Customer;

typedef struct {
    char name[100];
    float price;
    int quantity;
} Item;

void add_customer(Customer customers[], int *num_customers) {
    if (*num_customers == 100) {
        printf("Sorry, we can't add more than 100 customers.\n");
        return;
    }

    Customer new_customer;
    printf("Enter the name of the new customer: ");
    scanf("%s", new_customer.name);

    printf("Enter the address of the new customer: ");
    scanf("%s", new_customer.address);

    printf("Enter the phone number of the new customer: ");
    scanf("%s", new_customer.phone);

    printf("Enter the email address of the new customer: ");
    scanf("%s", new_customer.email);

    customers[*num_customers] = new_customer;
    *num_customers += 1;
}

void remove_customer(Customer customers[], int *num_customers) {
    if (*num_customers == 0) {
        printf("Sorry, there are no customers to remove.\n");
        return;
    }

    int index;
    printf("Enter the index of the customer to remove: ");
    scanf("%d", &index);

    if (index < 0 || index >= *num_customers) {
        printf("Sorry, the index is out of range.\n");
        return;
    }

    for (int i = index; i < *num_customers - 1; i++) {
        customers[i] = customers[i + 1];
    }

    *num_customers -= 1;
}

void add_item(Item items[], int *num_items) {
    if (*num_items == 100) {
        printf("Sorry, we can't add more than 100 items.\n");
        return;
    }

    Item new_item;
    printf("Enter the name of the new item: ");
    scanf("%s", new_item.name);

    printf("Enter the price of the new item: ");
    scanf("%f", &new_item.price);

    printf("Enter the quantity of the new item: ");
    scanf("%d", &new_item.quantity);

    items[*num_items] = new_item;
    *num_items += 1;
}

void remove_item(Item items[], int *num_items) {
    if (*num_items == 0) {
        printf("Sorry, there are no items to remove.\n");
        return;
    }

    int index;
    printf("Enter the index of the item to remove: ");
    scanf("%d", &index);

    if (index < 0 || index >= *num_items) {
        printf("Sorry, the index is out of range.\n");
        return;
    }

    for (int i = index; i < *num_items - 1; i++) {
        items[i] = items[i + 1];
    }

    *num_items -= 1;
}

void process_order(Customer customers[], Item items[], int *num_customers, int *num_items) {
    int customer_index, item_index;

    printf("Enter the index of the customer: ");
    scanf("%d", &customer_index);

    if (customer_index < 0 || customer_index >= *num_customers) {
        printf("Sorry, the customer index is out of range.\n");
        return;
    }

    printf("Enter the index of the item: ");
    scanf("%d", &item_index);

    if (item_index < 0 || item_index >= *num_items) {
        printf("Sorry, the item index is out of range.\n");
        return;
    }

    Customer *customer = &customers[customer_index];
    Item *item = &items[item_index];

    if (customer->balance < item->price) {
        printf("Sorry, the customer doesn't have enough balance.\n");
        return;
    }

    customer->balance -= item->price;
    item->quantity -= 1;

    printf("Order processed successfully.\n");
}

int main() {
    Customer customers[100];
    int num_customers = 0;

    Item items[100];
    int num_items = 0;

    char choice;
    while (1) {
        printf("Select an option:\n");
        printf("a) Add a new customer\n");
        printf("b) Remove a customer\n");
        printf("c) Add a new item\n");
        printf("d) Remove an item\n");
        printf("e) Process an order\n");
        printf("f) Exit\n");

        scanf(" %c", &choice);

        switch (choice) {
            case 'a':
                add_customer(customers, &num_customers);
                break;
            case 'b':
                remove_customer(customers, &num_customers);
                break;
            case 'c':
                add_item(items, &num_items);
                break;
            case 'd':
                remove_item(items, &num_items);
                break;
            case 'e':
                process_order(customers, items, &num_customers, &num_items);
                break;
            case 'f':
                return 0;
            default:
                printf("Invalid option.\n");
                break;
        }
    }

    return 0;
}
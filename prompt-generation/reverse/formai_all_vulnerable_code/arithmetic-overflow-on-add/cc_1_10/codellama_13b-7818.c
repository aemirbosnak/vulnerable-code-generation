//Code Llama-13B DATASET v1.0 Category: Cafe Billing System ; Style: ephemeral
// Cafe Billing System

#include <stdio.h>

struct Customer {
    char name[50];
    int table_no;
    int bill;
};

void print_menu() {
    printf("1. Coffee - $1.00\n");
    printf("2. Tea - $0.50\n");
    printf("3. Soda - $1.50\n");
    printf("4. Sandwich - $5.00\n");
    printf("5. Salad - $4.00\n");
    printf("6. Fries - $2.00\n");
}

void add_item(struct Customer *customer, int item_no, int quantity) {
    if (item_no == 1) {
        customer->bill += 1.00 * quantity;
    } else if (item_no == 2) {
        customer->bill += 0.50 * quantity;
    } else if (item_no == 3) {
        customer->bill += 1.50 * quantity;
    } else if (item_no == 4) {
        customer->bill += 5.00 * quantity;
    } else if (item_no == 5) {
        customer->bill += 4.00 * quantity;
    } else if (item_no == 6) {
        customer->bill += 2.00 * quantity;
    } else {
        printf("Invalid item number.\n");
    }
}

void print_bill(struct Customer *customer) {
    printf("Customer: %s\n", customer->name);
    printf("Table No: %d\n", customer->table_no);
    printf("Bill: $%.2f\n", customer->bill);
}

int main() {
    struct Customer customer;

    printf("Welcome to the Cafe Billing System.\n");
    printf("Enter your name: ");
    scanf("%s", customer.name);
    printf("Enter your table number: ");
    scanf("%d", &customer.table_no);

    print_menu();
    printf("Enter the item number you would like to order: ");
    int item_no;
    int quantity;
    scanf("%d", &item_no);
    printf("Enter the quantity: ");
    scanf("%d", &quantity);
    add_item(&customer, item_no, quantity);

    printf("Would you like to add more items? (y/n): ");
    char more;
    scanf(" %c", &more);
    while (more == 'y') {
        printf("Enter the item number you would like to order: ");
        scanf("%d", &item_no);
        printf("Enter the quantity: ");
        scanf("%d", &quantity);
        add_item(&customer, item_no, quantity);
        printf("Would you like to add more items? (y/n): ");
        scanf(" %c", &more);
    }

    print_bill(&customer);

    return 0;
}
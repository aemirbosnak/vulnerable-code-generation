//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct order {
    char name[20];
    int quantity;
    float price;
};

struct bill {
    struct order orders[100];
    int num_orders;
    float total_price;
};

void print_menu() {
    printf("Welcome to the Cafe\n");
    printf("Menu:\n");
    printf("1. Coffee - $2.50\n");
    printf("2. Sandwich - $5.00\n");
    printf("3. Soda - $1.50\n");
    printf("4. Cake - $3.00\n");
}

int take_order(struct bill *customer_bill) {
    printf("Enter your order: ");
    int choice;
    scanf("%d", &choice);
    if (choice < 1 || choice > 4) {
        printf("Invalid choice\n");
        return 1;
    }
    printf("Enter quantity: ");
    int quantity;
    scanf("%d", &quantity);
    if (quantity < 1) {
        printf("Invalid quantity\n");
        return 1;
    }
    switch (choice) {
        case 1:
            strcpy(customer_bill->orders[customer_bill->num_orders].name, "Coffee");
            customer_bill->orders[customer_bill->num_orders].price = 2.50;
            break;
        case 2:
            strcpy(customer_bill->orders[customer_bill->num_orders].name, "Sandwich");
            customer_bill->orders[customer_bill->num_orders].price = 5.00;
            break;
        case 3:
            strcpy(customer_bill->orders[customer_bill->num_orders].name, "Soda");
            customer_bill->orders[customer_bill->num_orders].price = 1.50;
            break;
        case 4:
            strcpy(customer_bill->orders[customer_bill->num_orders].name, "Cake");
            customer_bill->orders[customer_bill->num_orders].price = 3.00;
            break;
    }
    customer_bill->orders[customer_bill->num_orders].quantity = quantity;
    customer_bill->total_price += quantity * customer_bill->orders[customer_bill->num_orders].price;
    customer_bill->num_orders++;
    printf("Order added to bill\n");
    return 0;
}

void print_bill(struct bill customer_bill) {
    printf("Your bill:\n");
    for (int i=0; i<customer_bill.num_orders; i++) {
        printf("%d %s - $%.2f\n", customer_bill.orders[i].quantity, customer_bill.orders[i].name, customer_bill.orders[i].price);
    }
    printf("Total price: $%.2f\n", customer_bill.total_price);
}

int main() {
    srand(time(NULL));
    printf("Welcome to the Cafe Billing System\n");
    printf("Please enter your name: ");
    char customer_name[20];
    scanf("%s", customer_name);
    printf("Hello %s\n", customer_name);
    struct bill customer_bill;
    customer_bill.num_orders = 0;
    customer_bill.total_price = 0;
    int option;
    do {
        print_menu();
        printf("Enter 1 to place an order, 2 to print your bill, or 3 to exit: ");
        scanf("%d", &option);
        switch (option) {
            case 1:
                if (take_order(&customer_bill) != 0) {
                    printf("Order failed\n");
                }
                break;
            case 2:
                print_bill(customer_bill);
                break;
            case 3:
                printf("Thank you for visiting the Cafe\n");
                break;
            default:
                printf("Invalid option\n");
        }
    } while (option != 3);
    return 0;
}
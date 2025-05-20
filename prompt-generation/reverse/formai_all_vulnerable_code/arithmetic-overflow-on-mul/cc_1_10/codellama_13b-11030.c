//Code Llama-13B DATASET v1.0 Category: Cafe Billing System ; Style: thoughtful
#include <stdio.h>
    #include <stdlib.h>
    #include <string.h>

    typedef struct {
        char name[50];
        char email[50];
        int age;
        int phone;
        int order_id;
    } Customer;

    typedef struct {
        int id;
        char name[50];
        int price;
        int quantity;
    } Item;

    typedef struct {
        int id;
        char name[50];
        int price;
        int quantity;
    } Order;

    int main() {
        Customer customer;
        Item item;
        Order order;
        char choice;
        int i, n;

        printf("Welcome to C Cafe Billing System\n");

        // Get customer information
        printf("Enter customer name: ");
        scanf("%s", customer.name);
        printf("Enter customer email: ");
        scanf("%s", customer.email);
        printf("Enter customer age: ");
        scanf("%d", &customer.age);
        printf("Enter customer phone number: ");
        scanf("%d", &customer.phone);

        // Get item information
        printf("Enter item id: ");
        scanf("%d", &item.id);
        printf("Enter item name: ");
        scanf("%s", item.name);
        printf("Enter item price: ");
        scanf("%d", &item.price);
        printf("Enter item quantity: ");
        scanf("%d", &item.quantity);

        // Get order information
        printf("Enter order id: ");
        scanf("%d", &order.id);
        printf("Enter order name: ");
        scanf("%s", order.name);
        printf("Enter order price: ");
        scanf("%d", &order.price);
        printf("Enter order quantity: ");
        scanf("%d", &order.quantity);

        // Display customer information
        printf("Customer Information:\n");
        printf("Name: %s\n", customer.name);
        printf("Email: %s\n", customer.email);
        printf("Age: %d\n", customer.age);
        printf("Phone: %d\n", customer.phone);

        // Display item information
        printf("Item Information:\n");
        printf("Id: %d\n", item.id);
        printf("Name: %s\n", item.name);
        printf("Price: %d\n", item.price);
        printf("Quantity: %d\n", item.quantity);

        // Display order information
        printf("Order Information:\n");
        printf("Id: %d\n", order.id);
        printf("Name: %s\n", order.name);
        printf("Price: %d\n", order.price);
        printf("Quantity: %d\n", order.quantity);

        // Calculate total amount
        float total = (order.price * order.quantity) + (item.price * item.quantity);

        // Display total amount
        printf("Total Amount: %.2f\n", total);

        return 0;
    }
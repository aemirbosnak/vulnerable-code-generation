//Code Llama-13B DATASET v1.0 Category: Cafe Billing System ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Customer {
    char name[50];
    char address[100];
    char phone[15];
    int age;
};

struct Order {
    char name[50];
    char type[50];
    int quantity;
    float price;
};

struct Bill {
    int id;
    char name[50];
    float total;
};

void welcome_message() {
    printf("Welcome to our romantic cafe!\n");
    printf("We serve the most delicious and romantic drinks and food!\n");
    printf("Please choose your favorite drink or food from our menu and enjoy your stay!\n");
}

void show_menu() {
    printf("Our menu:\n");
    printf("1. Espresso\n");
    printf("2. Cappuccino\n");
    printf("3. Latte\n");
    printf("4. Mocha\n");
    printf("5. Coffee\n");
    printf("6. Tea\n");
    printf("7. Smoothie\n");
    printf("8. Fruit Salad\n");
    printf("9. Soup\n");
    printf("10. Sandwich\n");
    printf("11. Chocolate Cake\n");
    printf("12. Ice Cream\n");
}

void take_order(struct Customer customer, struct Order *order) {
    printf("Please enter your name: ");
    scanf("%s", customer.name);
    printf("Please enter your address: ");
    scanf("%s", customer.address);
    printf("Please enter your phone number: ");
    scanf("%s", customer.phone);
    printf("Please enter your age: ");
    scanf("%d", &customer.age);
    printf("Please enter your order: ");
    scanf("%s", order->name);
    printf("Please enter the quantity: ");
    scanf("%d", &order->quantity);
}

void show_bill(struct Bill *bill, struct Order order) {
    printf("Bill:\n");
    printf("Name: %s\n", bill->name);
    printf("Total: %.2f\n", bill->total);
    printf("Order:\n");
    printf("Name: %s\n", order.name);
    printf("Quantity: %d\n", order.quantity);
    printf("Price: %.2f\n", order.price);
}

int main() {
    struct Customer customer;
    struct Order order;
    struct Bill bill;

    welcome_message();
    show_menu();
    take_order(customer, &order);
    bill.total = order.quantity * order.price;
    strcpy(bill.name, customer.name);
    show_bill(&bill, order);

    return 0;
}
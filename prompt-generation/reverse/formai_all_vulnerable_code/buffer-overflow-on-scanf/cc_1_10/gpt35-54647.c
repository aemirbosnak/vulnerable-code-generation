//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>

#define MAX_NAME_LENGTH 50
#define MAX_ITEMS 10
#define MAX_ITEM_NAME_LENGTH 20

typedef struct {
    char name[MAX_NAME_LENGTH];
    int age;
    char gender;
    char phone_number[12];
} Customer;

typedef struct {
    char name[MAX_ITEM_NAME_LENGTH];
    float price;
    int quantity;
} Item;

float total_bill = 0.0;

void print_menu(Item *menu, int num_items) {
    printf("Cafe Menu:\n");
    printf("========================================================================\n");
    printf("%-20s%-10s%-10s\n", "Item", "Price", "Quantity");
    printf("========================================================================\n");

    for (int i = 0; i < num_items; i++) {
        printf("%-20s%-10.2f%-10d\n", menu[i].name, menu[i].price, menu[i].quantity);
    }
}

void bill_customer(Customer customer, Item *menu, int num_items) {
    char choice;
    int order_quantity;
    int item_index;
    float price;

    printf("Enter 'f' to finish order\n");

    do {
        printf("Enter the name of the item: ");
        char item_name[MAX_ITEM_NAME_LENGTH];
        scanf("%s", item_name);
        
        item_index = -1;
        for (int i = 0; i < num_items; i++) {
            if (strcmp(menu[i].name, item_name) == 0) {
                item_index = i;
                break;
            }
        }

        if (item_index == -1) {
            printf("Sorry, we don't have that item on the menu\n");
            continue;
        }

        printf("Enter the quantity of %s: ", item_name);
        scanf("%d", &order_quantity);

        if (order_quantity > menu[item_index].quantity) {
            printf("Sorry, we don't have enough quantity of %s\n", item_name);
            continue;
        }

        price = menu[item_index].price * order_quantity;
        printf("Price of %d %s is %.2f\n", order_quantity, item_name, price);
        total_bill += price;
        menu[item_index].quantity -= order_quantity;

        printf("Order taken, Enter 'f' to finish order or any other key to continue: ");
        char temp;
        scanf(" %c",&temp); // to clear any extra buffer characters
        scanf("%c", &choice);
    } while (choice != 'f');

    // print bill
    printf("\n\n*********************\n");
    printf("Customer details\n");
    printf("*********************\n");
    printf("Name: %s\n", customer.name);
    printf("Age: %d\n", customer.age);
    printf("Gender: %c\n", customer.gender);
    printf("Phone number: %s\n", customer.phone_number);
    printf("*********************\n");
    printf("\n\n");
    printf("*********************\n");
    printf("Bill details\n");
    printf("*********************\n");
    printf("Total bill: %.2f\n\n", total_bill);
    printf("========================================================================\n");
    printf("%-20s%-10s%-10s\n", "Item", "Price", "Quantity");
    printf("========================================================================\n");

    for (int i = 0; i < num_items; i++) {
        printf("%-20s%-10.2f%-10d\n", menu[i].name, menu[i].price, menu[i].quantity);
    }
    printf("\nThank you for visiting!\n");
}

int main() {
    Customer customer;
    Item menu[MAX_ITEMS];
    int num_items;

    printf("Welcome to Cafe Billing System\n");
    printf("Enter customer details:\n");

    printf("Enter name: ");
    scanf("%s", customer.name);

    printf("Enter age: ");
    scanf("%d", &customer.age);

    printf("Enter gender (M/F/O): ");
    scanf(" %c", &customer.gender);

    printf("Enter phone number: ");
    scanf("%s", customer.phone_number);

    printf("\n\n");

    printf("Enter the number of items on the menu: ");
    scanf("%d", &num_items);

    printf("\n\n");

    for (int i = 0; i < num_items; i++) {
        printf("Enter details of item %d\n", i+1);
        printf("Enter name: ");
        scanf("%s", menu[i].name);

        printf("Enter price: ");
        scanf("%f", &menu[i].price);

        printf("Enter quantity: ");
        scanf("%d", &menu[i].quantity);
    }

    printf("\n\n");

    print_menu(menu, num_items);

    bill_customer(customer, menu, num_items);

    return 0;
}
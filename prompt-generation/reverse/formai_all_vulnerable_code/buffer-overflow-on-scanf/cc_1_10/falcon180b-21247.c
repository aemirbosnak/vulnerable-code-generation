//Falcon-180B DATASET v1.0 Category: Cafe Billing System ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define menu items and prices
#define ITEM_COFFEE 1
#define ITEM_TEA 2
#define ITEM_CAKE 3
#define ITEM_COOKIE 4
#define ITEM_SANDWICH 5

const char* menu_items[] = {"Coffee", "Tea", "Cake", "Cookie", "Sandwich"};
int menu_prices[] = {100, 75, 150, 50, 200};

// Define customer details
typedef struct {
    char name[50];
    int order_count;
    int total_spent;
} Customer;

// Function to display menu
void display_menu() {
    printf("Welcome to the Cafe!\n");
    for(int i=0; i<5; i++) {
        printf("%d. %s - $%d\n", i+1, menu_items[i], menu_prices[i]);
    }
}

// Function to place an order
void place_order(Customer* customer) {
    int choice;
    printf("Enter your choice: ");
    scanf("%d", &choice);

    if(choice >= 1 && choice <= 5) {
        customer->order_count++;
        customer->total_spent += menu_prices[choice-1];
        printf("Your order has been placed.\n");
    } else {
        printf("Invalid choice.\n");
    }
}

// Function to display customer details
void display_customer_details(Customer* customer) {
    printf("Name: %s\n", customer->name);
    printf("Order count: %d\n", customer->order_count);
    printf("Total spent: $%d\n", customer->total_spent);
}

int main() {
    Customer customer;
    strcpy(customer.name, "John Doe");
    customer.order_count = 0;
    customer.total_spent = 0;

    int choice;
    while(1) {
        display_menu();
        printf("Enter 1 to place an order, 2 to display customer details, or 3 to exit: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                place_order(&customer);
                break;
            case 2:
                display_customer_details(&customer);
                break;
            case 3:
                printf("Thank you for visiting our cafe!\n");
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}
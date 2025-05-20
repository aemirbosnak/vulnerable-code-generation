//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// define constants for pricing
#define COFFEE_PRICE 50
#define TEA_PRICE 30
#define CAKE_PRICE 60

// define struct for customer
struct Customer {
    char name[50];
    int coffee_count;
    int tea_count;
    int cake_count;
    int total_amount;
};

// function prototypes
void initialize_customer(struct Customer*);
void display_menu();
void process_order(struct Customer*);
void display_receipt(struct Customer);

int main() {
    struct Customer customer;
    initialize_customer(&customer);
    display_menu();
    process_order(&customer);
    display_receipt(customer);
    return 0;
}

// function to initialize customer data
void initialize_customer(struct Customer *customer) {
    strcpy(customer->name, "");
    customer->coffee_count = 0;
    customer->tea_count = 0;
    customer->cake_count = 0;
    customer->total_amount = 0;
}

// function to display menu
void display_menu() {
    printf("Welcome to C Cafe Billing System!\n\n");
    printf("MENU:\n");
    printf("1. Coffee - %d\n", COFFEE_PRICE);
    printf("2. Tea - %d\n", TEA_PRICE);
    printf("3. Cake - %d\n", CAKE_PRICE);
    printf("\n");
}

// function to process customer order
void process_order(struct Customer *customer) {
    int choice;
    do {
        printf("Enter choice (1 for coffee, 2 for tea, 3 for cake, 0 to exit): ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                customer->coffee_count++;
                customer->total_amount += COFFEE_PRICE;
                break;
            case 2:
                customer->tea_count++;
                customer->total_amount += TEA_PRICE;
                break;
            case 3:
                customer->cake_count++;
                customer->total_amount += CAKE_PRICE;
                break;
            case 0:
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while(choice != 0);
}

// function to display customer receipt
void display_receipt(struct Customer customer) {
    printf("\n");
    printf("Customer name: %s\n", customer.name);
    printf("Coffee count: %d\n", customer.coffee_count);
    printf("Tea count: %d\n", customer.tea_count);
    printf("Cake count: %d\n", customer.cake_count);
    printf("Total amount: %d\n", customer.total_amount);
    printf("\n");
}
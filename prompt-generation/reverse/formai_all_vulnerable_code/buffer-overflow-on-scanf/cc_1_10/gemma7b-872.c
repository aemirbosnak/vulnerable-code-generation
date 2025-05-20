//Gemma-7B DATASET v1.0 Category: Cafe Billing System ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ORDERS 10

typedef struct Order {
    char name[20];
    char item[20];
    int quantity;
    float price;
} Order;

Order orders[MAX_ORDERS];

void display_menu() {
    printf("\nWelcome to the C Cafe!\n");
    printf("-------------------\n");
    printf("1. Coffee\n");
    printf("2. Tea\n");
    printf("3. Juice\n");
    printf("4. Smoothie\n");
    printf("5. Pastry\n");
    printf("-------------------\n");
}

void add_order() {
    printf("Enter your name: ");
    scanf("%s", orders[MAX_ORDERS - 1].name);

    printf("Enter item name: ");
    scanf("%s", orders[MAX_ORDERS - 1].item);

    printf("Enter quantity: ");
    scanf("%d", &orders[MAX_ORDERS - 1].quantity);

    printf("Enter price: ");
    scanf("%f", &orders[MAX_ORDERS - 1].price);
}

void calculate_total() {
    int total_cost = 0;
    for (int i = 0; i < MAX_ORDERS; i++) {
        total_cost += orders[i].quantity * orders[i].price;
    }
    printf("Total cost: $%.2f\n", total_cost);
}

int main() {
    int choice;

    display_menu();

    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            add_order();
            break;
        case 2:
            add_order();
            break;
        case 3:
            add_order();
            break;
        case 4:
            add_order();
            break;
        case 5:
            add_order();
            break;
        default:
            printf("Invalid choice\n");
    }

    calculate_total();

    return 0;
}
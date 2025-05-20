//MISTRAL-7B DATASET v1.0 Category: Cafe Billing System ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 50
#define MAX_NAME_LEN 50
#define MAX_QUANTITY 10

typedef struct {
    char name[MAX_NAME_LEN];
    float price;
    int quantity;
} Item;

Item menu[MAX_ITEMS];
float total_bill = 0.0;
int num_items = 0;

void add_item() {
    if (num_items >= MAX_ITEMS) {
        printf("Error: Maximum number of items reached.\n");
        return;
    }

    printf("Enter item name: ");
    scanf("%s", menu[num_items].name);

    printf("Enter item price: ");
    scanf("%f", &menu[num_items].price);

    printf("Enter item quantity: ");
    scanf("%d", &menu[num_items].quantity);

    num_items++;
}

void display_menu() {
    printf("\n--- MENU ---\n");

    for (int i = 0; i < num_items; i++) {
        printf("%d. %s - %.2f\n", i+1, menu[i].name, menu[i].price);
    }
}

void calculate_bill() {
    printf("\n--- BILL ---\n");

    for (int i = 0; i < num_items; i++) {
        float item_cost = menu[i].price * menu[i].quantity;
        total_bill += item_cost;
        printf("%s - %.2f x %d = %.2f\n", menu[i].name, menu[i].price, menu[i].quantity, item_cost);
    }

    printf("\nTotal bill: %.2f\n", total_bill);
}

int main() {
    int choice;

    printf("Welcome to the Café Billing System!\n");

    while (1) {
        display_menu();
        printf("\n1. Add Item\n2. Calculate Bill\n3. Exit\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_item();
                break;
            case 2:
                calculate_bill();
                total_bill = 0.0; // Reset total bill after calculating it
                break;
            case 3:
                printf("Thank you for using our Café Billing System.\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_ORDER 10

struct item {
    int id;
    char name[30];
    double price;
} menu[MAX_ITEMS];

struct order_item {
    int id;
    char name[30];
    double price;
    int quantity;
} order[MAX_ORDER];

int menu_size = 0;
int order_size = 0;

// Function to add item to the menu
void add_item() {
    char name[30];
    double price;

    printf("Enter item name: ");
    scanf("%s", name);
    printf("Enter item price: ");
    scanf("%lf", &price);

    menu[menu_size].id = menu_size + 1;
    strcpy(menu[menu_size].name, name);
    menu[menu_size].price = price;
    menu_size++;

    printf("Item added successfully!\n");
}

// Function to display menu
void display_menu() {
    printf("Menu:\n");
    printf("===============================\n");
    printf("ID\tName\t\tPrice\n");
    printf("===============================\n");
    for (int i = 0; i < menu_size; i++) {
        printf("%d\t%-20s%.2lf\n", menu[i].id, menu[i].name, menu[i].price);
    }
    printf("===============================\n");
}

// Function to add item to order
void add_to_order() {
    int id, quantity;
    printf("Enter item ID: ");
    scanf("%d", &id);
    printf("Enter quantity: ");
    scanf("%d", &quantity);

    // Check if item is already in order
    for (int i = 0; i < order_size; i++) {
        if (order[i].id == id) {
            order[i].quantity += quantity;
            printf("Quantity updated successfully!\n");
            return;
        }
    }

    // Add item to order
    for (int i = 0; i < menu_size; i++) {
        if (menu[i].id == id) {
            order[order_size].id = id;
            strcpy(order[order_size].name, menu[i].name);
            order[order_size].price = menu[i].price;
            order[order_size].quantity = quantity;
            order_size++;
            printf("Item added to order successfully!\n");
            return;
        }
    }

    printf("Invalid item ID!\n");
}

// Function to display order
void display_order() {
    double total = 0;

    printf("Order:\n");
    printf("=================================\n");
    printf("ID\tName\t\tPrice\tQuantity\n");
    printf("=================================\n");
    for (int i = 0; i < order_size; i++) {
        printf("%d\t%-20s%.2lf\t%d\n", order[i].id, order[i].name, order[i].price, order[i].quantity);
        total += order[i].price * order[i].quantity;
    }
    printf("=================================\n");
    printf("Total: %.2lf\n", total);
}

// Function to remove item from order
void remove_from_order() {
    int id;
    printf("Enter item ID to remove: ");
    scanf("%d", &id);

    for (int i = 0; i < order_size; i++) {
        if (order[i].id == id) {
            // Shift elements to remove item from array
            for (int j = i; j < order_size - 1; j++) {
                order[j] = order[j+1];
            }
            order_size--;
            printf("Item removed from order successfully!\n");
            return;
        }
    }

    printf("Invalid item ID!\n");
}

int main() {
    int choice;

    while (1) {
        printf("C Cafe Billing System\n");
        printf("==============================\n");
        printf("1. Add item to menu\n");
        printf("2. Display menu\n");
        printf("3. Add item to order\n");
        printf("4. Display order\n");
        printf("5. Remove item from order\n");
        printf("6. Exit\n");
        printf("==============================\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: add_item(); break;
            case 2: display_menu(); break;
            case 3: add_to_order(); break;
            case 4: display_order(); break;
            case 5: remove_from_order(); break;
            case 6: exit(0);
            default: printf("Invalid choice!\n");
        }
    }

    return 0;
}
//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: Ada Lovelace
/* The C Café Billing System */

// Written in Ada Lovelace style by [Your Name]

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct MenuItem {
    char name[20];
    int price;
};

typedef struct MenuItem MenuItem;

struct Order {
    char name[20];
    int table_number;
    int total_price;
    MenuItem items[10];
    int num_items;
};

typedef struct Order Order;

// Function to print the main menu
void print_menu() {
    printf("Welcome to the C Café!\n");
    printf("Menu:\n");
    printf("1. Add order\n");
    printf("2. View order\n");
    printf("3. Exit\n");
}

// Function to add an order
Order add_order() {
    Order order;
    printf("Enter customer name: ");
    scanf("%s", order.name);
    printf("Enter table number: ");
    scanf("%d", &order.table_number);
    order.total_price = 0;
    order.num_items = 0;
    int choice = 0;
    while(choice != 4) {
        printf("Menu:\n");
        printf("1. Coffee - $5\n");
        printf("2. Tea - $3\n");
        printf("3. Cake - $8\n");
        printf("4. Done\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                strcpy(order.items[order.num_items].name, "Coffee");
                order.items[order.num_items].price = 5;
                order.num_items++;
                order.total_price += 5;
                break;
            case 2:
                strcpy(order.items[order.num_items].name, "Tea");
                order.items[order.num_items].price = 3;
                order.num_items++;
                order.total_price += 3;
                break;
            case 3:
                strcpy(order.items[order.num_items].name, "Cake");
                order.items[order.num_items].price = 8;
                order.num_items++;
                order.total_price += 8;
                break;
            case 4:
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
    return order;
}

// Function to view an order
void view_order(Order order) {
    printf("Order for %s at table %d:\n", order.name, order.table_number);
    for(int i=0; i<order.num_items; i++) {
        printf("%s - $%d\n", order.items[i].name, order.items[i].price);
    }
    printf("Total: $%d\n", order.total_price);
}

int main() {
    Order orders[10];
    int num_orders = 0;
    int choice = 0;
    while(choice != 3) {
        print_menu();
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                if(num_orders < 10) {
                    orders[num_orders] = add_order();
                    num_orders++;
                    printf("Order added.\n");
                }
                else {
                    printf("Error: maximum orders reached.\n");
                }
                break;
            case 2:
                if(num_orders == 0) {
                    printf("No orders to view.\n");
                }
                else {
                    int index;
                    printf("Enter order number (1-%d): ", num_orders);
                    scanf("%d", &index);
                    if(index >= 1 && index <= num_orders) {
                        view_order(orders[index-1]);
                    }
                    else {
                        printf("Invalid order number. Try again.\n");
                    }
                }
                break;
            case 3:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
    return 0;
}
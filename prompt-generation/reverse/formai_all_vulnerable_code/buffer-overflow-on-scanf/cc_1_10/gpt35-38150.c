//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    int quantity;
    float price;
} Item;

typedef struct {
    Item items[50];
    int num_items;
} Order;

float calculate_total(Order order) {
    float total = 0.0;
    for (int i = 0; i < order.num_items; ++i) {
        total += order.items[i].price * order.items[i].quantity;
    }
    return total;
}

void print_order(Order order) {
    printf("+----------------------------------------------+\n");
    printf("|                      CAFE                    |\n");
    printf("+----------------------------------------------+\n");
    printf("| ITEM                            | QTY | PRICE |\n");
    printf("+----------------------------------------------+\n");
    for (int i = 0; i < order.num_items; ++i) {
        printf("| %-30s | %3d | $%.2f |\n",
            order.items[i].name,
            order.items[i].quantity,
            order.items[i].price
        );
    }
    printf("+----------------------------------------------+\n");
    printf("| TOTAL                                        |\n");
    printf("|                                $%.2f |\n", calculate_total(order));
    printf("+----------------------------------------------+\n");
}

int main() {
    Order order;
    order.num_items = 0;

    while (1) {
        // Print menu and get choice
        printf("\nSelect an item:\n");
        printf("1. Coffee - $2.50\n");
        printf("2. Tea - $1.50\n");
        printf("3. Sandwich - $4.00\n");
        printf("4. Check out\n");
        printf("5. Exit\n");
        printf("> ");

        int choice;
        scanf("%d", &choice);

        if (choice == 1) {
            // Add coffee to order
            if (order.num_items >= 50) {
                printf("Sorry, your order is too large to add another item.\n");
            }
            else {
                strcpy(order.items[order.num_items].name, "Coffee");
                order.items[order.num_items].price = 2.5;
                printf("Enter quantity: ");
                scanf("%d", &order.items[order.num_items].quantity);
                order.num_items++;
            }
        }
        else if (choice == 2) {
            // Add tea to order
            if (order.num_items >= 50) {
                printf("Sorry, your order is too large to add another item.\n");
            }
            else {
                strcpy(order.items[order.num_items].name, "Tea");
                order.items[order.num_items].price = 1.5;
                printf("Enter quantity: ");
                scanf("%d", &order.items[order.num_items].quantity);
                order.num_items++;
            }
        }
        else if (choice == 3) {
            // Add sandwich to order
            if (order.num_items >= 50) {
                printf("Sorry, your order is too large to add another item.\n");
            }
            else {
                strcpy(order.items[order.num_items].name, "Sandwich");
                order.items[order.num_items].price = 4.0;
                printf("Enter quantity: ");
                scanf("%d", &order.items[order.num_items].quantity);
                order.num_items++;
            }
        }
        else if (choice == 4) {
            // Check out and print order
            print_order(order);
            break;
        }
        else if (choice == 5) {
            // Exit program
            break;
        }
        else {
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
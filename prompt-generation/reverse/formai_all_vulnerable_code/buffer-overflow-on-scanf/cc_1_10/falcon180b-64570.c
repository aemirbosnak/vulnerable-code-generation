//Falcon-180B DATASET v1.0 Category: Warehouse Management System ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000
#define NUM_OF_PRODUCTS 10

typedef struct {
    char name[50];
    int quantity;
    int price;
} Product;

Product products[NUM_OF_PRODUCTS] = {
    {"Product 1", 50, 10},
    {"Product 2", 25, 20},
    {"Product 3", 75, 30},
    {"Product 4", 100, 40},
    {"Product 5", 35, 50},
    {"Product 6", 60, 60},
    {"Product 7", 80, 70},
    {"Product 8", 45, 80},
    {"Product 9", 20, 90},
    {"Product 10", 30, 100}
};

typedef struct {
    char name[50];
    int quantity;
    int price;
} Order;

Order order[MAX_SIZE];
int num_of_orders = 0;

void add_order() {
    printf("Enter order name: ");
    scanf("%s", order[num_of_orders].name);
    printf("Enter order quantity: ");
    scanf("%d", &order[num_of_orders].quantity);
    printf("Enter order price: ");
    scanf("%d", &order[num_of_orders].price);
    num_of_orders++;
}

void display_orders() {
    printf("Orders:\n");
    for (int i = 0; i < num_of_orders; i++) {
        printf("%s - %d units - $%d\n", order[i].name, order[i].quantity, order[i].price);
    }
}

int main() {
    int choice;
    do {
        printf("Warehouse Management System\n");
        printf("1. Add order\n");
        printf("2. Display orders\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_order();
                break;
            case 2:
                display_orders();
                break;
            case 3:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice!= 3);
    return 0;
}
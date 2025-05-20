//MISTRAL-7B DATASET v1.0 Category: Medical Store Management System ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_ITEMS 100

typedef struct {
    char name[50];
    int stock;
    float price;
} Item;

Item items[MAX_ITEMS];
int num_items = 0;

void add_item(char *name, int qty, float price) {
    if (num_items >= MAX_ITEMS) {
        printf("Out of stock!\n");
        return;
    }

    strcpy(items[num_items].name, name);
    items[num_items].stock = qty;
    items[num_items].price = price;
    num_items++;
}

void display_inventory() {
    printf("\n--- SHOCKED MEDICAL STORE INVENTORY ---\n");

    for (int i = 0; i < num_items; i++) {
        printf("%s: %d units @ $%.2f\n", items[i].name, items[i].stock, items[i].price);
    }
}

int main() {
    char input[100];
    int qty;
    float price;

    while (true) {
        printf("\n--- WELCOME TO SHOCKED MEDICAL STORE ---\n");
        printf("1. Add Item\n2. Display Inventory\n3. Exit\n");
        printf("Enter your choice: ");
        scanf("%s", input);

        if (strcmp(input, "1") == 0) {
            printf("Enter item name: ");
            scanf("%s", input);
            printf("Enter quantity: ");
            scanf("%d", &qty);
            printf("Enter price: $");
            scanf("%f", &price);

            add_item(input, qty, price);
        } else if (strcmp(input, "2") == 0) {
            display_inventory();
        } else if (strcmp(input, "3") == 0) {
            printf("Exiting...\n");
            break;
        } else {
            printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}
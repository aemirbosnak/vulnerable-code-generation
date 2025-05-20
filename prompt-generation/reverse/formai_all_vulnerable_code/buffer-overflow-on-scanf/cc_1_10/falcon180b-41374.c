//Falcon-180B DATASET v1.0 Category: Cafe Billing System ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 1000 // Maximum number of items

// Structure for item
struct item {
    char name[50]; // Name of the item
    int price; // Price of the item
};

// Function to add an item to the bill
void add_item(struct item* bill, int num_items, char* name, int price) {
    if (num_items >= MAX_ITEMS) {
        printf("Error: Maximum number of items reached.\n");
        return;
    }
    strcpy(bill[num_items].name, name);
    bill[num_items].price = price;
    num_items++;
}

// Function to calculate the total cost of the bill
int calculate_total(struct item* bill, int num_items) {
    int total = 0;
    for (int i = 0; i < num_items; i++) {
        total += bill[i].price;
    }
    return total;
}

// Function to print the bill
void print_bill(struct item* bill, int num_items) {
    printf("Bill:\n");
    for (int i = 0; i < num_items; i++) {
        printf("%s: $%d\n", bill[i].name, bill[i].price);
    }
    printf("Total: $%d\n", calculate_total(bill, num_items));
}

int main() {
    struct item bill[MAX_ITEMS]; // Bill structure
    int num_items = 0; // Number of items in the bill
    char name[50]; // Name of the item
    int price; // Price of the item

    // Main menu
    while (1) {
        printf("Cafe Billing System\n");
        printf("1. Add item\n");
        printf("2. Print bill\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &num_items);

        switch (num_items) {
        case 1:
            printf("Enter name of the item: ");
            scanf("%s", name);
            printf("Enter price of the item: ");
            scanf("%d", &price);
            add_item(bill, num_items, name, price);
            break;
        case 2:
            print_bill(bill, num_items);
            break;
        case 3:
            exit(0);
        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}
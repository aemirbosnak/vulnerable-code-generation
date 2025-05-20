//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store item details
typedef struct {
    int id;
    char name[100];
    float price;
    int quantity;
} item;

// Global array to store items in the warehouse
item items[100];
int num_items = 0;

// Function to add an item to the warehouse
void add_item() {
    int id, quantity;
    char name[100];
    float price;
    printf("Enter item id: ");
    scanf("%d", &id);
    printf("Enter item name: ");
    scanf("%s", name);
    printf("Enter item price: ");
    scanf("%f", &price);
    printf("Enter item quantity: ");
    scanf("%d", &quantity);
    items[num_items].id = id;
    strcpy(items[num_items].name, name);
    items[num_items].price = price;
    items[num_items].quantity = quantity;
    num_items++;
    printf("Item added successfully!\n");
}

// Function to remove an item from the warehouse
void remove_item() {
    int id, i, found = 0;
    printf("Enter item id to remove: ");
    scanf("%d", &id);
    for (i = 0; i < num_items; i++) {
        if (items[i].id == id) {
            found = 1;
            break;
        }
    }
    if (found) {
        for (; i < num_items - 1; i++) {
            items[i] = items[i+1];
        }
        num_items--;
        printf("Item removed successfully!\n");
    } else {
        printf("Item not found!\n");
    }
}

// Function to display all items in the warehouse
void display_items() {
    int i;
    printf("%-10s %-50s %-10s %-10s\n", "ID", "Name", "Price", "Quantity");
    printf("------------------------------------------------------------\n");
    for (i = 0; i < num_items; i++) {
        printf("%-10d %-50s %-10.2f %-10d\n", items[i].id, items[i].name, items[i].price, items[i].quantity);
    }
    printf("------------------------------------------------------------\n");
}

// Main function
int main() {
    char choice[10];
    while (1) {
        printf("1. Add item\n");
        printf("2. Remove item\n");
        printf("3. Display items\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%s", choice);
        if (strcmp(choice, "1") == 0) {
            add_item();
        } else if (strcmp(choice, "2") == 0) {
            remove_item();
        } else if (strcmp(choice, "3") == 0) {
            display_items();
        } else if (strcmp(choice, "4") == 0) {
            printf("Exiting program...\n");
            break;
        } else {
            printf("Invalid choice!\n");
        }
    }
    return 0;
}
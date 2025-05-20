//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Struct for item */
typedef struct Item {
    char name[50];
    int quantity;
    float cost;
} Item;

/* Function to add an item */
void add_item(Item* items, int* num_items) {
    Item item;
    
    /* Get input for item details */
    printf("Enter name of item: ");
    scanf("%s", item.name);
    printf("Enter quantity of item: ");
    scanf("%d", &item.quantity);
    printf("Enter cost of item: ");
    scanf("%f", &item.cost);
    
    /* Add item to array */
    items[*num_items] = item;
    (*num_items)++;
    
    printf("Item added successfully!\n");
}

/* Function to remove an item */
void remove_item(Item* items, int* num_items) {
    char name[50];
    int i, found = 0;
    
    /* Get name of item to be removed */
    printf("Enter name of item to be removed: ");
    scanf("%s", name);
    
    /* Find item in array */
    for (i = 0; i < *num_items; i++) {
        if (strcmp(items[i].name, name) == 0) {
            /* Shift all items after it by one position */
            for (int j = i; j < (*num_items)-1; j++) {
                items[j] = items[j+1];
            }
            (*num_items)--;
            found = 1;
            break;
        }
    }
    
    if (found) {
        printf("Item removed successfully!\n");
    } else {
        printf("Item not found!\n");
    }
}

/* Function to display all items */
void display_items(Item* items, int num_items) {
    if (num_items == 0) {
        printf("No items to display!\n");
        return;
    }
    
    printf("\n%-15s%-15s%-15s\n", "Name", "Quantity", "Cost");
    for (int i = 0; i < num_items; i++) {
        printf("%-15s%-15d%-15.2f\n", items[i].name, items[i].quantity, items[i].cost);
    }
    printf("\n");
}

int main() {
    Item items[100];
    int num_items = 0, choice;
    
    do {
        printf("======= Warehouse Management System Menu =======\n");
        printf("1. Add item\n");
        printf("2. Remove item\n");
        printf("3. Display all items\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                add_item(items, &num_items);
                break;
            case 2:
                remove_item(items, &num_items);
                break;
            case 3:
                display_items(items, num_items);
                break;
            case 4:
                printf("Thank you for using Warehouse Management System!\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 4);
    
    return 0;
}
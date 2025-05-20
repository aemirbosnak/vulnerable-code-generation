//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 100

// struct for inventory items
typedef struct {
    char item_name[MAX_SIZE];
    int item_id;
    int quantity;
    float price;
} item;

// function to add new items to inventory
void add_item(item inventory[], int *num_items) {
    printf("Enter item name: ");
    scanf("%s", inventory[*num_items].item_name);
    
    printf("Enter item ID: ");
    scanf("%d", &inventory[*num_items].item_id);
    
    printf("Enter quantity: ");
    scanf("%d", &inventory[*num_items].quantity);
    
    printf("Enter price: ");
    scanf("%f", &inventory[*num_items].price);
    
    (*num_items)++;
}

// function to search for an item in inventory by ID
int search_item(item inventory[], int *num_items, int search_id) {
    for (int i = 0; i < *num_items; i++) {
        if (inventory[i].item_id == search_id) {
            return i;
        }
    }
    return -1;
}

// function to update existing item in inventory 
void update_item(item inventory[], int *num_items) {
    int search_id;
    printf("Enter item ID to update: ");
    scanf("%d", &search_id);
    int index = search_item(inventory, num_items, search_id);
    if (index == -1) {
        printf("Item not found.\n");
    } else {
        printf("Enter new item name (leave blank to keep the same): ");
        scanf("%s", inventory[index].item_name);
        
        printf("Enter new quantity (enter -1 to keep the same): ");
        scanf("%d", &inventory[index].quantity);
        
        if (inventory[index].quantity != -1) {
            printf("Enter new price (enter -1 to keep the same): ");
            scanf("%f", &inventory[index].price);
        }
    }
}

// function to delete existing item in inventory
void delete_item(item inventory[], int *num_items) {
    int search_id;
    printf("Enter item ID to delete: ");
    scanf("%d", &search_id);
    int index = search_item(inventory, num_items, search_id);
    if (index == -1) {
        printf("Item not found.\n");
    } else {
        for (int i = index; i < *num_items - 1; i++) {
            inventory[i] = inventory[i + 1];
        }
        (*num_items)--;
        printf("Item deleted successfully.\n");
    }
}

// main function
int main() {
    item inventory[MAX_SIZE];
    int num_items = 0;

    while (1) {
        printf("\nWarehouse Management System\n");
        printf("---------------------------\n");
        printf("1. Add item to inventory\n");
        printf("2. Update item in inventory\n");
        printf("3. Delete item from inventory\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_item(inventory, &num_items);
                break;
            case 2:
                update_item(inventory, &num_items);
                break;
            case 3:
                delete_item(inventory, &num_items);
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}
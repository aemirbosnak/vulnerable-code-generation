//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: high level of detail
#include <stdio.h>
#include <string.h>

#define MAX_ITEM_NAME 50
#define MAX_LOCATION 20
#define MAX_ITEMS 100

typedef struct item_t {
    char name[MAX_ITEM_NAME];
    int quantity;
    char location[MAX_LOCATION];
} Item;

void menu() {
    printf("\n===================\n");
    printf("1. Add Item\n");
    printf("2. Remove Item\n");
    printf("3. Move Item\n");
    printf("4. List All Items\n");
    printf("5. Exit\n");
    printf("===================\n");
}

int add_item(Item item_list[], int item_count) {
    if (item_count == MAX_ITEMS) {
        printf("Warehouse is already full. Cannot add more items.\n");
        return item_count;
    }
    
    Item item;
    printf("Enter item name: ");
    scanf("%s", item.name);
    printf("Enter quantity: ");
    scanf("%d", &item.quantity);
    printf("Enter location: ");
    scanf("%s", item.location);
    
    item_list[item_count] = item;
    printf("Item added successfully.\n");
    return item_count + 1;
}

int remove_item(Item item_list[], int item_count) {
    if (item_count == 0) {
        printf("Warehouse is already empty. Cannot remove any items.\n");
        return item_count;
    }
    
    char item_name[MAX_ITEM_NAME];
    printf("Enter item name: ");
    scanf("%s", item_name);
    
    int index_to_remove = -1;
    for (int i = 0; i < item_count; i++) {
        if (strcmp(item_list[i].name, item_name) == 0) {
            index_to_remove = i;
            break;
        }
    }
    
    if (index_to_remove == -1) {
        printf("Item not found in the warehouse.\n");
        return item_count;
    }
    
    for (int i = index_to_remove; i < item_count - 1; i++) {
        item_list[i] = item_list[i+1];
    }
    
    printf("Item removed successfully.\n");
    return item_count - 1;
}

void print_item(Item item) {
    printf("%-20s | %-10d | %-10s\n", item.name, item.quantity, item.location);
}

void list_all_items(Item item_list[], int item_count) {
    if (item_count == 0) {
        printf("Warehouse is currently empty.\n");
        return;
    }
    
    printf("Name                | Quantity  | Location  \n");
    printf("-------------------------------------------\n");
    for (int i = 0; i < item_count; i++) {
        print_item(item_list[i]);
    }
}

int move_item(Item item_list[], int item_count) {
    if (item_count == 0) {
        printf("Warehouse is currently empty. Cannot move any items.\n");
        return item_count;
    }
    
    char item_name[MAX_ITEM_NAME];
    printf("Enter item name: ");
    scanf("%s", item_name);
    
    int index_to_move = -1;
    for (int i = 0; i < item_count; i++) {
        if (strcmp(item_list[i].name, item_name) == 0) {
            index_to_move = i;
            break;
        }
    }
    
    if (index_to_move == -1) {
        printf("Item not found in the warehouse.\n");
        return item_count;
    }
    
    char new_location[MAX_LOCATION];
    printf("Enter new location: ");
    scanf("%s", new_location);
    
    strcpy(item_list[index_to_move].location, new_location);
    printf("Item location updated successfully.\n");
    return item_count;
}

int main() {
    Item item_list[MAX_ITEMS];
    int item_count = 0;
    
    int choice = 0;
    while (choice != 5) {
        menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                item_count = add_item(item_list, item_count);
                break;
            case 2:
                item_count = remove_item(item_list, item_count);
                break;
            case 3:
                item_count = move_item(item_list, item_count);
                break;
            case 4:
                list_all_items(item_list, item_count);
                break;
            case 5:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    
    return 0;
}
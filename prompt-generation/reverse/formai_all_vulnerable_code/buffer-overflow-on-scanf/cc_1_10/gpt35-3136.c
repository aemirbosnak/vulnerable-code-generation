//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 1000

struct Item{
    int item_id;
    char name[50];
    int quantity;
};

struct Warehouse{
    struct Item items[MAX_ITEMS];
    int num_items;
};

void add_item(struct Warehouse* warehouse, struct Item* item);
void remove_item(struct Warehouse* warehouse, int item_id);
void display_stock(struct Warehouse* warehouse);

int main(){

    struct Warehouse warehouse;
    warehouse.num_items = 0;

    int choice = 0;
    while(choice != 4){
        printf("\n\nWarehouse Management System");
        printf("\n1. Add Item");
        printf("\n2. Remove Item");
        printf("\n3. Display Stock");
        printf("\n4. Exit");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                printf("\nEnter item details: ");
                struct Item item;

                printf("\nItem ID: ");
                scanf("%d", &item.item_id);

                printf("\nName: ");
                scanf("%s", &item.name);

                printf("\nQuantity: ");
                scanf("%d", &item.quantity);

                add_item(&warehouse, &item);
                break;
            case 2:
                printf("\nEnter Item ID to remove: ");
                int id;
                scanf("%d", &id);
                remove_item(&warehouse, id);
                break;
            case 3:
                display_stock(&warehouse);
                break;
            case 4:
                printf("\nExiting...");
                break;
            default:
                printf("\nInvalid choice, please try again.");
        }
    }

    return 0;
}

void add_item(struct Warehouse* warehouse, struct Item* item){
    if(warehouse->num_items == MAX_ITEMS){
        printf("\nWarehouse is full, cannot add more items.");
        return;
    }

    for(int i=0; i<warehouse->num_items; i++){
        if(warehouse->items[i].item_id == item->item_id){
            // if item ID already exists in warehouse, update quantity
            warehouse->items[i].quantity += item->quantity;
            printf("\nQuantity for item with ID %d updated to %d", item->item_id, warehouse->items[i].quantity);
            return;
        }
    }

    // if item ID does not exist in warehouse, add it as a new item
    warehouse->items[warehouse->num_items] = *item;
    warehouse->num_items++;
    printf("\nItem added successfully!");
}

void remove_item(struct Warehouse* warehouse, int item_id){
    for(int i=0; i<warehouse->num_items; i++){
        if(warehouse->items[i].item_id == item_id){
            // if item ID exists in warehouse, remove the item
            for(int j=i; j<warehouse->num_items-1; j++){
                warehouse->items[j] = warehouse->items[j+1];
            }
            warehouse->num_items--;
            printf("\nItem with ID %d removed successfully!", item_id);
            return;
        }
    }
    printf("\nItem with ID %d not found in warehouse.", item_id);
}

void display_stock(struct Warehouse* warehouse){
    if(warehouse->num_items == 0){
        printf("\nWarehouse is empty.");
        return;
    }

    printf("\n\nStock in warehouse:");
    printf("\n%-10s %-20s %-10s", "ID", "Name", "Quantity");

    for(int i=0; i<warehouse->num_items; i++){
        printf("\n%-10d %-20s %-10d", warehouse->items[i].item_id, warehouse->items[i].name, warehouse->items[i].quantity);
    }
}
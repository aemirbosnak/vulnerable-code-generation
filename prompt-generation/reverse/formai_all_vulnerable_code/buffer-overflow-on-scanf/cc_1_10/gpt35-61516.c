//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

struct Item {
    char name[20];
    int quantity;
    float price;
};

void add_item(struct Item inventory[], int *num_items);
void display_inventory(struct Item inventory[], int num_items);
void search_for_item(struct Item inventory[], int num_items);
float calculate_total_value(struct Item inventory[], int num_items);

int main(){
    int num_items = 0, choice;
    struct Item inventory[50]; // Assume max 50 items can be stored in the warehouse

    do {
        printf("\nWarehouse Management System\n");
        printf("1. Add Item\n2. Display Inventory\n3. Search for Item\n4. Calculate Total Value\n5. Exit\n");
        printf("Enter Choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                add_item(inventory, &num_items);
                break;

            case 2:
                display_inventory(inventory, num_items);
                break;

            case 3:
                search_for_item(inventory, num_items);
                break;

            case 4:
                printf("\nTotal Value of Inventory: $%.2f\n", calculate_total_value(inventory, num_items));
                break;

            case 5:
                printf("\nExiting Warehouse Management System...\n");
                break;

            default:
                printf("\nInvalid Choice. Please try again.\n");
                break;
        }
    } while(choice != 5);

    return 0;
}

void add_item(struct Item inventory[], int *num_items){
    if(*num_items == 50){
        printf("\nInventory Full. Cannot add more items.\n");
        return;
    }

    printf("\nEnter Item Name: ");
    scanf("%s", inventory[*num_items].name);
    printf("Enter Quantity: ");
    scanf("%d", &inventory[*num_items].quantity);
    printf("Enter Price: ");
    scanf("%f", &inventory[*num_items].price);

    *num_items += 1;
    printf("\nItem added to Inventory.\n");
}

void display_inventory(struct Item inventory[], int num_items){
    if(num_items == 0){
        printf("\nInventory Empty. No items to display.\n");
        return;
    }

    printf("\nInventory:\nName\tQuantity\tPrice\n");
    for(int i = 0; i < num_items; i++){
        printf("%s\t%d\t\t$%.2f\n", inventory[i].name, inventory[i].quantity, inventory[i].price);
    }
}

void search_for_item(struct Item inventory[], int num_items){
    if(num_items == 0){
        printf("\nInventory Empty. No items to search.\n");
        return;
    }

    char name[20];
    printf("\nEnter Item to Search: ");
    scanf("%s", name);

    for(int i = 0; i < num_items; i++){
        if(strcmp(name, inventory[i].name) == 0){
            printf("\nItem Found:\nName\tQuantity\tPrice\n");
            printf("%s\t%d\t\t$%.2f\n", inventory[i].name, inventory[i].quantity, inventory[i].price);
            return;
        }
    }

    printf("\nItem not found in Inventory.\n");
}

float calculate_total_value(struct Item inventory[], int num_items){
    if(num_items == 0){
        printf("\nInventory Empty. No items to calculate.\n");
        return 0.0;
    }

    float total_value = 0.0;
    for(int i = 0; i < num_items; i++){
        total_value += inventory[i].quantity * inventory[i].price;
    }

    return total_value;
}
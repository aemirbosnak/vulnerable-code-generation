//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: innovative
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//Define the structure for the inventory item
struct inventory_item{
    char name[50];
    int quantity;
    float price;
};

//Initialize the warehouse stock
struct inventory_item warehouse_stock[1000];

//Initialize the number of items in the warehouse
int number_of_items_in_warehouse = 0;

//Function to add an item to the warehouse
void add_item(){
    printf("Enter the name of the item:\n");
    scanf("%s", warehouse_stock[number_of_items_in_warehouse].name);
    printf("Enter the quantity of the item:\n");
    scanf("%d", &warehouse_stock[number_of_items_in_warehouse].quantity);
    printf("Enter the price of the item:\n");
    scanf("%f", &warehouse_stock[number_of_items_in_warehouse].price);
    number_of_items_in_warehouse++;
    printf("Item added successfully!\n");
}

//Function to remove an item from the warehouse
void remove_item(){
    char item_name[50];
    printf("Enter the name of the item to remove:\n");
    scanf("%s", item_name);
    int i, item_found = 0;
    for(i=0;i<number_of_items_in_warehouse;i++){
        if(strcmp(warehouse_stock[i].name, item_name) == 0){
            item_found = 1;
            printf("Enter the quantity to remove:\n");
            int quantity_to_remove;
            scanf("%d",&quantity_to_remove);
            if(quantity_to_remove > warehouse_stock[i].quantity){
                printf("Error: Quantity to remove is greater than available stock.\n");
                return;
            }
            else{
                warehouse_stock[i].quantity -= quantity_to_remove;
                printf("Item removed successfully!\n");
                return;
            }
        }
    }
    if(item_found == 0){
        printf("Error: Item not found in warehouse.\n");
    }
}

//Function to display all items in the warehouse
void display_items(){
    int i, j;
    for(i=0;i<number_of_items_in_warehouse;i++){
        printf("Item Name: %s\n", warehouse_stock[i].name);
        printf("Item Quantity: %d\n", warehouse_stock[i].quantity);
        printf("Item Price: %.2f\n", warehouse_stock[i].price);
        printf("\n");
    }
}

//Function to search for an item in the warehouse
void search_item(){
    char item_name[50];
    printf("Enter the name of the item to search:\n");
    scanf("%s", item_name);
    int i, item_found = 0;
    for(i=0;i<number_of_items_in_warehouse;i++){
        if(strcmp(warehouse_stock[i].name, item_name) == 0){
            item_found = 1;
            printf("Item found! Details are as follows:\n");
            printf("Item Name: %s\n", warehouse_stock[i].name);
            printf("Item Quantity: %d\n", warehouse_stock[i].quantity);
            printf("Item Price: %.2f\n", warehouse_stock[i].price);
            return;
        }
    }
    if(item_found == 0){
        printf("Error: Item not found in warehouse.\n");
    }
}

//Main function
int main(){
    int choice;
    printf("Warehouse Management System\n");
    while(1){
        printf("Enter your choice:\n");
        printf("1. Add an item to the warehouse\n");
        printf("2. Remove an item from the warehouse\n");
        printf("3. Search for an item in the warehouse\n");
        printf("4. Display all items in the warehouse\n");
        printf("5. Exit the program\n");
        scanf("%d", &choice);
        switch(choice){
            case 1: add_item();
                    break;
            case 2: remove_item();
                    break;
            case 3: search_item();
                    break;
            case 4: display_items();
                    break;
            case 5: printf("Goodbye!\n");
                    exit(0);
                    break;
            default: printf("Invalid choice.\n");
        }
    }
    return 0;
}
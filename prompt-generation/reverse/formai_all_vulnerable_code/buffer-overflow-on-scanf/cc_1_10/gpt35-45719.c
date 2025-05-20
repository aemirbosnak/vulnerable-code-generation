//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: random
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// global variables
int warehouse_capacity = 100; 
int current_items = 0;

// item structure
struct item {
    int id;
    char name[50];
    int quantity;
    float price;
};

// warehouse array
struct item warehouse[100];

// function to add an item to the warehouse
void add_item() {
    int id, quantity;
    char name[50];
    float price;
    printf("Enter the item details: \n");
    printf("ID: ");
    scanf("%d", &id);
    printf("Name: ");
    scanf("%s", name);
    printf("Price: ");
    scanf("%f", &price);
    printf("Quantity: ");
    scanf("%d", &quantity);
    struct item new_item = {id, name, quantity, price};
    // check if the warehouse is full
    if(current_items == warehouse_capacity) {
       printf("Warehouse is full! Cannot add more items.\n");
       return;
    }
    // add item to the warehouse
    warehouse[current_items] = new_item;
    printf("Item added successfully!\n");
    current_items++;  
}

// function to remove an item from the warehouse
void remove_item() {
    int id;
    printf("Enter the item ID to be removed: ");
    scanf("%d", &id);
    // search for the item in the warehouse
    int index = -1;
    for(int i = 0; i < current_items; i++) {
        if(warehouse[i].id == id) {
           index = i;
           break;
        }
    }
    if(index == -1) {
        printf("Item not found in the warehouse!\n");
        return;
    }
    // remove the item from the warehouse
    for(int i = index; i < current_items - 1; i++) {
        warehouse[i] = warehouse[i+1];    
    }
    current_items--;
    printf("Item removed successfully!\n");
}

// function to display items in the warehouse
void display_items() {
    printf("Warehouse contains %d items: \n", current_items);
    printf("%-10s %-20s %-10s %-10s\n", "ID", "Name", "Quantity", "Price");
    for(int i = 0; i < current_items; i++) {
        printf("%-10d %-20s %-10d %-10.2f\n", warehouse[i].id,
               warehouse[i].name, warehouse[i].quantity, warehouse[i].price);    
    }   
}

// main function
int main() {
    int option;
    while(1) {
        printf("1. Add item\n");
        printf("2. Remove item\n");
        printf("3. Display items\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &option);
        switch(option) {
            case 1:
                add_item();
                break;
            case 2:
                remove_item();
                break;
            case 3:
                display_items();
                break;
            case 4:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid option selected!\n");
        }   
    }   
    return 0;
}
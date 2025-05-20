//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Declare struct for warehouse item
typedef struct {
    int id;
    char name[50];
    int quantity;
    float price;
} Item;

// Declare function signatures
Item* addItem(Item* items, int* count);
void displayItems(Item* items, int count);
void searchItem(Item* items, int count);
void updateItem(Item* items, int count);
void deleteItem(Item* items, int* count);

int main() {
    int choice;
    int count = 0;
    Item* items = NULL;

    do {
        // Display menu
        printf("\nWELCOME TO WAREHOUSE MANAGEMENT SYSTEM\n");
        printf("1. Add new item\n");
        printf("2. Display all items\n");
        printf("3. Search item\n");
        printf("4. Update item\n");
        printf("5. Delete item\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                items = addItem(items, &count);
                break;
            case 2:
                displayItems(items, count);
                break;
            case 3:
                searchItem(items, count);
                break;
            case 4:
                updateItem(items, count);
                break;
            case 5:
                deleteItem(items, &count);
                break;
            case 6:
                printf("\nTHANK YOU FOR USING WAREHOUSE MANAGEMENT SYSTEM.\n");
                break;
            default:
                printf("\nINVALID CHOICE. PLEASE ENTER A NUMBER BETWEEN 1-6.\n");
        }
    } while(choice != 6);

    return 0;
}

// Function to add new item to warehouse
Item* addItem(Item* items, int* count) {
    // Increase count of items in warehouse
    (*count)++;

    // Reallocate memory to store new item
    items = (Item*) realloc(items, (*count) * sizeof(Item));

    // Get values for new item
    printf("\nEnter ID of item to add: ");
    scanf("%d", &items[*count - 1].id);
    printf("Enter name of item to add: ");
    scanf("%s", items[*count - 1].name);
    printf("Enter quantity of item to add: ");
    scanf("%d", &items[*count - 1].quantity);
    printf("Enter price of item to add: ");
    scanf("%f", &items[*count - 1].price);

    return items;
}

// Function to display all items in warehouse
void displayItems(Item* items, int count) {
    // Check if there are any items in warehouse
    if(count == 0) {
        printf("\nNO ITEMS FOUND IN WAREHOUSE. PLEASE ADD ITEMS FIRST.\n");
        return;
    }

    printf("\nID\tNAME\tQUANTITY\tPRICE\n");
    // Print details of each item in warehouse
    for(int i=0; i<count; i++) {
        printf("%d\t%s\t%d\t\t%.2f\n", items[i].id, items[i].name, items[i].quantity, items[i].price);
    }
}

// Function to search item in warehouse by name or ID
void searchItem(Item* items, int count) {
    char name[50];
    int id, found = 0;

    // Check if there are any items in warehouse
    if(count == 0) {
        printf("\nNO ITEMS FOUND IN WAREHOUSE. PLEASE ADD ITEMS FIRST.\n");
        return;
    }

    printf("\nEnter ID or name of item to search: ");
    scanf("%s", name);

    // Search item by ID or name
    for(int i=0; i<count; i++) {
        if(strcmp(items[i].name, name) == 0 || items[i].id == atoi(name)) {
            found = 1;
            printf("\nID\tNAME\tQUANTITY\tPRICE\n");
            printf("%d\t%s\t%d\t\t%.2f\n", items[i].id, items[i].name, items[i].quantity, items[i].price);
            break;
        }
    }
    // Print message if item not found
    if(!found) {
        printf("\nITEM NOT FOUND IN WAREHOUSE. PLEASE ENTER A VALID ID OR NAME.\n");
    }
}

// Function to update item in warehouse by ID
void updateItem(Item* items, int count) {
    int id, found = 0;

    // Check if there are any items in warehouse
    if(count == 0) {
        printf("\nNO ITEMS FOUND IN WAREHOUSE. PLEASE ADD ITEMS FIRST.\n");
        return;
    }

    printf("\nEnter ID of item to update: ");
    scanf("%d", &id);

    // Search item by ID
    for(int i=0; i<count; i++) {
        if(items[i].id == id) {
            found = 1;
            // Get updated values for item
            printf("Enter updated name of item: ");
            scanf("%s", items[i].name);
            printf("Enter updated quantity of item: ");
            scanf("%d", &items[i].quantity);
            printf("Enter updated price of item: ");
            scanf("%f", &items[i].price);
            printf("\nITEM UPDATED SUCCESSFULLY.\n");
            break;
        }
    }
    // Print message if item not found
    if(!found) {
        printf("\nITEM NOT FOUND IN WAREHOUSE. PLEASE ENTER A VALID ID.\n");
    }
}

// Function to delete item in warehouse by ID
void deleteItem(Item* items, int* count) {
    int id, found = 0;

    // Check if there are any items in warehouse
    if(*count == 0) {
        printf("\nNO ITEMS FOUND IN WAREHOUSE. PLEASE ADD ITEMS FIRST.\n");
        return;
    }

    printf("\nEnter ID of item to delete: ");
    scanf("%d", &id);

    // Search item by ID and delete
    for(int i=0; i<*count; i++) {
        if(items[i].id == id) {
            found = 1;
            // Shift all remaining items up to fill the gap
            for(int j=i; j<*count-1; j++) {
                items[j] = items[j+1];
            }
            // Decrease count of items in warehouse
            (*count)--;
            // Reallocate memory to free space
            items = (Item*) realloc(items, (*count) * sizeof(Item));
            printf("\nITEM DELETED SUCCESSFULLY.\n");
            break;
        }
    }
    // Print message if item not found
    if(!found) {
        printf("\nITEM NOT FOUND IN WAREHOUSE. PLEASE ENTER A VALID ID.\n");
    }
}
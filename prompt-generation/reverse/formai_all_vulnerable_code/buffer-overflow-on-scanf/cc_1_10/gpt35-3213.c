//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: detailed
#include <stdio.h>
#include <stdlib.h>

#define MAX_ITEMS 100
#define MAX_NAME_LENGTH 50

// Define a struct to represent an item in the warehouse
typedef struct {
    int id;
    char name[MAX_NAME_LENGTH];
    int quantity;
} Item;

// Define global variables for the warehouse and the number of items
Item warehouse[MAX_ITEMS];
int numItems = 0;

// Function prototypes
void addItem();
void removeItem();
void displayInventory();

int main() {
    int choice;
    
    // The main loop allows the user to perform actions on the warehouse
    do {
        printf("Enter 1 to add an item\n");
        printf("Enter 2 to remove an item\n");
        printf("Enter 3 to display the inventory\n");
        printf("Enter 4 to quit\n");
        
        scanf("%d", &choice);
        
        switch(choice) {
            case 1: addItem(); break;
            case 2: removeItem(); break;
            case 3: displayInventory(); break;
            case 4: break; // Exit the loop
            default: printf("Invalid choice\n");
        }
    } while(choice != 4);
    
    return 0;
}

// This function adds an item to the warehouse
void addItem() {
    // Check to make sure there is room in the warehouse
    if(numItems < MAX_ITEMS) {
        Item newItem;
        newItem.id = numItems + 1;
        
        printf("Enter the name of the item (up to %d characters): ", MAX_NAME_LENGTH);
        scanf("%s", newItem.name);
        
        printf("Enter the quantity: ");
        scanf("%d", &newItem.quantity);
        
        warehouse[numItems] = newItem;
        numItems++;
        
        printf("Item added to inventory\n");
    } else {
        printf("Warehouse is full\n");
    }
}

// This function removes an item from the warehouse
void removeItem() {
    int idToRemove;
    int i;
    int found = 0;
    
    printf("Enter the ID of the item to remove: ");
    scanf("%d", &idToRemove);
    
    for(i = 0; i < numItems; i++) {
        if(warehouse[i].id == idToRemove) {
            found = 1;
            // Move all items after the removed one back one position
            for(int j = i; j < numItems - 1; j++) {
                warehouse[j] = warehouse[j + 1];
            }
            numItems--;
            break;
        }
    }
    
    if(found) {
        printf("Item removed from inventory\n");
    } else {
        printf("Item not found\n");
    }
}

// This function displays the current inventory of the warehouse
void displayInventory() {
    int i;
    
    if(numItems == 0) {
        printf("Warehouse is empty\n");
    } else {
        printf("ID  Name                       Quantity\n");
        printf("---------------------------------------\n");
        for(i = 0; i < numItems; i++) {
            printf("%2d  %-25s %5d\n", warehouse[i].id, warehouse[i].name, warehouse[i].quantity);
        }
    }
}
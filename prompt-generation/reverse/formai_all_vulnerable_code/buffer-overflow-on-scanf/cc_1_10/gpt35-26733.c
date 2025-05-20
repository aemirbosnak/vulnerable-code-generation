//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: irregular
#include<stdio.h>
#include<stdlib.h>

#define MAX_ITEMS 100 // maximum number of items in the warehouse
#define MAX_STRING_LENGTH 50 // maximum length of strings

// structure to hold warehouse item details
typedef struct {
    int itemNumber;
    char itemName[MAX_STRING_LENGTH];
    int quantity;
    float price;
} Item;

// global warehouse inventory array
Item warehouseInventory[MAX_ITEMS];

// function to display menu options to user
void menu() {
    printf("\nWarehouse Management System\n");
    printf("---------------------------\n");
    printf("1. Add Item\n");
    printf("2. Remove Item\n");
    printf("3. View Inventory\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
}

int main() {
    int choice;
    int numItems = 0;
    
    do {
        menu(); // display menu to user
        scanf("%d", &choice); // get user input for menu option
        
        switch(choice) {
            case 1:
                // add item to warehouse inventory
                if(numItems < MAX_ITEMS) {
                    printf("\nEnter item details:\n");
                    printf("Item Number: ");
                    scanf("%d", &warehouseInventory[numItems].itemNumber);
                    printf("Item Name: ");
                    scanf("%s", warehouseInventory[numItems].itemName);
                    printf("Quantity: ");
                    scanf("%d", &warehouseInventory[numItems].quantity);
                    printf("Price: ");
                    scanf("%f", &warehouseInventory[numItems].price);
                    
                    printf("\nItem Added!\n");
                    numItems++;
                } else {
                    printf("\nWarehouse inventory full!\n");
                }
                break;
            case 2:
                // remove item from warehouse inventory
                if(numItems > 0) {
                    int itemNumber;
                    printf("\nEnter item number to remove: ");
                    scanf("%d", &itemNumber);
                    
                    int found = 0;
                    for(int i=0; i<numItems; i++) {
                        if(warehouseInventory[i].itemNumber == itemNumber) {
                            found = 1;
                            for(int j=i; j<numItems-1; j++) {
                                warehouseInventory[j] = warehouseInventory[j+1];
                            }
                            printf("\nItem removed!\n");
                            numItems--;
                            break;
                        }
                    }
                    if(!found) {
                        printf("\nItem not found!\n");
                    }
                } else {
                    printf("\nWarehouse inventory is empty!\n");
                }
                break;
            case 3:
                // view warehouse inventory
                if(numItems > 0) {
                    printf("\nWarehouse Inventory\n");
                    printf("--------------------\n");
                    printf("%-10s %-20s %-10s %-10s\n", "Item No.", "Item Name", "Quantity", "Price");
                    for(int i=0; i<numItems; i++) {
                        printf("%-10d %-20s %-10d %-10.2f\n", warehouseInventory[i].itemNumber,
                                                           warehouseInventory[i].itemName,
                                                           warehouseInventory[i].quantity,
                                                           warehouseInventory[i].price);
                    }
                } else {
                    printf("\nWarehouse inventory is empty!\n");
                }
                break;
            case 4:
                // exit program
                printf("\nExiting program...\n");
                break;
            default:
                printf("\nInvalid choice!\n");
        }
    } while(choice != 4);
    
    return 0;
}
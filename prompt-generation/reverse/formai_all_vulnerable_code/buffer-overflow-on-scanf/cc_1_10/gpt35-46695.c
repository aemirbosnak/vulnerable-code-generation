//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define global variables
#define MAX_STRING_LENGTH 100
#define MAX_INVENTORY_SIZE 100
int inventory[MAX_INVENTORY_SIZE]={0};  // Managing inventory stock

// Define function prototypes
void addStock(int, int);
void sellStock(int, int);
void getItem(int);
void printInventory();

int main() {
    int choice, itemID, amount;
    char action;
    printf("Welcome to the Medical Store Management System!\n");

    // Prompt user for main menu options
    do {
        printf("\n--- Main Menu ---\n");
        printf("1. Add Stock\n");
        printf("2. Sell Stock\n");
        printf("3. Get Item Info\n");
        printf("4. Print Inventory\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("\nEnter the item ID and amount of stock to add (separated by a space): ");
                scanf("%d %d", &itemID, &amount);
                addStock(itemID, amount);
                printf("\nThe stock of item id %d is added by %d.\n", itemID, amount);
                break;
            case 2:
                printf("\nEnter the item ID and amount of stock to sell (separated by a space): ");
                scanf("%d %d", &itemID, &amount);
                sellStock(itemID, amount);
                printf("\nThe stock of item id %d is sold by %d.\n", itemID, amount);
                break;
            case 3:
                printf("\nEnter the item ID to retrieve its details: ");
                scanf("%d", &itemID);
                getItem(itemID);
                break;
            case 4:
                printInventory();
                break;
            case 5:
                printf("\nThank you for using the Medical Store Management System.\n");
                break;
            default:
                printf("\nInvalid Input. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}

void addStock(int itemID, int amount){
    inventory[itemID-1] += amount;
}

void sellStock(int itemID, int amount){
    if(inventory[itemID-1] < amount){
        printf("\nInsufficient stock of item id %d.\n", itemID);
        return;
    }
    inventory[itemID-1] -= amount;  
}

void getItem(int itemID){
    printf("\nItem ID: %d\n", itemID);
    printf("Stock Quantity: %d\n", inventory[itemID-1]);
}

void printInventory(){
    printf("\nCurrent Inventory\n");
    printf("-----------------\n");
    for(int i=0; i<MAX_INVENTORY_SIZE; i++){
        if(inventory[i] != 0){
            printf("Item ID: %d | Stock Quantity: %d\n", i+1, inventory[i]);
        }
    }
}
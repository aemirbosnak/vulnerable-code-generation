//FormAI DATASET v1.0 Category: Product Inventory System ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100 // maximum number of products

// structure for product information
typedef struct {
    char name[20];
    int id;
    int quantity;
    double price;
} Product;

int numProducts = 0; // number of products in inventory
Product inventory[MAX_PRODUCTS]; // array to store products

// function prototypes
void addProduct();
void removeProduct();
void displayInventory();
void searchInventory();
void updateProduct();

int main() {
    int option;
    do {
        printf("\n\nProduct Inventory System");
        printf("\n\n[1] Add a product");
        printf("\n[2] Remove a product");
        printf("\n[3] Display inventory");
        printf("\n[4] Search inventory");
        printf("\n[5] Update product information");
        printf("\n[6] Exit");
        printf("\n\nEnter an option: ");
        scanf("%d", &option);
        
        switch(option) {
            case 1:
                addProduct();
                break;
            case 2:
                removeProduct();
                break;
            case 3:
                displayInventory();
                break;
            case 4:
                searchInventory();
                break;
            case 5:
                updateProduct();
                break;
            case 6:
                printf("\nThank you for using this inventory system!");
                break;
            default:
                printf("\nInvalid option, please try again.");
                break;
        }
        
    } while(option != 6);
    
    return 0;
}

// function to add a product to the inventory
void addProduct() {
    if(numProducts >= MAX_PRODUCTS) {
        printf("\nInventory is full, unable to add new product.");
    } else {
        printf("\nEnter product name: ");
        scanf(" %s", &inventory[numProducts].name);
        printf("Enter product ID: ");
        scanf("%d", &inventory[numProducts].id);
        printf("Enter product quantity: ");
        scanf("%d", &inventory[numProducts].quantity);
        printf("Enter product price: ");
        scanf("%lf", &inventory[numProducts].price);
        printf("\nProduct added successfully!\n");
        numProducts++;
    }
}

// function to remove a product from the inventory
void removeProduct() {
    int idToRemove, indexToRemove;
    
    printf("\nEnter product ID to remove: ");
    scanf("%d", &idToRemove);
    
    // find index of product to remove
    for(int i = 0; i < numProducts; i++) {
        if(inventory[i].id == idToRemove) {
            indexToRemove = i;
            break;
        }
    }
    
    // shift elements of array to remove product
    for(int i = indexToRemove; i < numProducts - 1; i++) {
        inventory[i] = inventory[i+1];
    }
    
    numProducts--;
    printf("\nProduct removed successfully!\n");
}

// function to display all products in the inventory
void displayInventory() {
    printf("\n\nProduct Inventory\n");
    printf("-----------------------------------------------\n");
    printf("%-20s %-10s %-10s %-10s\n", "Name", "ID", "Quantity", "Price");
    printf("-----------------------------------------------\n");
    for(int i = 0; i < numProducts; i++) {
        printf("%-20s %-10d %-10d $%.2lf\n", inventory[i].name, inventory[i].id, inventory[i].quantity, inventory[i].price);
    }
    printf("-----------------------------------------------\n");
}

// function to search for a product in the inventory
void searchInventory() {
    char nameToSearch[20];
    int idToSearch;
    int found = 0;
    
    printf("\n[1] Search by product name\n[2] Search by product ID\n");
    printf("Enter an option: ");
    int option;
    scanf("%d", &option);
    
    switch(option) {
        case 1:
            printf("\nEnter product name to search: ");
            scanf(" %s", &nameToSearch);
            for(int i = 0; i < numProducts; i++) {
                if(strcmp(inventory[i].name, nameToSearch) == 0) {
                    printf("\nProduct found:");
                    printf("\nName: %s\nID: %d\nQuantity: %d\nPrice: $%.2lf\n", inventory[i].name, inventory[i].id, inventory[i].quantity, inventory[i].price);
                    found = 1;
                    break;
                }
            }
            if(!found) {
                printf("\nProduct not found.");
            }
            break;
        case 2:
            printf("\nEnter product ID to search: ");
            scanf("%d", &idToSearch);
            for(int i = 0; i < numProducts; i++) {
                if(inventory[i].id == idToSearch) {
                    printf("\nProduct found:");
                    printf("\nName: %s\nID: %d\nQuantity: %d\nPrice: $%.2lf\n", inventory[i].name, inventory[i].id, inventory[i].quantity, inventory[i].price);
                    found = 1;
                    break;
                }
            }
            if(!found) {
                printf("\nProduct not found.");
            }
            break;
        default:
            printf("\nInvalid option, please try again.");
            break;
    }
}

// function to update a product in the inventory
void updateProduct() {
    int idToUpdate, fieldToUpdate;
    double newValue;
    
    printf("\nEnter product ID to update: ");
    scanf("%d", &idToUpdate);
    
    // find index of product to update
    int indexToUpdate = -1;
    for(int i = 0; i < numProducts; i++) {
        if(inventory[i].id == idToUpdate) {
            indexToUpdate = i;
            break;
        }
    }
    
    if(indexToUpdate == -1) {
        printf("\nProduct not found.");
        return;
    }
    
    printf("\n[1] Update quantity\n[2] Update price\n");
    printf("Enter the field to update: ");
    scanf("%d", &fieldToUpdate);
    
    switch(fieldToUpdate) {
        case 1:
            printf("\nEnter new quantity: ");
            scanf("%d", &inventory[indexToUpdate].quantity);
            break;
        case 2:
            printf("\nEnter new price: ");
            scanf("%lf", &inventory[indexToUpdate].price);
            break;
        default:
            printf("\nInvalid option, please try again.");
            break;
    }
    
    printf("\nProduct updated successfully!\n");
}
//FormAI DATASET v1.0 Category: Product Inventory System ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Product {
    int id;
    char name[100];
    int quantity;
    int price;
};

int main() {
    // Declare variables
    int numProducts;
    struct Product* inventory;
    
    // Get the number of products from the user
    printf("Enter the number of products: ");
    scanf("%d", &numProducts);
    
    // Allocate memory for the inventory
    inventory = (struct Product*) malloc(numProducts * sizeof(struct Product));
    
    // Initialize the inventory
    for (int i = 0; i < numProducts; i++) {
        printf("\nProduct %d:\n", i+1);
        printf("ID: ");
        scanf("%d", &inventory[i].id);
        printf("Name: ");
        scanf("%s", inventory[i].name);
        printf("Quantity: ");
        scanf("%d", &inventory[i].quantity);
        printf("Price: ");
        scanf("%d", &inventory[i].price);
    }
    
    // Display the inventory
    printf("\nProduct Inventory:\n");
    printf("ID\tName\tQuantity\tPrice\n");
    for (int i = 0; i < numProducts; i++) {
        printf("%d\t%s\t%d\t\t%d\n", inventory[i].id, inventory[i].name, inventory[i].quantity, inventory[i].price);
    }
    
    // Update the inventory
    int productID, newQuantity;
    printf("\nEnter the ID of the product to update: ");
    scanf("%d", &productID);
    printf("Enter the new quantity: ");
    scanf("%d", &newQuantity);
    for (int i = 0; i < numProducts; i++) {
        if (inventory[i].id == productID) {
            inventory[i].quantity = newQuantity;
        }
    }
    
    // Display the updated inventory
    printf("\nUpdated Product Inventory:\n");
    printf("ID\tName\tQuantity\tPrice\n");
    for (int i = 0; i < numProducts; i++) {
        printf("%d\t%s\t%d\t\t%d\n", inventory[i].id, inventory[i].name, inventory[i].quantity, inventory[i].price);
    }
    
    // Free memory
    free(inventory);
    
    return 0;
}
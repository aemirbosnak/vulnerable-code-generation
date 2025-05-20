//FormAI DATASET v1.0 Category: Product Inventory System ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct product {
    char name[50];
    int quantity;
    float price;
};

int inventory_size = 0; // number of products in inventory

void add_product(struct product *inventory) // function to add a new product to inventory
{
    printf("\nEnter product name: ");
    scanf("%s", inventory[inventory_size].name);
    
    printf("Enter product quantity: ");
    scanf("%d", &inventory[inventory_size].quantity);
    
    printf("Enter product price: ");
    scanf("%f", &inventory[inventory_size].price);
    
    printf("\nProduct added successfully!\n");
    inventory_size++;
}

void display_inventory(struct product *inventory) // function to display all products in inventory
{
    printf("\nProduct Inventory:\n\n");
    if (inventory_size == 0) {
        printf("No products in inventory\n");
        return;
    }
    for (int i = 0; i < inventory_size; i++) {
        printf("Product Name: %s\n", inventory[i].name);
        printf("Quantity: %d\n", inventory[i].quantity);
        printf("Price: %.2f\n\n", inventory[i].price);
    }
}

void delete_product(struct product *inventory) // function to delete a product from inventory
{
    char name[50];
    int index = -1;
    
    if (inventory_size == 0) {
        printf("\nNo products in inventory to delete\n");
        return;
    }
    
    printf("\nEnter name of product to delete: ");
    scanf("%s", name);
    
    for (int i = 0; i < inventory_size; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            index = i;
            break;
        }
    }
    
    if (index == -1) {
        printf("\nProduct not found in inventory\n");
        return;
    }
    
    for (int i = index; i < inventory_size - 1; i++) {
        inventory[i] = inventory[i + 1];
    }
    inventory_size--;
    printf("\nProduct deleted successfully!\n");
}

void search_product(struct product *inventory) // function to search for a product in inventory
{
    char name[50];
    int index = -1;
    
    if (inventory_size == 0) {
        printf("\nNo products in inventory to search\n");
        return;
    }
    
    printf("\nEnter name of product to search: ");
    scanf("%s", name);
    
    for (int i = 0; i < inventory_size; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            index = i;
            break;
        }
    }
    
    if (index == -1) {
        printf("\nProduct not found in inventory\n");
        return;
    }
    
    printf("\nProduct found!\n\nProduct Name: %s\nQuantity: %d\nPrice: %.2f\n", 
           inventory[index].name, inventory[index].quantity, inventory[index].price);
}

int main()
{
    int choice;
    struct product inventory[100];
    
    while (1) {
        printf("\n\n*** Product Inventory System ***\n");
        printf("1. Add product\n");
        printf("2. Delete product\n");
        printf("3. Search product\n");
        printf("4. Display inventory\n");
        printf("5. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1: 
                add_product(inventory);
                break;
            case 2: 
                delete_product(inventory);
                break;
            case 3: 
                search_product(inventory);
                break;
            case 4: 
                display_inventory(inventory);
                break;
            case 5: 
                printf("\nExiting program...");
                exit(0);
            default: 
                printf("\nInvalid choice! Try again.\n");
        }
    }
    return 0;
}
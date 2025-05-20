//FormAI DATASET v1.0 Category: Product Inventory System ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define product struct
typedef struct {
    int id;
    char name[50];
    int quantity;
    float price;
} Product;

// Declaration of Functions
void display_menu();
void add_product(Product inventory[], int *count);
void remove_product(Product inventory[], int *count);
void display_inventory(Product inventory[], int count);
void search_product(Product inventory[], int count);
void update_product(Product inventory[], int count);

int main(){
    // Initialize inventory with sample data
    Product inventory[50] = {
        {111, "Product 1", 10, 15.99},
        {222, "Product 2", 15, 25.99},
        {333, "Product 3", 20, 35.99},
        {444, "Product 4", 25, 45.99},
        {555, "Product 5", 30, 55.99},
    };
    int count = 5; // Number of products in inventory
    
    display_menu(); // Display Main Menu
    int option;
    printf("Enter option: ");
    scanf("%d", &option);
    
    while(option != 6){
        switch(option){
            case 1:
                add_product(inventory, &count);
                break;
            case 2:
                remove_product(inventory, &count);
                break;
            case 3:
                display_inventory(inventory, count);
                break;
            case 4:
                search_product(inventory, count);
                break;
            case 5:
                update_product(inventory, count);
                break;
            default:
                printf("Invalid option!\n");
        }
        printf("\n");
        display_menu();
        printf("Enter option: ");
        scanf("%d", &option);
    }
    printf("Exiting program...\n");
    
    return 0; // End of program
}

// Function to display Main Menu
void display_menu(){
    printf("Product Inventory System\n\n");
    printf("1. Add a product\n");
    printf("2. Remove a product\n");
    printf("3. Display inventory\n");
    printf("4. Search a product\n");
    printf("5. Update a product\n");
    printf("6. Exit\n");
}

// Function to add a product in inventory
void add_product(Product inventory[], int *count){
    Product new_product; // Create a new product
    
    printf("Enter Product ID: ");
    scanf("%d", &new_product.id);
    printf("Enter Product Name: ");
    scanf("%s", new_product.name);
    printf("Enter Product Quantity: ");
    scanf("%d", &new_product.quantity);
    printf("Enter Product Price: ");
    scanf("%f", &new_product.price);
    
    inventory[*count] = new_product; // Add new product to inventory
    (*count)++; // Increment count of products
    printf("Product added successfully!\n");
}

// Function to remove a product from inventory
void remove_product(Product inventory[], int *count){
    int product_id;
    int i, j;
    printf("Enter Product ID to remove: ");
    scanf("%d", &product_id);
    
    for(i = 0; i < *count; i++){
        if(inventory[i].id == product_id){
            // Shift elements to left of array
            for(j = i; j < *count - 1; j++){
                inventory[j] = inventory[j+1];
            }
            (*count)--; // Decrement count of products
            printf("Product removed successfully!\n");
            return;
        }
    }
    printf("Product with ID %d not found!\n", product_id);
}

// Function to display inventory
void display_inventory(Product inventory[], int count){
    int i;
    printf("ID\tProduct Name\tQuantity\tPrice\n");
    for(i = 0; i < count; i++){
        printf("%d\t%s\t%d\t%.2f\n", inventory[i].id, inventory[i].name, inventory[i].quantity, inventory[i].price);
    }
}

// Function to search for a product in inventory
void search_product(Product inventory[], int count){
    char product_name[50];
    int i;
    printf("Enter Product Name: ");
    scanf("%s", product_name);
    
    for(i = 0; i < count; i++){
        if(strcmp(inventory[i].name, product_name) == 0){
            printf("Product found!\n");
            printf("ID: %d, Quantity: %d, Price: %.2f\n", inventory[i].id, inventory[i].quantity, inventory[i].price);
            return;
        }
    }
    printf("Product with name \"%s\" not found!\n", product_name);
}

// Function to update a product in inventory
void update_product(Product inventory[], int count){
    int product_id;
    int i;
    printf("Enter Product ID to update: ");
    scanf("%d", &product_id);
    
    for(i = 0; i < count; i++){
        if(inventory[i].id == product_id){
            printf("Enter new quantity: ");
            scanf("%d", &inventory[i].quantity);
            printf("Enter new price: ");
            scanf("%f", &inventory[i].price);
            printf("Product updated successfully!\n");
            return;
        }
    }
    printf("Product with ID %d not found!\n", product_id);
}
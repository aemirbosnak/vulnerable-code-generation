//FormAI DATASET v1.0 Category: Product Inventory System ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Defining the inventory struct
typedef struct{
    int id;
    char name[50];
    int quantity;
    float price;
} Inventory;

// Function to add a new product in the inventory
void addProduct(Inventory *inventory, int numProducts){
    inventory = realloc(inventory, (numProducts+1)*sizeof(Inventory));
    printf("\nEnter the product name: ");
    scanf(" %[^\n]s", &(inventory[numProducts].name));
    printf("Enter the quantity of the product: ");
    scanf("%d", &(inventory[numProducts].quantity));
    printf("Enter the price of the product: ");
    scanf("%f", &(inventory[numProducts].price));
    inventory[numProducts].id = numProducts+1;
    printf("\nProduct %s added successfully!\n", inventory[numProducts].name);
}

// Function to view all the products in the inventory
void viewProducts(Inventory *inventory, int numProducts){
    printf("\n-----------------------------------------------\n");
    printf("***************Inventory Details***************\n");
    printf("-----------------------------------------------\n");
    printf("%-5s %-20s %-10s %-10s\n", "ID", "Name", "Quantity", "Price");
    printf("-----------------------------------------------\n");
    for(int i=0;i<numProducts;i++){
        printf("%-5d %-20s %-10d $%-10.2f\n", inventory[i].id, inventory[i].name, inventory[i].quantity, inventory[i].price);
    }
    printf("-----------------------------------------------\n");
}

// Function to search for a product by name 
void searchProduct(Inventory *inventory, int numProducts){
    char name[50];
    int found = 0;
    printf("Enter the product name to search: ");
    scanf("%s", name);
    printf("\nSearch Results\n");
    printf("-----------------------------------------------\n");
    printf("%-5s %-20s %-10s %-10s\n", "ID", "Name", "Quantity", "Price");
    printf("-----------------------------------------------\n");
    for(int i=0;i<numProducts;i++){
        if(strcmp(inventory[i].name, name) == 0){
            printf("%-5d %-20s %-10d $%-10.2f\n", inventory[i].id, inventory[i].name, inventory[i].quantity, inventory[i].price);
            found = 1;
            break;
        }
    }
    if(found == 0){
        printf("Product with name %s not found!\n", name);
    }
    printf("-----------------------------------------------\n");
}

// Function to delete a product from the inventory
void deleteProduct(Inventory *inventory, int numProducts){
    int id;
    printf("\nEnter the ID of the product to delete: ");
    scanf("%d", &id);
    int index = -1;
    for(int i=0;i<numProducts;i++){
        if(inventory[i].id == id){
            index = i;
            break;
        }
    }
    if(index == -1){
        printf("\nProduct not found with ID %d\n", id);
        return;
    }
    for(int i=index;i<numProducts-1;i++){
        inventory[i] = inventory[i+1];
    }
    inventory = realloc(inventory, (numProducts-1)*sizeof(Inventory));
    printf("\nProduct with ID %d deleted successfully!\n", id);
}

int main(){
    Inventory *inventory = NULL;
    int choice, numProducts = 0;
    printf("\n**********Product Inventory System**********\n");
    while(1){
        printf("\nSelect an option:\n");
        printf("1. Add new product\n");
        printf("2. View all products\n");
        printf("3. Search a product by name\n");
        printf("4. Delete a product\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                addProduct(inventory, numProducts);
                numProducts++;
                break;
            case 2:
                viewProducts(inventory, numProducts);
                break;
            case 3:
                searchProduct(inventory, numProducts);
                break;
            case 4:
                deleteProduct(inventory, numProducts);
                numProducts--;
                break;
            case 5:
                printf("\nExiting...\n");
                exit(0);
            default:
                printf("\nInvalid choice! Try again...\n");
                break;
        }
    }
    return 0;
}
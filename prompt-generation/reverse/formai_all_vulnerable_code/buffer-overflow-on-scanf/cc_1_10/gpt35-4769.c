//FormAI DATASET v1.0 Category: Product Inventory System ; Style: Dennis Ritchie
#include<stdio.h>
#include<string.h>

// Defining a structure to hold product information
struct Product {
    char name[50];
    int id;
    float price;
    int quantity;
};

// Function to add a new product to the inventory
void addProduct(struct Product inventory[], int *count) {
    printf("\nEnter Product ID: ");
    scanf("%d", &inventory[*count].id);

    printf("\nEnter Product Name: ");
    scanf("%s", inventory[*count].name);

    printf("\nEnter Product Price: ");
    scanf("%f", &inventory[*count].price);

    printf("\nEnter Product Quantity: ");
    scanf("%d", &inventory[*count].quantity);
    
    printf("\nProduct Added to Inventory Successfully!\n");
    (*count)++;
}

// Function to search for a product by ID
void searchProductById(int id, struct Product inventory[], int count) {
    int found = 0;
    for(int i=0; i<count; i++) {
        if(inventory[i].id == id) {
            printf("\nProduct Found:\n\nName: %s\nID: %d\nPrice: $%.2f\nQuantity: %d\n", inventory[i].name, inventory[i].id, inventory[i].price, inventory[i].quantity);
            found = 1;
            break;
        }
    }
    if(!found) {
        printf("\nProduct not found in inventory!\n");
    }
}

// Function to search for a product by name
void searchProductByName(char name[], struct Product inventory[], int count) {
    int found = 0;
    for(int i=0; i<count; i++) {
        if(strcmp(inventory[i].name, name) == 0) {
            printf("\nProduct Found:\n\nName: %s\nID: %d\nPrice: $%.2f\nQuantity: %d\n", inventory[i].name, inventory[i].id, inventory[i].price, inventory[i].quantity);
            found = 1;
            break;
        }
    }
    if(!found) {
        printf("\nProduct not found in inventory!\n");
    }
}

// Function to display the entire inventory
void viewInventory(struct Product inventory[], int count) {
    printf("\nCurrent Inventory:\n");
    printf("\nID\tName\t\tPrice\t\tQuantity\n");
    printf("----------------------------------------------------------------\n");
    for(int i=0; i<count; i++) {
        printf("%d\t%s\t\t$%.2f\t\t%d\n", inventory[i].id, inventory[i].name, inventory[i].price, inventory[i].quantity);
    }
}

int main() {
    // Initializing the inventory with 5 products
    struct Product inventory[100] = {{"Product1", 1, 10.99, 50}, {"Product2", 2, 15.99, 100}, {"Product3", 3, 20.99, 25}, {"Product4", 4, 12.99, 75}, {"Product5", 5, 9.99, 200}};
    int count = 5;
    
    // Displaying the options to the user
    int choice;
    do {
        printf("\nChoose an option (1-4):\n");
        printf("1. Add a new product to inventory\n");
        printf("2. Search for a product by ID\n");
        printf("3. Search for a product by Name\n");
        printf("4. View Inventory\n");
        printf("5. Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                addProduct(inventory, &count);
                break;
            case 2:
                printf("\nEnter the ID to search for: ");
                int id;
                scanf("%d", &id);
                searchProductById(id, inventory, count);
                break;
            case 3:
                printf("\nEnter the Name to search for: ");
                char name[50];
                scanf("%s", name);
                searchProductByName(name, inventory, count);
                break;
            case 4:
                viewInventory(inventory, count);
                break;
            case 5:
                printf("\nExiting...\n");
                break;
            default:
                printf("\nInvalid Choice! Please try again.\n");
        }
    } while(choice != 5);
    
    return 0;
}
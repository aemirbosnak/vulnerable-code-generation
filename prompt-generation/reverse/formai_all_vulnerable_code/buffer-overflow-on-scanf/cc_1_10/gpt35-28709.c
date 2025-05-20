//FormAI DATASET v1.0 Category: Product Inventory System ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of products
#define MAX_PRODUCTS 100

// Define the maximum length of the product name
#define MAX_NAME_LEN 50

// Define the maximum length of the serial number
#define MAX_SERIAL_LEN 20

// Define the maximum length of the description
#define MAX_DESCRIPTION_LEN 200

// Define the maximum quantity of the product
#define MAX_QUANTITY 1000

// Define a structure for the product
typedef struct {
    char name[MAX_NAME_LEN];
    char serial[MAX_SERIAL_LEN];
    char description[MAX_DESCRIPTION_LEN];
    int quantity;
} Product;

// Define a function to add a new product
void add_product(Product* inventory, int* count) {
    char name[MAX_NAME_LEN];
    char serial[MAX_SERIAL_LEN];
    char description[MAX_DESCRIPTION_LEN];
    int quantity;
    
    // Prompt for the product name
    printf("Enter product name: ");
    fgets(name, MAX_NAME_LEN, stdin);
    name[strcspn(name, "\n")] = '\0'; // remove newline character
    
    // Prompt for the product serial
    printf("Enter product serial: ");
    fgets(serial, MAX_SERIAL_LEN, stdin);
    serial[strcspn(serial, "\n")] = '\0'; // remove newline character
    
    // Prompt for the product description
    printf("Enter product description: ");
    fgets(description, MAX_DESCRIPTION_LEN, stdin);
    description[strcspn(description, "\n")] = '\0'; // remove newline character
    
    // Prompt for the product quantity
    printf("Enter product quantity: ");
    scanf("%d", &quantity);
    getchar(); // remove newline character
    
    // Check if the inventory is full
    if (*count >= MAX_PRODUCTS) {
        printf("The inventory is full. Cannot add new product.\n");
        return;
    }
    
    // Add the product to the inventory
    strncpy(inventory[*count].name, name, MAX_NAME_LEN);
    strncpy(inventory[*count].serial, serial, MAX_SERIAL_LEN);
    strncpy(inventory[*count].description, description, MAX_DESCRIPTION_LEN);
    inventory[*count].quantity = quantity;
    (*count)++;
    
    printf("New product added to inventory.\n");
}

// Define a function to remove a product
void remove_product(Product* inventory, int* count) {
    char serial[MAX_SERIAL_LEN];
    
    // Prompt for the product serial
    printf("Enter product serial: ");
    fgets(serial, MAX_SERIAL_LEN, stdin);
    serial[strcspn(serial, "\n")] = '\0'; // remove newline character
    
    // Find the index of the product with the given serial
    int index = -1;
    for (int i = 0; i < *count; i++) {
        if (strcmp(inventory[i].serial, serial) == 0) {
            index = i;
            break;
        }
    }
    
    // Check if the product was found
    if (index == -1) {
        printf("Product not found in inventory.\n");
        return;
    }
    
    // Remove the product from the inventory
    for (int i = index; i < *count - 1; i++) {
        strcpy(inventory[i].name, inventory[i+1].name);
        strcpy(inventory[i].serial, inventory[i+1].serial);
        strcpy(inventory[i].description, inventory[i+1].description);
        inventory[i].quantity = inventory[i+1].quantity;
    }
    (*count)--;
    
    printf("Product removed from inventory.\n");
}

// Define a function to update a product
void update_product(Product* inventory, int count) {
    char serial[MAX_SERIAL_LEN];
    
    // Prompt for the product serial
    printf("Enter product serial: ");
    fgets(serial, MAX_SERIAL_LEN, stdin);
    serial[strcspn(serial, "\n")] = '\0'; // remove newline character
    
    // Find the index of the product with the given serial
    int index = -1;
    for (int i = 0; i < count; i++) {
        if (strcmp(inventory[i].serial, serial) == 0) {
            index = i;
            break;
        }
    }
    
    // Check if the product was found
    if (index == -1) {
        printf("Product not found in inventory.\n");
        return;
    }
    
    // Prompt for the attribute to update
    printf("Select attribute to update:\n");
    printf("1. Name\n");
    printf("2. Serial\n");
    printf("3. Description\n");
    printf("4. Quantity\n");
    int choice;
    scanf("%d", &choice);
    getchar(); // remove newline character
    
    // Update the attribute
    switch (choice) {
        case 1:
            printf("Enter new name: ");
            fgets(inventory[index].name, MAX_NAME_LEN, stdin);
            inventory[index].name[strcspn(inventory[index].name, "\n")] = '\0'; // remove newline character
            break;
        case 2:
            printf("Enter new serial: ");
            fgets(inventory[index].serial, MAX_SERIAL_LEN, stdin);
            inventory[index].serial[strcspn(inventory[index].serial, "\n")] = '\0'; // remove newline character
            break;
        case 3:
            printf("Enter new description: ");
            fgets(inventory[index].description, MAX_DESCRIPTION_LEN, stdin);
            inventory[index].description[strcspn(inventory[index].description, "\n")] = '\0'; // remove newline character
            break;
        case 4:
            printf("Enter new quantity: ");
            scanf("%d", &inventory[index].quantity);
            getchar(); // remove newline character
            break;
        default:
            printf("Invalid choice.\n");
            return;
    }
    
    printf("Product updated.\n");
}

// Define a function to display the inventory
void display_inventory(Product* inventory, int count) {
    printf("%-20s%-20s%-40s%-10s\n", "Name", "Serial", "Description", "Quantity");
    for (int i = 0; i < count; i++) {
        printf("%-20s%-20s%-40s%-10d\n", inventory[i].name, inventory[i].serial, inventory[i].description, inventory[i].quantity);
    }
}

// Define the main function
int main() {
    Product inventory[MAX_PRODUCTS];
    int count = 0;
    int choice;
    
    printf("Product Inventory System\n");
    printf("========================\n");
    
    while (1) {
        printf("\nSelect an option:\n");
        printf("1. Add new product\n");
        printf("2. Remove product\n");
        printf("3. Update product\n");
        printf("4. Display inventory\n");
        printf("5. Exit\n");
        scanf("%d", &choice);
        getchar(); // remove newline character
        
        switch (choice) {
            case 1:
                add_product(inventory, &count);
                break;
            case 2:
                remove_product(inventory, &count);
                break;
            case 3:
                update_product(inventory, count);
                break;
            case 4:
                display_inventory(inventory, count);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice.\n");
                break;
        }
    }
    
    return 0;
}
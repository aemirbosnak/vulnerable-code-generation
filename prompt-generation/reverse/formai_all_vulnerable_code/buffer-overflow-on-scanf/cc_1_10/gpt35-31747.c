//FormAI DATASET v1.0 Category: Product Inventory System ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Defining product struct
struct product {
    int id;                 // Product ID
    char name[50];          // Product Name
    int quantity;           // Product Quantity in stock
    float price;            // Product Price per Unit
};

// Initializing Product Array
struct product products[100];

// Initializing Global Variables
int id_count = 1;
int product_count = 0;

// Function to Add New Product to the Inventory
void addProduct() {
    // Get ID Input from User
    printf("Enter Product ID: ");
    scanf("%d", &products[product_count].id);
    
    // Get Name Input from User
    printf("Enter Product Name: ");
    scanf("%s", products[product_count].name);
    
    // Get Quantity Input from User
    printf("Enter Product Quantity: ");
    scanf("%d", &products[product_count].quantity);
    
    // Get Price Input from User
    printf("Enter Product Price per Unit: ");
    scanf("%f", &products[product_count].price);
    
    printf("\nProduct Added Successfully!\n");
    
    // Incrementing ID Count and Product Count
    id_count++;
    product_count++;
}

// Function to Display all Products in the Inventory
void displayProducts() {
    // Check if Products Exist
    if (product_count > 0) {
        printf("\nProduct ID\tProduct Name\tProduct Quantity\tProduct Price\n");
        printf("-----------------------------------------------------------------\n");
        for (int i = 0; i < product_count; i++) {
            printf("%d\t\t%s\t\t%d\t\t%.2f\n", products[i].id, products[i].name, products[i].quantity, products[i].price);
        }
    }
    else {
        printf("\nNo Products Found in the Inventory\n");
    }
}

// Function to Search for a Product in the Inventory
void searchProduct() {
    // Get ID Input from User
    int search_id;
    printf("Enter Product ID: ");
    scanf("%d", &search_id);
    
    // Check if Product Exists
    bool found = false;
    for (int i = 0; i < product_count; i++) {
        if (products[i].id == search_id) {
            found = true;
            printf("\nProduct ID\tProduct Name\tProduct Quantity\tProduct Price\n");
            printf("-----------------------------------------------------------------\n");
            printf("%d\t\t%s\t\t%d\t\t%.2f\n", products[i].id, products[i].name, products[i].quantity, products[i].price);
            break;
        }
    }
    
    if (!found) {
        printf("\nProduct Not Found in the Inventory\n");
    }
}

// Function to Modify a Product in the Inventory
void modifyProduct() {
    // Get ID Input from User
    int modify_id;
    printf("Enter Product ID: ");
    scanf("%d", &modify_id);
    
    // Check if Product Exists
    int index;
    bool found = false;
    for (int i = 0; i < product_count; i++) {
        if (products[i].id == modify_id) {
            found = true;
            index = i;
            break;
        }
    }
    
    if (found) {
        // Get Name Input from User
        printf("Enter Product Name: ");
        scanf("%s", products[index].name);
        
        // Get Quantity Input from User
        printf("Enter Product Quantity: ");
        scanf("%d", &products[index].quantity);
        
        // Get Price Input from User
        printf("Enter Product Price per Unit: ");
        scanf("%f", &products[index].price);
        
        printf("\nProduct Modified Successfully!\n");
    }
    else {
        printf("\nProduct Not Found in the Inventory\n");
    }
}

// Function to Delete a Product from the Inventory
void deleteProduct() {
    // Get ID Input from User
    int delete_id;
    printf("Enter Product ID: ");
    scanf("%d", &delete_id);
    
    // Check if Product Exists
    int index;
    bool found = false;
    for (int i = 0; i < product_count; i++) {
        if (products[i].id == delete_id) {
            found = true;
            index = i;
            break;
        }
    }
    
    if (found) {
        // Removing Product from Array
        for (int i = index; i < product_count - 1; i++) {
            products[i] = products[i + 1];
        }
        
        printf("\nProduct Deleted Successfully!\n");
        
        // Decrementing Product Count
        product_count--;
    }
    else {
        printf("\nProduct Not Found in the Inventory\n");
    }
}

int main(void) {
    // Initializing Variables
    int choice;
    bool exit = false;
    
    while (!exit) {
        // Displaying Options to User
        printf("\nProduct Inventory System\n");
        printf("------------------------\n");
        printf("1. Add New Product\n");
        printf("2. Display All Products\n");
        printf("3. Search for a Product\n");
        printf("4. Modify a Product\n");
        printf("5. Delete a Product\n");
        printf("6. Exit Program\n");
        printf("Enter your Choice: ");
        scanf("%d", &choice);
        
        // Performing Operation Based on User Choice
        switch (choice) {
            case 1: addProduct();
                    break;
            case 2: displayProducts();
                    break;
            case 3: searchProduct();
                    break;
            case 4: modifyProduct();
                    break;
            case 5: deleteProduct();
                    break;
            case 6: exit = true;
                    break;
            default: printf("\nInvalid Choice, Please Try Again!\n");
        }
    }
    
    return 0;
}
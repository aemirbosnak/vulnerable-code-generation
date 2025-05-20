//FormAI DATASET v1.0 Category: Product Inventory System ; Style: enthusiastic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Structure for Product
struct product {
    int id;             // Product ID
    char name[20];      // Product Name
    int quantity;       // Quantity of Product
    float price;        // Price of Product
};

int main() {
    struct product inventory[10];   // Maximum 10 products can be stored in the inventory
    int choice, id, quantity, index, i;

    do {
        printf("\n 1. Add Product\n 2. Update Quantity\n 3. Search Product\n 4. Display Inventory\n 5. Exit\n Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:     // Add new Product
                printf(" Enter Product ID: ");
                scanf("%d", &id);

                // Check if the Product ID already exists
                for(i = 0; i < 10; i++) {
                    if(inventory[i].id == id) {
                        printf(" Product with ID %d already exists in the inventory.", id);
                        break;
                    }
                }

                // If Product ID does not exist, add the Product to the inventory
                if(i == 10) {
                    inventory[index].id = id;
                    printf(" Enter Product Name: ");
                    scanf("%s", inventory[index].name);
                    printf(" Enter Product Quantity: ");
                    scanf("%d", &inventory[index].quantity);
                    printf(" Enter Product Price: ");
                    scanf("%f", &inventory[index].price);

                    printf(" Product added successfully!");
                    index++;    // Increment index for the next product to be added
                }
                break;

            case 2:    // Update Product Quantity
                printf(" Enter Product ID: ");
                scanf("%d", &id);

                // Check if the Product ID exists
                for(i = 0; i < 10; i++) {
                    if(inventory[i].id == id) {
                        printf(" Enter new Product Quantity: ");
                        scanf("%d", &quantity);
                        inventory[i].quantity = quantity;
                        printf(" Product Quantity updated successfully.");
                        break;
                    }
                }

                if(i == 10) {
                    printf(" Product with ID %d does not exist in the inventory.", id);
                }
                break;

            case 3:     // Search Product
                printf(" Enter Product ID: ");
                scanf("%d", &id);

                // Check if the Product ID exists
                for(i = 0; i < 10; i++) {
                    if(inventory[i].id == id) {
                        printf(" Product ID\t Product Name\t Product Quantity\t Product Price\n");
                        printf(" %d\t\t %s\t\t %d\t\t %.2f", inventory[i].id, inventory[i].name, inventory[i].quantity, inventory[i].price);
                        break;
                    }
                }

                if(i == 10) {
                    printf(" Product with ID %d does not exist in the inventory.", id);
                }
                break;

            case 4:     // Display Inventory
                printf(" Product ID\t Product Name\t Product Quantity\t Product Price\n");

                for(i = 0; i < 10; i++) {
                    if(inventory[i].id != 0) {
                        printf(" %d\t\t %s\t\t %d\t\t %.2f\n", inventory[i].id, inventory[i].name, inventory[i].quantity, inventory[i].price);
                    }
                }
                break;

            case 5:     // Exit Program
                printf(" Thank you for using Product Inventory System!");
                exit(0);
                break;

            default:    // Invalid choice
                printf(" Invalid choice! Please try again.");
                break;
        }
    } while(1);

    return 0;
}
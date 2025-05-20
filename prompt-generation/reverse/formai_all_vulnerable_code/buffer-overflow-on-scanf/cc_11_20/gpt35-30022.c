//FormAI DATASET v1.0 Category: Product Inventory System ; Style: minimalist
//Minimalist Product Inventory System
//By: [Your Name]

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct product {
    char name[20];
    int id;
    int quantity;
    float price;
};

int main() {
    struct product inventory[100]; //maximum capacity of inventory is 100 products
    int num_products = 0; //current number of products in inventory
    int choice;
    int id;
    int i;

    while(1) { //loop until user chooses to exit
        printf("\n1. Add Product\n");
        printf("2. Search Product by ID\n");
        printf("3. View All Products\n");
        printf("4. Update Product Quantity\n");
        printf("5. Delete Product\n");
        printf("6. Exit\n");
        printf("\nEnter Choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: //add a new product to inventory
                if(num_products == 100) {
                    printf("Inventory is full.\n");
                    break;
                }
                printf("\nEnter Product Name: ");
                fflush(stdin); //clear input buffer
                fgets(inventory[num_products].name, 20, stdin);
                inventory[num_products].name[strcspn(inventory[num_products].name, "\n")] = '\0'; //remove newline character
                printf("Enter Product ID: ");
                scanf("%d", &inventory[num_products].id);
                printf("Enter Product Quantity: ");
                scanf("%d", &inventory[num_products].quantity);
                printf("Enter Product Price: ");
                scanf("%f", &inventory[num_products].price);
                num_products++;
                break;
            case 2: //search for a product by ID
                printf("\nEnter Product ID: ");
                scanf("%d", &id);
                for(i=0; i<num_products; i++) {
                    if(inventory[i].id == id) {
                        printf("\nName: %s\nID: %d\nQuantity: %d\nPrice: $%.2f\n", inventory[i].name, inventory[i].id, inventory[i].quantity, inventory[i].price);
                        break;
                    }
                }
                if(i == num_products) {
                    printf("\nProduct not found.\n");
                }
                break;
            case 3: //view all products in inventory
                printf("\n%-20s%-10s%-10s%-10s\n", "Name", "ID", "Qty", "Price");
                for(i=0; i<num_products; i++) {
                    printf("%-20s%-10d%-10d$%.2f\n", inventory[i].name, inventory[i].id, inventory[i].quantity, inventory[i].price);
                }
                break;
            case 4: //update quantity of a product
                printf("\nEnter Product ID: ");
                scanf("%d", &id);
                for(i=0; i<num_products; i++) {
                    if(inventory[i].id == id) {
                        printf("\nEnter New Quantity: ");
                        scanf("%d", &inventory[i].quantity);
                        break;
                    }
                }
                if(i == num_products) {
                    printf("\nProduct not found.\n");
                }
                break;
            case 5: //delete a product from inventory
                printf("\nEnter Product ID: ");
                scanf("%d", &id);
                for(i=0; i<num_products; i++) {
                    if(inventory[i].id == id) {
                        num_products--;
                        inventory[i] = inventory[num_products]; //overwrite deleted product with last product in list
                        printf("\nProduct deleted.\n");
                        break;
                    }
                }
                if(i == num_products) {
                    printf("\nProduct not found.\n");
                }
                break;
            case 6: //exit program
                exit(0);
            default:
                printf("\nInvalid Choice.\n");
                break;
        }
    }

    return 0;
}
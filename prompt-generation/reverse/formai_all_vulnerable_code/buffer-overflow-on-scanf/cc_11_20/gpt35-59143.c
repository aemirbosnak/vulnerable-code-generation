//FormAI DATASET v1.0 Category: Product Inventory System ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Product Structure
typedef struct Product{
    char name[50];
    char type[20];
    float price;
    int quantity;
} Product;

int main(){
    int choice;
    int num_products = 0;
    Product* inventory = NULL;

    do{
        printf("\n1. Add Product\n");
        printf("2. View Inventory\n");
        printf("3. Update Product\n");
        printf("4. Delete Product\n");
        printf("5. Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);

        if(choice == 1){ // Add product
            printf("\nAdd Product: \n");
            num_products++;
            inventory = (Product*)realloc(inventory, num_products * sizeof(Product));

            printf("Name: ");
            scanf("%s", inventory[num_products-1].name);
            printf("Type: ");
            scanf("%s", inventory[num_products-1].type);
            printf("Price: ");
            scanf("%f", &inventory[num_products-1].price);
            printf("Quantity: ");
            scanf("%d", &inventory[num_products-1].quantity);

            printf("\nProduct added successfully.\n");
        }
        else if(choice == 2){ // View Inventory
            printf("\nProduct Inventory:\n");
            for(int i=0; i<num_products; i++){
                printf("\nProduct %d:\n", i+1);
                printf("Name: %s\n", inventory[i].name);
                printf("Type: %s\n", inventory[i].type);
                printf("Price: %.2f\n", inventory[i].price);
                printf("Quantity: %d\n", inventory[i].quantity);
            }
        }
        else if(choice == 3){ // Update Product
            printf("\nEnter the index of the product to update (1-%d): ", num_products);
            int index;
            scanf("%d", &index);
            index--;

            if(index >= 0 && index < num_products){
                printf("\nCurrent Product Details:\n");
                printf("Name: %s\n", inventory[index].name);
                printf("Type: %s\n", inventory[index].type);
                printf("Price: %.2f\n", inventory[index].price);
                printf("Quantity: %d\n", inventory[index].quantity);

                printf("\nEnter New Product Details: \n");
                printf("Name: ");
                scanf("%s", inventory[index].name);
                printf("Type: ");
                scanf("%s", inventory[index].type);
                printf("Price: ");
                scanf("%f", &inventory[index].price);
                printf("Quantity: ");
                scanf("%d", &inventory[index].quantity);

                printf("\nProduct updated successfully.\n");
            }
            else{
                printf("\nInvalid index.\n");
            }
        }
        else if(choice == 4){ // Delete Product
            printf("\nEnter the index of the product to delete (1-%d): ", num_products);
            int index;
            scanf("%d", &index);
            index--;

            if(index >= 0 && index < num_products){
                for(int i=index; i<num_products-1; i++){
                    strcpy(inventory[i].name, inventory[i+1].name);
                    strcpy(inventory[i].type, inventory[i+1].type);
                    inventory[i].price = inventory[i+1].price;
                    inventory[i].quantity = inventory[i+1].quantity;
                }

                num_products--;
                inventory = (Product*)realloc(inventory, num_products * sizeof(Product));
                printf("\nProduct deleted successfully.\n");
            }
            else{
                printf("\nInvalid index.\n");
            }
        }
        else if(choice == 5){ // Exit
            printf("\nExiting program. Goodbye!\n");
            free(inventory);
            break;
        }
        else{ // Invalid choice
            printf("\nInvalid choice. Please choose 1-5 from the menu.\n");
        }
    }while(choice != 5);

    return 0;
}
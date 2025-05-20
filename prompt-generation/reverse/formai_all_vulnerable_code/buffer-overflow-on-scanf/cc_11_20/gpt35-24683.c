//FormAI DATASET v1.0 Category: Product Inventory System ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Product {    // struct for each product
    char name[20];
    int quantity;
    float price;
};

int main() {
    struct Product inventory[20];   // array of products
    int menuChoice;   // variable for user menu choice
    int numProducts = 0;   // variable to keep track of number of products added
    int i;

    do {
        // main menu
        printf("\n~~~PEACEFUL PRODUCT INVENTORY SYSTEM~~~\n");
        printf("1. Add a new product\n");
        printf("2. View inventory\n");
        printf("3. Update product quantity\n");
        printf("4. Search for a product\n");
        printf("5. Exit system\n");
        printf("Enter your choice (1-5): ");
        scanf("%d", &menuChoice);

        switch(menuChoice) {
            case 1:   // add a new product
                if(numProducts >= 20) {
                    printf("Inventory is full. Cannot add new product.\n");
                    break;
                }
                printf("Enter the name of the product: ");
                scanf("%s", inventory[numProducts].name);
                printf("Enter the price of the product: ");
                scanf("%f", &inventory[numProducts].price);
                printf("Enter the quantity of the product: ");
                scanf("%d", &inventory[numProducts].quantity);
                printf("Product added successfully!\n");
                numProducts++;
                break;

            case 2:   // view inventory
                if(numProducts == 0) {
                    printf("Inventory is empty.\n");
                    break;
                }
                for(i = 0; i < numProducts; i++) {
                    printf("%d. %s - $%.2f - %d in stock\n", i+1, inventory[i].name, inventory[i].price, inventory[i].quantity);
                }
                break;

            case 3:   // update product quantity
                if(numProducts == 0) {
                    printf("Inventory is empty.\n");
                    break;
                }
                int productChoice;
                printf("Which product's quantity would you like to update? (enter number 1-%d): ", numProducts);
                scanf("%d", &productChoice);
                if(productChoice < 1 || productChoice > numProducts) {
                    printf("Invalid choice.\n");
                    break;
                }
                int newQuantity;
                printf("Enter the new quantity for %s: ", inventory[productChoice-1].name);
                scanf("%d", &newQuantity);
                inventory[productChoice-1].quantity = newQuantity;
                printf("Quantity updated successfully!\n");
                break;

            case 4:   // search for a product
                if(numProducts == 0) {
                    printf("Inventory is empty.\n");
                    break;
                }
                char searchQuery[20];
                printf("Enter the name of the product you would like to search for: ");
                scanf("%s", searchQuery);
                int foundProduct = 0;   // variable to check if a product was found
                for(i = 0; i < numProducts; i++) {
                    if(strcmp(searchQuery, inventory[i].name) == 0) {   // if searchQuery matches a product name
                        foundProduct = 1;
                        printf("Match found!\n");
                        printf("%s - $%.2f - %d in stock\n", inventory[i].name, inventory[i].price, inventory[i].quantity);
                    }
                }
                if(!foundProduct) {
                    printf("No matches found.\n");
                }
                break;

            case 5:   // exit system
                printf("Thank you for using the Peaceful Product Inventory System. Have a nice day!\n");
                exit(0);
                break;

            default:   // invalid choice
                printf("Invalid choice.\n");
                break;
        }

    } while(1);   // infinite loop until user chooses to exit
    return 0;
}
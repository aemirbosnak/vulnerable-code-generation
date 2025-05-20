//FormAI DATASET v1.0 Category: Product Inventory System ; Style: standalone
#include<stdio.h>
#include<stdlib.h>

// Defining a Product struct
typedef struct Product {
    int productId;
    char name[50];
    float price;
    int quantity;
} Product;

int main()
{
    int choice, i, id, quantity;
    float price;
    char name[50];

    printf("\n\t\tPRODUCT INVENTORY SYSTEM\n\n");

    // Initializing an empty array of products
    Product products[100];
    int numProducts = 0;

    do {
        // Displaying menu of operations
        printf("1. Add a product\n");
        printf("2. Remove a product\n");
        printf("3. Update product price\n");
        printf("4. Update product quantity\n");
        printf("5. Display all products\n");
        printf("6. Exit\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                // Adding a product
                printf("\nEnter product details:\n");
                printf("Product ID: "); scanf("%d", &id);
                printf("Name: "); scanf("%s", name);
                printf("Price: "); scanf("%f", &price);
                printf("Quantity: "); scanf("%d", &quantity);

                products[numProducts].productId = id;
                strcpy(products[numProducts].name, name);
                products[numProducts].price = price;
                products[numProducts].quantity = quantity;
                numProducts++;
                printf("\nProduct added successfully!\n\n");
                break;

            case 2:
                // Removing a product
                printf("\nEnter product ID to be removed: ");
                scanf("%d", &id);
                for(i = 0; i < numProducts; i++) {
                    if(products[i].productId == id) {
                        for(int j = i; j < numProducts - 1; j++) {
                            products[j] = products[j+1];
                        }
                        numProducts--;
                        printf("\nProduct removed successfully!\n\n");
                        break;
                    }
                }
                if(i == numProducts) {
                    printf("\nProduct not found!\n\n");
                }
                break;

            case 3:
                // Updating product price
                printf("\nEnter product ID: ");
                scanf("%d", &id);
                printf("Enter updated price: ");
                scanf("%f", &price);
                for(i = 0; i < numProducts; i++) {
                    if(products[i].productId == id) {
                        products[i].price = price;
                        printf("\nProduct price updated successfully!\n\n");
                        break;
                    }
                }
                if(i == numProducts) {
                    printf("\nProduct not found!\n\n");
                }
                break;

            case 4:
                // Updating product quantity
                printf("\nEnter product ID: ");
                scanf("%d", &id);
                printf("Enter updated quantity: ");
                scanf("%d", &quantity);
                for(i = 0; i < numProducts; i++) {
                    if(products[i].productId == id) {
                        products[i].quantity = quantity;
                        printf("\nProduct quantity updated successfully!\n\n");
                        break;
                    }
                }
                if(i == numProducts) {
                    printf("\nProduct not found!\n\n");
                }
                break;

            case 5:
                // Displaying all products
                printf("\nPRODUCTS\n");
                printf("---------------------------------------------------\n");
                printf("ID\tName\tPrice\tQuantity\n");
                printf("---------------------------------------------------\n");
                for(i = 0; i < numProducts; i++) {
                    printf("%d\t%s\t%.2f\t%d\n",
                           products[i].productId, products[i].name,
                           products[i].price, products[i].quantity);
                }
                printf("\n");
                break;

            case 6:
                // Exit the program
                printf("\nExiting the program...\n\n");
                break;

            default:
                printf("\nInvalid choice! Try again.\n\n");
        }

    } while(choice != 6);

    return 0;
}
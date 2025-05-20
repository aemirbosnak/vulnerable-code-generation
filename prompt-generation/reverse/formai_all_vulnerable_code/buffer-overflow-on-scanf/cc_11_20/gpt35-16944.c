//FormAI DATASET v1.0 Category: Product Inventory System ; Style: energetic
#include<stdio.h>

// Defining a structure for products
struct product {
    int id;
    char name[50];
    int quantity;
    float price;
};

int main() {
    // Creating an array of products
    struct product products[100];
    int num_products = 0;

    // Displaying the options to the user
    printf("  *** Welcome to the Product Inventory System! ***\n\n");
    printf(" 1. Add a product\n 2. Display all products\n 3. Search for a product\n 4. Exit\n");

    while (1) {
        // Taking input for user choice
        int choice;
        printf("\nPlease enter your choice: ");
        scanf("%d", &choice);

        // Condition for adding a product
        if (choice == 1) {
            // Taking input for product details
            printf("\nEnter the name of the product: ");
            scanf("%s", &products[num_products].name);
            printf("Enter the quantity of the product: ");
            scanf("%d", &products[num_products].quantity);
            printf("Enter the price of the product: ");
            scanf("%f", &products[num_products].price);

            // Generating a unique id for the product
            products[num_products].id = num_products + 1;

            // Incrementing the number of products
            num_products++;

            printf("\nProduct added successfully!\n");
        }

        // Condition for displaying all products
        else if (choice == 2) {
            // Checking if there are any products
            if (num_products == 0) {
                printf("\nNo products found!\n");
            }
            else {
                printf("\nProduct ID\tName\t\tQuantity\tPrice\n");
                for (int i = 0; i < num_products; i++) {
                    printf("%d\t\t%s\t\t%d\t\t%.2f\n", products[i].id, products[i].name, products[i].quantity, products[i].price);
                }
            }
        }

        // Condition for searching for a product
        else if (choice == 3) {
            // Taking input for search query
            char search_query[50];
            printf("\nEnter the name of the product to search: ");
            scanf("%s", search_query);

            // Initializing a flag variable
            int found = 0;

            // Searching for product
            for (int i = 0; i < num_products; i++) {
                if (strcmp(products[i].name, search_query) == 0) {
                    printf("\nProduct found!\n");
                    printf("Product ID\tName\t\tQuantity\tPrice\n");
                    printf("%d\t\t%s\t\t%d\t\t%.2f\n", products[i].id, products[i].name, products[i].quantity, products[i].price);
                    found = 1;
                }
            }

            // Printing message if product not found
            if (found == 0) {
                printf("\nProduct not found!\n");
            }
        }

        // Condition for exiting
        else if (choice == 4) {
            printf("\nGoodbye!\n");
            return 0;
        }

        // Condition for invalid input
        else {
            printf("\nInvalid input! Please enter a valid option.\n");
        }
    }

    return 0;
}
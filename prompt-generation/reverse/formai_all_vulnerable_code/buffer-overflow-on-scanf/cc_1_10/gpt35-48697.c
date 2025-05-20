//FormAI DATASET v1.0 Category: Product Inventory System ; Style: distributed
#include<stdio.h>
#include<string.h>

// Defining the structure for the product
struct Product {
    char name[20];
    int quantity;
    float price;
};

// Function to display the details of a product
void display_product(struct Product p) {
    printf("\nProduct Name: %s", p.name);
    printf("\nQuantity: %d", p.quantity);
    printf("\nPrice per unit: %.2f", p.price);
    printf("\n");
}

int main() {
    int n, choice, i, j, found;
    char search_name[20];
    float total_cost;
    struct Product products[50];

    printf("\nEnter the number of products: ");
    scanf("%d", &n);

    // Taking input for each product
    for(i=0; i<n; i++) {
        printf("\nProduct %d:", i+1);
        printf("\nEnter the name: ");
        scanf("%s", products[i].name);
        printf("Enter the quantity: ");
        scanf("%d", &products[i].quantity);
        printf("Enter the price per unit: ");
        scanf("%f", &products[i].price);
    }

    // Displaying the menu
    do {
        found = 0;
        printf("\n\nMenu\n");
        printf("1. Display all products\n");
        printf("2. Search for a product\n");
        printf("3. Calculate total cost\n");
        printf("4. Exit\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        // Switch case for each choice
        switch(choice) {
            case 1:
                printf("\nProduct Details\n");
                for(i=0; i<n; i++) {
                    display_product(products[i]);
                }
                break;

            case 2:
                printf("\nEnter the name of the product to be searched: ");
                scanf("%s", search_name);

                // Searching for the product by name
                for(i=0; i<n; i++) {
                    if(strcmp(products[i].name, search_name) == 0) {
                        printf("\nProduct Found!\n");
                        display_product(products[i]);
                        found = 1;
                        break;
                    }
                }
                if(found == 0) {
                    printf("\nProduct not found.\n");
                }
                break;

            case 3:
                total_cost = 0;
                for(i=0; i<n; i++) {
                    total_cost += products[i].price * products[i].quantity;
                }
                printf("\nTotal cost = %.2f", total_cost);
                break;

            case 4:
                printf("\nExiting program.\n");
                break;

            default:
                printf("\nInvalid choice. Please try again.\n");
                break;
        }
    } while(choice != 4);

    return 0;
}
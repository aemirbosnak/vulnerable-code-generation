//FormAI DATASET v1.0 Category: Product Inventory System ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100 //Maximum number of products we can store

//A structure to represent a product
struct Product {
    int id;
    char name[50];
    double price;
    int quantity;
};

//Function prototypes
void addProduct(struct Product products[], int* count);
void viewProduct(struct Product products[], int count);
void deleteProduct(struct Product products[], int* count);
void searchProduct(struct Product products[], int count);

//Main function
int main(){
    int menuChoice;
    int productCount = 0;
    struct Product products[MAX_PRODUCTS];
    do {
        //Print menu
        printf("\n---Product Inventory System---\n");
        printf("1. Add a product\n");
        printf("2. View all products\n");
        printf("3. Delete a product\n");
        printf("4. Search for a product\n");
        printf("5. Exit\n");
        printf("Enter your choice (1-5): ");
        scanf("%d", &menuChoice);

        //Act on menu choice
        switch (menuChoice) {
            case 1:
                addProduct(products, &productCount);
                break;
            case 2:
                viewProduct(products, productCount);
                break;
            case 3:
                deleteProduct(products, &productCount);
                break;
            case 4:
                searchProduct(products, productCount);
                break;
            case 5:
                printf("\nExiting program.\n");
                break;
            default:
                printf("\nInvalid choice. Please try again.\n");
                break;
        }
    } while (menuChoice != 5);

    return 0;
}

//Function to add a product to the inventory
void addProduct(struct Product products[], int* count) {
    struct Product p;

    //Get product details from user
    printf("\nEnter details for new product:\n");
    printf("ID: ");
    scanf("%d", &p.id);
    printf("Name: ");
    scanf("%s", p.name);
    printf("Price: ");
    scanf("%lf", &p.price);
    printf("Quantity: ");
    scanf("%d", &p.quantity);

    //Add product to array
    products[*count] = p;
    (*count)++;
    printf("\nProduct added successfully.\n");
}

//Function to view all products in the inventory
void viewProduct(struct Product products[], int count) {
    if (count == 0) {
        printf("\nNo products to display.\n");
    } else {
        printf("\n---List of Products---\n");
        for (int i = 0; i < count; i++) {
            printf("%d. %s\t%.2lf\t%d\n", products[i].id, products[i].name, products[i].price, products[i].quantity);
        }
    }
}

//Function to delete a product from the inventory
void deleteProduct(struct Product products[], int* count) {
    int idToDelete;
    int found = 0;

    //Get product ID from user
    printf("\nEnter ID of product to delete: ");
    scanf("%d", &idToDelete);

    //Find product in array and delete it
    for (int i = 0; i < *count; i++) {
        if (products[i].id == idToDelete) {
            found = 1;
            for (int j = i; j < *count - 1; j++) {
                products[j] = products[j+1];
            }
            (*count)--;
            printf("\nProduct deleted successfully.\n");
            break;
        }
    }

    if (!found) {
        printf("\nProduct not found.\n");
    }
}

//Function to search for a product in the inventory
void searchProduct(struct Product products[], int count) {
    char keyword[50];
    int found = 0;

    //Get search keyword from user
    printf("\nEnter a product name to search for: ");
    scanf("%s", keyword);

    //Search array for product name containing keyword
    for (int i = 0; i < count; i++) {
        if (strstr(products[i].name, keyword) != NULL) {
            found = 1;
            printf("%d. %s\t%.2lf\t%d\n", products[i].id, products[i].name, products[i].price, products[i].quantity);
        }
    }

    if (!found) {
        printf("\nProduct not found.\n");
    }
}
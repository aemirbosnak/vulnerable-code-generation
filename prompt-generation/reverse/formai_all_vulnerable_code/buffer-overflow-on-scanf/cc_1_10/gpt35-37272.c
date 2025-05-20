//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/*Structure for Product details*/
struct Product {
    char productName[50];
    float price;
    int quantity;
    char category[20];
};

/*Function to add new product*/
void addProduct(struct Product *warehouse, int *productCount) {
    printf("Enter product name: ");
    scanf("%s", warehouse[*productCount].productName);
    printf("Enter product price: ");
    scanf("%f", &(warehouse[*productCount].price));
    printf("Enter product quantity: ");
    scanf("%d", &(warehouse[*productCount].quantity));
    printf("Enter product category: ");
    scanf("%s", warehouse[*productCount].category);
    (*productCount)++;
    printf("Product added successfully!\n");
}

/*Function to search for a product*/
void searchProduct(struct Product *warehouse, int productCount) {
    char searchName[50];
    bool found = false;
    printf("Enter name of product to search: ");
    scanf("%s", searchName);
    for(int i=0; i<productCount; i++) {
        if(strcmp(warehouse[i].productName, searchName) == 0) {
            printf("\nProduct Details:\n");
            printf("Product Name: %s\n", warehouse[i].productName);
            printf("Price: %f\n", warehouse[i].price);
            printf("Quantity: %d\n", warehouse[i].quantity);
            printf("Category: %s\n", warehouse[i].category);
            found = true;
            break;
        }
    }
    if(!found) {
        printf("\nProduct not found!\n");
    }
}

/*Function to update product details*/
void updateProduct(struct Product *warehouse, int productCount) {
    char updateName[50];
    bool found = false;
    printf("Enter name of product to update: ");
    scanf("%s", updateName);
    for(int i=0; i<productCount; i++) {
        if(strcmp(warehouse[i].productName, updateName) == 0) {
            printf("Enter updated price: ");
            scanf("%f", &(warehouse[i].price));
            printf("Enter updated quantity: ");
            scanf("%d", &(warehouse[i].quantity));
            printf("Enter updated category: ");
            scanf("%s", warehouse[i].category);
            printf("Product details updated successfully!\n");
            found = true;
            break;
        }
    }
    if(!found) {
        printf("\nProduct not found!\n");
    }
}

/*Function to delete product*/
void deleteProduct(struct Product *warehouse, int *productCount) {
    char deleteName[50];
    bool found = false;
    printf("Enter name of product to delete: ");
    scanf("%s", deleteName);
    for(int i=0; i<*productCount; i++) {
        if(strcmp(warehouse[i].productName, deleteName) == 0) {
            for(int j=i; j<(*productCount-1); j++) {
                strcpy(warehouse[j].productName, warehouse[j+1].productName);
                warehouse[j].price = warehouse[j+1].price;
                warehouse[j].quantity = warehouse[j+1].quantity;
                strcpy(warehouse[j].category, warehouse[j+1].category);
            }
            (*productCount)--;
            printf("Product deleted successfully!\n");
            found = true;
            break;
        }
    }
    if(!found) {
        printf("\nProduct not found!\n");
    }
}

/*Function to display all products*/
void displayProducts(struct Product *warehouse, int productCount) {
    printf("\nProduct Details:\n");
    for(int i=0; i<productCount; i++) {
        printf("--------------------------\n");
        printf("Product Name: %s\n", warehouse[i].productName);
        printf("Price: %f\n", warehouse[i].price);
        printf("Quantity: %d\n", warehouse[i].quantity);
        printf("Category: %s\n", warehouse[i].category);
    }
    printf("--------------------------\n");
}


int main() {
    struct Product warehouse[100];
    int productCount = 0, choice;

    while(true) {
        printf("Warehouse Management System\n");
        printf("1. Add new product\n");
        printf("2. Search for product\n");
        printf("3. Update product details\n");
        printf("4. Delete product\n");
        printf("5. Display all products\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                addProduct(warehouse, &productCount);
                break;
            case 2:
                searchProduct(warehouse, productCount);
                break;
            case 3:
                updateProduct(warehouse, productCount);
                break;
            case 4:
                deleteProduct(warehouse, &productCount);
                break;
            case 5:
                displayProducts(warehouse, productCount);
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice, please try again!\n");
        }
    }

    return 0;
}
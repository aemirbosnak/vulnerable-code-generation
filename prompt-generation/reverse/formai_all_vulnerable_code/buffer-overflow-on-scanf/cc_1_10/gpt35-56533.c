//FormAI DATASET v1.0 Category: Product Inventory System ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Product {
    int id;
    char name[20];
    int quantity;
    float price;
};

void addProduct(struct Product *products, int *totalProducts);
void displayAllProducts(struct Product *products, int totalProducts);
void searchProduct(struct Product *products, int totalProducts);
void updateProduct(struct Product *products, int totalProducts);
void deleteProduct(struct Product *products, int *totalProducts);

int main()
{
    struct Product products[100];
    int totalProducts = 0;
    int choice;

    while(1) {
        printf("\n-------------------------");
        printf("\nChoose an option: ");
        printf("\n-------------------------");
        printf("\n1 - Add a product");
        printf("\n2 - Display all products");
        printf("\n3 - Search a product");
        printf("\n4 - Update a product");
        printf("\n5 - Delete a product");
        printf("\n0 - Exit");
        printf("\n-------------------------");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                addProduct(products, &totalProducts);
                break;
            case 2:
                displayAllProducts(products, totalProducts);
                break;
            case 3:
                searchProduct(products, totalProducts);
                break;
            case 4:
                updateProduct(products, totalProducts);
                break;
            case 5:
                deleteProduct(products, &totalProducts);
                break;
            case 0:
                printf("\nExiting the program...");
                exit(0);
                break;
            default:
                printf("\nInvalid choice. Please try again...");
                break;
        }
    }

    return 0;
}

void addProduct(struct Product *products, int *totalProducts)
{
    if (*totalProducts >= 100) {
        printf("\nMaximum products limit reached. Can't add more products.");
        return;
    }

    printf("\nEnter the product details:");

    printf("\nProduct ID: ");
    scanf("%d", &products[*totalProducts].id);

    printf("\nProduct Name: ");
    scanf("%s", products[*totalProducts].name);

    printf("\nProduct Quantity: ");
    scanf("%d", &products[*totalProducts].quantity);

    printf("\nProduct Price: ");
    scanf("%f", &products[*totalProducts].price);

    (*totalProducts)++;

    printf("\nProduct added successfully.");
}

void displayAllProducts(struct Product *products, int totalProducts)
{
    if (totalProducts == 0) {
        printf("\nNo products added yet.");
        return;
    }

    printf("\nProduct ID\tProduct Name\tProduct Quantity\tProduct Price");

    for(int i=0; i<totalProducts; i++) {
        printf("\n%d\t\t%s\t\t%d\t\t%.2f", products[i].id, products[i].name, products[i].quantity, products[i].price);
    }
}

void searchProduct(struct Product *products, int totalProducts)
{
    if (totalProducts == 0) {
        printf("\nNo products added yet.");
        return;
    }

    int id, flag=0;

    printf("\nEnter product ID to search: ");
    scanf("%d", &id);

    for(int i=0; i<totalProducts; i++) {
        if(products[i].id == id) {
            printf("\nProduct details found:");
            printf("\nProduct ID: %d", products[i].id);
            printf("\nProduct Name: %s", products[i].name);
            printf("\nProduct Quantity: %d", products[i].quantity);
            printf("\nProduct Price: %.2f", products[i].price);
            flag = 1;
            break;
        }
    }

    if (flag == 0) {
        printf("\nProduct not found.");
    }
}

void updateProduct(struct Product *products, int totalProducts)
{
    if (totalProducts == 0) {
        printf("\nNo products added yet.");
        return;
    }

    int id, flag=0;

    printf("\nEnter product ID to update: ");
    scanf("%d", &id);

    for(int i=0; i<totalProducts; i++) {
        if(products[i].id == id) {
            printf("\nEnter the new product details:");

            printf("\nProduct Name: ");
            scanf("%s", products[i].name);

            printf("\nProduct Quantity: ");
            scanf("%d", &products[i].quantity);

            printf("\nProduct Price: ");
            scanf("%f", &products[i].price);

            printf("\nProduct updated successfully.");
            flag = 1;
            break;
        }
    }

    if (flag == 0) {
        printf("\nProduct not found.");
    }
}

void deleteProduct(struct Product *products, int *totalProducts)
{
    if (*totalProducts == 0) {
        printf("\nNo products added yet.");
        return;
    }

    int id, flag=0;

    printf("\nEnter product ID to delete: ");
    scanf("%d", &id);

    for(int i=0; i<*totalProducts; i++) {
        if(products[i].id == id) {
            for(int j=i; j<(*totalProducts)-1; j++) {
                products[j] = products[j+1];
            }
            (*totalProducts)--;
            printf("\nProduct deleted successfully.");
            flag = 1;
            break;
        }
    }

    if (flag == 0) {
        printf("\nProduct not found.");
    }
}
//FormAI DATASET v1.0 Category: Product Inventory System ; Style: automated
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

//Define the struct for the product
struct product {
    char name[50];
    int quantity;
    float price;
};

//Define a function to add a product to the inventory
void addProduct(struct product * productList, int * productCount) {
    printf("Enter product name: ");
    scanf("%s", (productList+*productCount)->name);
    printf("Enter quantity: ");
    scanf("%d", &(productList+*productCount)->quantity);
    printf("Enter price: ");
    scanf("%f", &(productList+*productCount)->price);
    (*productCount)++;
    
    printf("Product added.\n");
}

//Define a function to display all products in the inventory
void displayProducts(struct product * productList, int productCount) {
    if(productCount==0) {
        printf("The inventory is empty.\n");
        return;
    }
    printf("Product inventory:\n");
    printf("Name\t\tQuantity\tPrice\n");
    for(int i=0; i<productCount; i++) {
        printf("%s\t\t%d\t\t%.2f\n", (productList+i)->name, (productList+i)->quantity, (productList+i)->price);
    }
}

//Define a function to search for a product and display product details
void searchProduct(struct product * productList, int productCount) {
    if(productCount==0) {
        printf("The inventory is empty.\n");
        return;
    }
    char searchName[50];
    printf("Enter product name to search: ");
    scanf("%s", searchName);
    for(int i=0; i<productCount; i++) {
        if(strcmp((productList+i)->name, searchName)==0) {
            printf("Product details:\n");
            printf("Name: %s\nQuantity: %d\nPrice: %.2f\n", (productList+i)->name, (productList+i)->quantity, (productList+i)->price);
            return;
        }
    }
    printf("No product found with the name %s.\n", searchName);
}

int main() {
    int choice = 0, productCount = 0;
    struct product productList[100];
    printf("Product inventory system\n");
    while(choice!=4) {
        printf("\n1. Add product to inventory\n2. Display all products in inventory\n3. Search for a product\n4. Exit\n");
        printf("Enter your choice (1-4): ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                addProduct(productList, &productCount);
                break;
            case 2:
                displayProducts(productList, productCount);
                break;
            case 3:
                searchProduct(productList, productCount);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}
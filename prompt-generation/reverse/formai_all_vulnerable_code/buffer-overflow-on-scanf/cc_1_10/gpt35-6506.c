//FormAI DATASET v1.0 Category: Product Inventory System ; Style: thoughtful
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Product { 
    char name[50];
    int id;
    int quantity;
    float price;
};

void displayMenu() { // Function to display menu options
    printf("\n========== MENU ==========\n");
    printf("\n1. Add a product to the inventory\n");
    printf("2. Update a product in the inventory\n");
    printf("3. Delete a product from the inventory\n");
    printf("4. Display all products in the inventory\n");
    printf("5. Exit\n");
    printf("==========================\n\n");
}

void addProduct(struct Product products[], int* count) { // Function to add a new product
    struct Product newProduct;
    printf("\n===== ADD A PRODUCT =====\n");
    printf("Enter Product ID: ");
    scanf("%d", &newProduct.id);
    printf("Enter Product Name: ");
    scanf("%s", newProduct.name);
    printf("Enter Product Price: ");
    scanf("%f", &newProduct.price);
    printf("Enter Product Quantity: ");
    scanf("%d", &newProduct.quantity);
    products[*count] = newProduct;
    (*count)++;
    printf("\nProduct has been added to the inventory successfully.\n");
}

void updateProduct(struct Product products[], int count) { // Function to update an existing product
    int id, choice;
    printf("\n===== UPDATE A PRODUCT =====\n");
    printf("Enter Product ID: ");
    scanf("%d", &id);
    for(int i=0; i<count; i++) {
        if(products[i].id == id) {
            printf("What do you want to update?\n");
            printf("1. Product Name\n");
            printf("2. Product Price\n");
            printf("3. Product Quantity\n");
            scanf("%d", &choice);
            switch(choice) {
                case 1:
                    printf("Enter new Product Name: ");
                    scanf("%s", products[i].name);
                    printf("\nProduct Name has been updated successfully.\n");
                    return;
                case 2:
                    printf("Enter new Product Price: ");
                    scanf("%f", &products[i].price);
                    printf("\nProduct Price has been updated successfully.\n");
                    return;
                case 3:
                    printf("Enter new Product Quantity: ");
                    scanf("%d", &products[i].quantity);
                    printf("\nProduct Quantity has been updated successfully.\n");
                    return;
                default:
                    printf("\nInvalid choice!\n");
                    return;
            }
        }
    }
    printf("\nProduct not found!\n");
}

void deleteProduct(struct Product products[], int* count) { // Function to delete a product
    int id, i;
    printf("\n===== DELETE A PRODUCT =====\n");
    printf("Enter Product ID: ");
    scanf("%d", &id);    
    for(i=0; i<*count; i++) {
        if(products[i].id == id) {
            break;
        }
    }
    if(i == *count) {
        printf("\nProduct not found!\n");
        return;
    }
    for(int j=i; j<*count-1; j++) {
        products[j] = products[j+1];
    }
    (*count)--;
    printf("\nProduct has been deleted from the inventory successfully.\n");
}

void displayProducts(struct Product products[], int count) { // Function to display all products
    printf("\n===== PRODUCTS IN THE INVENTORY =====\n");
    printf("ID\tNAME\tPRICE\tQUANTITY\n");
    for(int i=0; i<count; i++) {
        printf("%d\t%s\t%.2f\t%d\n", products[i].id, products[i].name, products[i].price, products[i].quantity);
    }
}

int main() {
    struct Product products[100];
    int count = 0, choice;
    while(1) {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                addProduct(products, &count);
                break;
            case 2:
                updateProduct(products, count);
                break;
            case 3:
                deleteProduct(products, &count);
                break;
            case 4:
                displayProducts(products, count);
                break;
            case 5:
                printf("\nExiting the program...\n");
                exit(0);
            default:
                printf("\nInvalid choice!\n");
        }
    }
    return 0;
}
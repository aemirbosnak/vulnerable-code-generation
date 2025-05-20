//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: Claude Shannon
//Warehouse Management System by Claude Shannon

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Define structure for product
struct Product {
    char name[20];
    int id;
    int quantity;
    float price;
};

//Function to add a new product
void addProduct(struct Product *p, int n) {
    scanf("%s %d %d %f", p[n].name, &p[n].id, &p[n].quantity, &p[n].price);
}

//Function to update product information
void updateProduct(struct Product *p, int n) {
    int id;
    printf("Enter the product ID: ");
    scanf("%d", &id);
    for(int i=0; i<n; i++) {
        if(p[i].id == id) {
            scanf("%s %d %d %f", p[i].name, &p[i].quantity, &p[i].price);
            printf("Product information updated.\n");
            return;
        }
    }
    printf("Product not found.\n");
}

//Function to display all products
void displayAllProducts(struct Product *p, int n) {
    printf("ID\tNAME\tQUANTITY\tPRICE\n");
    for(int i=0; i<n; i++) {
        printf("%d\t%s\t%d\t\t%.2f\n", p[i].id, p[i].name, p[i].quantity, p[i].price);
    }
}

//Function to search for a product
void searchProduct(struct Product *p, int n) {
    int id;
    printf("Enter the product ID: ");
    scanf("%d", &id);
    for(int i=0; i<n; i++) {
        if(p[i].id == id) {
            printf("ID\tNAME\tQUANTITY\tPRICE\n");
            printf("%d\t%s\t%d\t\t%.2f\n", p[i].id, p[i].name, p[i].quantity, p[i].price);
            return;
        }
    }
    printf("Product not found.\n");
}

int main() {
    int choice, n=0;
    struct Product p[100];
    do {
        printf("-------------------------------\n");
        printf("Warehouse Management System\n");
        printf("-------------------------------\n");
        printf("1. Add a new product\n");
        printf("2. Update product information\n");
        printf("3. Display all products\n");
        printf("4. Search for a product\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("Enter the product details (name, id, quantity, price): ");
                addProduct(p, n++);
                printf("Product added successfully.\n");
                break;
            case 2:
                updateProduct(p, n);
                break;
            case 3:
                displayAllProducts(p, n);
                break;
            case 4:
                searchProduct(p, n);
                break;
            case 5:
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    } while(choice != 5);
    return 0;
}
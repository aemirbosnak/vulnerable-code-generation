//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: interoperable
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Structure for storing product details
struct Product {
    int id;
    char name[50];
    float price;
    int quantity;
};

int main() {
    int choice, i, j, flag, id, quantity;
    struct Product products[100];
    int productCount = 0;

    while(1) {
        printf("\nWarehouse Management System\n");
        printf("1. Add Product\n");
        printf("2. Update Product Quantity\n");
        printf("3. Search Product By ID\n");
        printf("4. List all Products\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                // Add Product
                printf("\nEnter Product ID: ");
                scanf("%d", &id);
                printf("Enter Product Name: ");
                scanf("%s", products[productCount].name);
                printf("Enter Product Price: ");
                scanf("%f", &products[productCount].price);
                printf("Enter Product Quantity: ");
                scanf("%d", &products[productCount].quantity);

                products[productCount].id = id;
                productCount++;

                printf("\nProduct added successfully!\n");
                break;

            case 2:
                // Update Product Quantity
                printf("\nEnter Product ID: ");
                scanf("%d", &id);

                flag = 0;
                for(i=0; i<productCount; i++) {
                    if(products[i].id == id) {
                        printf("Enter Quantity to be added: ");
                        scanf("%d", &quantity);

                        products[i].quantity += quantity;
                        printf("\nQuantity updated successfully!\n");
                        flag = 1;
                        break;
                    }
                }

                if(flag == 0) {
                    printf("\nProduct not found!\n");
                }
                break;

            case 3:
                // Search Product By ID
                printf("\nEnter Product ID: ");
                scanf("%d", &id);

                flag = 0;
                for(i=0; i<productCount; i++) {
                    if(products[i].id == id) {
                        printf("\nID\tName\t\tPrice\tQuantity\n");
                        printf("%d\t%s\t%.2f\t%d\n", products[i].id, products[i].name, products[i].price, products[i].quantity);
                        flag = 1;
                        break;
                    }
                }

                if(flag == 0) {
                    printf("\nProduct not found!\n");
                }
                break;

            case 4:
                // List all Products
                printf("\nID\tName\t\tPrice\tQuantity\n");
                for(i=0; i<productCount; i++) {
                    printf("%d\t%s\t%.2f\t%d\n", products[i].id, products[i].name, products[i].price, products[i].quantity);
                }
                break;

            case 5:
                // Exit
                exit(0);
                break;

            default:
                // Invalid choice
                printf("\nInvalid choice!\n");
                break;
        }
    }

    return 0;
}
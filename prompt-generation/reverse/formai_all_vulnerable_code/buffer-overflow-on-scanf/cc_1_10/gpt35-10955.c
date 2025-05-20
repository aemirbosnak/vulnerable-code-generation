//FormAI DATASET v1.0 Category: Product Inventory System ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Constants
#define MAX_PRODS 20
#define MAX_NAME_LEN 30

//Struct Defintions
struct Product {
    char name[MAX_NAME_LEN];
    int quantity;
    float price;
};

//Function Declarations
void addProduct(struct Product products[], int *numProducts);
void removeProduct(struct Product products[], int *numProducts);
void displayInventory(struct Product products[], int numProducts);

int main() {
    struct Product products[MAX_PRODS];
    int numProducts = 0;
    int choice;

    do {
        printf("\n---- Product Inventory System ----\n");
        printf("1. Add Product\n");
        printf("2. Remove Product\n");
        printf("3. Display Inventory\n");
        printf("4. Exit\n");
        printf("Enter choice (1-4): ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                addProduct(products, &numProducts);
                break;
            case 2:
                removeProduct(products, &numProducts);
                break;
            case 3:
                displayInventory(products, numProducts);
                break;
            case 4:
                printf("\nExiting Program\n");
                exit(0);
            default:
                printf("\nInvalid Choice. Try Again.\n");
        }
    } while(choice != 4);

    return 0;
}

void addProduct(struct Product products[], int *numProducts) {
    if(*numProducts == MAX_PRODS) {
        printf("\nInventory Limit Reached. Cannot add Product.\n");
        return;
    }

    printf("\nEnter Product Name: ");
    scanf("%s", products[*numProducts].name);

    printf("Enter Quantity: ");
    scanf("%d", &products[*numProducts].quantity);

    printf("Enter Price: ");
    scanf("%f", &products[*numProducts].price);

    (*numProducts)++;

    printf("\nProduct Added Successfully!\n");
}

void removeProduct(struct Product products[], int *numProducts) {
    int i, j;
    char name[MAX_NAME_LEN];

    printf("\nEnter Product Name to Remove: ");
    scanf("%s", name);

    for(i = 0; i < *numProducts; i++) {
        if(strcmp(products[i].name, name) == 0) {
            //Shift all elements one position left
            for(j = i; j < *numProducts - 1; j++) {
                products[j] = products[j + 1];
            }

            (*numProducts)--;

            printf("\nProduct Removed Successfully!\n");
            return;
        }
    }

    printf("\nProduct not found in Inventory.\n");
}

void displayInventory(struct Product products[], int numProducts) {
    int i;

    printf("\n----------- INVENTORY -----------\n");
    printf("%-15s %-10s %-10s\n", "Product Name", "Quantity", "Price");
    printf("---------------------------------\n");

    for(i = 0; i < numProducts; i++) {
        printf("%-15s %-10d %-10.2f\n", products[i].name, products[i].quantity, products[i].price);
    }

    printf("---------------------------------\n");
}
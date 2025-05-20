//FormAI DATASET v1.0 Category: Product Inventory System ; Style: shape shifting
#include<stdio.h>
#include<stdlib.h>

typedef struct product{
    char name[50];
    int id;
    float price;
    int quantity;
} product; // we define struct product and initialize it

void addProduct(product *p, int *n);
void displayProducts(product *p, int n);
void findProduct(product *p, int n, int id);

int main(){
    int choice = 0, numProducts = 0;
    product *products;

    while(choice != 4) {
        printf("\n---------------------\n");
        printf(" 1. Add Product");
        printf("\n 2. Display All Products");
        printf("\n 3. Find a product by ID");
        printf("\n 4. Exit");
        printf("\n---------------------\n");
        printf("Enter your choice: ");

        scanf("%d", &choice); 

        switch(choice) {
            case 1:
                addProduct(products, &numProducts); // add a product
                break;
            case 2:
                displayProducts(products, numProducts); // display all products
                break;
            case 3:
                findProduct(products, numProducts, 0); // find a product
                break;
            case 4:
                printf("\nExiting Program...\n");
                return 0;
            default:
                printf("\nInvalid Choice. Try Again.\n");
                break;
        }
    }
    return 0;
}

void addProduct(product *p, int *n) {
    if(*n == 0) {
        p = (product*) calloc(1, sizeof(product)); //allocate memory dynamically for one product
    }
    else {
        p = (product*) realloc(p, (*n+1)*sizeof(product)); //increase the memory block for additional products
    }

    printf("\nEnter Product Name: ");
    scanf(" %[^\n]s", &p[*n].name);
    printf("\nEnter Product ID: ");
    scanf("%d", &p[*n].id);
    printf("\nEnter Product Price: ");
    scanf("%f", &p[*n].price);
    printf("\nEnter Product Quantity: ");
    scanf("%d", &p[*n].quantity);

    (*n)++;
    printf("\nProduct Added Successfully.\n"); 
}

void displayProducts(product *p, int n) {
    if(n == 0) {
        printf("\nNo Products Added Yet.\n");
        return;
    }
    printf("\n---------------------Product List---------------------\n");
    printf("\n%-30s %-10s %-10s %-10s\n", "NAME", "ID", "PRICE", "IN STOCK");
    printf("-------------------------------------------------------\n");
    for (int i=0; i<n; i++) {
        printf("%-30s %-10d $%-9.2f %-10d\n", p[i].name, p[i].id, p[i].price, p[i].quantity);
    }
    printf("-------------------------------------------------------\n");
}

void findProduct(product *p, int n, int id) {
    if(n == 0) {
        printf("\nNo Products Added Yet.\n");
        return;
    }
    if(id == 0) {
        printf("\nEnter Product ID: ");
        scanf("%d", &id);
    }

    int i;
    for(i=0; i<n; i++) {
        if(p[i].id == id) {
            printf("\nProduct Details: \n");
            printf("Product Name: %s\n", p[i].name);
            printf("Product ID: %d\n", p[i].id);
            printf("Product Price: %.2f\n", p[i].price);
            printf("Product Quantity: %d\n", p[i].quantity);
            break;
        }
    }
    if (i == n) {
        printf("\nProduct Not Found.\n");
    }
}
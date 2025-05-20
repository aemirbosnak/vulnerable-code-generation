//FormAI DATASET v1.0 Category: Product Inventory System ; Style: intelligent
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Product{
    char name[20];
    int id;
    float price;
    int quantity;
} Product;

//function to display products in inventory
void displayInventory(Product p[], int n){
    printf("Inventory:\n");
    printf("%-10s %-10s %-10s %-10s\n", "Product", "ID", "Price", "Quantity");
    for(int i=0; i<n; i++){
        printf("%-10s %-10d %-10.2f %-10d\n", p[i].name, p[i].id, p[i].price, p[i].quantity);
    }
    printf("\n");
}

//function to add product to inventory
void addProduct(Product p[], int *n){
    printf("Enter product name: ");
    scanf("%s", p[*n].name);
    printf("Enter product ID: ");
    scanf("%d", &p[*n].id);
    printf("Enter product price: ");
    scanf("%f", &p[*n].price);
    printf("Enter product quantity: ");
    scanf("%d", &p[*n].quantity);
    (*n)++;
    printf("Product added to inventory!\n");
    printf("\n");
}

//function to search for product in inventory
void searchProduct(Product p[], int n){
    int id;
    printf("Enter product ID: ");
    scanf("%d", &id);
    for(int i=0; i<n; i++){
        if(p[i].id==id){
            printf("Product found!\n");
            printf("%-10s %-10s %-10s %-10s\n", "Product", "ID", "Price", "Quantity");
            printf("%-10s %-10d %-10.2f %-10d\n", p[i].name, p[i].id, p[i].price, p[i].quantity);
            printf("\n");
            return;
        }
    }
    printf("Product not found!\n");
    printf("\n");
}

//function to update product in inventory
void updateProduct(Product p[], int n){
    int id;
    printf("Enter product ID: ");
    scanf("%d", &id);
    for(int i=0; i<n; i++){
        if(p[i].id==id){
            printf("Enter new product name: ");
            scanf("%s", p[i].name);
            printf("Enter new product ID: ");
            scanf("%d", &p[i].id);
            printf("Enter new product price: ");
            scanf("%f", &p[i].price);
            printf("Enter new product quantity: ");
            scanf("%d", &p[i].quantity);
            printf("Product updated!\n");
            printf("\n");
            return;
        }
    }
    printf("Product not found!\n");
    printf("\n");
}

//function to delete product from inventory
void deleteProduct(Product p[], int *n){
    int id;
    printf("Enter product ID: ");
    scanf("%d", &id);
    for(int i=0; i<*n; i++){
        if(p[i].id==id){
            for(int j=i; j<*n-1; j++){
                p[j] = p[j+1];
            }
            (*n)--;
            printf("Product deleted!\n");
            printf("\n");
            return;
        }
    }
    printf("Product not found!\n");
    printf("\n");
}

int main(){
    Product inventory[100];
    int numProducts = 0;
    int choice;

    printf("==============================\n");
    printf("Product Inventory System\n");
    printf("==============================\n");

    do{
        printf("1. Display inventory\n");
        printf("2. Add product\n");
        printf("3. Search for product\n");
        printf("4. Update product\n");
        printf("5. Delete product\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                displayInventory(inventory, numProducts);
                break;
            case 2:
                addProduct(inventory, &numProducts);
                break;
            case 3:
                searchProduct(inventory, numProducts);
                break;
            case 4:
                updateProduct(inventory, numProducts);
                break;
            case 5:
                deleteProduct(inventory, &numProducts);
                break;
            case 6:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice! Try again.\n");
                break;
        }

    }while(choice!=6);

    return 0;
}
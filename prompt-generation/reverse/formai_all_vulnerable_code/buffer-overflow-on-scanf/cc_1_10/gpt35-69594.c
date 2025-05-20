//FormAI DATASET v1.0 Category: Product Inventory System ; Style: protected
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_SIZE 100

//Structure to represent the inventory
typedef struct{
    char name[20];
    int id;
    int quantity;
    float price;
}product;

//Function prototypes
void addProduct(product[] , int*);
void displayInventory(product[] , int);
void searchProduct(product[] , int);
void updateProduct(product[] , int);
void deleteProduct(product[] , int*);

int main(){
    product inv[MAX_SIZE];
    int size = 0;
    int choice;

    while(1){
        printf("\nWelcome to the Product Inventory System\n");
        printf("Please choose an option:\n");
        printf("1) Add a product\n");
        printf("2) Display the inventory\n");
        printf("3) Search for a product\n");
        printf("4) Update a product\n");
        printf("5) Delete a product\n");
        printf("6) Exit\n");

        scanf("%d", &choice);

        switch(choice){
            case 1:
                //Function call to add a product
                addProduct(inv, &size);
                break;

            case 2:
                //Function call to display the inventory
                displayInventory(inv, size);
                break;

            case 3:
                //Function call to search for a product
                searchProduct(inv, size);
                break;

            case 4:
                //Function call to update a product
                updateProduct(inv, size);
                break;

            case 5:
                //Function call to delete a product
                deleteProduct(inv, &size);
                break;

            case 6:
                //Exit the program
                printf("Goodbye!\n");
                exit(0);

            default:
                printf("Invalid choice\n");
                break;
        }
    }

    return 0;
}

//Function to add a product to the inventory
void addProduct(product inv[], int *size){
    if(*size == MAX_SIZE){
        printf("Inventory is full. Cannot add more products.\n");
        return;
    }

    product newProduct;
    printf("Enter name of the product: ");
    scanf("%s", newProduct.name);
    printf("Enter the unique id for the product: ");
    scanf("%d", &newProduct.id);
    printf("Enter the quantity of the product: ");
    scanf("%d", &newProduct.quantity);
    printf("Enter the price of the product: ");
    scanf("%f", &newProduct.price);

    inv[*size] = newProduct;
    printf("Product added successfully!\n");
    (*size)++;
}

//Function to display the inventory
void displayInventory(product inv[], int size){
    if(size == 0){
        printf("Inventory is empty.\n");
        return;
    }

    printf("\nProducts in the inventory:\n");
    printf("Name\tID\tQuantity\tPrice\n");
    for(int i=0; i<size; i++){
        product p = inv[i];
        printf("%s\t%d\t%d\t\t%.2f\n", p.name, p.id, p.quantity, p.price);
    }
}

//Function to search for a product by id
void searchProduct(product inv[], int size){
    if(size == 0){
        printf("Inventory is empty. Cannot search for a product.\n");
        return;
    }

    int id;
    printf("Enter the id of the product you want to search for: ");
    scanf("%d", &id);

    for(int i=0; i<size; i++){
        if(inv[i].id == id){
            printf("Product found!\n");
            printf("Name: %s\nID: %d\nQuantity: %d\nPrice: %.2f\n", inv[i].name, inv[i].id, inv[i].quantity, inv[i].price);
            return;
        }
    }

    printf("Product not found in inventory.\n");
}

//Function to update a product in the inventory
void updateProduct(product inv[], int size){
    if(size == 0){
        printf("Inventory is empty. Cannot update a product.\n");
        return;
    }

    int id;
    printf("Enter the id of the product you want to update: ");
    scanf("%d", &id);

    for(int i=0; i<size; i++){
        if(inv[i].id == id){
            printf("Product found!\n");
            printf("Enter new name of the product: ");
            scanf("%s", inv[i].name);
            printf("Enter new id of the product: ");
            scanf("%d", &inv[i].id);
            printf("Enter new quantity of the product: ");
            scanf("%d", &inv[i].quantity);
            printf("Enter new price of the product: ");
            scanf("%f", &inv[i].price);
            printf("Product updated successfully!\n");
            return;
        }
    }

    printf("Product not found in inventory.\n");
}

//Function to delete a product from the inventory
void deleteProduct(product inv[], int *size){
    if(*size == 0){
        printf("Inventory is empty. Cannot delete a product.\n");
        return;
    }

    int id;
    printf("Enter the id of the product you want to delete: ");
    scanf("%d", &id);

    for(int i=0; i<*size; i++){
        if(inv[i].id == id){
            printf("Product found!\n");
            for(int j=i; j<*size-1; j++){
                inv[j] = inv[j+1];
            }
            (*size)--;
            printf("Product deleted successfully!\n");
            return;
        }
    }

    printf("Product not found in inventory.\n");
}
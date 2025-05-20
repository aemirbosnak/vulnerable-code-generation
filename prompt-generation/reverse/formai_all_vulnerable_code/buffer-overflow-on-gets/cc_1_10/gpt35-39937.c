//FormAI DATASET v1.0 Category: Product Inventory System ; Style: interoperable
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct product{
    int id;
    char name[50];
    float price;
    int quantity;
    struct product *next;
}Product;

Product *head = NULL;

void addProduct(){
    Product *newProduct = (Product*)malloc(sizeof(Product));
    printf("Enter product id: ");
    scanf("%d", &newProduct->id);
    printf("Enter product name: ");
    fflush(stdin);
    gets(newProduct->name);
    printf("Enter product price: ");
    scanf("%f", &newProduct->price);
    printf("Enter product quantity: ");
    scanf("%d", &newProduct->quantity);
    newProduct->next = head;
    head = newProduct;
    printf("Product added successfully!\n");
}

void searchProduct(){
    if(head == NULL){
        printf("No products found!\n");
        return;
    }
    int id;
    printf("Enter product id to search: ");
    scanf("%d", &id);
    Product *temp = head;
    while(temp != NULL){
        if(temp->id == id){
            printf("Product found! Details are:\n");
            printf("ID: %d\n", temp->id);
            printf("Name: %s\n", temp->name);
            printf("Price: %.2f\n", temp->price);
            printf("Quantity: %d\n", temp->quantity);
            return;
        }
        temp = temp->next;
    }
    printf("Product not found!\n");
}

void updateProduct(){
    if(head == NULL){
        printf("No products found!\n");
        return;
    }
    int id;
    printf("Enter product id to update: ");
    scanf("%d", &id);
    Product *temp = head;
    while(temp != NULL){
        if(temp->id == id){
            printf("Product found! Enter new details:\n");
            printf("Enter product name: ");
            fflush(stdin);
            gets(temp->name);
            printf("Enter product price: ");
            scanf("%f", &temp->price);
            printf("Enter product quantity: ");
            scanf("%d", &temp->quantity);
            printf("Product updated successfully!\n");
            return;
        }
        temp = temp->next;
    }
    printf("Product not found!\n");
}

void deleteProduct(){
    if(head == NULL){
        printf("No products found!\n");
        return;
    }
    int id;
    printf("Enter product id to delete: ");
    scanf("%d", &id);
    Product *temp = head, *prev = NULL;
    while(temp != NULL){
        if(temp->id == id){
            if(prev == NULL){
                head = temp->next;
            }
            else{
                prev->next = temp->next;
            }
            free(temp);
            printf("Product deleted successfully!\n");
            return;
        }
        prev = temp;
        temp = temp->next;
    }
    printf("Product not found!\n");
}

void displayProducts(){
    if(head == NULL){
        printf("No products found!\n");
        return;
    }
    printf("List of products:\n");
    printf("ID\t\tName\t\tPrice\t\tQuantity\n");
    Product *temp = head;
    while(temp != NULL){
        printf("%d\t\t%s\t\t%.2f\t\t%d\n", temp->id, temp->name, temp->price, temp->quantity);
        temp = temp->next;
    }
}

int main(){
    int choice = 0;
    while(choice != 6){
        printf("\n***********************\n");
        printf("PRODUCT INVENTORY SYSTEM");
        printf("\n***********************\n");
        printf("1. Add Product\n");
        printf("2. Search Product\n");
        printf("3. Update Product\n");
        printf("4. Delete Product\n");
        printf("5. Display Products\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                addProduct();
                break;
            case 2:
                searchProduct();
                break;
            case 3:
                updateProduct();
                break;
            case 4:
                deleteProduct();
                break;
            case 5:
                displayProducts();
                break;
            case 6:
                printf("Exiting..");
                break;
            default:
                printf("Invalid choice! Please enter a valid choice.\n");
        }
    }
    return 0;
}
//FormAI DATASET v1.0 Category: Product Inventory System ; Style: Claude Shannon
/*
Product Inventory System
By: Claude Shannon

This program manages an inventory of products for a small business. Products are stored in a doubly linked list data structure and can be added, removed, searched, sorted and displayed.

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Product Node Structure
typedef struct productNode{
    int productID;
    char productName[50];
    float productPrice;
    int productQuantity;
    struct productNode *next;
    struct productNode *prev;
} PRODUCTNODE;

//Global Head and Tail Pointers
PRODUCTNODE *head = NULL;
PRODUCTNODE *tail = NULL;

//Product ID Counter
int productIDCounter = 1;

//Insert Product at the End of the List
void insertProduct(char *name, float price, int quantity) {
    PRODUCTNODE *newProduct = (PRODUCTNODE*) malloc(sizeof(PRODUCTNODE));
    newProduct->productID = productIDCounter;
    strcpy(newProduct->productName, name);
    newProduct->productPrice = price;
    newProduct->productQuantity = quantity;
    newProduct->prev = tail;
    newProduct->next = NULL;
    if(head == NULL) {
        head = newProduct;
        tail = newProduct;
    }
    else{
        tail->next = newProduct;
        tail = newProduct;
    }
    productIDCounter++;
}

//Delete Product by ID
void deleteProduct(int id) {
    PRODUCTNODE *temp = head;
    while(temp != NULL){
        if(temp->productID == id){
            if(temp == head){
                head = temp->next;
                temp->next->prev = NULL;
            }
            else if(temp == tail){
                tail = temp->prev;
                temp->prev->next = NULL;
            }
            else{
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;
            }
            free(temp);
            printf("Product Deleted!\n");
            return;
        }
        temp = temp->next;
    }
    printf("Product Not Found!\n");
}

//Search Product by Name
void searchProduct(char *name) {
    PRODUCTNODE *temp = head;
    int foundFlag = 0;
    while(temp != NULL){
        if(strcmp(temp->productName, name) == 0){
            printf("Product ID: %d\n", temp->productID);
            printf("Product Name: %s\n", temp->productName);
            printf("Product Price: %.2f\n", temp->productPrice);
            printf("Product Quantity: %d\n", temp->productQuantity);
            printf("---------------------\n");
            foundFlag = 1;
        }
        temp = temp->next;
    }
    if(foundFlag == 0){
        printf("Product Not Found!\n");
    }
}

//Sort Products by Price (Bubble Sort)
void sortProducts() {
    PRODUCTNODE *temp = head;
    int totalProducts = 0;
    while(temp != NULL){
        totalProducts++;
        temp = temp->next;
    }
    int i, j;
    float tempPrice;
    int tempID, tempQuantity;
    char tempName[50];
    for(i=0; i<totalProducts-1; i++){
        temp = head;
        for(j=0; j<totalProducts-i-1; j++){
            if(temp->productPrice > temp->next->productPrice){
                tempID = temp->productID;
                strcpy(tempName, temp->productName);
                tempPrice = temp->productPrice;
                tempQuantity = temp->productQuantity;
                temp->productID = temp->next->productID;
                strcpy(temp->productName, temp->next->productName);
                temp->productPrice = temp->next->productPrice;
                temp->productQuantity = temp->next->productQuantity;
                temp->next->productID = tempID;
                strcpy(temp->next->productName, tempName);
                temp->next->productPrice = tempPrice;
                temp->next->productQuantity = tempQuantity;
            }
            temp = temp->next;
        }
    }
    printf("Products Sorted!\n");
}

//Display All Products
void displayProducts() {
    PRODUCTNODE *temp = head;
    if(temp == NULL){
        printf("Inventory is Empty!\n");
        return;
    }
    while(temp != NULL){
        printf("Product ID: %d\n", temp->productID);
        printf("Product Name: %s\n", temp->productName);
        printf("Product Price: %.2f\n", temp->productPrice);
        printf("Product Quantity: %d\n", temp->productQuantity);
        printf("---------------------\n");
        temp = temp->next;
    }
}

//Main Function
int main() {
    int choice;
    char name[50];
    float price;
    int quantity;
    int id;
    printf("Welcome to the Product Inventory System!\n");
    while(1){
        printf("\n\n");
        printf("1 - Add a new product\n");
        printf("2 - Delete a product\n");
        printf("3 - Search for a product\n");
        printf("4 - Sort products by price\n");
        printf("5 - Display all products\n");
        printf("6 - Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("Enter name of product: ");
                scanf("%s", name);
                printf("Enter price of product: ");
                scanf("%f", &price);
                printf("Enter quantity of product: ");
                scanf("%d", &quantity);
                insertProduct(name, price, quantity);
                printf("Product Added!\n");
                break;
            case 2:
                printf("Enter ID of product to delete: ");
                scanf("%d", &id);
                deleteProduct(id);
                break;
            case 3:
                printf("Enter name of product to search: ");
                scanf("%s", name);
                searchProduct(name);
                break;
            case 4:
                sortProducts();
                break;
            case 5:
                displayProducts();
                break;
            case 6:
                printf("Thank you for using the Product Inventory System!\n");
                exit(0);
                break;
            default:
                printf("Invalid Choice!\n");
        }
    }
    return 0;
}
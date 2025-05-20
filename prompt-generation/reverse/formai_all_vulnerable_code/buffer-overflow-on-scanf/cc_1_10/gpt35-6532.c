//FormAI DATASET v1.0 Category: Product Inventory System ; Style: real-life
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

// Declaring a struct to hold the product details
struct Product{
    int productId;
    char productName[30];
    char productDescription[200];
    float productPrice;
    int productQuantity;
};

// Function to add a new product to the inventory
void addProduct(struct Product *inventory, int *count){
    printf("\nEnter new product details:\n");
    printf("Product ID: ");
    scanf("%d", &inventory[*count].productId);
    printf("Product Name: ");
    scanf("%s", inventory[*count].productName);
    printf("Product Description: ");
    scanf("%s", inventory[*count].productDescription);
    printf("Product Price: ");
    scanf("%f", &inventory[*count].productPrice);
    printf("Product Quantity: ");
    scanf("%d", &inventory[*count].productQuantity);
    *count += 1;
    printf("\nProduct added successfully!\n");
}

// Function to display all the products in the inventory
void displayInventory(struct Product *inventory, int count){
    if(count == 0){
        printf("\nInventory is empty!\n");
        return;
    }
    printf("\nProduct Inventory:\n\n");
    printf("ID\tName\t\t\tDescription\t\t\tPrice\tQuantity\n");
    for(int i=0; i<count; i++){
        printf("%d\t%-20s%-40s%.2f\t%d\n", inventory[i].productId, inventory[i].productName, inventory[i].productDescription, inventory[i].productPrice, inventory[i].productQuantity);
    }
}

// Function to search for a product by ID
void searchProduct(struct Product *inventory, int count){
    int prodId, found=0;
    printf("\nEnter the product ID to search: ");
    scanf("%d", &prodId);
    for(int i=0; i<count; i++){
        if(inventory[i].productId == prodId){
            printf("\nProduct Found!\n");
            printf("ID\tName\t\t\tDescription\t\t\tPrice\tQuantity\n");
            printf("%d\t%-20s%-40s%.2f\t%d\n", inventory[i].productId, inventory[i].productName, inventory[i].productDescription, inventory[i].productPrice, inventory[i].productQuantity);
            found = 1;
            break;
        }
    }
    if(!found){
        printf("\nProduct not found!\n");
    }
}

// Function to update the details of an existing product
void updateProductDetails(struct Product *inventory, int count){
    int prodId, found=0;
    printf("\nEnter the product ID to update: ");
    scanf("%d", &prodId);
    for(int i=0; i<count; i++){
        if(inventory[i].productId == prodId){
            printf("\nEnter updated product details:\n");
            printf("Name: ");
            scanf("%s", inventory[i].productName);
            printf("Description: ");
            scanf("%s", inventory[i].productDescription);
            printf("Price: ");
            scanf("%f", &inventory[i].productPrice);
            printf("Quantity: ");
            scanf("%d", &inventory[i].productQuantity);
            printf("\nProduct details updated successfully!\n");
            found = 1;
            break;
        }
    }
    if(!found){
        printf("\nProduct not found!\n");
    }
}

int main(){
    struct Product inventory[100];
    int count = 0, choice;
    while(1){
        printf("\n---------------Product Inventory System---------------\n");
        printf("1. Add new product\n");
        printf("2. Display all products\n");
        printf("3. Search for a product\n");
        printf("4. Update product details\n");
        printf("5. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1: addProduct(&inventory[0], &count);
                    break;
            case 2: displayInventory(&inventory[0], count);
                    break;
            case 3: searchProduct(&inventory[0], count);
                    break;
            case 4: updateProductDetails(&inventory[0], count);
                    break;
            case 5: exit(0);
            default: printf("\nInvalid choice!\n");
        }
    }
    return 0;
}
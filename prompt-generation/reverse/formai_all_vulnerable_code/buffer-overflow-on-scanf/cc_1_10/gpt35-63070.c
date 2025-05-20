//FormAI DATASET v1.0 Category: Product Inventory System ; Style: paranoid
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_PRODUCTS 100

struct product{
    char name[50];
    int quantity;
    float price;
};

void addProduct(struct product[], int*);
void updateQuantity(struct product[], int);
void displayInventory(struct product[], int);

int main(){
    struct product inventory[MAX_PRODUCTS];
    int numProducts = 0;
    char password[10];
    printf("Welcome to Paranoid Product Inventory System\n");
    printf("Please enter password: ");
    scanf("%s", password);
    if(strcmp(password, "paranoia")==0){
        printf("Access granted\n");
    }else{
        printf("Access denied. Terminating program\n");
        return 0;
    }
    int choice;
    do{
        printf("\n1.Add new product\n2.Update quantity\n3.Display inventory\n4.Exit\nEnter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1: addProduct(inventory, &numProducts); break;
            case 2: updateQuantity(inventory, numProducts); break;
            case 3: displayInventory(inventory, numProducts); break;
            case 4: printf("Exiting Paranoid Product Inventory System\n"); break;
            default: printf("Invalid choice. Please try again\n"); 
        }
    }while(choice!=4);
    return 0;
}

void addProduct(struct product inventory[], int *pNumProducts){
    if(*pNumProducts>=MAX_PRODUCTS){
        printf("Maximum capacity reached. Cannot add more products\n");
        return;
    }
    printf("Enter product name: ");
    scanf("%s", inventory[*pNumProducts].name);
    printf("Enter quantity: ");
    scanf("%d", &inventory[*pNumProducts].quantity);
    printf("Enter price: ");
    scanf("%f", &inventory[*pNumProducts].price);
    printf("Product added successfully\n");
    (*pNumProducts)++;
}

void updateQuantity(struct product inventory[], int numProducts){
    char productName[50];
    printf("Enter product name: ");
    scanf("%s", productName);
    for(int i=0;i<numProducts;i++){
        if(strcmp(productName, inventory[i].name)==0){
            printf("Enter new quantity: ");
            scanf("%d", &inventory[i].quantity);
            printf("Quantity updated successfully\n");
            return;
        }
    }
    printf("Product not found in inventory\n");
}

void displayInventory(struct product inventory[], int numProducts){
    if(numProducts==0){
        printf("Inventory is empty. Add new products\n");
        return;
    }
    printf("Current inventory: \n");
    for(int i=0;i<numProducts;i++){
        printf("%s - Quantity: %d - Price: %.2f\n", inventory[i].name, inventory[i].quantity, inventory[i].price);
    }
}
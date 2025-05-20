//FormAI DATASET v1.0 Category: Product Inventory System ; Style: Sherlock Holmes
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//Structure for Products
struct product{
    char name[50];
    int quantity;
    float price;
};

//Function to display menu options
void displayMenu(){
    printf("\n\nWelcome to Sherlock Holmes Product Inventory System!");
    printf("\n\n\t1. Add Product");
    printf("\n\t2. Delete Product");
    printf("\n\t3. Display Inventory");
    printf("\n\t4. Exit");
    printf("\nEnter your choice: ");
}

//Function to add Product
void addProduct(struct product inventory[], int *count){
    printf("\nEnter Product Name: ");
    scanf("%s", inventory[*count].name);
    printf("\nEnter Quantity: ");
    scanf("%d", &inventory[*count].quantity);
    printf("\nEnter Price: ");
    scanf("%f", &inventory[*count].price);
    (*count)++;
    printf("\nProduct added successfully!");
}

//Function to delete Product
void deleteProduct(struct product inventory[], int *count){
    char productName[50];
    printf("\nEnter Product Name to delete: ");
    scanf("%s", productName);
    int index = -1;
    for(int i=0; i<*count; i++){
        if(strcmp(inventory[i].name, productName)==0){
            index = i;
            break;
        }
    }
    if(index == -1){
        printf("\nProduct not found in inventory!");
    }
    else{
        for(int i=index; i<*count-1; i++){
            inventory[i] = inventory[i+1];
        }
        (*count)--;
        printf("\nProduct deleted successfully!");
    }
}

//Function to display Inventory
void displayInventory(struct product inventory[], int count){
    if(count == 0){
        printf("\nInventory is empty!");
    }
    else{
        printf("\n\t%-20s %-10s %-10s", "Product Name", "Quantity", "Price");
        for(int i=0; i<count; i++){
            printf("\n\t%-20s %-10d %-10.2f", inventory[i].name, inventory[i].quantity, inventory[i].price);
        }
    }
}

int main(){

    struct product inventory[100];
    int count = 0;

    while(1){
        displayMenu();
        int choice;
        scanf("%d", &choice);

        switch(choice){
            case 1:
                addProduct(inventory, &count);
                break;
            case 2:
                deleteProduct(inventory, &count);
                break;
            case 3:
                displayInventory(inventory, count);
                break;
            case 4:
                printf("\nThank you for using Sherlock Holmes Product Inventory System!");
                exit(0);
            default:
                printf("\nInvalid Choice! Please try again.");
        }
    }

    return 0;
}
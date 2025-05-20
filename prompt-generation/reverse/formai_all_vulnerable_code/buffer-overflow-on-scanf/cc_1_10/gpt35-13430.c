//FormAI DATASET v1.0 Category: Product Inventory System ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct product { 
   char name[50];
   int id;
   float price;
   int quantity;
}products[100];

int count = 0;

void addProduct(){
    struct product p;
    printf("Enter product details:\n");
    printf("Name: ");
    scanf("%s", &p.name);
    printf("ID: ");
    scanf("%d", &p.id);
    printf("Price: ");
    scanf("%f", &p.price);
    printf("Quantity: ");
    scanf("%d", &p.quantity);
    products[count++] = p;
    printf("\nProduct added to inventory successfully.\n\n");
}

void displayInventory(){
    printf("Product Inventory:\n\n");
    printf("Name\t\tID\tPrice\tQuantity\n");
    for(int i=0;i<count;i++){
        printf("%s\t%d\t%.2f\t%d\n", products[i].name, products[i].id, products[i].price, products[i].quantity);
    }
    printf("\n");
}

void searchProduct(){
    char pname[50];
    printf("Enter the product name: ");
    scanf("%s", &pname);
    int found = 0;
    for(int i=0;i<count;i++){
        if(strcmp(products[i].name, pname) == 0){
            found = 1;
            printf("Product details:\n");
            printf("Name: %s\nID: %d\nPrice: %.2f\nQuantity: %d\n", products[i].name, products[i].id, products[i].price, products[i].quantity);
            break;
        }
    }
    if(found == 0){
        printf("Product not found in inventory.\n\n");
    }
}

void removeProduct(){
    int pid, index;
    printf("Enter the product ID to be removed: ");
    scanf("%d", &pid);
    int found = 0;
    for(int i=0;i<count;i++){
        if(products[i].id == pid){
            found = 1;
            index = i;
            break;
        }
    }
    if(found == 0){
        printf("Product with ID %d not found in inventory.\n\n", pid);
    } else {
        for(int i=index;i<count-1;i++){
            products[i] = products[i+1];
        }
        count--;
        printf("Product with ID %d removed from inventory successfully.\n\n", pid);
    }
}

int main(){
    int choice;
    printf("Welcome to the Product Inventory System\n");
    while(1){
        printf("Choose an option:\n");
        printf("1. Add product\n");
        printf("2. Display inventory\n");
        printf("3. Search product\n");
        printf("4. Remove product\n");
        printf("5. Exit\n");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                addProduct();
                break;
            case 2:
                displayInventory();
                break;
            case 3:
                searchProduct();
                break;
            case 4:
                removeProduct();
                break;
            case 5:
                printf("Thank you for using the Product Inventory System.\n");
                exit(0);
            default:
                printf("Invalid choice. Please choose a valid option.\n\n");
                break;
        }
    }
    return 0;
}
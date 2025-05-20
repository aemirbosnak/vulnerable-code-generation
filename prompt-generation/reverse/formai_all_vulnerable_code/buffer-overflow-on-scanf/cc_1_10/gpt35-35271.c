//FormAI DATASET v1.0 Category: Product Inventory System ; Style: real-life
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//defining a struct to hold information about each product
struct product{
    int id;
    char name[50];
    int quantity;
    float price;
};

//function declarations
void addProduct(struct product[], int);
void displayInventory(struct product[], int);
void searchProduct(struct product[], int);
void updateProduct(struct product[], int);

int main(){
    int choice, numProducts=0;
    struct product inventory[100];

    while(1){
        //displaying the menu
        printf("\nWelcome to the Product Inventory System\n");
        printf("1. Add Product \n");
        printf("2. Display Inventory\n");
        printf("3. Search Product\n");
        printf("4. Update Product\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                addProduct(inventory, numProducts);
                numProducts++;
                break;
            case 2:
                displayInventory(inventory, numProducts);
                break;
            case 3:
                searchProduct(inventory, numProducts);
                break;
            case 4:
                updateProduct(inventory, numProducts);
                break;
            case 5:
                printf("Exiting Program...");
                exit(0);
            default:
                printf("Invalid Choice! Try again...\n");
                break;
        }
    }
    return 0;
}

void addProduct(struct product inventory[], int numProducts){
    printf("\nEnter details of the new product...\n");
    inventory[numProducts].id = numProducts + 1;
    printf("Name: ");
    scanf("%s", inventory[numProducts].name);
    printf("Quantity: ");
    scanf("%d", &inventory[numProducts].quantity);
    printf("Price: ");
    scanf("%f", &inventory[numProducts].price);
    printf("\nProduct added successfully!\n");
}

void displayInventory(struct product inventory[], int numProducts){
    if(numProducts == 0){
        printf("No products in inventory. Add products first!\n");
        return;
    }
    printf("\nInventory:\n");
    printf("ID\tName\tQuantity\tPrice\n");
    for(int i=0; i<numProducts; i++){
        printf("%d\t%s\t%d\t\t%.2f\n", inventory[i].id, inventory[i].name, inventory[i].quantity, inventory[i].price);
    }
}

void searchProduct(struct product inventory[], int numProducts){
    if(numProducts == 0){
        printf("No products in inventory. Add products first!\n");
        return;
    }
    char pname[50];
    printf("\nEnter name of product to search: ");
    scanf("%s", pname);
    for(int i=0; i<numProducts; i++){
        if(strcmp(inventory[i].name, pname) == 0){
            printf("\nProduct found!\n");
            printf("ID\tName\tQuantity\tPrice\n");
            printf("%d\t%s\t%d\t\t%.2f\n", inventory[i].id, inventory[i].name, inventory[i].quantity, inventory[i].price);
            return;
        }
    }
    printf("\nProduct not found!\n");
}

void updateProduct(struct product inventory[], int numProducts){
    if(numProducts == 0){
        printf("No products in inventory. Add products first!\n");
        return;
    }
    int pid, choice;
    printf("\nEnter ID of product to update: ");
    scanf("%d", &pid);
    for(int i=0; i<numProducts; i++){
        if(inventory[i].id == pid){
            printf("\nProduct found!\n");
            printf("Do you want to update:\n");
            printf("1. Name\n");
            printf("2. Quantity\n");
            printf("3. Price\n");
            printf("Enter your choice: ");
            scanf("%d", &choice);
            switch(choice){
                case 1:
                    printf("Enter new name: ");
                    scanf("%s", inventory[i].name);
                    printf("Product updated successfully!\n");
                    break;
                case 2:
                    printf("Enter new quantity: ");
                    scanf("%d", &inventory[i].quantity);
                    printf("Product updated successfully!\n");
                    break;
                case 3:
                    printf("Enter new price: ");
                    scanf("%f", &inventory[i].price);
                    printf("Product updated successfully!\n");
                    break;
                default:
                    printf("Invalid Choice! Try again...\n");
                    break;
            }
        }
    }
    printf("\nProduct not found!\n");
}
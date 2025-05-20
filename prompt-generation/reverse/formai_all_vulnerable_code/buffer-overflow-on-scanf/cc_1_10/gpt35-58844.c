//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: creative
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_SIZE 1000

typedef struct {
    int id;
    char name[20];
    int quantity;
} Product;

Product inventory[MAX_SIZE];

int numProducts = 0;

int AddProduct(char name[], int quantity){
    if(numProducts >= MAX_SIZE) return 0;

    inventory[numProducts].id = numProducts + 1;
    strcpy(inventory[numProducts].name, name);
    inventory[numProducts].quantity = quantity;

    numProducts++;

    return 1;
}

int RemoveProduct(int id){
    int i, found = 0;

    for(i = 0; i < numProducts; i++){
        if(inventory[i].id == id){
            found = 1;
            break;
        }
    }

    if(found == 0) return 0;

     for(i = id-1; i < numProducts-1; i++){
        inventory[i] = inventory[i+1];
    }

    numProducts--;

    return 1;
}

void PrintInventory(){
    int i;

    printf("ID\tName\tQuantity\n");

    for(i = 0; i < numProducts; i++){
        printf("%d\t%s\t%d\n", inventory[i].id, inventory[i].name, inventory[i].quantity);
    }
}

void MainMenu(){
    printf("\nWarehouse Management System\n");
    printf("1. Add Product\n");
    printf("2. Remove Product\n");
    printf("3. Print Inventory\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
}

int main(){
    int choice, id;
    char name[20];
    int quantity;

    do{
        MainMenu();

        scanf("%d", &choice);

        switch(choice){
            case 1:
                printf("\nEnter product name: ");
                scanf("%s", name);
                printf("Enter product quantity: ");
                scanf("%d", &quantity);

                if(AddProduct(name, quantity) == 1){
                    printf("Product added successfully!\n");
                }else{
                    printf("Error: Unable to add product!\n");
                }

                break;
            case 2:
                printf("\nEnter product ID to remove: ");
                scanf("%d", &id);

                if(RemoveProduct(id) == 1){
                    printf("Product removed successfully!\n");
                }else{
                    printf("Error: Unable to remove product!\n");
                }

                break;
            case 3:
                PrintInventory();
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }while(choice != 4);

    return 0;
}
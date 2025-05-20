//FormAI DATASET v1.0 Category: Product Inventory System ; Style: thoughtful
#include<stdio.h>
#include<string.h>

//Defining the structure for product details
struct product {
    char name[50];
    int id;
    float price;
    int stock;
};

//Defining a function to add a new product to the inventory
void addProduct(struct product *inventory, int *size) {
    *size=*size+1;
    int n=*size-1;
    printf("Enter the name of the product: ");
    scanf("%s",inventory[n].name);
    printf("Enter the product ID: ");
    scanf("%d",&inventory[n].id);
    printf("Enter the price of the product: ");
    scanf("%f",&inventory[n].price);
    printf("Enter the stock of the product: ");
    scanf("%d",&inventory[n].stock);
}

//Defining a function to display all products in the inventory
void displayInventory(struct product *inventory, int size) {
    int i;
    printf("\n******************INVENTORY******************");
    printf("\nName\t\tID\t\tPrice\t\tStock\n");
    for(i=0;i<size;i++) {
        printf("%s\t\t%d\t\t%.2f\t\t%d\n",inventory[i].name,inventory[i].id,inventory[i].price,inventory[i].stock);
    }
    printf("*********************************************\n");
}

//Defining a function to search for a product in the inventory
void searchProduct(struct product *inventory, int size, int id) {
    int i=0,flag=0;
    while(i<size) {
        if(inventory[i].id==id) {
            printf("\n******************PRODUCT FOUND******************");
            printf("\nName\t\tID\t\tPrice\t\tStock\n");
            printf("%s\t\t%d\t\t%.2f\t\t%d\n",inventory[i].name,inventory[i].id,inventory[i].price,inventory[i].stock);
            printf("*********************************************\n");
            flag=1;
            break;
        }
        i++;
    }
    if(flag==0) {
        printf("\nNo product found with the given ID.\n");
    }
}

//Defining a function to update the stock of a product in the inventory
void updateStock(struct product *inventory, int size, int id, int stock) {
    int i=0,flag=0;
    while(i<size) {
        if(inventory[i].id==id) {
            inventory[i].stock=stock;
            printf("\nStock updated successfully!\n");
            flag=1;
            break;
        }
        i++;
    }
    if(flag==0) {
        printf("\nNo product found with the given ID.\n");
    }
}

int main() {
    struct product inventory[50]; //Maximum of 50 products allowed in the inventory
    int size=0; //Initial size of the inventory
    int choice,id,stock,pid; //Variables for user choice, product ID, stock and product ID for searching/updating
    while(1) {
        printf("\n\n******************PRODUCT INVENTORY MANAGEMENT SYSTEM******************");
        printf("\n1. Add a new product to the inventory");
        printf("\n2. Display all products in the inventory");
        printf("\n3. Search for a product in the inventory");
        printf("\n4. Update the stock of a product in the inventory");
        printf("\n5. Exit");
        printf("\nEnter your choice (1-5): ");
        scanf("%d",&choice);
        switch(choice) {
            case 1: //Add a new product
                addProduct(inventory,&size);
                break;
            case 2: //Display all products
                displayInventory(inventory,size);
                break;
            case 3: //Search for a product
                printf("\nEnter the ID of the product you want to search: ");
                scanf("%d",&id);
                searchProduct(inventory,size,id);
                break;
            case 4: //Update the stock of a product
                printf("\nEnter the ID of the product you want to update: ");
                scanf("%d",&pid);
                printf("Enter the new stock of the product: ");
                scanf("%d",&stock);
                updateStock(inventory,size,pid,stock);
                break;
            case 5: //Exit
                printf("\nThank you for using the Product Inventory Management System!\n");
                return 0;
                break;
            default: //Invalid choice
                printf("\nInvalid choice. Please enter a valid choice.\n");
        }
    }
    return 0;
}
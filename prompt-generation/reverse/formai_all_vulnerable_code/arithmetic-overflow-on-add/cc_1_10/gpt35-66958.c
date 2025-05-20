//FormAI DATASET v1.0 Category: Product Inventory System ; Style: synchronous
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_PRODUCTS 10

struct product{
    char name[100];
    int quantity;
    float price;
};

struct inventory{
    struct product items[MAX_PRODUCTS];
    int count;
};

void addProduct(struct inventory *inv);
void removeProduct(struct inventory *inv);
void updateProduct(struct inventory *inv);
void viewInventory(struct inventory inv);

int main(){
    struct inventory inv;
    inv.count = 0;
    int choice;

    do{
        printf("Inventory Management System\n");
        printf("----------------------------\n");
        printf("1. Add Product\n");
        printf("2. Remove Product\n");
        printf("3. Update Product\n");
        printf("4. View Inventory\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            addProduct(&inv);
            break;
        
        case 2:
            removeProduct(&inv);
            break;

        case 3:
            updateProduct(&inv);
            break;

        case 4:
            viewInventory(inv);
            break;

        case 5:
            printf("Exiting Inventory Management System...\n");
            exit(0);
            
        default:
            printf("Invalid Choice. Try again.\n");
            break;
        }

    }while(choice != 5);

    return 0;
}

void addProduct(struct inventory *inv){
    if(inv->count == MAX_PRODUCTS){
        printf("Inventory is full. Cannot add more products.\n");
        return;
    }
    else{
        printf("Enter product name: ");
        scanf("%s", inv->items[inv->count].name);
        printf("Enter product quantity: ");
        scanf("%d", &inv->items[inv->count].quantity);
        printf("Enter product price: ");
        scanf("%f", &inv->items[inv->count].price);

        inv->count++;

        printf("Product added successfully to inventory.\n");
    }
}

void removeProduct(struct inventory *inv){
    char name[100];
    int i, found = 0;

    if(inv->count == 0){
        printf("Inventory is empty. Cannot remove products.\n");
        return;
    }
    else{
        printf("Enter name of product to remove: ");
        scanf("%s", name);

        for(i=0; i<inv->count; i++){
            if(strcmp(name, inv->items[i].name) == 0){
                found = 1;
                break;
            }
        }

        if(found){
            for(; i<(inv->count)-1; i++){
                inv->items[i] = inv->items[i+1];
            }
            inv->count--;

            printf("Product removed successfully from inventory.\n");
        }
        else{
            printf("Product not found in inventory.\n");
        }
    }
}

void updateProduct(struct inventory *inv){
    char name[100];
    int i, found = 0;

    if(inv->count == 0){
        printf("Inventory is empty. Cannot update products.\n");
        return;
    }
    else{
        printf("Enter name of product to update: ");
        scanf("%s", name);

        for(i=0; i<inv->count; i++){
            if(strcmp(name, inv->items[i].name) == 0){
                found = 1;
                break;
            }
        }

        if(found){
            printf("Enter new quantity: ");
            scanf("%d", &inv->items[i].quantity);
            printf("Enter new price: ");
            scanf("%f", &inv->items[i].price);

            printf("Product updated successfully.\n");
        }
        else{
            printf("Product not found in inventory.\n");
        }
    }
}

void viewInventory(struct inventory inv){
    if(inv.count == 0){
        printf("Inventory is empty.\n");
        return;
    }
    else{
        int i;
        printf("%-20s %-20s %-20s\n", "Product Name", "Quantity", "Price");

        for(i=0; i<inv.count; i++){
            printf("%-20s %-20d %-20.2f\n", inv.items[i].name, inv.items[i].quantity, inv.items[i].price);
        }
    }
}
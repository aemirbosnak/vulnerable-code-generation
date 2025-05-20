//FormAI DATASET v1.0 Category: Product Inventory System ; Style: light-weight
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_PRODUCTS 100

struct product{
    char name[50];
    float price;
    int quantity;
};

struct inventory{
    struct product products[MAX_PRODUCTS];
    int num_products;
};

void add_product(struct inventory *inv){
    if(inv->num_products < MAX_PRODUCTS){
        printf("Enter product name: ");
        scanf("%s", inv->products[inv->num_products].name);
        printf("Enter product price: $");
        scanf("%f", &inv->products[inv->num_products].price);
        printf("Enter product quantity: ");
        scanf("%d", &inv->products[inv->num_products].quantity);
        inv->num_products++;
        printf("Product added successfully!\n");
    }
    else{
        printf("Product inventory is full!\n");
    }
}

void remove_product(struct inventory *inv){
    char name[50];
    printf("Enter name of product to remove: ");
    scanf("%s", name);
    for(int i=0; i<inv->num_products; i++){
        if(strcmp(inv->products[i].name, name) == 0){
            for(int j=i; j<inv->num_products-1; j++){
                strcpy(inv->products[j].name, inv->products[j+1].name);
                inv->products[j].price = inv->products[j+1].price;
                inv->products[j].quantity = inv->products[j+1].quantity;
            }
            inv->num_products--;
            printf("Product removed successfully!\n");
            return;
        }
    }
    printf("Product not found.\n");
}

void search_product(struct inventory *inv){
    char name[50];
    printf("Enter name of product to search: ");
    scanf("%s", name);
    for(int i=0; i<inv->num_products; i++){
        if(strcmp(inv->products[i].name, name) == 0){
            printf("Product found!\n");
            printf("Name: %s\n", inv->products[i].name);
            printf("Price: $%.2f\n", inv->products[i].price);
            printf("Quantity: %d\n", inv->products[i].quantity);
            return;
        }
    }
    printf("Product not found.\n");
}

void print_inventory(struct inventory *inv){
    printf("Product inventory:\n");
    printf("-------------------\n");
    for(int i=0; i<inv->num_products; i++){
        printf("%d.\n", i+1);
        printf("Name: %s\n", inv->products[i].name);
        printf("Price: $%.2f\n", inv->products[i].price);
        printf("Quantity: %d\n", inv->products[i].quantity);
        printf("-------------------\n");
    }
}

int main(){
    struct inventory inv;
    inv.num_products = 0;
    int choice;
    while(1){
        printf("Product Inventory System\n");
        printf("1. Add product\n");
        printf("2. Remove product\n");
        printf("3. Search product\n");
        printf("4. Print inventory\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                add_product(&inv);
                break;
            case 2:
                remove_product(&inv);
                break;
            case 3:
                search_product(&inv);
                break;
            case 4:
                print_inventory(&inv);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}
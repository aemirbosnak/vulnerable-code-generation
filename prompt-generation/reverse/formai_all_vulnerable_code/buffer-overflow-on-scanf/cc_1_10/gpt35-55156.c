//FormAI DATASET v1.0 Category: Product Inventory System ; Style: scientific
//C Product Inventory System Example Program

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Product {
    int id;
    char name[50];
    int quantity;
    float price;
} Product;

void add_product(Product *inventory, int *size);
void remove_product(Product *inventory, int *size);
void print_inventory(Product *inventory, int size);
void print_total_value(Product *inventory, int size);

int main() {
    int option, size = 0;
    Product *inventory = (Product*) calloc(size, sizeof(Product));
    
    do {
        printf("Product Inventory System\n");
        printf("------------------------\n");
        printf("1. Add Product\n");
        printf("2. Remove Product\n");
        printf("3. Print Inventory\n");
        printf("4. Print Total Value\n");
        printf("5. Exit\n");
        printf("Enter Option: ");
        scanf("%d", &option);
        
        switch(option) {
            case 1:
                add_product(inventory, &size);
                break;
            case 2:
                remove_product(inventory, &size);
                break;
            case 3:
                print_inventory(inventory, size);
                break;
            case 4:
                print_total_value(inventory, size);
                break;
            case 5:
                printf("Exiting Program...");
                break;
            default:
                printf("Invalid Option!\n");
                break;
        }
        printf("\n");
    } while(option != 5);
    
    free(inventory);
    return 0;
}

void add_product(Product *inventory, int *size) {
    int id;
    printf("Enter Product ID: ");
    scanf("%d", &id);
    
    for(int i=0; i<*size; i++) {
        if(inventory[i].id == id) {
            printf("Product ID already exists!\n\n");
            return;
        }
    }
    
    inventory = (Product*) realloc(inventory, (*size + 1) * sizeof(Product));
    inventory[*size].id = id;
    
    printf("Enter Product Name: ");
    scanf("%s", inventory[*size].name);
    
    printf("Enter Quantity: ");
    scanf("%d", &inventory[*size].quantity);
    
    printf("Enter Price: ");
    scanf("%f", &inventory[*size].price);
    
    (*size)++;
    printf("Product Added Successfully!\n\n");
}

void remove_product(Product *inventory, int *size) {
    int id, index = -1;
    printf("Enter Product ID: ");
    scanf("%d", &id);
    
    for(int i=0; i<*size; i++) {
        if(inventory[i].id == id) {
            index = i;
            break;
        }
    }
    
    if(index == -1) {
        printf("Product ID not found!\n\n");
        return;
    }
    
    memmove(inventory + index, inventory + index + 1, (*size - index - 1) * sizeof(Product));
    (*size)--;
    inventory = (Product*) realloc(inventory, (*size) * sizeof(Product));
    
    printf("Product Removed Successfully!\n\n");
}

void print_inventory(Product *inventory, int size) {
    printf("Product Inventory:\n");
    printf("ID  Name                    Quantity  Price\n");
    printf("--------------------------------------------\n");
    for(int i=0; i<size; i++) {
        printf("%-4d%-24s%-10d%.2f\n", inventory[i].id, inventory[i].name, inventory[i].quantity, inventory[i].price);
    }
    printf("--------------------------------------------\n");
}

void print_total_value(Product *inventory, int size) {
    float total_value = 0;
    for(int i=0; i<size; i++) {
        total_value += inventory[i].quantity * inventory[i].price;
    }
    printf("Total Value of Inventory: %.2f\n\n", total_value);
}
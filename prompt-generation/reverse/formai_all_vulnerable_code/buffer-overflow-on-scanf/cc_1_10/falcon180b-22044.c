//Falcon-180B DATASET v1.0 Category: Warehouse Management System ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WAREHOUSE_SIZE 1000 // maximum number of products that can be stored in the warehouse
#define MAX_PRODUCT_NAME_SIZE 50 // maximum size of a product name
#define MAX_PRODUCT_QUANTITY 1000 // maximum number of units of a product that can be stored in the warehouse

typedef struct {
    char name[MAX_PRODUCT_NAME_SIZE];
    int quantity;
} Product;

Product warehouse[MAX_WAREHOUSE_SIZE]; // the warehouse
int num_products; // the number of products in the warehouse

// function to add a product to the warehouse
void add_product(char* name, int quantity) {
    if (num_products >= MAX_WAREHOUSE_SIZE) {
        printf("Error: warehouse is full.\n");
        return;
    }
    strcpy(warehouse[num_products].name, name);
    warehouse[num_products].quantity = quantity;
    num_products++;
}

// function to remove a product from the warehouse
void remove_product(char* name) {
    int i;
    for (i = 0; i < num_products; i++) {
        if (strcmp(warehouse[i].name, name) == 0) {
            num_products--;
            memmove(&warehouse[i], &warehouse[i+1], sizeof(Product) * (num_products - i));
            break;
        }
    }
}

// function to display the contents of the warehouse
void display_warehouse() {
    printf("Contents of the warehouse:\n");
    printf("---------------------------\n");
    int i;
    for (i = 0; i < num_products; i++) {
        printf("%-50s %d\n", warehouse[i].name, warehouse[i].quantity);
    }
}

int main() {
    int choice;
    char name[MAX_PRODUCT_NAME_SIZE];
    int quantity;

    do {
        printf("Warehouse Management System\n");
        printf("---------------------------\n");
        printf("1. Add product\n");
        printf("2. Remove product\n");
        printf("3. Display warehouse\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter product name: ");
            scanf("%s", name);
            printf("Enter quantity: ");
            scanf("%d", &quantity);
            add_product(name, quantity);
            break;
        case 2:
            printf("Enter product name: ");
            scanf("%s", name);
            remove_product(name);
            break;
        case 3:
            display_warehouse();
            break;
        case 4:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice.\n");
        }
    } while (choice!= 4);

    return 0;
}
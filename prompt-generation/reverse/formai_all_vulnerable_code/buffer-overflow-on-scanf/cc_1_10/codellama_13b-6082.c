//Code Llama-13B DATASET v1.0 Category: Product Inventory System ; Style: realistic
// inventory.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// define structure for product
struct product {
    int id;
    char name[50];
    int quantity;
    float price;
};

// function to print product details
void print_product(struct product *p) {
    printf("Product ID: %d\n", p->id);
    printf("Product Name: %s\n", p->name);
    printf("Quantity: %d\n", p->quantity);
    printf("Price: %f\n", p->price);
}

// function to add a product
void add_product(struct product *p) {
    int id;
    char name[50];
    int quantity;
    float price;

    printf("Enter Product ID: ");
    scanf("%d", &id);
    printf("Enter Product Name: ");
    scanf("%s", name);
    printf("Enter Quantity: ");
    scanf("%d", &quantity);
    printf("Enter Price: ");
    scanf("%f", &price);

    p->id = id;
    strcpy(p->name, name);
    p->quantity = quantity;
    p->price = price;
}

// function to update a product
void update_product(struct product *p) {
    int id;
    char name[50];
    int quantity;
    float price;

    printf("Enter Product ID: ");
    scanf("%d", &id);
    printf("Enter Product Name: ");
    scanf("%s", name);
    printf("Enter Quantity: ");
    scanf("%d", &quantity);
    printf("Enter Price: ");
    scanf("%f", &price);

    p->id = id;
    strcpy(p->name, name);
    p->quantity = quantity;
    p->price = price;
}

// function to delete a product
void delete_product(struct product *p) {
    int id;

    printf("Enter Product ID: ");
    scanf("%d", &id);

    p->id = 0;
    strcpy(p->name, "");
    p->quantity = 0;
    p->price = 0.0;
}

// function to search a product
void search_product(struct product *p) {
    int id;

    printf("Enter Product ID: ");
    scanf("%d", &id);

    if (p->id == id) {
        printf("Product Found!\n");
        print_product(p);
    } else {
        printf("Product Not Found!\n");
    }
}

int main() {
    struct product p;
    int choice;

    while (1) {
        printf("Enter your choice:\n");
        printf("1. Add Product\n");
        printf("2. Update Product\n");
        printf("3. Delete Product\n");
        printf("4. Search Product\n");
        printf("5. Exit\n");

        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_product(&p);
                break;
            case 2:
                update_product(&p);
                break;
            case 3:
                delete_product(&p);
                break;
            case 4:
                search_product(&p);
                break;
            case 5:
                return 0;
        }
    }

    return 0;
}
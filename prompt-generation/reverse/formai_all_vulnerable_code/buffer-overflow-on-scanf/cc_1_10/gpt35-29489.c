//FormAI DATASET v1.0 Category: Product Inventory System ; Style: Dennis Ritchie
#include <stdio.h>
#include <string.h>

#define MAX_PRODUCTS 100

struct product {
    int id;
    char name[20];
    int quantity;
    float price;
};

int numProducts = 0;
struct product products[MAX_PRODUCTS];

void addProduct() {
    if(numProducts == MAX_PRODUCTS) {
        printf("Inventory is full!\n");
        return;
    }

    struct product p;

    printf("Enter product name: ");
    scanf("%s", p.name);

    printf("Enter quantity: ");
    scanf("%d", &p.quantity);

    printf("Enter price: ");
    scanf("%f", &p.price);

    p.id = numProducts + 1;

    products[numProducts] = p;
    numProducts++;

    printf("Product added!\n");
}

void removeProduct(int id) {
    int i;

    for(i = 0; i < numProducts; i++) {
        if(products[i].id == id) {
            int j;
            for(j = i; j < numProducts - 1; j++) {
                products[j] = products[j + 1];
            }

            numProducts--;

            printf("Product removed!\n");
            return;
        }
    }

    printf("Product with ID %d not found!\n", id);
}

void updateProduct(int id) {
    int i;

    for(i = 0; i < numProducts; i++) {
        if(products[i].id == id) {
            printf("Enter product name: ");
            scanf("%s", products[i].name);

            printf("Enter quantity: ");
            scanf("%d", &products[i].quantity);

            printf("Enter price: ");
            scanf("%f", &products[i].price);

            printf("Product updated!\n");
            return;
        }
    }

    printf("Product with ID %d not found!\n", id);
}

void printProduct(struct product p) {
    printf("%d\t%s\t%d\t%.2f\n", p.id, p.name, p.quantity, p.price);
}

void listProducts() {
    int i;

    printf("ID\tName\tQuantity\tPrice\n");

    for(i = 0; i < numProducts; i++) {
        printProduct(products[i]);
    }
}

int main() {
    int option, id;

    do {
        printf("Welcome to the Product Inventory System!\n");
        printf("1. Add product\n");
        printf("2. Remove product\n");
        printf("3. Update product\n");
        printf("4. List products\n");
        printf("5. Exit\n");

        printf("Enter your option: ");
        scanf("%d", &option);

        switch(option) {
            case 1:
                addProduct();
                break;

            case 2:
                printf("Enter product ID to remove: ");
                scanf("%d", &id);
                removeProduct(id);
                break;

            case 3:
                printf("Enter product ID to update: ");
                scanf("%d", &id);
                updateProduct(id);
                break;

            case 4:
                listProducts();
                break;

            case 5:
                printf("Goodbye!\n");
                break;

            default:
                printf("Invalid option!\n");
                break;
        }
    } while(option != 5);

    return 0;
}
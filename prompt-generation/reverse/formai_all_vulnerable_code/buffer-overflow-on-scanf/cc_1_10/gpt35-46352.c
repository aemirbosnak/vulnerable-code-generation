//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>

struct product {
    int id;
    char name[50];
    int quantity;
};

void addProduct(struct product *p) {
    printf("\nEnter product ID: ");
    scanf("%d", &p->id);
    printf("Enter product name: ");
    scanf("%s", p->name);
    printf("Enter product quantity: ");
    scanf("%d", &p->quantity);
}

void showProducts(struct product *products, int count) {
    printf("\n--- Products in the warehouse ---\n");
    for(int i=0; i<count; i++) {
        printf("ID: %d | Name: %s | Quantity: %d\n", products[i].id, products[i].name, products[i].quantity);
    }
}

void searchProduct(struct product *products, int count) {
    int id;
    printf("\nEnter product ID to search: ");
    scanf("%d", &id);
    for(int i=0; i<count; i++) {
        if(products[i].id == id) {
            printf("ID: %d | Name: %s | Quantity: %d", products[i].id, products[i].name, products[i].quantity);
            return;
        }
    }
    printf("Product with ID %d not found!", id);
}

int main() {
    struct product products[100];
    int count = 0;
    int choice;
    do {
        printf("\n--- Warehouse Management System ---\n");
        printf("1. Add Product\n2. Show Products\n3. Search Product\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                addProduct(&products[count]);
                count++;
                break;
            case 2:
                showProducts(products, count);
                break;
            case 3:
                searchProduct(products, count);
                break;
            case 4:
                printf("Exiting program...");
                exit(0);
                break;
            default:
                printf("Invalid choice! Try again.");
        }
    } while(1);
    return 0;
}
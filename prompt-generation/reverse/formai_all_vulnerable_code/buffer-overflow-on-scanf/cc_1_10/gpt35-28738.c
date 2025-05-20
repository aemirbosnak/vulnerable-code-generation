//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: Ken Thompson
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct product {
    char name[30];
    float price;
    int quantity;
};

void addProduct(struct product* products, int* count) {
    char name[30];
    float price;
    int quantity;

    printf("Enter product name: ");
    scanf("%s", name);
    printf("Enter product price: ");
    scanf("%f", &price);
    printf("Enter product quantity: ");
    scanf("%d", &quantity);

    strcpy(products[*count].name, name);
    products[*count].price = price;
    products[*count].quantity = quantity;

    printf("Product added successfully!\n\n");

    (*count)++;
}

void removeProduct(struct product* products, int* count) {
    char name[30];
    int index = -1;

    printf("Enter product name: ");
    scanf("%s", name);

    for(int i=0; i<*count; i++) {
        if(strcmp(products[i].name, name) == 0) {
            index = i;
            break;
        }
    }

    if(index == -1) {
        printf("Product not found!\n\n");
        return;
    }

    for(int i=index; i<(*count)-1; i++) {
        strcpy(products[i].name, products[i+1].name);
        products[i].price = products[i+1].price;
        products[i].quantity = products[i+1].quantity;
    }

    (*count)--;

    printf("Product removed successfully!\n\n");
}

void listProducts(struct product* products, int count) {
    printf("Product Name\tPrice\tQuantity\n");

    for(int i=0; i<count; i++) {
        printf("%s\t\t%.2f\t%d\n", products[i].name, products[i].price, products[i].quantity);
    }

    printf("\n");
}

void updateQuantity(struct product* products, int count) {
    char name[30];
    int quantity, index = -1;

    printf("Enter product name: ");
    scanf("%s", name);

    for(int i=0; i<count; i++) {
        if(strcmp(products[i].name, name) == 0) {
            index = i;
            break;
        }
    }

    if(index == -1) {
        printf("Product not found!\n\n");
        return;
    }

    printf("Enter new product quantity: ");
    scanf("%d", &quantity);

    products[index].quantity = quantity;

    printf("Product quantity updated successfully!\n\n");
}

int main() {
    struct product products[100];
    int count = 0;

    int choice;

    do {
        printf("1. Add product\n");
        printf("2. Remove product\n");
        printf("3. List products\n");
        printf("4. Update quantity\n");
        printf("5. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                addProduct(products, &count);
                break;

            case 2:
                removeProduct(products, &count);
                break;

            case 3:
                listProducts(products, count);
                break;

            case 4:
                updateQuantity(products, count);
                break;

            case 5:
                exit(0);
            
            default:
                printf("Invalid choice!\n\n");
        }
    } while(1);

    return 0;
}
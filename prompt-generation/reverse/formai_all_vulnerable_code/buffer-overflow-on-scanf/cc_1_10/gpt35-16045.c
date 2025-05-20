//FormAI DATASET v1.0 Category: Product Inventory System ; Style: modular
#include<stdio.h>
#include<stdlib.h>

struct product {
    char name[20];
    int id;
    float price;
    int qty;
} p[20];

int size = 0;

void addProduct() {
    printf("\nEnter product name: ");
    scanf("%s", p[size].name);
    printf("Enter product ID: ");
    scanf("%d", &p[size].id);
    printf("Enter product price: ");
    scanf("%f", &p[size].price);
    printf("Enter product quantity: ");
    scanf("%d", &p[size].qty);
    size++;
}

void displayProduct() {
    printf("\n%-20s %-10s %-10s %-10s\n","Product Name","Product ID","Price","Quantity");
    for(int i=0; i<size; i++) {
        printf("%-20s %-10d %-10.2f %-10d\n", p[i].name, p[i].id, p[i].price, p[i].qty);
    }
}

void searchProduct() {
    int id;
    printf("\nEnter product ID to search: ");
    scanf("%d", &id);
    int index = -1;
    for(int i=0; i<size; i++) {
        if(p[i].id == id) {
            index = i;
            break;
        }
    }
    if(index == -1) {
        printf("Product not found!\n");
    } else {
        printf("\n%-20s %-10s %-10s %-10s\n","Product Name","Product ID","Price","Quantity");
        printf("%-20s %-10d %-10.2f %-10d\n", p[index].name, p[index].id, p[index].price, p[index].qty);
    }
}

void sellProduct() {
    int id, qty;
    printf("\nEnter product ID to sell: ");
    scanf("%d", &id);
    int index = -1;
    for(int i=0; i<size; i++) {
        if(p[i].id == id) {
            index = i;
            break;
        }
    }
    if(index == -1) {
        printf("Product not found!\n");
    } else {
        printf("Enter quantity to sell: ");
        scanf("%d", &qty);
        if(p[index].qty < qty) {
            printf("Not enough stock!\n");
        } else {
            p[index].qty -= qty;
            printf("Sold %d units of %s\n", qty, p[index].name);
        }
    }
}

int menu() {
    int choice;
    printf("\n----------PRODUCT INVENTORY SYSTEM----------\n");
    printf("[1] Add new product\n");
    printf("[2] Display all products\n");
    printf("[3] Search product by ID\n");
    printf("[4] Sell product\n");
    printf("[5] Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    return choice;
}

int main() {
    int choice;
    do {
        choice = menu();
        switch(choice) {
            case 1:
                addProduct();
                break;
            case 2:
                displayProduct();
                break;
            case 3:
                searchProduct();
                break;
            case 4:
                sellProduct();
                break;
            case 5:
                printf("\nExiting program...\n");
                exit(0);
            default:
                printf("\nInvalid choice!\n");
        }
    } while(1);
    return 0;
}
//FormAI DATASET v1.0 Category: Product Inventory System ; Style: artistic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct product {
    int id;
    char name[30];
    float price;
    int quantity;
};

void displayMenu() {
    printf("\n\nWelcome to the Inventory Management System");
    printf("\n[1] Add a new product");
    printf("\n[2] List all products");
    printf("\n[3] Find product by name");
    printf("\n[4] Buy a product");
    printf("\n[5] Exit");
    printf("\nPlease enter your choice: ");
}

void addProduct(struct product *p, int * count) {
    printf("\nEnter product details: ");
    printf("\nProduct name: ");
    scanf("%s", p[*count].name);
    printf("Product price: ");
    scanf("%f", &p[*count].price);
    printf("Product quantity: ");
    scanf("%d", &p[*count].quantity);
    p[*count].id = *count + 1;
    printf("\nProduct added successfully!");
    *count += 1;
}

void listProducts(struct product *p, int count) {
    printf("\nList of all products: ");
    printf("\nID | Name | Price | Quantity");
    printf("\n-----------------------------");
    for(int i=0; i<count; i++) {
        printf("\n%d | %s | %.2f | %d", p[i].id, p[i].name, p[i].price, p[i].quantity);
    }
}

void findProduct(struct product *p, int count) {
    char name[30];
    int found = 0;
    printf("\nEnter product name to search: ");
    scanf("%s", name);
    for(int i=0; i<count; i++) {
        if(strcmp(name, p[i].name) == 0) {
            printf("\nProduct found:");
            printf("\nID: %d, Name: %s, Price: %.2f, Quantity: %d", p[i].id, p[i].name, p[i].price, p[i].quantity);
            found = 1;
            break;
        }
    }
    if(!found) {
        printf("\nProduct not found");
    }
}

void buyProduct(struct product *p, int count) {
    int id, qty, found=0;
    printf("\nEnter product ID to buy: ");
    scanf("%d", &id);
    for(int i=0; i<count; i++) {
        if(p[i].id == id) {
            printf("\nEnter quantity to buy: ");
            scanf("%d", &qty);
            if(qty <= p[i].quantity) {
                p[i].quantity -= qty;
                printf("\nPurchase successful!");
            }
            else {
                printf("\nNot enough quantity available");
            }
            found = 1;
            break;
        }
    }
    if(!found) {
        printf("\nProduct not found");
    }
}

int main() {
    struct product p[100];
    int count = 0, choice;
    while(1) {
        displayMenu();
        scanf("%d", &choice);
        switch(choice) {
            case 1: 
                addProduct(p, &count);
                break;
            case 2:
                listProducts(p, count);
                break;
            case 3:
                findProduct(p, count);
                break;
            case 4:
                buyProduct(p, count);
                break;
            case 5:
                printf("\nExiting program...");
                exit(0);
            default:
                printf("\nInvalid choice. Please try again.");
        }
    }
    return 0;
}
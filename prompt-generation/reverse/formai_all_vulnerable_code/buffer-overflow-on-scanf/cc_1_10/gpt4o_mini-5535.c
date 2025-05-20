//GPT-4o-mini DATASET v1.0 Category: Medical Store Management System ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define NAME_LENGTH 50

typedef struct {
    char name[NAME_LENGTH];
    int quantity;
    float price;
} Product;

typedef struct {
    Product products[MAX_PRODUCTS];
    int count;
} Pharmacy;

void add_product(Pharmacy *pharmacy) {
    if(pharmacy->count >= MAX_PRODUCTS) {
        printf("No more space to add new products!\n");
        return;
    }
    Product p;
    printf("Enter product name: ");
    scanf("%s", p.name);
    printf("Enter product quantity: ");
    scanf("%d", &p.quantity);
    printf("Enter product price: ");
    scanf("%f", &p.price);
    
    pharmacy->products[pharmacy->count++] = p;
    printf("Product added successfully!\n");
}

void view_products(Pharmacy pharmacy) {
    if(pharmacy.count == 0) {
        printf("No products available.\n");
        return;
    }
    printf("\nAvailable Products:\n");
    for(int i = 0; i < pharmacy.count; i++) {
        printf("Product Name: %s, Quantity: %d, Price: $%.2f\n",
            pharmacy.products[i].name, 
            pharmacy.products[i].quantity, 
            pharmacy.products[i].price);
    }
    printf("\n");
}

void sell_product(Pharmacy *pharmacy) {
    char name[NAME_LENGTH];
    int quantity;

    printf("Enter product name to sell: ");
    scanf("%s", name);
    printf("Enter quantity to sell: ");
    scanf("%d", &quantity);

    for(int i = 0; i < pharmacy->count; i++) {
        if(strcmp(pharmacy->products[i].name, name) == 0) {
            if(pharmacy->products[i].quantity >= quantity) {
                pharmacy->products[i].quantity -= quantity;
                printf("Sold %d of %s successfully!\n", quantity, name);
                return;
            } else {
                printf("Not enough stock available!\n");
                return;
            }
        }
    }
    printf("Product not found!\n");
}

void delete_product(Pharmacy *pharmacy) {
    char name[NAME_LENGTH];
    printf("Enter product name to delete: ");
    scanf("%s", name);

    for(int i = 0; i < pharmacy->count; i++) {
        if(strcmp(pharmacy->products[i].name, name) == 0) {
            for(int j = i; j < pharmacy->count - 1; j++) {
                pharmacy->products[j] = pharmacy->products[j + 1];
            }
            pharmacy->count--;
            printf("Product deleted successfully!\n");
            return;
        }
    }
    printf("Product not found!\n");
}

void menu() {
    printf("---- Pharmacy Management System ----\n");
    printf("1. Add Product\n");
    printf("2. View Products\n");
    printf("3. Sell Product\n");
    printf("4. Delete Product\n");
    printf("5. Exit\n");
    printf("--------------------------------------\n");
    printf("Choose an option: ");
}

int main() {
    Pharmacy myPharmacy;
    myPharmacy.count = 0; // Initialize product count to 0

    int choice;
    while(1) {
        menu();
        scanf("%d", &choice);
        
        switch(choice) {
            case 1: 
                add_product(&myPharmacy);
                break;
            case 2:
                view_products(myPharmacy);
                break;
            case 3:
                sell_product(&myPharmacy);
                break;
            case 4:
                delete_product(&myPharmacy);
                break;
            case 5:
                printf("Exiting the system. Have a good day!\n");
                exit(0);
            default:
                printf("Invalid choice. Please choose again.\n");
        }
    }
    return 0;
}
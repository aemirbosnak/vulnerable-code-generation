//FormAI DATASET v1.0 Category: Digital Auction System ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_BIDS 5
#define MAX_PRODUCTS 10
#define MAX_PRODUCT_NAME 50

typedef struct {
    char name[MAX_PRODUCT_NAME];
    float price;
    int bids[MAX_BIDS];
    int num_bids;
} product;

void add_product(product products[], int* num_products);
void display_products(product products[], int num_products);
void manage_bids(product products[], int num_products);

int main() {
    srand(time(NULL));
    
    product products[MAX_PRODUCTS];
    int num_products = 0;
    int choice;
    
    do {
        printf("\n1. Add product\n2. Display products\n3. Manage bids\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1: add_product(products, &num_products); break;
            case 2: display_products(products, num_products); break;
            case 3: manage_bids(products, num_products); break;
            case 4: printf("Exiting...\n"); break;
            default: printf("Invalid choice!\n");
        }
    } while(choice != 4);
    
    return 0;
}

void add_product(product products[], int* num_products) {
    if (*num_products >= MAX_PRODUCTS) {
        printf("Cannot add more products!\n");
        return;
    }
    
    printf("Enter product name: ");
    scanf("%s", products[*num_products].name);
    products[*num_products].price = (rand() % 100) + 1; // price between 1 and 100
    products[*num_products].num_bids = 0;
    
    printf("Product added successfully!\n");
    
    (*num_products)++;
}

void display_products(product products[], int num_products) {
    if (num_products == 0) {
        printf("No products available!\n");
        return;
    }
    
    printf("PRODUCTS:\n");
    for (int i = 0; i < num_products; i++) {
        printf("%d. %s, Current price: $%.2f\n", i+1, products[i].name, products[i].price);
    }
}

void manage_bids(product products[], int num_products) {
    if (num_products == 0) {
        printf("No products available!\n");
        return;
    }
    
    int product_choice;
    printf("Enter product number to manage bids: ");
    scanf("%d", &product_choice);
    
    if (product_choice < 1 || product_choice > num_products) {
        printf("Invalid product choice!\n");
        return;
    }
    
    product* chosen_product = &products[product_choice-1];
    
    int bid_choice;
    do {
        printf("\n1. View bids\n2. Place bid\n3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &bid_choice);
        
        switch(bid_choice) {
            case 1:
                if (chosen_product->num_bids == 0) {
                    printf("No bids placed for this product!\n");
                } else {
                    printf("Bids for %s:\n", chosen_product->name);
                    for (int i = 0; i < chosen_product->num_bids; i++) {
                        printf("%d. $%d\n", i+1, chosen_product->bids[i]);
                    }
                }
                break;
            case 2:
                if (chosen_product->num_bids >= MAX_BIDS) {
                    printf("Cannot place more bids for this product!\n");
                } else {
                    int bid;
                    printf("Enter bid amount: $");
                    scanf("%d", &bid);
                    
                    if (bid <= chosen_product->price) {
                        printf("Bid amount must be greater than current price!\n");
                    } else {
                        chosen_product->bids[chosen_product->num_bids] = bid;
                        chosen_product->num_bids++;
                        chosen_product->price = bid;
                        
                        printf("Bid placed successfully!\n");
                    }
                }
                break;
            case 3: printf("Exiting...\n"); break;
            default: printf("Invalid choice!\n");
        }
    } while(bid_choice != 3);
}
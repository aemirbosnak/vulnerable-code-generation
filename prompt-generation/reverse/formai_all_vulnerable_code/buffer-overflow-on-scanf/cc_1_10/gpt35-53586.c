//FormAI DATASET v1.0 Category: Digital Auction System ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_PRODUCTS 100
#define MAX_BIDS 1000

typedef struct {
    char name[20];
    int quantity;
    float price;
} Product;

typedef struct {
    char bidder_name[20];
    float bid_amount;
} Bid;

Product products[MAX_PRODUCTS];
Bid bids[MAX_BIDS];
int num_products = 0;
int num_bids[MAX_PRODUCTS];

void add_product() {
    printf("Enter product name: ");
    scanf("%s", products[num_products].name);
    printf("Enter product quantity: ");
    scanf("%d", &products[num_products].quantity);
    printf("Enter product price: ");
    scanf("%f", &products[num_products].price);
    num_bids[num_products] = 0;
    num_products++;
    printf("Product added successfully.\n");
}

void display_products() {
    printf("\nAvailable Products:\n");
    printf("Name\t\tQuantity\tPrice\n");
    for (int i = 0; i < num_products; i++) {
        printf("%-20s%-10d%-10.2f\n", products[i].name, products[i].quantity, products[i].price);
    }
}

void place_bid(int product_index) {
    printf("Enter your name: ");
    scanf("%s", bids[num_bids[product_index]].bidder_name);
    printf("Enter your bid amount: ");
    scanf("%f", &bids[num_bids[product_index]].bid_amount);
    if (bids[num_bids[product_index]].bid_amount > products[product_index].price) {
        products[product_index].price = bids[num_bids[product_index]].bid_amount;
        printf("Congratulations! Your bid has been accepted.\n");
    } else {
        printf("Sorry, your bid has been rejected.\n");
    }
    num_bids[product_index]++;
}

void display_bids(int product_index) {
    printf("\nBids for %s:\n", products[product_index].name);
    printf("Bidder Name\tBid Amount\n");
    for (int i = 0; i < num_bids[product_index]; i++) {
        printf("%-20s%-10.2f\n", bids[i].bidder_name, bids[i].bid_amount);
    }
}

int main() {
    int choice, product_index;

    printf("Welcome to the Digital Auction System.\n\n");

    do {
        printf("Main Menu:\n");
        printf("1. Add product\n");
        printf("2. Display available products\n");
        printf("3. Place bid\n");
        printf("4. Display bids\n");
        printf("5. Exit\n\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_product();
                break;
            case 2:
                display_products();
                break;
            case 3:
                display_products();
                printf("Enter product index to bid: ");
                scanf("%d", &product_index);
                if (product_index >= num_products) {
                    printf("Invalid product index.\n");
                } else {
                    place_bid(product_index);
                }
                break;
            case 4:
                display_products();
                printf("Enter product index to display bids: ");
                scanf("%d", &product_index);
                if (product_index >= num_products) {
                    printf("Invalid product index.\n");
                } else {
                    display_bids(product_index);
                }
                break;
            case 5:
                printf("Thank you for using the Digital Auction System.\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 5);

    return 0;
}
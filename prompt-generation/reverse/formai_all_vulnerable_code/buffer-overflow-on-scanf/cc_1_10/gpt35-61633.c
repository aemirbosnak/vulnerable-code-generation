//FormAI DATASET v1.0 Category: Digital Auction System ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 50
#define MAX_BIDDERS 10

typedef struct Product {
    int id;
    char name[20];
    float current_price;
    int bids_count;
    int bidder_ids[MAX_BIDDERS];
} Product;

typedef struct Bidder {
    int id;
    char name[20];
    float balance;
} Bidder;

Product products[MAX_PRODUCTS];
Bidder bidders[MAX_BIDDERS];
int products_count = 0, bidders_count = 0;

void add_product() {
    Product new_product;
    new_product.id = products_count + 1;

    printf("\nEnter product name: ");
    scanf("%s", &new_product.name);
    printf("Enter starting price: ");
    scanf("%f", &new_product.current_price);

    new_product.bids_count = 0;
    products[products_count] = new_product;
    products_count++;

    printf("\nProduct added successfully!\n");
}

void add_bidder() {
    Bidder new_bidder;
    new_bidder.id = bidders_count + 1;

    printf("\nEnter bidder name: ");
    scanf("%s", &new_bidder.name);
    printf("Enter balance: ");
    scanf("%f", &new_bidder.balance);

    bidders[bidders_count] = new_bidder;
    bidders_count++;

    printf("\nBidder added successfully!\n");
}

void print_products() {
    printf("\n---Products---\n");
    for (int i = 0; i < products_count; i++) {
        printf("\nID: %d", products[i].id);
        printf("\nName: %s", products[i].name);
        printf("\nCurrent Price: %.2f", products[i].current_price);
        printf("\nNumber of Bids: %d", products[i].bids_count);
        printf("\nBidder IDs: ");
        for (int j = 0; j < products[i].bids_count; j++) {
            printf("%d ", products[i].bidder_ids[j]);
        }
        printf("\n------------------------\n");
    }
}

void print_bidders() {
    printf("\n---Bidders---\n");
    for (int i = 0; i < bidders_count; i++) {
        printf("\nID: %d", bidders[i].id);
        printf("\nName: %s", bidders[i].name);
        printf("\nBalance: %.2f", bidders[i].balance);
        printf("\n------------------------\n");
    }
}

void place_bid() {
    int product_id, bidder_id;
    float bid_amount;

    printf("\nEnter Product ID: ");
    scanf("%d", &product_id);
    printf("Enter Bidder ID: ");
    scanf("%d", &bidder_id);
    printf("Enter Bid Amount: ");
    scanf("%f", &bid_amount);

    if (product_id > products_count || bidder_id > bidders_count) {
        printf("\nInvalid product or bidder ID.\n");
        return;
    }
    
    Product *product = &products[product_id - 1];
    Bidder *bidder = &bidders[bidder_id - 1];

    if (bid_amount < product->current_price) {
        printf("\nBid amount must be greater than the current price.\n");
        return;
    }

    if (bid_amount > bidder->balance) {
        printf("\nBid amount exceeds bidder's balance.\n");
        return;
    }

    product->current_price = bid_amount;
    product->bidder_ids[product->bids_count] = bidder_id;
    product->bids_count++;

    bidder->balance -= bid_amount;

    printf("\nBid placed successfully!\n");
}

int main() {
    int choice;

    do {
        printf("\n---Digital Auction System---\n");
        printf("\n1. Add Product");
        printf("\n2. Add Bidder");
        printf("\n3. Print Products");
        printf("\n4. Print Bidders");
        printf("\n5. Place Bid");
        printf("\n6. Exit");
        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_product();
                break;
            case 2:
                add_bidder();
                break;
            case 3:
                print_products();
                break;
            case 4:
                print_bidders();
                break;
            case 5:
                place_bid();
                break;
            case 6:
                printf("\nExiting program...\n");
                exit(0);
            default:
                printf("\nInvalid choice.\n");
                break;
        }
    } while (choice != 6);

    return 0;
}
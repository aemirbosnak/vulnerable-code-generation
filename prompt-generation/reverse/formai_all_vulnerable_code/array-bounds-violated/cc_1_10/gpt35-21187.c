//FormAI DATASET v1.0 Category: Digital Auction System ; Style: configurable
#include<stdio.h>
#include<stdlib.h>

#define MAX_BIDDERS 10
#define MAX_PRODUCTS 10

typedef struct {
    int product_id;
    char product_name[30];
    float base_price;
    int highest_bidder_id;
    float highest_bid;
} Product;

typedef struct {
    int bidder_id;
    char bidder_name[30];
    float balance;
    int owned_products[MAX_PRODUCTS];
} Bidder;

int num_bidders = 0;
int num_products = 0;

Bidder bidders[MAX_BIDDERS];
Product products[MAX_PRODUCTS];

void register_bidder() {
    Bidder new_bidder;
    printf("Enter bidder name: ");
    scanf("%s", new_bidder.bidder_name);
    new_bidder.bidder_id = num_bidders++;
    new_bidder.balance = 1000;
    for(int i = 0; i < MAX_PRODUCTS; i++)
        new_bidder.owned_products[i] = -1;
    bidders[new_bidder.bidder_id] = new_bidder;
}

void display_bidders() {
    printf("BIDDERS:\n");
    printf("ID\tName\tBalance\n");
    for(int i = 0; i < num_bidders; i++)
        printf("%d\t%s\t%.2f\n", bidders[i].bidder_id, bidders[i].bidder_name, bidders[i].balance);
}

void register_product() {
    Product new_product;
    printf("Enter product name: ");
    scanf("%s", new_product.product_name);
    printf("Enter base price: ");
    scanf("%f", &new_product.base_price);
    new_product.product_id = num_products++;
    new_product.highest_bid = new_product.base_price;
    new_product.highest_bidder_id = -1;
    products[new_product.product_id] = new_product;
}

void display_products() {
    printf("PRODUCTS:\n");
    printf("ID\tName\tBase Price\tHighest Bid\tHighest Bidder ID\n");
    for(int i = 0; i < num_products; i++) {
        printf("%d\t%s\t%.2f\t", products[i].product_id, products[i].product_name, products[i].base_price);
        if(products[i].highest_bidder_id == -1)
            printf("None\t\t");
        else
            printf("%.2f\t\t%d\t\t", products[i].highest_bid, products[i].highest_bidder_id);
        printf("\n");
    }
}

void place_bid() {
    int bidder_id, product_id;
    float bid;
    printf("Enter bidder ID: ");
    scanf("%d", &bidder_id);
    printf("Enter product ID: ");
    scanf("%d", &product_id);
    printf("Enter bid: ");
    scanf("%f", &bid);
    if(bidders[bidder_id].balance < bid) {
        printf("Bidder does not have enough balance to place this bid!\n");
        return;
    }
    if(bid < products[product_id].highest_bid) {
        printf("Bid is lower than current highest bid!\n");
        return;
    }
    products[product_id].highest_bidder_id = bidder_id;
    products[product_id].highest_bid = bid;
    bidders[bidder_id].balance -= bid;
    int i;
    for(i = 0; i < MAX_PRODUCTS; i++) {
        if(bidders[bidder_id].owned_products[i] == -1) {
            bidders[bidder_id].owned_products[i] = product_id;
            break;
        }
    }
    printf("Bid successfully placed!\n");
}

void display_bidder_products() {
    int bidder_id;
    printf("Enter bidder ID: ");
    scanf("%d", &bidder_id);
    printf("PRODUCTS OWNED BY BIDDER %d:\n", bidder_id);
    printf("ID\tName\tBase Price\tHighest Bid\tHighest Bidder ID\n");
    for(int i = 0; i < MAX_PRODUCTS; i++) {
        if(bidders[bidder_id].owned_products[i] == -1)
            break;
        int product_id = bidders[bidder_id].owned_products[i];
        printf("%d\t%s\t%.2f\t", products[product_id].product_id, products[product_id].product_name, products[product_id].base_price);
        if(products[product_id].highest_bidder_id == -1)
            printf("None\t\t");
        else
            printf("%.2f\t\t%d\t\t", products[product_id].highest_bid, products[product_id].highest_bidder_id);
        printf("\n");
    }
}

int main() {
    int option;
    do {
        printf("SELECT OPTION:\n");
        printf("1. Register bidder\n");
        printf("2. View registered bidders\n");
        printf("3. Register product\n");
        printf("4. View registered products\n");
        printf("5. Place bid\n");
        printf("6. View bidder's owned products\n");
        printf("7. Exit\n");
        scanf("%d", &option);
        switch(option) {
            case 1:
                register_bidder();
                break;
            case 2:
                display_bidders();
                break;
            case 3:
                register_product();
                break;
            case 4:
                display_products();
                break;
            case 5:
                place_bid();
                break;
            case 6:
                display_bidder_products();
                break;
            case 7:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid option! Please enter a valid option.\n");
                break;
        }
    } while(option != 7);
    return 0;
}
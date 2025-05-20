//FormAI DATASET v1.0 Category: Digital Auction System ; Style: active
#include <stdio.h>
#define MAX_BIDDERS 100
#define MAX_PRODUCTS 1000
#define MAX_PRODUCT_NAME 50

typedef struct {
    char name[MAX_PRODUCT_NAME];
    int highest_bid;
    int bidder_id;
} Product;

typedef struct {
    char name[100];
    int balance;
    int product_id;
    int bid_amount;
    int active_bids;
} Bidder;

int num_bidders = 0;
int num_products = 0;
Bidder bidders[MAX_BIDDERS];
Product products[MAX_PRODUCTS];

void create_bidder() {
    if(num_bidders >= MAX_BIDDERS) {
        printf("Auction system is full\n");
        return;
    }
    
    printf("Enter bidder name: ");
    scanf("%s", bidders[num_bidders].name);
    
    printf("Enter starting balance: $");
    scanf("%d", &bidders[num_bidders].balance);
    
    bidders[num_bidders].product_id = -1;
    bidders[num_bidders].bid_amount = 0;
    bidders[num_bidders].active_bids = 0;
    
    num_bidders++;
}

void create_product() {
    if(num_products >= MAX_PRODUCTS) {
        printf("Auction system is full\n");
        return;
    }
    
    printf("Enter product name: ");
    scanf("%s", products[num_products].name);
    
    products[num_products].highest_bid = 0;
    products[num_products].bidder_id = -1;
    
    num_products++;
}

void make_bid(int bidder_index, int product_index, int bid_amount) {
    if(product_index < 0 || product_index >= num_products) {
        printf("Invalid product index\n");
        return;
    }
    
    if(bid_amount <= products[product_index].highest_bid) {
        printf("Bid must be higher than current highest bid\n");
        return;
    }
    
    if(bidders[bidder_index].product_id != -1) {
        printf("Bidder is already bidding on a product\n");
        return;
    }
    
    if(bidders[bidder_index].balance < bid_amount) {
        printf("Bidder does not have enough money\n");
        return;
    }
    
    if(products[product_index].bidder_id != -1) {
        bidders[products[product_index].bidder_id].active_bids--;
    }
    
    products[product_index].highest_bid = bid_amount;
    products[product_index].bidder_id = bidder_index;
    bidders[bidder_index].balance -= bid_amount;
    bidders[bidder_index].product_id = product_index;
    bidders[bidder_index].bid_amount = bid_amount;
    bidders[bidder_index].active_bids++;
}

void view_bids() {
    for(int i = 0; i < num_products; i++) {
        Product product = products[i];
        
        printf("Product: %s\n", product.name);
        printf("Current highest bid: $%d\n", product.highest_bid);
        if(product.bidder_id != -1) {
            printf("Winning bidder: %s\n", bidders[product.bidder_id].name);
        } else {
            printf("No bids yet\n");
        }
        printf("\n");
    }
}

void view_my_bids(int bidder_index) {
    printf("Your current bids:\n");
    for(int i = 0; i < num_products; i++) {
        if(bidders[bidder_index].product_id == i) {
            printf("%s: $%d\n", products[i].name, bidders[bidder_index].bid_amount);
        }
    }
}

int main() {
    int option, bidder_index, product_index, bid_amount;
    
    printf("Welcome to the digital auction system\n");
    
    while(1) {
        printf("1) Create bidder\n");
        printf("2) Create product\n");
        printf("3) Make bid\n");
        printf("4) View bids\n");
        printf("5) View my bids\n");
        printf("6) Exit\n");
        
        printf("Enter option: ");
        scanf("%d", &option);
        
        switch(option) {
            case 1:
                create_bidder();
                break;
            case 2:
                create_product();
                break;
            case 3:
                printf("Enter your bidder index: ");
                scanf("%d", &bidder_index);
                printf("Enter product index: ");
                scanf("%d", &product_index);
                printf("Enter bid amount: $");
                scanf("%d", &bid_amount);
                
                make_bid(bidder_index, product_index, bid_amount);
                break;
            case 4:
                view_bids();
                break;
            case 5:
                printf("Enter your bidder index: ");
                scanf("%d", &bidder_index);
                
                view_my_bids(bidder_index);
                break;
            case 6:
                printf("Goodbye\n");
                return 0;
            default:
                printf("Invalid option\n");
                break;
        }
    }
}
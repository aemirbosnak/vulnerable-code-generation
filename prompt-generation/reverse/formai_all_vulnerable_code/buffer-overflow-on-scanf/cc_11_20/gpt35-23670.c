//FormAI DATASET v1.0 Category: Digital Auction System ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_BIDDERS 50
#define MAX_PRODUCTS 50

int main()
{
    // Initialize variables
    int num_bidders, num_products, i, j, n;
    char bidder_name[100], product_name[100];
    float bid_amount;
    int highest_bidder_index, highest_bid_index, lowest_bidder_index, lowest_bid_index, no_bid_index;
    float highest_bid, lowest_bid;
    
    // Get number of bidders and products from user
    printf("Enter the number of bidders: ");
    scanf("%d", &num_bidders);
    printf("Enter the number of products: ");
    scanf("%d", &num_products);
    
    // Create arrays for bidders, products, and bids
    char bidders[MAX_BIDDERS][100], products[MAX_PRODUCTS][100];
    float bids[MAX_BIDDERS][MAX_PRODUCTS];
    
    // Get names of bidders and products from user
    for (i = 0; i < num_bidders; i++) {
        printf("Enter name of bidder %d: ", i+1);
        scanf("%s", bidder_name);
        strcpy(bidders[i], bidder_name);
    }
    for (i = 0; i < num_products; i++) {
        printf("Enter name of product %d: ", i+1);
        scanf("%s", product_name);
        strcpy(products[i], product_name);
    }
    
    // Auction loop
    for (i = 0; i < num_products; i++) {
        printf("\nAuctioning %s\n", products[i]);
        highest_bidder_index = -1;
        highest_bid_index = -1;
        lowest_bidder_index = -1;
        lowest_bid_index = -1;
        no_bid_index = -1;
        highest_bid = -1;
        lowest_bid = -1;
        
        // Get bids for current product from bidders
        for (j = 0; j < num_bidders; j++) {
            printf("Enter bid amount for %s by %s: ", products[i], bidders[j]);
            scanf("%f", &bid_amount);
            if (bid_amount == -1) {
                no_bid_index = j;
            } else {
                bids[j][i] = bid_amount;
                if (bid_amount > highest_bid) {
                    highest_bid = bid_amount;
                    highest_bidder_index = j;
                    highest_bid_index = i;
                }
                if (bid_amount < lowest_bid || lowest_bid == -1) {
                    lowest_bid = bid_amount;
                    lowest_bidder_index = j;
                    lowest_bid_index = i;
                }
            }
        }
        
        // Print results of auction for current product
        if (highest_bidder_index == -1) {
            printf("No bids for %s\n", products[i]);
        } else {
            printf("%s wins %s with a bid of %.2f\n", bidders[highest_bidder_index], products[highest_bid_index], highest_bid);
            if (no_bid_index != -1) {
                printf("%s did not bid for %s\n", bidders[no_bid_index], products[i]);
            }
            if (lowest_bidder_index != highest_bidder_index && lowest_bidder_index != -1) {
                printf("%s has the lowest bid for %s with a bid of %.2f\n", bidders[lowest_bidder_index], products[lowest_bid_index], lowest_bid);
            }
        }
    }
    
    return 0;
}
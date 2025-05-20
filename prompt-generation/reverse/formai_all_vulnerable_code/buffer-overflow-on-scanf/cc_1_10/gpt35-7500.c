//FormAI DATASET v1.0 Category: Digital Auction System ; Style: energetic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Structure to store auction details
struct Auction {
    char item_name[50];
    float base_price;
    float highest_bid;
    char highest_bidder[50];
};

// Function to update the details of the highest bidder
void update_bid(struct Auction *a, float new_bid, char *name) {
    if(new_bid > a->highest_bid) {
        a->highest_bid = new_bid;
        strcpy(a->highest_bidder, name);
        printf("Bid for %s updated successfully! Highest Bid: %.2f\n", a->item_name, a->highest_bid);
    } else {
        printf("Your bid should be higher than the current highest bid of %.2f\n", a->highest_bid);
    }
}

int main() {
    struct Auction item;
    char bidder[50];
    float bid;

    // Accepting initial details of the auction
    printf("Enter Item Name: ");
    scanf("%[^\n]%*c", item.item_name);
    printf("Enter Base Price: ");
    scanf("%f", &item.base_price);
    item.highest_bid = item.base_price;
    strcpy(item.highest_bidder, "None");
    printf("Auction Details Set!\n");

    // Auction Begins
    printf("Auction for %s Begins! Base Price: %.2f\n", item.item_name, item.base_price);
    printf("Enter Your Name: ");
    scanf("%[^\n]%*c", bidder);
    while(1) {
        printf("Enter Your Bid: ");
        scanf("%f", &bid);
        update_bid(&item, bid, bidder);
        printf("Enter 1 to Bid Again or 0 to End Auction: ");
        int choice;
        scanf("%d", &choice);
        if(choice == 0) break;
    }
    printf("Auction for %s Ended! Winning Bid: %.2f, Winner: %s\n", item.item_name, item.highest_bid, item.highest_bidder);
    return 0;
}
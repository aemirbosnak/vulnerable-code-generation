//GPT-4o-mini DATASET v1.0 Category: Digital Auction System ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Bid {
    char bidderName[50];
    float amount;
};

struct AuctionItem {
    char name[50];
    float startingBid;
    struct Bid highestBid;
};

void displayAuctionItem(struct AuctionItem item) {
    printf("Current Item: %s\n", item.name);
    printf("Starting Bid: $%.2f\n", item.startingBid);
    printf("Highest Bid: $%.2f by %s\n", item.highestBid.amount, item.highestBid.bidderName);
}

void placeBid(struct AuctionItem *item) {
    char name[50];
    float bidAmount;

    printf("Enter your name (please, no hilarious names): ");
    scanf("%s", name);
    
    printf("Enter your bid amount (in USD) for the %s: ", item->name);
    scanf("%f", &bidAmount);

    if(bidAmount <= item->highestBid.amount) {
        printf("Oops! Your bid is too low! Try again after some self-reflection.\n");
    } else {
        item->highestBid.amount = bidAmount;
        strcpy(item->highestBid.bidderName, name);
        printf("Congratulations, %s! You are now the proud highest bidder of the %s with a bid of $%.2f!\n", name, item->name, bidAmount);
    }
}

void auctionItemEnds(struct AuctionItem item) {
    printf("And the winner is... %s with a bid of $%.2f on the %s!\n", item.highestBid.bidderName, item.highestBid.amount, item.name);
    printf("Please make sure to pick up your imaginary item and cherish it forever. It does wonders for your non-existent collection!\n");
}

int main() {
    struct AuctionItem item;
    
    strcpy(item.name, "Invisible Unicorn");
    item.startingBid = 5.00; // Only $5 for an invisible unicorn!
    
    item.highestBid.amount = 0; // No bids yet, just like my social life.
    strcpy(item.highestBid.bidderName, "No bidders."); // Poor, lonely unicorn.

    printf("Welcome to the Invisible Unicorn Auction!\n");
    printf("Prepare your wallets for the most absurd item ever! \n\n");

    while(1) {
        displayAuctionItem(item);
        
        char choice;
        printf("Do you want to place a bid? (y/n): ");
        scanf(" %c", &choice);

        if(choice == 'y') {
            placeBid(&item);
        } else if(choice == 'n') {
            printf("That's fine; I didn't really want to sell it anyway!\n");
            break;
        } else {
            printf("Hmm, I didn't catch that. Let's try that again: yes or no?\n");
        }

        printf("\n"); // Space for readability
    }

    // End the auction and declare the winner
    if(item.highestBid.amount > 0) {
        auctionItemEnds(item);
    } else {
        printf("No one wants the invisible unicorn? Oh dear...\n");
    }

    printf("Thank you for participating in the strangest auction of all time! Have a fantastical day!\n");
    
    return 0;
}
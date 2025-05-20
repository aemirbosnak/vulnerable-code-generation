//GEMINI-pro DATASET v1.0 Category: Digital Auction System ; Style: funny
#include <stdio.h>
#include <stdlib.h>

// Item struct for holding item details
typedef struct Item {
    char name[50]; // Item name (e.g., "Rare ASCII Art")
    float reserve_price; // Minimum price for the item to be sold
    float current_bid; // Current highest bid for the item
} Item;

// Bidder struct for holding bidder details
typedef struct Bidder {
    char name[50]; // Bidder's name (e.g., "Elmo")
    float budget; // Bidder's maximum budget
} Bidder;

void print_item(Item item) {
    printf("\nItem Details:\n");
    printf("Name: %s\n", item.name);
    printf("Reserve Price: $%.2f\n", item.reserve_price);
    printf("Current Bid: $%.2f\n", item.current_bid);
}

void print_bidder(Bidder bidder) {
    printf("\nBidder Details:\n");
    printf("Name: %s\n", bidder.name);
    printf("Budget: $%.2f\n", bidder.budget);
}

// Main auction function
int main() {
    // Let's get ready for the wackiest digital auction ever!
    printf("Welcome to the LOL Auction House, where laughter and loot collide!\n");

    // Introducing our one-of-a-kind item
    Item item = {"Golden Banana", 100.0, 0.0}; // Reserve price: $100
    print_item(item);

    // Now, let's meet our extraordinary bidders
    Bidder bidders[] = {
        {"Big Bird", 200.0}, // Budget: $200
        {"Cookie Monster", 150.0}, // Budget: $150
        {"Count von Count", 120.0}, // Budget: $120 (he loves to count his pennies!)
    };

    int num_bidders = sizeof(bidders) / sizeof(Bidder);

    // Time for the wild bidding frenzy!
    char bid_again;
    do {
        printf("\nPlace your bids, folks! Enter 'q' to quit bidding.\n");
        for (int i = 0; i < num_bidders; i++) {
            Bidder bidder = bidders[i];
            printf("\n%s, it's your turn! Your budget: $%.2f\n", bidder.name, bidder.budget);

            float bid;
            printf("Enter your bid: ");
            scanf(" %f", &bid);

            if (bid == 'q') {
                printf("%s is out of the bidding game!\n", bidder.name);
            } else if (bid > bidder.budget) {
                printf("Oops, %s! Your bid exceeds your budget. Try again or quit like a sore loser!\n", bidder.name);
            } else if (bid < item.current_bid) {
                printf("Sorry, %s! Your bid is too low. You'll have to do better than that!\n", bidder.name);
            } else {
                item.current_bid = bid;
                printf("Woohoo! %s takes the lead with a bid of $%.2f\n", bidder.name, bid);
            }
        }

        // Check if the reserve price has been met
        if (item.current_bid >= item.reserve_price) {
            printf("\nThe reserve price has been met! We're getting close to selling this gem!\n");
        } else {
            printf("\nCome on, folks! We need a higher bid to reach the reserve price.\n");
        }

        // Let the bidders decide if they want to keep bidding
        printf("\nDo you want to bid again? (y/n): ");
        scanf(" %c", &bid_again);
    } while (bid_again == 'y' && item.current_bid < item.reserve_price);

    // Announcing the lucky winner!
    if (item.current_bid >= item.reserve_price) {
        for (int i = 0; i < num_bidders; i++) {
            Bidder bidder = bidders[i];
            if (bidder.budget >= item.current_bid) {
                printf("\nCongratulations, %s! You've won the Golden Banana with a bid of $%.2f!\n", bidder.name, item.current_bid);
                break;
            }
        }
    } else {
        printf("\nOh no! The reserve price wasn't met. The Golden Banana remains unsold.\n");
    }

    printf("\nThank you for participating in our wacky auction! We hope you had a banana-tastic time!\n");
    return 0;
}
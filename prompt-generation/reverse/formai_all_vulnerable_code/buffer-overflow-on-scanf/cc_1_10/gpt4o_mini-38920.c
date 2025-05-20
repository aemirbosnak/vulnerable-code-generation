//GPT-4o-mini DATASET v1.0 Category: Digital Auction System ; Style: funny
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAX_BIDDERS 10
#define AUCTION_DURATION 10  // in seconds

typedef struct {
    char name[30];
    int bid_amount;
} Bidder;

void display_bidding_details(Bidder bidders[], int count) {
    printf("\n\n=== Current Bids ===\n");
    for (int i = 0; i < count; i++) {
        printf("%s: $%d\n", bidders[i].name, bidders[i].bid_amount);
    }
    printf("====================\n");
}

int main() {
    Bidder bidders[MAX_BIDDERS];
    int bidder_count = 0;
    int highest_bid = 0;
    char highest_bidder[30] = "No one, maybe a ghost?";

    printf("Welcome to the Great Digital Auction Spectacular!\n");
    printf("We have millions... well, maybe just a few items for auction!\n");
    printf("Let's start the bidding war!\n\n");

    // Input bidder names and their first bids
    while (bidder_count < MAX_BIDDERS) {
        printf("Bidder %d, please enter your name (or type 'exit' to quit): ", bidder_count + 1);
        fgets(bidders[bidder_count].name, sizeof(bidders[bidder_count].name), stdin);
        bidders[bidder_count].name[strcspn(bidders[bidder_count].name, "\n")] = '\0';  // Remove newline

        if (strcmp(bidders[bidder_count].name, "exit") == 0) {
            break;
        }

        printf("Hello %s! Please enter your initial bid amount: $", bidders[bidder_count].name);
        scanf("%d", &bidders[bidder_count].bid_amount);
        // Flush the input buffer
        while (getchar() != '\n');  

        if (bidders[bidder_count].bid_amount > highest_bid) {
            highest_bid = bidders[bidder_count].bid_amount;
            strcpy(highest_bidder, bidders[bidder_count].name);
        }

        bidder_count++;
        printf("Your bid is awesome, %s! (Current highest: $%d)\n\n", bidders[bidder_count - 1].name, highest_bid);
    }

    // Countdown timer for the auction
    printf("\nStarting the auction in %d seconds!\n\n", AUCTION_DURATION);
    for (int i = AUCTION_DURATION; i > 0; i--) {
        printf("Auction will start in %d... Grab your wallets!\n", i);
        sleep(1);
    }

    // Bidding phase
    printf("\nAaaand... we're off! Bid like there’s no tomorrow!\n\n");
    time_t start_time = time(NULL);
    while (difftime(time(NULL), start_time) < AUCTION_DURATION) {
        printf("Current highest bid: $%d by %s\n", highest_bid, highest_bidder);
        for (int i = 0; i < bidder_count; i++) {
            printf("%s, do you want to outbid? Current highest is $%d\n", bidders[i].name, highest_bid);
            int new_bid;
            printf("Enter your new bid amount $ or 0 to skip: ");
            scanf("%d", &new_bid);
            // Flush the input buffer
            while (getchar() != '\n');

            if (new_bid > highest_bid) {
                highest_bid = new_bid;
                strcpy(highest_bidder, bidders[i].name);
                printf("New highest bid: $%d by %s! Crowd goes wild!\n", highest_bid, highest_bidder);
            }
        }
        display_bidding_details(bidders, bidder_count);
        sleep(2);
    }

    // Auction end
    printf("\nThe auction has ended! Congratulations to our top bidder:\n");
    if (strcmp(highest_bidder, "No one, maybe a ghost?") == 0) {
        printf("No bids? The item is now officially cursed!\n");
    } else {
        printf("%s with a bid of $%d! You must be loaded!\n", highest_bidder, highest_bid);
        printf("Thank you for participating in our wacky auction! Come back next time for more adventures!\n");
    }

    return 0;
}
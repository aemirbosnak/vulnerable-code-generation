//GPT-4o-mini DATASET v1.0 Category: Digital Auction System ; Style: recursive
#include <stdio.h>
#include <string.h>

#define MAX_BIDS 100

typedef struct {
    char bidderName[50];
    double bidAmount;
} Bid;

Bid bids[MAX_BIDS];
int bidCount = 0;

void placeBid();
void viewBids();
void endAuction();
void auctionMenu();
void clearBuffer();

int main() {
    auctionMenu();
    return 0;
}

void auctionMenu() {
    int choice;

    printf("=== Digital Auction System ===\n");
    printf("1. Place a Bid\n");
    printf("2. View Bids\n");
    printf("3. End Auction\n");
    printf("4. Exit\n");
    printf("Choose an option: ");
    
    if (scanf("%d", &choice) != 1) {
        clearBuffer();
        auctionMenu();
        return; // ensures recursion works properly
    }

    switch (choice) {
        case 1:
            placeBid();
            break;
        case 2:
            viewBids();
            break;
        case 3:
            endAuction();
            break;
        case 4:
            printf("Exiting the auction system. Thank you!\n");
            return;
        default:
            printf("Invalid choice! Please try again.\n");
            auctionMenu();
            break;
    }
}

void placeBid() {
    if (bidCount >= MAX_BIDS) {
        printf("Maximum bid limit reached. Cannot place more bids.\n");
        auctionMenu();
        return;
    }

    Bid newBid;
    printf("Enter your name: ");
    clearBuffer(); // clear the buffer for string input
    fgets(newBid.bidderName, sizeof(newBid.bidderName), stdin);
    newBid.bidderName[strcspn(newBid.bidderName, "\n")] = 0; // remove newline

    printf("Enter your bid amount: ");
    if (scanf("%lf", &newBid.bidAmount) != 1) {
        clearBuffer();
        printf("Invalid input! Please enter a numeric value for the bid amount.\n");
        placeBid();
        return; // recursion for retry
    }

    bids[bidCount++] = newBid;
    printf("Bid placed successfully by %s for $%.2f!\n", newBid.bidderName, newBid.bidAmount);
    auctionMenu();
}

void viewBids() {
    if (bidCount == 0) {
        printf("No bids have been placed yet.\n");
    } else {
        printf("=== Current Bids ===\n");
        for (int i = 0; i < bidCount; i++) {
            printf("Bidder: %s, Amount: $%.2f\n", bids[i].bidderName, bids[i].bidAmount);
        }
    }
    auctionMenu();
}

void endAuction() {
    if (bidCount == 0) {
        printf("No bids have been placed. Auction cannot be ended.\n");
    } else {
        printf("=== Auction Results ===\n");
        double highestBid = 0;
        char winner[50];

        for (int i = 0; i < bidCount; i++) {
            if (bids[i].bidAmount > highestBid) {
                highestBid = bids[i].bidAmount;
                strcpy(winner, bids[i].bidderName);
            }
        }
        printf("Winner: %s, Winning Bid: $%.2f\n", winner, highestBid);
    }
    printf("Ending the auction...\n");
    auctionMenu();
}

void clearBuffer() {
    while (getchar() != '\n'); // clear input buffer
}
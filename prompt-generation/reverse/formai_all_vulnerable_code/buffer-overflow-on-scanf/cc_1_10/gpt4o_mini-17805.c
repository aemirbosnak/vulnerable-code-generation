//GPT-4o-mini DATASET v1.0 Category: Digital Auction System ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_AUCTIONS 100
#define MAX_BIDS 10
#define TITLE_LEN 100
#define NAME_LEN 50

typedef struct {
    char name[NAME_LEN];
    float amount;
} Bid;

typedef struct {
    char title[TITLE_LEN];
    float reserve;
    int bidCount;
    Bid bids[MAX_BIDS];
} Auction;

void createAuction(Auction *auction) {
    printf("Enter auction title: ");
    fgets(auction->title, TITLE_LEN, stdin);
    auction->title[strcspn(auction->title, "\n")] = 0; // Remove newline

    printf("Enter reserve price: ");
    scanf("%f", &auction->reserve);
    auction->bidCount = 0;
    getchar(); // Clear newline from input buffer
}

void placeBid(Auction *auction) {
    if (auction->bidCount >= MAX_BIDS) {
        printf("Max bids reached. Cannot place a new bid.\n");
        return;
    }

    Bid *newBid = &auction->bids[auction->bidCount];
    printf("Enter your name: ");
    fgets(newBid->name, NAME_LEN, stdin);
    newBid->name[strcspn(newBid->name, "\n")] = 0; // Remove newline

    printf("Enter bid amount: ");
    scanf("%f", &newBid->amount);
    getchar(); // Clear newline from input buffer

    if (newBid->amount < auction->reserve) {
        printf("Bid is less than reserve price. Bid not placed.\n");
    } else {
        auction->bidCount++;
        printf("Bid placed successfully!\n");
    }
}

void viewAuction(Auction *auction) {
    printf("\nAuction Title: %s\n", auction->title);
    printf("Reserve Price: %.2f\n", auction->reserve);
    printf("Number of Bids: %d\n", auction->bidCount);
    
    for (int i = 0; i < auction->bidCount; i++) {
        printf("Bid #%d: Name: %s, Amount: %.2f\n", 
               i+1, auction->bids[i].name, auction->bids[i].amount);
    }
}

int main() {
    Auction auctions[MAX_AUCTIONS];
    int auctionCount = 0;
    int choice;
    
    do {
        printf("\nDigital Auction System\n");
        printf("1. Create Auction\n");
        printf("2. Place Bid\n");
        printf("3. View Auction\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Clear newline from input buffer

        switch (choice) {
            case 1:
                if (auctionCount < MAX_AUCTIONS) {
                    createAuction(&auctions[auctionCount]);
                    auctionCount++;
                } else {
                    printf("Maximum number of auctions reached.\n");
                }
                break;
            case 2:
                {
                    int index;
                    printf("Enter auction index (0 to %d): ", auctionCount - 1);
                    scanf("%d", &index);
                    getchar(); // Clear newline from input buffer
                    if (index >= 0 && index < auctionCount) {
                        placeBid(&auctions[index]);
                    } else {
                        printf("Invalid auction index.\n");
                    }
                }
                break;
            case 3:
                {
                    int index;
                    printf("Enter auction index (0 to %d): ", auctionCount - 1);
                    scanf("%d", &index);
                    getchar(); // Clear newline from input buffer
                    if (index >= 0 && index < auctionCount) {
                        viewAuction(&auctions[index]);
                    } else {
                        printf("Invalid auction index.\n");
                    }
                }
                break;
            case 4:
                printf("Exiting the system.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}
//GPT-4o-mini DATASET v1.0 Category: Digital Auction System ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ITEMS 100
#define MAX_BIDS 10
#define ITEM_NAME_LENGTH 50
#define BID_HISTORY_LENGTH 100

typedef struct {
    char itemName[ITEM_NAME_LENGTH];
    float highestBid;
    char highestBidder[ITEM_NAME_LENGTH];
    time_t endTime;
    char bidHistory[BID_HISTORY_LENGTH][ITEM_NAME_LENGTH];
    int bidCount;
} AuctionItem;

void initializeAuctionItem(AuctionItem *item, const char *name, int auctionDuration) {
    strcpy(item->itemName, name);
    item->highestBid = 0.0;
    item->highestBidder[0] = '\0';
    item->endTime = time(NULL) + auctionDuration;
    item->bidCount = 0;
}

void placeBid(AuctionItem *item, const char *bidder, float bidAmount) {
    if (time(NULL) > item->endTime) {
        printf("Auction has ended for item: %s\n", item->itemName);
        return;
    }

    if (bidAmount <= item->highestBid) {
        printf("Your bid must be higher than the current highest bid: %.2f\n", item->highestBid);
        return;
    }

    item->highestBid = bidAmount;
    strcpy(item->highestBidder, bidder);
    sprintf(item->bidHistory[item->bidCount], "%s: %.2f", bidder, bidAmount);
    item->bidCount++;
    printf("Bid placed successfully! New highest bid for %s is %.2f by %s\n", item->itemName, item->highestBid, item->highestBidder);
}

void viewAuctionItem(AuctionItem *item) {
    printf("Auction Item: %s\n", item->itemName);
    printf("Current Highest Bid: %.2f by %s\n", item->highestBid, item->highestBidder[0] ? item->highestBidder : "No bids yet");
    printf("Time remaining: %ld seconds\n", item->endTime - time(NULL));
    printf("Bid History:\n");
    for (int i = 0; i < item->bidCount; i++) {
        printf("%s\n", item->bidHistory[i]);
    }
}

int main() {
    AuctionItem items[MAX_ITEMS];
    int itemCount = 0;

    while (1) {
        printf("\n=== Digital Auction System ===\n");
        printf("1. Create Auction Item\n");
        printf("2. Place Bid\n");
        printf("3. View Auction Item\n");
        printf("4. Exit\n");
        printf("Choose an option: ");
        int option;
        scanf("%d", &option);
        getchar(); // consume newline

        if (option == 1) {
            if (itemCount >= MAX_ITEMS) {
                printf("Maximum auction items limit reached!\n");
                continue;
            }
            char name[ITEM_NAME_LENGTH];
            int duration;

            printf("Enter item name: ");
            fgets(name, ITEM_NAME_LENGTH, stdin);
            name[strcspn(name, "\n")] = 0; // remove newline

            printf("Enter auction duration in seconds: ");
            scanf("%d", &duration);
            getchar(); // consume newline

            initializeAuctionItem(&items[itemCount], name, duration);
            itemCount++;
            printf("Auction Item %s created successfully!\n", name);

        } else if (option == 2) {
            char bidder[ITEM_NAME_LENGTH];
            char itemName[ITEM_NAME_LENGTH];
            float bidAmount;

            printf("Enter your name: ");
            fgets(bidder, ITEM_NAME_LENGTH, stdin);
            bidder[strcspn(bidder, "\n")] = 0; // remove newline

            printf("Enter auction item name to bid on: ");
            fgets(itemName, ITEM_NAME_LENGTH, stdin);
            itemName[strcspn(itemName, "\n")] = 0; // remove newline

            printf("Enter your bid amount: ");
            scanf("%f", &bidAmount);
            getchar(); // consume newline

            int found = 0;
            for (int i = 0; i < itemCount; i++) {
                if (strcmp(items[i].itemName, itemName) == 0) {
                    placeBid(&items[i], bidder, bidAmount);
                    found = 1;
                    break;
                }
            }
            if (!found) {
                printf("Auction item not found.\n");
            }

        } else if (option == 3) {
            char itemName[ITEM_NAME_LENGTH];

            printf("Enter auction item name to view: ");
            fgets(itemName, ITEM_NAME_LENGTH, stdin);
            itemName[strcspn(itemName, "\n")] = 0; // remove newline

            int found = 0;
            for (int i = 0; i < itemCount; i++) {
                if (strcmp(items[i].itemName, itemName) == 0) {
                    viewAuctionItem(&items[i]);
                    found = 1;
                    break;
                }
            }
            if (!found) {
                printf("Auction item not found.\n");
            }

        } else if (option == 4) {
            printf("Exiting the auction system.\n");
            break;

        } else {
            printf("Invalid option. Please try again.\n");
        }
    }

    return 0;
}
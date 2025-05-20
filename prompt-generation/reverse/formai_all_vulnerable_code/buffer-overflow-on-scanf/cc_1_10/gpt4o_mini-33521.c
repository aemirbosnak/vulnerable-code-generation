//GPT-4o-mini DATASET v1.0 Category: Digital Auction System ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

#define MAX_BIDDERS 10
#define MAX_ITEMS 5
#define ITEM_NAME_LENGTH 50
#define BID_LIMIT 100
#define ITEM_TIME_LIMIT 30 // seconds

typedef struct {
    char name[ITEM_NAME_LENGTH];
    float startingPrice;
    float currentPrice;
    char highestBidder[ITEM_NAME_LENGTH];
    time_t endTime;
} Item;

typedef struct {
    char name[ITEM_NAME_LENGTH];
    float budget;
} Bidder;

Item items[MAX_ITEMS];
Bidder bidders[MAX_BIDDERS];
int itemCount = 0;
int bidderCount = 0;

void initializeItems();
void registerBidder();
void startAuction();
void displayItems();
void placeBid(int itemIndex, const char *bidderName, float bidAmount);
void auctionEnd(Item *item);

int main() {
    int choice;
    while (true) {
        printf("\nDigital Auction System\n");
        printf("1. Initialize Items\n");
        printf("2. Register Bidder\n");
        printf("3. Start Auction\n");
        printf("4. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                initializeItems();
                printf("Items initialized.\n");
                break;
            case 2:
                registerBidder();
                break;
            case 3:
                startAuction();
                break;
            case 4:
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}

void initializeItems() {
    itemCount = 2;
    
    strcpy(items[0].name, "Antique Vase");
    items[0].startingPrice = 50.0;
    items[0].currentPrice = 50.0;
    strcpy(items[0].highestBidder, "None");

    strcpy(items[1].name, "Vintage Watch");
    items[1].startingPrice = 100.0;
    items[1].currentPrice = 100.0;
    strcpy(items[1].highestBidder, "None");
}

void registerBidder() {
    if (bidderCount >= MAX_BIDDERS) {
        printf("Maximum number of bidders reached.\n");
        return;
    }

    printf("Enter bidder name: ");
    scanf("%s", bidders[bidderCount].name);
    printf("Enter budget for %s: ", bidders[bidderCount].name);
    scanf("%f", &bidders[bidderCount].budget);
    bidderCount++;
    printf("Bidder registered successfully.\n");
}

void startAuction() {
    displayItems();
    for (int i = 0; i < itemCount; i++) {
        printf("\nStarting auction for %s...\n", items[i].name);
        items[i].endTime = time(NULL) + ITEM_TIME_LIMIT;
        
        while (time(NULL) < items[i].endTime) {
            char bidderName[ITEM_NAME_LENGTH];
            float bidAmount;

            printf("Time left: %ld seconds\n", items[i].endTime - time(NULL));
            printf("Enter your name to place a bid or type 'exit' to continue: ");
            scanf("%s", bidderName);

            if (strcmp(bidderName, "exit") == 0) {
                break;
            }

            bool bidderFound = false;
            for (int j = 0; j < bidderCount; j++) {
                if (strcmp(bidders[j].name, bidderName) == 0) {
                    bidderFound = true;
                    printf("Enter your bid amount (current highest bid is %.2f): ", items[i].currentPrice);
                    scanf("%f", &bidAmount);

                    if (bidAmount > items[i].currentPrice && bidAmount <= bidders[j].budget) {
                        placeBid(i, bidderName, bidAmount);
                        printf("Bid successfully placed!\n");
                    } else {
                        printf("Bid not accepted. Please bid higher or check budget.\n");
                    }
                    break;
                }
            }
            if (!bidderFound) {
                printf("Bidder not found. Please register before bidding.\n");
            }
        }
        auctionEnd(&items[i]);
    }
}

void displayItems() {
    printf("\nAvailable items for auction:\n");
    for (int i = 0; i < itemCount; i++) {
        printf("%d. %s - Starting Price: %.2f, Current Price: %.2f, Highest Bidder: %s\n", 
                i + 1, items[i].name, items[i].startingPrice, items[i].currentPrice, items[i].highestBidder);
    }
}

void placeBid(int itemIndex, const char *bidderName, float bidAmount) {
    items[itemIndex].currentPrice = bidAmount;
    strcpy(items[itemIndex].highestBidder, bidderName);
}

void auctionEnd(Item *item) {
    printf("\nAuction for %s ended.\n", item->name);
    if (strcmp(item->highestBidder, "None") == 0) {
        printf("No bids placed.\n");
    } else {
        printf("Highest bidder: %s with a bid of %.2f\n", item->highestBidder, item->currentPrice);
    }
}
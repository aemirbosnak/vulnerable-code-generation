//FormAI DATASET v1.0 Category: Digital Auction System ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Bid {
    char bidder[50];
    int amount;
};

struct AuctionItem {
    char itemName[50];
    int currentBid;
    int numberOfBids;
    struct Bid bidHistory[10];
};

void printBidder(struct Bid b) {
    printf("%s\t%d\n", b.bidder, b.amount);
}

void printAuctionItem(struct AuctionItem item) {
    printf("Item Name: %s\nCurrent Bid: %d\nNumber of Bids: %d\nBid History:\nBidder\tAmount\n", item.itemName, item.currentBid, item.numberOfBids);
    for (int i = 0; i < item.numberOfBids; i++) {
        printBidder(item.bidHistory[i]);
    }
    printf("\n");
}

void makeBid(struct AuctionItem* item, char bidder[50], int amount) {
    if (amount <= item->currentBid) {
        printf("Bid must be higher than current bid!\n");
        return;
    }
    struct Bid b;
    sprintf(b.bidder, "%s", bidder);
    b.amount = amount;
    item->bidHistory[item->numberOfBids++] = b;
    item->currentBid = amount;
    printf("Bid accepted!\n");
}

int main() {
    srand(time(NULL));
    struct AuctionItem items[5];
    sprintf(items[0].itemName, "Painting");
    items[0].currentBid = 50;
    items[0].numberOfBids = 2;
    sprintf(items[0].bidHistory[0].bidder, "John");
    items[0].bidHistory[0].amount = 60;
    sprintf(items[0].bidHistory[1].bidder, "Sam");
    items[0].bidHistory[1].amount = 55;

    sprintf(items[1].itemName, "Watch");
    items[1].currentBid = 100;
    items[1].numberOfBids = 3;
    sprintf(items[1].bidHistory[0].bidder, "Amy");
    items[1].bidHistory[0].amount = 150;
    sprintf(items[1].bidHistory[1].bidder, "Mike");
    items[1].bidHistory[1].amount = 135;
    sprintf(items[1].bidHistory[2].bidder, "Susan");
    items[1].bidHistory[2].amount = 125;

    sprintf(items[2].itemName, "Jewelry");
    items[2].currentBid = 200;
    items[2].numberOfBids = 1;
    sprintf(items[2].bidHistory[0].bidder, "Kate");
    items[2].bidHistory[0].amount = 225;

    sprintf(items[3].itemName, "Camera");
    items[3].currentBid = 75;
    items[3].numberOfBids = 0;

    sprintf(items[4].itemName, "Bicycle");
    items[4].currentBid = 50;
    items[4].numberOfBids = 1;
    sprintf(items[4].bidHistory[0].bidder, "Tom");
    items[4].bidHistory[0].amount = 60;

    while (1) {
        printf("Select an item to bid on:\n");
        for (int i = 0; i < 5; i++) {
            printf("%d - %s\n", i + 1, items[i].itemName);
        }
        printf("0 - Exit\n");
        int choice;
        scanf("%d", &choice);
        if (choice == 0) break;
        if (choice < 1 || choice > 5) {
            printf("Invalid choice. Choose again.\n");
            continue;
        }
        struct AuctionItem selected = items[choice - 1];
        printf("You selected %s.\n", selected.itemName);
        printf("Current Bid: %d\n", selected.currentBid);
        char bidder[50];
        printf("Enter your name: ");
        scanf("%s", bidder);
        int bidAmount;
        printf("Enter your bid: ");
        scanf("%d", &bidAmount);
        makeBid(&selected, bidder, bidAmount);
        items[choice - 1] = selected;
        printf("Updated bid details:\n");
        printAuctionItem(selected);
    }
    printf("Auction over.\n");
}
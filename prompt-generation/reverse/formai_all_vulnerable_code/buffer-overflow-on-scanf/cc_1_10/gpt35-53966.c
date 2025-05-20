//FormAI DATASET v1.0 Category: Digital Auction System ; Style: synchronous
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_BIDDERS 10

typedef struct {
    int itemNumber;
    char itemName[50];
    double startPrice;
    double currentBid;
    char seller[50];
    bool sold;
    char soldTo[50];
} Item;

typedef struct {
    char bidderName[50];
    double balance;
    int itemsBiddedOn[MAX_ITEMS];
    double bidAmounts[MAX_ITEMS];
    int numBids;
} Bidder;

Item items[MAX_ITEMS];
Bidder bidders[MAX_BIDDERS];

int numItems = 0;
int numBidders = 0;

void addItem(char seller[50], char itemName[50], double startPrice) {
    if (numItems < MAX_ITEMS) {
        items[numItems].itemNumber = numItems + 1;
        strcpy(items[numItems].itemName, itemName);
        items[numItems].startPrice = startPrice;
        items[numItems].currentBid = startPrice;
        strcpy(items[numItems].seller, seller);
        items[numItems].sold = false;
        numItems++;
        printf("Item '%s' added successfully.\n", itemName);
    } else {
        printf("Maximum number of items reached.\n");
    }
}

void displayItems() {
    printf("-----------\n");
    printf("Current Items:\n");
    printf("-----------\n");
    for (int i = 0; i < numItems; i++) {
        printf("[%d] %s (Seller: %s, Starting price: %.2f, Current bid: %.2f)\n", items[i].itemNumber, items[i].itemName, items[i].seller, items[i].startPrice, items[i].currentBid);
    }
    printf("\n");
}

void displayBidders() {
    printf("-----------\n");
    printf("Current Bidders:\n");
    printf("-----------\n");
    for (int i = 0; i < numBidders; i++) {
        printf("[%d] %s (Balance: %.2f)\n", i+1, bidders[i].bidderName, bidders[i].balance);
    }
    printf("\n");
}

void addBid(int bidderIndex, int itemNumber, double bidAmount) {
    Bidder *bidder = &bidders[bidderIndex];
    Item *item = &items[itemNumber-1];
    if (bidAmount > bidder->balance) {
        printf("Bid amount exceeds bidder's balance.\n");
        return;
    }
    if (bidAmount <= item->currentBid) {
        printf("Bid amount must be higher than current bid.\n");
        return;
    }
    if (item->sold) {
        printf("Item already sold to %s.\n", item->soldTo);
        return;
    }
    item->currentBid = bidAmount;
    bidder->balance -= bidAmount;
    bidder->itemsBiddedOn[bidder->numBids] = itemNumber;
    bidder->bidAmounts[bidder->numBids] = bidAmount;
    bidder->numBids++;
}

void sellItem(int itemNumber, int bidderIndex) {
    Item *item = &items[itemNumber-1];
    Bidder *bidder = &bidders[bidderIndex];
    if (item->sold) {
        printf("Item already sold to %s.\n", item->soldTo);
        return;
    }
    item->sold = true;
    strcpy(item->soldTo, bidder->bidderName);
    bidder->balance += item->currentBid;
    for (int i = 0; i < numBidders; i++) {
        if (i != bidderIndex) {
            for (int j = 0; j < bidders[i].numBids; j++) {
                if (bidders[i].itemsBiddedOn[j] == itemNumber) {
                    bidders[i].balance += bidders[i].bidAmounts[j];
                    printf("%s has been refunded $%.2f for item %d.\n", bidders[i].bidderName, bidders[i].bidAmounts[j], itemNumber);
                    bidders[i].numBids--;
                }
            }
        }
    }
    printf("%s sold item %d to %s for $%.2f.\n", item->seller, itemNumber, item->soldTo, item->currentBid);
}

int main() {
    char command[50];
    char name[50];
    char itemName[50];
    double startPrice;
    int itemNumber;
    int bidderIndex;
    double bidAmount;
    printf("Welcome to the Digital Auction System!\n\n");
    while (true) {
        printf("> ");
        scanf("%s", command);
        if (strcmp(command, "additem") == 0) {
            scanf("%s %lf", name, &startPrice);
            fgets(itemName, 50, stdin);
            itemName[strcspn(itemName, "\n")] = 0;
            addItem(name, itemName, startPrice);
        } else if (strcmp(command, "displayitems") == 0) {
            displayItems();
        } else if (strcmp(command, "addbidder") == 0) {
            scanf("%s %lf", name, &bidAmount);
            if (numBidders < MAX_BIDDERS) {
                strcpy(bidders[numBidders].bidderName, name);
                bidders[numBidders].balance = bidAmount;
                numBidders++;
                printf("%s registered successfully.\n", name);
            } else {
                printf("Maximum number of bidders reached.\n");
            }
        } else if (strcmp(command, "displaybidders") == 0) {
            displayBidders();
        } else if (strcmp(command, "bid") == 0) {
            scanf("%d %lf", &bidderIndex, &bidAmount);
            printf("Bidder %s, please enter item number: ", bidders[bidderIndex-1].bidderName);
            scanf("%d", &itemNumber);
            addBid(bidderIndex-1, itemNumber, bidAmount);
        } else if (strcmp(command, "sell") == 0) {
            scanf("%d %d", &itemNumber, &bidderIndex);
            sellItem(itemNumber, bidderIndex-1);
        } else if (strcmp(command, "quit") == 0) {
            printf("Goodbye!\n");
            return 0;
        } else {
            printf("Invalid command.\n");
        }
    }
}
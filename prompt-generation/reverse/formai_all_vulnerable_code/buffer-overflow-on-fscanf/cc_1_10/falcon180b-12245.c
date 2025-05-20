//Falcon-180B DATASET v1.0 Category: Digital Auction System ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_BIDDERS 100
#define MAX_BIDS 1000

typedef struct {
    char name[50];
    int id;
} Bidder;

typedef struct {
    char name[50];
    int id;
    int price;
} Item;

typedef struct {
    int bidderId;
    int itemId;
    int price;
} Bid;

Bidder bidders[MAX_BIDDERS];
Item items[MAX_ITEMS];
Bid bids[MAX_BIDS];
int numBidders, numItems, numBids;

void readBidders() {
    FILE *fp;
    char line[100];

    fp = fopen("bidders.txt", "r");

    if (fp == NULL) {
        printf("Error opening bidders file\n");
        exit(0);
    }

    while (fscanf(fp, "%s %d", line, &bidders[numBidders].id)!= EOF) {
        strcpy(bidders[numBidders].name, line);
        numBidders++;
    }

    fclose(fp);
}

void readItems() {
    FILE *fp;
    char line[100];

    fp = fopen("items.txt", "r");

    if (fp == NULL) {
        printf("Error opening items file\n");
        exit(0);
    }

    while (fscanf(fp, "%s %d", line, &items[numItems].id)!= EOF) {
        strcpy(items[numItems].name, line);
        numItems++;
    }

    fclose(fp);
}

void readBids() {
    FILE *fp;
    char line[100];
    int i;

    fp = fopen("bids.txt", "r");

    if (fp == NULL) {
        printf("Error opening bids file\n");
        exit(0);
    }

    i = 0;

    while (fscanf(fp, "%d %d %d", &bids[i].bidderId, &bids[i].itemId, &bids[i].price)!= EOF) {
        i++;
    }

    numBids = i;

    fclose(fp);
}

void displayBidders() {
    int i;

    for (i = 0; i < numBidders; i++) {
        printf("%s (%d)\n", bidders[i].name, bidders[i].id);
    }
}

void displayItems() {
    int i;

    for (i = 0; i < numItems; i++) {
        printf("%s (%d)\n", items[i].name, items[i].id);
    }
}

void displayBids() {
    int i;

    for (i = 0; i < numBids; i++) {
        printf("%s bid $%d for %s\n", bidders[bids[i].bidderId].name, bids[i].price, items[bids[i].itemId].name);
    }
}

int main() {
    readBidders();
    readItems();
    readBids();

    displayBidders();
    displayItems();
    displayBids();

    return 0;
}
//Falcon-180B DATASET v1.0 Category: Digital Auction System ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int id;
    char name[50];
    int bid;
} Item;

typedef struct {
    int id;
    char name[50];
    int maxBid;
    int winner;
} Auction;

void createItem(Item* item) {
    printf("Enter the item ID: ");
    scanf("%d", &item->id);
    printf("Enter the item name: ");
    scanf("%s", item->name);
    item->bid = 0;
}

void createAuction(Auction* auction) {
    printf("Enter the auction ID: ");
    scanf("%d", &auction->id);
    printf("Enter the auction name: ");
    scanf("%s", auction->name);
    auction->maxBid = 0;
    auction->winner = -1;
}

void addItemToAuction(Auction* auction, Item* item) {
    auction->maxBid += item->bid;
}

void bidOnItem(Item* item, int bid) {
    if (bid > item->bid) {
        item->bid = bid;
    }
}

void startAuction(Auction* auction) {
    int i, maxBid = 0;
    printf("Auction %s has started!\n", auction->name);
    for (i = 0; i < auction->maxBid; i++) {
        printf("The current bid is: $%d\n", i);
        sleep(1);
    }
    printf("The auction has ended!\n");
    if (maxBid > 0) {
        auction->winner = rand() % maxBid + 1;
    }
}

void displayWinner(Auction* auction) {
    if (auction->winner!= -1) {
        printf("The winner of auction %s is bidder %d with a bid of $%d!\n", auction->name, auction->winner, auction->winner * 10);
    } else {
        printf("There was no winner for auction %s.\n", auction->name);
    }
}

int main() {
    srand(time(0));
    Item item1, item2;
    Auction auction1, auction2;

    createItem(&item1);
    createItem(&item2);

    createAuction(&auction1);
    createAuction(&auction2);

    addItemToAuction(&auction1, &item1);
    addItemToAuction(&auction2, &item2);

    bidOnItem(&item1, 50);
    bidOnItem(&item2, 75);

    startAuction(&auction1);
    startAuction(&auction2);

    displayWinner(&auction1);
    displayWinner(&auction2);

    return 0;
}
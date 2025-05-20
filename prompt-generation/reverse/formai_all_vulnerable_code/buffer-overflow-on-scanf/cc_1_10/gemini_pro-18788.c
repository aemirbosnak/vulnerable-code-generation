//GEMINI-pro DATASET v1.0 Category: Digital Auction System ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct AuctionItem {
    int id;
    char *name;
    float price;
    char *description;
};

struct Auction {
    int numItems;
    struct AuctionItem *items;
    float totalValue;
};

void createAuction(struct Auction *auction);
void addAuctionItem(struct Auction *auction, struct AuctionItem item);
void printAuctionDetails(struct Auction *auction);
void startAuction(struct Auction *auction);
void placeBid(struct Auction *auction, int itemIndex, float bidPrice);
void closeAuction(struct Auction *auction);

int main() {
    struct Auction auction;

    srand(time(NULL));
    createAuction(&auction);

    for (int i = 0; i < auction.numItems; i++) {
        printf("Enter the name of item %d: ", (i + 1));
        char name[256];
        fgets(name, sizeof(name), stdin);
        name[strcspn(name, "\n")] = '\0';

        printf("Enter the description of item %d: ", (i + 1));
        char description[512];
        fgets(description, sizeof(description), stdin);
        description[strcspn(description, "\n")] = '\0';

        float price = rand() % 1000 + 1;
        struct AuctionItem item = {i, name, price, description};
        addAuctionItem(&auction, item);
    }

    printAuctionDetails(&auction);
    startAuction(&auction);

    char command[256];
    while (strcmp(command, "quit") != 0) {
        printf("> ");
        fgets(command, sizeof(command), stdin);
        command[strcspn(command, "\n")] = '\0';

        if (strcmp(command, "bid") == 0) {
            int itemIndex;
            float bidPrice;
            printf("Enter the item index: ");
            scanf("%d", &itemIndex);
            printf("Enter the bid price: ");
            scanf("%f", &bidPrice);
            placeBid(&auction, itemIndex, bidPrice);
        }
    }

    closeAuction(&auction);

    return 0;
}

void createAuction(struct Auction *auction) {
    auction->numItems = 0;
    auction->items = NULL;
    auction->totalValue = 0;
}

void addAuctionItem(struct Auction *auction, struct AuctionItem item) {
    auction->numItems++;
    auction->items = realloc(auction->items, sizeof(struct AuctionItem) * auction->numItems);
    auction->items[auction->numItems - 1] = item;
    auction->totalValue += item.price;
}

void printAuctionDetails(struct Auction *auction) {
    printf("Number of items: %d\n", auction->numItems);
    printf("Total value: %.2f\n", auction->totalValue);
    for (int i = 0; i < auction->numItems; i++) {
        printf("Item %d:\n", (i + 1));
        printf("  Name: %s\n", auction->items[i].name);
        printf("  Description: %s\n", auction->items[i].description);
        printf("  Price: %.2f\n", auction->items[i].price);
    }
}

void startAuction(struct Auction *auction) {
    printf("Auction started!\n");
}

void placeBid(struct Auction *auction, int itemIndex, float bidPrice) {
    if (itemIndex < 0 || itemIndex >= auction->numItems) {
        printf("Invalid item index.\n");
        return;
    }

    struct AuctionItem *item = &auction->items[itemIndex];
    if (bidPrice < item->price) {
        printf("Bid price must be greater than or equal to the current price.\n");
        return;
    }

    item->price = bidPrice;
    auction->totalValue += bidPrice;
    printf("Bid placed successfully.\n");
}

void closeAuction(struct Auction *auction) {
    printf("Auction closed!\n");
    for (int i = 0; i < auction->numItems; i++) {
        printf("Item %d: %s\n", (i + 1), auction->items[i].name);
        printf("  Description: %s\n", auction->items[i].description);
        printf("  Price: %.2f\n", auction->items[i].price);
        printf("\n");
    }
}
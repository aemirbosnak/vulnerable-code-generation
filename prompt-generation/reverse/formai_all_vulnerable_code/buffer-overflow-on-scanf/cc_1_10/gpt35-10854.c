//FormAI DATASET v1.0 Category: Digital Auction System ; Style: rigorous
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_BIDS 10
#define ITEM_NAME_LEN 20

typedef struct Bidder {
    char name[20];
    int bidAmount;
} Bidder;

typedef struct Item {
    char itemName[ITEM_NAME_LEN];
    Bidder highestBidder;
    int highestBid;
} Item;

typedef struct Auction {
    Item items[5];
    int numItems;
} Auction;

void initAuction(Auction* auction);
void addItem(Auction* auction, char* itemName);
void viewItems(Auction* auction);
void placeBid(Auction* auction, int itemIndex, char* bidderName, int bidAmount);
void viewBids(Auction* auction, int itemIndex);

int main(){
    Auction auction;
    char itemName[ITEM_NAME_LEN], bidderName[20];
    int bidAmount, choice, itemIndex;

    initAuction(&auction);

    while(1){
        printf("1. Add Item\n2. View Items\n3. Place Bid\n4. View Bids\n5. Exit\n");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                printf("Enter item name: ");
                scanf("%s", itemName);
                addItem(&auction, itemName);
                break;

            case 2:
                viewItems(&auction);
                break;

            case 3:
                printf("Enter item index: ");
                scanf("%d", &itemIndex);
                printf("Enter bidder name: ");
                scanf("%s", bidderName);
                printf("Enter bid amount: ");
                scanf("%d", &bidAmount);
                placeBid(&auction, itemIndex, bidderName, bidAmount);
                break;

            case 4:
                printf("Enter item index: ");
                scanf("%d", &itemIndex);
                viewBids(&auction, itemIndex);
                break;

            case 5:
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}

void initAuction(Auction* auction){
    auction->numItems = 0;
}

void addItem(Auction* auction, char* itemName){
    if(auction->numItems == 5){
        printf("Auction can only hold 5 items!\n");
        return;
    }

    strcpy(auction->items[auction->numItems].itemName, itemName);
    auction->items[auction->numItems].highestBid = 0;
    auction->numItems++;

    printf("Item added successfully!\n");
}

void viewItems(Auction* auction){
    int i;

    if(auction->numItems == 0){
        printf("No items added yet!\n");
        return;
    }

    printf("Index\tItem Name\tHighest Bid\tHighest Bidder\n");
    for(i=0; i<auction->numItems; i++){
        printf("%d\t%s\t\t%d\t\t%s\n", i, auction->items[i].itemName, auction->items[i].highestBid, 
                auction->items[i].highestBidder.name);
    }
}

void placeBid(Auction* auction, int itemIndex, char* bidderName, int bidAmount){
    Item* item = &auction->items[itemIndex];
    Bidder bidder = {0};

    if(itemIndex < 0 || itemIndex >= auction->numItems){
        printf("Invalid item index!\n");
        return;
    }

    if(bidAmount <= item->highestBid){
        printf("Bid amount should be higher than current highest bid!\n");
        return;
    }

    bidder.bidAmount = bidAmount;
    strcpy(bidder.name, bidderName);
    item->highestBidder = bidder;
    item->highestBid = bidAmount;

    printf("Bid placed successfully!\n");
}

void viewBids(Auction* auction, int itemIndex){
    Item* item = &auction->items[itemIndex];

    if(itemIndex < 0 || itemIndex >= auction->numItems){
        printf("Invalid item index!\n");
        return;
    }

    printf("Highest Bidder\tBid Amount\n");
    printf("%s\t\t%d\n", item->highestBidder.name, item->highestBid);
}
//FormAI DATASET v1.0 Category: Digital Auction System ; Style: Alan Touring
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//define the structure to hold auction item details 
struct AuctionItem {
    int itemNumber;
    char itemDescription[50];
    float minBid;
    float currentBid;
    char bidderName[50];
};

//function to display the menu and get user's input
int displayMenu() {
    int choice;
    printf("\n");
    printf("1. Add new auction item\n");
    printf("2. Start bidding\n");
    printf("3. Show auction items\n");
    printf("4. Exit\n");
    printf("\nEnter your choice: ");
    scanf("%d", &choice);
    return choice;
}

//function to add a new auction item
void addItem(struct AuctionItem *items, int *count) {
    printf("\nItem Number: ");
    scanf("%d", &items[*count].itemNumber);
    printf("Item Description: ");
    scanf("%s", items[*count].itemDescription);
    printf("Minimum Bid: ");
    scanf("%f", &items[*count].minBid);
    items[*count].currentBid = items[*count].minBid;
    strcpy(items[*count].bidderName, "-");
    (*count)++;
    printf("\nAuction item added successfully!\n");
}

//function to start bidding on an item
void startBidding(struct AuctionItem *item) {
    float bidAmount;
    printf("\nBidding on item %d - %s\n", item->itemNumber, item->itemDescription);
    printf("Minimum Bid: %.2f\n", item->minBid);
    printf("Current Bid: %.2f\n", item->currentBid);
    printf("Enter your bid amount: ");
    scanf("%f", &bidAmount);
    if (bidAmount > item->currentBid) {
        item->currentBid = bidAmount;
        printf("Congratulations! You are currently the highest bidder.\n");
        printf("Enter your name: ");
        scanf("%s", item->bidderName);
    }
    else {
        printf("Sorry, your bid is lower than the current bid.\n");
    }
}

//function to show all auction items with their details
void showItems(struct AuctionItem *items, int count) {
    printf("\n---AUCTION ITEMS---\n");
    for (int i = 0; i < count; i++) {
        printf("\nItem Number: %d", items[i].itemNumber);
        printf("\nItem Description: %s", items[i].itemDescription);
        printf("\nMinimum Bid: %.2f", items[i].minBid);
        printf("\nCurrent Bid: %.2f", items[i].currentBid);
        printf("\nBidder Name: %s\n", items[i].bidderName);
    }
}

//main function 
int main() {
    struct AuctionItem items[100];
    int count = 0;
    int choice = 0;
    while (choice != 4) {
        choice = displayMenu();
        switch (choice) {
        case 1:
            addItem(items, &count);
            break;
        case 2:
            if (count <= 0) {
                printf("\nNo auction items found\n");
                break;
            }
            printf("\nEnter item number to start bidding: ");
            int itemNumber;
            scanf("%d", &itemNumber);
            for (int i = 0; i < count; i++) {
                if (items[i].itemNumber == itemNumber) {
                    startBidding(&items[i]);
                    break;
                }
            }
            break;
        case 3:
            if (count <= 0) {
                printf("\nNo auction items found\n");
                break;
            }
            showItems(items, count);
            break;
        case 4:
            printf("\nGoodbye!\n");
            break;
        default:
            printf("\nInvalid choice! Please try again.\n");
            break;
        }
    }
    return 0;
}
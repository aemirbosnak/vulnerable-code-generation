//FormAI DATASET v1.0 Category: Digital Auction System ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct auctionItem {
    int itemNo;
    char itemName[50];
    int currentBid;
    char bidder[50];
    bool isSold;
};

int main() {
    struct auctionItem *items = malloc(10 * sizeof(struct auctionItem));
    int numItems = 0;
    char input[50];
    bool quit = false;
    
    while (!quit) {
        printf("Enter command (add, remove, bid, list, quit): ");
        scanf("%s", input);
        
        if (strcmp(input, "add") == 0) {
            if (numItems == 10) {
                printf("Error: Auction is full!\n");
            } else {
                struct auctionItem newItem;
                printf("Enter item name: ");
                scanf("%s", newItem.itemName);
                printf("Enter starting bid: ");
                scanf("%d", &newItem.currentBid);
                newItem.itemNo = numItems;
                newItem.isSold = false;
                items[numItems++] = newItem;
                printf("Item added to auction!\n");
            }
        } else if (strcmp(input, "remove") == 0) {
            int itemNo;
            printf("Enter item number to remove: ");
            scanf("%d", &itemNo);
            if (itemNo < 0 || itemNo >= numItems) {
                printf("Error: Invalid item number!\n");
            } else {
                for (int i = itemNo; i < numItems-1; i++) {
                    items[i] = items[i+1];
                }
                numItems--;
                printf("Item removed from auction!\n");
            }
        } else if (strcmp(input, "bid") == 0) {
            int itemNo;
            printf("Enter item number to bid on: ");
            scanf("%d", &itemNo);
            if (itemNo < 0 || itemNo >= numItems) {
                printf("Error: Invalid item number!\n");
            } else if (items[itemNo].isSold) {
                printf("Error: Item has already been sold!\n");
            } else {
                int bid;
                printf("Enter bid amount: ");
                scanf("%d", &bid);
                if (bid > items[itemNo].currentBid) {
                    printf("New bid accepted!\n");
                    items[itemNo].currentBid = bid;
                    printf("Enter bidder name: ");
                    scanf("%s", items[itemNo].bidder);
                } else {
                    printf("Error: Bid must be higher than current bid!\n");
                }
            }
        } else if (strcmp(input, "list") == 0) {
            printf("Auction Items:\n");
            printf("%-3s %-20s %-10s %-20s %-10s\n", "No.", "Name", "Current Bid", "Bidder", "Status");
            for (int i = 0; i < numItems; i++) {
                printf("%-3d %-20s %-10d %-20s %-10s\n", items[i].itemNo, items[i].itemName, items[i].currentBid, items[i].bidder, items[i].isSold ? "Sold" : "Available");
            }
        } else if (strcmp(input, "quit") == 0) {
            printf("Auction ended.\n");
            quit = true;
        } else {
            printf("Error: Invalid command!\n");
        }
    }
    
    free(items);
    
    return 0;
}
//FormAI DATASET v1.0 Category: Digital Auction System ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// definition of auction item structure
typedef struct auctionItem {
    int itemId;
    char itemName[50];
    float maximumBid;
    char bidderName[50];
} AuctionItem;

// function to print the details of an auction item
void printAuctionItem(AuctionItem item) {
    printf("Item ID: %d\n", item.itemId);
    printf("Item Name: %s\n", item.itemName);
    printf("Maximum Bid: %.2f\n", item.maximumBid);
    if(strlen(item.bidderName) != 0) {
        printf("Bidder Name: %s\n", item.bidderName);
    }
    printf("\n");
}

int main() {
    // creating an array of auction items
    AuctionItem inventory[10];
    int itemCount = 0;

    // menu loop
    while(1) {
        // printing the menu options
        printf("Please select an option:\n");
        printf("1. Add an auction item\n");
        printf("2. Remove an auction item\n");
        printf("3. List all auction items\n");
        printf("4. Bid on an auction item\n");
        printf("5. Exit\n");

        // getting the user's choice
        int choice;
        scanf("%d", &choice);

        switch(choice) {
            case 1: { // add an auction item
                AuctionItem item;
                printf("Enter the item ID: ");
                scanf("%d", &item.itemId);
                printf("Enter the item name: ");
                scanf("%s", item.itemName);
                printf("Enter the maximum bid: ");
                scanf("%f", &item.maximumBid);
                item.bidderName[0] = '\0';
                inventory[itemCount] = item;
                itemCount++;
                printf("Item added successfully.\n\n");
                break;
            }
            case 2: { // remove an auction item
                printf("Enter the ID of the item to be removed: ");
                int itemId;
                scanf("%d", &itemId);

                int itemIndex = -1;
                for(int i=0; i<itemCount; i++) {
                    if(inventory[i].itemId == itemId) {
                        itemIndex = i;
                        break;
                    }
                }

                if(itemIndex == -1) {
                    printf("Item not found.\n\n");
                } else {
                    for(int i=itemIndex; i<itemCount-1; i++) {
                        inventory[i] = inventory[i+1];
                    }
                    itemCount--;
                    printf("Item removed successfully.\n\n");
                }
                break;
            }
            case 3: { // list all auction items
                if(itemCount == 0) {
                    printf("No items found.\n\n");
                } else {
                    for(int i=0; i<itemCount; i++) {
                        printf("Item #%d\n", i+1);
                        printAuctionItem(inventory[i]);
                    }
                }
                break;
            }
            case 4: { // bid on an auction item
                printf("Enter the ID of the item to bid on: ");
                int itemId;
                scanf("%d", &itemId);

                int itemIndex = -1;
                for(int i=0; i<itemCount; i++) {
                    if(inventory[i].itemId == itemId) {
                        itemIndex = i;
                        break;
                    }
                }

                if(itemIndex == -1) {
                    printf("Item not found.\n\n");
                } else {
                    char bidderName[50];
                    printf("Enter your name: ");
                    scanf("%s", bidderName);
                    float bidAmount;
                    printf("Enter your bid amount: ");
                    scanf("%f", &bidAmount);

                    if(bidAmount > inventory[itemIndex].maximumBid) {
                        strcpy(inventory[itemIndex].bidderName, bidderName);
                        inventory[itemIndex].maximumBid = bidAmount;
                        printf("Bid successful.\n\n");
                    } else {
                        printf("Bid amount too low.\n\n");
                    }
                }
                break;
            }
            case 5: { // exit the program
                printf("Goodbye!");
                exit(0);
            }
            default: { // invalid choice
                printf("Invalid choice. Please try again.\n\n");
                break;
            }
        }
    }

    return 0;
}
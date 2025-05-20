//GPT-4o-mini DATASET v1.0 Category: Digital Auction System ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Bid {
    char bidderName[50];
    float amount;
    struct Bid* next;
} Bid;

typedef struct AuctionItem {
    char itemName[100];
    float startingPrice;
    Bid* bids;
    struct AuctionItem* next;
} AuctionItem;

AuctionItem* auctionHead = NULL;

void addItem();
void placeBid();
void viewItems();
void freeMemory();

int main() {
    int choice;
    
    while (1) {
        printf("=== Digital Auction System ===\n");
        printf("1. Add Auction Item\n");
        printf("2. Place a Bid\n");
        printf("3. View Auction Items\n");
        printf("4. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addItem();
                break;
            case 2:
                placeBid();
                break;
            case 3:
                viewItems();
                break;
            case 4:
                freeMemory();
                exit(0);
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }
    return 0;
}

void addItem() {
    AuctionItem* newItem = (AuctionItem*)malloc(sizeof(AuctionItem));
    
    printf("Enter the name of the auction item: ");
    scanf("%s", newItem->itemName);
    printf("Enter the starting price: ");
    scanf("%f", &newItem->startingPrice);
    
    newItem->bids = NULL;
    newItem->next = auctionHead;
    auctionHead = newItem;
    
    printf("Auction item added successfully!\n");
}

void placeBid() {
    char itemName[100];
    float bidAmount;
    char bidderName[50];
    
    printf("Enter the name of the auction item: ");
    scanf("%s", itemName);
    
    AuctionItem* current = auctionHead;
    while (current != NULL) {
        if (strcmp(current->itemName, itemName) == 0) {
            printf("Enter your name: ");
            scanf("%s", bidderName);
            printf("Enter your bid amount: ");
            scanf("%f", &bidAmount);
            
            if (bidAmount > current->startingPrice) {
                Bid* newBid = (Bid*)malloc(sizeof(Bid));
                strcpy(newBid->bidderName, bidderName);
                newBid->amount = bidAmount;
                newBid->next = current->bids;
                current->bids = newBid;

                current->startingPrice = bidAmount; // Update the starting price to the latest bid
                printf("Bid placed successfully!\n");
            } else {
                printf("Bid amount must be greater than the starting price of %.2f!\n", current->startingPrice);
            }
            return;
        }
        current = current->next;
    }
    printf("Auction item not found.\n");
}

void viewItems() {
    AuctionItem* current = auctionHead;
    if (current == NULL) {
        printf("No auction items available.\n");
        return;
    }
    
    printf("=== List of Auction Items ===\n");
    while (current != NULL) {
        printf("Item: %s, Current Highest Bid: %.2f\n", current->itemName, current->startingPrice);
        Bid* bidCurrent = current->bids;
        if (bidCurrent == NULL) {
            printf("No bids placed yet.\n");
        } else {
            printf("Bids:\n");
            while (bidCurrent != NULL) {
                printf("Bidder: %s, Amount: %.2f\n", bidCurrent->bidderName, bidCurrent->amount);
                bidCurrent = bidCurrent->next;
            }
        }
        current = current->next;
    }
}

void freeMemory() {
    AuctionItem* current = auctionHead;
    while (current != NULL) {
        Bid* bidCurrent = current->bids;
        while (bidCurrent != NULL) {
            Bid* tempBid = bidCurrent;
            bidCurrent = bidCurrent->next;
            free(tempBid);
        }
        AuctionItem* tempItem = current;
        current = current->next;
        free(tempItem);
    }
    printf("Memory freed successfully.\n");
}
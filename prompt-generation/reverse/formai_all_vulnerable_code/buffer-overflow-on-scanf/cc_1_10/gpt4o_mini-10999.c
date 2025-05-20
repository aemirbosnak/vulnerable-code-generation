//GPT-4o-mini DATASET v1.0 Category: Digital Auction System ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_BIDS 100

typedef struct Bid {
    char bidderName[50];
    float bidAmount;
    struct Bid* next;
} Bid;

typedef struct Item {
    char itemName[100];
    float startingPrice;
    Bid* bids;
    struct Item* next;
} Item;

Item* itemList = NULL;

// Function to create a new item
Item* createItem(char* name, float price) {
    Item* newItem = (Item*)malloc(sizeof(Item));
    if (newItem) {
        strcpy(newItem->itemName, name);
        newItem->startingPrice = price;
        newItem->bids = NULL;
        newItem->next = NULL;
    }
    return newItem;
}

// Function to add an item to the auction
void addItem(char* name, float price) {
    Item* newItem = createItem(name, price);
    if (!itemList) {
        itemList = newItem;
    } else {
        Item* temp = itemList;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newItem;
    }
}

// Function to place a bid on an item
void placeBid(char* itemName, char* bidderName, float bidAmount) {
    Item* temp = itemList;
    while (temp) {
        if (strcmp(temp->itemName, itemName) == 0) {
            if (!temp->bids || bidAmount > temp->startingPrice) {
                Bid* newBid = (Bid*)malloc(sizeof(Bid));
                if (newBid) {
                    strcpy(newBid->bidderName, bidderName);
                    newBid->bidAmount = bidAmount;
                    newBid->next = temp->bids;
                    temp->bids = newBid;
                    printf("Bid placed by %s for item %s: $%.2f\n", bidderName, itemName, bidAmount);
                }
            } else {
                printf("Bid must be higher than the starting price or existing bids.\n");
            }
            return;
        }
        temp = temp->next;
    }
    printf("Item not found: %s\n", itemName);
}

// Function to display all items and their bids
void displayItems() {
    Item* temp = itemList;
    while (temp) {
        printf("Item: %s, Starting Price: $%.2f\n", temp->itemName, temp->startingPrice);
        if (temp->bids) {
            Bid* bidTemp = temp->bids;
            printf("Bids:\n");
            while (bidTemp) {
                printf("  %s: $%.2f\n", bidTemp->bidderName, bidTemp->bidAmount);
                bidTemp = bidTemp->next;
            }
        } else {
            printf("  No bids yet.\n");
        }
        temp = temp->next;
    }
}

// Function to clean up allocated memory
void freeMemory() {
    Item* itemTemp = itemList;
    while (itemTemp) {
        Bid* bidTemp = itemTemp->bids;
        while (bidTemp) {
            Bid* toFree = bidTemp;
            bidTemp = bidTemp->next;
            free(toFree);
        }
        Item* toFree = itemTemp;
        itemTemp = itemTemp->next;
        free(toFree);
    }
}

int main() {
    int choice;
    char itemName[100], bidderName[50];
    float price, bidAmount;

    while (1) {
        printf("\nDigital Auction System\n");
        printf("1. Add Item\n");
        printf("2. Place Bid\n");
        printf("3. Display Items\n");
        printf("4. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter item name: ");
                scanf(" %[^\n]", itemName);
                printf("Enter starting price: ");
                scanf("%f", &price);
                addItem(itemName, price);
                break;
            case 2:
                printf("Enter item name to bid on: ");
                scanf(" %[^\n]", itemName);
                printf("Enter your name: ");
                scanf(" %[^\n]", bidderName);
                printf("Enter bid amount: ");
                scanf("%f", &bidAmount);
                placeBid(itemName, bidderName, bidAmount);
                break;
            case 3:
                displayItems();
                break;
            case 4:
                freeMemory();
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
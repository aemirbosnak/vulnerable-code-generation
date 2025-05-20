//FormAI DATASET v1.0 Category: Digital Auction System ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Structure for Item
struct Item {
    char name[100];
    int price;
    int id;
};

// Structure for Bidder
struct Bidder {
    char name[100];
    int budget;
    int id;
};

// Global Variables
int bidderCount = 0, itemCount = 0;
struct Bidder bidders[100];
struct Item items[100];

// Function to get a Bidder's details
void getBidderDetails() {
    struct Bidder bidder;
    printf("Enter Bidder Name: ");
    scanf("%s", bidder.name);
    printf("Enter Bidder Budget: ");
    scanf("%d", &bidder.budget);
    bidder.id = bidderCount;
    bidderCount++;
    bidders[bidder.id] = bidder;
}

// Function to get an Item's details
void getItemDetails() {
    struct Item item;
    printf("Enter Item Name: ");
    scanf("%s", item.name);
    printf("Enter Item Starting Price: ");
    scanf("%d", &item.price);
    item.id = itemCount;
    itemCount++;
    items[item.id] = item;
}

// Function to display all Bidders
void displayBidders() {
    printf("\n-------List of Bidders-------\n");
    for(int i = 0; i< bidderCount; i++) {
        printf("Bidder ID: %d, Bidder Name: %s, Bidder Budget: %d\n", bidders[i].id, bidders[i].name, bidders[i].budget);
    }
}

// Function to display all Items
void displayItems() {
    printf("\n-------List of Items-------\n");
    for(int i = 0; i< itemCount; i++) {
        printf("Item ID: %d, Item Name: %s, Item Price: %d\n", items[i].id, items[i].name, items[i].price);
    }
}

// Function to start Auction
void startAuction() {
    printf("\n-------Starting Auction-------\n");
    for(int i = 0; i< itemCount; i++) {
        struct Item item = items[i];
        printf("\nItem %d: %s", i+1, item.name);
        printf("\nStarting Price: %d", item.price);
        printf("\nBidders: ");
        
        // Shuffle Bidders for random order of bidding
        for(int j = 0; j< bidderCount; j++) {
            int randomIndex = rand() % bidderCount;
            struct Bidder bidder = bidders[randomIndex];
            printf("\n\tBidder %d: %s with Budget %d", bidder.id, bidder.name, bidder.budget);
            int bid;
            printf("\n\tEnter your bid for Item %d: ", item.id);
            scanf("%d", &bid);
            if(bid > item.price && bid <= bidder.budget) {
                item.price = bid;
                printf("\n\tBid Accepted !");
            }
            else {
                printf("\n\tBid Rejected, either budget is less or bid is less than starting price !");
            }
        }
        printf("\n\nSold %s to bidder with ID %d for Rs. %d", item.name, bidders[item.id].id, item.price);
    }
}

// Main Function
int main() {
    printf("-------Welcome to Digital Auction System-------\n");
    
    // Menu
    int option;
    do {
        printf("\n-------Menu-------\n");
        printf("1. Add a Bidder\n2. Add an Item\n3. View Bidders\n4. View Items\n5. Start Auction\n6. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &option);
        switch(option) {
            case 1: getBidderDetails(); break;
            case 2: getItemDetails(); break;
            case 3: displayBidders(); break;
            case 4: displayItems(); break;
            case 5: startAuction(); break;
            case 6: break;
            default: printf("\nInvalid Choice, Try Again !");
        }
    } while (option != 6);
    
    printf("\n-------Thanks for using our Digital Auction System-------\n\n");
    return 0;
}
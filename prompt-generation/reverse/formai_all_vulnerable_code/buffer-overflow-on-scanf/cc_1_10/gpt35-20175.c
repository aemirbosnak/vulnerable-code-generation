//FormAI DATASET v1.0 Category: Digital Auction System ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Declare global constants for max bids and max auctions
const int MAX_BIDS = 100;
const int MAX_AUCTIONS = 10;

//Declare global variable for number of auctions
int numAuctions = 0;

//Declare Auction struct
typedef struct Auction {
    int itemNumber;
    float startingBid;
    float highestBid;
    char bidder[50];
    int numBids;
} Auction;

//Declare function prototypes
void createAuction(Auction auctions[]);
void bidOnAuction(Auction auctions[]);
void printAuctions(Auction auctions[]);

int main() {
    srand(time(NULL)); //Seed the random number generator

    Auction auctions[MAX_AUCTIONS]; //Declare array of auctions

    int choice;

    do {
        printf("\n1. Create auction\n2. Bid on auction\n3. Print auctions\n4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: //Create auction
                if(numAuctions >= MAX_AUCTIONS) {
                    printf("Maximum number of auctions reached.\n");
                } else {
                    createAuction(auctions);
                    numAuctions++;
                }
                break;
            case 2: //Bid on auction
                if(numAuctions == 0) {
                    printf("No auctions created yet.\n");
                } else {
                    bidOnAuction(auctions);
                }
                break;
            case 3: //Print auctions
                if(numAuctions == 0) {
                    printf("No auctions created yet.\n");
                } else {
                    printAuctions(auctions);
                }
                break;
            case 4: //Exit
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }

    } while(choice != 4); //Loop until user chooses to exit

    return 0;
}

//Function to create a new auction
void createAuction(Auction auctions[]) {
    int itemNumber = rand() % 1000 + 1; //Generate random item number
    float startingBid;
    printf("Enter starting bid: ");
    scanf("%f", &startingBid);

    Auction auction = {itemNumber, startingBid, startingBid, "", 0}; //Create new auction with given starting bid
    auctions[numAuctions] = auction;
    printf("Auction created.\n");
}

//Function to place a bid on an auction
void bidOnAuction(Auction auctions[]) {
    int itemNumber;
    printf("Enter item number: ");
    scanf("%d", &itemNumber);

    int auctionIndex = -1;
    for(int i = 0; i < numAuctions; i++) {
        if(auctions[i].itemNumber == itemNumber) {
            auctionIndex = i;
            break;
        }
    }

    if(auctionIndex == -1) {
        printf("Auction not found.\n");
    } else {
        float bid;
        printf("Enter bid: ");
        scanf("%f", &bid);

        if(bid <= auctions[auctionIndex].highestBid) {
            printf("Bid must be higher than current highest bid.\n");
        } else {
            auctions[auctionIndex].highestBid = bid;
            printf("Bid accepted.\n");

            //Copy bidder name to auction struct
            printf("Enter bidder name: ");
            scanf("%s", auctions[auctionIndex].bidder);

            auctions[auctionIndex].numBids++; //Increment number of bids for auction
        }
    }
}

//Function to print all auctions
void printAuctions(Auction auctions[]) {
    printf("%-15s %-15s %-15s %-15s %s\n", "Item Number", "Starting Bid", "Current Bid", "Bidder Name", "Number of Bids");
    for(int i = 0; i < numAuctions; i++) {
        printf("%-15d %-15.2f %-15.2f %-15s %d\n", auctions[i].itemNumber, auctions[i].startingBid, auctions[i].highestBid, auctions[i].bidder, auctions[i].numBids);
    }
}
//FormAI DATASET v1.0 Category: Digital Auction System ; Style: random
#include <stdio.h> //header file for standard input and output functions
#include <stdlib.h> //header file for memory allocation and exit function

struct AuctionItem { //structure for defining auction item
    int id;
    char name[50];
    float startingPrice;
    float highestBid;
    char highestBidder[50];
};

void addItem(struct AuctionItem* items, int* numItems, int id, char* name, float startingPrice) { //function to add an item to the auction list
    items[*numItems].id = id;
    sprintf(items[*numItems].name, "%s", name);
    items[*numItems].startingPrice = startingPrice;
    items[*numItems].highestBid = startingPrice;
    sprintf(items[*numItems].highestBidder, "No bidder yet");
    (*numItems)++;
}

void printItemList(struct AuctionItem* items, int numItems) { //function to print the auction list
    printf("\nAuction Item List:\n");
    printf("------------------\n");
    for(int i=0; i<numItems; i++) {
        printf("ID: %d | Name: %s | Starting Price: %.2f | Highest Bid: %.2f | Highest Bidder: %s\n", items[i].id, items[i].name, items[i].startingPrice, items[i].highestBid, items[i].highestBidder);
    }
    printf("------------------\n");
}

int main() {
    int numItems = 0; //counter for number of auction items
    int choice;
    struct AuctionItem items[10]; //array of auction items, can hold up to 10 items

    do { //menu-driven program loop
        printf("\nDigital Auction System\n");
        printf("---------------------\n");
        printf("1. Add Item\n");
        printf("2. View Item List\n");
        printf("3. Place Bid\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: { //add item
                int id;
                char name[50];
                float startingPrice;
                printf("\nEnter Item ID: ");
                scanf("%d", &id);
                printf("Enter Item Name: ");
                scanf(" %[^\n]s", name);
                printf("Enter Starting Price: ");
                scanf("%f", &startingPrice);
                addItem(items, &numItems, id, name, startingPrice);
                printf("\nItem added successfully!\n");
                break;
            }
            case 2: { //view item list
                if(numItems==0) {
                    printf("\nNo items added yet!\n");
                } else {
                    printItemList(items, numItems);
                }
                break;
            }
            case 3: { //place bid
                if(numItems==0) {
                    printf("\nNo items added yet!\n");
                    break;
                }
                int itemId, bidderId;
                float bidAmount;
                printf("\nEnter Item ID to place bid: ");
                scanf("%d", &itemId);
                int isValidItem = 0; //flag to check if item is present in the auction list
                for(int i=0; i<numItems; i++) {
                    if(items[i].id==itemId) {
                        isValidItem = 1;
                        printf("Item found!\n");
                        printf("Name: %s | Starting Price: %.2f | Highest Bid: %.2f | Highest Bidder: %s\n", items[i].name, items[i].startingPrice, items[i].highestBid, items[i].highestBidder);
                        printf("Enter Bidder ID: ");
                        scanf("%d", &bidderId);
                        printf("Enter Bid Amount: ");
                        scanf("%f", &bidAmount);
                        if(bidAmount<=items[i].highestBid) {
                            printf("Bid amount should be higher than current highest bid of %.2f!\n", items[i].highestBid);
                            break;
                        }
                        items[i].highestBid = bidAmount;
                        sprintf(items[i].highestBidder, "%d", bidderId);
                        printf("Bid placed successfully!\n");
                        break;
                    }
                }
                if(!isValidItem) {
                    printf("Invalid Item ID!\n");
                }
                break;
            }
            case 4: { //exit program
                printf("\nThank you for using Digital Auction System!\n");
                exit(0);
                break;
            }
            default: { //invalid choice
                printf("\nInvalid choice! Please enter again.\n");
                break;
            }
        }
    } while(choice!=4);

    return 0;
}
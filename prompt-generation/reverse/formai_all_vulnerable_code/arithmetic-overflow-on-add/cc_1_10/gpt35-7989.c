//FormAI DATASET v1.0 Category: Digital Auction System ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define MAX_BIDDERS 50

// Declaration of the bidder structure
typedef struct
{
    char name[50];
    int bid_amount;
} Bidder;

// Declaration of the auction item structure
typedef struct
{
    char name[50];
    int current_bid;
    Bidder current_bidder;
    Bidder bidders[MAX_BIDDERS];
    int num_bidders;
} AuctionItem;

// Declaration of Romeo and Juliet's auction system
int main()
{
    AuctionItem item;
    item.num_bidders = 0;
    
    // Start the auction system
    printf("Welcome to Romeo and Juliet's Digital Auction System\n");
    printf("--------------------------------------------------\n\n");
    printf("Enter the name of the item to auction: ");
    scanf("%s", item.name);
    printf("\nEnter the starting bid amount: ");
    scanf("%d", &item.current_bid);
    
    // Initialize the current bidder with empty values
    Bidder empty_bidder = {"", 0};
    item.current_bidder = empty_bidder;
    
    while (true)
    {
        char choice;
        
        // Display the current status of the auction
        printf("\nCurrent item: %s\n", item.name);
        printf("Current highest bid: $%d by %s\n", item.current_bid, item.current_bidder.name);
        printf("Bidder list:\n");
        for (int i = 0; i < item.num_bidders; i++)
        {
            printf("%d. %s - $%d\n", i + 1, item.bidders[i].name, item.bidders[i].bid_amount);
        }
        
        // Prompt the user for their choice
        printf("\nWhat would you like to do?\n");
        printf("1. Place a bid\n");
        printf("2. End the auction\n");
        printf("Choice: ");
        scanf(" %c", &choice);
        
        switch(choice)
        {
            case '1':
                // Prompt the user to place a bid
                printf("\nEnter your name: ");
                scanf("%s", item.bidders[item.num_bidders].name);
                printf("Enter your bid: ");
                scanf("%d", &item.bidders[item.num_bidders].bid_amount);
                
                // Check if the bid is higher than the current bid
                if (item.bidders[item.num_bidders].bid_amount > item.current_bid)
                {
                    // Update the current highest bid and bidder
                    item.current_bid = item.bidders[item.num_bidders].bid_amount;
                    item.current_bidder = item.bidders[item.num_bidders];
                    printf("\nCongratulations %s, you are now the highest bidder!\n", item.current_bidder.name);
                }
                else
                {
                    printf("\nSorry %s, your bid is not high enough.\n", item.bidders[item.num_bidders].name);
                }
                
                item.num_bidders++;
                break;
                
            case '2':
                // End the auction and display the winning bidder and amount
                printf("\nThe auction has ended.\n");
                printf("The winning bidder is %s with a bid of $%d.\n", item.current_bidder.name, item.current_bid);
                return 0;
                
            default:
                printf("\nInvalid choice. Please choose again.\n");
                break;
        }
    }
    
    return 0;
}
//FormAI DATASET v1.0 Category: Digital Auction System ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Structure for each item to be auctioned
typedef struct
{
    char name[50];
    char description[100];
    double starting_bid;
    double current_bid;
    char highest_bidder[50];
    bool sold;
} Item;

// Structure for each bidder
typedef struct
{
    char name[50];
    double funds;
    Item *winning_item;
} Bidder;

// Global variables
Item *items;
Bidder *bidders;
int num_items;
int num_bidders;

// Function for initializing the auction items
void initialize_items()
{
    items = (Item*)malloc(num_items * sizeof(Item));
    for(int i = 0; i < num_items; i++)
    {
        printf("\nEnter details for Item %d:\n", i+1);
        printf("Name: ");
        scanf("%s", &items[i].name);
        printf("Description: ");
        scanf("%s", &items[i].description);
        printf("Starting bid: ");
        scanf("%lf", &items[i].starting_bid);
        items[i].current_bid = items[i].starting_bid;
        items[i].sold = false;
    }
}

// Function for initializing the bidders
void initialize_bidders()
{
    bidders = (Bidder*)malloc(num_bidders * sizeof(Bidder));
    for(int i = 0; i < num_bidders; i++)
    {
        printf("\nEnter details for Bidder %d:\n", i+1);
        printf("Name: ");
        scanf("%s", &bidders[i].name);
        printf("Funds: ");
        scanf("%lf", &bidders[i].funds);
        bidders[i].winning_item = NULL;
    }
}

// Function for displaying all the auction items
void display_items()
{
    printf("\nAuction Items:\n");
    for(int i = 0; i < num_items; i++)
    {
        printf("Item %d: %s - %s - Starting Bid: $%.2lf - Current Bid: $%.2lf", i+1, items[i].name, items[i].description, items[i].starting_bid, items[i].current_bid);
        if(items[i].sold)
        {
            printf(" - SOLD to %s", items[i].highest_bidder);
        }
        printf("\n");
    }
}

// Function for displaying all the bidders
void display_bidders()
{
    printf("\nBidders:\n");
    for(int i = 0; i < num_bidders; i++)
    {
        printf("Bidder %d: %s - Available Funds: $%.2lf", i+1, bidders[i].name, bidders[i].funds);
        if(bidders[i].winning_item != NULL)
        {
            printf(" - Winning Item: %s\n", bidders[i].winning_item->name);
        }
        else
        {
            printf("\n");
        }
    }
}

// Function for checking if a bidder can bid on an item
bool bidder_can_bid(Bidder *bidder, Item *item, double new_bid)
{
    if(new_bid <= item->current_bid)
    {
        printf("New bid must be higher than current bid.\n");
        return false;
    }
    if(new_bid > bidder->funds)
    {
        printf("Bidder does not have enough funds to bid.\n");
        return false;
    }
    if(bidder->winning_item != NULL && bidder->winning_item != item)
    {
        printf("Bidder is already winning another item.\n");
        return false;
    }
    return true;
}

// Function for selecting the highest bidder for an item
void select_highest_bidder(Item *item)
{
    for(int i = 0; i < num_bidders; i++)
    {
        if(bidder_can_bid(&bidders[i], item, item->current_bid + 1))
        {
            if(item->highest_bidder[0] != '\0')
            {
                // Return funds to previous highest bidder
                for(int j = 0; j < num_bidders; j++)
                {
                    if(strcmp(bidders[j].name, item->highest_bidder) == 0)
                    {
                        bidders[j].funds += item->current_bid;
                        bidders[j].winning_item = NULL;
                        break;
                    }
                }
            }
            // Update current highest bidder
            strcpy(item->highest_bidder, bidders[i].name);
            item->current_bid += 1;
            bidder_can_bid(&bidders[i], item, item->current_bid);
            bidder_can_bid(&bidders[i], item, item->current_bid + 1);
            bidder_can_bid(&bidders[i], item, item->current_bid + 2);
            bidders[i].funds -= item->current_bid;
            bidders[i].winning_item = item;
        }
    }
    // If nobody bids on the item, mark it as unsold
    if(item->highest_bidder[0] == '\0')
    {
        item->sold = false;
        item->current_bid = item->starting_bid;
    }
    else
    {
        item->sold = true;
    }
}

// Function for conducting the auction
void conduct_auction()
{
    for(int i = 0; i < num_items; i++)
    {
        printf("\nAuctioning Item %d: %s - Starting Bid: $%.2lf\n", i+1, items[i].name, items[i].starting_bid);
        select_highest_bidder(&items[i]);
        printf("Result: Item %d - %s", i+1, items[i].sold ? "SOLD" : "UNSOLD");
        if(items[i].sold)
        {
            printf(" to %s for $%.2lf", items[i].highest_bidder, items[i].current_bid);
        }
        printf("\n");
    }
}

int main()
{
    // Welcome message
    printf("Welcome to our Digital Auction System!\n");

    // Prompt for number of items and bidders
    printf("\nHow many items will be auctioned? ");
    scanf("%d", &num_items);
    printf("How many bidders will participate? ");
    scanf("%d", &num_bidders);

    // Initialize items and bidders
    initialize_items();
    initialize_bidders();

    // Display initial state
    display_items();
    display_bidders();

    // Conduct the auction
    conduct_auction();

    // Display final state
    display_items();
    display_bidders();

    // Free memory
    free(items);
    free(bidders);

    return 0;
}
//FormAI DATASET v1.0 Category: Digital Auction System ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Defining constants
#define PLAYER_COUNT 10
#define ITEM_COUNT 5
#define MAX_BID 1000

// Struct for player information
typedef struct {
    char name[20];
    int money;
} Player;

// Struct for item information
typedef struct {
    char name[20];
    int highest_bid;
    int highest_bidder_id;
} Item;

// Function prototypes
void print_header();
void init_players(Player players[]);
void init_items(Item items[]);
int get_bid();
void print_players(Player players[]);
void print_items(Item items[]);
int get_highest_bidder_id(Item items[]);
void bid(Item items[], int player_id, int item_id, int bid);

// Main function
int main() {
    // Initializing players and items
    Player players[PLAYER_COUNT];
    Item items[ITEM_COUNT];
    init_players(players);
    init_items(items);
    
    // Printing header
    print_header();
    
    // Auction starts
    printf("\nAuction has started!");
    srand(time(0));
    int current_item_id = rand() % ITEM_COUNT;
    while(1) {
        // Printing current item being auctioned
        printf("\n\nCurrent item: %s", items[current_item_id].name);
        
        // Printing highest bidder information
        int highest_bidder_id = get_highest_bidder_id(items);
        if(highest_bidder_id != -1) {
            printf("\nHighest bidder: %s, bid: %d", players[highest_bidder_id].name, items[current_item_id].highest_bid);
        }
        
        // Asking for new bid
        printf("\nPlayer #%d, enter your bid for this item (maximum bid: %d): ", current_item_id+1, MAX_BID);
        int bid_amount = get_bid();
        
        // Checking if bid is valid
        if(bid_amount > MAX_BID || bid_amount <= items[current_item_id].highest_bid) {
            printf("\nInvalid bid amount, please try again...");
            continue;
        }
        
        // Placing bid
        bid(items, current_item_id, current_item_id, bid_amount);
        printf("\nBid accepted by player #%d", current_item_id+1);
        
        // Moving to next player
        current_item_id = (current_item_id + 1) % ITEM_COUNT;
        
        // Checking if auction is over
        int bids_left = 0;
        for(int i=0; i<ITEM_COUNT; i++) {
            if(items[i].highest_bidder_id == -1) {
                bids_left++;
            }
        }
        if(bids_left == 0) {
            break;
        }
    }
    
    // Auction ends
    printf("\n\nAuction has ended!");
    
    // Printing final result
    print_items(items);
    print_players(players);
    
    return 0;
}

// Function to print header
void print_header() {
    printf("====================================================");
    printf("\n||            Digital Auction System             ||");
    printf("\n====================================================");
}

// Function to initialize players
void init_players(Player players[]) {
    for(int i=0; i<PLAYER_COUNT; i++) {
        printf("\nEnter name of Player #%d: ", i+1);
        scanf("%s", players[i].name);
        players[i].money = 1000;
    }
}

// Function to initialize items
void init_items(Item items[]) {
    strcpy(items[0].name, "Water");
    strcpy(items[1].name, "Food");
    strcpy(items[2].name, "Gasoline");
    strcpy(items[3].name, "Medicine");
    strcpy(items[4].name, "Weapon");
    for(int i=0; i<ITEM_COUNT; i++) {
        items[i].highest_bid = 0;
        items[i].highest_bidder_id = -1;
    }
}

// Function to get bid from player input
int get_bid() {
    int bid_amount;
    scanf("%d", &bid_amount);
    return bid_amount;
}

// Function to print player information
void print_players(Player players[]) {
    printf("\n\nPlayers:");
    for(int i=0; i<PLAYER_COUNT; i++) {
        printf("\n%s: %d", players[i].name, players[i].money);
    }
}

// Function to print item information
void print_items(Item items[]) {
    printf("\n\nItems:");
    for(int i=0; i<ITEM_COUNT; i++) {
        printf("\n%s: Highest bid: %d, Highest bidder: %s", items[i].name, items[i].highest_bid, (items[i].highest_bidder_id == -1) ? "Nobody" : items[items[i].highest_bidder_id].name);
    }
}

// Function to get the id of the player with the highest bid for any item
int get_highest_bidder_id(Item items[]) {
    int highest_bidder_id = -1;
    int highest_bid = -1;
    for(int i=0; i<ITEM_COUNT; i++) {
        if(items[i].highest_bid > highest_bid) {
            highest_bid = items[i].highest_bid;
            highest_bidder_id = items[i].highest_bidder_id;
        }
    }
    return highest_bidder_id;
}

// Function to place bid on an item
void bid(Item items[], int player_id, int item_id, int bid) {
    items[item_id].highest_bid = bid;
    items[item_id].highest_bidder_id = player_id;
}
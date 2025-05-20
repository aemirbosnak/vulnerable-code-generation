//FormAI DATASET v1.0 Category: Digital Auction System ; Style: satisfied
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_ENTRIES 100
#define MAX_BIDS 10

struct auction_entry {
    int id;
    char item_name[50];
    char item_description[100];
    int highest_bid;
    char highest_bidder[50];
    int bids_count;
    int bids[MAX_BIDS];
};

struct auction_entry auctions[MAX_ENTRIES];
int auction_count = 0;

void add_auction_entry(char* item_name, char* item_description) {
    struct auction_entry entry;
    entry.id = auction_count + 1;
    strcpy(entry.item_name, item_name);
    strcpy(entry.item_description, item_description);
    entry.bids_count = 0;
    auctions[auction_count] = entry;
    auction_count++;
}

void display_auction_entries() {
    if (auction_count == 0) {
        printf("No auctions entries available!\n");
        return;
    }
    printf("ID\tName\t\tDescription\n");
    for (int i = 0; i < auction_count; i++) {
        struct auction_entry entry = auctions[i];
        printf("%d\t%s\t%s\n", entry.id, entry.item_name, entry.item_description);
    }
}

void display_auction_entry(int id) {
    for (int i = 0; i < auction_count; i++) {
        struct auction_entry entry = auctions[i];
        if (entry.id == id) {
            printf("ID: %d\nName: %s\nDescription: %s\nHighest Bidder: %s\nHighest Bid: %d\n", entry.id, entry.item_name, entry.item_description, entry.highest_bidder, entry.highest_bid);
            printf("%d bids:\n", entry.bids_count);
            for (int b = 0; b < entry.bids_count; b++) {
                printf("%d. %d\n", b + 1, entry.bids[b]);
            }
            return;
        }
    }
    printf("Auction entry with id %d not found.\n", id);
}

int get_auction_entry_index(int id) {
    for (int i = 0; i < auction_count; i++) {
        struct auction_entry entry = auctions[i];
        if (entry.id == id) {
            return i;
        }
    }
    return -1;
}

void add_bid(int id, char* bidder, int bid_amount) {
    int index = get_auction_entry_index(id);
    if (index == -1) {
        printf("Auction entry with id %d not found.\n", id);
        return;
    }
    struct auction_entry* entry = &auctions[index];
    if (entry->bids_count == MAX_BIDS) {
        printf("Max number of bids for auction entry with id %d reached.\n", id);
        return;
    }
    if (entry->highest_bid >= bid_amount) {
        printf("The current highest bid for auction entry with id %d is %d.\n", id, entry->highest_bid);
        return;
    }
    entry->highest_bid = bid_amount;
    strcpy(entry->highest_bidder, bidder);
    entry->bids[entry->bids_count] = bid_amount;
    entry->bids_count++;
    printf("Bid with amount %d added for auction entry with id %d by %s.\n", bid_amount, id, bidder);
}

int main() {
    int option = 0;

    while (option != 4) {
        printf("\n\nDigital Auction System\n");
        printf("-------------------------\n");
        printf("1. Add Auction Entry\n");
        printf("2. Display Auction Entries\n");
        printf("3. Add Bid\n");
        printf("4. Exit\n");
        printf("-------------------------\n");
        printf("Enter option: ");
        scanf("%d", &option);
        printf("-------------------------\n");

        switch(option) {
            case 1:
                printf("Add Auction Entry\n");
                printf("-------------------------\n");
                printf("Enter item name: ");
                char item_name[50];
                scanf("%s", item_name);
                printf("Enter item description: ");
                char item_description[100];
                scanf("%s", item_description);
                add_auction_entry(item_name, item_description);
                printf("Auction entry added successfully with id %d.\n", auction_count);
                break;
            
            case 2:
                printf("Display Auction Entries\n");
                printf("-------------------------\n");
                display_auction_entries();
                break;
            
            case 3:
                printf("Add Bid\n");
                printf("-------------------------\n");
                printf("Enter auction entry id: ");
                int id;
                scanf("%d", &id);
                printf("Enter bidder name: ");
                char bidder[50];
                scanf("%s", bidder);
                printf("Enter bid amount: ");
                int bid_amount;
                scanf("%d", &bid_amount);
                add_bid(id, bidder, bid_amount);
                break;
            
            case 4:
                printf("Goodbye!\n");
                break;

            default:
                printf("Invalid option selected!\n");
        }
    }

    return 0;
}
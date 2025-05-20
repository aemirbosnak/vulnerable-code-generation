//GEMINI-pro DATASET v1.0 Category: Digital Auction System ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store the auction item details
typedef struct auction_item {
    char name[50];
    float starting_price;
    float current_price;
    int status; // 0 - active, 1 - sold, 2 - unsold
} auction_item;

// Structure to store the bidder details
typedef struct bidder {
    char name[50];
    float balance;
} bidder;

// Function to add an auction item
void add_item(auction_item *items, int *num_items) {
    printf("Enter the name of the item: ");
    scanf("%s", items[*num_items].name);

    printf("Enter the starting price: ");
    scanf("%f", &items[*num_items].starting_price);

    printf("Enter the current price: ");
    scanf("%f", &items[*num_items].current_price);

    items[*num_items].status = 0;

    (*num_items)++;
}

// Function to add a bidder
void add_bidder(bidder *bidders, int *num_bidders) {
    printf("Enter the name of the bidder: ");
    scanf("%s", bidders[*num_bidders].name);

    printf("Enter the balance: ");
    scanf("%f", &bidders[*num_bidders].balance);

    (*num_bidders)++;
}

// Function to display the auction items
void display_items(auction_item *items, int num_items) {
    printf("\nAuction Items:\n");
    for (int i = 0; i < num_items; i++) {
        printf("%d. %s (Starting Price: %.2f, Current Price: %.2f, Status: %s)\n", i + 1, items[i].name, items[i].starting_price, items[i].current_price, items[i].status == 0 ? "Active" : items[i].status == 1 ? "Sold" : "Unsold");
    }
}

// Function to display the bidders
void display_bidders(bidder *bidders, int num_bidders) {
    printf("\nBidders:\n");
    for (int i = 0; i < num_bidders; i++) {
        printf("%d. %s (Balance: %.2f)\n", i + 1, bidders[i].name, bidders[i].balance);
    }
}

// Function to place a bid
void place_bid(auction_item *items, bidder *bidders, int num_items, int num_bidders) {
    int item_number, bidder_number;
    float bid_amount;

    printf("\nEnter the item number: ");
    scanf("%d", &item_number);

    if (item_number < 1 || item_number > num_items) {
        printf("Invalid item number.\n");
        return;
    }

    printf("Enter the bidder number: ");
    scanf("%d", &bidder_number);

    if (bidder_number < 1 || bidder_number > num_bidders) {
        printf("Invalid bidder number.\n");
        return;
    }

    printf("Enter the bid amount: ");
    scanf("%f", &bid_amount);

    if (bid_amount <= items[item_number - 1].current_price) {
        printf("Bid amount must be greater than current price.\n");
        return;
    }

    if (bid_amount > bidders[bidder_number - 1].balance) {
        printf("Insufficient balance.\n");
        return;
    }

    // Update the current price of the item and the balance of the bidder
    items[item_number - 1].current_price = bid_amount;
    bidders[bidder_number - 1].balance -= bid_amount;
}

// Function to end the auction
void end_auction(auction_item *items, int num_items) {
    for (int i = 0; i < num_items; i++) {
        if (items[i].status == 0) {
            if (items[i].current_price > items[i].starting_price) {
                items[i].status = 1;
            } else {
                items[i].status = 2;
            }
        }
    }

    printf("\nAuction Ended.\n");
}

// Function to display the auction results
void display_results(auction_item *items, int num_items) {
    printf("\nAuction Results:\n");
    for (int i = 0; i < num_items; i++) {
        printf("%s: ", items[i].name);
        if (items[i].status == 1) {
            printf("Sold for %.2f\n", items[i].current_price);
        } else if (items[i].status == 2) {
            printf("Unsold\n");
        }
    }
}

int main() {
    int choice, num_items = 0, num_bidders = 0;
    auction_item items[100];
    bidder bidders[100];

    while (1) {
        printf("\n1. Add Auction Item\n2. Add Bidder\n3. Display Auction Items\n4. Display Bidders\n5. Place Bid\n6. End Auction\n7. Display Results\n8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_item(items, &num_items);
                break;
            case 2:
                add_bidder(bidders, &num_bidders);
                break;
            case 3:
                display_items(items, num_items);
                break;
            case 4:
                display_bidders(bidders, num_bidders);
                break;
            case 5:
                place_bid(items, bidders, num_items, num_bidders);
                break;
            case 6:
                end_auction(items, num_items);
                break;
            case 7:
                display_results(items, num_items);
                break;
            case 8:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}
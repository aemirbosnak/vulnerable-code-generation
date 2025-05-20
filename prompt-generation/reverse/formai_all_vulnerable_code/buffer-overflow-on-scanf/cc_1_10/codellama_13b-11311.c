//Code Llama-13B DATASET v1.0 Category: Digital Auction System ; Style: peaceful
// Digital Auction System in C

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_AUCTIONS 10
#define MAX_BIDDERS 5

typedef struct {
    char name[20];
    int bid;
} Bidder;

typedef struct {
    char item[20];
    int starting_price;
    int current_price;
    int bid_count;
    Bidder bidders[MAX_BIDDERS];
} Auction;

void print_menu() {
    printf("--------------------------------------------------\n");
    printf("Digital Auction System\n");
    printf("--------------------------------------------------\n");
    printf("1. List all auctions\n");
    printf("2. Place a bid\n");
    printf("3. Check auction status\n");
    printf("4. End auction\n");
    printf("5. Exit\n");
    printf("--------------------------------------------------\n");
}

void list_auctions(Auction auctions[], int num_auctions) {
    printf("--------------------------------------------------\n");
    printf("List of Auctions\n");
    printf("--------------------------------------------------\n");
    for (int i = 0; i < num_auctions; i++) {
        printf("%d. %s - starting price: %d\n", i + 1, auctions[i].item, auctions[i].starting_price);
    }
    printf("--------------------------------------------------\n");
}

void place_bid(Auction auctions[], int num_auctions) {
    int auction_index, bidder_index, bid;

    printf("Enter the index of the auction you want to bid on: ");
    scanf("%d", &auction_index);
    printf("Enter your name: ");
    scanf("%s", &auctions[auction_index].bidders[auctions[auction_index].bid_count].name);
    printf("Enter your bid: ");
    scanf("%d", &bid);

    if (bid > auctions[auction_index].current_price) {
        auctions[auction_index].current_price = bid;
        auctions[auction_index].bid_count++;
        printf("Your bid has been placed successfully.\n");
    } else {
        printf("Your bid is too low, please try again.\n");
    }
}

void check_auction_status(Auction auctions[], int num_auctions) {
    int auction_index;

    printf("Enter the index of the auction you want to check: ");
    scanf("%d", &auction_index);
    printf("Current price: %d\n", auctions[auction_index].current_price);
    printf("Number of bidders: %d\n", auctions[auction_index].bid_count);
}

void end_auction(Auction auctions[], int num_auctions) {
    int auction_index;

    printf("Enter the index of the auction you want to end: ");
    scanf("%d", &auction_index);
    printf("The auction has ended.\n");
    printf("The winner is %s with a bid of %d.\n", auctions[auction_index].bidders[0].name, auctions[auction_index].current_price);
}

int main() {
    Auction auctions[MAX_AUCTIONS] = {
        {"iPhone X", 500, 500, 0},
        {"MacBook Pro", 2000, 2000, 0},
        {"Nintendo Switch", 300, 300, 0},
        {"Samsung TV", 500, 500, 0},
        {"Lenovo Laptop", 1500, 1500, 0}
    };

    int num_auctions = 5;

    while (1) {
        print_menu();
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                list_auctions(auctions, num_auctions);
                break;
            case 2:
                place_bid(auctions, num_auctions);
                break;
            case 3:
                check_auction_status(auctions, num_auctions);
                break;
            case 4:
                end_auction(auctions, num_auctions);
                break;
            case 5:
                exit(0);
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }
    }

    return 0;
}
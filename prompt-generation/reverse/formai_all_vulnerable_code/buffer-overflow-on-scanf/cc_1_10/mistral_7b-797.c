//MISTRAL-7B DATASET v1.0 Category: Digital Auction System ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BIDDERS 10
#define MAX_BID 50

typedef struct {
    char name[20];
    int bid;
} bidder;

bidder bidders[MAX_BIDDERS];
int num_bidders = 0;
int highest_bid = 0;

void print_menu() {
    printf("\nDigital Auction System\n");
    printf("------------------------\n");
    printf("1. Place Bid\n");
    printf("2. Declare Winner\n");
    printf("3. Quit\n");
}

void place_bid() {
    if (num_bidders >= MAX_BIDDERS) {
        printf("Maximum number of bidders reached.\n");
        return;
    }

    printf("Enter bidder name: ");
    scanf("%s", bidders[num_bidders].name);
    printf("Enter bid: ");
    scanf("%d", &bidders[num_bidders].bid);

    if (bidders[num_bidders].bid > highest_bid) {
        highest_bid = bidders[num_bidders].bid;
    }

    num_bidders++;
}

void declare_winner() {
    if (num_bidders == 0) {
        printf("No bidders found.\n");
        return;
    }

    printf("The winner is %s with a bid of %d.\n", bidders[0].name, highest_bid);
}

int main() {
    int choice;

    while (1) {
        print_menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                place_bid();
                break;
            case 2:
                declare_winner();
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}
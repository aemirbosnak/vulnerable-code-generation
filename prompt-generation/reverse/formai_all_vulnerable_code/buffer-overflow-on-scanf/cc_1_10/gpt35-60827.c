//FormAI DATASET v1.0 Category: Digital Auction System ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BIDS 50
#define MAX_NAME_LENGTH 20

struct bid {
    char bidder[MAX_NAME_LENGTH];
    float amount;
};

void get_bids(struct bid *bids, int max_bids);
void print_bids(struct bid *bids, int num_bids);
void find_winner(struct bid *bids, int num_bids);

int main() {
    struct bid bids[MAX_BIDS];
    int num_bids;

    printf("Welcome to the digital auction system!\n");
    printf("Please enter the bids:\n");
    get_bids(bids, MAX_BIDS);

    printf("\nAll bids:\n");
    print_bids(bids, MAX_BIDS);

    printf("\nWinner:\n");
    find_winner(bids, MAX_BIDS);

    return 0;
}

void get_bids(struct bid *bids, int max_bids) {
    char name[MAX_NAME_LENGTH];

    for (int i = 0; i < max_bids; i++) {
        printf("Bidder name: ");
        scanf("%s", name);
        if (strcmp(name, "DONE") == 0) {
            break;
        }
        strcpy(bids[i].bidder, name);
        printf("Amount: $");
        scanf("%f", &bids[i].amount);
    }
}

void print_bids(struct bid *bids, int num_bids) {
    for (int i = 0; i < num_bids; i++) {
        if (strlen(bids[i].bidder) == 0) {
            break;
        }
        printf("%s: $%.2f\n", bids[i].bidder, bids[i].amount);
    }
}

void find_winner(struct bid *bids, int num_bids) {
    float max_bid = 0;
    char winner[MAX_NAME_LENGTH];

    for (int i = 0; i < num_bids; i++) {
        if (strlen(bids[i].bidder) == 0) {
            break;
        }
        if (bids[i].amount > max_bid) {
            max_bid = bids[i].amount;
            strcpy(winner, bids[i].bidder);
        }
    }

    printf("%s: $%.2f\n", winner, max_bid);
}
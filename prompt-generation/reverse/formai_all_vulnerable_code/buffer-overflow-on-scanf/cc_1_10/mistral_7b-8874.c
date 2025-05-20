//MISTRAL-7B DATASET v1.0 Category: Digital Auction System ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#define MAX_BIDS 100
#define BUFFER_SIZE 1024

typedef struct {
    int bidder_id;
    char name[50];
    int bid;
} Bid;

Bid bids[MAX_BIDS];
int bid_count = 0;
int highest_bid = 0;
pthread_mutex_t bids_mutex = PTHREAD_MUTEX_INITIALIZER;

void print_menu() {
    printf("\n------------------------\n");
    printf("| Welcome to the Auction |\n");
    printf("|  1. Place a bid      |\n");
    printf("|  2. View current bids |\n");
    printf("|  3. Exit             |\n");
    printf("------------------------\n");
}

void place_bid(int bidder_id, int bid) {
    pthread_mutex_lock(&bids_mutex);

    if (bid_count >= MAX_BIDS) {
        printf("Maximum number of bids reached.\n");
        pthread_mutex_unlock(&bids_mutex);
        return;
    }

    strcpy(bids[bid_count].name, "Bidder"); // Replace this with the bidder's name
    bids[bid_count].bidder_id = bidder_id;
    bids[bid_count].bid = bid;

    if (bid > highest_bid) {
        highest_bid = bid;
    }

    bid_count++;

    printf("Bid placed successfully.\n");
    printf("Current highest bid: %d\n", highest_bid);

    pthread_mutex_unlock(&bids_mutex);
}

void view_bids() {
    int i;

    pthread_mutex_lock(&bids_mutex);

    printf("\nCurrent bids:\n");
    printf("------------------------\n");

    for (i = 0; i < bid_count; i++) {
        printf("| Bidder ID: %d, Name: %s, Bid: %d |\n", bids[i].bidder_id, bids[i].name, bids[i].bid);
    }

    printf("------------------------\n");

    pthread_mutex_unlock(&bids_mutex);
}

int main() {
    int bidder_id, bid;
    int choice;

    while (1) {
        print_menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                scanf("%d %d", &bidder_id, &bid);
                place_bid(bidder_id, bid);
                break;
            case 2:
                view_bids();
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}
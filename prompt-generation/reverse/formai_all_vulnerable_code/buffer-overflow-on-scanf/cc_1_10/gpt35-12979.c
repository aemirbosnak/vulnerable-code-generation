//FormAI DATASET v1.0 Category: Digital Auction System ; Style: complete
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_BIDS 100
#define MAX_LEN 50

typedef struct {
    char name[MAX_LEN];
    float bid_amount;
} Bid;

void print_current_bid(Bid current_bid);
void print_bid_history(Bid bid_history[], int num_bids);
void get_bidder_name(char name[]);
float get_bid_amount();
int get_num_bids();
bool is_valid_bid(float new_bid, float current_bid);

int main()
{
    Bid current_bid = {"No bids yet", 0};
    Bid bid_history[MAX_BIDS];
    int num_bids = 0;

    printf("Welcome to the Digital Auction System!\n");

    int num_input_bids = get_num_bids();

    for (int i = 0; i < num_input_bids; i++) {
        printf("New bid:\n");

        char name[MAX_LEN];
        get_bidder_name(name);

        float bid_amount = get_bid_amount();

        if (is_valid_bid(bid_amount, current_bid.bid_amount)) {
            current_bid.bid_amount = bid_amount;
            strncpy(current_bid.name, name, MAX_LEN);
            printf("You are currently the highest bidder!\n");
        } else {
            printf("Sorry, your bid is not high enough.\n");
        }

        Bid new_bid = {name, bid_amount};
        bid_history[num_bids++] = new_bid;

        printf("\nCurrent bid information:\n");
        print_current_bid(current_bid);

        printf("\nBid history:\n");
        print_bid_history(bid_history, num_bids);

        printf("------------------------\n");
    }

    return 0;
}

void print_current_bid(Bid current_bid)
{
    printf("Current highest bidder: %s\n", current_bid.name);
    printf("Current bid amount: $%.2f\n", current_bid.bid_amount);
}

void print_bid_history(Bid bid_history[], int num_bids)
{
    for (int i = 0; i < num_bids; i++) {
        printf("%s bid $%.2f\n", bid_history[i].name, bid_history[i].bid_amount);
    }
}

void get_bidder_name(char name[])
{
    printf("Enter your bidder name: ");
    fgets(name, MAX_LEN, stdin);
    name[strcspn(name, "\n")] = '\0';  // Remove trailing newline
}

float get_bid_amount()
{
    float bid_amount;

    do {
        printf("Enter your bid amount: ");
    } while (scanf("%f", &bid_amount) != 1 || bid_amount < 0);

    return bid_amount;
}

int get_num_bids()
{
    int num_bids;

    do {
        printf("How many bids would you like to enter? ");
    } while (scanf("%d", &num_bids) != 1 || num_bids < 1 || num_bids > MAX_BIDS);

    return num_bids;
}

bool is_valid_bid(float new_bid, float current_bid)
{
    return new_bid > current_bid;
}
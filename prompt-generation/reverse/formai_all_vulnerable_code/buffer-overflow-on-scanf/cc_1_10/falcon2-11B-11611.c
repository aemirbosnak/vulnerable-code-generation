//Falcon2-11B DATASET v1.0 Category: Digital Auction System ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define MAX_BIDDERS 10
#define MAX_ITEMS 20
#define MAX_BIDS 50

typedef struct bidder {
    char name[50];
    int balance;
} bidder;

typedef struct item {
    char name[50];
    int price;
    int winner;
} item;

int main() {
    int num_bidders = 0;
    int num_items = 0;
    int num_bids = 0;

    srand(time(NULL));

    item items[MAX_ITEMS];
    bidder bidders[MAX_BIDDERS];

    printf("Welcome to the Digital Auction System!\n");
    printf("Enter the number of bidders: ");
    scanf("%d", &num_bidders);
    printf("Enter the number of items: ");
    scanf("%d", &num_items);
    printf("Enter the number of bids: ");
    scanf("%d", &num_bids);

    for (int i = 0; i < num_bidders; i++) {
        bidders[i].name[0] = 'B';
        bidders[i].name[1] = 'i';
        bidders[i].name[2] = '\0';
        bidders[i].balance = 100;
    }

    for (int i = 0; i < num_items; i++) {
        items[i].name[0] = 'I';
        items[i].name[1] = 't';
        items[i].name[2] = 'e';
        items[i].name[3] ='m';
        items[i].name[4] ='s';
        items[i].name[5] = '\0';
        items[i].price = rand() % 1000 + 1;
    }

    for (int i = 0; i < num_bids; i++) {
        printf("Bidder %d: ", num_bidders - 1);
        scanf("%d", &bidders[num_bidders - 1].balance);
    }

    for (int i = 0; i < num_items; i++) {
        printf("Item %d: ", i + 1);
        scanf("%d", &items[i].price);
    }

    printf("\n");

    for (int i = 0; i < num_bidders; i++) {
        for (int j = 0; j < num_items; j++) {
            if (bidders[i].balance >= items[j].price) {
                items[j].winner = i + 1;
                bidders[i].balance -= items[j].price;
                break;
            }
        }
    }

    printf("\n");

    for (int i = 0; i < num_items; i++) {
        if (items[i].winner == -1) {
            printf("Item %d is still up for bid.\n", i + 1);
        } else {
            printf("Item %d has been won by bidder %d.\n", i + 1, items[i].winner);
        }
    }

    return 0;
}
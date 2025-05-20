//Code Llama-13B DATASET v1.0 Category: Digital Auction System ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_BIDS 100
#define MAX_AUCTIONS 10

struct bid {
    int id;
    int amount;
    struct bid *next;
};

struct auction {
    int id;
    char *name;
    int starting_price;
    int reserve_price;
    struct bid *bids;
    int highest_bid;
    int winner_id;
};

void print_menu() {
    printf("1. Start Auction\n");
    printf("2. Place Bid\n");
    printf("3. End Auction\n");
    printf("4. Show Auctions\n");
    printf("5. Show Bids\n");
    printf("6. Show Winner\n");
    printf("7. Exit\n");
}

void start_auction(struct auction *auctions, int n) {
    for (int i = 0; i < n; i++) {
        auctions[i].id = i;
        auctions[i].name = malloc(sizeof(char) * 20);
        printf("Enter auction name: ");
        scanf("%s", auctions[i].name);
        printf("Enter starting price: ");
        scanf("%d", &auctions[i].starting_price);
        printf("Enter reserve price: ");
        scanf("%d", &auctions[i].reserve_price);
        auctions[i].bids = NULL;
        auctions[i].highest_bid = auctions[i].starting_price;
        auctions[i].winner_id = -1;
    }
}

void place_bid(struct auction *auctions, int n) {
    int id, amount;
    printf("Enter auction id: ");
    scanf("%d", &id);
    printf("Enter amount: ");
    scanf("%d", &amount);
    struct bid *new_bid = malloc(sizeof(struct bid));
    new_bid->id = id;
    new_bid->amount = amount;
    new_bid->next = auctions[id].bids;
    auctions[id].bids = new_bid;
    if (amount > auctions[id].highest_bid) {
        auctions[id].highest_bid = amount;
        auctions[id].winner_id = id;
    }
}

void end_auction(struct auction *auctions, int n) {
    for (int i = 0; i < n; i++) {
        if (auctions[i].winner_id == -1) {
            printf("Auction %d did not have a winner.\n", auctions[i].id);
        } else {
            printf("Auction %d winner is %d with a bid of %d.\n", auctions[i].id, auctions[i].winner_id, auctions[i].highest_bid);
        }
    }
}

void show_auctions(struct auction *auctions, int n) {
    for (int i = 0; i < n; i++) {
        printf("Auction %d: %s, starting price: %d, reserve price: %d\n", auctions[i].id, auctions[i].name, auctions[i].starting_price, auctions[i].reserve_price);
    }
}

void show_bids(struct auction *auctions, int n) {
    for (int i = 0; i < n; i++) {
        printf("Auction %d bids:\n", auctions[i].id);
        struct bid *current = auctions[i].bids;
        while (current != NULL) {
            printf("    %d: %d\n", current->id, current->amount);
            current = current->next;
        }
    }
}

void show_winner(struct auction *auctions, int n) {
    for (int i = 0; i < n; i++) {
        if (auctions[i].winner_id == -1) {
            printf("Auction %d did not have a winner.\n", auctions[i].id);
        } else {
            printf("Auction %d winner is %d with a bid of %d.\n", auctions[i].id, auctions[i].winner_id, auctions[i].highest_bid);
        }
    }
}

int main() {
    struct auction auctions[MAX_AUCTIONS];
    start_auction(auctions, MAX_AUCTIONS);
    int n;
    do {
        print_menu();
        scanf("%d", &n);
        switch (n) {
            case 1:
                start_auction(auctions, MAX_AUCTIONS);
                break;
            case 2:
                place_bid(auctions, MAX_AUCTIONS);
                break;
            case 3:
                end_auction(auctions, MAX_AUCTIONS);
                break;
            case 4:
                show_auctions(auctions, MAX_AUCTIONS);
                break;
            case 5:
                show_bids(auctions, MAX_AUCTIONS);
                break;
            case 6:
                show_winner(auctions, MAX_AUCTIONS);
                break;
            case 7:
                break;
            default:
                printf("Invalid option.\n");
                break;
        }
    } while (n != 7);
    return 0;
}
//FormAI DATASET v1.0 Category: Digital Auction System ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/* Define structs */
typedef struct {
    int id;
    char name[50];
    float starting_price;
    float current_price;
    int seller_id;
    int buyer_id;
    int time_left;
} Auction;

typedef struct {
    int id;
    char name[50];
} User;

/* Define global variables */
Auction *auctions = NULL;
User *users = NULL;
int num_auctions = 0;
int num_users = 0;

/* Define functions */
void add_auction() {
    Auction new_auction;
    printf("Enter item name: ");
    scanf("%s", new_auction.name);
    printf("Enter starting price: ");
    scanf("%f", &new_auction.starting_price);
    new_auction.current_price = new_auction.starting_price;
    printf("Enter seller id: ");
    scanf("%d", &new_auction.seller_id);
    new_auction.buyer_id = -1; // no buyer yet
    new_auction.time_left = 60; // 60 seconds
    new_auction.id = num_auctions + 1;
    num_auctions++;
    auctions = realloc(auctions, num_auctions * sizeof(Auction));
    auctions[num_auctions - 1] = new_auction;
    printf("Auction added successfully.\n");
}

void bid_on_auction(int auction_id, int user_id, float amount) {
    /* Find the auction */
    Auction *auction = NULL;
    for (int i = 0; i < num_auctions; i++) {
        if (auctions[i].id == auction_id) {
            auction = &auctions[i];
            break;
        }
    }
    if (auction == NULL) {
        printf("Auction not found.\n");
        return;
    }
    /* Check if the user can bid */
    if (user_id == auction->seller_id) {
        printf("You cannot bid on your own auction.\n");
        return;
    }
    if (amount <= auction->current_price) {
        printf("Bid must be higher than the current price.\n");
        return;
    }
    /* Update the auction */
    auction->current_price = amount;
    auction->buyer_id = user_id;
    auction->time_left = 60; // reset the time left
    printf("Bid accepted.\n");
}

void print_auctions() {
    printf("ID\tItem\t\tStarting Price\tCurrent Price\tSeller ID\tBuyer ID\tTime Left\n");
    for (int i = 0; i < num_auctions; i++) {
        printf("%d\t%-15s\t%.2f\t\t%.2f\t\t%d\t\t", auctions[i].id, auctions[i].name, auctions[i].starting_price, auctions[i].current_price, auctions[i].seller_id);
        if (auctions[i].buyer_id == -1) {
            printf("-\t\t");
        } else {
            printf("%d\t\t", auctions[i].buyer_id);
        }
        printf("%d seconds\n", auctions[i].time_left);
    }
}

void time_tick() {
    /* Loop through all auctions and decrement time_left */
    for (int i = 0; i < num_auctions; i++) {
        if (auctions[i].time_left > 0) {
            auctions[i].time_left--;
        }
    }
    /* Check for expired auctions */
    for (int i = 0; i < num_auctions; i++) {
        if (auctions[i].time_left == 0) {
            printf("Auction for item %s has ended.\n", auctions[i].name);
            if (auctions[i].buyer_id == -1) {
                printf("No bids were placed for this item.\n");
            } else {
                printf("Item sold to user %d for %.2f.\n", auctions[i].buyer_id, auctions[i].current_price);
            }
            /* Remove the auction from the array */
            for (int j = i; j < num_auctions - 1; j++) {
                auctions[j] = auctions[j+1];
            }
            num_auctions--;
            auctions = realloc(auctions, num_auctions * sizeof(Auction));
        }
    }
}

int main() {
    int choice;
    while (1) {
        /* Print menu */
        printf("1. Add auction\n");
        printf("2. Bid on auction\n");
        printf("3. Print all auctions\n");
        printf("4. Time tick (1 second)\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        printf("\n");
        /* Process user choice */
        switch (choice) {
            case 1:
                add_auction();
                break;
            case 2:
                printf("Enter auction id: ");
                int auction_id;
                scanf("%d", &auction_id);
                printf("Enter user id: ");
                int user_id;
                scanf("%d", &user_id);
                printf("Enter bid amount: ");
                float amount;
                scanf("%f", &amount);
                bid_on_auction(auction_id, user_id, amount);
                break;
            case 3:
                print_auctions();
                break;
            case 4:
                time_tick();
                break;
            case 5:
                printf("Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice. Try again.\n");
        }
        printf("\n");
    }
}
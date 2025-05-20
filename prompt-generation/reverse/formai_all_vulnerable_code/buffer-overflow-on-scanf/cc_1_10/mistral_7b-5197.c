//MISTRAL-7B DATASET v1.0 Category: Digital Auction System ; Style: satisfied
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_BIDDERS 10
#define MAX_BID_SIZE 50

typedef struct {
    char name[50];
    int bid;
} Bidder;

void print_menu() {
    printf("\n---- Digital Auction System ----\n");
    printf("1. Register as a bidder\n");
    printf("2. Place a bid\n");
    printf("3. Display current highest bid and bidder\n");
    printf("4. Exit\n");
}

Bidder highest_bidder[MAX_BIDDERS];
int num_bidders = 0;
int highest_bid = 0;

void register_bidder(char *name) {
    if (num_bidders >= MAX_BIDDERS) {
        printf("Sorry, maximum number of bidders reached!\n");
        return;
    }
    strcpy(highest_bidder[num_bidders].name, name);
    highest_bidder[num_bidders].bid = 0;
    num_bidders++;
}

void place_bid(int item_value, char *name, int bid) {
    int i;
    for (i = 0; i < num_bidders; i++) {
        if (strcmp(highest_bidder[i].name, name) == 0) {
            if (bid > highest_bid) {
                highest_bid = bid;
                highest_bidder[i].bid = bid;
            }
            printf("Bid placed successfully!\n");
            return;
        }
    }
    register_bidder(name);
    highest_bidder[num_bidders - 1].bid = bid;
    highest_bid = bid;
    printf("Bidder %s registered and placed bid of %d\n", name, bid);
}

void display_highest_bid() {
    printf("Current highest bid: %d by %s\n", highest_bid, highest_bidder[num_bidders - 1].name);
}

int main() {
    char name[50];
    int item_value, bid;

    while (1) {
        print_menu();
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter your name: ");
                scanf("%s", name);
                register_bidder(name);
                break;
            case 2:
                printf("Enter item value: ");
                scanf("%d", &item_value);
                printf("Enter your name: ");
                scanf("%s", name);
                printf("Enter your bid: ");
                scanf("%d", &bid);
                place_bid(item_value, name, bid);
                break;
            case 3:
                display_highest_bid();
                break;
            case 4:
                printf("Thank you for using our Digital Auction System. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
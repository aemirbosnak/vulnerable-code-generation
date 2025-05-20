//Falcon-180B DATASET v1.0 Category: Digital Auction System ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ITEMS 100
#define MAX_BIDDERS 50
#define MAX_BIDS 1000

typedef struct {
    char name[50];
    int bid;
} Bidder;

typedef struct {
    char name[50];
    int price;
} Item;

void generate_random_string(char* str, int len) {
    for (int i = 0; i < len; i++) {
        str[i] = 'a' + rand() % 26;
    }
    str[len] = '\0';
}

int main() {
    srand(time(NULL));

    Item items[MAX_ITEMS];
    Bidder bidders[MAX_BIDDERS];
    int num_items = 0, num_bidders = 0;

    while (num_items < MAX_ITEMS && num_bidders < MAX_BIDDERS) {
        printf("Enter the name of the item (%d characters max): ", MAX_ITEMS - num_items);
        scanf("%s", items[num_items].name);
        printf("Enter the starting price for the item: ");
        scanf("%d", &items[num_items].price);
        num_items++;
    }

    while (num_bidders < MAX_BIDDERS) {
        printf("Enter the name of the bidder (%d characters max): ", MAX_BIDDERS - num_bidders);
        scanf("%s", bidders[num_bidders].name);
        num_bidders++;
    }

    int max_bid = 0;
    for (int i = 0; i < num_items; i++) {
        printf("Bidding for item '%s' starts at $%d.\n", items[i].name, items[i].price);
        for (int j = 0; j < num_bidders; j++) {
            printf("Bidder '%s' bids $%d.\n", bidders[j].name, items[i].price);
            if (items[i].price < max_bid) {
                max_bid = items[i].price;
                items[i].price = max_bid + 1;
            }
        }
    }

    printf("\nAuction results:\n");
    for (int i = 0; i < num_items; i++) {
        printf("Item '%s' sold for $%d to bidder '%s'.\n", items[i].name, items[i].price, bidders[i % num_bidders].name);
    }

    return 0;
}
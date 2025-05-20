//Falcon-180B DATASET v1.0 Category: Digital Auction System ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ITEMS 100
#define MAX_BIDDERS 100

typedef struct {
    char name[50];
    int id;
    int max_bid;
} Bidder;

typedef struct {
    char name[100];
    int id;
    int current_bid;
    Bidder* highest_bidder;
} Item;

Bidder* create_bidder(char* name) {
    Bidder* bidder = (Bidder*)malloc(sizeof(Bidder));
    strcpy(bidder->name, name);
    bidder->id = rand() % 1000;
    bidder->max_bid = 0;
    return bidder;
}

void place_bid(Item* item, Bidder* bidder, int amount) {
    if(item->current_bid < amount && amount <= bidder->max_bid) {
        item->current_bid = amount;
        item->highest_bidder = bidder;
    }
}

int main() {
    srand(time(NULL));

    Bidder bidders[MAX_BIDDERS];
    int num_bidders = 0;

    Item items[MAX_ITEMS];
    int num_items = 0;

    char choice;
    while(1) {
        printf("Digital Auction System\n");
        printf("1. Create item\n");
        printf("2. Place bid\n");
        printf("3. View items\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%c", &choice);

        switch(choice) {
            case '1':
                printf("Enter item name: ");
                scanf("%s", items[num_items].name);
                items[num_items].id = rand() % 1000;
                items[num_items].current_bid = 0;
                items[num_items].highest_bidder = NULL;
                num_items++;
                break;
            case '2':
                printf("Enter bidder name: ");
                scanf("%s", bidders[num_bidders].name);
                bidders[num_bidders].id = rand() % 1000;
                bidders[num_bidders].max_bid = 0;
                num_bidders++;
                break;
            case '3':
                printf("Item ID\tItem Name\tCurrent Bid\tHighest Bidder\n");
                for(int i=0; i<num_items; i++) {
                    printf("%d\t%s\t%d\t", items[i].id, items[i].name, items[i].current_bid);
                    if(items[i].highest_bidder!= NULL) {
                        printf("%s\n", items[i].highest_bidder->name);
                    } else {
                        printf("No bids yet\n");
                    }
                }
                break;
            case '4':
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
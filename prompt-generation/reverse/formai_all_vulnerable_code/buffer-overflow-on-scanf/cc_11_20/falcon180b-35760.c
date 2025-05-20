//Falcon-180B DATASET v1.0 Category: Digital Auction System ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_BIDDERS 100
#define MAX_BIDS 1000
#define MAX_ITEM_NAME 100
#define MAX_BIDDER_NAME 100

typedef struct {
    char name[MAX_ITEM_NAME];
    int value;
    int highest_bid;
    int highest_bidder;
} Item;

typedef struct {
    char name[MAX_BIDDER_NAME];
    int bid;
} Bidder;

int main() {
    srand(time(0));

    Item items[MAX_ITEMS];
    Bidder bidders[MAX_BIDDERS];
    int num_items = 0;
    int num_bidders = 0;

    char choice;
    int item_index, bidder_index;

    do {
        system("clear");
        printf("Digital Auction System\n\n");
        printf("A) Add item\n");
        printf("B) Add bidder\n");
        printf("C) Start auction\n");
        printf("D) View items\n");
        printf("E) View bidders\n");
        printf("F) Quit\n");
        printf("\n");

        scanf("%c", &choice);

        switch(choice) {
            case 'a':
                if(num_items >= MAX_ITEMS) {
                    printf("Maximum number of items reached.\n");
                } else {
                    printf("Enter item name: ");
                    scanf("%s", items[num_items].name);
                    printf("Enter item value: ");
                    scanf("%d", &items[num_items].value);
                    items[num_items].highest_bid = 0;
                    items[num_items].highest_bidder = -1;
                    num_items++;
                }
                break;

            case 'b':
                if(num_bidders >= MAX_BIDDERS) {
                    printf("Maximum number of bidders reached.\n");
                } else {
                    printf("Enter bidder name: ");
                    scanf("%s", bidders[num_bidders].name);
                    num_bidders++;
                }
                break;

            case 'c':
                if(num_items == 0) {
                    printf("No items to auction.\n");
                } else {
                    int i;
                    for(i=0; i<num_items; i++) {
                        printf("%d. %s - Current bid: $%d by %d\n", i+1, items[i].name, items[i].highest_bid, items[i].highest_bidder+1);
                    }
                    printf("\n");
                }
                break;

            case 'd':
                if(num_bidders == 0) {
                    printf("No bidders registered.\n");
                } else {
                    int i;
                    for(i=0; i<num_bidders; i++) {
                        printf("%d. %s\n", i+1, bidders[i].name);
                    }
                    printf("\n");
                }
                break;

            case 'e':
                if(num_items == 0) {
                    printf("No items to auction.\n");
                } else {
                    int i;
                    for(i=0; i<num_items; i++) {
                        printf("%s - Value: $%d\n", items[i].name, items[i].value);
                    }
                    printf("\n");
                }
                break;

            case 'f':
                exit(0);

            default:
                printf("Invalid choice.\n");
        }

    } while(choice!= 'f');

    return 0;
}
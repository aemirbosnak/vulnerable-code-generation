//Falcon-180B DATASET v1.0 Category: Digital Auction System ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ITEMS 100
#define MAX_BIDDERS 100

typedef struct {
    char name[50];
    int id;
    int highest_bid;
} bidder;

typedef struct {
    char name[100];
    int id;
    int starting_price;
    int current_price;
    bidder* highest_bidder;
} item;

void display_menu() {
    printf("\nDigital Auction System\n");
    printf("1. Register as a bidder\n");
    printf("2. View items for auction\n");
    printf("3. Place a bid\n");
    printf("4. View highest bids\n");
    printf("5. Exit\n");
}

int main() {
    int choice;
    char ch;
    int num_bidders = 0;
    int num_items = 0;
    bidder bidders[MAX_BIDDERS];
    item items[MAX_ITEMS];

    srand(time(NULL));

    do {
        system("clear");
        display_menu();
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                if (num_bidders >= MAX_BIDDERS) {
                    printf("Maximum number of bidders reached.\n");
                } else {
                    printf("Enter your name: ");
                    scanf("%s", bidders[num_bidders].name);
                    bidders[num_bidders].id = num_bidders + 1;
                    num_bidders++;
                }
                break;
            case 2:
                if (num_items == 0) {
                    printf("No items available for auction.\n");
                } else {
                    for (int i = 0; i < num_items; i++) {
                        printf("%d. %s - Current Price: $%d\n", i+1, items[i].name, items[i].current_price);
                    }
                }
                break;
            case 3:
                if (num_items == 0) {
                    printf("No items available for auction.\n");
                } else {
                    int item_id;
                    printf("Enter the ID of the item you want to bid on: ");
                    scanf("%d", &item_id);

                    for (int i = 0; i < num_items; i++) {
                        if (items[i].id == item_id) {
                            printf("Enter your bid: ");
                            scanf("%d", &items[i].current_price);
                            items[i].highest_bidder = &bidders[0];
                            for (int j = 1; j < num_bidders; j++) {
                                if (bidders[j].highest_bid > items[i].current_price) {
                                    items[i].highest_bidder = &bidders[j];
                                    items[i].current_price = bidders[j].highest_bid;
                                }
                            }
                            break;
                        }
                    }
                }
                break;
            case 4:
                if (num_items == 0) {
                    printf("No items available for auction.\n");
                } else {
                    for (int i = 0; i < num_items; i++) {
                        printf("%d. %s - Highest Bid: $%d by %s\n", i+1, items[i].name, items[i].current_price, items[i].highest_bidder->name);
                    }
                }
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }

        printf("\nPress any key to continue...");
        scanf(" %c", &ch);
    } while (1);

    return 0;
}
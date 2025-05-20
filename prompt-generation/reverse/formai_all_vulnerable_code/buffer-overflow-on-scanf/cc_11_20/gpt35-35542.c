//FormAI DATASET v1.0 Category: Digital Auction System ; Style: futuristic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ITEMS 50
#define MAX_NAME_LEN 20
#define MAX_DESC_LEN 50

typedef struct {
    int id;
    char name[MAX_NAME_LEN];
    char desc[MAX_DESC_LEN];
    double min_price;
    double highest_bid;
    char highest_bidder[MAX_NAME_LEN];
} Auction;

int main() {
    Auction items[MAX_ITEMS];
    int num_items = 0;
    int menu_option;
    srand(time(NULL));

    printf("***Welcome to the Digital Auction System***\n");

    do {
        printf("\nMenu:\n");
        printf("1. Add item\n");
        printf("2. View items\n");
        printf("3. Make a bid\n");
        printf("4. Quit\n");
        printf("Choose an option: ");
        scanf("%d", &menu_option);

        switch (menu_option) {
            case 1: {
                printf("\nAdd Item\n");
                if (num_items == MAX_ITEMS) {
                    printf("Sorry, you cannot add any more items.\n");
                } else {
                    Auction item;
                    item.id = num_items + 1;
                    printf("Enter item name: ");
                    scanf("%s", item.name);
                    printf("Enter item description: ");
                    scanf("%s", item.desc);
                    printf("Enter minimum price: ");
                    scanf("%lf", &item.min_price);
                    item.highest_bid = item.min_price;
                    strcpy(item.highest_bidder, "None");
                    items[num_items++] = item;
                    printf("Item added successfully.\n");
                }
                break;
            }
            case 2: {
                printf("\nView Items\n");
                if (num_items == 0) {
                    printf("No items to display.\n");
                } else {
                    printf("ID\tName\tDescription\tMinimum Price\tHighest Bid\tHighest Bidder\n");
                    for (int i = 0; i < num_items; i++) {
                        printf("%d\t%s\t%s\t%.2lf\t\t%.2lf\t\t%s\n", items[i].id, items[i].name, items[i].desc, items[i].min_price, items[i].highest_bid, items[i].highest_bidder);
                    }
                }
                break;
            }
            case 3: {
                printf("\nMake a Bid\n");
                if (num_items == 0) {
                    printf("No items to bid on.\n");
                } else {
                    int item_id;
                    printf("Enter item ID: ");
                    scanf("%d", &item_id);
                    int item_index = -1;
                    for (int i = 0; i < num_items; i++) {
                        if (items[i].id == item_id) {
                            item_index = i;
                            break;
                        }
                    }
                    if (item_index == -1) {
                        printf("Invalid item ID.\n");
                    } else {
                        double bid_amount;
                        printf("Enter bid amount: ");
                        scanf("%lf", &bid_amount);
                        if (bid_amount > items[item_index].highest_bid) {
                            strcpy(items[item_index].highest_bidder, "Bidder Name");
                            items[item_index].highest_bid = bid_amount;
                            printf("Bid accepted.\n");
                        } else {
                            printf("Bid amount must be higher than current highest bid.\n");
                        }
                    }
                }
                break;
            }
            case 4: {
                printf("\nExiting...\n");
                break;
            }
            default: {
                printf("\nInvalid option.\n");
            }
        }
    } while (menu_option != 4);

    return 0;
}
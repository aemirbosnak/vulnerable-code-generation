//FormAI DATASET v1.0 Category: Digital Auction System ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 10
#define MAX_BIDS 5

struct Item {
    char name[50];
    char description[100];
    int id;
    double price;
    int num_bids;
    double bids[MAX_BIDS];
};

struct Auction {
    struct Item items[MAX_ITEMS];
    int num_items;
};

int main() {
    struct Auction auction;
    int choice, id, i, j;
    double bid;
    char name[50], description[100];

    auction.num_items = 0;

    while (1) {
        printf("\n1. Add item\n");
        printf("2. View items\n");
        printf("3. Bid on item\n");
        printf("4. Exit\n");
        printf("Enter your choice : ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (auction.num_items >= MAX_ITEMS) {
                    printf("Sorry, you cannot add more items.\n");
                    break;
                }

                printf("Enter item name : ");
                scanf("%s", name);
                printf("Enter item description : ");
                scanf("%s", description);

                struct Item item = {"", "", 0, 0, 0};
                strcpy(item.name, name);
                strcpy(item.description, description);
                item.id = auction.num_items + 1;

                printf("Enter starting price : ");
                scanf("%lf", &item.price);

                auction.items[auction.num_items++] = item;

                printf("Item added successfully.\n");
                break;

            case 2:
                if (auction.num_items == 0) {
                    printf("There are no items to view.\n");
                    break;
                }

                printf("ID\tName\tDescription\tPrice\tNumber of Bids\n");
                for (i = 0; i < auction.num_items; i++) {
                    printf("%d\t%s\t%s\t%.2lf\t%d\n",
                           auction.items[i].id, auction.items[i].name, auction.items[i].description,
                           auction.items[i].price, auction.items[i].num_bids);
                }
                break;

            case 3:
                if (auction.num_items == 0) {
                    printf("There are no items to bid on.\n");
                    break;
                }

                printf("Enter item ID : ");
                scanf("%d", &id);

                for (i = 0; i < auction.num_items; i++) {
                    if (auction.items[i].id == id) {
                        struct Item item = auction.items[i];
                        printf("Current highest bid : %.2lf\n", item.bids[item.num_bids - 1]);
                        printf("Enter bid amount : ");
                        scanf("%lf", &bid);

                        if (bid > item.price && bid > item.bids[item.num_bids - 1]) {
                            item.bids[item.num_bids++] = bid;
                            printf("Bid accepted.\n");
                            auction.items[i] = item;
                        } else {
                            printf("Bid amount must be higher than current highest bid and starting price.\n");
                        }

                        break;
                    }
                }

                if (i == auction.num_items) {
                    printf("Item not found.\n");
                }

                break;

            case 4:
                printf("Thank you for using the digital auction system.\n");
                exit(0);

            default:
                printf("Invalid choice.\n");
                break;
        }
    }

    return 0;
}
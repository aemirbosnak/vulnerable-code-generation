//Falcon-180B DATASET v1.0 Category: Digital Auction System ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_BIDDERS 50

struct item {
    char name[50];
    int starting_price;
};

struct bidder {
    char name[50];
    int highest_bid;
};

void display_menu() {
    printf("1. Add item\n");
    printf("2. Add bidder\n");
    printf("3. Start auction\n");
    printf("4. View current bids\n");
    printf("5. Exit\n");
}

int main() {
    int choice, i, j;
    char input[50];
    struct item items[MAX_ITEMS];
    int num_items = 0;
    struct bidder bidders[MAX_BIDDERS];
    int num_bidders = 0;

    while(1) {
        display_menu();
        scanf("%s", input);
        choice = atoi(input);

        switch(choice) {
            case 1:
                if(num_items >= MAX_ITEMS) {
                    printf("Maximum number of items reached.\n");
                    break;
                }

                printf("Enter item name: ");
                scanf("%s", items[num_items].name);
                printf("Enter starting price: ");
                scanf("%d", &items[num_items].starting_price);
                num_items++;
                break;

            case 2:
                if(num_bidders >= MAX_BIDDERS) {
                    printf("Maximum number of bidders reached.\n");
                    break;
                }

                printf("Enter bidder name: ");
                scanf("%s", bidders[num_bidders].name);
                num_bidders++;
                break;

            case 3:
                for(i=0; i<num_items; i++) {
                    printf("Item %d: %s, starting price $%d\n", i+1, items[i].name, items[i].starting_price);
                }

                for(j=0; j<num_bidders; j++) {
                    printf("Bidder %d: %s\n", j+1, bidders[j].name);
                }

                break;

            case 4:
                for(i=0; i<num_items; i++) {
                    printf("Item %d: %s, highest bid $%d by %s\n", i+1, items[i].name, items[i].starting_price, "");
                }

                break;

            case 5:
                exit(0);

            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}
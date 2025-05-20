//FormAI DATASET v1.0 Category: Digital Auction System ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct item {
    char name[20];
    int quantity;
    int auction_id;
    float start_bid;
    float curr_high_bid;
    char high_bidder[20];
    int time_left;
};

int main() {
    struct item items[5];
    int choice, auction_choice, bid_choice, count = 0;

    while(1) {
        printf("Welcome to the Digital Auction System\n");
        printf("1. Add new item\n");
        printf("2. Start auction\n");
        printf("3. Place bid\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                if(count < 5) {
                    printf("Enter item name: ");
                    scanf("%s", &items[count].name);
                    printf("Enter quantity: ");
                    scanf("%d", &items[count].quantity);
                    printf("Enter starting bid: ");
                    scanf("%f", &items[count].start_bid);
                    items[count].curr_high_bid = items[count].start_bid;
                    printf("Item added successfully!\n");
                    items[count].auction_id = count;
                    count++;
                } else {
                    printf("Maximum items limit reached.\n");
                }
                break;

            case 2:
                printf("Enter auction ID: ");
                scanf("%d", &auction_choice);
                if(auction_choice < count) {
                    printf("Auction of %s has started!\n", items[auction_choice].name);
                    printf("Starting bid: %.2f\n", items[auction_choice].start_bid);
                    printf("Time left: %d minutes\n", items[auction_choice].time_left);
                } else {
                    printf("Invalid auction ID.\n");
                }
                break;

            case 3:
                printf("Enter auction ID: ");
                scanf("%d", &bid_choice);
                if(bid_choice < count) {
                    printf("Current highest bid: %.2f by %s\n", items[bid_choice].curr_high_bid, items[bid_choice].high_bidder);
                    printf("Enter your bid: ");
                    float new_bid;
                    scanf("%f", &new_bid);
                    if(new_bid > items[bid_choice].curr_high_bid) {
                        printf("Congratulations! You are the new highest bidder!\n");
                        strcpy(items[bid_choice].high_bidder, "You");
                        items[bid_choice].curr_high_bid = new_bid;
                    } else {
                        printf("Sorry, your bid is too low.\n");
                    }
                } else {
                    printf("Invalid auction ID.\n");
                }
                break;

            case 4:
                printf("Thank you for using the Digital Auction System.\n");
                exit(0);
                break;

            default:
                printf("Invalid choice.\n");
                break;
        }
    }

    return 0;
}
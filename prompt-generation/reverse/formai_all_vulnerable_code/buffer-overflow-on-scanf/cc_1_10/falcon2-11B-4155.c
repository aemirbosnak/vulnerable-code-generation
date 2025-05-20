//Falcon2-11B DATASET v1.0 Category: Digital Auction System ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 100

typedef struct {
    char name[MAX_LENGTH];
    int price;
    int bidCount;
} Bidder;

int main() {
    Bidder bidder1 = {"Bidder 1", 50, 0};
    Bidder bidder2 = {"Bidder 2", 100, 0};

    printf("Welcome to the Digital Auction System!\n");

    int choice, bid = 0;
    int bidder_count = 2;

    while (1) {
        printf("\n1. View current bids\n2. Place a bid\n3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Current bids:\n");
                printf("Bidder 1: %s - $%d\n", bidder1.name, bidder1.price);
                printf("Bidder 2: %s - $%d\n", bidder2.name, bidder2.price);
                break;

            case 2:
                printf("Enter your bid amount: ");
                scanf("%d", &bid);

                if (bid > bidder1.price) {
                    bidder1.price = bid;
                    bidder1.bidCount++;
                } else if (bid > bidder2.price) {
                    bidder2.price = bid;
                    bidder2.bidCount++;
                } else {
                    printf("Invalid bid. Please try again.\n");
                }

                printf("Bidder 1: %s - $%d\n", bidder1.name, bidder1.price);
                printf("Bidder 2: %s - $%d\n", bidder2.name, bidder2.price);
                break;

            case 3:
                printf("Thank you for using the Digital Auction System! Goodbye.\n");
                exit(0);
                break;

            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}
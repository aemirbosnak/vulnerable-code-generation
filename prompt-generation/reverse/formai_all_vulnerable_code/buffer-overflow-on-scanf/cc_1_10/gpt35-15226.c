//FormAI DATASET v1.0 Category: Digital Auction System ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>

// Define a struct for the auction item
typedef struct {
    int id;
    char name[20];
    float current_price;
    int highest_bidder_id;
} AuctionItem;

// Define a function to display the auction item details
void display_item(AuctionItem item) {
    printf("ID: %d\n", item.id);
    printf("Name: %s\n", item.name);
    printf("Current Price: $%.2f\n", item.current_price);
    printf("Highest Bidder ID: %d\n\n", item.highest_bidder_id);
}

int main() {
    AuctionItem item;
    item.id = 1;
    strcpy(item.name, "Guitar");
    item.current_price = 100.00;

    // Start the auction
    printf("Welcome to the digital auction system!\n\n");
    printf("The auction for the following item is now open:\n");
    display_item(item);

    // Allow users to bid on the item
    int bidder_id;
    float bid_amount;

    while (1) {
        printf("Enter your bidder ID (0 to quit): ");
        scanf("%d", &bidder_id);

        if (bidder_id == 0) {
            break;
        }

        printf("Enter your bid amount (minimum: $%.2f): ", item.current_price + 1.00);
        scanf("%f", &bid_amount);

        if (bid_amount < item.current_price + 1.00) {
            printf("Error: Bid amount is too low!\n");
            continue;
        }

        item.current_price = bid_amount;
        item.highest_bidder_id = bidder_id;

        printf("Bid accepted!\n");
        display_item(item);
    }

    printf("Thank you for using the digital auction system.\n");
    return 0;
}
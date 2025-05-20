//FormAI DATASET v1.0 Category: Digital Auction System ; Style: configurable
#include <stdio.h>
#include <stdlib.h>

struct auction_item {
    char name[50];
    int starting_price;
    int current_bid;
    char current_bidder[50];
};

int main() {
    struct auction_item item1 = {"Smart TV", 500, 0, ""};
    struct auction_item item2 = {"Gaming Laptop", 800, 0, ""};
    
    printf("Welcome to the Digital Auction System\n\n");
    printf("Items for auction:\n");
    printf("1. %s (Starting Price: $%d)\n", item1.name, item1.starting_price);
    printf("2. %s (Starting Price: $%d)\n", item2.name, item2.starting_price);
    
    int choice, new_bid;
    char bidder_name[50];
    
    do {
        printf("\nEnter your choice (1 or 2): ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                printf("\nEnter your bid for %s: $", item1.name);
                scanf("%d", &new_bid);
                if (new_bid > item1.current_bid) {
                    item1.current_bid = new_bid;
                    printf("Congratulations! You are the highest bidder for %s\n", item1.name);
                    printf("Please provide your name: ");
                    scanf("%s", bidder_name);
                    strcpy(item1.current_bidder, bidder_name);
                } else {
                    printf("Sorry, your bid is not high enough. Please try again.\n");
                }
                break;
            
            case 2:
                printf("\nEnter your bid for %s: $", item2.name);
                scanf("%d", &new_bid);
                if (new_bid > item2.current_bid) {
                    item2.current_bid = new_bid;
                    printf("Congratulations! You are the highest bidder for %s\n", item2.name);
                    printf("Please provide your name: ");
                    scanf("%s", bidder_name);
                    strcpy(item2.current_bidder, bidder_name);
                } else {
                    printf("Sorry, your bid is not high enough. Please try again.\n");
                }
                break;
            
            default:
                printf("Invalid choice. Please choose again.\n");
        }
    } while (item1.current_bid == 0 || item2.current_bid == 0);
    
    printf("\n\nResults of the auction:\n");
    if (item1.current_bid > item2.current_bid) {
        printf("%s is sold to %s for $%d\n", item1.name, item1.current_bidder, item1.current_bid);
        printf("%s is unsold\n", item2.name);
    } else {
        printf("%s is sold to %s for $%d\n", item2.name, item2.current_bidder, item2.current_bid);
        printf("%s is unsold\n", item1.name);
    }
    
    return 0;
}
//FormAI DATASET v1.0 Category: Digital Auction System ; Style: futuristic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct auction_item {
    char item_name[100];
    int item_code;
    int current_bid;
    int min_bid;
    char bidder_name[100];
};

// Function to display the details of current bid
void display_bid(struct auction_item *item) {
    printf("\nCurrent Bid: %d\n", item->current_bid);
    printf("Minimum Bid: %d\n", item->min_bid);
    printf("Bidder Name: %s\n", item->bidder_name);
}

int main() {
    struct auction_item item1, item2, item3;

    // Initializing the details of auction items
    strcpy(item1.item_name, "Futuristic Flying Car");
    item1.item_code = 1234;
    item1.current_bid = 0;
    item1.min_bid = 100;
    strcpy(item1.bidder_name, "No Bids Yet");

    strcpy(item2.item_name, "Intergalactic Spaceship");
    item2.item_code = 5678;
    item2.current_bid = 0;
    item2.min_bid = 500;
    strcpy(item2.bidder_name, "No Bids Yet");

    strcpy(item3.item_name, "Time Machine");
    item3.item_code = 9101;
    item3.current_bid = 0;
    item3.min_bid = 1000;
    strcpy(item3.bidder_name, "No Bids Yet");

    int option, item_choice, bid_amount;
    char bidder[100];

    // Displaying the menu for auction items
    printf("\nWelcome to the Future Auction!");
    printf("\nChoose an Item to Bid on:");
    printf("\n1. %s (Item Code: %d)", item1.item_name, item1.item_code);
    printf("\n2. %s (Item Code: %d)", item2.item_name, item2.item_code);
    printf("\n3. %s (Item Code: %d)", item3.item_name, item3.item_code);

    // Taking input from user for auction item choice
    printf("\nEnter your choice: ");
    scanf("%d", &item_choice);

    // Displaying the details of the chosen item
    if (item_choice == 1) {
        printf("\nYou have chosen %s (Item Code: %d)", item1.item_name, item1.item_code);
        display_bid(&item1);
    }
    else if (item_choice == 2) {
        printf("\nYou have chosen %s (Item Code: %d)", item2.item_name, item2.item_code);
        display_bid(&item2);
    }
    else if (item_choice == 3) {
        printf("\nYou have chosen %s (Item Code: %d)", item3.item_name, item3.item_code);
        display_bid(&item3);
    }
    else {
        printf("\nInvalid Choice!");
        exit(0);
    }

    // Accepting bid amount and bidder name from user
    printf("\nEnter Your Bid Amount: ");
    scanf("%d", &bid_amount);

    printf("Enter Your Name: ");
    scanf("%s", bidder);

    // Checking if the bid amount is greater than the current bid and minimum bid
    if (bid_amount > 0) {
        if (item_choice == 1) {
            if (bid_amount > item1.current_bid && bid_amount >= item1.min_bid) {
                item1.current_bid = bid_amount;
                strcpy(item1.bidder_name, bidder);
                printf("\nCongratulations! You are the highest bidder for %s (Item Code: %d)", item1.item_name, item1.item_code);
                display_bid(&item1);
            }
            else {
                printf("\nSorry! Your bid was not accepted for %s (Item Code: %d)", item1.item_name, item1.item_code);
            }
        }
        else if (item_choice == 2) {
            if (bid_amount > item2.current_bid && bid_amount >= item2.min_bid) {
                item2.current_bid = bid_amount;
                strcpy(item2.bidder_name, bidder);
                printf("\nCongratulations! You are the highest bidder for %s (Item Code: %d)", item2.item_name, item2.item_code);
                display_bid(&item2);
            }
            else {
                printf("\nSorry! Your bid was not accepted for %s (Item Code: %d)", item2.item_name, item2.item_code);
            }
        }
        else if (item_choice == 3) {
            if (bid_amount > item3.current_bid && bid_amount >= item3.min_bid) {
                item3.current_bid = bid_amount;
                strcpy(item3.bidder_name, bidder);
                printf("\nCongratulations! You are the highest bidder for %s (Item Code: %d)", item3.item_name, item3.item_code);
                display_bid(&item3);
            }
            else {
                printf("\nSorry! Your bid was not accepted for %s (Item Code: %d)", item3.item_name, item3.item_code);
            }
        }
        else {
            printf("\nInvalid Choice!");
            exit(0);
        }
    }
    else {
        printf("\nInvalid Bid Amount!");
        exit(0);
    }

    return 0;
}
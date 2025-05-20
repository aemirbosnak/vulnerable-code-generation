//Code Llama-13B DATASET v1.0 Category: Digital Auction System ; Style: multiplayer
// C Digital Auction System
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Global Variables
int bid_amount = 0;
int highest_bidder = 0;
int highest_bid = 0;

// Function to display the menu
void display_menu() {
    printf("Welcome to the Digital Auction System\n");
    printf("1. Place a bid\n");
    printf("2. View the current bid\n");
    printf("3. Exit\n");
}

// Function to place a bid
void place_bid() {
    printf("Enter your bid amount: ");
    scanf("%d", &bid_amount);
    if (bid_amount > highest_bid) {
        highest_bid = bid_amount;
        highest_bidder = 1;
    }
}

// Function to view the current bid
void view_bid() {
    printf("The current bid is: %d\n", highest_bid);
    printf("The highest bidder is: %d\n", highest_bidder);
}

// Main function
int main() {
    int choice = 0;
    while (choice != 3) {
        display_menu();
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                place_bid();
                break;
            case 2:
                view_bid();
                break;
            case 3:
                printf("Exiting the program...\n");
                break;
            default:
                printf("Invalid choice, please try again\n");
                break;
        }
    }
    return 0;
}
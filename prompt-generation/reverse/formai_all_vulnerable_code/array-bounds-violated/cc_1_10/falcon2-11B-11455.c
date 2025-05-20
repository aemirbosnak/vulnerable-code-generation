//Falcon2-11B DATASET v1.0 Category: Digital Auction System ; Style: careful
#include <stdio.h>

// Define the maximum number of bidders
#define MAX_BIDDERS 5

// Declare an array to store bidder information
int bidder[MAX_BIDDERS][2]; // bidder ID (0-indexed), bid amount

// Function to display menu options
void displayMenu() {
    printf("1. Place bid\n");
    printf("2. See top bidder(s)\n");
    printf("3. Exit\n");
}

// Function to process user input
void processInput(int choice) {
    int id = 0;
    int bid = 0;

    // Get bidder ID and bid amount
    printf("Enter bidder ID (0-%d): ", MAX_BIDDERS);
    scanf("%d", &id);
    printf("Enter bid amount: ");
    scanf("%d", &bid);

    // Check if valid choice
    if (choice == 1) {
        // Check if ID is within range
        if (id >= 0 && id <= MAX_BIDDERS) {
            // Update bidder information
            bidder[id][0] = id;
            bidder[id][1] = bid;
            printf("Bid placed successfully!\n");
        } else {
            printf("Invalid bidder ID\n");
        }
    } else if (choice == 2) {
        // Find top bidder(s)
        int max_bid = bidder[0][1];
        int top_bidders = 1;

        // Loop through each bidder
        for (int i = 0; i < MAX_BIDDERS; i++) {
            if (bidder[i][1] > max_bid) {
                top_bidders++;
                max_bid = bidder[i][1];
            }
        }

        // Display top bidder(s)
        if (top_bidders == 1) {
            printf("Top bidder: %d with a bid of %d\n", bidder[0][0], bidder[0][1]);
        } else {
            printf("Top bidders: %d with a bid of %d\n", top_bidders, max_bid);
        }
    } else if (choice == 3) {
        printf("Goodbye!\n");
    } else {
        printf("Invalid choice\n");
    }
}

// Main program
int main() {
    int choice = 0;

    // Loop forever
    while (1) {
        // Display menu options
        displayMenu();

        // Get user choice
        printf("Enter choice (1-%d): ", MAX_BIDDERS);
        scanf("%d", &choice);

        // Process input
        processInput(choice);
    }

    return 0;
}
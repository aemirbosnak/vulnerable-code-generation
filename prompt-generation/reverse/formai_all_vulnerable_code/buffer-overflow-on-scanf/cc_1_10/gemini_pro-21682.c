//GEMINI-pro DATASET v1.0 Category: Digital Auction System ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>

// Item structure representing auctioned items
typedef struct item {
    char name[50];
    float starting_bid;
    float current_bid;
    int highest_bidder;
} Item;

// User structure representing registered bidders
typedef struct user {
    char name[50];
    int id;
    float balance;
} User;

// Initialize the system with a demo item and user
Item items[] = {{"Antique Vase", 100.0, 100.0, -1}};
User users[] = {{"John Doe", 1, 1000.0}};

int num_items = 1;
int num_users = 1;

// Function to register a new user
void register_user(User *users, int *num_users) {
    printf("Enter your name: ");
    scanf(" %[^\n]%*c", users[*num_users].name);
    printf("Enter your initial balance (positive value): ");
    scanf("%f", &users[*num_users].balance);
    users[*num_users].id = *num_users;
    (*num_users)++;
}

// Function to place a bid
void place_bid(Item *items, User *users, int num_items, int num_users) {
    int item_index, bidder_index;
    float bid_amount;

    // Display available items
    printf("Available Items:\n");
    for (int i = 0; i < num_items; i++) {
        printf("%d. %s (Current Bid: $%.2f)\n", i+1, items[i].name, items[i].current_bid);
    }

    // Prompt for item and bid amount
    printf("Enter the item number you wish to bid on: ");
    scanf("%d", &item_index);
    printf("Enter your bid amount (must be greater than current bid): ");
    scanf("%f", &bid_amount);

    // Check if item index is valid and bid amount is valid
    if (item_index <= 0 || item_index > num_items || bid_amount <= items[item_index-1].current_bid) {
        printf("Invalid input. Please try again.\n");
        return;
    }

    // Check if the user has sufficient balance
    for (int i = 0; i < num_users; i++) {
        if (bid_amount > users[i].balance) {
            printf("Insufficient balance. Please try again.\n");
            return;
        }
    }

    // Update the bid and highest bidder
    items[item_index-1].current_bid = bid_amount;
    items[item_index-1].highest_bidder = bidder_index;

    // Deduct the bid amount from the bidder's balance
    users[bidder_index].balance -= bid_amount;

    printf("Your bid has been placed successfully.\n");
}

// Function to display the highest bidder and current bid for each item
void display_bids(Item *items, int num_items) {
    printf("Current Bids:\n");
    for (int i = 0; i < num_items; i++) {
        printf("%s: $%.2f (Highest Bidder: %s)\n", items[i].name, items[i].current_bid, users[items[i].highest_bidder].name);
    }
}

// Main function
int main() {
    int choice;

    while (1) {
        printf("\nPlease choose an option:\n");
        printf("1. Register as a new user\n");
        printf("2. Place a bid\n");
        printf("3. Display current bids\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                register_user(users, &num_users);
                break;
            case 2:
                place_bid(items, users, num_items, num_users);
                break;
            case 3:
                display_bids(items, num_items);
                break;
            case 4:
                printf("Thank you for using the Digital Auction System.\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
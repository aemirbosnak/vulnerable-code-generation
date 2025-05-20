//FormAI DATASET v1.0 Category: Digital Auction System ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define struct to store auction items
typedef struct AuctionItem {
    char title[50];
    char description[100];
    int currentBid;
    char seller[50];
} AuctionItem;

// Define struct to store user account information
typedef struct User {
    char username[50];
    char password[50];
    int balance;
} User;

// Define function to return index of auction item in array based on title
int findItemIndex(AuctionItem *items, int numItems, char *title) {
    for (int i = 0; i < numItems; i++) {
        if (strcmp(items[i].title, title) == 0) {
            return i;
        }
    }
    return -1; // If item is not found
}

// Define function to prompt user to input username and password
void getUserLogin(char *username, char *password) {
    printf("Enter username: ");
    scanf("%s", username);
    printf("Enter password: ");
    scanf("%s", password);
}

// Define function to prompt user to input auction item information
void getAuctionItem(AuctionItem *item) {
    printf("Enter title: ");
    scanf("%s", item->title);
    printf("Enter description: ");
    scanf("%s", item->description);
    printf("Enter initial bid: ");
    scanf("%d", &item->currentBid);
    printf("Enter seller's username: ");
    scanf("%s", item->seller);
}

int main() {
    int numItems = 0;
    int numUsers = 2; // Set as default for simplicity
    AuctionItem items[50];
    User users[2] = {{"user1", "password1", 100}, {"user2", "password2", 200}}; // Set as default for simplicity
    int loggedInUserIndex;

    // Prompt user to login or create account
    printf("Welcome to the auction system!\n");
    printf("1. Login\n2. Create account\n");
    int choice;
    scanf("%d", &choice);
    if (choice == 1) {
        // Login
        char username[50];
        char password[50];
        getUserLogin(username, password);
        for (int i = 0; i < numUsers; i++) {
            if (strcmp(users[i].username, username) == 0 && strcmp(users[i].password, password) == 0) {
                loggedInUserIndex = i;
                printf("Login successful!\n");
                break;
            }
            if (i == numUsers - 1) {
                // User not found, exit program
                printf("Invalid username or password.\n");
                return 0;
            }
        }
    } else if (choice == 2) {
        // Create account
        loggedInUserIndex = numUsers; // New user is added to end of array
        printf("Enter desired username: ");
        scanf("%s", users[loggedInUserIndex].username);
        printf("Enter desired password: ");
        scanf("%s", users[loggedInUserIndex].password);
        printf("Account created successfully!\n");
        numUsers++;
    }

    // Prompt user to add or bid on auction items
    while (1) {
        printf("Choose an action:\n1. Add item\n2. Bid on item\n3. List items\n4. Exit\n");
        scanf("%d", &choice);
        if (choice == 1) {
            // Add item
            if (loggedInUserIndex == -1) {
                printf("You must be logged in to perform this action.\n");
                continue;
            }
            AuctionItem newItem;
            getAuctionItem(&newItem);
            items[numItems] = newItem;
            numItems++;
            printf("Item added successfully.\n");
        } else if (choice == 2) {
            // Bid on item
            if (loggedInUserIndex == -1) {
                printf("You must be logged in to perform this action.\n");
                continue;
            }
            char title[50];
            printf("Enter item title: ");
            scanf("%s", title);
            int itemIndex = findItemIndex(items, numItems, title);
            if (itemIndex == -1) {
                printf("Item not found.\n");
                continue;
            }
            int bid;
            printf("Enter bid: ");
            scanf("%d", &bid);
            if (bid <= items[itemIndex].currentBid) {
                printf("Bid must be higher than current bid.\n");
                continue;
            }
            if (bid > users[loggedInUserIndex].balance) {
                printf("Insufficient funds.\n");
                continue;
            }
            items[itemIndex].currentBid = bid;
            strcpy(items[itemIndex].seller, users[loggedInUserIndex].username);
            users[loggedInUserIndex].balance -= bid;
            printf("Bid successful.\n");
        } else if (choice == 3) {
            // List items
            printf("Current items:\n");
            for (int i = 0; i < numItems; i++) {
                printf("Title: %s\nDescription: %s\nCurrent bid: %d\nSeller: %s\n\n", items[i].title, items[i].description, items[i].currentBid, items[i].seller);
            }
        } else if (choice == 4) {
            // Exit
            printf("Goodbye!\n");
            return 0;
        } else {
            // Invalid choice
            printf("Invalid choice.\n");
        }
    }
}
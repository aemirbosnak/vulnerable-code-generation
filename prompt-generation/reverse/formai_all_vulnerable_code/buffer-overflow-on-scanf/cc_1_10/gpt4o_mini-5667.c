//GPT-4o-mini DATASET v1.0 Category: Digital Auction System ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERS 100
#define MAX_ITEMS 100
#define NAME_SIZE 50
#define ITEM_NAME_SIZE 100

typedef struct {
    char name[ITEM_NAME_SIZE];
    float currentBid;
    char highestBidder[NAME_SIZE];
} AuctionItem;

typedef struct {
    char username[NAME_SIZE];
    int isRegistered;
} User;

User users[MAX_USERS];
AuctionItem items[MAX_ITEMS];
int userCount = 0, itemCount = 0;

void registerUser() {
    if (userCount >= MAX_USERS) {
        printf("User limit reached! Cannot register more users.\n");
        return;
    }
    printf("Enter username: ");
    scanf("%s", users[userCount].username);
    users[userCount].isRegistered = 1;
    userCount++;
    printf("User registered successfully!\n");
}

void addAuctionItem() {
    if (itemCount >= MAX_ITEMS) {
        printf("Item limit reached! Cannot add more items.\n");
        return;
    }
    printf("Enter item name: ");
    scanf(" %[^\n]", items[itemCount].name);
    items[itemCount].currentBid = 0.0;
    strcpy(items[itemCount].highestBidder, "None");
    itemCount++;
    printf("Item added successfully!\n");
}

void placeBid() {
    char username[NAME_SIZE];
    printf("Enter your username: ");
    scanf("%s", username);
    int userIndex = -1;

    for (int i = 0; i < userCount; i++) {
        if (strcmp(users[i].username, username) == 0 && users[i].isRegistered) {
            userIndex = i;
            break;
        }
    }

    if (userIndex == -1) {
        printf("User not registered! Please register before placing a bid.\n");
        return;
    }

    int itemIndex;
    printf("Enter item number to bid on (0 to %d): ", itemCount - 1);
    scanf("%d", &itemIndex);

    if (itemIndex < 0 || itemIndex >= itemCount) {
        printf("Invalid item number!\n");
        return;
    }

    float bidAmount;
    printf("Enter your bid amount: ");
    scanf("%f", &bidAmount);

    if (bidAmount <= items[itemIndex].currentBid) {
        printf("Your bid must be higher than the current bid of %.2f!\n", items[itemIndex].currentBid);
        return;
    }

    items[itemIndex].currentBid = bidAmount;
    strcpy(items[itemIndex].highestBidder, username);
    printf("Bid placed successfully!\n");
}

void viewAuctionItems() {
    printf("\nCurrent Auction Items:\n");
    for (int i = 0; i < itemCount; i++) {
        printf("Item %d: %s\n", i, items[i].name);
        printf("Current Bid: %.2f by %s\n", items[i].currentBid, items[i].highestBidder);
    }
}

void displayMenu() {
    printf("\nWelcome to the Digital Auction System!\n");
    printf("1. Register User\n");
    printf("2. Add Auction Item\n");
    printf("3. Place a Bid\n");
    printf("4. View Auction Items\n");
    printf("5. Exit\n");
}

int main() {
    int choice;
    while (1) {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                registerUser();
                break;
            case 2:
                addAuctionItem();
                break;
            case 3:
                placeBid();
                break;
            case 4:
                viewAuctionItems();
                break;
            case 5:
                printf("Exiting the auction system. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}
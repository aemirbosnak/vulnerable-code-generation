//GPT-4o-mini DATASET v1.0 Category: Digital Auction System ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_USERS 10
#define MAX_ITEMS 10

typedef struct {
    char name[50];
    float basePrice;
    float currentBid;
    char highestBidder[50];
} AuctionItem;

typedef struct {
    char username[50];
    float balance;
} User;

AuctionItem items[MAX_ITEMS];
User users[MAX_USERS];
int itemCount = 0;
int userCount = 0;

void addUser();
void addItem();
void placeBid();
void displayItems();
void showMenu();
void clearInputBuffer();

int main() {
    int choice;
    while (1) {
        showMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        clearInputBuffer();
        switch (choice) {
            case 1: addUser(); break;
            case 2: addItem(); break;
            case 3: placeBid(); break;
            case 4: displayItems(); break;
            case 5: exit(0);
            default: printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}

void showMenu() {
    printf("\n==== Digital Auction System ====\n");
    printf("1. Add User\n");
    printf("2. Add Auction Item\n");
    printf("3. Place Bid\n");
    printf("4. Display Auction Items\n");
    printf("5. Exit\n");
}

void addUser() {
    if (userCount >= MAX_USERS) {
        printf("User limit reached!\n");
        return;
    }
    printf("Enter username: ");
    fgets(users[userCount].username, 50, stdin);
    strtok(users[userCount].username, "\n"); // Remove newline
    printf("Enter initial balance: ");
    scanf("%f", &users[userCount].balance);
    clearInputBuffer();
    userCount++;
    printf("User '%s' added successfully!\n", users[userCount - 1].username);
}

void addItem() {
    if (itemCount >= MAX_ITEMS) {
        printf("Item limit reached!\n");
        return;
    }
    printf("Enter item name: ");
    fgets(items[itemCount].name, 50, stdin);
    strtok(items[itemCount].name, "\n"); // Remove newline
    printf("Enter base price: ");
    scanf("%f", &items[itemCount].basePrice);
    items[itemCount].currentBid = items[itemCount].basePrice;
    strcpy(items[itemCount].highestBidder, "None");
    clearInputBuffer();
    itemCount++;
    printf("Item '%s' added successfully!\n", items[itemCount - 1].name);
}

void placeBid() {
    if (itemCount == 0) {
        printf("No auction items available!\n");
        return;
    }
    displayItems();

    int itemIndex;
    printf("Select the item number to bid on: ");
    scanf("%d", &itemIndex);
    itemIndex--; // Convert to 0-based index

    if (itemIndex < 0 || itemIndex >= itemCount) {
        printf("Invalid item selection!\n");
        return;
    }

    char username[50];
    printf("Enter your username: ");
    fgets(username, 50, stdin);
    strtok(username, "\n"); // Remove newline

    // Find user
    int userIndex = -1;
    for (int i = 0; i < userCount; i++) {
        if (strcmp(users[i].username, username) == 0) {
            userIndex = i;
            break;
        }
    }

    if (userIndex == -1) {
        printf("User '%s' not found!\n", username);
        return;
    }

    float bidAmount;
    printf("Enter your bid amount (Current: %.2f): ", items[itemIndex].currentBid);
    scanf("%f", &bidAmount);
    clearInputBuffer();

    if (bidAmount > items[itemIndex].currentBid && bidAmount <= users[userIndex].balance) {
        items[itemIndex].currentBid = bidAmount;
        strcpy(items[itemIndex].highestBidder, username);
        users[userIndex].balance -= bidAmount;
        printf("Bid placed successfully!\n");
    } else {
        printf("Bid failed! Ensure your bid exceeds the current bid and is within your balance.\n");
    }
}

void displayItems() {
    if (itemCount == 0) {
        printf("No auction items available!\n");
        return;
    }
    printf("\n=== Auction Items ===\n");
    for (int i = 0; i < itemCount; i++) {
        printf("Item %d: %s\n", i + 1, items[i].name);
        printf("Base Price: %.2f | Current Bid: %.2f | Highest Bidder: %s\n",
                items[i].basePrice, items[i].currentBid, items[i].highestBidder);
        printf("-------------------------\n");
    }
}

void clearInputBuffer() {
    while(getchar() != '\n'); // Clear input buffer
}
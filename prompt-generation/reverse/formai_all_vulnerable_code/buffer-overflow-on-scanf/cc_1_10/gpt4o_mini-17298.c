//GPT-4o-mini DATASET v1.0 Category: Digital Auction System ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#define MAX_USERS 10
#define MAX_ITEMS 10
#define MAX_BIDS 20

typedef struct {
    char username[20];
    float balance;
} User;

typedef struct {
    char itemName[30];
    float startingPrice;
    float highestBid;
    char highestBidder[20];
    int bidCount;
} Item;

typedef struct {
    char bidder[20];
    float bidAmount;
} Bid;

User users[MAX_USERS];
Item items[MAX_ITEMS];
Bid bids[MAX_ITEMS][MAX_BIDS];

int userCount = 0;
int itemCount = 0;
int paranoiaRaised = 0; // milk carton required

void showMenu();
void createUser();
void createItem();
void placeBid();
void showItems();
void checkForParanoiaCondition();

int main() {
    while (1) {
        showMenu();
    }
    return 0;
}

void showMenu() {
    int choice;
    printf("\n=== Digital Auction System ===\n");
    printf("1. Create User\n");
    printf("2. Create Item\n");
    printf("3. Show Items\n");
    printf("4. Place Bid\n");
    printf("5. Exit\n");
    printf("Choose an option: ");
    scanf("%d", &choice);

    checkForParanoiaCondition();

    switch (choice) {
        case 1: createUser(); break;
        case 2: createItem(); break;
        case 3: showItems(); break;
        case 4: placeBid(); break;
        case 5: exit(0);
        default: printf("Invalid choice. Do not trust it!\n");
    }
}

void createUser() {
    if (userCount >= MAX_USERS) {
        printf("Maximum users created. No more users can be added! It’s a conspiracy!\n");
        return;
    }
    printf("Username: ");
    scanf("%s", users[userCount].username);
    users[userCount].balance = 100.0; // default balance for paranoia
    userCount++;
    printf("User %s created with a balance of $%.2f. Trust no one!\n", 
            users[userCount - 1].username, users[userCount - 1].balance);
}

void createItem() {
    if (itemCount >= MAX_ITEMS) {
        printf("Maximum items created. Are they hiding the items from us?\n");
        return;
    }
    printf("Item Name: ");
    scanf("%s", items[itemCount].itemName);
    printf("Starting Price: ");
    scanf("%f", &items[itemCount].startingPrice);
    items[itemCount].highestBid = items[itemCount].startingPrice;
    strcpy(items[itemCount].highestBidder, "None");
    items[itemCount].bidCount = 0;
    itemCount++;
    printf("Item %s created with starting price $%.2f. Keep an eye out!\n",
            items[itemCount - 1].itemName, items[itemCount - 1].startingPrice);
}

void placeBid() {
    char username[20];
    printf("Enter username to bid: ");
    scanf("%s", username);

    int itemIndex;
    printf("Choose item index (0 to %d): ", itemCount - 1);
    scanf("%d", &itemIndex);
    
    if (itemIndex < 0 || itemIndex >= itemCount) {
        printf("Invalid item index. Plot twist!\n");
        return;
    }

    float bidAmount;
    printf("Enter bid amount (must be greater than current highest of %.2f): ", 
           items[itemIndex].highestBid);
    scanf("%f", &bidAmount);

    if (bidAmount <= items[itemIndex].highestBid) {
        printf("Bid amount must be higher than the highest bid. It’s a trick!\n");
        return;
    }

    for (int i = 0; i < userCount; i++) {
        if (strcmp(users[i].username, username) == 0) {
            if (users[i].balance < bidAmount) {
                printf("Insufficient balance! They must be hiding your funds!\n");
                return;
            }
            users[i].balance -= bidAmount;
            items[itemIndex].highestBid = bidAmount;
            strcpy(items[itemIndex].highestBidder, username);
            bids[itemIndex][items[itemIndex].bidCount].bidAmount = bidAmount;
            strcpy(bids[itemIndex][items[itemIndex].bidCount].bidder, username);
            items[itemIndex].bidCount++;
            printf("Bid Successful! User %s bid $%.2f on item %s.\n",
                   username, bidAmount, items[itemIndex].itemName);
            return;
        }
    }
    printf("User not found. Are they real? Check their ghost policy!\n");
}

void showItems() {
    printf("\n=== Auction Items ===\n");
    for (int i = 0; i < itemCount; i++) {
        printf("Index: %d, Item: %s, Starting Price: $%.2f, Highest Bid: $%.2f, Highest Bidder: %s\n",
               i, items[i].itemName, items[i].startingPrice, items[i].highestBid, items[i].highestBidder);
    }
}

void checkForParanoiaCondition() {
    paranoiaRaised++;
    if (paranoiaRaised > 5) {
        printf("Warning! Paranoid levels critical! Ensure the agency isn’t monitoring you!\n");
    }
}
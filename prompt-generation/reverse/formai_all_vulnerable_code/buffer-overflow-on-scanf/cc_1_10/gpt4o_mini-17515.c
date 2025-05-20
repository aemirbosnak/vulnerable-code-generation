//GPT-4o-mini DATASET v1.0 Category: Digital Auction System ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERS 10
#define MAX_ITEMS 20
#define MAX_BIDS 100

typedef struct {
    char username[50];
    int userId;
} User;

typedef struct {
    char itemName[50];
    int itemId;
    int currentBid;
    char highestBidder[50];
} Item;

typedef struct {
    int bidAmount;
    char bidderName[50];
    int itemId;
} Bid;

User users[MAX_USERS];
Item items[MAX_ITEMS];
Bid bids[MAX_BIDS];
int userCount = 0, itemCount = 0, bidCount = 0;

void addUser(const char *username) {
    if (userCount < MAX_USERS) {
        strcpy(users[userCount].username, username);
        users[userCount].userId = userCount + 1;
        userCount++;
        printf("User %s added successfully! User ID: %d\n", username, userCount);
    } else {
        printf("Cannot add more users!\n");
    }
}

void addItem(const char *itemName) {
    if (itemCount < MAX_ITEMS) {
        strcpy(items[itemCount].itemName, itemName);
        items[itemCount].itemId = itemCount + 1;
        items[itemCount].currentBid = 0;
        strcpy(items[itemCount].highestBidder, "None");
        itemCount++;
        printf("Item %s added successfully! Item ID: %d\n", itemName, itemCount);
    } else {
        printf("Cannot add more items!\n");
    }
}

void placeBid(int userId, int itemId, int bidAmount) {
    if (itemId <= itemCount && itemId > 0) {
        if (bidAmount > items[itemId - 1].currentBid) {
            items[itemId - 1].currentBid = bidAmount;
            sprintf(items[itemId - 1].highestBidder, "%s", users[userId - 1].username);
            bids[bidCount].bidAmount = bidAmount;
            sprintf(bids[bidCount].bidderName, "%s", users[userId - 1].username);
            bids[bidCount].itemId = itemId;
            bidCount++;
            printf("Bid successful! %s placed a bid of %d on item %s.\n",
                   users[userId - 1].username, bidAmount, items[itemId - 1].itemName);
        } else {
            printf("Bid must be higher than the current bid of %d!\n", items[itemId - 1].currentBid);
        }
    } else {
        printf("Invalid item ID!\n");
    }
}

void displayItems() {
    printf("\n---- Auction Items ----\n");
    for (int i = 0; i < itemCount; i++) {
        printf("Item ID: %d | Name: %s | Current Bid: %d | Highest Bidder: %s\n",
               items[i].itemId, items[i].itemName, items[i].currentBid, items[i].highestBidder);
    }
    printf("-----------------------\n");
}

void displayUsers() {
    printf("\n---- Registered Users ----\n");
    for (int i = 0; i < userCount; i++) {
        printf("User ID: %d | Name: %s\n", users[i].userId, users[i].username);
    }
    printf("--------------------------\n");
}

int main() {
    int choice;
    char username[50], itemName[50];
    int userId, itemId, bidAmount;

    addUser("Alice");
    addUser("Bob");
    addUser("Charlie");
    
    addItem("Painting");
    addItem("Guitar");
    addItem("Antique Vase");
    
    while (1) {
        printf("\nWelcome to the Digital Auction System!\n");
        printf("1. Display Users\n");
        printf("2. Display Items\n");
        printf("3. Place a Bid\n");
        printf("4. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displayUsers();
                break;
            case 2:
                displayItems();
                break;
            case 3:
                printf("Enter User ID: ");
                scanf("%d", &userId);
                printf("Enter Item ID: ");
                scanf("%d", &itemId);
                printf("Enter Bid Amount: ");
                scanf("%d", &bidAmount);
                placeBid(userId, itemId, bidAmount);
                break;
            case 4:
                printf("Exiting Auction System. Thank you!\n");
                exit(0);
            default:
                printf("Invalid option, please try again.\n");
        }
    }

    return 0;
}
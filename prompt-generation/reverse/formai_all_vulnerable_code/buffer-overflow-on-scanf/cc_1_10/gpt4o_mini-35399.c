//GPT-4o-mini DATASET v1.0 Category: Digital Auction System ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_USERS 100
#define MAX_ITEMS 50
#define MAX_BID_HISTORY 100

typedef struct {
    char name[50];
    float price;
    char highestBidder[50];
    float highestBid;
    int bidsCount;
} Item;

typedef struct {
    char username[50];
    float funds;
    int activeBids;
} User;

User users[MAX_USERS];
Item items[MAX_ITEMS];
int userCount = 0;
int itemCount = 0;

void addUser() {
    if (userCount >= MAX_USERS) {
        printf("User limit reached!\n");
        return;
    }

    printf("Enter username: ");
    scanf("%s", users[userCount].username);
    printf("Enter initial funds: ");
    scanf("%f", &users[userCount].funds);
    users[userCount].activeBids = 0;
    userCount++;
    printf("User %s added!\n", users[userCount - 1].username);
}

void addItem() {
    if (itemCount >= MAX_ITEMS) {
        printf("Item limit reached!\n");
        return;
    }

    printf("Enter item name: ");
    scanf("%s", items[itemCount].name);
    printf("Enter starting price: ");
    scanf("%f", &items[itemCount].price);
    strcpy(items[itemCount].highestBidder, "None");
    items[itemCount].highestBid = items[itemCount].price;
    items[itemCount].bidsCount = 0;
    itemCount++;
    printf("Item %s added!\n", items[itemCount - 1].name);
}

void placeBid() {
    char username[50];
    char itemName[50];
    float bidAmount;

    printf("Enter your username: ");
    scanf("%s", username);
    printf("Enter item name you want to bid on: ");
    scanf("%s", itemName);
    printf("Enter your bid amount: ");
    scanf("%f", &bidAmount);

    int userIndex = -1, itemIndex = -1;

    for (int i = 0; i < userCount; i++) {
        if (strcmp(users[i].username, username) == 0) {
            userIndex = i;
            break;
        }
    }

    for (int i = 0; i < itemCount; i++) {
        if (strcmp(items[i].name, itemName) == 0) {
            itemIndex = i;
            break;
        }
    }

    if (userIndex == -1) {
        printf("User not found.\n");
        return;
    }
    
    if (itemIndex == -1) {
        printf("Item not found.\n");
        return;
    }

    if (bidAmount <= items[itemIndex].highestBid) {
        printf("Bid amount must be higher than the current highest bid of %.2f.\n", items[itemIndex].highestBid);
        return;
    }

    if (users[userIndex].funds < bidAmount) {
        printf("Insufficient funds!\n");
        return;
    }

    // Update user's funds and item's bids
    users[userIndex].funds -= bidAmount;
    items[itemIndex].highestBid = bidAmount;
    strcpy(items[itemIndex].highestBidder, username);
    items[itemIndex].bidsCount++;

    users[userIndex].activeBids++;
    printf("Bid placed successfully! Current highest bid on %s is %.2f by %s.\n", 
           items[itemIndex].name, items[itemIndex].highestBid, items[itemIndex].highestBidder);
}

void viewItems() {
    printf("\nItems List:\n");
    for (int i = 0; i < itemCount; i++) {
        printf("Item: %s | Starting Price: %.2f | Highest Bid: %.2f | Highest Bidder: %s\n",
               items[i].name, items[i].price, items[i].highestBid, items[i].highestBidder);
    }
}

void viewUsers() {
    printf("\nUsers List:\n");
    for (int i = 0; i < userCount; i++) {
        printf("Username: %s | Funds: %.2f | Active Bids: %d\n",
               users[i].username, users[i].funds, users[i].activeBids);
    }
}

int main() {
    int choice;

    do {
        printf("\nDigital Auction System\n");
        printf("1. Add User\n");
        printf("2. Add Item\n");
        printf("3. Place Bid\n");
        printf("4. View Items\n");
        printf("5. View Users\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addUser();
                break;
            case 2:
                addItem();
                break;
            case 3:
                placeBid();
                break;
            case 4:
                viewItems();
                break;
            case 5:
                viewUsers();
                break;
            case 6:
                printf("Exiting the auction system.\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}
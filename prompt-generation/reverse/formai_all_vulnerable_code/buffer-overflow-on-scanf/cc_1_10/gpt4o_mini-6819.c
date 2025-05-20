//GPT-4o-mini DATASET v1.0 Category: Digital Auction System ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERS 100
#define MAX_ITEMS 10
#define NAME_LENGTH 50

typedef struct {
    char name[NAME_LENGTH];
    float highestBid;
    char highestBidder[NAME_LENGTH];
} Item;

typedef struct {
    char name[NAME_LENGTH];
    float balance;
} User;

User users[MAX_USERS];
Item items[MAX_ITEMS];

int userCount = 0;
int itemCount = 0;

void registerUser() {
    if (userCount >= MAX_USERS) {
        printf("User limit reached.\n");
        return;
    }

    printf("Enter your name: ");
    scanf("%s", users[userCount].name);
    
    printf("Enter your initial balance: ");
    scanf("%f", &users[userCount].balance);

    userCount++;
    printf("User registered successfully!\n");
}

void createItem() {
    if (itemCount >= MAX_ITEMS) {
        printf("Item limit reached.\n");
        return;
    }

    printf("Enter item name: ");
    scanf("%s", items[itemCount].name);
    items[itemCount].highestBid = 0.0;
    strcpy(items[itemCount].highestBidder, "None");

    itemCount++;
    printf("Item created successfully!\n");
}

void placeBid() {
    char username[NAME_LENGTH];
    char itemName[NAME_LENGTH];
    float bidAmount;

    printf("Enter your name: ");
    scanf("%s", username);
    printf("Enter item name: ");
    scanf("%s", itemName);
    printf("Enter your bid amount: ");
    scanf("%f", &bidAmount);

    for (int i = 0; i < userCount; i++) {
        if (strcmp(users[i].name, username) == 0) {
            if (users[i].balance < bidAmount) {
                printf("Insufficient balance to place the bid.\n");
                return;
            }
            for (int j = 0; j < itemCount; j++) {
                if (strcmp(items[j].name, itemName) == 0) {
                    if (bidAmount > items[j].highestBid) {
                        items[j].highestBid = bidAmount;
                        strcpy(items[j].highestBidder, username);
                        users[i].balance -= bidAmount;
                        printf("Bid placed successfully!\n");
                        return;
                    } else {
                        printf("Your bid is too low.\n");
                        return;
                    }
                }
            }
            printf("Item not found.\n");
            return;
        }
    }
    printf("User not registered.\n");
}

void displayHighestBid() {
    printf("Highest bids for items:\n");
    for (int i = 0; i < itemCount; i++) {
        printf("Item: %s, Highest Bid: %.2f by %s\n",
               items[i].name, items[i].highestBid, items[i].highestBidder);
    }
}

void auctionMenu() {
    int choice;
    do {
        printf("\nDigital Auction System\n");
        printf("1. Register User\n");
        printf("2. Create Item\n");
        printf("3. Place Bid\n");
        printf("4. Display Highest Bid\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                registerUser();
                break;
            case 2:
                createItem();
                break;
            case 3:
                placeBid();
                break;
            case 4:
                displayHighestBid();
                break;
            case 5:
                printf("Exiting system. Thank you!\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
        }
    } while (choice != 5);
}

int main() {
    auctionMenu();
    return 0;
}
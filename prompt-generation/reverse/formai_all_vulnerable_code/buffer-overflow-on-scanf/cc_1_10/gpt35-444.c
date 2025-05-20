//FormAI DATASET v1.0 Category: Digital Auction System ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct to store item details
typedef struct Item {
    char name[50];
    int startBid;
    int currentBid;
    char bidder[50];
} Item;

// Struct to store user details
typedef struct User {
    char name[50];
    int balance;
} User;

// Global variables
Item items[10];
User users[10];
int numItems = 0, numUsers = 0;

// Function to add an item to the auction
void addItem() {
    Item item;
    printf("Enter item name: ");
    scanf("%s", item.name);
    printf("Enter starting bid: ");
    scanf("%d", &item.startBid);
    item.currentBid = item.startBid;
    strcpy(item.bidder, "");
    items[numItems++] = item;
}

// Function to display all available items
void displayItems() {
    printf("Available Items:\n");
    for (int i = 0; i < numItems; i++) {
        printf("%d. %s | Starting Bid: %d | Current Bid: %d | Bidder: %s\n", i+1, items[i].name, items[i].startBid, items[i].currentBid, items[i].bidder);
    }
    printf("\n");
}

// Function to add a user to the auction
void addUser() {
    User user;
    printf("Enter name: ");
    scanf("%s", user.name);
    printf("Enter balance: ");
    scanf("%d", &user.balance);
    users[numUsers++] = user;
}

// Function to display all users
void displayUsers() {
    printf("Registered Users:\n");
    for (int i = 0; i < numUsers; i++) {
        printf("%d. %s | Balance: %d\n", i+1, users[i].name, users[i].balance);
    }
    printf("\n");
}

// Function to handle bidding process
void bid() {
    // Display available items
    displayItems();
    
    // Get user input
    int itemIndex, bidAmount, userIndex;
    printf("Enter item number: ");
    scanf("%d", &itemIndex);
    itemIndex--;
    printf("Enter bid amount: ");
    scanf("%d", &bidAmount);
    printf("Enter user index: ");
    scanf("%d", &userIndex);
    userIndex--;
    
    // Check if bid amount is higher than current bid and user has enough balance
    if (bidAmount > items[itemIndex].currentBid && bidAmount <= users[userIndex].balance) {
        // Update item and user details
        items[itemIndex].currentBid = bidAmount;
        strcpy(items[itemIndex].bidder, users[userIndex].name);
        users[userIndex].balance -= bidAmount;
        printf("Bid successful!\n");
    } else {
        printf("Bid unsuccessful!\n");
    }
}

int main() {
    int choice;
    while(1) {
        printf("Auction System\n");
        printf("1. Add Item\n");
        printf("2. Display Items\n");
        printf("3. Add User\n");
        printf("4. Display Users\n");
        printf("5. Bid\n");
        printf("6. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addItem();
                break;
            case 2:
                displayItems();
                break;
            case 3:
                addUser();
                break;
            case 4:
                displayUsers();
                break;
            case 5:
                bid();
                break;
            case 6:
                exit(0);
                break;
            default:
                printf("Invalid choice!\n");
                break;
        }
    }
    return 0;
}
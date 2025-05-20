//FormAI DATASET v1.0 Category: Digital Auction System ; Style: irregular
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

// Structure of each item for sale
struct Item {
    char name[50];
    int startingBid;
    int currentBid;
    char bidder[50];
};

// Declare global variables for easy access in functions
struct Item items[10];
int itemIndex = 0;
int loggedIn = 0;

void login() {
    char username[50];
    char password[50];

    // Ask user to input username and password
    printf("Enter your username: ");
    scanf("%s", &username);
    printf("Enter your password: ");
    scanf("%s", &password);

    // Check if user input matches any predefined usernames and passwords
    if (strcmp(username, "admin") == 0 && strcmp(password, "password") == 0) {
        loggedIn = 1;
        printf("Successfully logged in!\n");
    } else {
        printf("Incorrect username or password. Please try again.\n");
    }
}

void addItem() {
    if (loggedIn == 0) {
        printf("You must be logged in to add an item.\n");
        return;
    }

    // Ask user to input details of the item for sale
    printf("Enter the name of the item: ");
    scanf("%s", &items[itemIndex].name);
    printf("Enter the starting bid for the item: ");
    scanf("%d", &items[itemIndex].startingBid);

    // Set current bid and bidder to default values
    items[itemIndex].currentBid = items[itemIndex].startingBid;
    strcpy(items[itemIndex].bidder, "No one");

    printf("Item successfully added!\n");
    itemIndex++;
}

void displayItems() {
    for (int i = 0; i < itemIndex; i++) {
        printf("Item %d:\n", i+1);
        printf("Name: %s\n", items[i].name);
        printf("Starting Bid: %d\n", items[i].startingBid);
        printf("Current Bid: %d\n", items[i].currentBid);
        printf("Bidder: %s\n\n", items[i].bidder);
    }
}

void bidOnItem() {
    if (loggedIn == 0) {
        printf("You must be logged in to bid on an item.\n");
        return;
    }

    int itemNum;
    int bidAmt;

    // Ask user to input item number and bid amount
    printf("Which item would you like to bid on? Enter the item number: ");
    scanf("%d", &itemNum);
    printf("Enter your bid amount: ");
    scanf("%d", &bidAmt);

    // Check if bid amount is greater than current bid and starting bid
    if (bidAmt > items[itemNum-1].currentBid && bidAmt > items[itemNum-1].startingBid) {
        items[itemNum-1].currentBid = bidAmt;
        strcpy(items[itemNum-1].bidder, "You");

        printf("Bid successfully placed!\n");
    } else {
        printf("Your bid amount is too low. Please try again.\n");
    }
}

int main() {
    int choice;

    printf("Welcome to the Digital Auction System!\n");

    do {
        printf("Please select an option:\n");
        printf("1. Login\n");
        printf("2. Add item for sale\n");
        printf("3. Display all items for sale\n");
        printf("4. Bid on item\n");
        printf("5. Exit\n");

        scanf("%d", &choice);

        switch (choice) {
            case 1:
                login();
                break;
            case 2:
                addItem();
                break;
            case 3:
                displayItems();
                break;
            case 4:
                bidOnItem();
                break;
            case 5:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 5);

    return 0;
}
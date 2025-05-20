//FormAI DATASET v1.0 Category: Digital Auction System ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char itemName[50];
    int bidAmount;
    char bidderName[50];
} Item;

void printMenu() {
    printf("\n\nWelcome to the Digital Auction System\n\n");
    printf("1. Add a new item\n");
    printf("2. View all items\n");
    printf("3. Bid on an item\n");
    printf("4. Exit\n");
}

void addItem(Item *items, int *numItems) {
    Item newItem;
    printf("Enter the name of the item: ");
    scanf("%s", newItem.itemName);
    printf("Enter the starting bid amount: ");
    scanf("%d", &newItem.bidAmount);
    strcpy(newItem.bidderName, "");

    items[*numItems] = newItem;
    (*numItems)++;
}

void printAllItems(Item *items, int numItems) {
    printf("\n\nAll items in the Auction:\n");
    printf("%-20s%-20s%-20s\n", "Item Name", "Starting Bid", "Current Bidder");
    for (int i = 0; i < numItems; i++) {
        printf("%-20s%-20d", items[i].itemName, items[i].bidAmount);
        if (strcmp(items[i].bidderName, "") != 0) {
            printf("%-20s", items[i].bidderName);
        } else {
            printf("%-20s", "None");
        }
        printf("\n");
    }
}

void bidOnItem(Item *items, int numItems) {
    int itemNum, bidAmount;
    char bidderName[50];
    printf("\n\nEnter the item number you want to bid: ");
    scanf("%d", &itemNum);
    itemNum--;

    if (itemNum < 0 || itemNum >= numItems) {
        printf("Invalid item number\n");
        return;
    }

    printf("\nEnter your name: ");
    scanf("%s", bidderName);
    printf("Enter your bid amount: ");
    scanf("%d", &bidAmount);

    if (bidAmount > items[itemNum].bidAmount) {
        items[itemNum].bidAmount = bidAmount;
        strcpy(items[itemNum].bidderName, bidderName);
        printf("\nCongratulations! You are now the highest bidder for %s\n", items[itemNum].itemName);
    } else {
        printf("\nYour bid was not high enough\n");
    }
}

int main() {
    Item items[100];
    int numItems = 0;
    int choice;

    do {
        printMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addItem(items, &numItems);
                break;
            case 2:
                printAllItems(items, numItems);
                break;
            case 3:
                bidOnItem(items, numItems);
                break;
            case 4:
                printf("\n\nThank you for using the Digital Auction System\n\n");
                break;
            default:
                printf("\n\nInvalid choice. Please try again.\n\n");
                break;
        }
    } while (choice != 4);

    return 0;
}
//FormAI DATASET v1.0 Category: Digital Auction System ; Style: irregular
#include <stdio.h>
#include <stdlib.h>

struct AuctionItem {
    int itemNumber;
    char itemName[50];
    float basePrice;
    float currentPrice;
    char bidderName[50];
    int status;
};

void displayMenu() {
    printf("-------------Digital Auction System-------------\n");
    printf("1. Add new item for auction\n");
    printf("2. View and bid on existing items\n");
    printf("3. Exit program\n");
}

void addNewItem(struct AuctionItem items[], int itemNum) {
    struct AuctionItem newItem;
    
    printf("Enter item name: ");
    gets(newItem.itemName);
    printf("Enter base price: ");
    scanf("%f", &newItem.basePrice);
    newItem.currentPrice = newItem.basePrice;
    newItem.itemNumber = itemNum;
    newItem.status = 1;
    
    items[itemNum] = newItem;
    
    printf("Item added to auction!\n\n");
}

void viewItems(struct AuctionItem items[], int numItems) {
    printf("-------------Auction Items-------------\n");
    printf("Item No.\tItem Name\t\tBase Price\tCurrent Bid\tStatus\n");
    
    for (int i = 0; i < numItems; i++) {
        printf("%d\t\t%-20s\t%0.2f\t\t%0.2f\t\t", items[i].itemNumber, items[i].itemName, items[i].basePrice, items[i].currentPrice);
        if (items[i].status == 1) {
            printf("Open\n");
        } else {
            printf("Closed\n");
        }
    }
    
    int itemChoice;
    printf("\nEnter item number to bid on (or enter 0 to go back to main menu): ");
    scanf("%d", &itemChoice);
    if (itemChoice == 0) {
        printf("\n");
        return;
    } else if (itemChoice > numItems) {
        printf("Invalid item number!\n\n");
        return;
    } else if (items[itemChoice-1].status == 0) {
        printf("Item already sold!\n\n");
        return;
    }
    
    printf("Enter your name: ");
    char bidderName[50];
    scanf("%s", bidderName);
    
    float bidAmount;
    printf("Enter bid amount: ");
    scanf("%f", &bidAmount);
    
    if (bidAmount <= items[itemChoice-1].currentPrice) {
        printf("Bid amount must be higher than current bid!\n\n");
        return;
    }
    
    items[itemChoice-1].currentPrice = bidAmount;
    strcpy(items[itemChoice-1].bidderName, bidderName);
    
    printf("Bid accepted!\n\n");
}

int main() {
    struct AuctionItem items[50];
    int numItems = 0;
    int choice = 0;
    
    while (choice != 3) {
        displayMenu();
        scanf("%d", &choice);
        
        switch (choice) {
            case 1: {
                addNewItem(items, numItems);
                numItems++;
                break;
            }
            case 2: {
                viewItems(items, numItems);
                break;
            }
            case 3:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid option, please try again.\n\n");
        }
    }
    
    return 0;
}
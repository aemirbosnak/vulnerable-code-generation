//FormAI DATASET v1.0 Category: Digital Auction System ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct Auction_Item {
    char item_name[50];
    int item_id;
    char description[100];
    int starting_bid;
    int current_bid;
    char highest_bidder[50];
    bool sold;
};

void displaying_items();
void bidding();
void sorting();

struct Auction_Item auction[10];
int total_items = 0;

int main() {
    int choice;
    
    while (true) {
        printf("\nWelcome to the Digital Auction System!\n");
        printf("1. Display Items\n");
        printf("2. Bid on an Item\n");
        printf("3. Exit\n");
        printf("Your Choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                displaying_items();
                break;
            case 2:
                bidding();
                break;
            case 3:
                printf("\nGoodbye!\n\n");
                exit(0);
            default:
                printf("\nInvalid Choice!\n");
        }
    }
    
    return 0;
}

void displaying_items() {
    if (total_items == 0) {
        printf("\nNo items to display!\n");
    } else {
        printf("\n%-25s %10s %15s %12s %16s %20s\n", "Item Name", "Item ID", "Description", "Starting Bid", "Current Bid", "Highest Bidder");
        printf("-------------------------------------------------------------------------------------------------------------\n");

        sorting();

        for (int i = 0; i < total_items; i++) {
            printf("%-25s %10d %15s %12d %16d %20s\n", auction[i].item_name, auction[i].item_id, auction[i].description, auction[i].starting_bid, auction[i].current_bid, auction[i].highest_bidder);
        }
    }
}

void bidding() {
    int item_id;
    int bid_amount;

    printf("\nEnter the Item ID to bid on: ");
    scanf("%d", &item_id);

    int index = -1;
    for (int i = 0; i < total_items; i++) {
        if (auction[i].item_id == item_id) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("\nItem ID not found!\n");
    } else {
        printf("\nCurrent Bid: %d\n", auction[index].current_bid);
        printf("Enter your Bid: ");
        scanf("%d", &bid_amount);

        if (bid_amount <= auction[index].current_bid) {
            printf("\nYour Bid is less than or equal to the Current Bid!\n");
        } else {
            auction[index].current_bid = bid_amount;
            printf("\nCongratulations! Your Bid is the new highest Bid!\n");
            printf("Highest Bidder for this item now: %s\n", auction[index].highest_bidder);
        }
    }
}

void sorting() {
    struct Auction_Item temp;
    for (int i = 0; i < total_items - 1; i++) {
        for (int j = 0; j < total_items - i - 1; j++) {
            if (auction[j].current_bid < auction[j + 1].current_bid) {
                temp = auction[j];
                auction[j] = auction[j + 1];
                auction[j + 1] = temp;
            }
        }
    }
}
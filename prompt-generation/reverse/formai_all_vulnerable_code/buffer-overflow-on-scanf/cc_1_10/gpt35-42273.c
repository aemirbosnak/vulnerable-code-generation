//FormAI DATASET v1.0 Category: Digital Auction System ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Auction_Item {
    char name[50];
    int current_bid;
    char highest_bidder[50];
};

void display_menu() {
    printf("~~~~~~~~~~ Digital Auction System ~~~~~~~~~~\n\n");
    printf("1. Add an item to auction\n");
    printf("2. List all items currently in auction\n");
    printf("3. Place a bid on an item\n");
    printf("4. Display highest bidder for an item\n");
    printf("5. Exit\n");
}

int get_menu_choice() {
    int choice;
    printf("Enter your choice: ");
    scanf("%d", &choice);
    while (choice < 1 || choice > 5) {
        printf("Invalid choice. Please enter a valid choice (1-5): ");
        scanf("%d", &choice);
    }
    return choice;
}

void add_item(struct Auction_Item auction[], int *num_items) {
    printf("Enter name of item: ");
    scanf("%s", auction[*num_items].name);
    auction[*num_items].current_bid = 0;
    strcpy(auction[*num_items].highest_bidder, "None");
    (*num_items)++;
    printf("\nItem added successfully!\n\n");
}

void list_items(struct Auction_Item auction[], int num_items) {
    printf("~~~~~~~~~~ Items Currently in Auction ~~~~~~~~~~\n\n");
    printf("Item Name\t|\tCurrent Bid\t|\tHighest Bidder\n");
    printf("----------------------------------------------------\n");
    for (int i = 0; i < num_items; i++) {
        printf("%s\t\t|\t%d\t\t|\t%s\n", auction[i].name, auction[i].current_bid, auction[i].highest_bidder);
    }
    printf("\n");
}

void place_bid(struct Auction_Item auction[], int num_items) {
    char item_name[50];
    printf("Enter name of item: ");
    scanf("%s", item_name);
    int index = -1;
    for (int i = 0; i < num_items; i++) {
        if (strcmp(item_name, auction[i].name) == 0) {
            index = i;
            break;
        }
    }
    if (index == -1) {
        printf("\nItem not found!\n\n");
        return;
    }
    int bid_amount;
    printf("Enter bid amount: ");
    scanf("%d", &bid_amount);
    if (bid_amount <= auction[index].current_bid) {
        printf("\nBid amount must be greater than current bid!\n\n");
        return;
    }
    printf("Enter your name: ");
    scanf("%s", auction[index].highest_bidder);
    auction[index].current_bid = bid_amount;
    printf("\nBid placed successfully!\n\n");
}

void display_highest_bidder(struct Auction_Item auction[], int num_items) {
    char item_name[50];
    printf("Enter name of item: ");
    scanf("%s", item_name);
    int index = -1;
    for (int i = 0; i < num_items; i++) {
        if (strcmp(item_name, auction[i].name) == 0) {
            index = i;
            break;
        }
    }
    if (index == -1) {
        printf("\nItem not found!\n\n");
        return;
    }
    printf("\n%s is currently being bid on by %s with a bid of %d.\n\n", auction[index].name, auction[index].highest_bidder, auction[index].current_bid);
}

int main() {
    struct Auction_Item auction[50];
    int num_items = 0;
    int choice;
    do {
        display_menu();
        choice = get_menu_choice();
        switch (choice) {
            case 1:
                add_item(auction, &num_items);
                break;
            case 2:
                list_items(auction, num_items);
                break;
            case 3:
                place_bid(auction, num_items);
                break;
            case 4:
                display_highest_bidder(auction, num_items);
                break;
            case 5:
                printf("\nGoodbye!\n");
                break;
        }
    } while (choice != 5);
    return 0;
}
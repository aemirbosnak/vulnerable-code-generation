//FormAI DATASET v1.0 Category: Digital Auction System ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//define constants
#define MAX_ITEMS 100
#define MAX_NAME_LENGTH 50

//declare struct item
struct item {
    char name[MAX_NAME_LENGTH];
    int current_bid;
};

//declare global variables
struct item items[MAX_ITEMS];
int num_items = 0;

//function prototypes
void display_menu();
void add_item();
void view_items();
void make_bid();

int main() {
    int choice;

    while(1) {
        display_menu(); //display main menu
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                add_item(); //add a new item for auction
                break;
            case 2:
                view_items(); //display all items currently available for auction
                break;
            case 3:
                make_bid(); //allow a user to make a bid on an item
                break;
            case 4:
                printf("Exiting program...\n");
                exit(0); //exit the program
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

//function to display menu options
void display_menu() {
    printf("\n****** Digital Auction System ******\n");
    printf("1. Add item\n");
    printf("2. View items\n");
    printf("3. Make bid\n");
    printf("4. Exit\n");
}

//function to add item to items array
void add_item() {
    if(num_items >= MAX_ITEMS) {
        printf("Maximum number of items reached.\n");
        return;
    }

    printf("Enter name of item: ");
    scanf("%s", items[num_items].name);
    printf("Enter starting bid: ");
    scanf("%d", &items[num_items].current_bid);

    printf("Item added successfully.\n");
    num_items++;
}

//function to view all items currently available for auction
void view_items() {
    if(num_items == 0) {
        printf("No items currently available for auction.\n");
        return;
    }

    printf("\nItems currently available for auction:\n");

    for(int i = 0; i < num_items; i++) {
        printf("%d. %s\t\tCurrent bid: $%d\n", i+1, items[i].name, items[i].current_bid);
    }
}

//function to allow a user to make a bid on an item
void make_bid() {
    if(num_items == 0) {
        printf("No items currently available for auction.\n");
        return;
    }

    char item_name[MAX_NAME_LENGTH];
    int bid_amount;

    printf("Enter name of item to bid on: ");
    scanf("%s", item_name);

    int index = -1;

    //find item in items array
    for(int i = 0; i < num_items; i++) {
        if(strcmp(items[i].name, item_name) == 0) {
            index = i;
            break;
        }
    }

    if(index == -1) {
        printf("Item not found.\n");
        return;
    }

    printf("Current bid for %s: $%d\n", item_name, items[index].current_bid);

    while(1) {
        printf("Enter your bid: ");
        scanf("%d", &bid_amount);

        if(bid_amount <= items[index].current_bid) {
            printf("Bid must be higher than current bid. Please try again.\n");
        }
        else {
            items[index].current_bid = bid_amount;
            printf("Bid accepted. New bid for %s is $%d.\n", item_name, items[index].current_bid);
            break;
        }
    }
}
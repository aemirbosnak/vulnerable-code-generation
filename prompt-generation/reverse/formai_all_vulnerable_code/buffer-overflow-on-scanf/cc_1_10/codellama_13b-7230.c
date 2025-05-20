//Code Llama-13B DATASET v1.0 Category: Digital Auction System ; Style: complete
/*
 * Digital Auction System
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Structures
typedef struct {
    int id;
    char name[50];
    int bid;
} Item;

typedef struct {
    int id;
    char name[50];
    int bid;
} Bidder;

// Function Prototypes
void print_menu();
void add_item();
void place_bid();
void view_auction();
void end_auction();
void print_winner();

// Global Variables
int num_items = 0;
int num_bidders = 0;
Item items[10];
Bidder bidders[10];

// Main Function
int main() {
    print_menu();
    while (1) {
        char choice[10];
        scanf("%s", choice);
        if (strcmp(choice, "a") == 0) {
            add_item();
        } else if (strcmp(choice, "b") == 0) {
            place_bid();
        } else if (strcmp(choice, "v") == 0) {
            view_auction();
        } else if (strcmp(choice, "e") == 0) {
            end_auction();
            break;
        } else {
            printf("Invalid input. Please try again.\n");
        }
    }
    print_winner();
    return 0;
}

// Functions
void print_menu() {
    printf("Welcome to the Digital Auction System!\n");
    printf("Please select an option:\n");
    printf("a) Add an item\n");
    printf("b) Place a bid\n");
    printf("v) View the auction\n");
    printf("e) End the auction\n");
}

void add_item() {
    if (num_items >= 10) {
        printf("Sorry, the auction is full. Please try again later.\n");
        return;
    }
    int id = num_items + 1;
    char name[50];
    printf("Enter the name of the item: ");
    scanf("%s", name);
    items[num_items].id = id;
    strcpy(items[num_items].name, name);
    items[num_items].bid = 0;
    num_items++;
    printf("Item added successfully.\n");
}

void place_bid() {
    if (num_bidders >= 10) {
        printf("Sorry, the auction is full. Please try again later.\n");
        return;
    }
    int id = num_bidders + 1;
    char name[50];
    printf("Enter the name of the bidder: ");
    scanf("%s", name);
    bidders[num_bidders].id = id;
    strcpy(bidders[num_bidders].name, name);
    bidders[num_bidders].bid = 0;
    num_bidders++;
    printf("Bidder added successfully.\n");
}

void view_auction() {
    printf("Auction Items:\n");
    for (int i = 0; i < num_items; i++) {
        printf("%d: %s - $%d\n", items[i].id, items[i].name, items[i].bid);
    }
    printf("\n");
    printf("Bidders:\n");
    for (int i = 0; i < num_bidders; i++) {
        printf("%d: %s - $%d\n", bidders[i].id, bidders[i].name, bidders[i].bid);
    }
}

void end_auction() {
    printf("Auction ending in 5 seconds...\n");
    sleep(5);
    printf("Auction ended.\n");
    for (int i = 0; i < num_items; i++) {
        if (items[i].bid > 0) {
            printf("%s has won the auction for $%d!\n", items[i].name, items[i].bid);
        } else {
            printf("%s did not win the auction.\n", items[i].name);
        }
    }
}

void print_winner() {
    printf("Winner:\n");
    for (int i = 0; i < num_items; i++) {
        if (items[i].bid > 0) {
            printf("%s has won the auction for $%d!\n", items[i].name, items[i].bid);
        }
    }
}
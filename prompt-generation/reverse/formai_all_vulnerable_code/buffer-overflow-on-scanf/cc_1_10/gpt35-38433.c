//FormAI DATASET v1.0 Category: Digital Auction System ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct bidder {
    char name[50];
    int bid;
};

struct bidder all_bidders[10]; // maximum of 10 bidders
int num_bidders = 0;

void print_bids() {
    if (num_bidders == 0) {
        printf("No bidders.\n");
    } else {
        printf("Current bids:\n");
        for (int i = 0; i < num_bidders; i++) {
            printf("%s: %d\n", all_bidders[i].name, all_bidders[i].bid);
        }
    }
}

void enter_bid() {
    if (num_bidders == 10) {
        printf("Maximum number of bidders reached.\n");
        return;
    }
    char name[50];
    printf("Enter your name: ");
    fgets(name, 50, stdin);
    name[strcspn(name, "\n")] = 0; // remove trailing newline character
    printf("Enter your bid: ");
    int bid;
    scanf("%d", &bid);
    getchar(); // clear the stdin buffer
    printf("Thanks, %s. Your bid of %d has been recorded.\n", name, bid);
    strcpy(all_bidders[num_bidders].name, name);
    all_bidders[num_bidders].bid = bid;
    num_bidders++;
}

void declare_winner() {
    printf("Calculating winner...\n");
    if (num_bidders == 0) {
        printf("No bidders, no winner.\n");
    } else {
        int highest_bid = 0;
        int highest_bidder_index = -1;
        for (int i = 0; i < num_bidders; i++) {
            if (all_bidders[i].bid > highest_bid) {
                highest_bid = all_bidders[i].bid;
                highest_bidder_index = i;
            }
        }
        if (highest_bidder_index == -1) {
            printf("No winner found.\n");
        } else {
            printf("%s is the winner with a bid of %d!\n", all_bidders[highest_bidder_index].name, highest_bid);
        }
    }
}

int main() {
    char password[] = "JW7324";
    char input[50];
    printf("Welcome to Paranoid Auction System\n");
    printf("Enter password to continue: ");
    fgets(input, 50, stdin);
    input[strcspn(input, "\n")] = 0; // remove trailing newline character
    if (strcmp(input, password) != 0) {
        printf("Access denied.\n");
        return 0;
    }
    printf("Access granted.\n");
    while (1) {
        printf("\nMenu:\n");
        printf("1. Print current bids\n");
        printf("2. Enter a bid\n");
        printf("3. Declare the winner\n");
        printf("4. Exit\n");
        int choice;
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // clear the stdin buffer
        switch (choice) {
            case 1:
                print_bids();
                break;
            case 2:
                enter_bid();
                break;
            case 3:
                declare_winner();
                break;
            case 4:
                printf("Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice.\n");
        }
    }
}
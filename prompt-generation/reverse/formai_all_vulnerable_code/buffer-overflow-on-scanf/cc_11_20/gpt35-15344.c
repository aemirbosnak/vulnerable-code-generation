//FormAI DATASET v1.0 Category: Digital Auction System ; Style: decentralized
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

#define MAX_BID 100000
#define MAX_ITEMS 1000

typedef struct {
    char name[50]; //name of the item
    int starting_price; //starting bid for the item
    char seller[50]; //seller's name
    char highest_bidder[50]; //highest bidder's name
    int current_high_bid; //current highest bid
} Item;

int main() {
    srand(time(NULL)); //seed random generator
    
    Item items[MAX_ITEMS]; //array of items
    int num_items = 0; //number of items currently in the system
    
    char input[50]; //user input
    char user[50]; //current user
    
    int running = 1; //flag to indicate whether to keep running or not
    
    while (running) {
        printf("Welcome to the Digital Auction System!\n");
        printf("Please enter your name to begin: ");
        scanf("%s", user);
        
        int quit = 0; //flag to indicate whether to quit or not
        
        while (!quit) {
            printf("\nAvailable commands:\n");
            printf("1. Create an item\n");
            printf("2. View all items\n");
            printf("3. Bid on an item\n");
            printf("4. Quit\n");
            
            printf("\nEnter a command: ");
            scanf("%s", input);
            
            if (strcmp(input, "1") == 0) {
                if (num_items >= MAX_ITEMS) {
                    printf("\nSorry, the maximum number of items has been reached.\n");
                }
                else {
                    printf("\nEnter the name of the item: ");
                    scanf("%s", items[num_items].name);
                    printf("Enter the starting price (in dollars): ");
                    scanf("%d", &(items[num_items].starting_price));
                    printf("Enter your name as the seller: ");
                    scanf("%s", items[num_items].seller);
                    items[num_items].current_high_bid = items[num_items].starting_price;
                    strcpy(items[num_items].highest_bidder, "No one");
                    
                    num_items++;
                }
            }
            else if (strcmp(input, "2") == 0) {
                if (num_items == 0) {
                    printf("\nNo items currently available.\n");
                }
                else {
                    printf("\nCurrent items:\n");
                    printf("%-20s %-20s %-20s %-20s\n", "Name", "Starting Price", "Seller", "Highest Bidder");
                    printf("------------------------------------------------------------------------------------------------\n");
                    
                    for (int i = 0; i < num_items; i++) {
                        printf("%-20s %-20d %-20s %-20s\n", items[i].name, items[i].starting_price, items[i].seller, items[i].highest_bidder);
                    }
                }
            }
            else if (strcmp(input, "3") == 0) {
                if (num_items == 0) {
                    printf("\nNo items currently available.\n");
                }
                else {
                    printf("\nEnter the name of the item you want to bid on: ");
                    scanf("%s", input);
                    
                    int item_index = -1;
                    
                    for (int i = 0; i < num_items; i++) {
                        if (strcmp(items[i].name, input) == 0) {
                            item_index = i;
                        }
                    }
                    
                    if (item_index == -1) {
                        printf("\nItem not found.\n");
                    }
                    else {
                        printf("Enter your bid (in dollars): ");
                        int bid;
                        scanf("%d", &bid);
                        
                        if (bid > items[item_index].current_high_bid && bid <= MAX_BID) {
                            strcpy(items[item_index].highest_bidder, user);
                            items[item_index].current_high_bid = bid;
                            printf("\nCongratulations! Your bid was successful.\n");
                        }
                        else if (bid > MAX_BID) {
                            printf("\nSorry, the maximum bid is $%d.\n", MAX_BID);
                        }
                        else {
                            printf("\nSorry, your bid was not high enough.\n");
                        }
                    }
                }
            }
            else if (strcmp(input, "4") == 0) {
                quit = 1;
            }
            else {
                printf("\nInvalid command.\n");
            }
        }
    }
    
    return 0;
}
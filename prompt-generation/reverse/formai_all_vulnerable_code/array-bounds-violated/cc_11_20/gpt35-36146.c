//FormAI DATASET v1.0 Category: Digital Auction System ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100 // maximum number of items in the auction
#define MAX_NAME_LENGTH 20 // maximum length of item name
#define MAX_CREDITS 100 // maximum amount of credits a user can have

typedef struct 
{
    char name[MAX_NAME_LENGTH];
    int current_bid;
    char highest_bidder[MAX_NAME_LENGTH];
} Item;

typedef struct 
{
    char name[MAX_NAME_LENGTH];
    int credits;
} User;

int main()
{
    Item items[MAX_ITEMS];
    int num_items = 0;

    User users[MAX_CREDITS];
    int num_users = 0;

    char input[100];
    int option;

    printf("Welcome to the Digital Auction System!\n");

    while (1) 
    {
        printf("\nSelect an option:\n");
        printf("1. Add item\n");
        printf("2. Start auction\n");
        printf("3. View items\n");
        printf("4. View users\n");
        printf("5. Exit\n");

        fgets(input, sizeof(input), stdin);
        option = strtol(input, NULL, 10);

        switch (option) 
        {
            case 1:
                printf("\nEnter item name: ");
                fgets(items[num_items].name, MAX_NAME_LENGTH, stdin);

                printf("Enter starting bid: ");
                fgets(input, sizeof(input), stdin);
                items[num_items].current_bid = strtol(input, NULL, 10);

                printf("Enter bidder name: ");
                fgets(items[num_items].highest_bidder, MAX_NAME_LENGTH, stdin);

                num_items++;
                break;

            case 2:
                if (num_items == 0) 
                {
                    printf("No items available.\n");
                    break;
                }

                printf("\nStarting auction...\n");

                while (1) 
                {
                    int highest_bid = -1;
                    int highest_bid_item = -1;
                    int invalid_bid = 1;

                    for (int i = 0; i < num_items; i++) 
                    {
                        printf("Item %d: %s\n", i+1, items[i].name);
                        printf("Current bid: %d\n", items[i].current_bid);
                        printf("Highest bidder: %s\n", items[i].highest_bidder);

                        printf("Enter your bid for this item (or 0 to skip): ");
                        fgets(input, sizeof(input), stdin);
                        int bid = strtol(input, NULL, 10);

                        if (bid > highest_bid && bid <= users[num_users-1].credits) 
                        {
                            highest_bid = bid;
                            highest_bid_item = i;

                            invalid_bid = 0;
                        }
                        else if (bid > users[num_users-1].credits)
                        {
                            printf("Invalid bid. You do not have enough credits.\n");
                        }
                    }

                    if (invalid_bid) 
                    {
                        printf("All bids are invalid.\n");
                        break;
                    }

                    printf("\nThe winner of %s is %s with a bid of %d credits!\n", items[highest_bid_item].name, items[highest_bid_item].highest_bidder, highest_bid);

                    for (int i = 0; i < num_users; i++) 
                    {
                        if (strcmp(users[i].name, items[highest_bid_item].highest_bidder) == 0) 
                        {
                            users[i].credits -= highest_bid;
                            items[highest_bid_item].current_bid = highest_bid;
                            break;
                        }
                    }

                    printf("\nContinue auction? (Y/N): ");
                    fgets(input, sizeof(input), stdin);

                    if (input[0] == 'N' || input[0] == 'n') 
                    {
                        break;
                    }
                }
                break;

            case 3:
                printf("\nItems:\n");
                for (int i = 0; i < num_items; i++) 
                {
                    printf("Item %d: %s\n", i+1, items[i].name);
                    printf("Current bid: %d\n", items[i].current_bid);
                    printf("Highest bidder: %s\n", items[i].highest_bidder);
                }
                break;

            case 4:
                printf("\nUsers:\n");
                for (int i = 0; i < num_users; i++) 
                {
                    printf("User %d: %s\n", i+1, users[i].name);
                    printf("Credits: %d\n", users[i].credits);
                }
                break;

            case 5:
                printf("\nExiting Digital Auction System...\n");
                exit(0);

            default:
                printf("\nInvalid option. Please try again.\n");
        }
    }

    return 0;
}
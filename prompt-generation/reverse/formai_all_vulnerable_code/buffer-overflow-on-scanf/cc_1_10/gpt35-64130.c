//FormAI DATASET v1.0 Category: Digital Auction System ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct for an item in the auction
typedef struct item {
    char name[50];
    char description[200];
    float curr_bid;
    char curr_bidder[50];
} Item;

// Function to display the menu options
void display_menu() {
    printf("\nWelcome to the Digital Auction System!\n");
    printf("1. Add an item\n");
    printf("2. View all items\n");
    printf("3. Place a bid\n");
    printf("4. Exit\n");
    printf("Please enter your choice (1-4): ");
}

int main() {

    int choice, num_items = 0;
    Item *items = NULL;

    printf("How many items do you want to auction? ");
    scanf("%d", &num_items);

    items = (Item*) malloc(num_items * sizeof(Item));

    // Loop until the user chooses to exit
    do {
        display_menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                // Add a new item to the auction
                if (num_items > 0) {
                    printf("\nEnter the details of the item:\n");

                    // Get name
                    printf("Name: ");
                    scanf("%s", items[num_items-1].name);

                    // Get description
                    printf("Description: ");
                    scanf("%s", items[num_items-1].description);

                    // Set initial bid to 0
                    items[num_items-1].curr_bid = 0;

                    // Set current bidder to "None"
                    strcpy(items[num_items-1].curr_bidder, "None");

                    num_items--;
                }
                else {
                    printf("\nYou have added all the items you specified earlier.\n");
                }
                break;
            case 2:
                // View all items in the auction
                if (num_items == 0) {
                    printf("\nAuction Items:\n");
                    printf("Name\t\tDescription\t\tCurrent Bid\t\tCurrent Bidder\n");
                    for (int i=0; i<num_items; i++) {
                        printf("%s\t\t%s\t\t%f\t\t%s\n", items[i].name, items[i].description, items[i].curr_bid, items[i].curr_bidder);
                    }
                }
                else {
                    printf("\nYou must add at least 1 item before you can view the auction items.\n");
                }
                break;
            case 3:
                // Place a bid on an item
                if (num_items == 0) {
                    char item_name[50];
                    printf("\nEnter the name of the item you want to bid on: ");
                    scanf("%s", item_name);

                    for (int i=0; i<num_items; i++) {
                        if (strcmp(items[i].name, item_name) == 0) {
                            float new_bid;
                            printf("Enter your bid for %s: ", item_name);
                            scanf("%f", &new_bid);

                            if (new_bid > items[i].curr_bid) {
                                items[i].curr_bid = new_bid;
                                printf("Your bid of %f for %s has been accepted!\n", new_bid, item_name);
                                strcpy(items[i].curr_bidder, "You");
                            }
                            else {
                                printf("Your bid of %f for %s is not higher than the current bid of %f.\n", new_bid, item_name, items[i].curr_bid);
                            }
                        }
                    }
                }
                else {
                    printf("\nYou must add at least 1 item before you can place a bid.\n");
                }
                break;
            case 4:
                // Exit the program
                printf("\nThank you for using the Digital Auction System!\n");
                break;
            default:
                // Invalid choice
                printf("\nInvalid choice. Please enter a number between 1 and 4.\n");
                break;
        }

    } while (choice != 4);

    free(items);

    return 0;
}
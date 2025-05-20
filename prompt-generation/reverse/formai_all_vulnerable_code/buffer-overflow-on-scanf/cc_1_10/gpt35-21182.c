//FormAI DATASET v1.0 Category: Digital Auction System ; Style: all-encompassing
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct auction_item {
    int id;
    char name[50];
    char description[100];
    float base_price;
    float current_bid;
    char bidder[50];
    int status;
};

void print_item_details(struct auction_item item) {
    printf("ID: %d\n", item.id);
    printf("Name: %s\n", item.name);
    printf("Description: %s\n", item.description);
    printf("Base Price: %.2f\n", item.base_price);
    printf("Current Bid: %.2f\n", item.current_bid);
    printf("Bidder: %s\n", item.bidder);
    printf("Status: %d\n", item.status);
}

int main() {
    struct auction_item items[10];
    int num_items = 0;
    int choice = 0;

    do {
        printf("\nWelcome to the Digital Auction System!\n");
        printf("1. Add Item\n");
        printf("2. List Items\n");
        printf("3. Start Auction\n");
        printf("4. End Auction\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                if(num_items >= 10) {
                    printf("Maximum items limit reached. Cannot add more items.\n");
                    break;
                }

                struct auction_item new_item;
                printf("Enter ID: ");
                scanf("%d", &new_item.id);
                printf("Enter Name: ");
                scanf("%s", new_item.name);
                printf("Enter Description: ");
                scanf("%s", new_item.description);
                printf("Enter Base Price: ");
                scanf("%f", &new_item.base_price);
                new_item.current_bid = 0;
                strcpy(new_item.bidder, "");
                new_item.status = 0;

                items[num_items] = new_item;
                num_items++;

                printf("Item added successfully!\n");
                break;

            case 2:
                if(num_items == 0) {
                    printf("No items to display.\n");
                    break;
                }

                printf("Details of all items:\n");
                for(int i = 0; i < num_items; i++) {
                    printf("------------------------------------------------------------------\n");
                    print_item_details(items[i]);
                }
                printf("------------------------------------------------------------------\n");

                break;

            case 3:
                if(num_items == 0) {
                    printf("No items to start auction.\n");
                    break;
                }

                for(int i = 0; i < num_items; i++) {
                    if(items[i].status == 1) {
                        printf("Auction for item %d has already started.\n", items[i].id);
                        continue;
                    }

                    printf("Starting auction for item %d...\n", items[i].id);
                    items[i].status = 1;
                }
                printf("All item auctions started successfully.\n");

                break;

            case 4:
                if(num_items == 0) {
                    printf("No items to end auction.\n");
                    break;
                }

                for(int i = 0; i < num_items; i++) {
                    if(items[i].status == 0) {
                        printf("Auction for item %d has not started yet.\n", items[i].id);
                        continue;
                    }

                    printf("Ending auction for item %d...\n", items[i].id);

                    if(strcmp(items[i].bidder, "") != 0) {
                        printf("The winning bidder for item %d is %s with a bid of %.2f\n", items[i].id, items[i].bidder, items[i].current_bid);
                    } else {
                        printf("No bids placed for item %d\n", items[i].id);
                    }

                    items[i].status = 0;
                    items[i].current_bid = 0;
                    strcpy(items[i].bidder, "");
                }
                printf("All item auctions ended successfully.\n");

                break;

            case 5:
                printf("Exiting Digital Auction System. Thank you for using!\n");
                exit(0);

            default:
                printf("Invalid choice. Please enter a valid choice.\n");
        }
    } while(1);

    return 0;
}
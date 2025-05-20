//FormAI DATASET v1.0 Category: Digital Auction System ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100           // Maximum number of items that can be auctioned
#define MIN_BID_INCREMENT 10    // Minimum bid increment for an item
#define MAX_VENDORS 10          // Maximum number of vendors allowed

typedef struct {
    int item_id;                // Unique ID assigned to each item
    char item_name[50];         // Name of the item being auctioned
    int starting_price;         // Starting price for the item
    int current_bid;            // Current bid for the item
    int current_bidder;         // ID of the current highest bidder
    int status;                 // Status of item - available (0) or sold (1)
} item_t;

typedef struct {
    int vendor_id;              // Unique ID assigned to each vendor
    char vendor_name[50];       // Name of the vendor
    int items_auctioned[MAX_ITEMS]; // IDs of items auctioned by the vendor
    int num_items_auctioned;    // Number of items auctioned by the vendor
} vendor_t;

item_t items[MAX_ITEMS];        // Array to store all the items being auctioned
int num_items = 0;              // Current number of items being auctioned
vendor_t vendors[MAX_VENDORS];  // Array to store all the vendors participating in the auction
int num_vendors = 0;            // Current number of vendors participating in the auction

// Function to add a new item to the auction
void add_item() {
    int id, price;
    char name[50];

    printf("Enter item name: ");
    scanf("%s", name);
    printf("Enter starting price: ");
    scanf("%d", &price);

    // Assign a unique ID to the new item
    id = num_items + 1;

    // Initialize the values for the new item
    items[num_items].item_id = id;
    strcpy(items[num_items].item_name, name);
    items[num_items].starting_price = price;
    items[num_items].current_bid = price;
    items[num_items].current_bidder = -1; // No bidder yet
    items[num_items].status = 0;

    // Increment the number of items being auctioned
    num_items++;

    printf("Item added successfully!\n");
}

// Function to check if a vendor with the given ID exists
int vendor_exists(int vendor_id) {
    int i;

    for (i = 0; i < num_vendors; i++) {
        if (vendors[i].vendor_id == vendor_id) {
            return 1;
        }
    }

    return 0;
}

// Function to add a new vendor to the auction
void add_vendor() {
    int id;
    char name[50];

    printf("Enter vendor name: ");
    scanf("%s", name);

    // Assign a unique ID to the new vendor
    id = num_vendors + 1;

    // Initialize the values for the new vendor
    vendors[num_vendors].vendor_id = id;
    strcpy(vendors[num_vendors].vendor_name, name);
    vendors[num_vendors].num_items_auctioned = 0;

    // Increment the number of vendors participating in the auction
    num_vendors++;

    printf("Vendor added successfully!\n");
}

// Function to display the list of items being auctioned
void display_items() {
    int i;

    printf("ID\tName\t\tStarting Price\tCurrent Bid\tCurrent Bidder\n");
    printf("-----------------------------------------------------------------\n");

    for (i = 0; i < num_items; i++) {
        if (items[i].status == 0) {
            printf("%d\t%s\t%d\t\t%d\t\t%d\n", items[i].item_id, items[i].item_name, items[i].starting_price,
                   items[i].current_bid, items[i].current_bidder);
        }
    }
}

// Function to display the list of vendors participating in the auction
void display_vendors() {
    int i;

    printf("Vendor ID\tVendor Name\n");
    printf("---------------------------\n");

    for (i = 0; i < num_vendors; i++) {
        printf("%d\t\t%s\n", vendors[i].vendor_id, vendors[i].vendor_name);
    }
}

// Function to search for an item with the given ID
int find_item(int item_id) {
    int i;

    for (i = 0; i < num_items; i++) {
        if (items[i].item_id == item_id) {
            return i;
        }
    }

    return -1;
}

// Function to handle a bid for a particular item
void handle_bid(int item_id, int bidder_id, int bid_amount) {
    int item_index = find_item(item_id);

    if (item_index < 0) {
        printf("Item not found!\n");
    } else {
        if (bid_amount < items[item_index].current_bid + MIN_BID_INCREMENT) {
            printf("Bid amount must be at least %d more than the current bid!\n", MIN_BID_INCREMENT);
        } else {
            items[item_index].current_bid = bid_amount;
            items[item_index].current_bidder = bidder_id;

            printf("Bid accepted for item %d by bidder %d for amount %d!\n", item_id, bidder_id, bid_amount);
        }
    }
}

// Function to handle the closing of an item's auction
void handle_closing_auction(int item_id) {
    int item_index = find_item(item_id);

    if (item_index < 0) {
        printf("Item not found!\n");
    } else {
        items[item_index].status = 1;

        printf("Auction closed for item %d! Winner is bidder %d with a bid of %d.\n", item_id, items[item_index].current_bidder,
               items[item_index].current_bid);
    }
}

int main() {
    int choice, vendor_id, item_id, bid_amount;

    do {
        printf("Auction Menu:\n");
        printf("1. Add item\n");
        printf("2. Add vendor\n");
        printf("3. Display items\n");
        printf("4. Display vendors\n");
        printf("5. Bid on item\n");
        printf("6. Close auction for item\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                add_item();
                break;
            case 2:
                add_vendor();
                break;
            case 3:
                display_items();
                break;
            case 4:
                display_vendors();
                break;
            case 5:
                printf("Enter vendor ID: ");
                scanf("%d", &vendor_id);
                if (!vendor_exists(vendor_id)) {
                    printf("Vendor not found!\n");
                } else {
                    printf("Enter item ID: ");
                    scanf("%d", &item_id);
                    if (find_item(item_id) < 0) {
                        printf("Item not found!\n");
                    } else {
                        printf("Enter bid amount: ");
                        scanf("%d", &bid_amount);
                        handle_bid(item_id, vendor_id, bid_amount);
                    }
                }
                break;
            case 6:
                printf("Enter item ID: ");
                scanf("%d", &item_id);
                handle_closing_auction(item_id);
                break;
            case 7:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while(choice != 7);

    return 0;
}
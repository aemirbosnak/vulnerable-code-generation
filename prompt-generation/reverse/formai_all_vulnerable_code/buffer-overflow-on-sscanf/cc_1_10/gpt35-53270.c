//FormAI DATASET v1.0 Category: Digital Auction System ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Constants
#define MAX_ITEMS 100         // Maximum number of items that can be auctioned
#define MAX_DIGITS 10         // Maximum number of digits in item id
#define MAX_BIDDERS 20        // Maximum number of bidders in one item
#define MAX_BID_DIGITS 10     // Maximum number of digits in bid amount
#define MAX_NAME_LENGTH 50    // Maximum length of bidder's name
#define MAX_FILENAME_LENGTH 50 // Maximum length of filename

// Structs
typedef struct {
    int id;
    char name[MAX_NAME_LENGTH];
} Bidder;

typedef struct {
    int id;
    char name[MAX_NAME_LENGTH];
    int num_bidders;
    Bidder bidders[MAX_BIDDERS];
    char highest_bidder_name[MAX_NAME_LENGTH];
    double highest_bid_amount;
} Item;

// Function prototypes
void print_menu();
void add_item(Item* items, int* num_items);
void add_bidder(Item* items, int num_items);
void place_bid(Item* items, int num_items);
void view_auctions(Item* items, int num_items);
void write_to_file(Item* items, int num_items);
void read_from_file(Item* items, int* num_items);

int main() {
    // Initialize
    Item items[MAX_ITEMS];
    int num_items = 0;
    char input;

    // Loop until user quits
    do {
        print_menu();
        scanf(" %c", &input);

        switch (input) {
            case '1':
                add_item(items, &num_items);
                break;
            case '2':
                add_bidder(items, num_items);
                break;
            case '3':
                place_bid(items, num_items);
                break;
            case '4':
                view_auctions(items, num_items);
                break;
            case '5':
                write_to_file(items, num_items);
                break;
            case '6':
                read_from_file(items, &num_items);
                break;
            case 'q':
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid input.\n");
        }
    } while (input != 'q');

    return 0;
}

void print_menu() {
    printf("\n1. Add item\n");
    printf("2. Add bidder to item\n");
    printf("3. Place bid on item\n");
    printf("4. View all auctions and their highest bidders\n");
    printf("5. Write auctions to file\n");
    printf("6. Read auctions from file\n");
    printf("q. Quit\n");
}

void add_item(Item* items, int* num_items) {
    if (*num_items == MAX_ITEMS) {
        printf("Sorry, the maximum number of items has been reached. No more items can be added.\n");
        return;
    }

    Item new_item;
    printf("Enter item id (max %d digits): ", MAX_DIGITS);
    scanf("%d", &new_item.id);

    // Check if item id already exists
    for (int i = 0; i < *num_items; i++) {
        if (items[i].id == new_item.id) {
            printf("An item with this id already exists.\n");
            return;
        }
    }

    printf("Enter item name (max %d characters): ", MAX_NAME_LENGTH);
    scanf(" %[^\n]", new_item.name);
    new_item.num_bidders = 0;
    new_item.highest_bid_amount = 0;

    items[*num_items] = new_item;
    *num_items += 1;

    printf("Item successfully added.\n");
}

void add_bidder(Item* items, int num_items) {
    if (num_items == 0) {
        printf("No items have been added yet. Please add an item first.\n");
        return;
    }

    int item_id;
    printf("Enter item id: ");
    scanf("%d", &item_id);

    int item_index = -1;
    for (int i = 0; i < num_items; i++) {
        if (items[i].id == item_id) {
            item_index = i;
            break;
        }
    }

    if (item_index == -1) {
        printf("No item with this id exists.\n");
        return;
    }

    if (items[item_index].num_bidders == MAX_BIDDERS) {
        printf("Sorry, no more bidders can be added to this item.\n");
        return;
    }

    Bidder new_bidder;
    printf("Enter bidder name (max %d characters): ", MAX_NAME_LENGTH);
    scanf(" %[^\n]", new_bidder.name);

    // Check if bidder is already in the list
    for (int i = 0; i < items[item_index].num_bidders; i++) {
        if (strcmp(items[item_index].bidders[i].name, new_bidder.name) == 0) {
            printf("This bidder has already been added to the item.\n");
            return;
        }
    }

    new_bidder.id = items[item_index].num_bidders + 1;
    items[item_index].bidders[items[item_index].num_bidders] = new_bidder;
    items[item_index].num_bidders++;

    printf("Bidder successfully added to item.\n");
}

void place_bid(Item* items, int num_items) {
    if (num_items == 0) {
        printf("No items have been added yet. Please add an item first.\n");
        return;
    }

    int item_id;
    printf("Enter item id: ");
    scanf("%d", &item_id);

    int item_index = -1;
    for (int i = 0; i < num_items; i++) {
        if (items[i].id == item_id) {
            item_index = i;
            break;
        }
    }

    if (item_index == -1) {
        printf("No item with this id exists.\n");
        return;
    }

    if (items[item_index].num_bidders == 0) {
        printf("No bidders have been added to this item yet. Please add a bidder first.\n");
        return;
    }

    double bid_amount;
    printf("Enter bid amount (max %d digits): $", MAX_BID_DIGITS);
    scanf("%lf", &bid_amount);

    if (bid_amount <= items[item_index].highest_bid_amount) {
        printf("Your bid must be higher than the current highest bid of $%.2lf.\n", items[item_index].highest_bid_amount);
        return;
    }

    char bidder_name[MAX_NAME_LENGTH];
    printf("Enter bidder name (max %d characters): ", MAX_NAME_LENGTH);
    scanf(" %[^\n]", bidder_name);

    int bidder_index = -1;
    for (int i = 0; i < items[item_index].num_bidders; i++) {
        if (strcmp(items[item_index].bidders[i].name, bidder_name) == 0) {
            bidder_index = i;
            break;
        }
    }

    if (bidder_index == -1) {
        printf("No bidder with this name exists for this item.\n");
        return;
    }

    strcpy(items[item_index].highest_bidder_name, bidder_name);
    items[item_index].highest_bid_amount = bid_amount;

    printf("Bid successfully placed.\n");
}

void view_auctions(Item* items, int num_items) {
    if (num_items == 0) {
        printf("No items have been added yet. Please add an item first.\n");
        return;
    }

    printf("All auctions:\n");
    printf("Item ID\tItem Name\tHighest Bidder\tBid Amount\n");
    printf("----------------------------------------------------\n");
    for (int i = 0; i < num_items; i++) {
        printf("%d\t%s\t%s\t$%.2lf\n", items[i].id, items[i].name, items[i].highest_bidder_name, items[i].highest_bid_amount);
    }
}

void write_to_file(Item* items, int num_items) {
    if (num_items == 0) {
        printf("No items have been added yet. Please add an item first.\n");
        return;
    }

    char filename[MAX_FILENAME_LENGTH];
    printf("Enter filename to save auctions to: ");
    scanf("%s", filename);

    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }

    fprintf(file, "Item ID,Item Name,Highest Bidder,Bid Amount\n");
    for (int i = 0; i < num_items; i++) {
        fprintf(file, "%d,%s,%s,$%.2lf\n", items[i].id, items[i].name, items[i].highest_bidder_name, items[i].highest_bid_amount);
    }

    fclose(file);
    printf("Auctions successfully saved to file.\n");
}

void read_from_file(Item* items, int* num_items) {
    char filename[MAX_FILENAME_LENGTH];
    printf("Enter filename to read auctions from: ");
    scanf("%s", filename);

    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }

    // Clear all existing items
    *num_items = 0;

    // Read file and create items
    char line[100];
    fgets(line, 100, file); // Skip first line
    while (fgets(line, 100, file) != NULL) {
        Item new_item;
        sscanf(line, "%d,%[^,],%[^,],$%lf\n", &new_item.id, new_item.name, new_item.highest_bidder_name, &new_item.highest_bid_amount);

        // Count number of bidders for this item
        int num_bidders = 0;
        for (int i = 0; i < strlen(line); i++) {
            if (line[i] == ',') {
                num_bidders++;
            }
        }

        num_bidders -= 3; // Subtract 3 because we only want to count bidders, not id, name, and amount

        // Read bidders
        for (int i = 0; i < num_bidders; i++) {
            Bidder new_bidder;
            fgets(line, 100, file);
            sscanf(line, "%d,%[^,],", &new_bidder.id, new_bidder.name);
            new_item.bidders[i] = new_bidder;
        }

        new_item.num_bidders = num_bidders;
        items[*num_items] = new_item;
        *num_items += 1;
    }

    fclose(file);

    printf("Auctions successfully read from file.\n");
}
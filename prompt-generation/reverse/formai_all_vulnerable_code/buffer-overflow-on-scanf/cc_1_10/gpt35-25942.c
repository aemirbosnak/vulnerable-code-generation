//FormAI DATASET v1.0 Category: Digital Auction System ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERS 10
#define MAX_BIDS 50

typedef struct Bid {
    int user_id;
    float amount;
} Bid;

typedef struct Item {
    int id;
    char name[50];
    float starting_price;
    float current_bid;
    Bid bids[MAX_BIDS];
    int num_bids;
} Item;

typedef struct User {
    int id;
    char username[50];
    float balance;
} User;

void print_header(char* title);
int get_input_int(char* message);
float get_input_float(char* message);
void add_user(User* users, int* num_users);
void add_item(Item* items, int* num_items, User* users, int num_users);
void view_items(Item* items, int num_items);
void bid_on_item(Item* item);
void close_auction(Item* item, User* users, int num_users);
void print_items(Item* items, int num_items, char* message);

int main() {
    User users[MAX_USERS];
    int num_users = 0;

    Item items[MAX_BIDS];
    int num_items = 0;

    int choice;

    while(1) {
        print_header("C Digital Auction System");
        printf("1. Add user\n");
        printf("2. Add item\n");
        printf("3. View items\n");
        printf("4. Bid on item\n");
        printf("5. Close auction\n");
        printf("6. Exit\n");

        choice = get_input_int("Please enter your choice: ");

        switch(choice) {
            case 1:
                add_user(users, &num_users);
                break;
            case 2:
                add_item(items, &num_items, users, num_users);
                break;
            case 3:
                view_items(items, num_items);
                break;
            case 4:
                bid_on_item(items);
                break;
            case 5:
                close_auction(items, users, num_users);
                break;
            case 6:
                printf("Thank you for using the C Digital Auction System!\n");
                exit(0);
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

void print_header(char* title) {
    system("clear");
    printf("********************************************\n");
    printf("* %s *\n", title);
    printf("********************************************\n");
}

int get_input_int(char* message) {
    int num;
    printf("%s", message);
    scanf("%d", &num);
    return num;
}

float get_input_float(char* message) {
    float num;
    printf("%s", message);
    scanf("%f", &num);
    return num;
}

void add_user(User* users, int* num_users) {
    if(*num_users == MAX_USERS) {
        printf("Sorry, can't add any more users. The limit is %d.\n", MAX_USERS);
        return;
    }
    users[*num_users].id = *num_users + 1;
    printf("Enter username: ");
    scanf("%s", users[*num_users].username);
    printf("Enter balance: ");
    scanf("%f", &users[*num_users].balance);
    printf("User added successfully!\n");
    (*num_users)++;
}

void add_item(Item* items, int* num_items, User* users, int num_users) {
    if(*num_items == MAX_BIDS) {
        printf("Sorry, can't add any more items. The limit is %d.\n", MAX_BIDS);
        return;
    }
    items[*num_items].id = *num_items + 1;
    printf("Enter item name: ");
    scanf("%s", items[*num_items].name);
    items[*num_items].starting_price = get_input_float("Enter starting price: ");
    items[*num_items].current_bid = items[*num_items].starting_price;
    printf("Which user is selling this item?\n");
    print_items(users, num_users, "Select user by ID:");
    int user_id;
    while(1) {
        user_id = get_input_int("Enter user ID: ");
        if(user_id >= 1 && user_id <= num_users) {
            break;
        }
        printf("Invalid user ID. Please try again.\n");
    }
    items[*num_items].bids[0].user_id = user_id;
    items[*num_items].num_bids = 1;
    printf("Item added successfully!\n");
    (*num_items)++;
}

void view_items(Item* items, int num_items) {
    if(num_items == 0) {
        printf("No items to display.\n");
        return;
    }
    print_items(items, num_items, "Items currently available:");
    int item_id;
    while(1) {
        item_id = get_input_int("Enter item ID to view details: ");
        if(item_id >= 1 && item_id <= num_items) {
            break;
        }
        printf("Invalid item ID. Please try again.\n");
    }
    print_header("Item details");
    printf("Item name: %s\n", items[item_id-1].name);
    printf("Starting price: %.2f\n", items[item_id-1].starting_price);
    printf("Current bid: %.2f\n", items[item_id-1].current_bid);
    printf("Bids on this item:\n");
    printf("User ID | Bid amount\n");
    for(int i = 0; i < items[item_id-1].num_bids; i++) {
        printf("%7d | %.2f\n", items[item_id-1].bids[i].user_id, items[item_id-1].bids[i].amount);
    }
    printf("Press ENTER to go back.");
    getchar();
    while(getchar() != '\n');
}

void bid_on_item(Item* items) {
    if(items == NULL) {
        printf("No items to bid on.\n");
        return;
    }
    print_items(items, MAX_BIDS, "Select item by ID:");
    int item_id;
    while(1) {
        item_id = get_input_int("Enter item ID: ");
        if(item_id >= 1 && item_id <= MAX_BIDS && item_id <= MAX_BIDS && items[item_id-1].id) {
            break;
        }
        printf("Invalid item ID. Please try again.\n");
    }
    float bid_amount = get_input_float("Enter bid amount: ");
    if(bid_amount <= items[item_id-1].current_bid) {
        printf("Your bid must be higher than the current bid.\n");
        return;
    }
    if(bid_amount > items[item_id-1].current_bid * 1.05) {
        printf("Your bid is too high. The maximum increase is 5%% of current bid.\n");
        return;
    }
    items[item_id-1].current_bid = bid_amount;
    int user_id;
    while(1) {
        user_id = get_input_int("Enter user ID: ");
        if(user_id >= 1 && user_id <= MAX_USERS && user_id <= MAX_USERS) {
            break;
        }
        printf("Invalid user ID. Please try again.\n");
    }
    int num_bids = items[item_id-1].num_bids;
    items[item_id-1].bids[num_bids].user_id = user_id;
    items[item_id-1].bids[num_bids].amount = bid_amount;
    items[item_id-1].num_bids++;
    printf("Your bid has been placed!\n");
}

void close_auction(Item* items, User* users, int num_users) {
    if(items == NULL) {
        printf("No items to close.\n");
        return;
    }
    print_items(items, MAX_BIDS, "Select item by ID:");
    int item_id;
    while(1) {
        item_id = get_input_int("Enter item ID: ");
        if(item_id >= 1 && item_id <= MAX_BIDS && item_id <= MAX_BIDS && items[item_id-1].id) {
            break;
        }
        printf("Invalid item ID. Please try again.\n");
    }
    Item item = items[item_id-1];
    User seller = users[item.bids[0].user_id-1];
    User highest_bidder;
    float highest_bid = 0;
    for(int i = 1; i < item.num_bids; i++) {
        if(item.bids[i].amount > highest_bid) {
            highest_bid = item.bids[i].amount;
            highest_bidder = users[item.bids[i].user_id-1];
        }
    }
    if(highest_bidder.balance < highest_bid) {
        printf("The highest bidder does not have enough balance to purchase the item.\n");
        printf("The item will remain unsold.\n");
        return;
    }
    seller.balance += item.current_bid;
    highest_bidder.balance -= item.current_bid;
    printf("Auction closed successfully!\n");
    printf("%s has sold their %s for %.2f.\n", seller.username, item.name, item.current_bid);
    printf("%s has purchased the item for %.2f\n", highest_bidder.username, item.current_bid);
    // remove item from list
    items[item_id-1].id = 0;
    items[item_id-1].name[0] = '\0';
    items[item_id-1].starting_price = 0;
    items[item_id-1].current_bid = 0;
    items[item_id-1].num_bids = 0;
    for(int i = 0; i < MAX_BIDS; i++) {
        items[item_id-1].bids[i].user_id = 0;
        items[item_id-1].bids[i].amount = 0;
    }
}

void print_items(Item* items, int num_items, char* message) {
    printf("%s\n", message);
    printf("ID | Name | Starting Price | Current Bid\n");
    for(int i = 0; i < num_items; i++) {
        Item item = items[i];
        if(item.id) {
            printf("%2d | %-20s | %14.2f | %11.2f\n", item.id, item.name, item.starting_price, item.current_bid);
        }
    }
}
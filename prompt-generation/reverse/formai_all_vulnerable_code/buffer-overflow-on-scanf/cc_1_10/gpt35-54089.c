//FormAI DATASET v1.0 Category: Digital Auction System ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// defining the limit for the items and users
#define MAX_ITEMS 10
#define MAX_USERS 10

// defining the structure for the item
struct item {
    int item_id;
    char item_name[100];
    float item_price;
    int seller_id;
    int buyer_id;
};

// defining the structure for a user
struct user {
    int user_id;
    char username[100];
    float balance;
};

// declaring the global variables
struct item items[MAX_ITEMS];
struct user users[MAX_USERS];
int item_count = 0;
int user_count = 0;

// function to add an item
void add_item() {
    if (item_count >= MAX_ITEMS) {
        printf("Cannot add more items!\n");
        return;
    }

    // getting the input from the user
    int seller_id;
    printf("Enter seller ID: ");
    scanf("%d", &seller_id);

    char name[100];
    float price;
    printf("\nEnter item name: ");
    scanf("%s", name);
    printf("\nEnter item price: ");
    scanf("%f", &price);

    // creating and adding the item to the items array
    struct item new_item = {
        item_count + 1,
        name,
        price,
        seller_id,
        0
    };

    items[item_count] = new_item;
    item_count++;

    printf("\nItem added successfully!\n");
}

// function to view all the items
void view_items() {
    if (item_count == 0) {
        printf("\nNo items added yet!\n");
        return;
    }

    printf("\nItem ID\tItem Name\tItem Price\tSeller ID\n");
    for (int i = 0; i < item_count; i++) {
        printf("%d\t%s\t%f\t%d\n", items[i].item_id, items[i].item_name, items[i].item_price, items[i].seller_id);
    }
}

// function to register a new user
void register_user() {
    if (user_count >= MAX_USERS) {
        printf("Cannot register more users!\n");
        return;
    }

    // getting the input from the user
    char username[100];
    float balance;
    printf("\nEnter username: ");
    scanf("%s", username);
    printf("\nEnter balance: ");
    scanf("%f", &balance);

    // creating and adding the user to the users array
    struct user new_user = {
        user_count + 1,
        username,
        balance
    };

    users[user_count] = new_user;
    user_count++;

    printf("\nUser registered successfully!\n");
}

// function to view all the users
void view_users() {
    if (user_count == 0) {
        printf("\nNo users registered yet!\n");
        return;
    }

    printf("\nUser ID\tUsername\tBalance\n");
    for (int i = 0; i < user_count; i++) {
        printf("%d\t%s\t%f\n", users[i].user_id, users[i].username, users[i].balance);
    }
}

// function to bid on an item
void bid_item() {
    if (item_count == 0) {
        printf("\nNo items added yet!\n");
        return;
    }

    // getting the input from the user
    int buyer_id, item_id;
    float bid_price;
    printf("Enter buyer ID: ");
    scanf("%d", &buyer_id);
    printf("\nEnter item ID to bid on: ");
    scanf("%d", &item_id);
    printf("\nEnter bid price: ");
    scanf("%f", &bid_price);

    // checking if the buyer has enough balance to place the bid
    if (users[buyer_id - 1].balance < bid_price) {
        printf("\nNot enough balance to place bid!\n");
        return;
    }

    // finding the item to bid on
    struct item *item = NULL;
    for (int i = 0; i < item_count; i++) {
        if (items[i].item_id == item_id) {
            item = &items[i];
            break;
        }
    }

    if (item == NULL) {
        printf("\nInvalid item ID!\n");
        return;
    }

    // checking if the bid price is higher than the current price of the item
    if (bid_price <= item->item_price) {
        printf("\nBid price should be higher than current price of the item!\n");
        return;
    }

    // updating the item and user information
    item->item_price = bid_price;
    item->buyer_id = buyer_id;
    users[buyer_id - 1].balance -= bid_price;

    printf("\nBid placed successfully!\n");
}

int main() {
    int choice;

    do {
        printf("\nDigital Auction System\n");
        printf("----------------------\n");
        printf("1. Add Item\n");
        printf("2. View Items\n");
        printf("3. Register User\n");
        printf("4. View Users\n");
        printf("5. Bid Item\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_item();
                break;

            case 2:
                view_items();
                break;

            case 3:
                register_user();
                break;

            case 4:
                view_users();
                break;

            case 5:
                bid_item();
                break;

            case 6:
                printf("\nExiting...\n");
                break;

            default:
                printf("\nInvalid choice! Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}
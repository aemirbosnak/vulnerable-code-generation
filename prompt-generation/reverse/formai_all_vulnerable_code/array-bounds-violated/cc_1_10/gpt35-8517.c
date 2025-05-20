//FormAI DATASET v1.0 Category: Digital Auction System ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_NAME_LENGTH 50

typedef struct item {
    int id;
    char name[MAX_NAME_LENGTH];
    float price;
} Item;

typedef struct bid {
    int id;
    char name[MAX_NAME_LENGTH];
    float amount;
    struct bid *next;
} Bid;

Item items[MAX_ITEMS];
int num_items = 0;
Bid *first_bid = NULL;

void add_item() {
    if (num_items >= MAX_ITEMS) {
        printf("Maximum number of items reached!\n");
        return;
    }

    Item new_item;
    new_item.id = num_items + 1;

    printf("Enter item name: ");
    fgets(new_item.name, MAX_NAME_LENGTH, stdin);
    new_item.name[strlen(new_item.name)-1] = '\0'; // remove newline char

    printf("Enter starting price: ");
    scanf("%f", &new_item.price);
    getchar(); // remove newline char

    items[num_items] = new_item;
    num_items++;

    printf("Item added successfully!\n");
}

void view_items() {
    printf("Items for auction:\n");
    for (int i = 0; i < num_items; i++) {
        printf("%d. %s - $%.2f\n", items[i].id, items[i].name, items[i].price);
    }
}

void place_bid(int item_id) {
    int item_index = item_id - 1;
    if (item_index < 0 || item_index >= num_items) {
        printf("Invalid item ID!\n");
        return;
    }

    Bid new_bid;
    new_bid.id = item_id;

    printf("Enter your name: ");
    fgets(new_bid.name, MAX_NAME_LENGTH, stdin);
    new_bid.name[strlen(new_bid.name)-1] = '\0'; // remove newline char

    printf("Enter bid amount: ");
    scanf("%f", &new_bid.amount);
    getchar(); // remove newline char

    // insert new bid in sorted order
    Bid **prev_bid = &first_bid;
    Bid *curr_bid = first_bid;
    while (curr_bid != NULL && curr_bid->id <= item_id && curr_bid->amount > new_bid.amount) {
        prev_bid = &curr_bid->next;
        curr_bid = curr_bid->next;
    }

    new_bid.next = curr_bid;
    *prev_bid = &new_bid;

    printf("Bid placed successfully!\n");
}

void view_bids(int item_id) {
    printf("Bids for item %d:\n", item_id);

    Bid *curr_bid = first_bid;
    while (curr_bid != NULL && curr_bid->id == item_id) {
        printf("%s - $%.2f\n", curr_bid->name, curr_bid->amount);
        curr_bid = curr_bid->next;
    }
}

void display_menu() {
    printf("\n*** Digital Auction System ***\n");
    printf("1. Add item\n");
    printf("2. View items\n");
    printf("3. Place bid\n");
    printf("4. View bids\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");
}

void handle_choice(int choice) {
    int item_id;

    switch (choice) {
        case 1:
            add_item();
            break;
        case 2:
            view_items();
            break;
        case 3:
            printf("Enter item ID: ");
            scanf("%d", &item_id);
            getchar(); // remove newline char
            place_bid(item_id);
            break;
        case 4:
            printf("Enter item ID: ");
            scanf("%d", &item_id);
            getchar(); // remove newline char
            view_bids(item_id);
            break;
        case 5:
            printf("Exiting program...\n");
            exit(0);
            break;
        default:
            printf("Invalid choice!\n");
    }

    display_menu();
    int new_choice;
    scanf("%d", &new_choice);
    getchar(); // remove newline char
    handle_choice(new_choice);
}

int main() {
    display_menu();
    int choice;
    scanf("%d", &choice);
    getchar(); // remove newline char
    handle_choice(choice);
    return 0;
}
//FormAI DATASET v1.0 Category: Digital Auction System ; Style: statistical
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ITEMS 100
#define MAX_BIDDERS 10

struct item {
    int id;
    char name[50];
    double start_price;
    double current_bid;
    int bidder_id;
};

struct bidder {
    int id;
    char name[50];
    double balance;
};

int num_items = 0;
int num_bidders = 0;

struct item items[MAX_ITEMS];
struct bidder bidders[MAX_BIDDERS];

void add_item(char*, double);
void add_bidder(char*, double);
void list_items();
void list_bidders();
void place_bid(int, double, int);
int get_bidder(double);
void run_auction();

int main() {
    char name[50];
    double price;
    int choice, item_id, bidder_id;
    srand(time(NULL));

    while (1) {
        printf("1. Add item\n2. Add bidder\n3. List items\n4. List bidders\n5. Run auction\n6. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter item name: ");
                scanf("%s", name);
                printf("Enter starting price: ");
                scanf("%lf", &price);
                add_item(name, price);
                break;
            case 2:
                printf("Enter bidder name: ");
                scanf("%s", name);
                printf("Enter balance: ");
                scanf("%lf", &price);
                add_bidder(name, price);
                break;
            case 3:
                list_items();
                break;
            case 4:
                list_bidders();
                break;
            case 5:
                run_auction();
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice!\n");
                break;
        }
    }
    return 0;
}

void add_item(char* name, double price) {
    if (num_items == MAX_ITEMS) {
        printf("Maximum number of items reached!\n");
        return;
    }
    items[num_items].id = rand() % 1000;
    strcpy(items[num_items].name, name);
    items[num_items].start_price = price;
    items[num_items].current_bid = price;
    items[num_items].bidder_id = -1;
    num_items++;
    printf("Item added successfully!\n");
}

void add_bidder(char* name, double balance) {
    if (num_bidders == MAX_BIDDERS) {
        printf("Maximum number of bidders reached!\n");
        return;
    }
    bidders[num_bidders].id = rand() % 100;
    strcpy(bidders[num_bidders].name, name);
    bidders[num_bidders].balance = balance;
    num_bidders++;
    printf("Bidder added successfully!\n");
}

void list_items() {
    if (num_items == 0) {
        printf("No items found!\n");
        return;
    }
    printf("ID\tItem Name\tStarting Price\tCurrent Bid\tBidder ID\n");
    for (int i = 0; i < num_items; i++) {
        printf("%d\t%s\t%.2lf\t\t%.2lf\t\t", items[i].id, items[i].name, items[i].start_price, items[i].current_bid);
        if (items[i].bidder_id == -1) {
            printf("No bids yet\n");
        } else {
            printf("%d\n", items[i].bidder_id);
        }
    }
}

void list_bidders() {
    if (num_bidders == 0) {
        printf("No bidders found!\n");
        return;
    }
    printf("ID\tBidder Name\tBalance\n");
    for (int i = 0; i < num_bidders; i++) {
        printf("%d\t%s\t%.2lf\n", bidders[i].id, bidders[i].name, bidders[i].balance);
    }
}

void place_bid(int item_id, double bid, int bidder_id) {
    if (bid < items[item_id].current_bid) {
        printf("Bid lower than current bid!\n");
        return;
    }
    if (bid > bidders[bidder_id].balance) {
        printf("Bidder does not have enough balance!\n");
        return;
    }
    if (items[item_id].bidder_id != -1 && items[item_id].bidder_id != bidder_id) {
        bidders[items[item_id].bidder_id].balance += items[item_id].current_bid;
    }
    items[item_id].current_bid = bid;
    items[item_id].bidder_id = bidder_id;
    bidders[bidder_id].balance -= bid;
    printf("Bid placed successfully!\n");
}

int get_bidder(double bid) {
    int max_bidder_id = -1;
    double max_balance = 0;
    for (int i = 0; i < num_bidders; i++) {
        if (bidders[i].balance >= bid && bidders[i].balance > max_balance) {
            max_bidder_id = i;
            max_balance = bidders[i].balance;
        }
    }
    return max_bidder_id;
}

void run_auction() {
    if (num_items == 0) {
        printf("No items found!\n");
        return;
    }
    for (int i = 0; i < num_items; i++) {
        printf("Item ID: %d, Item Name: %s, Starting Price: %.2lf\n", items[i].id, items[i].name, items[i].start_price);
        while (1) {
            printf("Enter bid amount (0 to skip): ");
            double bid;
            int bidder_id;
            scanf("%lf", &bid);
            if (bid == 0) {
                break;
            }
            bidder_id = get_bidder(bid);
            if (bidder_id == -1) {
                printf("No bidders found with sufficient balance!\n");
            } else {
                place_bid(i, bid, bidder_id);
            }
        }
    }
    printf("Auction complete!\n");
}
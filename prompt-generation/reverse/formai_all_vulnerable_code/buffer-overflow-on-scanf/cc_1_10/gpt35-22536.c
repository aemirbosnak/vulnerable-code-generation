//FormAI DATASET v1.0 Category: Digital Auction System ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
    char item_name[50];
    int item_id;
    float auction_price;
    char seller_name[50];
    char buyer_name[50];
} Item;

Item items[10];
int num_items;

void print_menu() {
    printf("1. Add item to auction\n");
    printf("2. Place bid on an item\n");
    printf("3. Display auction items\n");
    printf("4. Exit\n");
}

void add_item() {
    if (num_items < 10) {
        printf("Enter item name: ");
        scanf("%s", items[num_items].item_name);
        printf("Enter item id: ");
        scanf("%d", &items[num_items].item_id);
        printf("Enter auction price: ");
        scanf("%f", &items[num_items].auction_price);
        printf("Enter seller name: ");
        scanf("%s", items[num_items].seller_name);
        strcpy(items[num_items].buyer_name, "");
        num_items++;
        printf("Item added to auction!\n");
    } else {
        printf("Auction is full!\n");
    }
}

void place_bid() {
    int item_id;
    printf("Enter item id: ");
    scanf("%d", &item_id);
    int i;
    for (i = 0; i < num_items; i++) {
        if (items[i].item_id == item_id) {
            float bid;
            printf("Current price: $%.2f\n", items[i].auction_price);
            printf("Enter your bid: ");
            scanf("%f", &bid);
            if (bid > items[i].auction_price) {
                printf("Bid accepted!\n");
                items[i].auction_price = bid;
                printf("New price: $%.2f\n", items[i].auction_price);
                printf("Enter your name: ");
                scanf("%s", items[i].buyer_name);
                return;
            } else {
                printf("Bid too low!\n");
                return;
            }
        }
    }
    printf("Item not found!\n");
}

void print_items() {
    int i;
    printf("| %-10s | %-10s | %-15s | %-15s | %-15s |\n", "Item ID", "Item Name", "Auction Price", "Seller Name", "Buyer Name");
    printf("|------------|------------|----------------|----------------|----------------|\n");
    for (i = 0; i < num_items; i++) {
        printf("| %-10d | %-10s | $%-14.2f | %-15s | %-15s |\n", items[i].item_id, items[i].item_name, items[i].auction_price, items[i].seller_name, items[i].buyer_name);
    }
}

int main() {
    num_items = 0;
    int choice;
    do {
        print_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_item();
                break;
            case 2:
                place_bid();
                break;
            case 3:
                print_items();
                break;
            case 4:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice!\n");
                break;
        }
    } while (choice != 4);
    return 0;
}
//FormAI DATASET v1.0 Category: Digital Auction System ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

struct auction_item {
    char name[50];
    int price;
};

void print_menu() {
    printf("\n1. Add item");
    printf("\n2. Display all items");
    printf("\n3. Place bid");
    printf("\n4. Exit");
}

void add_item(int index, struct auction_item *items) {
    printf("Enter name of item %d: ", index);
    scanf("%s", items[index].name);
    printf("Enter starting price of item %d: ", index);
    scanf("%d", &items[index].price);
}

void display_items(int index, struct auction_item *items) {
    printf("\n--------AUCTION ITEMS--------\n");
    for (int i = 0; i < index; i++) {
        printf("\nItem %d: %s - Starting Price: %d", i+1, items[i].name, items[i].price);
    }
}

int place_bid(int index, struct auction_item *items) {
    int item_index, bid_amount;
    
    printf("\nEnter index of item you want to bid for: ");
    scanf("%d", &item_index);
    
    if (item_index > index || item_index < 1) {
        printf("Invalid item index, try again.");
        return -1;
    }
    
    printf("Enter your bid amount: ");
    scanf("%d", &bid_amount);
    
    if (bid_amount < items[item_index-1].price) {
        printf("Your bid must be higher than the starting price of %d.", items[item_index-1].price);
        return -1;
    }
    
    items[item_index-1].price = bid_amount;
    printf("Your bid of %d for item %d was accepted!", bid_amount, item_index);
}

int main() {
    struct auction_item *items = malloc(sizeof(struct auction_item));
    int index = 0, choice, result; 
    do {
        print_menu();
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                index++;
                items = realloc(items, (index + 1) * sizeof(struct auction_item));
                add_item(index-1, items);
                break;
            case 2:
                display_items(index, items);
                break;
            case 3:
                result = place_bid(index, items);
                if (result == -1) {
                    printf("Bid unsuccessful, try again.");
                }
                break;
            case 4:
                printf("\nExiting auction...");
                break;
            default:
                printf("\nInvalid choice, try again.");
        }
    } while (choice != 4);
    
    free(items);
    return 0;
}
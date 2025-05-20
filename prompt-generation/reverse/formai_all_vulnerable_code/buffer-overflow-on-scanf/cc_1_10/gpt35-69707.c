//FormAI DATASET v1.0 Category: Digital Auction System ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct item {
    char name[50];
    int starting_bid;
    int current_bid;
    int time_left; //in minutes
    char bidder[50];
} Item;

typedef struct auction {
    Item item;
    struct auction* next;
} Auction;

Auction* head = NULL;

void display_items() {
    Auction* current = head;
    
    while(current != NULL) {
        printf("\nName: %s", current->item.name);
        printf("\nStarting Bid: %d", current->item.starting_bid);
        printf("\nCurrent Bid: %d", current->item.current_bid);
        printf("\nTime Left: %d minutes", current->item.time_left);
        printf("\nBidder: %s\n", current->item.bidder);
        current = current->next;
    }
}

void add_item() {
    Auction* new_item = (Auction*) malloc(sizeof(Auction));
    
    printf("Enter item name: ");
    scanf("%s", new_item->item.name);
    printf("Enter starting bid: ");
    scanf("%d", &new_item->item.starting_bid);
    new_item->item.current_bid = new_item->item.starting_bid;
    printf("Enter time left (in minutes): ");
    scanf("%d", &new_item->item.time_left);
    strcpy(new_item->item.bidder, "No bids yet");
    
    new_item->next = head;
    head = new_item;
    
    printf("\nItem has been added to the auction successfully.\n");
}

void bid_item() {
    char item_name[50];
    int bid_amount;
    
    printf("Enter item name: ");
    scanf("%s", item_name);
    
    Auction* current = head;
    
    while(current != NULL) {
        if(strcmp(current->item.name, item_name) == 0) {
            printf("Enter bid amount: ");
            scanf("%d", &bid_amount);
            if(bid_amount > current->item.current_bid) {
                current->item.current_bid = bid_amount;
                printf("\nBid has been placed successfully.\n");
                printf("New Current Bid: %d\n", current->item.current_bid);
                printf("Bidder Name: ");
                scanf("%s", current->item.bidder);
            }
            else {
                printf("\nSorry, your bid is too low.\n");
            }
            return;
        }
        current = current->next;
    }
    
    printf("No item found with that name.\n");
}

void remove_item() {
    char item_name[50];
    
    printf("Enter item name to remove: ");
    scanf("%s", item_name);
    
    Auction* current = head;
    Auction* previous = NULL;
    
    while(current != NULL) {
        if(strcmp(current->item.name, item_name) == 0) {
            if(previous == NULL) {
                head = current->next;
            }
            else {
                previous->next = current->next;
            }
            free(current);
            printf("\nItem has been removed successfully.\n");
            return;
        }
        previous = current;
        current = current->next;
    }
    
    printf("No item found with that name.\n");
}

void update_time() {
    Auction* current = head;
    
    while(current != NULL) {
        if(current->item.time_left == 0) {
            printf("\nAuction has ended for %s\n", current->item.name);
            if(strcmp(current->item.bidder, "No bids yet") == 0) {
                printf("No bids were placed on this item.\n");
            }
            else {
                printf("Winner: %s\n", current->item.bidder);
            }
            remove_item(current->item.name);
        }
        else {
            current->item.time_left--;
        }
        current = current->next;
    }
}

int main() {
    int choice;
    
    while(1) {
        printf("\nDIGITAL AUCTION SYSTEM\n");
        printf("1. Display all items\n");
        printf("2. Add new item\n");
        printf("3. Bid on item\n");
        printf("4. Remove item\n");
        printf("5. Update time left\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                display_items();
                break;
            case 2:
                add_item();
                break;
            case 3:
                bid_item();
                break;
            case 4:
                remove_item();
                break;
            case 5:
                update_time();
                break;
            case 6:
                exit(0);
            default:
                printf("\nInvalid choice.\n");
        }
    }
    return 0;
}
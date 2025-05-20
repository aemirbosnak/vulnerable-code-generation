//FormAI DATASET v1.0 Category: Digital Auction System ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEM_NAME 50
#define MAX_BIDDER_NAME 20

struct auction_item {
    char name[MAX_ITEM_NAME];
    float curr_bid;
    char curr_bidder[MAX_BIDDER_NAME];
};

void print_menu() {
    printf("\n1. Add item for auction");
    printf("\n2. View current items");
    printf("\n3. Place bid");
    printf("\n4. Exit");
    printf("\n\nEnter your choice: ");
}

int main() {
    int choice;
    int num_items = 0;
    struct auction_item items[50];
    int i;
    
    do {
        print_menu();
        scanf("%d", &choice);
        fflush(stdin);
        
        switch(choice) {
            case 1:
                printf("\nEnter item name: ");
                fgets(items[num_items].name, MAX_ITEM_NAME, stdin);
                
                items[num_items].curr_bid = 0;
                strcpy(items[num_items].curr_bidder, "None");
                
                printf("\nItem %s added for auction.\n", items[num_items].name);
                num_items++;
                break;
                
            case 2:
                printf("\nCurrent items for auction:\n");
                
                for(i=0; i<num_items; i++) {
                    printf("%s", items[i].name);
                    
                    if(items[i].curr_bidder == "None") {
                        printf(" - No bids yet.\n");
                    }
                    else {
                        printf(" - Current bid: $%.2f by %s\n", items[i].curr_bid, items[i].curr_bidder);
                    }
                }
                break;
                
            case 3:
                printf("\nEnter item number to bid on: ");
                scanf("%d", &i);
                fflush(stdin);
                
                if(i >= num_items || i < 0) {
                    printf("\nInvalid item number.\n");
                    break;
                }
                
                printf("\nCurrent bid for %s is $%.2f by %s", items[i].name, items[i].curr_bid, items[i].curr_bidder);
                printf("\nEnter your name to bid: ");
                fgets(items[i].curr_bidder, MAX_BIDDER_NAME, stdin);
                fflush(stdin);
                
                printf("\nEnter your bid amount: ");
                scanf("%f", &items[i].curr_bid);
                fflush(stdin);
                
                printf("\nBid placed successfully.\n");
                break;
                
            case 4:
                printf("\nExiting program.\n");
                break;
                
            default:
                printf("\nInvalid choice.\n");
                break;
        }
    
    }while(choice!=4);
    
    return 0;
}
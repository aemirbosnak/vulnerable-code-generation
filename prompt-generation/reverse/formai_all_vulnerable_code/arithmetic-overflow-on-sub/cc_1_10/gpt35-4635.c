//FormAI DATASET v1.0 Category: Digital Auction System ; Style: peaceful
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct item {
    char name[50];
    float price;
    char bidder[50];
} auction[10];

int total_items = 0;

// function to add items for auction
void add_item() {
    printf("\nEnter the name of the item: ");
    scanf("%s", auction[total_items].name);
    printf("Enter the starting price: $");
    scanf("%f", &auction[total_items].price);

    total_items++;
    printf("\nItem added successfully!\n");
}

// function to display all items in auction
void display_items() {
    if (total_items == 0) {
        printf("\nNo items available for auction.\n");
        return;
    }

    printf("\n--------------\n");
    printf("ITEMS AVAILABLE\n");
    printf("--------------\n");

    for (int i = 0; i < total_items; i++) {
        printf("%d. %s ($%.2f)\n", i+1, auction[i].name, auction[i].price);
    }
}

// function to bid for an item
void bid_item() {
    int choice;
    display_items();
    printf("\nEnter the number of the item to bid for: ");
    scanf("%d", &choice);
    choice--; // to adjust array index

    printf("\nEnter your name: ");
    scanf("%s", auction[choice].bidder);
    printf("Enter your bid: $");
    scanf("%f", &auction[choice].price);

    printf("\nBid placed successfully!\n");
}

int main() {
    int option;

    do {
        printf("\nWELCOME TO DIGITAL AUCTION SYSTEM:\n");
        printf("1. Add item for auction\n");
        printf("2. Display all items in auction\n");
        printf("3. Bid for an item\n");
        printf("4. Exit\n");

        printf("\nEnter your choice (1-4): ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                add_item();
                break;
            case 2:
                display_items();
                break;
            case 3:
                bid_item();
                break;
            case 4:
                printf("\nThank you for using Digital Auction System.\n");
                exit(0);
            default:
                printf("\nInvalid choice. Please try again.\n");
        }
    } while (1);

    return 0;
}
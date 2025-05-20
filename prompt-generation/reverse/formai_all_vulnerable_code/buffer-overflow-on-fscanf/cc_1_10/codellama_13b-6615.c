//Code Llama-13B DATASET v1.0 Category: Digital Auction System ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_BIDS 100

typedef struct {
    char name[50];
    int starting_price;
    int current_price;
    int bids[MAX_BIDS];
    int num_bids;
} Item;

void print_menu() {
    printf("1. View Items\n");
    printf("2. Place Bid\n");
    printf("3. Exit\n");
}

void view_items() {
    Item items[MAX_ITEMS];
    int num_items = 0;

    // Read in items from a file
    FILE *fp = fopen("items.txt", "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    while (fscanf(fp, "%s %d %d", items[num_items].name, &items[num_items].starting_price, &items[num_items].current_price) == 3) {
        num_items++;
    }

    fclose(fp);

    // Print out items
    for (int i = 0; i < num_items; i++) {
        printf("%s: %d - %d\n", items[i].name, items[i].starting_price, items[i].current_price);
    }
}

void place_bid() {
    Item items[MAX_ITEMS];
    int num_items = 0;

    // Read in items from a file
    FILE *fp = fopen("items.txt", "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    while (fscanf(fp, "%s %d %d", items[num_items].name, &items[num_items].starting_price, &items[num_items].current_price) == 3) {
        num_items++;
    }

    fclose(fp);

    // Get user input for item and bid amount
    char item_name[50];
    int bid_amount;
    printf("Enter item name: ");
    scanf("%s", item_name);
    printf("Enter bid amount: ");
    scanf("%d", &bid_amount);

    // Check if bid amount is greater than current price
    int item_index = -1;
    for (int i = 0; i < num_items; i++) {
        if (strcmp(items[i].name, item_name) == 0) {
            item_index = i;
            break;
        }
    }

    if (item_index == -1) {
        printf("Invalid item name.\n");
        return;
    }

    if (bid_amount < items[item_index].current_price) {
        printf("Bid amount must be greater than current price.\n");
        return;
    }

    // Update item with new current price
    items[item_index].current_price = bid_amount;

    // Write items back to file
    fp = fopen("items.txt", "w");
    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    for (int i = 0; i < num_items; i++) {
        fprintf(fp, "%s %d %d\n", items[i].name, items[i].starting_price, items[i].current_price);
    }

    fclose(fp);
}

int main() {
    int choice;

    while (1) {
        print_menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                view_items();
                break;
            case 2:
                place_bid();
                break;
            case 3:
                exit(0);
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }
    }

    return 0;
}
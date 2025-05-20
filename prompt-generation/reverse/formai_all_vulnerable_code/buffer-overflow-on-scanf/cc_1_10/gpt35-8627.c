//FormAI DATASET v1.0 Category: Digital Auction System ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 1000

typedef struct item {
    char name[50];
    int id;
    float price;
} Item;

Item items[MAX_ITEMS];
int num_items = 0;

void add_item() {
    char name[50];
    float price;
    printf("Enter item name: ");
    scanf("%s", name);
    printf("Enter item price: ");
    scanf("%f", &price);
    num_items++;
    Item new_item;
    strcpy(new_item.name, name);
    new_item.price = price;
    new_item.id = num_items;
    items[num_items-1] = new_item;
}

void print_items() {
    printf("Available items:\n");
    for (int i = 0; i < num_items; i++) {
        printf("%d) %s - $%.2f\n", items[i].id, items[i].name, items[i].price);
    }
}

int bid_item(int id, float bid) {
    if (id > num_items || id <= 0) {
        printf("Invalid item ID.\n");
        return 0;
    }
    if (bid <= items[id-1].price) {
        printf("Invalid bid. Must be higher than current price.\n");
        return 0;
    }
    items[id-1].price = bid;
    printf("Successful bid on %s for $%.2f!\n", items[id-1].name, bid);
    return 1;
}

int main() {
    int choice;
    float bid;
    int id;
    printf("Welcome to the Digital Auction System!\n");
    do {
        printf("\n1. Add item\n2. Print available items\n3. Bid on item\n4. Quit\nEnter choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                add_item();
                break;
            case 2:
                print_items();
                break;
            case 3:
                print_items();
                printf("Enter item ID to bid on: ");
                scanf("%d", &id);
                printf("Enter bid amount: ");
                scanf("%f", &bid);
                bid_item(id, bid);
                break;
            case 4:
                printf("Thanks for using the Digital Auction System!\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
                break;
        }
    } while (choice != 4);
    return 0;
}
//Falcon-180B DATASET v1.0 Category: Digital Auction System ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>

#define MAX_ITEMS 100
#define MAX_BIDDERS 100

typedef struct {
    char name[50];
    int id;
} bidder;

typedef struct {
    char name[50];
    int id;
    int price;
} item;

int main() {
    bidder bidders[MAX_BIDDERS];
    item items[MAX_ITEMS];
    int num_bidders, num_items, i, j;
    char choice;

    printf("Welcome to the Digital Auction System!\n");
    printf("Enter the number of bidders: ");
    scanf("%d", &num_bidders);

    for (i = 0; i < num_bidders; i++) {
        printf("Enter the name and ID of bidder %d: ", i+1);
        scanf("%s %d", bidders[i].name, &bidders[i].id);
    }

    printf("Enter the number of items: ");
    scanf("%d", &num_items);

    for (i = 0; i < num_items; i++) {
        printf("Enter the name and ID of item %d: ", i+1);
        scanf("%s %d", items[i].name, &items[i].id);
        printf("Enter the starting price for item %d: ", i+1);
        scanf("%d", &items[i].price);
    }

    do {
        system("clear");
        printf("Current bids:\n");
        for (i = 0; i < num_items; i++) {
            printf("%s (%d) - $%d\n", items[i].name, items[i].id, items[i].price);
        }
        printf("\n");

        printf("Enter your choice:\n");
        printf("1. Place a bid\n");
        printf("2. View current bids\n");
        printf("3. Exit\n");
        scanf(" %c", &choice);

        switch (choice) {
            case '1':
                printf("Enter the item ID you want to bid on: ");
                scanf("%d", &j);
                printf("Enter your bid amount: ");
                scanf("%d", &items[j-1].price);
                break;
            case '2':
                system("clear");
                break;
            case '3':
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    } while (choice!= '3');

    return 0;
}
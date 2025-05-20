//Falcon2-11B DATASET v1.0 Category: Digital Auction System ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BIDDERS 100
#define MAX_ITEMS 100

struct bidder {
    char name[50];
    int bid;
    int items;
};

struct item {
    char name[50];
    int price;
    int bidder;
};

int main() {
    struct bidder bidders[MAX_BIDDERS];
    struct item items[MAX_ITEMS];
    int n, i, j, k;

    printf("Welcome to the Digital Auction System!\n");
    printf("Enter the number of bidders: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        printf("Enter bidder name: ");
        scanf("%s", bidders[i].name);
        printf("Enter bidder bid: ");
        scanf("%d", &bidders[i].bid);
        printf("Enter bidder items: ");
        scanf("%d", &bidders[i].items);
    }

    printf("\nEnter the number of items: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        printf("Enter item name: ");
        scanf("%s", items[i].name);
        printf("Enter item price: ");
        scanf("%d", &items[i].price);
        printf("Enter item bidder: ");
        scanf("%d", &items[i].bidder);
    }

    printf("\nBidders:\n");
    for (i = 0; i < n; i++) {
        printf("%s - %d\n", bidders[i].name, bidders[i].bid);
    }

    printf("\nItems:\n");
    for (i = 0; i < n; i++) {
        printf("%s - %d\n", items[i].name, items[i].price);
    }

    printf("\nAuction begins!\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (items[j].bidder == bidders[i].bid) {
                items[j].price *= 2;
                printf("Bidder %s wins item %s with price %d\n", bidders[i].name, items[j].name, items[j].price);
                break;
            }
        }
    }

    return 0;
}
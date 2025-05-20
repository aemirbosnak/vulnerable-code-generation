//Falcon-180B DATASET v1.0 Category: Digital Auction System ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[100];
    int bid;
    int max_bid;
} Bidder;

typedef struct {
    char name[100];
    int bid;
} Item;

int main() {
    int num_items, num_bidders;
    char filename[100];
    printf("Enter the number of items: ");
    scanf("%d", &num_items);
    printf("Enter the number of bidders: ");
    scanf("%d", &num_bidders);
    printf("Enter the filename: ");
    scanf("%s", filename);

    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: File not found\n");
        exit(1);
    }

    Item items[num_items];
    Bidder bidders[num_bidders];
    int i, j;
    for (i = 0; i < num_items; i++) {
        fscanf(fp, "%s %d", items[i].name, &items[i].bid);
    }
    for (i = 0; i < num_bidders; i++) {
        fscanf(fp, "%s %d", bidders[i].name, &bidders[i].max_bid);
    }
    fclose(fp);

    int max_bid = 0;
    for (i = 0; i < num_items; i++) {
        printf("%s: $%d\n", items[i].name, items[i].bid);
        for (j = 0; j < num_bidders; j++) {
            if (items[i].bid <= bidders[j].max_bid) {
                printf("%s bids $%d\n", bidders[j].name, items[i].bid);
            }
        }
        if (items[i].bid > max_bid) {
            max_bid = items[i].bid;
        }
    }

    printf("\nHighest bid: $%d\n", max_bid);

    return 0;
}
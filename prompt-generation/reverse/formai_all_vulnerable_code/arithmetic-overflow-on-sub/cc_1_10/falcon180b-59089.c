//Falcon-180B DATASET v1.0 Category: Digital Auction System ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int id;
    char name[50];
    int bid;
    time_t timestamp;
} Bid;

void displayBids(Bid bids[], int size) {
    printf("Bids:\n");
    for (int i = 0; i < size; i++) {
        printf("%d. %s - $%d at %s\n", i + 1, bids[i].name, bids[i].bid, ctime(&bids[i].timestamp));
    }
}

void placeBid(Bid bids[], int size, int itemId, char name[], int amount) {
    for (int i = 0; i < size; i++) {
        if (bids[i].id == itemId) {
            bids[i].bid = amount;
            bids[i].timestamp = time(NULL);
            strcpy(bids[i].name, name);
            return;
        }
    }
    bids[size].id = itemId;
    bids[size].bid = amount;
    bids[size].timestamp = time(NULL);
    strcpy(bids[size].name, name);
    size++;
}

int main() {
    Bid bids[100];
    int size = 0;
    int choice;

    do {
        printf("1. Place bid\n2. Display bids\n3. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter item ID: ");
            scanf("%d", &size);
            printf("Enter your name: ");
            scanf("%s", bids[size - 1].name);
            printf("Enter your bid amount: ");
            scanf("%d", &bids[size - 1].bid);
            break;
        case 2:
            displayBids(bids, size);
            break;
        case 3:
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    } while (1);

    return 0;
}
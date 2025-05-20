//Falcon-180B DATASET v1.0 Category: Digital Auction System ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_ITEMS 10

typedef struct {
    int id;
    char name[20];
    int value;
} item;

item items[NUM_ITEMS] = {
    {1, "Laptop", 1000},
    {2, "Phone", 500},
    {3, "Tablet", 800},
    {4, "Watch", 200},
    {5, "Headphones", 150},
    {6, "Speaker", 300},
    {7, "TV", 1200},
    {8, "Camera", 700},
    {9, "Game Console", 400},
    {10, "Printer", 250}
};

int max_bid[NUM_ITEMS] = {0};
int highest_bidder[NUM_ITEMS] = {0};

void *bid(void *arg) {
    int item_id = *(int *) arg;
    int bid_amount;

    printf("Enter your bid for item %d: ", item_id);
    scanf("%d", &bid_amount);

    if (bid_amount > max_bid[item_id]) {
        max_bid[item_id] = bid_amount;
        highest_bidder[item_id] = pthread_self();
    }

    printf("Current highest bid for item %d: $%d by thread %lu\n", item_id, max_bid[item_id], highest_bidder[item_id]);
}

int main() {
    pthread_t threads[NUM_ITEMS];

    for (int i = 0; i < NUM_ITEMS; i++) {
        pthread_create(&threads[i], NULL, bid, (void *) &i);
    }

    for (int i = 0; i < NUM_ITEMS; i++) {
        pthread_join(threads[i], NULL);
    }

    for (int i = 0; i < NUM_ITEMS; i++) {
        printf("Item %d sold for $%d to thread %lu\n", i+1, max_bid[i], highest_bidder[i]);
    }

    return 0;
}
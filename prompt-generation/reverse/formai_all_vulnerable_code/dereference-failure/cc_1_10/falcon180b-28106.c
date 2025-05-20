//Falcon-180B DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_BAGS 100
#define MAX_WEIGHT 50
#define MAX_SIZE 100

struct Bag {
    int weight;
    int size;
    char *owner;
    struct Bag *next;
};

struct Bag *head = NULL;

void addBag(struct Bag *bag) {
    if (head == NULL) {
        head = bag;
        return;
    }
    struct Bag *curr = head;
    while (curr->next!= NULL) {
        curr = curr->next;
    }
    curr->next = bag;
}

void printBags() {
    struct Bag *curr = head;
    while (curr!= NULL) {
        printf("Owner: %s, Weight: %d, Size: %d\n", curr->owner, curr->weight, curr->size);
        curr = curr->next;
    }
}

int main() {
    srand(time(NULL));
    int i;
    for (i = 0; i < NUM_BAGS; i++) {
        struct Bag *bag = (struct Bag*)malloc(sizeof(struct Bag));
        bag->weight = rand() % MAX_WEIGHT + 1;
        bag->size = rand() % MAX_SIZE + 1;
        bag->owner = (char*)malloc(10 * sizeof(char));
        sprintf(bag->owner, "Passenger %d", i+1);
        bag->next = NULL;
        addBag(bag);
    }
    printBags();
    return 0;
}
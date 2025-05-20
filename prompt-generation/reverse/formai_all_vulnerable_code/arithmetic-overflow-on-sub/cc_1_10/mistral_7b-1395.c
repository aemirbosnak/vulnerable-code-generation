//MISTRAL-7B DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
    int id;
    char *destination;
} Bag;

void swap(Bag *a, Bag *b) {
    Bag temp;
    temp.id = a->id;
    a->id = b->id;
    b->id = temp.id;

    temp.destination = a->destination;
    a->destination = b->destination;
    b->destination = temp.destination;
}

void shuffle(Bag bags[], int n) {
    srand(time(NULL));
    for (int i = n - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        swap(&bags[i], &bags[j]);
    }
}

int main() {
    int n;
    printf("Enter the number of bags: ");
    scanf("%d", &n);

    Bag bags[n];

    for (int i = 0; i < n; i++) {
        printf("Enter bag %d's ID and destination: ", i + 1);
        scanf("%d%s", &bags[i].id, bags[i].destination);
    }

    printf("\nShuffling bags...\n");
    shuffle(bags, n);

    printf("\nBaggage Handling Desk 1:\n");
    for (int i = 0; i < n; i += 2) {
        if (i + 1 < n && strcmp(bags[i].destination, bags[i + 1].destination) == 0) {
            printf("Baggage conflict detected between bags %d and %d.\n", bags[i].id, bags[i + 1].id);
            i++;
            continue;
        }
        printf("Handling bag %d with ID %d and destination %s.\n", i / 2 + 1, bags[i].id, bags[i].destination);
    }

    printf("\nBaggage Handling Desk 2:\n");
    for (int i = 1; i < n; i += 2) {
        if (i > 0 && strcmp(bags[i].destination, bags[i - 1].destination) == 0) {
            printf("Baggage conflict detected between bags %d and %d.\n", bags[i].id, bags[i - 1].id);
            i--;
            continue;
        }
        printf("Handling bag %d with ID %d and destination %s.\n", (i + 1) / 2 + 1, bags[i].id, bags[i].destination);
    }

    printf("\nBaggage handling complete.\n");

    return 0;
}
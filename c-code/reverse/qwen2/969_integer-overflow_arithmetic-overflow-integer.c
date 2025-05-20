#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_BAGS 100
#define MAX_WEIGHT 50

typedef struct {
    int id;
    int weight;
    int status;
} Bag;

void initializeBags(Bag bags[], int numBags) {
    for (int i = 0; i < numBags; i++) {
        bags[i].id = i + 1;
        bags[i].weight = rand() % (MAX_WEIGHT + 1);
        bags[i].status = 0;
    }
}

void processBags(Bag bags[], int numBags) {
    for (int t = 1; t <= 60; t++) {
        printf("Second %d:\n", t);
        for (int i = 0; i < numBags; i++) {
            if (bags[i].status == 0 && bags[i].weight <= 20) {
                bags[i].status = 1;
                printf("Bag %d processed\n", bags[i].id);
            } else if (bags[i].status == 1 && bags[i].weight > 20 && bags[i].weight <= 40) {
                bags[i].status = 2;
                printf("Bag %d processed\n", bags[i].id);
            } else if (bags[i].status == 2 && bags[i].weight > 40) {
                bags[i].status = 3;
                printf("Bag %d processed\n", bags[i].id);
            }
        }
        printf("\n");
    }
}

int main() {
    srand(time(0));
    int numBags;
    printf("Enter the number of bags: ");
    scanf("%d", &numBags);

    Bag bags[MAX_BAGS];
    initializeBags(bags, numBags);

    processBags(bags, numBags);

    return 0;
}

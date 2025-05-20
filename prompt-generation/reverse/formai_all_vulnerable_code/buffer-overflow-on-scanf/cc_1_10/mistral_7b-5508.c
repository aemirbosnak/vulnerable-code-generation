//MISTRAL-7B DATASET v1.0 Category: Greedy Algorithms ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int weight;
    int candies;
    char name[50];
} Box;

int compare(const void *a, const void *b) {
    Box *boxA = (Box *) a;
    Box *boxB = (Box *) b;

    float ratioA = (float) boxA->candies / boxA->weight;
    float ratioB = (float) boxB->candies / boxB->weight;

    return ratioB > ratioA ? -1 : (ratioB < ratioA ? 1 : strcmp(boxA->name, boxB->name));
}

int main() {
    int numBoxes, desiredWeight;
    printf("Enter the number of boxes: ");
    scanf("%d", &numBoxes);

    Box *boxes = (Box *) malloc(numBoxes * sizeof(Box));

    for (int i = 0; i < numBoxes; i++) {
        printf("Enter box %d details (weight candies name): ", i + 1);
        scanf("%d %d %s", &boxes[i].weight, &boxes[i].candies, boxes[i].name);
    }

    printf("Enter the desired weight: ");
    scanf("%d", &desiredWeight);

    qsort(boxes, numBoxes, sizeof(Box), compare);

    int selectedBoxes = 0;
    int currentWeight = 0;

    for (int i = 0; i < numBoxes; i++) {
        int candiesToAdd = desiredWeight / boxes[i].weight;

        if (boxes[i].weight + currentWeight > desiredWeight) {
            break;
        }

        currentWeight += boxes[i].weight;
        selectedBoxes += candiesToAdd * (boxes[i].candies / boxes[i].weight);
    }

    printf("You can carry %d candies in one trip.", selectedBoxes);

    free(boxes);
    return 0;
}
//FormAI DATASET v1.0 Category: Memory Game ; Style: calm
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main() {
    int n;
    printf("Enter n (number of boxes): ");
    scanf("%d", &n);
    getchar();
    char *boxes = (char *) malloc(sizeof(char) * n);
    int *indexes = (int *) malloc(sizeof(int) * n);
    int *flipped = (int *) malloc(sizeof(int) * n);

    // Initialize the boxes, indexes, and flipped arrays.
    for(int i=0; i<n; i++) {
        boxes[i] = '?';
        indexes[i] = i;
        flipped[i] = 0;
    }

    // Seed the random number generator with the current time.
    srand(time(NULL));

    // Shuffle the indexes array using Fisher-Yates shuffle algorithm.
    for(int i=n-1; i>=1; i--) {
        int j = rand() % (i+1);
        int temp = indexes[i];
        indexes[i] = indexes[j];
        indexes[j] = temp;
    }

    printf("\nMEMORY GAME\n\n");
    printf("You have to find the matching pairs of boxes.\n\n");

    // Keep playing until all boxes are flipped.
    int pairs_found = 0;
    while(pairs_found < n/2) {
        printf("\n");
        for(int i=0; i<n; i++) {
            if(flipped[i]) {
                printf(" %c ", boxes[i]);
            }
            else {
                printf(" - ");
            }
        }
        printf("\n");

        int choice1, choice2;

        // Get the first choice from user.
        printf("\nEnter the first box number to flip: ");
        scanf("%d", &choice1);
        choice1--;
        getchar();

        if(flipped[choice1]) {
            printf("Box %d is already flipped.\n", choice1+1);
            continue;
        }

        boxes[choice1] = 'A' + (indexes[choice1] % (n/2));

        // Get the second choice from user.
        printf("\nEnter the second box number to flip: ");
        scanf("%d", &choice2);
        choice2--;
        getchar();

        if(flipped[choice2]) {
            printf("Box %d is already flipped.\n", choice2+1);
            continue;
        }

        boxes[choice2] = 'A' + (indexes[choice2] % (n/2));

        // Check if the choices match.
        if(boxes[choice1] == boxes[choice2]) {
            flipped[choice1] = 1;
            flipped[choice2] = 1;
            printf("\nMATCH!\n");
            pairs_found++;
        }
        else {
            printf("\nNO MATCH!\n");
            boxes[choice1] = '?';
            boxes[choice2] = '?';
        }
    }
    printf("\nCONGRATULATIONS! You found all the pairs.\n");

    // Free the memory allocated for boxes, indexes, and flipped arrays.
    free(boxes);
    free(indexes);
    free(flipped);

    return 0;
}
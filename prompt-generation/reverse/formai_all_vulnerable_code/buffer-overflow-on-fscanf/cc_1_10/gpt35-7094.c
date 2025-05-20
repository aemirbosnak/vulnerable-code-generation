//FormAI DATASET v1.0 Category: File handling ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fpointer;
    int scores[5];

    // Writing data to a file
    fpointer = fopen("scores.txt", "w");
    fprintf(fpointer, "35 27 18 44 52\n");
    fclose(fpointer);

    // Reading data from a file
    fpointer = fopen("scores.txt", "r");
    for (int i = 0; i < 5; i++) {
        fscanf(fpointer, "%d", &scores[i]);
    }
    fclose(fpointer);

    // Displaying the scores
    printf("The scores are: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", scores[i]);
    }
    printf("\n");

    // Calculating average score
    int sum = 0;
    for (int i = 0; i < 5; i++) {
        sum += scores[i];
    }
    float avg = (float) sum / 5.0;
    printf("The average score is: %.2f\n", avg);

    // Appending new score to file
    fpointer = fopen("scores.txt", "a");
    fprintf(fpointer, "77 ");
    fclose(fpointer);

    // Reading data again and updating scores array
    fpointer = fopen("scores.txt", "r");
    for (int i = 0; i < 6; i++) {
        fscanf(fpointer, "%d", &scores[i]);
    }
    fclose(fpointer);

    // Displaying updated scores
    printf("The updated scores are: ");
    for (int i = 0; i < 6; i++) {
        printf("%d ", scores[i]);
    }
    printf("\n");

    return 0;
}
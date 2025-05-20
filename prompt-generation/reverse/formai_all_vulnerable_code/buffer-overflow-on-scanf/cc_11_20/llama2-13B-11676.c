//LLAMA2-13B DATASET v1.0 Category: Game ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define PI 3.14159

int main() {
    int numOfCups, numOfLids, i, j, k;
    char cupName[20];
    float radius, height, volume;

    // Get the number of cups and lids from the user
    printf("Enter the number of cups: ");
    scanf("%d", &numOfCups);
    printf("Enter the number of lids: ");
    scanf("%d", &numOfLids);

    // Create an array to store the cup names
    char* cupNames[numOfCups];
    for (i = 0; i < numOfCups; i++) {
        printf("Enter the name of cup %d: ", i + 1);
        scanf("%19s", cupName);
        cupNames[i] = cupName;
    }

    // Create an array to store the lid names
    char* lidNames[numOfLids];
    for (i = 0; i < numOfLids; i++) {
        printf("Enter the name of lid %d: ", i + 1);
        scanf("%19s", lidNames[i]);
    }

    // Create a 2D array to store the cup and lid pairs
    int** pairs = (int**) malloc(numOfCups * sizeof(int*));
    for (i = 0; i < numOfCups; i++) {
        pairs[i] = (int*) malloc(numOfLids * sizeof(int));
        for (j = 0; j < numOfLids; j++) {
            pairs[i][j] = 0;
        }
    }

    // Loop through the cups and lids to find the perfect pair
    for (i = 0; i < numOfCups; i++) {
        for (j = 0; j < numOfLids; j++) {
            // Calculate the distance between the cup and lid
            radius = (float) rand() / RAND_MAX * 2 - 1;
            height = (float) rand() / RAND_MAX * 10 - 5;
            volume = (float) pow(radius * radius * PI, 2);

            // Check if the cup and lid are a perfect pair
            if (abs(volume - height) < 0.1) {
                pairs[i][j] = 1;
                break;
            }
        }
    }

    // Print the perfect pairs
    for (i = 0; i < numOfCups; i++) {
        for (j = 0; j < numOfLids; j++) {
            if (pairs[i][j] == 1) {
                printf("%s %s\n", cupNames[i], lidNames[j]);
            }
        }
    }

    // Free the memory
    for (i = 0; i < numOfCups; i++) {
        free(pairs[i]);
    }
    free(pairs);

    return 0;
}
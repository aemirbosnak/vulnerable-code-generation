//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_BUCKET_SIZE 1000

int main()
{
    int i, j, x, bucket[MAX_BUCKET_SIZE], count;

    srand(time(NULL));

    printf("Enter the number of elements: ");
    scanf("%d", &count);

    if (count > MAX_BUCKET_SIZE) {
        printf("Error: Maximum bucket size exceeded!\n");
        exit(EXIT_FAILURE);
    }

    /* Initialize the bucket */
    for (i = 0; i < MAX_BUCKET_SIZE; i++) {
        bucket[i] = 0;
    }

    /* Generate random numbers and place them in the bucket */
    for (i = 0; i < count; i++) {
        x = rand() % MAX_BUCKET_SIZE;
        bucket[x]++;
    }

    /* Print the unsorted bucket */
    printf("Unsorted bucket:\n");
    for (i = 0; i < MAX_BUCKET_SIZE; i++) {
        if (bucket[i] > 0) {
            for (j = 0; j < bucket[i]; j++) {
                printf("%d ", i);
            }
        }
    }
    printf("\n");

    /* Sort the bucket using bucket sort algorithm */
    for (i = 0; i < MAX_BUCKET_SIZE; i++) {
        for (j = 0; j < bucket[i]; j++) {
            printf("%d ", i);
        }
    }
    printf("\n");

    return 0;
}
//Falcon-180B DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define MAX_THREADS 4
#define MAX_DISTANCE 1000

// Function to calculate the Levenshtein distance between two strings
void *lev_distance(void *arg) {
    char *str1 = (char *) arg;
    char *str2 = (char *) malloc(strlen(str1) + 1);
    strcpy(str2, str1);

    int distance[MAX_DISTANCE];
    int i = 0, j = 0;

    while (i < strlen(str1) && j < strlen(str2)) {
        if (str1[i] == str2[j]) {
            i++;
            j++;
        } else {
            distance[j] = j;
            j++;
        }
    }

    while (i < strlen(str1)) {
        distance[j] = j;
        j++;
    }

    while (j < strlen(str2)) {
        distance[j] = j;
        j++;
    }

    printf("Levenshtein distance between '%s' and '%s': %d\n", str1, str2, distance[strlen(str2) - 1]);

    free(str2);
    pthread_exit(0);
}

int main() {
    pthread_t threads[MAX_THREADS];
    char input[MAX_THREADS][100];
    int i, j;

    printf("Enter strings to calculate Levenshtein distance (up to %d pairs):\n", MAX_THREADS);

    for (i = 0; i < MAX_THREADS; i++) {
        scanf("%s", input[i]);
    }

    for (i = 0; i < MAX_THREADS; i++) {
        pthread_create(&threads[i], NULL, lev_distance, input[i]);
    }

    for (i = 0; i < MAX_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}
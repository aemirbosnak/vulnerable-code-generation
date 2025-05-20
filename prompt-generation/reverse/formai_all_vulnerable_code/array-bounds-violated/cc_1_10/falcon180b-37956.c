//Falcon-180B DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define MAX_THREADS 4

int matrix[MAX_THREADS][MAX_THREADS];
int distances[MAX_THREADS];

void *levenshtein_distance_thread(void *arg) {
    int i, j, k;
    char *str1 = (char *) arg;
    char *str2 = (char *) arg + strlen(str1) + 1;

    for (i = 0; i < strlen(str1); i++) {
        matrix[i][0] = i;
    }

    for (j = 0; j < strlen(str2); j++) {
        matrix[0][j] = j;
    }

    for (i = 1; i < strlen(str1); i++) {
        for (j = 1; j < strlen(str2); j++) {
            if (str1[i - 1] == str2[j - 1]) {
                matrix[i][j] = matrix[i - 1][j - 1];
            } else {
                matrix[i][j] = matrix[i - 1][j] + 1;
                matrix[i][j] = matrix[i][j - 1] + 1;
                matrix[i][j] = matrix[i - 1][j - 1] + 1;
            }
        }
    }

    distances[0] = matrix[strlen(str1) - 1][strlen(str2) - 1];

    pthread_exit(0);
}

int main() {
    pthread_t threads[MAX_THREADS];
    char *str1 = "kitten";
    char *str2 = "sitting";
    int i, rc;

    for (i = 0; i < MAX_THREADS; i++) {
        rc = pthread_create(&threads[i], NULL, levenshtein_distance_thread, (void *) &str1);
        if (rc) {
            printf("Error: unable to create thread, %d\n", rc);
            exit(-1);
        }
    }

    for (i = 0; i < MAX_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("Levenshtein Distance: %d\n", distances[0]);

    return 0;
}
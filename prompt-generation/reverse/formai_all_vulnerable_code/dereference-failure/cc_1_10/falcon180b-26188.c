//Falcon-180B DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define MAX_THREADS 10

// Function to calculate Levenshtein distance between two strings
void *lev_distance(void *arg) {
    char *s1 = (char *) arg;
    int len1 = strlen(s1);
    char *s2 = (char *) malloc(len1 + 1);
    strcpy(s2, s1);

    int i, j, cost;
    int **matrix = (int **) malloc(sizeof(int *) * (len1 + 1));
    for (i = 0; i <= len1; i++) {
        matrix[i] = (int *) malloc(sizeof(int) * (len1 + 1));
        for (j = 0; j <= len1; j++) {
            if (i == 0)
                matrix[i][j] = j;
            else if (j == 0)
                matrix[i][j] = i;
            else if (s1[i - 1] == s2[j - 1])
                matrix[i][j] = matrix[i - 1][j - 1];
            else
                matrix[i][j] = matrix[i - 1][j] + 1;
        }
    }

    free(s2);
    free(matrix);
    return (void *) matrix[len1][len1];
}

int main() {
    pthread_t threads[MAX_THREADS];
    int i, j, n_threads, rc;
    char **strings = (char **) malloc(sizeof(char *) * 2);
    strings[0] = "kitten";
    strings[1] = "sitting";

    n_threads = 2;

    for (i = 0; i < n_threads; i++) {
        rc = pthread_create(&threads[i], NULL, lev_distance, strings[i]);
        if (rc) {
            printf("Error: unable to create thread, %d\n", rc);
            exit(1);
        }
    }

    for (i = 0; i < n_threads; i++) {
        rc = pthread_join(threads[i], NULL);
        if (rc) {
            printf("Error: unable to join thread, %d\n", rc);
            exit(1);
        }
    }

    for (i = 0; i < n_threads; i++) {
        printf("Levenshtein distance between %s and %s is %d\n", strings[0], strings[1], *(int *) strings[i]);
    }

    return 0;
}
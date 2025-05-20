//Falcon-180B DATASET v1.0 Category: Performance-Critical Component ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

#define N 1000000
#define MAX_STRING_LENGTH 100

int main() {
    char **strings;
    int i, j;
    clock_t start, end;
    double cpu_time_used;

    strings = (char **) malloc(N * sizeof(char *));
    if (strings == NULL) {
        printf("Memory error\n");
        return 1;
    }

    for (i = 0; i < N; i++) {
        strings[i] = (char *) malloc(MAX_STRING_LENGTH * sizeof(char));
        if (strings[i] == NULL) {
            printf("Memory error\n");
            return 1;
        }
        sprintf(strings[i], "String %d", i);
    }

    start = clock();
    for (i = 0; i < N; i++) {
        for (j = 0; j < strlen(strings[i]); j++) {
            if (strings[i][j] == 'a') {
                strings[i][j] = 'b';
            }
        }
    }
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("Time taken: %f seconds\n", cpu_time_used);

    for (i = 0; i < N; i++) {
        free(strings[i]);
    }
    free(strings);

    return 0;
}
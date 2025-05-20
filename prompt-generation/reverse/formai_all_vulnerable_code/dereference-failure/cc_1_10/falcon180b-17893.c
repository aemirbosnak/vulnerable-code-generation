//Falcon-180B DATASET v1.0 Category: Benchmarking ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_LEN 10000
#define MAX_NUM_STRINGS 1000

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <num_strings>\n", argv[0]);
        return 1;
    }

    int num_strings = atoi(argv[1]);
    if (num_strings <= 0 || num_strings > MAX_NUM_STRINGS) {
        fprintf(stderr, "Invalid number of strings\n");
        return 1;
    }

    char **strings = malloc(num_strings * sizeof(char *));
    if (strings == NULL) {
        fprintf(stderr, "Memory error\n");
        return 1;
    }

    for (int i = 0; i < num_strings; i++) {
        strings[i] = malloc(MAX_LEN * sizeof(char));
        if (strings[i] == NULL) {
            fprintf(stderr, "Memory error\n");
            return 1;
        }
        sprintf(strings[i], "String %d", i);
    }

    double start_time = clock();
    for (int j = 0; j < 1000000; j++) {
        for (int i = 0; i < num_strings; i++) {
            strcpy(strings[i], strings[(i + j) % num_strings]);
        }
    }
    double end_time = clock();

    printf("Time taken: %.6f seconds\n", (end_time - start_time) / CLOCKS_PER_SEC);

    for (int i = 0; i < num_strings; i++) {
        free(strings[i]);
    }
    free(strings);

    return 0;
}
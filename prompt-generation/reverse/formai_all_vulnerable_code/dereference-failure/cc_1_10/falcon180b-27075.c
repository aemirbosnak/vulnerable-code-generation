//Falcon-180B DATASET v1.0 Category: Benchmarking ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define NUM_ELEMENTS 1000000
#define MAX_STRING_LENGTH 100

char* generate_random_string(int length) {
    char* string = malloc(length + 1);
    if (string == NULL) {
        printf("Memory error\n");
        exit(1);
    }
    for (int i = 0; i < length; i++) {
        string[i] = rand() % 26 + 'a';
    }
    string[length] = '\0';
    return string;
}

int main(int argc, char** argv) {
    srand(time(NULL));

    char** strings = malloc(NUM_ELEMENTS * sizeof(char*));
    if (strings == NULL) {
        printf("Memory error\n");
        exit(1);
    }

    for (int i = 0; i < NUM_ELEMENTS; i++) {
        strings[i] = generate_random_string(rand() % MAX_STRING_LENGTH + 1);
    }

    int search_length = rand() % MAX_STRING_LENGTH + 1;
    char* search_string = generate_random_string(search_length);

    clock_t start_time = clock();
    int count = 0;
    for (int i = 0; i < NUM_ELEMENTS; i++) {
        if (strlen(strings[i]) == search_length && strcmp(strings[i], search_string) == 0) {
            count++;
        }
    }
    clock_t end_time = clock();

    double elapsed_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;
    printf("Found %d strings with length %d in %f seconds\n", count, search_length, elapsed_time);

    for (int i = 0; i < NUM_ELEMENTS; i++) {
        free(strings[i]);
    }
    free(strings);

    return 0;
}
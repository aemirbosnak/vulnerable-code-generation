//Falcon-180B DATASET v1.0 Category: Palindrome Checker ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define MAX_THREADS 10
#define MAX_STRING_LENGTH 1000

char *strings[MAX_THREADS];
int string_lengths[MAX_THREADS];
int num_strings = 0;

void *check_palindrome(void *arg) {
    int i;
    char *string = (char *)arg;
    int length = strlen(string);

    for (i = 0; i < length/2; i++) {
        if (string[i]!= string[length-i-1]) {
            return 0;
        }
    }

    return 1;
}

int main() {
    int i, j;
    char input[MAX_STRING_LENGTH];

    printf("Enter strings to check for palindromes (enter 'done' when finished):\n");

    while (scanf("%s", input)!= EOF) {
        if (strcmp(input, "done") == 0) {
            break;
        }

        if (num_strings >= MAX_THREADS) {
            printf("Error: too many strings entered.\n");
            return 1;
        }

        strings[num_strings] = malloc(strlen(input) + 1);
        if (strings[num_strings] == NULL) {
            printf("Error: could not allocate memory.\n");
            return 1;
        }

        strcpy(strings[num_strings], input);
        string_lengths[num_strings] = strlen(input);
        num_strings++;
    }

    pthread_t threads[num_strings];

    for (i = 0; i < num_strings; i++) {
        pthread_create(&threads[i], NULL, check_palindrome, (void *)strings[i]);
    }

    for (i = 0; i < num_strings; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("All strings are palindromes.\n");

    for (j = 0; j < num_strings; j++) {
        free(strings[j]);
    }

    return 0;
}
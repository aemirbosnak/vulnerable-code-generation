//Falcon-180B DATASET v1.0 Category: Palindrome Checker ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include <ctype.h>

#define MAX_THREADS 10
#define MAX_STRING_LENGTH 1000

typedef struct {
    char *string;
    int length;
} string_t;

void *palindrome_checker(void *param);

int main(int argc, char *argv[]) {
    int num_threads;
    pthread_t threads[MAX_THREADS];
    string_t strings[MAX_THREADS];
    char input_string[MAX_STRING_LENGTH];
    int i, j, k;

    printf("Enter the number of strings to check: ");
    scanf("%d", &num_threads);

    for (i = 0; i < num_threads; i++) {
        printf("Enter string %d: ", i + 1);
        scanf("%s", input_string);
        strings[i].string = strdup(input_string);
        strings[i].length = strlen(input_string);
    }

    for (i = 0; i < num_threads; i++) {
        pthread_create(&threads[i], NULL, palindrome_checker, (void *)&strings[i]);
    }

    for (i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}

void *palindrome_checker(void *param) {
    string_t *string = (string_t *)param;
    int i, j;

    for (i = 0, j = string->length - 1; i < j; i++, j--) {
        if (tolower(string->string[i])!= tolower(string->string[j])) {
            printf("%s is not a palindrome\n", string->string);
            pthread_exit(0);
        }
    }

    printf("%s is a palindrome\n", string->string);
    pthread_exit(0);
}
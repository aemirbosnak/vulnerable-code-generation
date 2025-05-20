//MISTRAL-7B DATASET v1.0 Category: Typing Speed Test ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MIN_LENGTH 25
#define MAX_LENGTH 101
#define MAX_TRIES 3

typedef struct {
    char str[MAX_LENGTH];
    int len;
} Word;

void generate_random_string(Word *word) {
    int length = rand() % (MAX_LENGTH - MIN_LENGTH + 1) + MIN_LENGTH;
    word->len = length;

    for (int i = 0; i < length; i++) {
        word->str[i] = 'a' + rand() % 26;
    }

    word->str[length] = '\0';
}

int main(void) {
    srand(time(NULL));

    Word word;
    generate_random_string(&word);

    printf("Typing speed test:\n");
    printf("Type the following word as fast as you can:\n");
    printf("%s\n", word.str);

    int tries = 0;
    char input[MAX_LENGTH];
    clock_t start, end;

    while (tries < MAX_TRIES) {
        scanf("%s", input);

        if (strlen(input) == word.len) {
            start = clock();
            fflush(stdin);
            printf("%s\n", input);
            end = clock();

            double time_taken = (double)(end - start) / CLOCKS_PER_SEC;
            printf("Time taken: %.6f seconds\n", time_taken);
            break;
        } else {
            printf("Incorrect length. Try again.\n");
            tries++;
        }
    }

    if (tries == MAX_TRIES) {
        printf("Sorry, you did not pass the test.\n");
    }

    return EXIT_SUCCESS;
}
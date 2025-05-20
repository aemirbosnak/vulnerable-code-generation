//Falcon-180B DATASET v1.0 Category: Typing Speed Test ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_WORDS 10

char *words[] = {
    "the",
    "quick",
    "brown",
    "fox",
    "jumps",
    "over",
    "the",
    "lazy",
    "dog",
    "."
};

int main()
{
    int i, j, correct = 0, incorrect = 0, total = 0;
    char input[100];
    int word_index = 0;
    int start_time, end_time;

    srand(time(NULL));
    word_index = rand() % NUM_WORDS;

    printf("Welcome to the Typing Speed Test!\n");
    printf("You will be typing the following sentence:\n");
    printf("%s\n", words[word_index]);

    start_time = clock();
    while ((scanf("%s", input))!= EOF) {
        total++;
        if (strcmp(input, words[word_index]) == 0) {
            correct++;
        } else {
            incorrect++;
        }
        word_index = (word_index + 1) % NUM_WORDS;
    }
    end_time = clock();

    printf("\nTest complete!\n");
    printf("You typed %d words correctly and %d words incorrectly.\n", correct, incorrect);
    printf("Total words typed: %d\n", total);

    double elapsed_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;
    printf("Elapsed time: %.2f seconds\n", elapsed_time);

    return 0;
}
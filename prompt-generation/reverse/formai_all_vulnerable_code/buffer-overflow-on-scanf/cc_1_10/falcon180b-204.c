//Falcon-180B DATASET v1.0 Category: Typing Speed Test ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_WORDS 100
#define MAX_WORD_LENGTH 20

typedef struct {
    char word[MAX_WORD_LENGTH];
    int length;
} word_t;

word_t words[MAX_WORDS];
int num_words;

void load_words(const char *filename) {
    FILE *file;
    char line[MAX_WORD_LENGTH];
    int i;

    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: could not open file %s\n", filename);
        exit(1);
    }

    i = 0;
    while (fgets(line, MAX_WORD_LENGTH, file)!= NULL) {
        words[i].length = strlen(line);
        strcpy(words[i].word, line);
        i++;
    }

    num_words = i;

    fclose(file);
}

int main() {
    char input[MAX_WORD_LENGTH];
    int i, j, correct = 0, incorrect = 0, total = 0;
    double accuracy;
    clock_t start_time, end_time;

    printf("Welcome to the Typing Speed Test!\n");
    printf("Please enter the name of the word file:\n");
    scanf("%s", input);

    load_words(input);

    printf("Press enter to start the test:\n");
    getchar();

    start_time = clock();

    for (i = 0; i < num_words; i++) {
        printf("Word %d: ", i + 1);
        for (j = 0; j < words[i].length; j++) {
            printf("_");
        }
        printf("\n");

        fflush(stdout);
        if (fgets(input, MAX_WORD_LENGTH, stdin) == NULL) {
            printf("Error: could not read input\n");
            exit(1);
        }

        if (strcmp(input, words[i].word) == 0) {
            correct++;
        } else {
            incorrect++;
        }

        total++;
    }

    end_time = clock();

    accuracy = (double)correct / total * 100.0;

    printf("\nTest complete!\n");
    printf("You typed %d words correctly out of %d (%.2f%%).\n", correct, total, accuracy);
    printf("Your typing speed was %.2f words per minute.\n", (double)total / ((double)(end_time - start_time) / CLOCKS_PER_SEC) * 60.0);

    return 0;
}
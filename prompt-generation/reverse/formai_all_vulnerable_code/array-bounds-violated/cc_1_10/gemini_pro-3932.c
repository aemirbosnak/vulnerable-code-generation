//GEMINI-pro DATASET v1.0 Category: Typing Speed Test ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_WORDS 100
#define MAX_LENGTH 20

typedef struct {
    char word[MAX_LENGTH];
    int length;
} Word;

Word words[MAX_WORDS];
int num_words;

void load_words() {
    FILE *fp = fopen("words.txt", "r");
    if (fp == NULL) {
        perror("Error opening words.txt");
        exit(EXIT_FAILURE);
    }

    char line[MAX_LENGTH];
    while (fgets(line, MAX_LENGTH, fp) != NULL) {
        line[strlen(line) - 1] = '\0'; // Remove newline
        strcpy(words[num_words].word, line);
        words[num_words].length = strlen(line);
        num_words++;
    }

    fclose(fp);
}

void print_instructions() {
    printf("Instructions:\n");
    printf("Type the words that appear on the screen as quickly and accurately as possible.\n");
    printf("Press Enter to start the test.\n");
}

void start_test() {
    int i, correct = 0, incorrect = 0;
    char input[MAX_LENGTH];
    clock_t start, end;

    start = clock();

    for (i = 0; i < num_words; i++) {
        printf("%s ", words[i].word);
    }

    printf("\n");

    while (scanf("%s", input) != EOF) {
        if (strcmp(input, words[i].word) == 0) {
            correct++;
        } else {
            incorrect++;
        }

        i++;

        if (i == num_words) {
            break;
        }
    }

    end = clock();
    double time_taken = (double)(end - start) / CLOCKS_PER_SEC;

    printf("Correct: %d\n", correct);
    printf("Incorrect: %d\n", incorrect);
    printf("Time taken: %.2fs\n", time_taken);
}

int main() {
    load_words();
    print_instructions();
    start_test();

    return 0;
}
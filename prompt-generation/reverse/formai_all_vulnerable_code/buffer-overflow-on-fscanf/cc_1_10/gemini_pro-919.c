//GEMINI-pro DATASET v1.0 Category: Typing Speed Test ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define WORDS_PER_TEST 100
#define MAX_WORD_LENGTH 20

typedef struct {
    char word[MAX_WORD_LENGTH + 1];
    int length;
} Word;

Word words[WORDS_PER_TEST];

void generate_words() {
    FILE *f = fopen("words.txt", "r");
    if (f == NULL) {
        printf("Error: could not open file words.txt\n");
        exit(1);
    }

    for (int i = 0; i < WORDS_PER_TEST; i++) {
        fscanf(f, "%s", words[i].word);
        words[i].length = strlen(words[i].word);
    }

    fclose(f);
}

void print_words() {
    for (int i = 0; i < WORDS_PER_TEST; i++) {
        printf("%s ", words[i].word);
    }

    printf("\n");
}

int main() {
    generate_words();

    time_t start_time = time(NULL);

    print_words();

    char input[MAX_WORD_LENGTH + 1];
    int correct_count = 0;

    for (int i = 0; i < WORDS_PER_TEST; i++) {
        scanf("%s", input);

        if (strcmp(input, words[i].word) == 0) {
            correct_count++;
        }
    }

    time_t end_time = time(NULL);

    double elapsed_time = difftime(end_time, start_time);
    double wpm = (correct_count / 5) / (elapsed_time / 60);

    printf("Your typing speed is %.2f WPM\n", wpm);

    return 0;
}
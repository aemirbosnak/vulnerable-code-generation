//Falcon-180B DATASET v1.0 Category: Typing Speed Test ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_WORDS 10
#define MAX_WORD_LENGTH 20
#define MIN_WPM 20
#define MAX_WPM 120

typedef struct {
    char word[MAX_WORD_LENGTH];
    int length;
} Word;

void generate_words(Word words[], int num_words) {
    const char *words_list[] = {"apple", "banana", "cherry", "date", "elderberry", "fig", "grape", "honeydew", "kiwi", "lemon"};
    for (int i = 0; i < num_words; i++) {
        int rand_index = rand() % sizeof(words_list) / sizeof(words_list[0]);
        strcpy(words[i].word, words_list[rand_index]);
        words[i].length = strlen(words[i].word);
    }
}

int main() {
    int num_words = rand() % (MAX_WORDS - 2) + 2;
    Word words[MAX_WORDS];
    generate_words(words, num_words);

    int total_chars = 0;
    for (int i = 0; i < num_words; i++) {
        total_chars += words[i].length;
    }

    int num_correct = 0;
    int num_incorrect = 0;

    clock_t start_time = clock();
    for (int i = 0; i < num_words; i++) {
        printf("Type the word: ");
        char input[MAX_WORD_LENGTH];
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = '\0';

        if (strcmp(input, words[i].word) == 0) {
            num_correct++;
        } else {
            num_incorrect++;
        }
    }

    clock_t end_time = clock();

    double elapsed_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;
    int wpm = (int)round(total_chars / (elapsed_time * 60));

    if (wpm < MIN_WPM) {
        printf("You need to practice more. Your typing speed is only %d WPM.\n", wpm);
    } else if (wpm > MAX_WPM) {
        printf("You are a typing robot! Your typing speed is %d WPM.\n", wpm);
    } else {
        printf("Your typing speed is %d WPM.\n", wpm);
    }

    return 0;
}
//Falcon-180B DATASET v1.0 Category: Typing Speed Test ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 100
#define MIN_WORD_LENGTH 3
#define MAX_WORD_LENGTH 10
#define MAX_WPM 200

typedef struct {
    char word[MAX_WORD_LENGTH + 1];
    int length;
} Word;

void init_words(Word words[]) {
    FILE *fp = fopen("words.txt", "r");
    if (fp == NULL) {
        printf("Error opening words file.\n");
        exit(1);
    }

    int count = 0;
    while (fscanf(fp, "%s", words[count].word)!= EOF) {
        words[count].length = strlen(words[count].word);
        count++;
    }

    fclose(fp);
}

void shuffle_words(Word words[]) {
    for (int i = 0; i < MAX_WORDS; i++) {
        int j = rand() % MAX_WORDS;
        Word temp = words[i];
        words[i] = words[j];
        words[j] = temp;
    }
}

int main() {
    Word words[MAX_WORDS];
    init_words(words);
    shuffle_words(words);

    int num_words = rand() % MAX_WORDS + MIN_WORD_LENGTH;

    printf("Welcome to the Cheerful Typing Speed Test!\n");
    printf("You will be typing %d words.\n", num_words);
    printf("Press enter to begin...\n");

    fflush(stdin);
    getchar();

    clock_t start_time = clock();

    for (int i = 0; i < num_words; i++) {
        printf("%s ", words[i].word);
    }

    clock_t end_time = clock();
    double elapsed_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;

    int correct_words = 0;
    printf("\nEnter the words you typed:\n");
    char input[MAX_WORD_LENGTH + 1];
    while (fgets(input, MAX_WORD_LENGTH + 1, stdin)!= NULL) {
        input[strcspn(input, "\n")] = '\0';
        if (strcmp(input, words[correct_words].word) == 0) {
            correct_words++;
        }
    }

    double wpm = (double)correct_words / (elapsed_time / 60);

    printf("\nYou typed %d words correctly!\n", correct_words);
    printf("Your typing speed is %.2f words per minute.\n", wpm);

    return 0;
}
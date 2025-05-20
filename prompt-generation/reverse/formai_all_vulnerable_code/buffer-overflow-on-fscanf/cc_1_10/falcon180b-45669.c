//Falcon-180B DATASET v1.0 Category: Typing Speed Test ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 20
#define MAX_TIME 60

char words[MAX_WORDS][MAX_WORD_LENGTH];
int word_count = 0;

void load_words() {
    FILE *file;
    char word[MAX_WORD_LENGTH];

    file = fopen("words.txt", "r");
    if (file == NULL) {
        printf("Error loading words.\n");
        exit(1);
    }

    while (fscanf(file, "%s", word)!= EOF) {
        if (word_count >= MAX_WORDS) {
            printf("Maximum word limit reached.\n");
            exit(1);
        }

        strcpy(words[word_count], word);
        word_count++;
    }

    fclose(file);
}

int main() {
    srand(time(NULL));
    load_words();

    int score = 0;
    int correct_words = 0;
    int incorrect_words = 0;
    int total_words = word_count;
    int time_left = MAX_TIME;

    printf("Welcome to the Typing Speed Test!\n");
    printf("You will have %d seconds to type as many words as possible.\n", MAX_TIME);
    printf("Press ENTER to start...\n");

    getchar();

    while (time_left > 0 && word_count > 0) {
        int word_index = rand() % word_count;
        char word[MAX_WORD_LENGTH];
        strcpy(word, words[word_index]);

        printf("%s\n", word);

        char input[MAX_WORD_LENGTH];
        fgets(input, MAX_WORD_LENGTH, stdin);

        input[strcspn(input, "\n")] = '\0';

        if (strcmp(input, word) == 0) {
            correct_words++;
            score += strlen(word);
        } else {
            incorrect_words++;
        }

        time_left--;
        word_count--;
    }

    printf("\nTime's up!\n");

    if (word_count == 0) {
        printf("You typed %d words correctly and %d words incorrectly.\n", correct_words, incorrect_words);
    } else {
        printf("You typed %d words correctly and %d words incorrectly.\n", correct_words, incorrect_words);
    }

    printf("Your final score is %d points.\n", score);

    return 0;
}
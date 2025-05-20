//Falcon-180B DATASET v1.0 Category: Typing Speed Test ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WORDS 100
#define MAX_WORD_LENGTH 20

typedef struct {
    char word[MAX_WORD_LENGTH];
    int length;
} Word;

void generate_word(Word *word) {
    int i;
    char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    word->length = rand() % MAX_WORD_LENGTH + 1;
    for (i = 0; i < word->length; i++) {
        word->word[i] = charset[rand() % (sizeof(charset) - 1)];
    }
    word->word[i] = '\0';
}

int main() {
    int i, j, correct_words = 0, wrong_words = 0, total_words = 0;
    Word word;
    char user_input[MAX_WORD_LENGTH];
    time_t start_time, end_time;
    double elapsed_time;
    FILE *fp;

    fp = fopen("words.txt", "r");
    if (fp == NULL) {
        printf("Error: Unable to open words.txt\n");
        exit(1);
    }

    srand(time(NULL));
    for (i = 0; i < MAX_WORDS; i++) {
        fscanf(fp, "%s", word.word);
        word.length = strlen(word.word);
        total_words++;
    }

    fclose(fp);

    printf("Welcome to the C Typing Speed Test!\n");
    printf("You will be tested on your ability to type %d words.\n\n", total_words);

    start_time = time(NULL);

    for (i = 0; i < total_words; i++) {
        generate_word(&word);
        printf("Word %d: %s\n", i+1, word.word);
        fflush(stdout);
        fgets(user_input, MAX_WORD_LENGTH, stdin);
        user_input[strcspn(user_input, "\n")] = '\0';

        if (strcmp(user_input, word.word) == 0) {
            correct_words++;
        } else {
            wrong_words++;
        }
    }

    end_time = time(NULL);
    elapsed_time = difftime(end_time, start_time);

    printf("\nTest complete!\n");
    printf("You typed %d words correctly and %d words incorrectly.\n", correct_words, wrong_words);
    printf("Your typing speed is %.2f words per minute.\n", (double)total_words / (elapsed_time / 60));

    return 0;
}
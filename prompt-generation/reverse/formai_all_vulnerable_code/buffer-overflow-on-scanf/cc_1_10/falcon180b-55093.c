//Falcon-180B DATASET v1.0 Category: Typing Speed Test ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_WORD_LENGTH 20
#define NUM_WORDS 10

typedef struct {
    char word[MAX_WORD_LENGTH];
    int length;
} Word;

void generate_word(Word *word) {
    char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    int i;
    for (i = 0; i < MAX_WORD_LENGTH; i++) {
        word->word[i] = charset[rand() % strlen(charset)];
    }
    word->length = i;
}

int main() {
    srand(time(NULL));
    int num_correct = 0;
    int num_incorrect = 0;
    int total_words = 0;
    Word word;
    char input[MAX_WORD_LENGTH];
    int input_length;
    int i;

    printf("Welcome to the C Typing Speed Test!\n");
    printf("You will be given a series of words to type.\n");
    printf("Type each word as accurately and quickly as possible.\n");
    printf("Press ENTER to begin.\n");
    scanf("%c", &input[0]);

    while (input[0]!= '\n') {
        input_length = strlen(input);
        if (input_length == 1 && input[0] == '\n') {
            break;
        }
        printf("Please enter a valid input.\n");
        scanf("%c", &input[0]);
    }

    for (i = 0; i < NUM_WORDS; i++) {
        generate_word(&word);
        printf("Word %d: %s\n", i + 1, word.word);
        while (1) {
            input_length = 0;
            while (input_length < word.length && input[input_length]!= '\n') {
                input_length++;
                input[input_length] = getchar();
            }
            if (input_length == word.length) {
                if (strcmp(input, word.word) == 0) {
                    num_correct++;
                } else {
                    num_incorrect++;
                }
                total_words++;
                break;
            }
            printf("Please enter a valid input.\n");
        }
    }

    printf("Results:\n");
    printf("Correct: %d\n", num_correct);
    printf("Incorrect: %d\n", num_incorrect);
    printf("Total words: %d\n", total_words);
    printf("Accuracy: %.2f%%\n", (float)num_correct / total_words * 100);

    return 0;
}
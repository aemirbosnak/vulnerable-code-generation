//Falcon-180B DATASET v1.0 Category: Typing Speed Test ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_WORDS 20
#define WORD_LENGTH 8

int main() {
    char *words[NUM_WORDS] = {"apple", "banana", "cherry", "date", "elderberry", "fig", "grape", "honeydew", "kiwi", "lemon", "mango", "nectarine", "orange", "peach", "plum", "quince", "raspberry", "strawberry", "tangerine", "watermelon"};
    int word_index = 0;
    int num_correct_words = 0;
    int num_incorrect_words = 0;
    int num_words_typed = 0;
    int num_correct_letters = 0;
    int num_incorrect_letters = 0;
    int letters_per_word = WORD_LENGTH;
    int total_letters = 0;
    int total_words = 0;
    double accuracy = 0.0;
    double speed = 0.0;
    double time_elapsed = 0.0;
    char user_input[WORD_LENGTH + 1];
    char correct_word[WORD_LENGTH + 1];
    char incorrect_word[WORD_LENGTH + 1];
    int i, j;

    printf("Welcome to the Typing Speed Test!\n");
    printf("Please type the following words as accurately and quickly as possible:\n");

    srand(time(NULL));
    for (i = 0; i < NUM_WORDS; i++) {
        word_index = rand() % NUM_WORDS;
        strcpy(correct_word, words[word_index]);
        for (j = 0; j < WORD_LENGTH; j++) {
            correct_word[j] = toupper(correct_word[j]);
        }
        printf("%s\n", correct_word);
        total_letters += WORD_LENGTH;
        total_words++;
    }

    printf("\n");
    printf("Press enter to begin...\n");
    getchar();

    time_t start_time = time(NULL);

    while (1) {
        fgets(user_input, WORD_LENGTH + 1, stdin);
        user_input[strcspn(user_input, "\n")] = '\0';
        if (strlen(user_input) == WORD_LENGTH) {
            strcpy(incorrect_word, user_input);
            for (i = 0; i < WORD_LENGTH; i++) {
                incorrect_word[i] = toupper(incorrect_word[i]);
            }
            for (i = 0; i < WORD_LENGTH; i++) {
                if (correct_word[i] == incorrect_word[i]) {
                    num_correct_letters++;
                }
            }
            if (num_correct_letters == WORD_LENGTH) {
                num_correct_words++;
            } else {
                num_incorrect_words++;
            }
            num_words_typed++;
        }
    }

    time_t end_time = time(NULL);
    time_elapsed = difftime(end_time, start_time);

    accuracy = (double)num_correct_words / total_words * 100.0;
    speed = (double)total_letters / time_elapsed * 60.0;

    printf("\n");
    printf("Test Results:\n");
    printf("Accuracy: %.2f%%\n", accuracy);
    printf("Speed: %.2f words per minute\n", speed);

    return 0;
}
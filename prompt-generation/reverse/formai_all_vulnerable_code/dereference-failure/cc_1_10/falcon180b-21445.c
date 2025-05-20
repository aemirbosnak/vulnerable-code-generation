//Falcon-180B DATASET v1.0 Category: Typing Speed Test ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

#define WORD_LENGTH 5
#define NUM_WORDS 10
#define TIME_LIMIT 60

char *words[NUM_WORDS] = {"amour", "coeur", "baiser", "soupir", "tendresse", "caresse", "passion", "désir", "enchantement", "charme"};

int main() {
    srand(time(NULL));
    int random_word_index = rand() % NUM_WORDS;
    char *random_word = words[random_word_index];
    char *typed_word = malloc(WORD_LENGTH + 1);
    memset(typed_word, '\0', WORD_LENGTH + 1);
    int correct_letters = 0;
    int wrong_letters = 0;
    int total_letters = 0;
    int score = 0;
    int time_left = TIME_LIMIT;
    int start_time = time(NULL);
    int elapsed_time = 0;

    printf("Welcome to the Romantic Typing Speed Test!\n");
    printf("You have %d seconds to type the word '%s'.\n", TIME_LIMIT, random_word);
    printf("Press enter to begin...\n");
    getchar();

    while (time_left > 0 && total_letters < WORD_LENGTH) {
        char input_char = getchar();
        if (isalpha(input_char)) {
            total_letters++;
            if (input_char == tolower(random_word[total_letters - 1])) {
                correct_letters++;
            } else {
                wrong_letters++;
            }
        }
        typed_word[total_letters - 1] = input_char;
        printf("\rTyped word: %s", typed_word);
        fflush(stdout);
        time_left--;
        elapsed_time++;
    }

    free(typed_word);
    printf("\nTest complete! You scored %d points.\n", score);
    printf("You typed %d correct letters and %d wrong letters.\n", correct_letters, wrong_letters);
    printf("Your final score is %d out of %d.\n", score, WORD_LENGTH);
    printf("Your typing speed is %d characters per second.\n", (WORD_LENGTH * 60) / elapsed_time);

    return 0;
}
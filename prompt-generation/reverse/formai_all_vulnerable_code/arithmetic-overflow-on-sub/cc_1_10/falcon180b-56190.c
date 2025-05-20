//Falcon-180B DATASET v1.0 Category: Typing Speed Test ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WORDS 100
#define MAX_WORD_LENGTH 20
#define SPEED_TEST_DURATION 60

typedef struct {
    char word[MAX_WORD_LENGTH];
    int length;
} Word;

void generate_random_word(char* word) {
    const char alphanum[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    int i = 0;
    while (i < MAX_WORD_LENGTH) {
        int rand_index = rand() % (sizeof(alphanum) - 1);
        word[i] = alphanum[rand_index];
        i++;
    }
    word[i] = '\0';
}

int main() {
    srand(time(NULL));

    Word words[MAX_WORDS];
    int num_words = 0;

    printf("Welcome to the Sherlock Holmes Typing Speed Test!\n");
    printf("In this test, you will be presented with random words to type.\n");
    printf("You have %d seconds to type as many words as possible.\n", SPEED_TEST_DURATION);
    printf("Press enter to begin...\n");

    getchar();

    clock_t start_time = clock();
    while (clock() - start_time < SPEED_TEST_DURATION * CLOCKS_PER_SEC) {
        if (num_words >= MAX_WORDS) {
            break;
        }

        generate_random_word(words[num_words].word);
        words[num_words].length = strlen(words[num_words].word);
        num_words++;
    }

    printf("\nTime's up! Here are your results:\n");
    printf("You typed %d words in %d seconds.\n", num_words, SPEED_TEST_DURATION);
    printf("Your typing speed is %d words per second.\n", (int)((float)num_words / SPEED_TEST_DURATION));

    return 0;
}
//Falcon-180B DATASET v1.0 Category: Typing Speed Test ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_WORDS 50
#define WORD_LENGTH 10

char words[NUM_WORDS][WORD_LENGTH] = {
    "apple", "banana", "cherry", "date", "elderberry", "fig", "grape",
    "honeydew", "kiwi", "lemon", "mango", "nectarine", "orange", "pear",
    "plum", "quince", "raspberry", "strawberry", "tangerine", "watermelon",
    "xylophone", "yellow", "zebra", "balloon", "carrot", "dinosaur", "elephant",
    "flower", "guitar", "hamburger", "igloo", "jellyfish", "kangaroo", "lion",
    "monkey", "necktie", "ostrich", "penguin", "queen", "robot", "spider",
    "tiger", "umbrella", "violin", "whale", "xylophone", "yellow", "zebra"
};

void random_word(char word[]) {
    int i;
    for (i = 0; i < WORD_LENGTH; i++) {
        word[i] = words[rand() % NUM_WORDS][i];
    }
    word[WORD_LENGTH] = '\0';
}

int main(void) {
    int i;
    char word[WORD_LENGTH + 1];
    int correct_words = 0;
    int total_words = 0;
    int start_time, end_time;
    double elapsed_time;
    int words_per_minute;

    srand(time(NULL));

    printf("Welcome to the Typing Speed Test!\n");
    printf("You will be given a series of words to type.\n");
    printf("Type as many words as you can in one minute.\n");
    printf("Press enter to begin.\n");
    scanf("%c", &word[0]);

    start_time = clock();

    while (1) {
        random_word(word);
        printf("%s ", word);

        for (i = 0; i < WORD_LENGTH; i++) {
            if (word[i]!= '\0') {
                printf("%c", word[i]);
            }
        }

        printf("\n");

        total_words++;

        if (total_words == NUM_WORDS) {
            break;
        }
    }

    end_time = clock();
    elapsed_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;
    words_per_minute = (double)total_words / elapsed_time;

    printf("\nTest complete!\n");
    printf("You typed %d words correctly.\n", correct_words);
    printf("You typed %d words in total.\n", total_words);
    printf("Your typing speed is %.2f words per minute.\n", words_per_minute);

    return 0;
}
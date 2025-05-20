//Falcon-180B DATASET v1.0 Category: Typing Speed Test ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_WORDS 10
#define MAX_WORD_LEN 20

struct word {
    char word[MAX_WORD_LEN];
    int length;
};

void generate_word(char *word, int length) {
    int i;
    for (i = 0; i < length; i++) {
        word[i] = 'a' + rand() % 26;
    }
    word[length] = '\0';
}

int main() {
    int i, j, num_words, total_chars, correct_chars, speed, accuracy;
    char input[MAX_WORD_LEN];
    struct word words[MAX_WORDS];
    time_t start_time, end_time;

    printf("Welcome to the Claude Shannon Typing Speed Test!\n");
    printf("Please enter the number of words you would like to type:\n");
    scanf("%d", &num_words);

    if (num_words > MAX_WORDS || num_words < 1) {
        printf("Invalid number of words. Please enter a number between 1 and %d.\n", MAX_WORDS);
        return 1;
    }

    srand(time(NULL));

    for (i = 0; i < num_words; i++) {
        generate_word(words[i].word, rand() % MAX_WORD_LEN + 4);
        words[i].length = strlen(words[i].word);
    }

    printf("Please type the following words:\n");

    for (i = 0; i < num_words; i++) {
        printf("%s\n", words[i].word);
    }

    fflush(stdout);
    total_chars = 0;
    correct_chars = 0;

    start_time = time(NULL);
    for (i = 0; i < num_words; i++) {
        scanf("%s", input);
        if (strcmp(input, words[i].word) == 0) {
            correct_chars += words[i].length;
        }
        total_chars += words[i].length;
    }

    end_time = time(NULL);

    speed = (int) (total_chars / (end_time - start_time) + 0.5);
    accuracy = (int) ((float) correct_chars / total_chars * 100 + 0.5);

    printf("\nResults:\n");
    printf("Words per minute: %d\n", speed);
    printf("Accuracy: %d%%\n", accuracy);

    return 0;
}
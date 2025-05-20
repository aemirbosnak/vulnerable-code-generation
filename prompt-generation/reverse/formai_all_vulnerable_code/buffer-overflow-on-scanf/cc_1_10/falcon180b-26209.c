//Falcon-180B DATASET v1.0 Category: Typing Speed Test ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_WORDS 100
#define MAX_WORD_LENGTH 20

struct word {
    char word[MAX_WORD_LENGTH];
    int length;
};

void generate_random_word(char *word) {
    int i;
    for (i = 0; i < strlen(word); i++) {
        word[i] = rand() % 26 + 'a';
    }
    word[strlen(word)] = '\0';
}

int main() {
    int num_words, i, j, correct_words = 0, total_words = 0, current_speed = 0, max_speed = 0;
    char input[MAX_WORD_LENGTH];
    struct word words[MAX_WORDS];
    time_t start_time, end_time;

    printf("Welcome to the Brave C Typing Speed Test!\n");
    printf("How many words do you want to type? ");
    scanf("%d", &num_words);

    srand(time(NULL));

    for (i = 0; i < num_words; i++) {
        generate_random_word(words[i].word);
        words[i].length = strlen(words[i].word);
    }

    printf("Type as many words as you can in 60 seconds.\n");
    printf("Press enter after each word.\n");

    start_time = time(NULL);

    while (total_words < num_words && (difftime(time(NULL), start_time) < 60)) {
        fgets(input, MAX_WORD_LENGTH, stdin);
        input[strcspn(input, "\n")] = '\0';

        if (strcmp(input, words[total_words].word) == 0) {
            correct_words++;
        }

        total_words++;
    }

    end_time = time(NULL);
    current_speed = (int) (total_words / (difftime(end_time, start_time) + 0.0));
    max_speed = (current_speed > max_speed)? current_speed : max_speed;

    printf("\nYou typed %d words correctly out of %d.\n", correct_words, num_words);
    printf("Your typing speed is %d words per minute.\n", current_speed);
    printf("Your maximum typing speed is %d words per minute.\n", max_speed);

    return 0;
}
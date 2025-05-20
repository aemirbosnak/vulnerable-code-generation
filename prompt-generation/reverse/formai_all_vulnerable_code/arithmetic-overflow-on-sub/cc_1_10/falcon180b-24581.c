//Falcon-180B DATASET v1.0 Category: Typing Speed Test ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

#define WPM_THRESHOLD 200
#define MAX_WPM 300
#define MIN_WPM 100

typedef struct {
    char word[100];
    int length;
    int correct;
} word_t;

int main() {
    srand(time(NULL));

    word_t words[] = {
        {"happy", 5, 0},
        {"programmer", 10, 0},
        {"example", 7, 0},
        {"program", 7, 0},
        {"style", 5, 0},
        {"instructions", 11, 0},
        {"minimum", 7, 0},
        {"lines", 5, 0},
        {"creative", 7, 0},
        {"code", 4, 0},
        {"compile", 7, 0},
        {"run", 3, 0},
        {"error", 5, 0},
        {"unique", 6, 0},
        {"speed", 5, 0},
        {"test", 4, 0}
    };

    int word_count = sizeof(words) / sizeof(word_t);
    int word_index = rand() % word_count;
    word_t current_word = words[word_index];

    printf("Welcome to the Happy Typing Speed Test!\n");
    printf("You will be typing the word '%s'.\n", current_word.word);
    printf("Press enter to begin.\n");

    fflush(stdin);
    fgets(current_word.word, sizeof(current_word.word), stdin);

    int start_time = clock();
    while (1) {
        char c = getchar();
        if (c == '\n') {
            break;
        } else if (isalnum(c)) {
            if (tolower(c) == tolower(current_word.word[current_word.correct])) {
                current_word.correct++;
            } else {
                printf("Incorrect letter: %c\n", c);
            }
        }
    }

    int end_time = clock();
    int elapsed_time = (end_time - start_time) / CLOCKS_PER_SEC;

    int wpm = (current_word.length * 60) / elapsed_time;

    if (wpm >= WPM_THRESHOLD) {
        printf("Congratulations! You are an expect programmer!\n");
    } else if (wpm < MIN_WPM) {
        printf("You need to practice more.\n");
    } else {
        printf("Your typing speed is %d WPM.\n", wpm);
    }

    return 0;
}
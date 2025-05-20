//Falcon-180B DATASET v1.0 Category: Typing Speed Test ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 20

struct word {
    char word[MAX_WORD_LENGTH];
    int length;
};

int main() {
    srand(time(NULL));
    int num_words = rand() % MAX_WORDS + 1;
    struct word words[MAX_WORDS];
    int i;

    for (i = 0; i < num_words; i++) {
        int length = rand() % MAX_WORD_LENGTH + 1;
        char word[MAX_WORD_LENGTH];
        int j;

        for (j = 0; j < length; j++) {
            word[j] = rand() % 26 + 'a';
        }

        strcpy(words[i].word, word);
        words[i].length = length;
    }

    printf("Type the following words:\n");
    for (i = 0; i < num_words; i++) {
        printf("%s\n", words[i].word);
    }

    int correct = 0;
    int incorrect = 0;
    int total_words = 0;
    int max_speed = 0;
    int current_speed = 0;

    char input[MAX_WORD_LENGTH];
    int length;

    for (i = 0; i < num_words; i++) {
        printf("Word %d: ", i + 1);
        scanf("%s", input);

        length = strlen(input);

        if (length == words[i].length && strcmp(input, words[i].word) == 0) {
            correct++;
        } else {
            incorrect++;
        }

        total_words++;

        if (correct == total_words) {
            max_speed = (int)((double)total_words / (double)5 * 60);
        } else {
            current_speed = (int)((double)correct / (double)total_words * 100);

            if (current_speed > max_speed) {
                max_speed = current_speed;
            }
        }
    }

    printf("\nYou typed %d words correctly and %d words incorrectly.\n", correct, incorrect);
    printf("Your typing speed is %d words per minute.\n", max_speed);

    return 0;
}
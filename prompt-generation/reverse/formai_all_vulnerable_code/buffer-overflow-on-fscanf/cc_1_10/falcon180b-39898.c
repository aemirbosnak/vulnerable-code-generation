//Falcon-180B DATASET v1.0 Category: Typing Speed Test ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

#define MAX_WORD_LENGTH 20
#define MAX_WORDS 100
#define MAX_TEST_TIME 60

struct word {
    char word[MAX_WORD_LENGTH];
    int length;
};

void generate_words(struct word words[], int num_words) {
    FILE *file = fopen("words.txt", "r");
    int i = 0;

    while (i < num_words && fscanf(file, "%s", words[i].word)!= EOF) {
        words[i].length = strlen(words[i].word);
        i++;
    }

    fclose(file);
}

int main() {
    struct word words[MAX_WORDS];
    int num_words, max_speed = 0, speed = 0, correct = 0, incorrect = 0;
    char input[MAX_WORD_LENGTH];
    int i, j, k, index;
    time_t start_time, end_time;

    printf("Welcome to the Typing Speed Test!\n");
    printf("You will have %d seconds to type as many words as you can.\n", MAX_TEST_TIME);

    generate_words(words, MAX_WORDS);
    num_words = rand() % MAX_WORDS;

    start_time = time(NULL);

    for (i = 0; i < num_words; i++) {
        printf("\nWord %d: ", i + 1);
        for (j = 0; j < words[i].length; j++) {
            printf("_");
        }
        printf("\n");

        fflush(stdout);
        fgets(input, MAX_WORD_LENGTH, stdin);

        for (k = 0; k < words[i].length; k++) {
            if (tolower(input[k])!= tolower(words[i].word[k])) {
                incorrect++;
            } else {
                correct++;
            }
        }

        if (correct > max_speed) {
            max_speed = correct;
        }

        speed += correct;
    }

    end_time = time(NULL);

    printf("\nTest complete!\n");
    printf("You typed %d words correctly and %d words incorrectly.\n", correct, incorrect);
    printf("Your typing speed is %d words per minute.\n", (int)((float)speed / (end_time - start_time) * 60));
    printf("Your maximum speed was %d words per minute.\n", max_speed);

    return 0;
}
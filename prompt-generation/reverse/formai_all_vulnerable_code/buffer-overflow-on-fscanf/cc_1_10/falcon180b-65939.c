//Falcon-180B DATASET v1.0 Category: Typing Speed Test ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>

#define MAX_WORDS 100
#define MAX_WORD_LENGTH 20

struct word {
    char word[MAX_WORD_LENGTH + 1];
    int length;
};

void load_words(struct word words[], int num_words) {
    FILE *file = fopen("words.txt", "r");
    if (file == NULL) {
        printf("Error loading words.txt\n");
        exit(1);
    }

    int i = 0;
    while (fscanf(file, "%s", words[i].word)!= EOF) {
        words[i].length = strlen(words[i].word);
        i++;
        if (i >= num_words) {
            break;
        }
    }

    fclose(file);
}

int main() {
    int num_words = 0;
    struct word words[MAX_WORDS];

    load_words(words, MAX_WORDS);
    num_words = MAX_WORDS;

    int score = 0;
    int correct_words = 0;
    int incorrect_words = 0;

    time_t start_time = time(NULL);

    printf("Type as many words as you can in 60 seconds.\n");

    for (int i = 0; i < num_words; i++) {
        char input[MAX_WORD_LENGTH + 1];
        printf("%s: ", words[i].word);
        fgets(input, sizeof(input), stdin);

        int input_length = strlen(input);
        if (input_length > words[i].length) {
            input[words[i].length] = '\0';
        }

        if (strcmp(input, words[i].word) == 0) {
            correct_words++;
        } else {
            incorrect_words++;
        }

        score += words[i].length;
    }

    time_t end_time = time(NULL);

    printf("\nYou typed %d words correctly and %d words incorrectly.\n", correct_words, incorrect_words);
    printf("Your final score is %d.\n", score);
    printf("Your typing speed is %d words per minute.\n", (int) (score / (end_time - start_time) * 60));

    return 0;
}
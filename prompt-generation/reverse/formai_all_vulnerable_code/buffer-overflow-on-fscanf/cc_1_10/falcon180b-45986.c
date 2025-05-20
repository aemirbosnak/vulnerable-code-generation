//Falcon-180B DATASET v1.0 Category: Typing Speed Test ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WORD_LENGTH 20
#define NUM_WORDS 100

struct word_struct {
    char word[MAX_WORD_LENGTH];
    int length;
};

void load_words(struct word_struct* words) {
    FILE* file = fopen("words.txt", "r");
    if (!file) {
        printf("Error loading words file\n");
        exit(1);
    }

    int num_words = 0;
    while (fscanf(file, "%s", words[num_words].word)!= EOF) {
        words[num_words].length = strlen(words[num_words].word);
        num_words++;
    }

    fclose(file);
}

int main() {
    srand(time(NULL));
    struct word_struct words[NUM_WORDS];
    load_words(words);

    int num_correct = 0;
    int num_incorrect = 0;
    int num_words_typed = 0;
    int num_words_missed = 0;

    for (int i = 0; i < NUM_WORDS; i++) {
        printf("Word %d: ", i + 1);
        char input[MAX_WORD_LENGTH];
        fgets(input, MAX_WORD_LENGTH, stdin);

        int input_length = strlen(input);
        if (input_length == words[i].length && strcmp(input, words[i].word) == 0) {
            num_correct++;
        } else {
            num_incorrect++;
        }

        num_words_typed += input_length;
        num_words_missed += words[i].length;
    }

    double accuracy = (double)num_correct / NUM_WORDS * 100;
    double wpm = (double)num_words_typed / (5 * NUM_WORDS) * 60;

    printf("Accuracy: %.2f%%\n", accuracy);
    printf("Words per minute: %.2f\n", wpm);
    printf("Words typed: %d\n", num_words_typed);
    printf("Words missed: %d\n", num_words_missed);

    return 0;
}
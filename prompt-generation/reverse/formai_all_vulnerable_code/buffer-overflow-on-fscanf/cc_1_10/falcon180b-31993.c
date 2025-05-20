//Falcon-180B DATASET v1.0 Category: Typing Speed Test ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WORDS 100
#define MAX_WORD_LENGTH 20

struct word {
    char text[MAX_WORD_LENGTH];
    int length;
};

void load_words(struct word *words, int num_words) {
    FILE *file = fopen("words.txt", "r");
    if (file == NULL) {
        printf("Error loading words file.\n");
        exit(1);
    }

    int count = 0;
    while (count < num_words && fscanf(file, "%s", words[count].text)!= EOF) {
        words[count].length = strlen(words[count].text);
        count++;
    }

    fclose(file);
}

int main() {
    srand(time(NULL));

    int num_words = rand() % MAX_WORDS + 1;
    struct word words[MAX_WORDS];
    load_words(words, num_words);

    int correct_count = 0;
    int incorrect_count = 0;
    int total_count = 0;

    printf("Welcome to the C Typing Speed Test!\n");
    printf("You will be typing %d words.\n", num_words);

    for (int i = 0; i < num_words; i++) {
        printf("Word %d: %s\n", i + 1, words[i].text);
        char input[MAX_WORD_LENGTH];
        fgets(input, MAX_WORD_LENGTH, stdin);
        input[strcspn(input, "\n")] = '\0';

        if (strcmp(words[i].text, input) == 0) {
            correct_count++;
        } else {
            incorrect_count++;
        }

        total_count++;
    }

    double accuracy = (double)correct_count / total_count * 100;
    double words_per_minute = (double)total_count / (5 * num_words) * 60;

    printf("Results:\n");
    printf("Correct: %d\n", correct_count);
    printf("Incorrect: %d\n", incorrect_count);
    printf("Accuracy: %.2f%%\n", accuracy);
    printf("Words per minute: %.2f\n", words_per_minute);

    return 0;
}
//Falcon-180B DATASET v1.0 Category: Typing Speed Test ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WORDS 100
#define MAX_WORD_LENGTH 10

char words[MAX_WORDS][MAX_WORD_LENGTH];
int num_words;

void generate_words() {
    FILE *file = fopen("words.txt", "r");
    char word[MAX_WORD_LENGTH];
    int i = 0;

    while (fscanf(file, "%s", word)!= EOF) {
        strcpy(words[i], word);
        i++;
    }

    num_words = i;
    fclose(file);
}

int main() {
    srand(time(NULL));
    generate_words();

    printf("Welcome to the Typing Speed Test!\n");
    printf("You will be typing %d words.\n", num_words);
    printf("Press enter to begin:\n");
    getchar();

    int correct = 0;
    int incorrect = 0;
    int total_words = 0;
    int current_word = rand() % num_words;
    char input[MAX_WORD_LENGTH];

    while (total_words < num_words) {
        printf("\nWord %d: %s\n", total_words + 1, words[current_word]);
        fflush(stdout);

        if (fgets(input, MAX_WORD_LENGTH, stdin)) {
            input[strcspn(input, "\n")] = '\0';

            if (strcmp(input, words[current_word]) == 0) {
                correct++;
            } else {
                incorrect++;
            }

            total_words++;
            current_word = rand() % num_words;
        } else {
            printf("Error reading input.\n");
            return 1;
        }
    }

    printf("\nTest complete!\n");
    printf("You typed %d words correctly and %d words incorrectly.\n", correct, incorrect);

    return 0;
}
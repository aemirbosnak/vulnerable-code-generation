//Falcon-180B DATASET v1.0 Category: Typing Speed Test ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WORDS 100
#define WORD_LENGTH 10

char words[MAX_WORDS][WORD_LENGTH];
int num_words;

void generate_words() {
    FILE *file = fopen("words.txt", "r");
    if (file == NULL) {
        printf("Error: Could not open words file.\n");
        exit(1);
    }

    num_words = 0;
    while (fscanf(file, "%s", words[num_words])!= EOF) {
        num_words++;
    }

    fclose(file);
}

int main() {
    srand(time(NULL));
    generate_words();

    int score = 0;
    int num_correct = 0;
    int num_incorrect = 0;

    for (int i = 0; i < num_words; i++) {
        int length = strlen(words[i]);
        char *word = (char *) malloc(length + 1);
        strcpy(word, words[i]);

        char *shuffled_word = (char *) malloc(length + 1);
        for (int j = 0; j < length; j++) {
            int k = rand() % length;
            char temp = word[j];
            word[j] = word[k];
            word[k] = temp;
        }
        strcpy(shuffled_word, word);

        printf("Type the following word: %s\n", shuffled_word);
        char input[WORD_LENGTH];
        fgets(input, WORD_LENGTH, stdin);

        if (strcmp(input, shuffled_word) == 0) {
            num_correct++;
        } else {
            num_incorrect++;
        }

        free(word);
        free(shuffled_word);
    }

    score = (num_correct * 100) / num_words;

    printf("You scored %d%%\n", score);

    return 0;
}
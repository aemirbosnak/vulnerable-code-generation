//Falcon-180B DATASET v1.0 Category: Typing Speed Test ; Style: careful
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include<ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

struct word {
    char word[MAX_WORD_LENGTH];
    int length;
};

void load_words(struct word *words, int num_words) {
    FILE *file = fopen("words.txt", "r");
    if (file == NULL) {
        printf("Error loading words\n");
        exit(1);
    }

    int count = 0;
    while (count < num_words && fscanf(file, "%s", words[count].word)!= EOF) {
        words[count].length = strlen(words[count].word);
        count++;
    }

    fclose(file);
}

int main() {
    int num_words = 10;
    struct word words[MAX_WORDS];

    load_words(words, num_words);

    int num_correct = 0;
    int num_incorrect = 0;
    int num_skipped = 0;

    printf("C Typing Speed Test\n");
    printf("=====================\n");

    for (int i = 0; i < num_words; i++) {
        printf("Word %d: ", i+1);
        for (int j = 0; j < words[i].length; j++) {
            printf("_");
        }
        printf("\n");

        char input[MAX_WORD_LENGTH];
        fgets(input, MAX_WORD_LENGTH, stdin);

        input[strcspn(input, "\n")] = '\0';

        if (strcmp(input, words[i].word) == 0) {
            num_correct++;
        } else {
            num_incorrect++;
        }
    }

    printf("\nResults:\n");
    printf("Correct: %d\n", num_correct);
    printf("Incorrect: %d\n", num_incorrect);
    printf("Skipped: %d\n", num_skipped);

    return 0;
}
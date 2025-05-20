//Falcon-180B DATASET v1.0 Category: Typing Speed Test ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WORD_LENGTH 20
#define MAX_NUM_WORDS 100

typedef struct {
    char word[MAX_WORD_LENGTH];
    int length;
    int index;
} Word;

void load_words(Word words[], int num_words) {
    FILE *file = fopen("words.txt", "r");
    if (file == NULL) {
        printf("Error: Could not open words.txt\n");
        exit(1);
    }

    int count = 0;
    while (count < num_words && fscanf(file, "%s", words[count].word)!= EOF) {
        words[count].length = strlen(words[count].word);
        words[count].index = count;
        count++;
    }

    fclose(file);
}

void shuffle_words(Word words[], int num_words) {
    for (int i = 0; i < num_words; i++) {
        int j = rand() % num_words;
        Word temp = words[i];
        words[i] = words[j];
        words[j] = temp;
    }
}

void print_word(Word word) {
    for (int i = 0; i < word.length; i++) {
        printf("*");
    }
    printf("\n");
}

int main() {
    Word words[MAX_NUM_WORDS];
    int num_words = 0;

    load_words(words, MAX_NUM_WORDS);
    num_words = rand() % MAX_NUM_WORDS + 1;

    srand(time(NULL));
    shuffle_words(words, num_words);

    int score = 0;
    int correct = 0;

    for (int i = 0; i < num_words; i++) {
        Word word = words[i];

        printf("Word %d:\n", i + 1);
        print_word(word);

        char input[MAX_WORD_LENGTH];
        fgets(input, MAX_WORD_LENGTH, stdin);
        input[strcspn(input, "\n")] = '\0';

        if (strcmp(input, word.word) == 0) {
            correct++;
        }

        if (i == num_words - 1) {
            printf("Your final score is %d out of %d.\n", correct, num_words);
        }
    }

    return 0;
}
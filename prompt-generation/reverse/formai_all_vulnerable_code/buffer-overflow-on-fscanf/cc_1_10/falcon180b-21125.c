//Falcon-180B DATASET v1.0 Category: Typing Speed Test ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_WORDS 100
#define MAX_WORD_LENGTH 20

struct word {
    char word[MAX_WORD_LENGTH];
    int length;
    int difficulty;
};

void load_words(struct word words[]) {
    FILE *file = fopen("words.txt", "r");
    if (file == NULL) {
        printf("Error loading words file\n");
        exit(1);
    }

    int count = 0;
    while (fscanf(file, "%s %d", words[count].word, &words[count].difficulty)!= EOF) {
        words[count].length = strlen(words[count].word);
        count++;
    }

    fclose(file);
}

void shuffle_words(struct word words[], int n) {
    for (int i = 0; i < n; i++) {
        int rand_index = rand() % n;
        struct word temp = words[i];
        words[i] = words[rand_index];
        words[rand_index] = temp;
    }
}

void print_word(struct word word) {
    for (int i = 0; i < word.length; i++) {
        printf("*");
    }
}

int main() {
    srand(time(NULL));

    struct word words[MAX_WORDS];
    load_words(words);

    int num_words = rand() % MAX_WORDS + 1;
    printf("Typing test with %d words\n", num_words);

    shuffle_words(words, num_words);

    int total_correct = 0;
    int total_words = 0;

    for (int i = 0; i < num_words; i++) {
        printf("\nWord %d: ", i+1);
        print_word(words[i]);
        printf("\n");

        char input[MAX_WORD_LENGTH];
        fgets(input, MAX_WORD_LENGTH, stdin);

        if (strcasecmp(input, words[i].word) == 0) {
            printf("Correct!\n");
            total_correct++;
        } else {
            printf("Incorrect.\n");
        }

        total_words++;
    }

    printf("\nTest complete.\n");
    printf("You got %d out of %d correct.\n", total_correct, total_words);

    return 0;
}
//Falcon-180B DATASET v1.0 Category: Typing Speed Test ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

struct word {
    char word[MAX_WORD_LENGTH];
    int length;
};

void generate_words(struct word words[], int num_words) {
    FILE *file = fopen("words.txt", "r");
    if (file == NULL) {
        printf("Error: could not open words.txt\n");
        exit(1);
    }

    int num_read = 0;
    while (num_read < num_words && fscanf(file, "%s", words[num_read].word)!= EOF) {
        words[num_read].length = strlen(words[num_read].word);
        num_read++;
    }

    fclose(file);
}

void shuffle_words(struct word words[], int num_words) {
    for (int i = 0; i < num_words; i++) {
        int j = rand() % num_words;
        struct word temp = words[i];
        words[i] = words[j];
        words[j] = temp;
    }
}

void print_word(struct word word) {
    for (int i = 0; i < word.length; i++) {
        printf("%c", word.word[i]);
    }
    printf(" ");
}

int main() {
    struct word words[MAX_WORDS];
    int num_words = 0;

    generate_words(words, MAX_WORDS);
    num_words = MAX_WORDS;

    shuffle_words(words, num_words);

    clock_t start_time = clock();

    int correct_words = 0;

    printf("Type the words as they appear on the screen.\n");

    for (int i = 0; i < num_words; i++) {
        printf("Word %d: ", i + 1);
        char input[MAX_WORD_LENGTH];
        fgets(input, MAX_WORD_LENGTH, stdin);
        input[strcspn(input, "\n")] = '\0';

        if (strcmp(input, words[i].word) == 0) {
            correct_words++;
        }

        printf("\n");
    }

    clock_t end_time = clock();

    double time_taken = (double)(end_time - start_time) / CLOCKS_PER_SEC;

    printf("You typed %d words correctly out of %d words.\n", correct_words, num_words);
    printf("Your typing speed is %.2f words per minute.\n", (double)num_words / time_taken);

    return 0;
}
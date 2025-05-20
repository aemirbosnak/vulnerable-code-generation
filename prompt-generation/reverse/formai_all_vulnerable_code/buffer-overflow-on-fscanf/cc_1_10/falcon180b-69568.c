//Falcon-180B DATASET v1.0 Category: Typing Speed Test ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WORDS 1000
#define WORD_LENGTH_MIN 4
#define WORD_LENGTH_MAX 12

char *words[MAX_WORDS];
int num_words;
int word_length;

void generate_words() {
    FILE *file = fopen("words.txt", "r");
    if (file == NULL) {
        printf("Error: Unable to open words.txt\n");
        exit(1);
    }

    char word[WORD_LENGTH_MAX + 1];
    while (fscanf(file, "%s", word)!= EOF) {
        if (strlen(word) >= WORD_LENGTH_MIN && strlen(word) <= WORD_LENGTH_MAX) {
            words[num_words++] = strdup(word);
        }
    }

    fclose(file);
}

void shuffle_words() {
    for (int i = 0; i < num_words; i++) {
        int j = rand() % num_words;
        char *temp = words[i];
        words[i] = words[j];
        words[j] = temp;
    }
}

void print_words() {
    printf("Enter the following words:\n");
    for (int i = 0; i < num_words; i++) {
        printf("%d. %s\n", i + 1, words[i]);
    }
}

int main() {
    srand(time(NULL));

    generate_words();
    shuffle_words();

    int correct_words = 0;
    int incorrect_words = 0;
    int total_words = num_words;

    char input[WORD_LENGTH_MAX + 1];
    while (total_words > 0) {
        printf("Word %d: ", total_words);
        scanf("%s", input);

        if (strcmp(input, words[--total_words]) == 0) {
            correct_words++;
        } else {
            incorrect_words++;
        }
    }

    printf("\nYou typed %d words correctly and %d words incorrectly.\n", correct_words, incorrect_words);

    return 0;
}
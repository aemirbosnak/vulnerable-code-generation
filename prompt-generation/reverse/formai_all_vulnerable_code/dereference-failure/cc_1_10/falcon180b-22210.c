//Falcon-180B DATASET v1.0 Category: Browser Plugin ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024
#define MAX_WORD_LENGTH 64

typedef struct {
    char *word;
    int count;
} WordFrequency;

WordFrequency *initialize_word_frequency(char *text) {
    WordFrequency *word_frequency = malloc(sizeof(WordFrequency));
    word_frequency->word = strtok(text, ",.?!;:");
    word_frequency->count = 1;
    return word_frequency;
}

void update_word_frequency(WordFrequency *word_frequency, char *text) {
    char *next_word = strtok(NULL, ",.?!;:");
    while (next_word!= NULL) {
        if (strcmp(word_frequency->word, next_word) == 0) {
            word_frequency->count++;
        }
        next_word = strtok(NULL, ",.?!;:");
    }
}

void print_word_frequency(WordFrequency *word_frequency) {
    printf("%s: %d\n", word_frequency->word, word_frequency->count);
}

int main() {
    char text[MAX_LINE_LENGTH];
    printf("Enter a line of text: ");
    fgets(text, MAX_LINE_LENGTH, stdin);
    text[strcspn(text, "\n")] = '\0';

    WordFrequency *word_frequency = initialize_word_frequency(text);
    char *next_word = strtok(NULL, ",.?!;:");
    while (next_word!= NULL) {
        update_word_frequency(word_frequency, next_word);
        next_word = strtok(NULL, ",.?!;:");
    }

    print_word_frequency(word_frequency);

    return 0;
}
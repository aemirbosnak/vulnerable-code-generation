//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

struct word_t {
    char word[MAX_WORD_LENGTH];
    int frequency;
};

struct word_t words[MAX_WORDS];
int num_words;

void add_word(char *word) {
    int i;
    for (i = 0; i < num_words; i++) {
        if (strcmp(word, words[i].word) == 0) {
            words[i].frequency++;
            return;
        }
    }
    if (num_words >= MAX_WORDS) {
        printf("Error: Maximum number of words reached.\n");
        exit(1);
    }
    strcpy(words[num_words].word, word);
    words[num_words].frequency = 1;
    num_words++;
}

void print_word_frequencies() {
    int i;
    for (i = 0; i < num_words; i++) {
        printf("%s: %d\n", words[i].word, words[i].frequency);
    }
}

int main() {
    char word[MAX_WORD_LENGTH];
    char input[1000];
    char *token;
    FILE *file;

    num_words = 0;

    printf("Enter the name of the input file: ");
    scanf("%s", input);

    file = fopen(input, "r");
    if (file == NULL) {
        printf("Error: Unable to open input file.\n");
        exit(1);
    }

    while (fgets(input, sizeof(input), file)!= NULL) {
        token = strtok(input, ",.!?;");
        while (token!= NULL) {
            add_word(token);
            token = strtok(NULL, ",.!?;");
        }
    }

    fclose(file);

    print_word_frequencies();

    return 0;
}
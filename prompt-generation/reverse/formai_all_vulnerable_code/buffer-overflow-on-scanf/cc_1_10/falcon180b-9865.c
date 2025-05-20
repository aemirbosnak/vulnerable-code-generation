//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 10000
#define MAX_WORD_LENGTH 20

struct word {
    char *word;
    int count;
};

struct word words[MAX_WORDS];
int num_words = 0;

void load_dictionary(char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Error: could not open dictionary file\n");
        exit(1);
    }
    char word[MAX_WORD_LENGTH];
    while (fscanf(file, "%s", word)!= EOF) {
        if (num_words >= MAX_WORDS) {
            printf("Error: dictionary too large\n");
            exit(1);
        }
        words[num_words].word = strdup(word);
        words[num_words].count = 0;
        num_words++;
    }
    fclose(file);
}

void check_spelling(char *word) {
    int i;
    for (i = 0; i < num_words; i++) {
        if (strcmp(word, words[i].word) == 0) {
            words[i].count++;
            return;
        }
    }
    printf("Misspelled word: %s\n", word);
}

void print_misspelled_words() {
    int i;
    for (i = 0; i < num_words; i++) {
        if (words[i].count == 0) {
            printf("%s\n", words[i].word);
        }
    }
}

int main() {
    char filename[100];
    printf("Enter dictionary filename: ");
    scanf("%s", filename);
    load_dictionary(filename);

    char input[1000];
    while (fgets(input, 1000, stdin)!= NULL) {
        char *word = strtok(input, ",.?!;:");
        while (word!= NULL) {
            check_spelling(word);
            word = strtok(NULL, ",.?!;:");
        }
    }

    print_misspelled_words();

    return 0;
}
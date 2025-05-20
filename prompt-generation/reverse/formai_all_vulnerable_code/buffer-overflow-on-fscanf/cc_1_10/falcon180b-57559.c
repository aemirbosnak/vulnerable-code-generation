//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 20

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} Word;

Word words[MAX_WORDS];
int num_words = 0;

void add_word(char *word) {
    int i;
    for (i = 0; i < num_words; i++) {
        if (strcmp(word, words[i].word) == 0) {
            words[i].count++;
            return;
        }
    }
    if (num_words >= MAX_WORDS) {
        printf("Error: too many words\n");
        exit(1);
    }
    strcpy(words[num_words].word, word);
    words[num_words].count = 1;
    num_words++;
}

void print_misspelled_words(char *filename) {
    FILE *file;
    char word[MAX_WORD_LENGTH];
    int i;

    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: could not open file '%s'\n", filename);
        exit(1);
    }

    while (fscanf(file, "%s", word)!= EOF) {
        if (strlen(word) > MAX_WORD_LENGTH) {
            printf("Error: word '%s' is too long\n", word);
            exit(1);
        }
        for (i = 0; i < strlen(word); i++) {
            if (!isalpha(word[i])) {
                printf("Error: word '%s' contains non-alphabetic characters\n", word);
                exit(1);
            }
        }
        if (isalpha(word[0])) {
            word[0] = toupper(word[0]);
        }
        add_word(word);
    }

    fclose(file);

    for (i = 0; i < num_words; i++) {
        if (words[i].count == 1) {
            printf("%s: %d\n", words[i].word, words[i].count);
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(1);
    }
    print_misspelled_words(argv[1]);
    return 0;
}
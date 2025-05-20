//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 10000
#define MAX_WORD_LENGTH 50

typedef struct word_t {
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
        printf("Error: Maximum number of words reached.\n");
        exit(1);
    }
    strcpy(words[num_words].word, word);
    words[num_words].count = 1;
    num_words++;
}

void print_word_counts() {
    int i;
    for (i = 0; i < num_words; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }
}

int main() {
    char filename[100], word[100];
    FILE *file;
    int i, j, k, word_length;

    printf("Enter filename: ");
    scanf("%s", filename);

    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Could not open file.\n");
        exit(1);
    }

    while (fscanf(file, "%s", word)!= EOF) {
        word_length = strlen(word);
        if (word_length > MAX_WORD_LENGTH) {
            printf("Error: Word is too long.\n");
            exit(1);
        }
        for (i = 0; i < word_length; i++) {
            if (!isalpha(word[i])) {
                printf("Error: Word contains non-alphabetic character.\n");
                exit(1);
            }
        }
        for (i = 0; i < num_words; i++) {
            if (strcmp(word, words[i].word) == 0) {
                words[i].count++;
                break;
            }
        }
        if (i == num_words) {
            add_word(word);
        }
    }

    fclose(file);

    print_word_counts();

    return 0;
}
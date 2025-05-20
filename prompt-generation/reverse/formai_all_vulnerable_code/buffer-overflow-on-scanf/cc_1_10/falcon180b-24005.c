//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 100

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} Word;

void read_words(Word words[], int num_words) {
    FILE *fp;
    char line[MAX_WORD_LENGTH];
    int i = 0;

    fp = fopen("words.txt", "r");

    if (fp == NULL) {
        printf("Error opening words file.\n");
        exit(1);
    }

    while (fgets(line, MAX_WORD_LENGTH, fp)!= NULL) {
        char *word = strtok(line, " ");

        while (word!= NULL) {
            if (i >= num_words) {
                printf("Too many words in file.\n");
                exit(1);
            }

            strcpy(words[i].word, word);
            words[i].count = 0;

            i++;

            word = strtok(NULL, " ");
        }
    }

    fclose(fp);
}

void spell_check(char word[], Word words[], int num_words) {
    int i = 0;
    int length = strlen(word);

    while (i < length) {
        char c = tolower(word[i]);

        if (!isalpha(c)) {
            i++;
            continue;
        }

        int found = 0;

        for (int j = 0; j < num_words; j++) {
            if (strncmp(words[j].word, word, length) == 0) {
                found = 1;
                break;
            }
        }

        if (!found) {
            printf("%s is not in the dictionary.\n", word);
        }

        i++;
    }
}

int main() {
    Word words[MAX_WORDS];
    int num_words;

    printf("Enter the number of words in the dictionary: ");
    scanf("%d", &num_words);

    read_words(words, num_words);

    char word[MAX_WORD_LENGTH];

    while (1) {
        printf("Enter a word to spell check: ");
        scanf("%s", word);

        spell_check(word, words, num_words);
    }

    return 0;
}
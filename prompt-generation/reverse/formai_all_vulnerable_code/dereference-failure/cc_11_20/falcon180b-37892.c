//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 10000
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} Word;

int main() {
    FILE *file;
    char line[100];
    char word[MAX_WORD_LENGTH];
    int i;
    Word *words[MAX_WORDS];
    int num_words = 0;

    file = fopen("input.txt", "r");
    if (file == NULL) {
        printf("Error: Could not open file.\n");
        exit(1);
    }

    while (fgets(line, 100, file)!= NULL) {
        int len = strlen(line);
        for (i = 0; i < len; i++) {
            if (isalpha(line[i])) {
                int j = 0;
                while (isalpha(line[i + j]) && j < MAX_WORD_LENGTH - 1) {
                    word[j++] = tolower(line[i + j]);
                }
                word[j] = '\0';

                int found = 0;
                for (int k = 0; k < num_words; k++) {
                    if (strcmp(words[k]->word, word) == 0) {
                        words[k]->count++;
                        found = 1;
                        break;
                    }
                }
                if (!found) {
                    if (num_words >= MAX_WORDS) {
                        printf("Error: Exceeded maximum number of words.\n");
                        exit(1);
                    }
                    strcpy(words[num_words]->word, word);
                    words[num_words]->count = 1;
                    num_words++;
                }
            }
        }
    }

    fclose(file);

    printf("Total words: %d\n", num_words);

    for (i = 0; i < num_words; i++) {
        printf("%s: %d\n", words[i]->word, words[i]->count);
    }

    return 0;
}
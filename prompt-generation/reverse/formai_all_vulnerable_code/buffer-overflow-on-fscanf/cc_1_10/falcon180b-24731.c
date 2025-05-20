//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: minimalist
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX_WORDS 1000
#define MAX_WORD_LEN 20

struct word {
    char word[MAX_WORD_LEN];
    int count;
};

int main() {
    FILE *fp;
    char line[MAX_WORD_LEN];
    char word[MAX_WORD_LEN];
    struct word words[MAX_WORDS];
    int num_words = 0;
    int i, j;

    // Open the dictionary file
    fp = fopen("dictionary.txt", "r");
    if (fp == NULL) {
        printf("Error: could not open dictionary file.\n");
        return 1;
    }

    // Read in the words from the dictionary file
    while (fscanf(fp, "%s", word)!= EOF) {
        struct word *w = &words[num_words];
        strcpy(w->word, word);
        w->count = 1;
        num_words++;
    }
    fclose(fp);

    // Read in the text file
    fp = fopen("text.txt", "r");
    if (fp == NULL) {
        printf("Error: could not open text file.\n");
        return 1;
    }

    // Check spelling
    while (fscanf(fp, "%s", line)!= EOF) {
        for (i = 0; i < strlen(line); i++) {
            if (isalpha(line[i])) {
                for (j = 0; j < num_words; j++) {
                    if (strcasecmp(words[j].word, line) == 0) {
                        printf("Correct spelling: %s\n", words[j].word);
                        break;
                    }
                }
                if (j == num_words) {
                    printf("Incorrect spelling: %s\n", line);
                }
            }
        }
    }

    fclose(fp);
    return 0;
}
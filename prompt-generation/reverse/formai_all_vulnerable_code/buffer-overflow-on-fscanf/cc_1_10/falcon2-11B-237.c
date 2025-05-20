//Falcon2-11B DATASET v1.0 Category: Spell checking ; Style: Claude Shannon
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Define a structure to store word information
struct Word {
    char word[50];
    int count;
};

// Define a function to compare two words for spell checking
int compareWords(const void *a, const void *b) {
    const struct Word *w1 = (const struct Word *) a;
    const struct Word *w2 = (const struct Word *) b;
    return strcmp(w1->word, w2->word);
}

// Define a function to read words from a text file
void readWords(FILE *fp, struct Word *words, int maxWords) {
    char word[50];
    int i;

    for (i = 0; i < maxWords; i++) {
        if (fscanf(fp, "%s", word) == 1) {
            words[i].word[0] = tolower(word[0]);
            words[i].word[strlen(word)] = '\0';
            words[i].count = 1;
            qsort(words, i + 1, sizeof(struct Word), compareWords);
        }
    }
}

// Define a function to check for misspelled words in a text file
void checkWords(FILE *fp, struct Word *words, int maxWords) {
    char word[50];
    int i, j, k, misspelled;

    for (i = 0; i < maxWords; i++) {
        misspelled = 0;
        for (j = 0; j < i; j++) {
            if (strcmp(words[i].word, words[j].word) == 0) {
                if (words[i].count == 1 && words[j].count > 1) {
                    words[i].count = 0;
                    misspelled = 1;
                }
            }
        }
        if (misspelled == 0) {
            printf("%s\n", words[i].word);
        }
    }
}

int main(int argc, char *argv[]) {
    FILE *fp;
    struct Word words[100];
    int maxWords = 100;

    if (argc == 2) {
        fp = fopen(argv[1], "r");
        if (fp!= NULL) {
            readWords(fp, words, maxWords);
            checkWords(fp, words, maxWords);
            fclose(fp);
        } else {
            printf("Error opening file: %s\n", argv[1]);
        }
    } else {
        printf("Usage: %s <filename>\n", argv[0]);
    }

    return 0;
}
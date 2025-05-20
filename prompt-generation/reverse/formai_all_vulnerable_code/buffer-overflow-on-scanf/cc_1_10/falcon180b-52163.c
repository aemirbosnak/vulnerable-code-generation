//Falcon-180B DATASET v1.0 Category: Educational ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct WordFrequency {
    char word[51];
    int frequency;
};

void loadWords(struct WordFrequency words[], int maxWords, FILE *file) {
    char line[1025];
    char *word = strtok(line, ",.?!;:");
    int i = 0;

    while (word!= NULL && i < maxWords) {
        strcpy(words[i].word, word);
        words[i].frequency = 1;
        i++;
        word = strtok(NULL, ",.?!;:");
    }
}

void countWords(struct WordFrequency words[], int numWords, FILE *file) {
    char line[1025];
    char *word = strtok(line, ",.?!;:");

    while (word!= NULL) {
        int j;
        for (j = 0; j < numWords; j++) {
            if (strcmp(word, words[j].word) == 0) {
                words[j].frequency++;
                break;
            }
        }
        if (j == numWords) {
            strcpy(words[numWords - 1].word, word);
            words[numWords - 1].frequency = 1;
            numWords++;
        }
        word = strtok(NULL, ",.?!;:");
    }
}

void printWords(struct WordFrequency words[], int numWords) {
    int i;

    for (i = 0; i < numWords; i++) {
        printf("%s: %d\n", words[i].word, words[i].frequency);
    }
}

int main() {
    FILE *file;
    char filename[1025];
    int maxWords = 1000;
    struct WordFrequency words[maxWords];

    printf("Enter the name of the text file: ");
    scanf("%s", filename);

    file = fopen(filename, "r");

    if (file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    loadWords(words, maxWords, file);

    fclose(file);

    countWords(words, maxWords, file);

    printWords(words, maxWords);

    return 0;
}
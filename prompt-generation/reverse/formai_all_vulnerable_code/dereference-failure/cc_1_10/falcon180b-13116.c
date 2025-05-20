//Falcon-180B DATASET v1.0 Category: Word Frequency Counter ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000000
#define MAX_WORD_LENGTH 100

typedef struct {
    char word[MAX_WORD_LENGTH];
    int frequency;
} WordFrequency;

int main(int argc, char* argv[]) {
    FILE* file;
    char line[1024];
    char* word;
    WordFrequency* words = (WordFrequency*) malloc(MAX_WORDS * sizeof(WordFrequency));
    int numWords = 0;

    if (argc < 2) {
        printf("Please provide a filename.\n");
        return 1;
    }

    file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    while (fgets(line, sizeof(line), file)!= NULL) {
        word = strtok(line, ",.?!;:\"'");
        while (word!= NULL) {
            int i;
            for (i = 0; i < strlen(word); i++) {
                if (!isalpha(word[i])) {
                    word[i] = '\0';
                    break;
                }
            }
            if (i > 0) {
                strcpy(words[numWords].word, word);
                words[numWords].frequency++;
                numWords++;
            }
            word = strtok(NULL, ",.?!;:\"'");
        }
    }

    fclose(file);

    printf("Word\tFrequency\n");
    for (int i = 0; i < numWords; i++) {
        printf("%s\t%d\n", words[i].word, words[i].frequency);
    }

    free(words);
    return 0;
}
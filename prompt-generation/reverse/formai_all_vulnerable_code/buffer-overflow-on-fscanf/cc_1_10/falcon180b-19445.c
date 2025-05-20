//Falcon-180B DATASET v1.0 Category: Cat Language Translator ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 20

typedef struct {
    char english[MAX_WORD_LENGTH];
    char cat[MAX_WORD_LENGTH];
} Word;

void loadWords(Word words[]) {
    FILE *file = fopen("words.txt", "r");

    if (file == NULL) {
        printf("Error loading words file.\n");
        exit(1);
    }

    int count = 0;
    while (fscanf(file, "%s %s\n", words[count].english, words[count].cat)!= EOF) {
        count++;
    }

    fclose(file);
}

int main() {
    Word words[MAX_WORDS];
    loadWords(words);

    char input[MAX_WORD_LENGTH];
    char output[MAX_WORD_LENGTH];

    printf("Enter a sentence to translate:\n");
    fgets(input, MAX_WORD_LENGTH, stdin);

    int inputLength = strlen(input);
    int outputLength = 0;

    for (int i = 0; i < inputLength; i++) {
        if (isalpha(input[i])) {
            int j;
            for (j = 0; j < MAX_WORD_LENGTH; j++) {
                if (words[j].english[j] == tolower(input[i])) {
                    strcpy(output + outputLength, words[j].cat);
                    outputLength += strlen(words[j].cat);
                    break;
                }
            }
        } else {
            strcpy(output + outputLength, &input[i]);
            outputLength += 1;
        }
    }

    printf("Translated sentence: %s\n", output);

    return 0;
}
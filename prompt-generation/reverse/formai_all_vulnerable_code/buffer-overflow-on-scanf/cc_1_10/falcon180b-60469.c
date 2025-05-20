//Falcon-180B DATASET v1.0 Category: Greedy Algorithms ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH];
    int frequency;
} WordFrequency;

void readWords(char* filename, WordFrequency* words) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Unable to open file %s\n", filename);
        exit(1);
    }

    char word[MAX_WORD_LENGTH];
    while (fscanf(file, "%s", word)!= EOF) {
        int i;
        for (i = 0; i < strlen(word); i++) {
            word[i] = tolower(word[i]);
        }
        int found = false;
        for (i = 0; i < MAX_WORDS; i++) {
            if (strcmp(word, words[i].word) == 0) {
                words[i].frequency++;
                found = true;
                break;
            }
        }
        if (!found) {
            strcpy(words[i].word, word);
            words[i].frequency = 1;
            i++;
        }
    }

    fclose(file);
}

void sortWords(WordFrequency* words) {
    int i, j;
    char temp[MAX_WORD_LENGTH];
    WordFrequency tempW;

    for (i = 0; i < MAX_WORDS - 1; i++) {
        for (j = 0; j < MAX_WORDS - i - 1; j++) {
            if (words[j].frequency < words[j + 1].frequency) {
                strcpy(temp, words[j].word);
                words[j].frequency = words[j + 1].frequency;
                strcpy(words[j].word, words[j + 1].word);
                words[j + 1].frequency = tempW.frequency;
                strcpy(words[j + 1].word, temp);
            }
        }
    }
}

void printWords(WordFrequency* words) {
    int i;
    for (i = 0; i < MAX_WORDS; i++) {
        if (words[i].frequency > 0) {
            printf("%s: %d\n", words[i].word, words[i].frequency);
        }
    }
}

int main() {
    WordFrequency words[MAX_WORDS];

    char filename[50];
    printf("Enter the name of the input file: ");
    scanf("%s", filename);

    readWords(filename, words);

    sortWords(words);

    printf("Sorted words based on frequency:\n");
    printWords(words);

    return 0;
}
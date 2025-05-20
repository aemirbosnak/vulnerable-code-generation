//Falcon2-11B DATASET v1.0 Category: Text processing ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100
#define MAX_FILE_SIZE 100000

int main() {
    char filename[MAX_FILE_SIZE];
    printf("Enter the name of the text file: ");
    scanf("%s", filename);

    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening the file.\n");
        return 1;
    }

    char word[MAX_WORD_LENGTH];
    int wordCount[MAX_WORD_LENGTH];
    int maxWordCount = 0;
    int numWords = 0;

    while (fscanf(file, "%s", word)!= EOF) {
        wordCount[numWords] = 0;
        numWords++;

        for (int i = 0; word[i]!= '\0'; i++) {
            if (isalpha(word[i])) {
                word[i] = tolower(word[i]);
                wordCount[numWords]++;
            }
        }

        if (wordCount[numWords] > maxWordCount) {
            maxWordCount = wordCount[numWords];
        }
    }

    fclose(file);

    for (int i = 0; i < numWords; i++) {
        if (wordCount[i] == maxWordCount) {
            printf("Word: %s\tFrequency: %d\n", word, maxWordCount);
        }
    }

    return 0;
}
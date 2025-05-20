//Falcon-180B DATASET v1.0 Category: Image Classification system ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_SIZE 100

struct Word {
    char word[MAX_WORD_SIZE];
    int count;
};

int main() {
    struct Word words[MAX_WORDS];
    int numWords = 0;

    // Read in the text file
    FILE* file = fopen("text.txt", "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    // Count the number of words in the file
    char ch;
    while ((ch = fgetc(file))!= EOF) {
        if (isspace(ch)) {
            numWords++;
        }
    }
    rewind(file);

    // Read in the words and count their frequencies
    char word[MAX_WORD_SIZE];
    while (fscanf(file, "%s", word)!= EOF) {
        int i;
        for (i = 0; i < numWords; i++) {
            if (strcmp(word, words[i].word) == 0) {
                words[i].count++;
                break;
            }
        }
        if (i == numWords) {
            strcpy(words[numWords].word, word);
            words[numWords].count = 1;
            numWords++;
        }
    }

    // Sort the words alphabetically
    for (int i = 0; i < numWords - 1; i++) {
        for (int j = i + 1; j < numWords; j++) {
            if (strcmp(words[i].word, words[j].word) > 0) {
                struct Word temp = words[i];
                words[i] = words[j];
                words[j] = temp;
            }
        }
    }

    // Print the word frequencies
    printf("Word frequencies:\n");
    for (int i = 0; i < numWords; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }

    return 0;
}
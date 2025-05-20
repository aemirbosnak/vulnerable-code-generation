//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: shape shifting
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX_WORDS 5000
#define MAX_WORD_LEN 20

typedef struct {
    char word[MAX_WORD_LEN];
    int count;
} WordCount;

int main() {
    FILE *file;
    char filename[MAX_WORD_LEN];
    char line[MAX_WORD_LEN];
    int numWords = 0;
    WordCount words[MAX_WORDS];

    printf("Enter the name of the file to check: ");
    scanf("%s", filename);

    file = fopen(filename, "r");

    if (file == NULL) {
        printf("Error: File not found.\n");
        return 1;
    }

    while (fgets(line, MAX_WORD_LEN, file)!= NULL) {
        int i = 0;
        char word[MAX_WORD_LEN];
        int len = strlen(line);

        while (i < len) {
            if (isalpha(line[i])) {
                strncat(word, &line[i], 1);
                i++;
            } else {
                if (strlen(word) > 0) {
                    numWords++;
                    if (numWords >= MAX_WORDS) {
                        printf("Maximum number of words reached.\n");
                        fclose(file);
                        return 1;
                    }
                    strcpy(words[numWords-1].word, word);
                    words[numWords-1].count = 1;
                }
                i++;
                strcpy(word, "");
            }
        }
    }

    fclose(file);

    printf("Enter the word to search for: ");
    scanf("%s", filename);

    int found = 0;
    int index = -1;

    for (int i = 0; i < numWords; i++) {
        if (strcmp(filename, words[i].word) == 0) {
            found = 1;
            index = i;
            break;
        }
    }

    if (found == 0) {
        printf("Word not found.\n");
    } else {
        printf("Word found %d time(s).\n", words[index].count);
    }

    return 0;
}
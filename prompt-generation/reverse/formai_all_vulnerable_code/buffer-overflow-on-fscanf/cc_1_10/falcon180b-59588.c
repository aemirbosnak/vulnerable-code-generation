//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: retro
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 20

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

void loadDictionary(char* filename, WordCount* dictionary) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error loading dictionary file.\n");
        exit(1);
    }

    int wordCount = 0;
    while (fscanf(file, "%s", dictionary[wordCount].word)!= EOF) {
        dictionary[wordCount].count = 0;
        wordCount++;
    }

    fclose(file);
}

int main() {
    char text[10000];
    printf("Enter text to spell check: ");
    fgets(text, sizeof(text), stdin);

    WordCount dictionary[MAX_WORDS];
    loadDictionary("dictionary.txt", dictionary);

    char* token = strtok(text, ",.?!;:");
    while (token!= NULL) {
        int i = 0;
        while (i < MAX_WORD_LENGTH && isalpha(token[i])) {
            token[i] = tolower(token[i]);
            i++;
        }

        if (i >= 3 && i <= MAX_WORD_LENGTH) {
            int found = 0;
            for (int j = 0; j < MAX_WORDS; j++) {
                if (strcmp(dictionary[j].word, token) == 0) {
                    found = 1;
                    break;
                }
            }

            if (!found) {
                printf("%s is not in the dictionary.\n", token);
            }
        }

        token = strtok(NULL, ",.?!;:");
    }

    return 0;
}
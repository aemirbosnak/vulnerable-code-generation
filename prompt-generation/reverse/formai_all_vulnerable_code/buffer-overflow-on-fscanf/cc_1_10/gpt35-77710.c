//FormAI DATASET v1.0 Category: Spell checking ; Style: light-weight
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

#define MAX_WORD_LENGTH 50

bool isAlphabet(char c) {
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
        return true;
    } else {
        return false;
    }
}

void toLowerCase(char *str) {
    int i = 0;
    while (str[i] != '\0') {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] = str[i] + 32;
        }
        i++;
    }
}

int main() {
    char sentence[1000];
    char word[MAX_WORD_LENGTH];
    char dictionary[1000][MAX_WORD_LENGTH];
    int dictionarySize = 0;

    // Load the dictionary file into memory
    FILE *fptr = fopen("dictionary.txt", "r");
    if (fptr == NULL) {
        printf("Unable to open dictionary file.\n");
        exit(EXIT_FAILURE);
    }

    while (fscanf(fptr, "%s", dictionary[dictionarySize]) != EOF) {
        toLowerCase(dictionary[dictionarySize]);
        dictionarySize++;
    }

    fclose(fptr);

    // Perform spell checking
    printf("Enter a sentence: ");
    fgets(sentence, 1000, stdin);

    int i = 0, j = 0, k = 0;
    bool incorrect = false;

    while (sentence[i] != '\0') {
        if (isAlphabet(sentence[i])) {
            word[k] = sentence[i];
            k++;
        } else if (k > 0) {
            word[k] = '\0';
            toLowerCase(word);

            bool found = false;

            for (j = 0; j < dictionarySize; j++) {
                if (strcmp(word, dictionary[j]) == 0) {
                    found = true;
                    break;
                }
            }

            if (!found) {
                printf("Incorrect spelling: %s\n", word);
                incorrect = true;
            }

            k = 0;
        }

        i++;
    }

    if (!incorrect) {
        printf("No spelling errors found.\n");
    }

    return 0;
}
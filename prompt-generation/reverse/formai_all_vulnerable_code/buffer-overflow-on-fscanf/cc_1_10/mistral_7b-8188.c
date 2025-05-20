//MISTRAL-7B DATASET v1.0 Category: Spell checking ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define DICTIONARY_SIZE 1000
#define WORD_LENGTH 50

typedef struct {
    char word[WORD_LENGTH];
} Dictionary;

void loadDictionary(Dictionary dictionary[], const char *filename) {
    FILE *fp = fopen(filename, "r");
    int i = 0;

    if (fp != NULL) {
        while (fscanf(fp, "%s", dictionary[i].word) != EOF) {
            i++;
        }
        fclose(fp);
    }
}

int checkSpelling(const char *word, Dictionary dictionary[], int size) {
    for (int i = 0; i < size; i++) {
        if (strcmp(word, dictionary[i].word) == 0) {
            return 1;
        }
    }
    return 0;
}

int main() {
    Dictionary dictionary[DICTIONARY_SIZE];
    char input[1024];
    char *token;
    int wordsFound = 0;
    int wordLength;

    loadDictionary(dictionary, "dictionary.txt");

    printf("Enter a sentence: ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0';

    token = strtok(input, " .,\\n:;\"'()");

    while (token != NULL) {
        wordLength = strlen(token);

        if (checkSpelling(token, dictionary, DICTIONARY_SIZE) == 1) {
            printf("%s is spelled correctly.\n", token);
            wordsFound++;
        } else {
            printf("%s is not in the dictionary.\n", token);
        }

        token = strtok(NULL, " .,\\n:;\"'()");
    }

    if (wordsFound < 5) {
        printf("You have entered less than 5 words. Try again.\n");
    }

    return 0;
}
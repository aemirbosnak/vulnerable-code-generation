//Falcon-180B DATASET v1.0 Category: Cat Language Translator ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH];
    char translation[MAX_WORD_LENGTH];
} WordPair;

int loadDictionary(WordPair *dictionary, int size) {
    FILE *file = fopen("dictionary.txt", "r");
    if (file == NULL) {
        printf("Error loading dictionary\n");
        return 0;
    }

    int count = 0;
    char line[MAX_WORD_LENGTH];
    while (fscanf(file, "%s %s\n", line, line)!= EOF) {
        strcpy(dictionary[count].word, line);
        strcpy(dictionary[count].translation, line);
        count++;
    }

    fclose(file);
    return count;
}

int translate(WordPair *dictionary, int size, char *input) {
    int i;
    for (i = 0; i < size; i++) {
        if (strcmp(dictionary[i].word, input) == 0) {
            printf("%s = %s\n", input, dictionary[i].translation);
            return 1;
        }
    }
    printf("No translation found for %s\n", input);
    return 0;
}

int main() {
    WordPair dictionary[100];
    int size = loadDictionary(dictionary, 100);

    char input[MAX_WORD_LENGTH];
    while (1) {
        printf("Enter a word to translate: ");
        scanf("%s", input);

        if (translate(dictionary, size, input)) {
            printf("Enter another word? (y/n): ");
            char choice;
            scanf("%c", &choice);
            if (choice == 'n') {
                break;
            }
        }
    }

    return 0;
}
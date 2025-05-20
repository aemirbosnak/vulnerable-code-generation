//MISTRAL-7B DATASET v1.0 Category: Spell checking ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 50
#define MAX_DICTIONARY_SIZE 10000

typedef struct {
    char word[MAX_WORD_LENGTH + 1];
    int is_valid;
} DictionaryEntry;

void load_dictionary(DictionaryEntry *dictionary, char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Unable to open dictionary file.\n");
        exit(1);
    }

    int index = 0;
    char line[MAX_WORD_LENGTH + 1];
    while (fgets(line, sizeof(line), file) != NULL) {
        size_t length = strlen(line);
        if (length > MAX_WORD_LENGTH || line[length - 1] == '\n') {
            line[length - 1] = '\0';
            length--;
        }
        strcpy(dictionary[index].word, line);
        dictionary[index].is_valid = 1;
        index++;
    }

    fclose(file);
}

int is_valid_word(char *word, DictionaryEntry *dictionary, int size) {
    for (int i = 0; i < size; i++) {
        if (strcmp(word, dictionary[i].word) == 0) {
            return dictionary[i].is_valid;
        }
    }

    return 0;
}

int main() {
    DictionaryEntry dictionary[MAX_DICTIONARY_SIZE];
    char filename[MAX_WORD_LENGTH + 1] = "dictionary.txt";

    load_dictionary(dictionary, filename);

    char word[MAX_WORD_LENGTH + 1];
    int size = sizeof(dictionary) / sizeof(DictionaryEntry);

    printf("Enter words to check (type 'quit' to exit):\n");

    while (1) {
        scanf("%s", word);
        if (strcmp(word, "quit") == 0) {
            break;
        }

        int is_valid = is_valid_word(word, dictionary, size);

        if (is_valid) {
            printf("%s is a valid word.\n", word);
        } else {
            printf("%s is not a valid word.\n", word);
        }
    }

    return 0;
}
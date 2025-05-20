//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORD_LENGTH 100
#define MAX_DICTIONARY_SIZE 1000

struct Dictionary {
    char word[MAX_WORD_LENGTH];
    int frequency;
};

int loadDictionary(struct Dictionary *dictionary, int size) {
    FILE *file = fopen("dictionary.txt", "r");
    if (file == NULL) {
        printf("Error: Could not open dictionary file.\n");
        return 0;
    }

    int count = 0;
    while (fscanf(file, "%s %d", dictionary[count].word, &dictionary[count].frequency)!= EOF) {
        count++;
        if (count >= size) {
            printf("Warning: Dictionary is too large for the program.\n");
            break;
        }
    }

    fclose(file);
    return count;
}

int compareWords(char *word1, char *word2) {
    int len1 = strlen(word1);
    int len2 = strlen(word2);
    int min_len = (len1 < len2)? len1 : len2;

    for (int i = 0; i < min_len; i++) {
        if (tolower(word1[i])!= tolower(word2[i])) {
            return 0;
        }
    }

    return 1;
}

void printSuggestions(struct Dictionary *dictionary, int size, char *word) {
    char suggestions[MAX_WORD_LENGTH];
    int count = 0;

    for (int i = 0; i < size; i++) {
        if (compareWords(dictionary[i].word, word)) {
            strcpy(suggestions[count++], dictionary[i].word);
        }
    }

    if (count == 0) {
        printf("No suggestions found.\n");
    } else {
        printf("Did you mean:\n");
        for (int i = 0; i < count; i++) {
            printf("%s\n", suggestions[i]);
        }
    }
}

int main() {
    struct Dictionary dictionary[MAX_DICTIONARY_SIZE];
    int size = loadDictionary(dictionary, MAX_DICTIONARY_SIZE);

    char word[MAX_WORD_LENGTH];
    printf("Enter a word to check:\n");
    scanf("%s", word);

    if (size == 0) {
        printf("Error: Dictionary is empty.\n");
        return 1;
    }

    int found = 0;
    for (int i = 0; i < size; i++) {
        if (compareWords(dictionary[i].word, word)) {
            found = 1;
            break;
        }
    }

    if (found) {
        printf("'%s' is spelled correctly.\n", word);
    } else {
        printSuggestions(dictionary, size, word);
    }

    return 0;
}
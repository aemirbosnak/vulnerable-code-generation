//MISTRAL-7B DATASET v1.0 Category: String manipulation ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 10000
#define WORD_LENGTH 50

typedef struct Word {
    char str[WORD_LENGTH];
    struct Word *next;
} Word;

Word *dictionary = NULL;
Word *anagrams = NULL;

int compare(const void *a, const void *b) {
    return strcmp(((Word *)a)->str, ((Word *)b)->str);
}

void read_dictionary(const char *filename) {
    FILE *file = fopen(filename, "r");

    if (!file) {
        printf("Error: Could not open file %s\n", filename);
        exit(EXIT_FAILURE);
    }

    Word *current = NULL;
    char word[WORD_LENGTH];

    while (fscanf(file, "%s", word) != EOF) {
        Word *new_word = (Word *)malloc(sizeof(Word));

        strcpy(new_word->str, word);
        new_word->next = current;
        current = new_word;

        dictionary = current;
    }

    fclose(file);
}

void find_anagrams(const char *word) {
    int word_length = strlen(word);
    qsort(dictionary, 1 + (dictionary ? strlen(dictionary->str) / WORD_LENGTH : 0),
          sizeof(Word), compare);

    Word *current = dictionary;

    while (current) {
        if (strspn(word, current->str) == strlen(word)) {
            Word *anagram = (Word *)malloc(sizeof(Word));
            strcpy(anagram->str, word);
            anagram->next = anagrams;
            anagrams = anagram;
        }

        current = current->next;
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <dictionary_file>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    read_dictionary(argv[1]);

    char word[WORD_LENGTH];
    printf("Enter words to find anagrams, type 'exit' to quit:\n");

    while (1) {
        fgets(word, WORD_LENGTH, stdin);
        word[strlen(word) - 1] = '\0'; // Remove newline character

        if (strcmp(word, "exit") == 0) {
            break;
        }

        find_anagrams(word);
        printf("Anagrams for %s:\n", word);

        if (!anagrams) {
            printf("None found.\n");
        } else {
            Word *current = anagrams;

            while (current) {
                printf("%s ", current->str);
                current = current->next;
            }

            printf("\n");
        }

        anagrams = NULL;
    }

    Word *current = dictionary;

    while (current) {
        Word *next = current->next;
        free(current);
        current = next;
    }

    return 0;
}
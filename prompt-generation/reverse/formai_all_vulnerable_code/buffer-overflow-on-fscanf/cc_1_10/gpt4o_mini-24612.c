//GPT-4o-mini DATASET v1.0 Category: Spell checking ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100
#define MAX_DICTIONARY_SIZE 10000

// Function declarations
void to_lowercase(char *str);
int load_dictionary(const char *filename, char dictionary[][MAX_WORD_LENGTH]);
int check_spelling(const char *text_filename, char dictionary[][MAX_WORD_LENGTH], int dict_size);
void report_misspelled_words(const char *text_filename, char dictionary[][MAX_WORD_LENGTH], int dict_size);

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <dictionary_file> <text_file>\n", argv[0]);
        return 1;
    }

    char dictionary[MAX_DICTIONARY_SIZE][MAX_WORD_LENGTH];
    int dict_size = load_dictionary(argv[1], dictionary);

    if (dict_size < 0) {
        printf("Failed to load dictionary.\n");
        return 1;
    }

    report_misspelled_words(argv[2], dictionary, dict_size);
    return 0;
}

void to_lowercase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower((unsigned char)str[i]);
    }
}

int load_dictionary(const char *filename, char dictionary[][MAX_WORD_LENGTH]) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening dictionary file");
        return -1;
    }

    int count = 0;
    while (count < MAX_DICTIONARY_SIZE && fscanf(file, "%s", dictionary[count]) == 1) {
        to_lowercase(dictionary[count]);
        count++;
    }
    
    fclose(file);
    return count;
}

int check_spelling(const char *word, char dictionary[][MAX_WORD_LENGTH], int dict_size) {
    for (int i = 0; i < dict_size; i++) {
        if (strcmp(word, dictionary[i]) == 0) {
            return 1; // Found in dictionary
        }
    }
    return 0; // Not found
}

void report_misspelled_words(const char *text_filename, char dictionary[][MAX_WORD_LENGTH], int dict_size) {
    FILE *file = fopen(text_filename, "r");
    if (file == NULL) {
        perror("Error opening text file");
        return;
    }

    char word[MAX_WORD_LENGTH];
    int misspelled_count = 0;
    
    printf("Misspelled words:\n");
    while (fscanf(file, "%s", word) == 1) {
        to_lowercase(word);
        if (!check_spelling(word, dictionary, dict_size)) {
            printf("%s\n", word);
            misspelled_count++;
        }
    }
    
    fclose(file);
    printf("Total misspelled words: %d\n", misspelled_count);
}
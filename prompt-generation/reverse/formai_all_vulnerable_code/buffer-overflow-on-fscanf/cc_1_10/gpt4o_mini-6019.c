//GPT-4o-mini DATASET v1.0 Category: Spell checking ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 100
#define DICTIONARY_SIZE 10000

void load_dictionary(const char *filename, char dictionary[][MAX_WORD_LENGTH], int *size) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Could not open dictionary file");
        exit(EXIT_FAILURE);
    }
    
    *size = 0;
    while (fscanf(file, "%s", dictionary[*size]) != EOF && *size < DICTIONARY_SIZE) {
        (*size)++;
    }
    fclose(file);
}

int binary_search(char dictionary[][MAX_WORD_LENGTH], int size, const char *word) {
    int low = 0, high = size - 1;
    
    while (low <= high) {
        int mid = (low + high) / 2;
        int cmp = strcmp(dictionary[mid], word);
        if (cmp == 0) return 1; // Word found
        else if (cmp < 0) low = mid + 1;
        else high = mid - 1;
    }
    return 0; // Word not found
}

void check_spelling(const char *text, char dictionary[][MAX_WORD_LENGTH], int dict_size) {
    char word[MAX_WORD_LENGTH];
    const char *ptr = text;
    
    while (*ptr) {
        char *word_ptr = word;
        while (*ptr && (isalpha((unsigned char)*ptr) || *ptr == '\'' || *ptr == '-')) {
            *word_ptr++ = *ptr++;
        }
        *word_ptr = '\0';
        
        if (strlen(word) > 0 && !binary_search(dictionary, dict_size, word)) {
            printf("Misspelled: %s\n", word);
        }
        
        while (*ptr && !isalpha((unsigned char)*ptr)) {
            ptr++;
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <dictionary_file> <text_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    char dictionary[DICTIONARY_SIZE][MAX_WORD_LENGTH];
    int dict_size;

    load_dictionary(argv[1], dictionary, &dict_size);
    
    FILE *text_file = fopen(argv[2], "r");
    if (!text_file) {
        perror("Could not open text file");
        return EXIT_FAILURE;
    }
    
    char *text = NULL;
    size_t len = 0, read;
    while ((read = getline(&text, &len, text_file)) != -1) {
        check_spelling(text, dictionary, dict_size);
    }

    free(text);
    fclose(text_file);
    
    return EXIT_SUCCESS;
}
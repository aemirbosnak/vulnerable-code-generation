//FormAI DATASET v1.0 Category: Spell checking ; Style: beginner-friendly
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_SIZE 30
#define MAX_FILE_NAME 100

int get_word(char word[], int limit);
void to_lower_case(char word[]);
int is_word(char word[]);
int is_in_dictionary(char word[], char dictionary[][MAX_WORD_SIZE], int dictionary_size);

int main() {
    char file_name[MAX_FILE_NAME];
    char word[MAX_WORD_SIZE];
    char dictionary[50000][MAX_WORD_SIZE];
    int dictionary_size = 0;
    
    printf("Enter the name of the dictionary file: ");
    scanf("%s", file_name);
    
    // Read dictionary file and store words
    FILE *dictionary_file = fopen(file_name, "r");
    if (dictionary_file == NULL) {
        printf("File not found!\n");
        return 1;
    }
    while (fscanf(dictionary_file, "%s", dictionary[dictionary_size]) == 1) {
        to_lower_case(dictionary[dictionary_size]);
        dictionary_size++;
    }
    fclose(dictionary_file);
    printf("Dictionary loaded successfully.\n");
    
    // Ask user for file to spell check
    printf("Enter the name of the file to be checked: ");
    scanf("%s", file_name);
    
    // Read file and spell check words
    FILE *file = fopen(file_name, "r");
    if (file == NULL) {
        printf("File not found!\n");
        return 1;
    }
    printf("Misspelled words:\n");
    while (get_word(word, MAX_WORD_SIZE) != EOF) {
        to_lower_case(word);
        if (is_word(word) && !is_in_dictionary(word, dictionary, dictionary_size)) {
            printf("%s\n", word);
        }
    }
    fclose(file);
    return 0;
}

int get_word(char word[], int limit) {
    int c;
    int i = 0;
    while ((c = getchar()) != EOF && !isalpha(c)) {
        // discard non-word characters
    }
    if (c == EOF) {
        return EOF;
    }
    word[i++] = c;
    while (i < limit && (c = getchar()) != EOF && isalpha(c)) {
        word[i++] = c;
    }
    word[i] = '\0';
    return word[0];
}

void to_lower_case(char word[]) {
    int i = 0;
    while (word[i]) {
        word[i] = tolower(word[i]);
        i++;
    }
}

int is_word(char word[]) {
    int i = 0;
    while (word[i]) {
        if (!isalpha(word[i])) {
            return 0;
        }
        i++;
    }
    return 1;
}

int is_in_dictionary(char word[], char dictionary[][MAX_WORD_SIZE], int dictionary_size) {
    int i;
    for (i = 0; i < dictionary_size; i++) {
        if (strcmp(word, dictionary[i]) == 0) {
            return 1;
        }
    }
    return 0;
}
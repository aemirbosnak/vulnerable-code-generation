//FormAI DATASET v1.0 Category: Spell checking ; Style: accurate
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LEN 100
#define MAX_DICT_SIZE 50000

// Define a function to load the dictionary
void load_dict(char *dict_path, char dictionary[][MAX_WORD_LEN]) {
    FILE *fptr;
    char word[MAX_WORD_LEN];
    int i = 0;
    
    fptr = fopen(dict_path, "r");
    if (fptr == NULL) {
        printf("Error: Cannot open the dictionary\n");
        exit(-1);
    }
    
    while (fgets(word, MAX_WORD_LEN, fptr)) {
        // Remove newline character
        word[strcspn(word, "\n")] = 0;
        strcpy(dictionary[i++], word);
    }
    
    fclose(fptr);
}

// Define a function to perform spell checking on a piece of text
void spell_check(char *text_path, char dictionary[][MAX_WORD_LEN]) {
    FILE *fptr;
    char word[MAX_WORD_LEN];
    int i, found, line_no = 0;
    
    fptr = fopen(text_path, "r");
    if (fptr == NULL) {
        printf("Error: Cannot open the text file\n");
        exit(-1);
    }
    
    while (fgets(word, MAX_WORD_LEN, fptr)) {
        line_no++;
        int len = strlen(word);
        if (len > 0 && word[len-1] == '\n') {
            word[len-1] = '\0';
        }
        // Convert to lower case
        for (i = 0; word[i]; i++) {
            word[i] = tolower(word[i]);
        }
        found = 0;
        // Check if the word is in the dictionary
        for (i = 0; i < MAX_DICT_SIZE; i++) {
            if (strlen(dictionary[i]) == 0) {
                break;
            }
            if (strcmp(word, dictionary[i]) == 0) {
                found = 1;
                break;
            }
        }
        if (!found) {
            printf("Line %d, word %s: Possible spelling mistake\n", line_no, word);
        }
    }
    fclose(fptr);
}

int main() {
    char dict_path[MAX_WORD_LEN], text_path[MAX_WORD_LEN];
    char dictionary[MAX_DICT_SIZE][MAX_WORD_LEN];
    
    // Get the path of the dictionary
    printf("Enter the path to dictionary: ");
    scanf("%s", dict_path);
    
    // Load the dictionary
    load_dict(dict_path, dictionary);
    
    // Get the path of the text file to spell check
    printf("Enter the path to text file to spell check: ");
    scanf("%s", text_path);
    
    // Perform spell checking
    spell_check(text_path, dictionary);
    
    return 0;
}
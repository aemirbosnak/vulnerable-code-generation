//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100

// Function to check if a word is in the dictionary
int is_in_dictionary(char* word) {
    FILE* dictionary = fopen("dictionary.txt", "r");
    if (dictionary == NULL) {
        fprintf(stderr, "Error: could not open dictionary file.\n");
        return 1;
    }

    char line[MAX_WORD_LENGTH];
    while (fgets(line, sizeof(line), dictionary)!= NULL) {
        int len = strlen(line);
        if (line[len-1] == '\n') {
            line[len-1] = '\0';
        }
        if (strcmp(line, word) == 0) {
            fclose(dictionary);
            return 0;
        }
    }

    fclose(dictionary);
    return 1;
}

int main() {
    char input[MAX_WORD_LENGTH];
    printf("Enter a word to check: ");
    fgets(input, sizeof(input), stdin);
    int len = strlen(input);
    if (len > 0 && input[len-1] == '\n') {
        input[len-1] = '\0';
    }

    // Convert input to lowercase for case-insensitive comparison
    for (int i = 0; i < len; i++) {
        input[i] = tolower(input[i]);
    }

    int is_correct = is_in_dictionary(input);
    if (is_correct) {
        printf("'%s' is spelled correctly.\n", input);
    } else {
        printf("'%s' is spelled incorrectly.\n", input);
    }

    return 0;
}
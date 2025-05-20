//FormAI DATASET v1.0 Category: Spell checking ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(void) {
    // Input file
    char filename[256];
    printf("Enter the name of the file: ");
    fgets(filename, 256, stdin);
    filename[strlen(filename)-1] = '\0';
    FILE *input = fopen(filename, "r");

    // Dictionary file
    FILE *dictionary = fopen("dictionary.txt", "r");
    if (dictionary == NULL) {
        printf("Error: Could not open dictionary file.\n");
        return 1;
    }

    // Read dictionary into array
    char words[500000][50];
    int num_words = 0;
    char dict_line[256];
    while (fgets(dict_line, 256, dictionary)) {
        dict_line[strlen(dict_line)-1] = '\0';
        strcpy(words[num_words], dict_line);
        num_words++;
    }

    // Spell check input file
    char line[256];
    int line_num = 0;
    while (fgets(line, 256, input)) {
        line_num++;
        char *word = strtok(line, " \t\n\r\f.,;:!?'\"()[]{}+-*=/");
        while (word != NULL) {
            // Convert word to lowercase
            for (int i = 0; word[i]; i++) {
                word[i] = tolower(word[i]);
            }

            // Check if word is in dictionary
            int found = 0;
            for (int i = 0; i < num_words; i++) {
                if (strcmp(word, words[i]) == 0) {
                    found = 1;
                    break;
                }
            }

            // Print error message if word is not found
            if (!found) {
                printf("Error: '%s' not found in dictionary. Line: %d\n", word, line_num);
            }

            // Get next word
            word = strtok(NULL, " \t\n\r\f.,;:!?'\"()[]{}+-*=/");
        }
    }

    // Close files
    fclose(input);
    fclose(dictionary);
    return 0;
}
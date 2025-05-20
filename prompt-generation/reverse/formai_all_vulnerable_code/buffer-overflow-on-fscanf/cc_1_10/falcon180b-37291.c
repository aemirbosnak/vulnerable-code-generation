//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

// Function to check if a word is in the dictionary
bool is_word(const char *word) {
    FILE *dict = fopen("dictionary.txt", "r");
    char dict_word[100];
    while (fscanf(dict, "%s", dict_word)!= EOF) {
        if (strcmp(word, dict_word) == 0) {
            fclose(dict);
            return true;
        }
    }
    fclose(dict);
    return false;
}

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }
    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error: File not found\n");
        return 1;
    }

    // Read file line by line
    char line[100];
    while (fgets(line, 100, file)!= NULL) {
        // Remove newline character from end of line
        line[strcspn(line, "\n")] = '\0';

        // Check if line is a word
        int i = 0;
        while (line[i]!= '\0' && isalpha(line[i])) {
            i++;
        }
        if (i > 0) {
            char word[100] = {0};
            strncpy(word, line, i);

            // Check if word is in dictionary
            if (!is_word(word)) {
                printf("Possible spelling error: %s\n", word);
            }
        }
    }
    fclose(file);
    return 0;
}
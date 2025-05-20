//Falcon-180B DATASET v1.0 Category: Text processing ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1000

// Function to remove leading/trailing whitespace from a string
void trim(char *str) {
    char *end;

    // Trim leading whitespace
    while (isspace(*str)) {
        str++;
    }

    // Trim trailing whitespace
    end = str + strlen(str) - 1;
    while (end > str && isspace(*end)) {
        end--;
        *end = '\0';
    }
}

int main() {
    FILE *input_file, *output_file;
    char line[MAX_LINE_LENGTH];
    char *word;
    size_t len = 0;
    ssize_t read;

    // Open input file
    input_file = fopen("input.txt", "r");
    if (input_file == NULL) {
        printf("Error opening input file.\n");
        return 1;
    }

    // Open output file
    output_file = fopen("output.txt", "w");
    if (output_file == NULL) {
        printf("Error opening output file.\n");
        fclose(input_file);
        return 1;
    }

    // Read input file line by line
    while ((read = getline(&line, &len, input_file))!= -1) {
        // Remove leading/trailing whitespace from line
        trim(line);

        // Split line into words
        word = strtok(line, " ");
        while (word!= NULL) {
            // Reverse each word
            char reversed_word[MAX_LINE_LENGTH];
            int i, j;
            for (i = strlen(word) - 1, j = 0; i >= 0; i--, j++) {
                reversed_word[j] = tolower(word[i]);
            }
            reversed_word[j] = '\0';

            // Write reversed word to output file
            fprintf(output_file, "%s ", reversed_word);

            // Get next word
            word = strtok(NULL, " ");
        }

        // Write newline character to output file
        fprintf(output_file, "\n");
    }

    // Close files
    fclose(input_file);
    fclose(output_file);

    return 0;
}
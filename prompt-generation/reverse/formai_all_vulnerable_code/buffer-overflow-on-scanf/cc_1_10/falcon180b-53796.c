//Falcon-180B DATASET v1.0 Category: Word Count Tool ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100

int main() {
    FILE *file;
    char filename[MAX_WORD_LENGTH];
    char word[MAX_WORD_LENGTH];
    int word_count = 0;
    int letter_count = 0;
    int sentence_count = 0;
    int paragraph_count = 0;

    // Prompt user for filename
    printf("Enter filename: ");
    scanf("%s", filename);

    // Open file for reading
    file = fopen(filename, "r");

    // Check if file was successfully opened
    if (file == NULL) {
        printf("Error: File not found.\n");
        exit(1);
    }

    // Read file line by line
    char line[MAX_WORD_LENGTH];
    while (fgets(line, MAX_WORD_LENGTH, file)!= NULL) {
        // Remove newline character from end of line
        line[strcspn(line, "\n")] = '\0';

        // Count words in line
        char *token = strtok(line, " \t\n\r\f\v.,;:!?()[]{}<>");
        while (token!= NULL) {
            word_count++;

            // Count letters in word
            int i;
            for (i = 0; i < strlen(token); i++) {
                if (isalpha(token[i])) {
                    letter_count++;
                }
            }

            // Count sentences in line
            if (token[strlen(token) - 1] == '.' ||
                token[strlen(token) - 1] == '!' ||
                token[strlen(token) - 1] == '?') {
                sentence_count++;
            }

            // Count paragraphs in line
            if (line[0] == '\n') {
                paragraph_count++;
            }

            token = strtok(NULL, " \t\n\r\f\v.,;:!?()[]{}<>");
        }
    }

    // Close file
    fclose(file);

    // Print results
    printf("Word count: %d\n", word_count);
    printf("Letter count: %d\n", letter_count);
    printf("Sentence count: %d\n", sentence_count);
    printf("Paragraph count: %d\n", paragraph_count);

    return 0;
}
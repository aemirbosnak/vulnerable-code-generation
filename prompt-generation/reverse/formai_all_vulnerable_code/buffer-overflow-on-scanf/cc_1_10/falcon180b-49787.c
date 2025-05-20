//Falcon-180B DATASET v1.0 Category: Word Count Tool ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1000
#define MAX_WORD_LENGTH 100

int main() {
    FILE *file;
    char filename[MAX_LINE_LENGTH];
    char line[MAX_LINE_LENGTH];
    char word[MAX_WORD_LENGTH];
    int line_count = 0;
    int word_count = 0;

    // Get filename from user input
    printf("Enter filename: ");
    scanf("%s", filename);

    // Open file for reading
    file = fopen(filename, "r");

    // Check if file was successfully opened
    if (file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    // Loop through file and count lines and words
    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        line_count++;

        // Remove newline character from end of line
        line[strcspn(line, "\n")] = '\0';

        // Loop through each word in line
        char *word_ptr = strtok(line, " \t\n\r\f\v");
        while (word_ptr!= NULL) {
            strcpy(word, word_ptr);
            word_ptr = strtok(NULL, " \t\n\r\f\v");

            // Check if word is empty or contains only special characters
            if (strspn(word, " \t\n\r\f\v")!= strlen(word)) {
                word_count++;
            }
        }
    }

    // Close file
    fclose(file);

    // Print results
    printf("Total lines: %d\n", line_count);
    printf("Total words: %d\n", word_count);

    return 0;
}
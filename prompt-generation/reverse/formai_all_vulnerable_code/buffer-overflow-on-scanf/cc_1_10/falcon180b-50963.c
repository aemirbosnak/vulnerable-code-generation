//Falcon-180B DATASET v1.0 Category: Word Count Tool ; Style: beginner-friendly
#include <stdio.h>
#include <string.h>

#define MAX_WORD_LENGTH 100

int main() {
    FILE* file;
    char filename[MAX_WORD_LENGTH];
    char line[MAX_WORD_LENGTH];
    char word[MAX_WORD_LENGTH];
    int word_count = 0;
    int char_count = 0;
    int line_count = 0;

    // Get filename from user
    printf("Enter filename: ");
    scanf("%s", filename);

    // Open file for reading
    file = fopen(filename, "r");

    // Check if file is opened successfully
    if (file == NULL) {
        printf("Error: File not found.\n");
        return 0;
    }

    // Read file line by line
    while (fgets(line, MAX_WORD_LENGTH, file)!= NULL) {
        line_count++;

        // Remove newline character from end of line
        line[strcspn(line, "\n")] = '\0';

        // Count number of characters in line
        char_count += strlen(line);

        // Count number of words in line
        int word_index = 0;
        char* token = strtok(line, " ");
        while (token!= NULL) {
            strcpy(word, token);
            word_count++;
            token = strtok(NULL, " ");
        }
    }

    // Close file
    fclose(file);

    // Print results
    printf("Number of lines: %d\n", line_count);
    printf("Number of words: %d\n", word_count);
    printf("Number of characters: %d\n", char_count);

    return 0;
}
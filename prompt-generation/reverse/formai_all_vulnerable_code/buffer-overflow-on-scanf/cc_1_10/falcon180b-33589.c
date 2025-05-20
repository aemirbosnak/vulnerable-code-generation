//Falcon-180B DATASET v1.0 Category: Word Count Tool ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_WORD_LENGTH 100
#define MAX_LINE_LENGTH 1000

// Function to count words in a line
int count_words(char* line) {
    int count = 0;
    bool in_word = false;
    for (int i = 0; i < strlen(line); i++) {
        if (isspace(line[i])) {
            if (in_word) {
                count++;
                in_word = false;
            }
        } else {
            in_word = true;
        }
    }
    if (in_word) {
        count++;
    }
    return count;
}

// Function to count lines in a file
int count_lines(FILE* file) {
    int count = 0;
    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, file)) {
        count++;
    }
    return count;
}

// Function to count words in a file
int count_words_in_file(FILE* file) {
    int count = 0;
    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, file)) {
        count += count_words(line);
    }
    return count;
}

int main() {
    FILE* file;
    char filename[MAX_LINE_LENGTH];

    // Get filename from user
    printf("Enter filename: ");
    scanf("%s", filename);

    // Open file
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    // Count lines and words in file
    int num_lines = count_lines(file);
    int num_words = count_words_in_file(file);

    // Print results
    printf("Number of lines: %d\n", num_lines);
    printf("Number of words: %d\n", num_words);

    // Close file
    fclose(file);

    return 0;
}
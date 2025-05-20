//Falcon-180B DATASET v1.0 Category: Word Count Tool ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORD_LENGTH 100
#define MAX_LINE_LENGTH 1000

// Function to count the number of words in a string
int count_words(char* str) {
    int count = 0;
    char* word;
    char* token = strtok(str, " ");
    while (token!= NULL) {
        count++;
        word = token;
        while (isalnum(*word)) {
            word++;
        }
        while (!isalnum(*word)) {
            word++;
        }
        token = strtok(NULL, " ");
    }
    return count;
}

// Function to count the number of lines in a file
int count_lines(FILE* file) {
    int count = 0;
    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        count++;
    }
    return count;
}

// Function to count the number of words in a file
int count_file_words(FILE* file) {
    int count = 0;
    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        count += count_words(line);
    }
    return count;
}

int main() {
    FILE* file;
    char filename[MAX_LINE_LENGTH];
    printf("Enter the filename: ");
    scanf("%s", filename);

    // Open the file
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    // Count the number of lines and words in the file
    int line_count = count_lines(file);
    int word_count = count_file_words(file);

    // Close the file
    fclose(file);

    // Print the results
    printf("The file '%s' contains:\n", filename);
    printf(" - %d lines\n", line_count);
    printf(" - %d words\n", word_count);

    return 0;
}
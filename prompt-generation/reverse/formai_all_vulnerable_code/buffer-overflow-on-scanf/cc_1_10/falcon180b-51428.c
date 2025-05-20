//Falcon-180B DATASET v1.0 Category: Word Count Tool ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100
#define MAX_LINE_LENGTH 1000

// Function to count the number of words in a line
int count_words(char* line) {
    int count = 0;
    char* word = strtok(line, " ");
    while (word!= NULL) {
        count++;
        word = strtok(NULL, " ");
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

// Function to count the number of characters in a line
int count_chars(char* line) {
    int count = 0;
    while (*line!= '\0') {
        count++;
        line++;
    }
    return count;
}

// Function to count the number of vowels in a line
int count_vowels(char* line) {
    int count = 0;
    while (*line!= '\0') {
        if (isalpha(*line) && (*line == 'a' || *line == 'e' || *line == 'i' || *line == 'o' || *line == 'u' || *line == 'A' || *line == 'E' || *line == 'I' || *line == 'O' || *line == 'U')) {
            count++;
        }
        line++;
    }
    return count;
}

int main() {
    FILE* file;
    char filename[MAX_LINE_LENGTH];
    char line[MAX_LINE_LENGTH];
    int line_count = 0;
    int word_count = 0;
    int char_count = 0;
    int vowel_count = 0;

    // Get the filename from the user
    printf("Enter the filename: ");
    scanf("%s", filename);

    // Open the file for reading
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: could not open file.\n");
        return 1;
    }

    // Read the file line by line and count the words, characters, and vowels
    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        line_count++;
        word_count += count_words(line);
        char_count += count_chars(line);
        vowel_count += count_vowels(line);
    }

    // Print the results
    printf("\nFile: %s\n", filename);
    printf("Lines: %d\n", line_count);
    printf("Words: %d\n", word_count);
    printf("Characters: %d\n", char_count);
    printf("Vowels: %d\n", vowel_count);

    // Close the file
    fclose(file);

    return 0;
}
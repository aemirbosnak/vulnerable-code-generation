//FormAI DATASET v1.0 Category: Text processing ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 50 // Maximum length of a word in the text file
#define MAX_LINE_LENGTH 500 // Maximum length of a single line in the text file
#define MAX_FILENAME_LENGTH 100 // Maximum length of the input and output file names

void count_words(char* filename);
void capitalize_text(char* input_filename, char* output_filename);

int main(void) {

    // Example usage of count_words() function
    count_words("example.txt");

    // Example usage of capitalize_text() function
    capitalize_text("input.txt", "output.txt");

    return 0;
}

void count_words(char* filename) {

    FILE* fp = fopen(filename, "r"); // Open file for reading

    if (fp == NULL) {
        printf("Error: Input file not found!\n");
        return;
    }

    int word_count = 0; // Count of total words

    // Loop through each word
    while (!feof(fp)) {
        char word[MAX_WORD_LENGTH] = { 0 };
        fscanf(fp, "%s", word); // Read a word from file

        if (word[0] != '\0') { // Ignore empty words
            word_count++;
        }
    }

    fclose(fp); // Close file

    printf("Total number of words in file: %d\n", word_count);
}

void capitalize_text(char* input_filename, char* output_filename) {

    FILE* input_fp = fopen(input_filename, "r"); // Open input file for reading

    if (input_fp == NULL) {
        printf("Error: Input file not found!\n");
        return;
    }

    FILE* output_fp = fopen(output_filename, "w"); // Open output file for writing

    char line[MAX_LINE_LENGTH] = { 0 };

    // Loop through each line in the file
    while (fgets(line, MAX_LINE_LENGTH, input_fp) != NULL) {

        int line_length = strlen(line);

        // Convert first character of each word to uppercase
        for (int i = 0; i < line_length; i++) {
            if (i == 0 || line[i - 1] == ' ') {
                line[i] = toupper(line[i]);
            }
        }

        fputs(line, output_fp); // Write line to output file

    }

    fclose(input_fp); // Close input file
    fclose(output_fp); // Close output file

    printf("Capitalized text has been saved to %s.\n", output_filename);
}
//Code Llama-13B DATASET v1.0 Category: Text Summarizer ; Style: configurable
/*
 * C Text Summarizer Example Program
 *
 * This program takes a text file as input and summarizes it into a summary file.
 * The summary file will contain the most important sentences from the original text.
 *
 * Usage: ./summarizer <input_file> <output_file>
 *
 * Example: ./summarizer input.txt output.txt
 *
 * Author: Your Name
 * Date: Current Date
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_SUMMARY_LENGTH 1024

// Function to read a line from a file and store it in a buffer
int read_line(FILE *fp, char *buffer, int max_length) {
    // Read a line from the file
    fgets(buffer, max_length, fp);

    // Remove newline character from the end of the line
    buffer[strcspn(buffer, "\n")] = '\0';

    // Return the length of the line
    return strlen(buffer);
}

// Function to write a line to a file
int write_line(FILE *fp, char *buffer) {
    // Write the line to the file
    fputs(buffer, fp);

    // Return the length of the line
    return strlen(buffer);
}

// Function to summarize a text file
void summarize_text(char *input_file, char *output_file) {
    // Open the input file
    FILE *input = fopen(input_file, "r");
    if (input == NULL) {
        printf("Error opening input file: %s\n", input_file);
        return;
    }

    // Open the output file
    FILE *output = fopen(output_file, "w");
    if (output == NULL) {
        printf("Error opening output file: %s\n", output_file);
        return;
    }

    // Read the first line of the input file
    char line[MAX_LINE_LENGTH];
    int line_length = read_line(input, line, MAX_LINE_LENGTH);

    // Initialize the summary
    char summary[MAX_SUMMARY_LENGTH] = "";
    int summary_length = 0;

    // Iterate over the lines of the input file
    while (line_length > 0) {
        // Check if the line is a sentence
        if (line[line_length - 1] == '.' || line[line_length - 1] == '?') {
            // Add the line to the summary
            strcat(summary, line);
            summary_length += line_length;

            // Check if the summary is too long
            if (summary_length > MAX_SUMMARY_LENGTH) {
                // Remove the last sentence from the summary
                summary[summary_length - 1] = '\0';
                summary_length -= line_length;
            }
        }

        // Read the next line of the input file
        line_length = read_line(input, line, MAX_LINE_LENGTH);
    }

    // Write the summary to the output file
    write_line(output, summary);

    // Close the input and output files
    fclose(input);
    fclose(output);
}

int main(int argc, char *argv[]) {
    // Check the number of arguments
    if (argc != 3) {
        printf("Usage: ./summarizer <input_file> <output_file>\n");
        return 1;
    }

    // Summarize the text
    summarize_text(argv[1], argv[2]);

    return 0;
}
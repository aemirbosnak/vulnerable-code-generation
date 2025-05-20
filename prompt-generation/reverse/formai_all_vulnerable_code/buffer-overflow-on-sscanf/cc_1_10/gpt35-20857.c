//FormAI DATASET v1.0 Category: File handling ; Style: Linus Torvalds
/* 
 * File:   main.c
 * Author: Linus Torvalds
 * Description: This program takes an input file, calculates the average value of
 *              the integers contained in the file, and writes the result to an output file. 
 */

#include <stdio.h>
#include <stdlib.h>

#define MAX_CHARS_PER_LINE 100

int main(int argc, char** argv) {
    FILE *input_file_ptr, *output_file_ptr;
    char input_filename[MAX_CHARS_PER_LINE],
         output_filename[MAX_CHARS_PER_LINE],
         line[MAX_CHARS_PER_LINE];
    int line_sum = 0, num_of_lines = 0, num;
    float average;

    printf("Enter input filename: ");
    fgets(input_filename, MAX_CHARS_PER_LINE, stdin);
    input_filename[strcspn(input_filename, "\n")] = '\0'; // Remove trailing newline character

    input_file_ptr = fopen(input_filename, "r");
    if (input_file_ptr == NULL) {
        printf("Error: Could not open input file.\n");
        exit(EXIT_FAILURE);
    }

    printf("Enter output filename: ");
    fgets(output_filename, MAX_CHARS_PER_LINE, stdin);
    output_filename[strcspn(output_filename, "\n")] = '\0'; // Remove trailing newline character

    output_file_ptr = fopen(output_filename, "w");
    if (output_file_ptr == NULL) {
        printf("Error: Could not open output file.\n");
        exit(EXIT_FAILURE);
    }

    while (fgets(line, MAX_CHARS_PER_LINE, input_file_ptr) != NULL) {
        if (sscanf(line, "%d", &num) == 1) {
            line_sum += num;
            num_of_lines++;
        }
    }

    if (num_of_lines == 0) {
        fprintf(output_file_ptr, "Error: Input file contains no integers.\n");
    } else {
        average = (float) line_sum / num_of_lines;
        fprintf(output_file_ptr, "Average = %f", average);
    }

    fclose(input_file_ptr);
    fclose(output_file_ptr);

    return 0;
}
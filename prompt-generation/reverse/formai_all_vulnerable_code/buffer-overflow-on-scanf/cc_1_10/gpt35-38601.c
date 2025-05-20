//FormAI DATASET v1.0 Category: Text processing ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 100

int main() {
    FILE *input_file;
    char input_filename[100];
    char output_filename[100];
    char line[MAX_LINE_LENGTH];
    char *token;
    int word_count = 0;
    int line_count = 0;
    int char_count = 0;
    
    printf("Enter name of input file: ");
    scanf("%s", input_filename);
    
    // Open input file
    input_file = fopen(input_filename, "r");
    if (input_file == NULL) {
        printf("Error opening file.\n");
        return 0;
    }
    
    printf("Enter name of output file: ");
    scanf("%s", output_filename);
    
    // Open output file
    FILE *output_file = fopen(output_filename, "w");
    if (output_file == NULL) {
        printf("Error opening file.\n");
        return 0;
    }
    
    // Read input file line by line
    while (fgets(line, MAX_LINE_LENGTH, input_file) != NULL) {
        line_count++;
        char_count += strlen(line);
        
        // Tokenize line to count words
        token = strtok(line, " \n");
        while (token != NULL) {
            word_count++;
            token = strtok(NULL, " \n");
        }
        
        // Write line to output file in reverse order
        for (int i = strlen(line) - 1; i >= 0; i--) {
            fputc(line[i], output_file);
        }
        fputc('\n', output_file);
    }
    
    // Close files and print summary
    fclose(input_file);
    fclose(output_file);
    printf("Processed %d lines, %d words, and %d characters. Reversed output saved to %s.\n", line_count, word_count, char_count, output_filename);
    
    return 0;
}
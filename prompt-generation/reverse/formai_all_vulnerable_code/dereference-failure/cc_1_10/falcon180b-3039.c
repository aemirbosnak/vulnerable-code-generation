//Falcon-180B DATASET v1.0 Category: Error handling ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000

// function to print the error message and exit the program
void error(const char* message) {
    fprintf(stderr, "Error: %s\n", message);
    exit(1);
}

// function to read a line from the file and return it as a string
char* read_line(FILE* file) {
    char line[MAX_LINE_LENGTH];
    char* result = NULL;
    if (fgets(line, MAX_LINE_LENGTH, file) == NULL) {
        error("Failed to read line from file");
    }
    result = strdup(line);
    return result;
}

// function to write a string to a file
void write_to_file(const char* filename, const char* string) {
    FILE* file = fopen(filename, "a");
    if (file == NULL) {
        error("Failed to open file for writing");
    }
    fprintf(file, "%s", string);
    fclose(file);
}

// function to count the number of words in a string
int count_words(const char* string) {
    int count = 0;
    const char* delimiters = " \t\r\n";
    char* token = strtok(string, delimiters);
    while (token!= NULL) {
        count++;
        token = strtok(NULL, delimiters);
    }
    return count;
}

int main(int argc, char** argv) {
    if (argc!= 3) {
        error("Invalid number of arguments");
    }
    const char* input_filename = argv[1];
    const char* output_filename = argv[2];

    // open the input file and read its contents
    FILE* input_file = fopen(input_filename, "r");
    if (input_file == NULL) {
        error("Failed to open input file");
    }
    char* input_contents = NULL;
    int input_length = 0;
    while ((input_length = fread(input_contents, 1, MAX_LINE_LENGTH, input_file)) > 0) {
        input_contents = realloc(input_contents, input_length + 1);
        input_contents[input_length] = '\0';
    }
    fclose(input_file);

    // count the number of words in the input file
    int word_count = count_words(input_contents);

    // write the word count to the output file
    char output_string[50];
    snprintf(output_string, sizeof(output_string), "Word count: %d\n", word_count);
    write_to_file(output_filename, output_string);

    // free the memory used by the input file contents
    free(input_contents);

    return 0;
}
//Falcon-180B DATASET v1.0 Category: File handling ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

// Function to read a line from the file
char* read_line(FILE* file) {
    char* line = malloc(MAX_LINE_LENGTH);
    if (fgets(line, MAX_LINE_LENGTH, file) == NULL) {
        printf("Error reading file.\n");
        exit(1);
    }
    return line;
}

// Function to write a line to the file
void write_line(FILE* file, char* line) {
    fprintf(file, "%s", line);
}

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

// Function to reverse the order of words in a line
char* reverse_words(char* line) {
    char* reversed_line = malloc(MAX_LINE_LENGTH);
    char* word = strtok(line, " ");
    while (word!= NULL) {
        strcat(reversed_line, word);
        strcat(reversed_line, " ");
        word = strtok(NULL, " ");
    }
    strcat(reversed_line, word);
    strcat(reversed_line, "\n");
    return reversed_line;
}

int main() {
    FILE* input_file = fopen("input.txt", "r");
    if (input_file == NULL) {
        printf("Error opening input file.\n");
        exit(1);
    }

    FILE* output_file = fopen("output.txt", "w");
    if (output_file == NULL) {
        printf("Error opening output file.\n");
        exit(1);
    }

    char* line;
    while ((line = read_line(input_file))!= NULL) {
        int word_count = count_words(line);
        char* reversed_line = reverse_words(line);
        write_line(output_file, reversed_line);
        free(reversed_line);
        free(line);
    }

    fclose(input_file);
    fclose(output_file);
    printf("Done.\n");
    return 0;
}
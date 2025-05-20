//Falcon-180B DATASET v1.0 Category: File handling ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1000 // maximum number of characters per line

// function to read a line from a file and return it as a string
char* read_line(FILE* file) {
    char* line = malloc(MAX_LINE_SIZE * sizeof(char));
    char c;
    int i = 0;
    while ((c = fgetc(file))!= EOF) {
        if (i == MAX_LINE_SIZE - 1) { // if line is full, exit loop
            line[i] = '\0';
            break;
        }
        line[i++] = c;
    }
    return line;
}

// function to write a string to a file
void write_line(FILE* file, char* line) {
    fprintf(file, "%s", line);
}

// function to count the number of lines in a file
int count_lines(FILE* file) {
    int count = 0;
    char* line;
    while ((line = read_line(file))!= NULL) {
        count++;
        free(line);
    }
    return count;
}

// function to read a file and print it backwards
void reverse_file(FILE* file) {
    char* line;
    while ((line = read_line(file))!= NULL) {
        fprintf(stdout, "%s", line);
    }
}

int main() {
    FILE* input_file = fopen("input.txt", "r");
    if (input_file == NULL) {
        printf("Error: Could not open input file.\n");
        exit(1);
    }
    int num_lines = count_lines(input_file);
    printf("Number of lines in input file: %d\n", num_lines);
    reverse_file(input_file);
    fclose(input_file);
    return 0;
}
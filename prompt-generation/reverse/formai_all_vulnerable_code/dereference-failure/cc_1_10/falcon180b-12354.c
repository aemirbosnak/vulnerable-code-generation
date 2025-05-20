//Falcon-180B DATASET v1.0 Category: File handling ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000

// Function to print a string in reverse order
void reverse_string(char *str, int start, int end) {
    char temp;
    while (start < end) {
        temp = *(str + start);
        *(str + start++) = *(str + end);
        *(str + end--) = temp;
    }
}

// Function to read a file and print its contents in reverse order
void read_file(FILE *fp) {
    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, fp)!= NULL) {
        int len = strlen(line);
        reverse_string(line, 0, len - 1);
        printf("%s", line);
    }
}

// Function to write a string to a file in reverse order
void write_file(FILE *fp, char *str) {
    int len = strlen(str);
    reverse_string(str, 0, len - 1);
    fprintf(fp, "%s", str);
}

// Recursive function to copy a file in reverse order
void copy_file(FILE *input_fp, FILE *output_fp) {
    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, input_fp)!= NULL) {
        int len = strlen(line);
        reverse_string(line, 0, len - 1);
        fprintf(output_fp, "%s", line);
    }
}

int main() {
    FILE *input_fp, *output_fp;

    // Open input file for reading
    input_fp = fopen("input.txt", "r");
    if (input_fp == NULL) {
        printf("Error: Could not open input file.\n");
        exit(1);
    }

    // Open output file for writing
    output_fp = fopen("output.txt", "w");
    if (output_fp == NULL) {
        printf("Error: Could not open output file.\n");
        exit(1);
    }

    // Copy the contents of the input file to the output file in reverse order
    copy_file(input_fp, output_fp);

    // Close the files
    fclose(input_fp);
    fclose(output_fp);

    return 0;
}
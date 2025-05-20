//Falcon-180B DATASET v1.0 Category: File Backup System ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1000 // Maximum length of a line in the input file

// Function to backup a file
void backup_file(FILE *input_file, FILE *output_file) {
    char line[MAX_LINE_LENGTH];
    int line_number = 1;

    while (fgets(line, MAX_LINE_LENGTH, input_file)!= NULL) {
        fprintf(output_file, "Line %d: %s", line_number, line);
        line_number++;
    }
}

int main() {
    FILE *input_file, *output_file;
    char input_file_name[100], output_file_name[100];

    // Get input file name from user
    printf("Enter input file name: ");
    scanf("%s", input_file_name);

    // Open input file for reading
    input_file = fopen(input_file_name, "r");

    if (input_file == NULL) {
        printf("Error opening input file.\n");
        exit(1);
    }

    // Create output file name by appending "_backup" to input file name
    strcpy(output_file_name, input_file_name);
    strcat(output_file_name, "_backup");

    // Open output file for writing
    output_file = fopen(output_file_name, "w");

    if (output_file == NULL) {
        printf("Error opening output file.\n");
        exit(1);
    }

    // Backup input file to output file
    backup_file(input_file, output_file);

    // Close input and output files
    fclose(input_file);
    fclose(output_file);

    printf("File backup completed.\n");

    return 0;
}
//Falcon-180B DATASET v1.0 Category: File handling ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000
#define MAX_NUM_LINES 1000

// Function to read a line from the file and store it in the buffer
int read_line(FILE* file, char* buffer, int line_num) {
    char c;
    int i = 0;

    while ((c = fgetc(file))!= EOF && i < MAX_LINE_LENGTH) {
        buffer[i] = c;
        i++;
    }

    if (i == MAX_LINE_LENGTH) {
        printf("Line %d is too long.\n", line_num);
        return -1;
    }

    buffer[i] = '\0';
    return 0;
}

// Function to write the lines to the file
void write_lines(FILE* file, char* lines[], int num_lines) {
    for (int i = 0; i < num_lines; i++) {
        fprintf(file, "%s\n", lines[i]);
    }
}

// Function to reverse the order of the lines in the buffer
void reverse_lines(char* lines[], int num_lines) {
    for (int i = 0; i < num_lines / 2; i++) {
        char* temp = lines[i];
        lines[i] = lines[num_lines - i - 1];
        lines[num_lines - i - 1] = temp;
    }
}

// Function to sort the lines alphabetically
void sort_lines(char* lines[], int num_lines) {
    for (int i = 0; i < num_lines - 1; i++) {
        for (int j = i + 1; j < num_lines; j++) {
            if (strcmp(lines[i], lines[j]) > 0) {
                char* temp = lines[i];
                lines[i] = lines[j];
                lines[j] = temp;
            }
        }
    }
}

int main() {
    FILE* input_file;
    char filename[100];
    char buffer[MAX_LINE_LENGTH];
    char* lines[MAX_NUM_LINES];
    int num_lines = 0;

    // Get the filename from the user
    printf("Enter the filename: ");
    scanf("%s", filename);

    // Open the file for reading
    input_file = fopen(filename, "r");

    if (input_file == NULL) {
        printf("Error opening file.\n");
        return -1;
    }

    // Read the lines from the file
    while (fgets(buffer, MAX_LINE_LENGTH, input_file)!= NULL) {
        if (num_lines == MAX_NUM_LINES) {
            printf("Maximum number of lines reached.\n");
            break;
        }

        if (read_line(input_file, buffer, num_lines) == -1) {
            return -1;
        }

        lines[num_lines] = strdup(buffer);
        num_lines++;
    }

    // Close the input file
    fclose(input_file);

    // Sort the lines alphabetically
    sort_lines(lines, num_lines);

    // Reverse the order of the lines
    reverse_lines(lines, num_lines);

    // Open the output file for writing
    FILE* output_file = fopen("output.txt", "w");

    if (output_file == NULL) {
        printf("Error opening output file.\n");
        return -1;
    }

    // Write the lines to the output file
    write_lines(output_file, lines, num_lines);

    // Close the output file
    fclose(output_file);

    printf("Done.\n");

    return 0;
}
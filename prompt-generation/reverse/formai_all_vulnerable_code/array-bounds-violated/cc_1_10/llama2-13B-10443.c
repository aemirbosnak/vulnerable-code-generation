//LLAMA2-13B DATASET v1.0 Category: File handling ; Style: retro
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define MAX_FILE_SIZE 1024
#define MAX_LINE_LENGTH 80

// Function to read a line from a file
void read_line(FILE *file) {
    char line[MAX_LINE_LENGTH];
    size_t len = fread(line, 1, MAX_LINE_LENGTH, file);
    line[len - 1] = '\0'; // Make sure the line is null-terminated
    printf("%s\n", line);
}

// Function to write a line to a file
void write_line(FILE *file, const char *line) {
    size_t len = strlen(line);
    fwrite(line, 1, len, file);
    fwrite("\n", 1, 1, file); // Add a newline at the end of the line
}

int main() {
    // Open the file in read-write mode
    FILE *file = fopen("example.txt", "r+");
    if (file == NULL) {
        perror("Failed to open file");
        return 1;
    }

    // Read the first line of the file
    read_line(file);

    // Ask the user to input a line to add to the file
    char line[MAX_LINE_LENGTH];
    printf("Enter a line to add to the file: ");
    fgets(line, MAX_LINE_LENGTH, stdin);

    // Write the line to the file
    write_line(file, line);

    // Read the next line of the file
    read_line(file);

    // Loop until the user wants to stop
    while (1) {
        // Ask the user to input another line to add to the file
        char line[MAX_LINE_LENGTH];
        printf("Enter another line to add to the file: ");
        fgets(line, MAX_LINE_LENGTH, stdin);

        // Write the line to the file
        write_line(file, line);

        // Read the next line of the file
        read_line(file);
    }

    // Close the file
    fclose(file);

    return 0;
}
//MISTRAL-7B DATASET v1.0 Category: File handling ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILE_SIZE 100
#define LINE_SIZE 80

void die(const char *msg) {
    perror(msg);
    exit(1);
}

int main(void) {
    FILE *fp;
    char filename[LINE_SIZE];
    char file_contents[FILE_SIZE];
    char *line_end;
    char line[LINE_SIZE];
    size_t chars_read;

    printf("Oh noes! I can't believe I have to read a file again!\n");

    // Ask user for file name
    printf("Enter file name: ");
    scanf("%s", filename);

    // Open file for reading
    fp = fopen(filename, "r");
    if (fp == NULL) {
        die("Failed to open file.");
    }

    // Read file contents into a buffer
    chars_read = fread(file_contents, sizeof(char), FILE_SIZE, fp);
    if (chars_read < FILE_SIZE) {
        die("Error reading file.");
    }

    // Close file
    fclose(fp);

    // Print file size and contents
    printf("File size: %ld bytes\n", chars_read);
    printf("File contents:\n-----------------\n%s\n-----------------\n", file_contents);

    // Read file line by line
    rewind(stdin); // Reset input stream to allow reading from filename again
    fp = fopen(filename, "r");

    while (fgets(line, LINE_SIZE, fp) != NULL) {
        // Process line
        size_t length = strlen(line);
        if (line[length - 1] == '\n') {
            line[length - 1] = '\0'; // Remove newline character
        }

        printf("Line contents: %s\n", line);

        // Do something with line here...

        // Free memory if necessary
        free(line);
    }

    fclose(fp);

    printf("All done! No more files for me!\n");

    return EXIT_SUCCESS;
}
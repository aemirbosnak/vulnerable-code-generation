//Code Llama-13B DATASET v1.0 Category: File handling ; Style: lively
// File handling example program in a lively style
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main() {
    // Declare variables
    char filename[256];
    FILE *file;
    char buffer[256];
    int line_count = 0;
    int char_count = 0;

    // Get the current time in seconds
    time_t t = time(NULL);
    struct tm *tm = localtime(&t);
    int year = tm->tm_year + 1900;
    int month = tm->tm_mon + 1;
    int day = tm->tm_mday;

    // Construct the filename
    snprintf(filename, sizeof(filename), "file%d-%d-%d.txt", year, month, day);

    // Open the file
    file = fopen(filename, "w");
    if (file == NULL) {
        fprintf(stderr, "Error: unable to open file %s\n", filename);
        return 1;
    }

    // Write some data to the file
    fprintf(file, "Hello, world!\n");
    fprintf(file, "This is a test of the emergency broadcast system.\n");
    fprintf(file, "This is only a test.\n");

    // Close the file
    fclose(file);

    // Open the file again
    file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Error: unable to open file %s\n", filename);
        return 1;
    }

    // Read the data from the file
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        line_count++;
        char_count += strlen(buffer);
    }

    // Close the file
    fclose(file);

    // Print the results
    printf("File: %s\n", filename);
    printf("Lines: %d\n", line_count);
    printf("Characters: %d\n", char_count);

    return 0;
}
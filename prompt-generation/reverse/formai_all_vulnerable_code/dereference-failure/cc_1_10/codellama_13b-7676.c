//Code Llama-13B DATASET v1.0 Category: File handling ; Style: immersive
// immersive_file_handling.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to read a file
void read_file(char *filename) {
    // Open the file
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file %s\n", filename);
        return;
    }

    // Read the file line by line
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    while ((read = getline(&line, &len, fp)) != -1) {
        // Remove trailing newline
        line[strcspn(line, "\n")] = '\0';
        printf("%s\n", line);
    }

    // Close the file
    fclose(fp);
    if (line) {
        free(line);
    }
}

// Function to write to a file
void write_file(char *filename) {
    // Open the file
    FILE *fp = fopen(filename, "w");
    if (fp == NULL) {
        printf("Error opening file %s\n", filename);
        return;
    }

    // Write to the file
    fprintf(fp, "Hello, world!\n");

    // Close the file
    fclose(fp);
}

int main(int argc, char *argv[]) {
    // Read the file
    read_file("example.txt");

    // Write to the file
    write_file("example.txt");

    return 0;
}
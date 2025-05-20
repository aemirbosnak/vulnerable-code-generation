//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Constants representing the maximum size of the file path and the line buffer */
#define MAX_PATH_SIZE 1000
#define MAX_LINE_SIZE 200

/* Function to open the file and check for errors */
FILE* open_file(char* file_path) {
    FILE* file = fopen(file_path, "r");
    if (file == NULL) {
        printf("Error: Unable to open file '%s'!\n", file_path);
        exit(1);
    }
    return file;
}

int main(int argc, char* argv[]) {
    printf("Welcome to the C Disk Space Analyzer program, Mr. Holmes!\n\n");

    /* Check if a command line argument (a file path) was provided */
    if (argc < 2) {
        printf("Error: No file path provided! Please provide a file path as a command line argument.\n");
        return 1;
    }

    /* Open the file and initialize variables */
    char* file_path = argv[1];
    FILE* file = open_file(file_path);
    char line[MAX_LINE_SIZE];
    int total_size = 0;
    int line_count = 0;

    /* Read each line of the file and analyze the disk space */
    while (fgets(line, MAX_LINE_SIZE, file)) {
        /* Remove the newline character at the end of the line, if present */
        if (line[strlen(line) - 1] == '\n') {
            line[strlen(line) - 1] = '\0';
        }

        /* Extract the file size from the line */
        int size = atoi(strrchr(line, ' ') + 1);

        /* Add the file size to the total size */
        total_size += size;
        line_count++;
    }

    /* Close the file and print the results */
    fclose(file);
    printf("I have analyzed the disk space used by the files in '%s', Mr. Holmes.\n", file_path);
    printf("There are %d files and directories, with a total size of %d bytes.\n", line_count, total_size);

    return 0;
}
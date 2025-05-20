//FormAI DATASET v1.0 Category: File handling ; Style: shocked
#include <stdio.h>
#include <stdlib.h>

// Define constant for maximum length of file path
#define MAX_PATH_LENGTH 256

// Define function to read contents of file
void read_file(char* file_path) {
    FILE* file = fopen(file_path, "r"); // open file in read mode
    if (file == NULL) { // handle file opening errors
        printf("ERROR: Failed to open file.\n");
        exit(1);
    }

    // read contents of file line by line and print them
    char line[256];
    while (fgets(line, 256, file) != NULL) {
        printf("%s", line);
    }

    fclose(file); // close file
}

// Define function to write contents to file
void write_file(char* file_path, char* content) {
    FILE* file = fopen(file_path, "w"); // open file in write mode
    if (file == NULL) { // handle file opening errors
        printf("ERROR: Failed to open file.\n");
        exit(1);
    }

    // write contents to file
    fprintf(file, "%s", content);

    fclose(file); // close file
}

int main() {
    char file_path[MAX_PATH_LENGTH]; // declare variable to store file path
    char content[256]; // declare variable to store content to write

    // prompt user to enter file path and content
    printf("Enter file path (max %d chars): ", MAX_PATH_LENGTH);
    scanf("%s", file_path);
    printf("Enter content to write (max 256 chars): ");
    scanf("%s", content);

    // write content to file
    write_file(file_path, content);

    // read and print contents of file
    printf("\nContents of %s:\n", file_path);
    read_file(file_path);

    return 0;
}
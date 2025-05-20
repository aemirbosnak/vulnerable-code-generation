//LLAMA2-13B DATASET v1.0 Category: File handling ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>

#define BUFFER_SIZE 1024
#define MAX_FILES 10

// Define a structure to hold information about each file
typedef struct {
    char *name;
    size_t size;
    off_t offset;
} file_info_t;

// Function to read a file and return its contents as a string
char *read_file(const char *file_name) {
    // Open the file in read mode
    FILE *file = fopen(file_name, "r");
    if (!file) {
        perror("Failed to open file");
        return NULL;
    }

    // Get the file size
    fseek(file, 0, SEEK_END);
    size_t file_size = ftell(file);
    rewind(file);

    // Allocate memory for the file contents
    char *file_contents = malloc(file_size + 1);
    if (!file_contents) {
        perror("Failed to allocate memory");
        fclose(file);
        return NULL;
    }

    // Read the file contents into the allocated memory
    size_t bytes_read = fread(file_contents, 1, file_size, file);
    if (bytes_read != file_size) {
        perror("Failed to read file");
        free(file_contents);
        fclose(file);
        return NULL;
    }

    // Null-terminate the string
    file_contents[file_size] = '\0';

    // Close the file
    fclose(file);

    return file_contents;
}

// Function to write a file and return its contents as a string
char *write_file(const char *file_name, const char *contents) {
    // Open the file in write mode
    FILE *file = fopen(file_name, "w");
    if (!file) {
        perror("Failed to open file");
        return NULL;
    }

    // Write the contents to the file
    size_t bytes_written = fwrite(contents, 1, strlen(contents), file);
    if (bytes_written != strlen(contents)) {
        perror("Failed to write file");
        fclose(file);
        return NULL;
    }

    // Flush the buffer to ensure the data is written to disk
    fflush(file);

    // Close the file
    fclose(file);

    return contents;
}

int main() {
    // Array to hold the file names
    char *file_names[MAX_FILES];

    // Initialize the array with some default filenames
    for (int i = 0; i < MAX_FILES; i++) {
        file_names[i] = "example_file";
    }

    // Ask the user to enter the names of the files they want to read and write
    for (int i = 0; i < MAX_FILES; i++) {
        printf("Enter the name of the file you want to %s (%s): ",
            i == 0 ? "read" : "write",
            file_names[i]);
        scanf("%s", file_names[i]);
    }

    // Loop through the files and read/write them as specified
    for (int i = 0; i < MAX_FILES; i++) {
        if (strcmp(file_names[i], "done") == 0) {
            break;
        }

        // Read the file if we're in read mode
        if (i == 0) {
            char *file_contents = read_file(file_names[i]);
            if (!file_contents) {
                perror("Failed to read file");
                continue;
            }

            printf("The contents of %s are:\n%s\n", file_names[i], file_contents);
            free(file_contents);
        } else {
            // Write the file if we're in write mode
            char *file_contents = write_file(file_names[i], "Hello, world!");
            if (!file_contents) {
                perror("Failed to write file");
                continue;
            }

            printf("Wrote %s\n", file_names[i]);
        }
    }

    return 0;
}
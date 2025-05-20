//Code Llama-13B DATASET v1.0 Category: File handling ; Style: interoperable
// interoperable_file_handling.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

// Define a structure to store file information
struct file_info {
    char *name;
    char *extension;
    int size;
};

// Function to read file information from a file
int read_file_info(struct file_info *file_info, const char *file_path) {
    FILE *file;
    char line[256];
    char *token;

    // Open the file
    file = fopen(file_path, "r");
    if (file == NULL) {
        fprintf(stderr, "Error opening file: %s\n", file_path);
        return -1;
    }

    // Read the file name and extension
    if (fgets(line, sizeof(line), file) == NULL) {
        fprintf(stderr, "Error reading file name and extension\n");
        fclose(file);
        return -1;
    }

    // Get the file name and extension
    token = strtok(line, ".");
    file_info->name = strdup(token);
    token = strtok(NULL, ".");
    file_info->extension = strdup(token);

    // Read the file size
    if (fscanf(file, "%d", &file_info->size) != 1) {
        fprintf(stderr, "Error reading file size\n");
        fclose(file);
        return -1;
    }

    // Close the file
    fclose(file);

    return 0;
}

// Function to write file information to a file
int write_file_info(const struct file_info *file_info, const char *file_path) {
    FILE *file;

    // Open the file
    file = fopen(file_path, "w");
    if (file == NULL) {
        fprintf(stderr, "Error opening file: %s\n", file_path);
        return -1;
    }

    // Write the file name and extension
    fprintf(file, "%s.%s\n", file_info->name, file_info->extension);

    // Write the file size
    fprintf(file, "%d\n", file_info->size);

    // Close the file
    fclose(file);

    return 0;
}

int main(void) {
    struct file_info file_info;

    // Read file information from a file
    if (read_file_info(&file_info, "file.txt") != 0) {
        fprintf(stderr, "Error reading file information\n");
        return -1;
    }

    // Print the file information
    printf("File name: %s\n", file_info.name);
    printf("File extension: %s\n", file_info.extension);
    printf("File size: %d\n", file_info.size);

    // Write file information to a file
    if (write_file_info(&file_info, "file_info.txt") != 0) {
        fprintf(stderr, "Error writing file information\n");
        return -1;
    }

    return 0;
}
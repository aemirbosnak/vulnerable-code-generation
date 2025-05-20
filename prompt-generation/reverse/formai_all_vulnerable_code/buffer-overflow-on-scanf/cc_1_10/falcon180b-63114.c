//Falcon-180B DATASET v1.0 Category: File Synchronizer ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_FILE_NAME_LEN 256
#define MAX_FILE_PATH_LEN 1024

struct file_info {
    char file_name[MAX_FILE_NAME_LEN];
    char file_path[MAX_FILE_PATH_LEN];
    bool is_directory;
};

void print_file_info(struct file_info* file_info) {
    printf("File name: %s\n", file_info->file_name);
    printf("File path: %s\n", file_info->file_path);
    printf("Is directory: %s\n", file_info->is_directory? "Yes" : "No");
}

int main() {
    struct file_info source_file_info;
    struct file_info destination_file_info;

    // Get source file information
    printf("Enter source file name: ");
    scanf("%s", source_file_info.file_name);
    printf("Enter source file path: ");
    scanf("%s", source_file_info.file_path);
    source_file_info.is_directory = false;

    // Get destination file information
    printf("Enter destination file name: ");
    scanf("%s", destination_file_info.file_name);
    printf("Enter destination file path: ");
    scanf("%s", destination_file_info.file_path);
    destination_file_info.is_directory = false;

    // Open source file
    FILE* source_file = fopen(source_file_info.file_path, "r");
    if (source_file == NULL) {
        printf("Error: Could not open source file.\n");
        exit(1);
    }

    // Open destination file
    FILE* destination_file = fopen(destination_file_info.file_path, "w");
    if (destination_file == NULL) {
        printf("Error: Could not open destination file.\n");
        fclose(source_file);
        exit(1);
    }

    // Read source file contents
    char buffer[1024];
    while (fgets(buffer, sizeof(buffer), source_file)!= NULL) {
        fputs(buffer, destination_file);
    }

    // Close files
    fclose(source_file);
    fclose(destination_file);

    // Print success message
    printf("File synchronization completed successfully!\n");

    return 0;
}
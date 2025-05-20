//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>

int main() {
    // Initialize variables
    DIR* directory;
    struct dirent* file;
    char* path = ".";
    int total_size = 0;

    // Open current directory
    directory = opendir(path);

    // Check if directory is open
    if (directory != NULL) {
        // Print header
        printf("\nC Disk Space Analyzer\n\n");

        // Loop through files in directory
        while ((file = readdir(directory)) != NULL) {
            // Get file path
            char file_path[256];
            sprintf(file_path, "%s/%s", path, file->d_name);

            // Get file size
            FILE* fp;
            fp = fopen(file_path, "rb");
            if (fp != NULL) {
                fseek(fp, 0, SEEK_END);
                int file_size = ftell(fp);
                fclose(fp);

                // Add file size to total
                total_size += file_size;

                // Print file name and size
                printf("%s - %d bytes\n", file->d_name, file_size);
            }
        }

        // Close directory
        closedir(directory);

        // Print total disk usage
        printf("\nTotal disk usage: %d bytes\n", total_size);
    } else {
        // Print error message if directory can't be opened
        printf("Error: Could not open directory\n");
    }

    return 0;
}
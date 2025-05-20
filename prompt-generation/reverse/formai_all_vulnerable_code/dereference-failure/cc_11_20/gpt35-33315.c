//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <ctype.h>

#define MAX_FILES 1000 // Maximum number of files to scan
#define BUFFER_SIZE 1024 // Size of buffer for reading files

int main(int argc, char *argv[]) {

    int file_counter = 0; // Keeps track of number of scanned files
    char buffer[BUFFER_SIZE];
    char current_directory[BUFFER_SIZE];

    // Get current working directory
    if (getcwd(current_directory, sizeof(current_directory)) == NULL) {
        printf("Error: Unable to get current working directory.");
        return 1;
    }

    // Open directory for scanning
    DIR *dir;
    struct dirent *ent;
    if ((dir = opendir(current_directory)) == NULL) {
        printf("Error: Unable to open directory.");
        return 1;
    }

    // Store file names in array for scanning
    char file_names[MAX_FILES][BUFFER_SIZE];
    while ((ent = readdir(dir)) != NULL && file_counter < MAX_FILES) {
        if (strcmp(ent->d_name, ".") != 0 && strcmp(ent->d_name, "..") != 0) {
            strncpy(file_names[file_counter], ent->d_name, BUFFER_SIZE-1);
            file_counter++;
        }
    }
    closedir(dir);

    // Scan files for viruses
    int virus_counter = 0;
    for (int i = 0; i < file_counter; i++) {

        // Open file for reading
        FILE *file;
        char file_path[BUFFER_SIZE];
        sprintf(file_path, "%s/%s", current_directory, file_names[i]);

        if ((file = fopen(file_path, "r")) == NULL) {
            printf("\nError: Unable to open file %s for reading.", file_names[i]);
        }

        // Read file line by line
        while (fgets(buffer, BUFFER_SIZE, file)) {

            // Check for common virus signatures
            if ((strstr(buffer, "virus") != NULL) || 
                (strstr(buffer, "worm") != NULL) || 
                (strstr(buffer, "trojan") != NULL)) {

                // Found virus signature in file
                printf("\n%s - contains virus signature(s)", file_names[i]);
                virus_counter++;
                break;
            }
        }

        fclose(file);
    }

    printf("\nScanning completed. %d viruses found in %d files.", virus_counter, file_counter);
    return 0;
}
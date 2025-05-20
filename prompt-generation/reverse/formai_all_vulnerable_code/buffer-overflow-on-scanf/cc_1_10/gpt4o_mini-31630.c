//GPT-4o-mini DATASET v1.0 Category: Antivirus scanner ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

#define MAX_PATH 1024
#define MAX_SIGNATURES 100
#define SIGNATURE_LENGTH 64

// Function prototypes
void scan_directory(const char *directory);
int is_infected(const char *file_path);
void read_signatures(const char *file_name);

// Global variables
char signatures[MAX_SIGNATURES][SIGNATURE_LENGTH];
int signature_count = 0;

int main() {
    char directory[MAX_PATH];

    printf("Welcome to Simple C Antivirus Scanner!\n");
    printf("Enter the directory to scan: ");
    scanf("%s", directory);

    // Load malware signatures
    read_signatures("signatures.txt");
    
    // Scan the specified directory
    scan_directory(directory);

    return 0;
}

// Function to read malware signatures from file
void read_signatures(const char *file_name) {
    FILE *file = fopen(file_name, "r");
    if (file == NULL) {
        perror("Failed to open signatures file");
        exit(EXIT_FAILURE);
    }

    while (fgets(signatures[signature_count], SIGNATURE_LENGTH, file) != NULL) {
        // Remove newline character from each signature
        signatures[signature_count][strcspn(signatures[signature_count], "\n")] = 0;
        signature_count++;
        
        // Limit the number of signatures
        if (signature_count >= MAX_SIGNATURES) {
            break;
        }
    }

    fclose(file);
    printf("Loaded %d malware signatures.\n", signature_count);
}

// Function to scan a directory and its files
void scan_directory(const char *directory) {
    struct dirent *entry;
    DIR *dp = opendir(directory);
    if (dp == NULL) {
        perror("Failed to open directory");
        return;
    }

    while ((entry = readdir(dp)) != NULL) {
        // Skip the "." and ".." entries
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        char path[MAX_PATH];
        snprintf(path, sizeof(path), "%s/%s", directory, entry->d_name);

        // Check if it's a directory
        if (entry->d_type == DT_DIR) {
            // Recursively scan the subdirectory
            scan_directory(path);
        } else {
            // Scan the file for viruses
            if (is_infected(path)) {
                printf("Infected file found: %s\n", path);
            }
        }
    }

    closedir(dp);
}

// Function to check if a file is infected
int is_infected(const char *file_path) {
    FILE *file = fopen(file_path, "rb");
    if (file == NULL) {
        perror("Failed to open file");
        return 0; // Consider it not infected if there's an error
    }

    char buffer[1024];
    size_t bytes_read;
    while ((bytes_read = fread(buffer, 1, sizeof(buffer), file)) > 0) {
        for (int i = 0; i < signature_count; i++) {
            // Check if the signature is present in the read buffer
            if (memmem(buffer, bytes_read, signatures[i], strlen(signatures[i]))) {
                fclose(file);
                return 1; // File is infected
            }
        }
    }

    fclose(file);
    return 0; // File is not infected
}
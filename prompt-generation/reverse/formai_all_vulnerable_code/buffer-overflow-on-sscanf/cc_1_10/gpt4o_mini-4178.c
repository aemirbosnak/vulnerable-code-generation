//GPT-4o-mini DATASET v1.0 Category: Antivirus scanner ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

#define MAX_SIGNATURES 5
#define MAX_FILENAME 256
#define MAX_PATH 512

// Known virus signatures to check for (in hex format).
const char *virus_signatures[MAX_SIGNATURES] = {
    "E4 5E 12 35 AB", // Signature 1
    "DA 4D 7A B1 C4", // Signature 2
    "3A B1 D2 80 48", // Signature 3
    "C1 F8 FE 1A 23", // Signature 4
    "00 11 22 33 44"  // Signature 5
};

// Function to check a file against known virus signatures
int scan_file(const char *file_path) {
    FILE *file = fopen(file_path, "rb");
    if (!file) {
        perror("Failed to open file");
        return -1; 
    }

    unsigned char buffer[512];
    size_t bytes_read = fread(buffer, 1, sizeof(buffer), file);
    fclose(file);

    for (int i = 0; i < MAX_SIGNATURES; i++) {
        // Convert signature to binary and check against file
        unsigned char signature[5];
        int bytes_matched = sscanf(virus_signatures[i], "%hhx %hhx %hhx %hhx %hhx",
                                   &signature[0], &signature[1], 
                                   &signature[2], &signature[3], 
                                   &signature[4]);
        
        if (bytes_matched != 5) continue;

        // Search for the signature in the file's content
        for (size_t j = 0; j <= bytes_read - 5; j++) {
            if (memcmp(&buffer[j], signature, 5) == 0) {
                printf("Virus found in file: %s - Signature: %s\n", file_path, virus_signatures[i]);
                return 1; // Virus found
            }
        }
    }
    return 0; // No virus found
}

// Function to scan files in a given directory
void scan_directory(const char *dir_path) {
    struct dirent *entry;
    DIR *dp = opendir(dir_path);
    if (!dp) {
        perror("Couldn't open the directory");
        return;
    }

    while ((entry = readdir(dp))) {
        if (entry->d_name[0] == '.') continue; // Skip hidden files

        char file_path[MAX_PATH];
        snprintf(file_path, sizeof(file_path), "%s/%s", dir_path, entry->d_name);

        struct stat path_stat;
        stat(file_path, &path_stat);
        if (S_ISDIR(path_stat.st_mode)) {
            // Recursive scan of subdirectories
            scan_directory(file_path);
        } else if (S_ISREG(path_stat.st_mode)) {
            // Scan regular files
            int result = scan_file(file_path);
            if (result == -1) {
                fprintf(stderr, "Error scanning file: %s\n", file_path);
            }
        }
    }
    closedir(dp);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <directory_to_scan>\n", argv[0]);
        return 1;
    }

    printf("Scanning directory: %s\n", argv[1]);
    scan_directory(argv[1]);
    printf("Scanning complete.\n");

    return 0;
}
//GPT-4o-mini DATASET v1.0 Category: Antivirus scanner ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

#define MAX_PATH_LENGTH 1024
#define MAX_SIGNATURES 100
#define SIGNATURE_LENGTH 64

struct VirusSignature {
    char name[SIGNATURE_LENGTH];
    char signature[SIGNATURE_LENGTH];
};

struct VirusSignature signatures[MAX_SIGNATURES];
int signature_count = 0;

// Function to load virus signatures from a file
void load_signatures(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Failed to open signature file");
        exit(EXIT_FAILURE);
    }

    while (fscanf(file, "%s %s", signatures[signature_count].name, signatures[signature_count].signature) == 2) {
        signature_count++;
        if (signature_count >= MAX_SIGNATURES) {
            break;
        }
    }

    fclose(file);
}

// Function to scan a file for virus signatures
int scan_file(const char *filepath) {
    FILE *file = fopen(filepath, "rb");
    if (!file) {
        perror("Failed to open file");
        return 0;
    }

    unsigned char buffer[1024];
    size_t bytesRead;
    int found = 0;

    while ((bytesRead = fread(buffer, 1, sizeof(buffer), file)) > 0) {
        for (int i = 0; i < signature_count; i++) {
            if (strstr((char *)buffer, signatures[i].signature) != NULL) {
                printf("Virus found in file: %s (Signature: %s)\n", filepath, signatures[i].name);
                found = 1;
                break;
            }
        }
    }

    fclose(file);
    return found;
}

// Function to recursively scan directories
void scan_directory(const char *dirpath) {
    struct dirent *entry;
    struct stat file_stat;
    char path[MAX_PATH_LENGTH];
    DIR *dir = opendir(dirpath);

    if (!dir) {
        perror("Failed to open directory");
        return;
    }

    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        snprintf(path, sizeof(path), "%s/%s", dirpath, entry->d_name);
        if (stat(path, &file_stat) < 0) {
            perror("Failed to get file status");
            continue;
        }

        if (S_ISDIR(file_stat.st_mode)) {
            scan_directory(path); // Recursive scan for directories
        } else if (S_ISREG(file_stat.st_mode)) {
            if (scan_file(path)) {
                printf("A virus was detected in: %s\n", path);
            }
        }
    }

    closedir(dir);
}

// Main function
int main(int argc, char *argv[]) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <signature_file> <directory_to_scan>\n", argv[0]);
        return EXIT_FAILURE;
    }

    load_signatures(argv[1]); // Load the virus signatures from a file
    scan_directory(argv[2]); // Scan the specified directory

    printf("Scanning complete!\nTotal signatures loaded: %d\n", signature_count);
    return EXIT_SUCCESS;
}
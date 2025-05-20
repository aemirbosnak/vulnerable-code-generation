//GPT-4o-mini DATASET v1.0 Category: Antivirus scanner ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

#define MAX_PATH 1024
#define SIGNATURE_SIZE 64
#define MAX_SIGNATURES 100

typedef struct {
    char name[MAX_PATH];
    char signature[SIGNATURE_SIZE];
} AntivirusSignature;

AntivirusSignature signatures[MAX_SIGNATURES];
int signature_count = 0;

void load_signatures(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Failed to open signature file");
        exit(EXIT_FAILURE);
    }

    while (fscanf(file, "%s %s", signatures[signature_count].name, signatures[signature_count].signature) != EOF) {
        signature_count++;
        if (signature_count >= MAX_SIGNATURES) {
            break;
        }
    }

    fclose(file);
}

int is_vulnerable(const char *file_path) {
    FILE *file = fopen(file_path, "rb");
    if (file == NULL) {
        perror("Failed to open file for scanning");
        return 0;
    }

    char buffer[SIGNATURE_SIZE];
    fread(buffer, sizeof(char), SIGNATURE_SIZE, file);
    fclose(file);

    for (int i = 0; i < signature_count; i++) {
        if (memcmp(buffer, signatures[i].signature, SIGNATURE_SIZE) == 0) {
            printf("WARNING: Virus found in %s! Detected by signature: %s\n", file_path, signatures[i].name);
            return 1;
        }
    }
    return 0;
}

void scan_directory(const char *dir_path) {
    struct dirent *entry;
    DIR *dir = opendir(dir_path);
    if (!dir) {
        perror("Could not open directory");
        return;
    }

    while ((entry = readdir(dir)) != NULL) {
        
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue; // Skip current and parent directory entries
        }

        char path[MAX_PATH];
        snprintf(path, sizeof(path), "%s/%s", dir_path, entry->d_name);

        struct stat statbuf;
        stat(path, &statbuf);
        if (S_ISDIR(statbuf.st_mode)) {
            // It's a directory, scan it recursively
            printf("Scanning directory: %s\n", path);
            scan_directory(path);
        } else {
            // It's a file, check if it's infected
            printf("Scanning file: %s\n", path);
            if (is_vulnerable(path)) {
                printf("ALERT! Infection detected in: %s\n", path);
            }
        }
    }
    closedir(dir);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <signature_file> <directory_to_scan>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Load virus signatures
    load_signatures(argv[1]);
    printf("Loaded %d signatures for scanning.\n", signature_count);

    // Start the scanning process
    printf("Starting scan of directory: %s\n", argv[2]);
    scan_directory(argv[2]);

    printf("Scanning completed. Review alerts above for potential infections.\n");
    return EXIT_SUCCESS;
}
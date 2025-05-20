//GPT-4o-mini DATASET v1.0 Category: Antivirus scanner ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#define MAX_PATH 1024
#define SIGNATURE_SIZE 256
#define MAX_SIGNATURES 100
#define BUFFER_SIZE 4096

typedef struct {
    char name[SIGNATURE_SIZE];
    unsigned char pattern[SIGNATURE_SIZE];
    size_t length;
} Signature;

Signature signatures[MAX_SIGNATURES];
int signature_count = 0;

void load_signatures(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening signature file");
        exit(EXIT_FAILURE);
    }

    while (fscanf(file, "%s %s", signatures[signature_count].name, signatures[signature_count].pattern) != EOF) {
        signatures[signature_count].length = strlen(signatures[signature_count].pattern) / 2;
        for (size_t i = 0; i < signatures[signature_count].length; i++) {
            sscanf(signatures[signature_count].pattern + 2 * i, "%2hhx", &signatures[signature_count].pattern[i]);
        }
        signature_count++;
    }
    fclose(file);
}

int scan_for_signature(const char *filepath, const Signature *sig) {
    FILE *file = fopen(filepath, "rb");
    if (file == NULL) {
        perror("Error opening file for scanning");
        return 0;
    }

    unsigned char buffer[BUFFER_SIZE];
    size_t bytes_read;
    size_t match_count = 0;

    while ((bytes_read = fread(buffer, 1, BUFFER_SIZE, file)) > 0) {
        for (size_t i = 0; i <= bytes_read - sig->length; i++) {
            if (memcmp(buffer + i, sig->pattern, sig->length) == 0) {
                fclose(file);
                return 1; // Signature found
            }
        }
    }
    fclose(file);
    return 0; // Signature not found
}

void scan_directory(const char *directory) {
    struct dirent *entry;
    DIR *dp = opendir(directory);

    if (dp == NULL) {
        perror("Error opening directory");
        return;
    }

    while ((entry = readdir(dp)) != NULL) {
        char path[MAX_PATH];
        snprintf(path, sizeof(path), "%s/%s", directory, entry->d_name);

        if (entry->d_type == DT_DIR) {
            if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
                scan_directory(path); // Recursive scan
            }
        } else if (entry->d_type == DT_REG) {
            for (int i = 0; i < signature_count; i++) {
                if (scan_for_signature(path, &signatures[i])) {
                    printf("Infected file found: %s - Signature: %s\n", path, signatures[i].name);
                }
            }
        }
    }
    closedir(dp);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <signature_file> <directory_to_scan>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    load_signatures(argv[1]);
    printf("Loaded %d signatures.\n", signature_count);

    scan_directory(argv[2]);
    printf("Scanning completed.\n");

    return 0;
}
//GPT-4o-mini DATASET v1.0 Category: Antivirus scanner ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

#define MAX_PATH 4096
#define SIGNATURE_SIZE 64
#define MAX_SIGNATURES 128

typedef struct {
    char name[MAX_PATH];
    char signature[SIGNATURE_SIZE];
} VirusSignature;

VirusSignature virusSignatures[MAX_SIGNATURES];
int virusCount = 0;

void loadVirusSignatures(const char *filePath) {
    FILE *file = fopen(filePath, "r");
    if (!file) {
        fprintf(stderr, "ERROR: Unable to open signature file: %s\n", filePath);
        exit(EXIT_FAILURE);
    }
    
    while (fscanf(file, "%s %s", virusSignatures[virusCount].name, virusSignatures[virusCount].signature) != EOF) {
        virusCount++;
        if (virusCount >= MAX_SIGNATURES) {
            fprintf(stderr, "ERROR: Maximum number of virus signatures exceeded.\n");
            fclose(file);
            exit(EXIT_FAILURE);
        }
    }
    fclose(file);
}

void scanFile(const char *filePath) {
    FILE *file = fopen(filePath, "rb");
    if (!file) {
        fprintf(stderr, "ERROR: Unable to open file for scanning: %s\n", filePath);
        return;
    }

    unsigned char buffer[4096];
    size_t bytesRead;

    while ((bytesRead = fread(buffer, 1, sizeof(buffer), file)) > 0) {
        for (int i = 0; i < virusCount; i++) {
            if (memmem(buffer, bytesRead, virusSignatures[i].signature, strlen(virusSignatures[i].signature))) {
                printf("ALERT! Virus detected: %s in file: %s\n", virusSignatures[i].name, filePath);
                fclose(file);
                return;
            }
        }
    }
    fclose(file);
}

void scanDirectory(const char *dirPath) {
    struct dirent *entry;
    DIR *dp = opendir(dirPath);

    if (!dp) {
        fprintf(stderr, "ERROR: Unable to open directory: %s\n", dirPath);
        return;
    }

    while ((entry = readdir(dp))) {
        if (entry->d_type == DT_DIR) {
            if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
                char subDirPath[MAX_PATH];
                snprintf(subDirPath, sizeof(subDirPath), "%s/%s", dirPath, entry->d_name);
                scanDirectory(subDirPath);  // Recursion for subdirectories
            }
        } else {
            char filePath[MAX_PATH];
            snprintf(filePath, sizeof(filePath), "%s/%s", dirPath, entry->d_name);
            scanFile(filePath);
        }
    }

    closedir(dp);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "SOMETHING IS WRONG! Usage: %s <signature_file> <directory_to_scan>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    loadVirusSignatures(argv[1]);
    printf("Loaded %d virus signatures. Initiating scan...\n", virusCount);

    scanDirectory(argv[2]);
    printf("Scan complete!\n");

    return 0;
}
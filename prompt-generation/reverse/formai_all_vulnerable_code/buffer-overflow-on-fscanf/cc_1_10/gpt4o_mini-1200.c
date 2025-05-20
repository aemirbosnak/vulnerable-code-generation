//GPT-4o-mini DATASET v1.0 Category: Antivirus scanner ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

#define MAX_FILE_PATH 1024
#define MAX_VIRUS_SIG 256
#define MAX_VIRUS_LIST 10

typedef struct VirusSignature {
    char name[MAX_VIRUS_SIG];
    char signature[MAX_VIRUS_SIG];
} VirusSignature;

VirusSignature virusDatabase[MAX_VIRUS_LIST];
int virusCount = 0;

void loadVirusSignatures(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Could not open virus signature file");
        exit(EXIT_FAILURE);
    }

    while (fscanf(file, "%s %s", virusDatabase[virusCount].name, virusDatabase[virusCount].signature) != EOF) {
        virusCount++;
        if (virusCount >= MAX_VIRUS_LIST) {
            break;
        }
    }
    fclose(file);
}

int scanFile(const char *filePath) {
    FILE *file = fopen(filePath, "r");
    if (!file) {
        perror("Could not open file for scanning");
        return 0; // Could not open file, skip
    }

    char *buffer = (char *)malloc(1024);
    int foundVirus = 0;

    while (fread(buffer, 1, 1024, file) > 0) {
        for (int i = 0; i < virusCount; i++) {
            if (strstr(buffer, virusDatabase[i].signature) != NULL) {
                printf("Virus Found: %s in file: %s\n", virusDatabase[i].name, filePath);
                foundVirus = 1;
                break; // Virus found, break loop
            }
        }
        if (foundVirus)
            break; // No need to read further if a virus was found
    }

    free(buffer);
    fclose(file);
    return foundVirus;
}

void scanDirectory(const char *directoryPath) {
    struct dirent *entry;
    DIR *dp = opendir(directoryPath);

    if (!dp) {
        perror("Could not open directory");
        return;
    }

    while ((entry = readdir(dp))) {
        if (entry->d_type == DT_REG) { // Regular file
            char filePath[MAX_FILE_PATH];
            snprintf(filePath, sizeof(filePath), "%s/%s", directoryPath, entry->d_name);
            scanFile(filePath);
        } else if (entry->d_type == DT_DIR) { // Directory
            if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
                char subDirPath[MAX_FILE_PATH];
                snprintf(subDirPath, sizeof(subDirPath), "%s/%s", directoryPath, entry->d_name);
                scanDirectory(subDirPath); // Recur for subdirectory
            }
        }
    }

    closedir(dp);
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <virus_signatures_file> <directory_to_scan>\n", argv[0]);
        return EXIT_FAILURE;
    }

    loadVirusSignatures(argv[1]);
    scanDirectory(argv[2]);

    return EXIT_SUCCESS;
}
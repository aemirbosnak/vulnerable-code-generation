//GPT-4o-mini DATASET v1.0 Category: Antivirus scanner ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

#define MAX_PATH_LENGTH 1024
#define MAX_VIRUS_DEFINITIONS 100
#define MAX_DEFINITION_LENGTH 256

typedef struct {
    char name[MAX_DEFINITION_LENGTH];
    char hash[MAX_DEFINITION_LENGTH];
} VirusDefinition;

typedef struct {
    VirusDefinition definitions[MAX_VIRUS_DEFINITIONS];
    int count;
} VirusDatabase;

VirusDatabase db;

void loadVirusDefinitions(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Could not open virus definitions file");
        exit(EXIT_FAILURE);
    }
    
    db.count = 0;
    while (fscanf(file, "%s %s", db.definitions[db.count].name, db.definitions[db.count].hash) != EOF) {
        db.count++;
        if (db.count >= MAX_VIRUS_DEFINITIONS) {
            break;
        }
    }
    fclose(file);
}

void calculateFileHash(const char *filepath, char *hash) {
    // This is a placeholder. Implement your own hash function here
    snprintf(hash, MAX_DEFINITION_LENGTH, "%s_hash", filepath);
}

int checkFileForVirus(const char *filepath) {
    char fileHash[MAX_DEFINITION_LENGTH];
    calculateFileHash(filepath, fileHash);

    for (int i = 0; i < db.count; i++) {
        if (strcmp(fileHash, db.definitions[i].hash) == 0) {
            printf("Virus detected: %s in file: %s\n", db.definitions[i].name, filepath);
            return 1;
        }
    }
    return 0;
}

void scanDirectory(const char *directory) {
    struct dirent *entry;
    struct stat fileStat;
    DIR *dir = opendir(directory);
    
    if (!dir) {
        perror("Failed to open directory");
        return;
    }

    while ((entry = readdir(dir)) != NULL) {
        char path[MAX_PATH_LENGTH];
        snprintf(path, sizeof(path), "%s/%s", directory, entry->d_name);
        
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }
        
        if (stat(path, &fileStat) == -1) {
            perror("Error accessing file");
            continue;
        }
        
        if (S_ISDIR(fileStat.st_mode)) {
            // It's a directory, recurse into it
            scanDirectory(path);
        } else {
            // It's a regular file, check for viruses
            if (checkFileForVirus(path)) {
                printf("Alert: Virus found in %s!\n", path);
            }
        }
    }

    closedir(dir);
}

void scanSystem(const char *startDirectory) {
    printf("Scanning directory: %s\n", startDirectory);
    scanDirectory(startDirectory);
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <definitions_file> <directory_to_scan>\n", argv[0]);
        return EXIT_FAILURE;
    }

    loadVirusDefinitions(argv[1]);

    scanSystem(argv[2]);

    return EXIT_SUCCESS;
}
//GPT-4o-mini DATASET v1.0 Category: Antivirus scanner ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

#define MAX_PATH 1024
#define SIGNATURES_FILE "signatures.txt"
#define BUFFER_SIZE 4096

typedef struct {
    char name[MAX_PATH];
    unsigned char hash[16]; // Simple hash representation (MD5 would be larger)
} VirusSignature;

VirusSignature *load_signatures(int *count) {
    FILE *file = fopen(SIGNATURES_FILE, "r");
    if (!file) {
        perror("Could not open signatures file");
        return NULL;
    }

    VirusSignature *signatures = NULL;
    *count = 0;

    char line[MAX_PATH + 32]; // Extra space for hash
    while (fgets(line, sizeof(line), file)) {
        if (*count % 10 == 0) {
            signatures = realloc(signatures, (*count + 10) * sizeof(VirusSignature));
        }

        sscanf(line, "%s %hhx%hhx%hhx%hhx%hhx%hhx%hhx%hhx%hhx%hhx%hhx%hhx%hhx%hhx%hhx%hhx",
               signatures[*count].name,
               &signatures[*count].hash[0],
               &signatures[*count].hash[1],
               &signatures[*count].hash[2],
               &signatures[*count].hash[3],
               &signatures[*count].hash[4],
               &signatures[*count].hash[5],
               &signatures[*count].hash[6],
               &signatures[*count].hash[7],
               &signatures[*count].hash[8],
               &signatures[*count].hash[9],
               &signatures[*count].hash[10],
               &signatures[*count].hash[11],
               &signatures[*count].hash[12],
               &signatures[*count].hash[13],
               &signatures[*count].hash[14],
               &signatures[*count].hash[15]);
        
        (*count)++;
    }

    fclose(file);
    return signatures;
}

void compute_file_hash(const char *path, unsigned char *hash) {
    // A stub function that should compute the hash of the file at 'path'
    // In a real antivirus program, you would use a hash function like MD5 or SHA-256
    memset(hash, 0, 16); // For demonstration, populate with zeros (NOT secure or correct)
}

int scan_file(const char *filepath, VirusSignature *signatures, int count) {
    unsigned char file_hash[16];
    compute_file_hash(filepath, file_hash);

    for (int i = 0; i < count; i++) {
        if (memcmp(file_hash, signatures[i].hash, 16) == 0) {
            printf("Virus detected in file: %s (Signature: %s)\n", filepath, signatures[i].name);
            return 1; // Virus found
        }
    }
    return 0; // No virus found
}

void scan_directory(const char *directory, VirusSignature *signatures, int count) {
    struct dirent *entry;
    struct stat statbuf;

    DIR *dp = opendir(directory);
    if (!dp) {
        perror("opendir failed");
        return;
    }

    while ((entry = readdir(dp)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue; // Skip dot and dot-dot entries
        }

        char path[MAX_PATH];
        snprintf(path, sizeof(path), "%s/%s", directory, entry->d_name);
        
        if (stat(path, &statbuf) == -1) {
            perror("stat failed");
            continue;
        }

        if (S_ISDIR(statbuf.st_mode)) {
            scan_directory(path, signatures, count); // Recur into subdirectory
        } else if (S_ISREG(statbuf.st_mode)) {
            scan_file(path, signatures, count);
        }
    }

    closedir(dp);
}

int main(int argc, char *argv[]) {
    int signature_count = 0;
    VirusSignature *signatures = load_signatures(&signature_count);
    
    if (!signatures) {
        return EXIT_FAILURE; // If there was an error loading the signatures
    }

    const char *directory_to_scan = (argc > 1) ? argv[1] : ".";
    printf("Scanning directory: %s\n", directory_to_scan);

    scan_directory(directory_to_scan, signatures, signature_count);

    free(signatures);
    return EXIT_SUCCESS;
}
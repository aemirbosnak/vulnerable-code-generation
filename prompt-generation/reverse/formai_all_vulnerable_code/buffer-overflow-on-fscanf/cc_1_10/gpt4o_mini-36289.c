//GPT-4o-mini DATASET v1.0 Category: Antivirus scanner ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>

#define MAX_PATH 1024
#define MAX_SIGNATURE_LENGTH 50
#define MAX_VIRUS_DEFINITION 100

typedef struct {
    char name[MAX_SIGNATURE_LENGTH];
    char signature[MAX_SIGNATURE_LENGTH];
} VirusSignature;

VirusSignature virus_definitions[MAX_VIRUS_DEFINITION];
int virus_count = 0;

void load_virus_definitions(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening virus definitions file");
        exit(EXIT_FAILURE);
    }
    
    while (fscanf(file, "%s %s", virus_definitions[virus_count].name, virus_definitions[virus_count].signature) == 2) {
        virus_count++;
        if (virus_count >= MAX_VIRUS_DEFINITION) {
            break;
        }
    }
    fclose(file);
}

int scan_file(const char *filepath) {
    FILE *file = fopen(filepath, "rb");
    if (file == NULL) {
        perror("Error opening file for scanning");
        return -1;
    }
    
    unsigned char buffer[512];
    size_t bytesRead;
    int is_infected = 0;

    while ((bytesRead = fread(buffer, 1, sizeof(buffer), file)) > 0) {
        for (int i = 0; i < virus_count; i++) {
            if (strstr((char *) buffer, virus_definitions[i].signature) != NULL) {
                is_infected = 1;
                printf("Infected file: %s with virus: %s\n", filepath, virus_definitions[i].name);
                break;
            }
        }
    }

    fclose(file);
    return is_infected;
}

void scan_directory(const char *directory) {
    DIR *dir = opendir(directory);
    if (dir == NULL) {
        perror("Error opening directory");
        return;
    }

    struct dirent *entry;
    char filepath[MAX_PATH];

    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type == DT_DIR) {
            if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
                snprintf(filepath, sizeof(filepath), "%s/%s", directory, entry->d_name);
                scan_directory(filepath);
            }
        } else {
            snprintf(filepath, sizeof(filepath), "%s/%s", directory, entry->d_name);
            scan_file(filepath);
        }
    }

    closedir(dir);
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <virus_definitions_file> <directory_to_scan>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    load_virus_definitions(argv[1]);
    printf("Loaded %d virus definitions.\n", virus_count);

    scan_directory(argv[2]);

    printf("Scanning completed.\n");
    return 0;
}
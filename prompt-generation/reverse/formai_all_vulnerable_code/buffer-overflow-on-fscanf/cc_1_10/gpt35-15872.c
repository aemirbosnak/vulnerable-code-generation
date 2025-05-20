//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_SIZE 256
#define MAX_VIRUS_SIGNATURES 1024
#define MAX_VIRUS_NAME_SIZE 64

typedef struct {
    char name[MAX_VIRUS_NAME_SIZE];
    unsigned char signature[16];
} VirusSignature;

typedef struct {
    char name[MAX_FILENAME_SIZE];
    int num_viruses;
    VirusSignature *virus_signatures;
} AntivirusDatabase;

AntivirusDatabase database;

void load_database() {
    FILE *file = fopen("database.txt", "r");

    if (!file) {
        printf("Cannot open database file.\n");
        exit(1);
    }

    fscanf(file, "%d\n", &database.num_viruses);
    database.virus_signatures = (VirusSignature*)malloc(sizeof(VirusSignature) * database.num_viruses);

    for (int i = 0; i < database.num_viruses; i++) {
        fscanf(file, "%s %s\n", database.virus_signatures[i].name, database.virus_signatures[i].signature);
    }

    fclose(file);
}

int scan_file(const char *filename) {
    FILE *file = fopen(filename, "rb");

    if (!file) {
        printf("Cannot open file %s.\n", filename);
        return 0;
    }

    unsigned char buffer[4096];
    int bytes_read, num_matches = 0;
    while ((bytes_read = fread(buffer, 1, sizeof(buffer), file)) > 0) {
        for (int i = 0; i < database.num_viruses; i++) {
            for (int j = 0; j < bytes_read - 16; j++) {
                if (memcmp(buffer + j, database.virus_signatures[i].signature, 16) == 0) {
                    printf("Match found in %s: %s\n", filename, database.virus_signatures[i].name);
                    num_matches++;
                    break;
                }
            }
        }
    }

    fclose(file);

    if (num_matches == 0) {
        printf("No viruses found in %s.\n", filename);
    }

    return num_matches;
}

void list_files(const char* dir) {
    printf("Looking for files in %s...\n", dir);
    // Implement file searching logic here
    printf("Done.\n");
}

int main() {
    load_database();

    while (1) {
        printf("Choose an option:\n");
        printf("1. Scan file\n");
        printf("2. List files in a directory\n");
        printf("3. Exit\n");
        printf("Option: ");

        int option;
        scanf("%d", &option);

        switch (option) {
            case 1: {
                printf("Enter filename: ");
                char filename[MAX_FILENAME_SIZE];
                scanf("%s", filename);
                scan_file(filename);
                break;
            }
            case 2: {
                printf("Enter directory: ");
                char dir[MAX_FILENAME_SIZE];
                scanf("%s", dir);
                list_files(dir);
                break;
            }
            case 3: {
                printf("Goodbye!\n");
                return 0;
            }
            default: {
                printf("Invalid option.\n");
                break;
            }
        }
        printf("\n");
    }

    return 0;
}
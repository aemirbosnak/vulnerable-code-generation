//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: all-encompassing
#include <stdio.h>
#include <string.h>

#define MAX_FILES 50
#define MAX_FILENAME 50
#define MAX_VIRUS_SIGNATURE 100

int scan_file(char* filename, char* virus_signature);
void report_virus(char* filename, char* virus_signature);

int main() {
    char filenames[MAX_FILES][MAX_FILENAME];
    char virus_signatures[MAX_VIRUS_SIGNATURE][MAX_FILENAME];
    int file_count = 0, virus_count = 0;

    // get files to scan
    printf("Enter filenames to scan (enter 'stop' to stop):\n");
    char input[MAX_FILENAME];
    while (strcmp(input, "stop") != 0 && file_count < MAX_FILES) {
        scanf("%s", input);
        if (strcmp(input, "stop") != 0) {
            strcpy(filenames[file_count], input);
            file_count++;
        }
    }

    // get virus signatures
    printf("Enter virus signatures (enter 'stop' to stop):\n");
    while (strcmp(input, "stop") != 0 && virus_count < MAX_VIRUS_SIGNATURE) {
        scanf("%s", input);
        if (strcmp(input, "stop") != 0) {
            strcpy(virus_signatures[virus_count], input);
            virus_count++;
        }
    }

    // scan files for viruses
    printf("Scanning for viruses...\n");
    for (int i = 0; i < file_count; i++) {
        for (int j = 0; j < virus_count; j++) {
            if (scan_file(filenames[i], virus_signatures[j]) == 1) {
                report_virus(filenames[i], virus_signatures[j]);
            }
        }
    }

    printf("Scan complete.\n");

    return 0;
}

// scan file for given virus signature
int scan_file(char* filename, char* virus_signature) {
    FILE* file = fopen(filename, "r");
    char line[256];

    while (fgets(line, sizeof(line), file)) {
        if (strstr(line, virus_signature) != NULL) {
            fclose(file);
            return 1;
        }   
    }
    fclose(file);
    return 0;
}

// report virus found in file
void report_virus(char* filename, char* virus_signature) {
    printf("Virus found in %s: %s\n", filename, virus_signature);
}
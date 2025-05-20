//Falcon-180B DATASET v1.0 Category: Antivirus scanner ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

#define MAX_FILE_NAME 256
#define MAX_VIRUS_NAME 256

typedef struct {
    char *name;
    char *signature;
} virus;

virus viruses[] = {
    {"Cascade", "CAAA"},
    {"Jerusalem", "AABBC"},
    {"Stoned", "AADDA"},
    {"Form", "AAEAA"},
    {"Dir-2", "AAEEA"},
    {"Flock", "AAFFA"}
};

int num_viruses = sizeof(viruses) / sizeof(virus);

void scan_file(char *file_name) {
    FILE *fp;
    char buffer[1024];
    int file_size = 0;
    int virus_found = 0;

    fp = fopen(file_name, "rb");
    if (fp == NULL) {
        printf("Error: Could not open file %s\n", file_name);
        return;
    }

    while (fread(buffer, 1, 1024, fp) > 0) {
        file_size += 1024;
    }

    for (int i = 0; i < num_viruses; i++) {
        virus *current_virus = &viruses[i];
        int j;
        for (j = 0; j < strlen(current_virus->signature); j++) {
            char c = tolower(buffer[j]);
            if (c!= current_virus->signature[j]) {
                break;
            }
        }
        if (j == strlen(current_virus->signature)) {
            printf("Virus found: %s\n", current_virus->name);
            virus_found = 1;
            break;
        }
    }

    if (!virus_found) {
        printf("No viruses found in %s\n", file_name);
    }

    fclose(fp);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <file_name>\n", argv[0]);
        return 1;
    }

    char file_name[MAX_FILE_NAME];
    strcpy(file_name, argv[1]);

    scan_file(file_name);

    return 0;
}
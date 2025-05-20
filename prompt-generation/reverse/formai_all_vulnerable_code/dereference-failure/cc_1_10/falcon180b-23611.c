//Falcon-180B DATASET v1.0 Category: Antivirus scanner ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_FILE_SIZE (10 * 1024 * 1024) // 10 MB
#define MAX_VIRUS_NAME_LENGTH 256
#define MAX_VIRUS_PATTERN_LENGTH 1024

typedef struct {
    char name[MAX_VIRUS_NAME_LENGTH];
    char pattern[MAX_VIRUS_PATTERN_LENGTH];
} virus_t;

void read_viruses(const char* filename, virus_t* viruses, int* count) {
    FILE* fp = fopen(filename, "r");
    if (!fp) {
        printf("Error: could not open virus database file.\n");
        exit(1);
    }

    char line[1024];
    int lineno = 0;
    while (fgets(line, sizeof(line), fp)) {
        lineno++;

        // Skip empty lines and comments
        if (line[0] == '#' || line[0] == '\n') {
            continue;
        }

        // Parse virus name and pattern
        char* name = strtok(line, ":");
        char* pattern = strtok(NULL, ":");
        if (!name ||!pattern) {
            printf("Error: invalid virus definition on line %d.\n", lineno);
            exit(1);
        }

        // Copy virus name and pattern
        strncpy(viruses[(*count)].name, name, MAX_VIRUS_NAME_LENGTH - 1);
        strncpy(viruses[(*count)].pattern, pattern, MAX_VIRUS_PATTERN_LENGTH - 1);
        viruses[(*count)++].name[MAX_VIRUS_NAME_LENGTH - 1] = '\0';
        viruses[(*count) - 1].pattern[MAX_VIRUS_PATTERN_LENGTH - 1] = '\0';
    }

    fclose(fp);
}

int scan_file(const char* filename, virus_t* viruses, int count) {
    FILE* fp = fopen(filename, "r");
    if (!fp) {
        printf("Error: could not open file '%s'.\n", filename);
        return 1;
    }

    char buffer[MAX_FILE_SIZE];
    int buflen = 0;
    while (fread(buffer + buflen, 1, MAX_FILE_SIZE - buflen, fp) > 0) {
        buflen += fread(buffer + buflen, 1, MAX_FILE_SIZE - buflen, fp);
    }

    fclose(fp);

    int i;
    for (i = 0; i < count; i++) {
        char* virus_pattern = viruses[i].pattern;
        char* file_buffer = buffer;
        while ((file_buffer = strstr(file_buffer, virus_pattern))!= NULL) {
            printf("Virus '%s' found in file '%s'.\n", viruses[i].name, filename);
            return 1;
        }
    }

    return 0;
}

int main(int argc, char* argv[]) {
    if (argc < 3) {
        printf("Usage: %s <virus_database_file> <file_to_scan>\n", argv[0]);
        return 1;
    }

    virus_t viruses[100];
    int virus_count = 0;
    read_viruses(argv[1], viruses, &virus_count);

    int result = scan_file(argv[2], viruses, virus_count);
    if (result == 0) {
        printf("File '%s' is clean.\n", argv[2]);
    }

    return result;
}
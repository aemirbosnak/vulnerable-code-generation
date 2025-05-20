//Falcon-180B DATASET v1.0 Category: Antivirus scanner ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_VIRUS_SIGNATURES 100
#define MAX_VIRUS_NAME_LENGTH 50
#define MAX_FILE_SIZE 1000000

typedef struct {
    char name[MAX_VIRUS_NAME_LENGTH];
    char signature[MAX_VIRUS_SIGNATURES];
} virus_t;

void load_virus_signatures(virus_t *viruses) {
    // Load virus signatures from a file or hardcode them here
}

bool scan_file(const char *filename, virus_t *viruses) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        printf("Error: Could not open file '%s'\n", filename);
        return false;
    }

    char buffer[MAX_FILE_SIZE];
    size_t bytes_read = fread(buffer, 1, MAX_FILE_SIZE, file);
    if (ferror(file)) {
        printf("Error: Could not read file '%s'\n", filename);
        fclose(file);
        return false;
    }

    for (int i = 0; i < MAX_VIRUS_SIGNATURES; i++) {
        if (strstr(buffer, viruses[i].signature)) {
            printf("Virus found: %s\n", viruses[i].name);
            fclose(file);
            return true;
        }
    }

    fclose(file);
    return false;
}

int main() {
    virus_t viruses[MAX_VIRUS_SIGNATURES];
    load_virus_signatures(viruses);

    char filename[100];
    printf("Enter filename to scan: ");
    scanf("%s", filename);

    if (scan_file(filename, viruses)) {
        printf("File is infected with a virus.\n");
    } else {
        printf("File is clean.\n");
    }

    return 0;
}
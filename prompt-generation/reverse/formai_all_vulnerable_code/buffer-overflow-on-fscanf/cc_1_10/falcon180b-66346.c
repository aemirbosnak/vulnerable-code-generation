//Falcon-180B DATASET v1.0 Category: Antivirus scanner ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_FILE_SIZE (1024 * 1024 * 10) // 10 MB
#define MAX_VIRUS_NAME_LENGTH 256
#define MAX_VIRUS_SIGNATURE_LENGTH 1024

typedef struct {
    char name[MAX_VIRUS_NAME_LENGTH];
    char signature[MAX_VIRUS_SIGNATURE_LENGTH];
} virus_t;

int load_virus_database(virus_t *database, int count) {
    FILE *fp = fopen("virus_database.txt", "r");
    if (fp == NULL) {
        printf("Error: could not open virus database file.\n");
        return -1;
    }

    int i = 0;
    while (i < count && fscanf(fp, "%s %s", database[i].name, database[i].signature) == 2) {
        i++;
    }

    fclose(fp);
    return i;
}

int scan_file(const char *filename, virus_t *database, int count) {
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error: could not open file '%s'.\n", filename);
        return -1;
    }

    unsigned char buffer[MAX_FILE_SIZE];
    size_t bytes_read = 0;
    while ((bytes_read = fread(buffer, 1, MAX_FILE_SIZE, fp)) > 0) {
        for (int i = 0; i < count; i++) {
            virus_t *virus = &database[i];
            size_t signature_length = strlen(virus->signature);
            for (size_t j = 0; j <= bytes_read - signature_length; j++) {
                if (memcmp(buffer + j, virus->signature, signature_length) == 0) {
                    printf("Virus found: %s\n", virus->name);
                    return 1;
                }
            }
        }
    }

    fclose(fp);
    return 0;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <file>\n", argv[0]);
        return 1;
    }

    virus_t database[10];
    int count = load_virus_database(database, 10);
    if (count <= 0) {
        return 1;
    }

    int result = scan_file(argv[1], database, count);
    if (result == 0) {
        printf("No viruses found.\n");
    }

    return 0;
}
//GEMINI-pro DATASET v1.0 Category: Antivirus scanner ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE 1024 * 1024
#define MAX_VIRUS_SIGNATURE_COUNT 10

typedef struct {
    char *name;
    char *signature;
    int signature_length;
} VirusSignature;

VirusSignature virus_signatures[MAX_VIRUS_SIGNATURE_COUNT];

int load_virus_signatures(char *filename) {
    FILE *fp;
    int i, count;

    fp = fopen(filename, "r");
    if (fp == NULL) {
        fprintf(stderr, "Error opening virus signature file: %s\n", filename);
        return -1;
    }

    count = 0;
    while (fscanf(fp, "%s %s\n", virus_signatures[count].name, virus_signatures[count].signature) != EOF) {
        virus_signatures[count].signature_length = strlen(virus_signatures[count].signature);
        count++;
    }

    fclose(fp);

    return count;
}

int scan_file(char *filename) {
    FILE *fp;
    char buffer[MAX_FILE_SIZE];
    int i, j, found;

    fp = fopen(filename, "rb");
    if (fp == NULL) {
        fprintf(stderr, "Error opening file: %s\n", filename);
        return -1;
    }

    fread(buffer, 1, MAX_FILE_SIZE, fp);
    fclose(fp);

    found = 0;
    for (i = 0; i < MAX_VIRUS_SIGNATURE_COUNT; i++) {
        for (j = 0; j < MAX_FILE_SIZE - virus_signatures[i].signature_length; j++) {
            if (memcmp(&buffer[j], virus_signatures[i].signature, virus_signatures[i].signature_length) == 0) {
                printf("Virus found: %s\n", virus_signatures[i].name);
                found = 1;
            }
        }
    }

    if (!found) {
        printf("No virus found\n");
    }

    return 0;
}

int main(int argc, char *argv[]) {
    int i, virus_signature_count;

    if (argc < 3) {
        fprintf(stderr, "Usage: %s <virus signature file> <file to scan>\n", argv[0]);
        return -1;
    }

    virus_signature_count = load_virus_signatures(argv[1]);
    if (virus_signature_count < 0) {
        return -1;
    }

    for (i = 0; i < virus_signature_count; i++) {
        printf("Virus %d: %s\n", i + 1, virus_signatures[i].name);
    }

    scan_file(argv[2]);

    return 0;
}
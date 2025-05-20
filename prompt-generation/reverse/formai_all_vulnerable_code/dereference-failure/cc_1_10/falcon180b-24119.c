//Falcon-180B DATASET v1.0 Category: Antivirus scanner ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define VIRUS_COUNT 5
#define FILE_SIZE 1024

typedef struct {
    char name[20];
    char signature[20];
} virus;

virus viruses[VIRUS_COUNT] = {
    {"mydoom", "KUKU"},
    {"codered", "HLLW"},
    {"sasser", "FTP"},
    {"iloveyou", "LOVE"},
    {"zbot", "BANK"}
};

void scan_file(FILE *fp, virus *viruses) {
    char buffer[FILE_SIZE];
    int i, j;

    while (fread(buffer, sizeof(char), FILE_SIZE, fp)!= 0) {
        for (i = 0; i < VIRUS_COUNT; i++) {
            for (j = 0; j < strlen(viruses[i].signature); j++) {
                if (buffer[j]!= viruses[i].signature[j]) {
                    break;
                }
            }
            if (j == strlen(viruses[i].signature)) {
                printf("Virus found: %s\n", viruses[i].name);
                exit(1);
            }
        }
    }
}

int main(int argc, char *argv[]) {
    FILE *fp;
    int i;

    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    fp = fopen(argv[1], "rb");
    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    printf("Scanning file...\n");
    scan_file(fp, viruses);

    printf("No virus found.\n");
    fclose(fp);
    exit(0);
}
//Falcon-180B DATASET v1.0 Category: Antivirus scanner ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_VIRUSES 5

typedef struct virus_t {
    char *name;
    char *signature;
} virus_t;

virus_t viruses[NUM_VIRUSES] = {
    {"Happy Virus", "HV1234"},
    {"Joyful Worm", "JW5678"},
    {"Cheerful Trojan", "CT9012"},
    {"Gleeful Adware", "GA3456"},
    {"Merry Ransomware", "MR7890"}
};

int scan_file(char *filename) {
    FILE *file;
    char line[1024];
    int i, j;

    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: could not open file %s\n", filename);
        return 1;
    }

    while (fgets(line, sizeof(line), file)!= NULL) {
        for (i = 0; i < NUM_VIRUSES; i++) {
            for (j = 0; j < strlen(viruses[i].signature); j++) {
                if (line[j]!= viruses[i].signature[j]) {
                    break;
                }
            }
            if (j == strlen(viruses[i].signature)) {
                printf("Virus found: %s\n", viruses[i].name);
                return 1;
            }
        }
    }

    fclose(file);
    return 0;
}

int main(int argc, char *argv[]) {
    int i;

    printf("Welcome to the Happy Antivirus Scanner!\n\n");

    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    for (i = 0; i < NUM_VIRUSES; i++) {
        printf("Scanning for %s...\n", viruses[i].name);
    }

    if (scan_file(argv[1]) == 0) {
        printf("\nNo viruses found. Your computer is happy and healthy!\n");
    }

    return 0;
}
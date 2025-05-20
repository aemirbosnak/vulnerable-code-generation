//Falcon-180B DATASET v1.0 Category: Antivirus scanner ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_VIRUS_LENGTH 1024
#define MAX_FILE_SIZE (1024 * 1024) // 1 MB

typedef struct {
    char name[MAX_VIRUS_LENGTH];
    int length;
    char pattern[MAX_VIRUS_LENGTH];
} virus_t;

virus_t viruses[] = {
    {"WannaCry", 7, "WannaCry"},
    {"Locky", 5, "Locky"},
    {"Petya", 5, "Petya"},
    {"NotPetya", 8, "NotPetya"}
};

int num_viruses = sizeof(viruses) / sizeof(virus_t);

int is_virus(FILE *file) {
    char buffer[MAX_FILE_SIZE];
    int i, j, k;

    rewind(file);
    fseek(file, 0, SEEK_END);
    int file_size = ftell(file);

    if (file_size > MAX_FILE_SIZE) {
        printf("File is too large.\n");
        return 0;
    }

    rewind(file);
    fread(buffer, 1, file_size, file);

    for (i = 0; i < num_viruses; i++) {
        for (j = 0; j < file_size - viruses[i].length; j++) {
            for (k = 0; k < viruses[i].length; k++) {
                if (tolower(buffer[j + k])!= tolower(viruses[i].pattern[k])) {
                    break;
                }
            }
            if (k == viruses[i].length) {
                printf("Possible %s infection found.\n", viruses[i].name);
                return 1;
            }
        }
    }

    printf("No viruses found.\n");
    return 0;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <file>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "rb");

    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    is_virus(file);

    fclose(file);
    return 0;
}
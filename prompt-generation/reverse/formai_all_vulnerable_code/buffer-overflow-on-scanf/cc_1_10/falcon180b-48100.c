//Falcon-180B DATASET v1.0 Category: Antivirus scanner ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define VIRUS_COUNT 3

typedef struct {
    char *name;
    char *signature;
} virus_t;

virus_t viruses[VIRUS_COUNT] = {
    {"Happy Virus", "HV"},
    {"Sad Virus", "SV"},
    {"Confused Virus", "CV"}
};

int scan_file(FILE *file, virus_t *viruses) {
    char buffer[1024];
    int i, j;

    while (fgets(buffer, sizeof(buffer), file)!= NULL) {
        for (i = 0; i < VIRUS_COUNT; i++) {
            for (j = 0; j < strlen(viruses[i].signature); j++) {
                if (buffer[j]!= viruses[i].signature[j]) {
                    break;
                }
            }

            if (j == strlen(viruses[i].signature)) {
                printf("Virus found: %s\n", viruses[i].name);
                return 1;
            }
        }
    }

    return 0;
}

int main() {
    FILE *file;
    char filename[256];

    printf("Enter filename: ");
    scanf("%s", filename);

    file = fopen(filename, "r");

    if (file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    scan_file(file, viruses);

    fclose(file);

    return 0;
}
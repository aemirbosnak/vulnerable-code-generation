//Falcon-180B DATASET v1.0 Category: Antivirus scanner ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define VIRUS_COUNT 10
#define VIRUS_NAMES {"I Love You", "Melissa", "Mydoom", "Slammer", "CodeRed", "Nimda", "Blaster", "Sasser", "Conficker", "WannaCry"}

typedef struct {
    char name[50];
    int length;
    char signature[100];
} Virus;

Virus viruses[VIRUS_COUNT] = {{"I Love You", 26, "ILoveYou"}, {"Melissa", 29, "MMM"}, {"Mydoom", 40, "MMM"}, {"Slammer", 37, "Slammer"}, {"CodeRed", 31, "CodeRed"}, {"Nimda", 31, "Nimda"}, {"Blaster", 42, "Blaster"}, {"Sasser", 36, "Sasser"}, {"Conficker", 67, "Conficker"}, {"WannaCry", 67, "WannaCry"}};

int scan_file(char *filename) {
    FILE *file;
    char buffer[1024];
    int i, j, k;

    file = fopen(filename, "rb");
    if (file == NULL) {
        printf("Error opening file %s\n", filename);
        return 1;
    }

    while (fread(buffer, sizeof(char), sizeof(buffer), file) > 0) {
        for (i = 0; i < VIRUS_COUNT; i++) {
            for (j = 0; j < viruses[i].length - 1; j++) {
                for (k = 0; k < strlen(buffer) - viruses[i].length + j; k++) {
                    if (strncmp(&buffer[k], viruses[i].signature, viruses[i].length) == 0) {
                        printf("Virus %s found in file %s\n", viruses[i].name, filename);
                        return 1;
                    }
                }
            }
        }
    }

    fclose(file);
    return 0;
}

int main(int argc, char *argv[]) {
    int i;

    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    for (i = 0; i < strlen(argv[1]); i++) {
        if (!isalpha(argv[1][i])) {
            printf("Error: Invalid filename\n");
            return 1;
        }
    }

    scan_file(argv[1]);

    return 0;
}
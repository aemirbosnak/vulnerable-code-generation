//Falcon-180B DATASET v1.0 Category: Antivirus scanner ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define VIRUS_COUNT 5
#define FILE_SIZE 1024

typedef struct {
    char name[100];
    unsigned char signature[FILE_SIZE];
} virus;

virus viruses[VIRUS_COUNT] = {
    {"MyDoom", "\x5A\x4D\x49\x43\x52\x4F\x53\x5F\x50\x4E\x47\x50\x52\x4F\x47\x52\x41\x4D"},
    {"W32.Stration", "\x4D\x5A\x90\x00\x03\x00\x00\x00\x04\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00"},
    {"ILOVEYOU", "\x2E\x65\x78\x65\x20\x6C\x6F\x76\x65\x20\x6C\x65\x74\x74\x65\x72\x20\x66\x6F"},
    {"Melissa", "\x52\x6F\x63\x6B\x65\x74\x20\x53\x65\x63\x72\x65\x74\x20\x4B\x65\x65\x70"},
    {"CodeRed", "\x43\x6F\x64\x65\x52\x65\x64\x20\x45\x6D\x65\x72\x67\x65\x6E\x63\x79"}
};

int is_infected(FILE *file) {
    char buffer[FILE_SIZE];
    unsigned int i;

    for (i = 0; i < VIRUS_COUNT; i++) {
        fseek(file, 0, SEEK_SET);
        fread(buffer, 1, FILE_SIZE, file);

        if (memcmp(buffer, viruses[i].signature, FILE_SIZE) == 0) {
            printf("Virus found: %s\n", viruses[i].name);
            return 1;
        }
    }

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

    int infected = is_infected(file);

    if (infected) {
        return 1;
    }

    printf("No virus found.\n");
    return 0;
}
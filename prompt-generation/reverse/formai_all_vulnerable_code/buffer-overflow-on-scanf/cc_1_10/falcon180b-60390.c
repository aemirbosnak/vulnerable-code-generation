//Falcon-180B DATASET v1.0 Category: Antivirus scanner ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define VIRUS_COUNT 5
#define FILE_EXTENSION_COUNT 3

typedef struct {
    char *name;
    char *extension;
} File;

typedef struct {
    char *name;
    int dangerous;
} Virus;

File files[FILE_EXTENSION_COUNT] = {{"example.exe", ".exe"},
                                     {"picture.jpg", ".jpg"},
                                     {"document.docx", ".docx"}};

Virus viruses[VIRUS_COUNT] = {{"Trojan", 1},
                              {"Worm", 1},
                              {"Ransomware", 1},
                              {"Adware", 0},
                              {"Spyware", 0}};

int is_dangerous(char *filename) {
    int i;
    for (i = 0; i < VIRUS_COUNT; i++) {
        if (strcmp(filename, viruses[i].name) == 0) {
            return viruses[i].dangerous;
        }
    }
    return 0;
}

int main() {
    int i, j;
    char input_filename[100];

    printf("Welcome to the surrealist antivirus scanner!\n");
    printf("Please enter the name of the file you want to scan: ");
    scanf("%s", input_filename);

    for (i = 0; i < FILE_EXTENSION_COUNT; i++) {
        if (strcmp(input_filename + strlen(input_filename) - 4, files[i].extension) == 0) {
            printf("Scanning %s for viruses...\n", input_filename);
            for (j = 0; j < VIRUS_COUNT; j++) {
                if (is_dangerous(input_filename)) {
                    printf("Warning! %s detected in %s!\n", viruses[j].name, input_filename);
                }
            }
            break;
        }
    }

    if (i == FILE_EXTENSION_COUNT) {
        printf("File extension not supported.\n");
    }

    return 0;
}
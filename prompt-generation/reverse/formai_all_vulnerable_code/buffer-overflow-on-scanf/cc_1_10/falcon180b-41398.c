//Falcon-180B DATASET v1.0 Category: Antivirus scanner ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VIRUS_SIZE 256
#define MAX_FILE_SIZE 1024

typedef struct {
    char name[MAX_VIRUS_SIZE];
    char signature[MAX_VIRUS_SIZE];
} virus_t;

virus_t viruses[] = {
    {"MyDoom", "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789"},
    {"ILOVEYOU", "ILOVEYOU"},
    {"Conficker", "A"},
    {"Stuxnet", "B"},
    {"WannaCry", "C"}
};

int num_viruses = sizeof(viruses) / sizeof(virus_t);

int is_virus(FILE *file, virus_t virus) {
    char buffer[MAX_FILE_SIZE];
    int size = fread(buffer, 1, MAX_FILE_SIZE, file);

    if (size < MAX_VIRUS_SIZE) {
        return 0;
    }

    char *signature = strstr(buffer, virus.signature);

    if (signature == NULL) {
        return 0;
    }

    return 1;
}

int main() {
    char filename[MAX_VIRUS_SIZE];

    printf("Enter the file name to scan: ");
    scanf("%s", filename);

    FILE *file = fopen(filename, "rb");

    if (file == NULL) {
        printf("Error: file not found.\n");
        exit(1);
    }

    int virus_found = 0;

    for (int i = 0; i < num_viruses; i++) {
        if (is_virus(file, viruses[i])) {
            printf("Virus found: %s\n", viruses[i].name);
            virus_found = 1;
        }
    }

    if (!virus_found) {
        printf("No virus found.\n");
    }

    fclose(file);

    return 0;
}
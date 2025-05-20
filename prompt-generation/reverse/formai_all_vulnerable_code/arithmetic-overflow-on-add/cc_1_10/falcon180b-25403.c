//Falcon-180B DATASET v1.0 Category: Antivirus scanner ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VIRUSES 10
#define MAX_VIRUS_LENGTH 100

typedef struct {
    char name[MAX_VIRUS_LENGTH];
    char signature[MAX_VIRUS_LENGTH];
} virus;

virus viruses[MAX_VIRUSES] = {
    {"MyDoom", "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789"},
    {"Sasser", "sasser"},
    {"Code Red", "code red"},
    {"I Love You", "love"},
    {"Stuxnet", "stuxnet"},
    {"WannaCry", "WannaCry"},
    {"Locky", "Locky"},
    {"Petya", "Petya"},
    {"WannaCrypt", "WannaCrypt"},
    {"NotPetya", "NotPetya"}
};

int findVirus(char *data, int length) {
    int i = 0;
    while (i < MAX_VIRUSES) {
        if (strstr(data, viruses[i].signature)) {
            printf("\nVirus found: %s\n", viruses[i].name);
            return 1;
        }
        i++;
    }
    return 0;
}

int main() {
    char filename[100];
    printf("\nEnter filename: ");
    scanf("%s", filename);

    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        printf("\nError opening file.\n");
        exit(1);
    }

    fseek(file, 0, SEEK_END);
    int filesize = ftell(file);
    fseek(file, 0, SEEK_SET);

    char *data = (char *) malloc(filesize + 1);
    fread(data, filesize, 1, file);
    data[filesize] = '\0';

    int virusFound = findVirus(data, filesize);

    if (virusFound == 0) {
        printf("\nNo virus found.\n");
    }

    free(data);
    fclose(file);

    return 0;
}
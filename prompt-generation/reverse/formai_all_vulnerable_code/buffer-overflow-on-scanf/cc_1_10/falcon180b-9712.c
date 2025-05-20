//Falcon-180B DATASET v1.0 Category: Antivirus scanner ; Style: medieval
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
    {"Trojan", "TRJ"},
    {"Worm", "WORM"},
    {"Backdoor", "BKDR"},
    {"Adware", "ADW"},
    {"Spyware", "SPY"}
};

int scan_file(FILE *file, virus *viruses) {
    char buffer[FILE_SIZE];
    int virus_found = 0;

    while (fread(buffer, 1, FILE_SIZE, file)!= 0) {
        for (int i = 0; i < VIRUS_COUNT; i++) {
            if (strstr(buffer, viruses[i].signature)!= NULL) {
                printf("Virus found: %s\n", viruses[i].name);
                virus_found = 1;
                break;
            }
        }
    }

    return virus_found;
}

int main() {
    char file_name[50];

    printf("Enter the file name to scan: ");
    scanf("%s", file_name);

    FILE *file = fopen(file_name, "rb");

    if (file == NULL) {
        printf("File not found.\n");
        return 1;
    }

    int virus_found = scan_file(file, viruses);

    if (virus_found == 0) {
        printf("No virus found.\n");
    }

    fclose(file);
    return 0;
}
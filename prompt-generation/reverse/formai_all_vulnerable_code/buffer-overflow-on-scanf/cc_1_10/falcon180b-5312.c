//Falcon-180B DATASET v1.0 Category: Antivirus scanner ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VIRUSES 10
#define MAX_VIRUS_NAME_LENGTH 50
#define MAX_FILE_NAME_LENGTH 100

typedef struct {
    char name[MAX_VIRUS_NAME_LENGTH];
    char signature[MAX_FILE_NAME_LENGTH];
} virus_t;

virus_t viruses[MAX_VIRUSES];

int num_viruses = 0;

void add_virus(char* name, char* signature) {
    if (num_viruses >= MAX_VIRUSES) {
        printf("Error: Maximum number of viruses reached.\n");
        return;
    }

    strcpy(viruses[num_viruses].name, name);
    strcpy(viruses[num_viruses].signature, signature);

    num_viruses++;
}

int scan_file(char* file_name) {
    FILE* file = fopen(file_name, "rb");

    if (file == NULL) {
        printf("Error: Could not open file %s.\n", file_name);
        return -1;
    }

    char buffer[MAX_FILE_NAME_LENGTH];
    int file_size = 0;

    while (fread(buffer, 1, MAX_FILE_NAME_LENGTH, file) > 0) {
        file_size += strlen(buffer);
    }

    fclose(file);

    int i;
    for (i = 0; i < num_viruses; i++) {
        if (strstr(buffer, viruses[i].signature)!= NULL) {
            printf("Virus found: %s\n", viruses[i].name);
            return i;
        }
    }

    printf("No virus found.\n");
    return -1;
}

int main() {
    add_virus("WannaCry", "WNCRY");
    add_virus("Locky", "LOCKY");

    char file_name[MAX_FILE_NAME_LENGTH];
    printf("Enter file name to scan: ");
    scanf("%s", file_name);

    int result = scan_file(file_name);

    if (result >= 0) {
        printf("Virus name: %s\n", viruses[result].name);
    }

    return 0;
}
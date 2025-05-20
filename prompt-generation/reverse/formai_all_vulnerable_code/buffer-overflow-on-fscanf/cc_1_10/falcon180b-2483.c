//Falcon-180B DATASET v1.0 Category: Antivirus scanner ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_VIRUS_SIGNATURES 1000
#define MAX_VIRUS_NAME_LENGTH 100

typedef struct {
    char name[MAX_VIRUS_NAME_LENGTH];
    char signature[MAX_VIRUS_SIGNATURES];
} Virus;

int main() {
    FILE *virus_database = fopen("virus_database.txt", "r");
    if (virus_database == NULL) {
        printf("Error: could not open virus database file.\n");
        return 1;
    }

    int num_viruses = 0;
    Virus *viruses = malloc(sizeof(Virus));

    while (fscanf(virus_database, "%s %s", viruses[num_viruses].name, viruses[num_viruses].signature)!= EOF) {
        num_viruses++;
        viruses = realloc(viruses, sizeof(Virus) * num_viruses);
    }

    fclose(virus_database);

    char *file_contents = malloc(1000000);
    FILE *file = fopen("file_to_scan.txt", "r");
    if (file == NULL) {
        printf("Error: could not open file to scan.\n");
        free(file_contents);
        return 1;
    }

    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    rewind(file);

    fread(file_contents, file_size, 1, file);
    fclose(file);

    int virus_count = 0;
    for (int i = 0; i < num_viruses; i++) {
        char *signature_ptr = viruses[i].signature;
        char *file_ptr = file_contents;

        while (*file_ptr!= '\0' && *signature_ptr!= '\0') {
            if (tolower(*file_ptr) == tolower(*signature_ptr)) {
                signature_ptr++;
            } else {
                signature_ptr = viruses[i].signature;
                file_ptr++;
            }
        }

        if (*signature_ptr == '\0') {
            printf("Virus found: %s\n", viruses[i].name);
            virus_count++;
        }
    }

    if (virus_count == 0) {
        printf("No viruses found.\n");
    }

    free(file_contents);
    free(viruses);

    return 0;
}
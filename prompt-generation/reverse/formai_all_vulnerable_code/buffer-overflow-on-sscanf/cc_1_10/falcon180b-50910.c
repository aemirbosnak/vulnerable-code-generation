//Falcon-180B DATASET v1.0 Category: Antivirus scanner ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_VIRUSES 100
#define MAX_VIRUS_NAME 50
#define MAX_FILE_NAME 100

typedef struct {
    char name[MAX_VIRUS_NAME];
    char signature[MAX_FILE_NAME];
} Virus;

Virus viruses[MAX_VIRUSES];
int num_viruses;

void load_viruses() {
    FILE *file = fopen("viruses.txt", "r");
    if (file == NULL) {
        printf("Error: could not open viruses file.\n");
        exit(1);
    }

    char line[MAX_FILE_NAME];
    while (fgets(line, sizeof(line), file)!= NULL) {
        Virus virus;
        sscanf(line, "%s %s", virus.name, virus.signature);
        strcpy(virus.name, toupper(virus.name));
        strcpy(virus.signature, toupper(virus.signature));
        viruses[num_viruses++] = virus;
    }

    fclose(file);
}

bool scan_file(const char *filename, const Virus *virus) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: could not open file '%s'.\n", filename);
        return false;
    }

    char line[MAX_FILE_NAME];
    while (fgets(line, sizeof(line), file)!= NULL) {
        int i, j;
        for (i = 0; i < strlen(line) - strlen(virus->signature) + 1; i++) {
            for (j = 0; j < strlen(virus->signature); j++) {
                if (tolower(line[i + j])!= virus->signature[j]) {
                    break;
                }
            }
            if (j == strlen(virus->signature)) {
                printf("Virus '%s' found in file '%s'.\n", virus->name, filename);
                fclose(file);
                return true;
            }
        }
    }

    fclose(file);
    return false;
}

int main() {
    load_viruses();

    char filename[MAX_FILE_NAME];
    printf("Enter file name to scan: ");
    scanf("%s", filename);

    int i;
    for (i = 0; i < num_viruses; i++) {
        if (scan_file(filename, &viruses[i])) {
            break;
        }
    }

    if (i == num_viruses) {
        printf("No viruses found in file '%s'.\n", filename);
    }

    return 0;
}
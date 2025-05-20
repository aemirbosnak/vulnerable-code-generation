//Falcon-180B DATASET v1.0 Category: Antivirus scanner ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_VIRUSES 100
#define MAX_VIRUS_NAME_LEN 100
#define MAX_FILE_NAME_LEN 100

typedef struct {
    char name[MAX_VIRUS_NAME_LEN];
    char signature[MAX_VIRUS_NAME_LEN];
} Virus;

Virus viruses[MAX_VIRUSES];
int num_viruses;

void load_viruses() {
    FILE *fp = fopen("viruses.txt", "r");
    if (fp == NULL) {
        printf("Error: could not open viruses.txt\n");
        exit(1);
    }

    char line[MAX_VIRUS_NAME_LEN];
    while (fgets(line, MAX_VIRUS_NAME_LEN, fp)!= NULL) {
        char *name = strtok(line, ",");
        char *signature = strtok(NULL, ",");

        if (name == NULL || signature == NULL) {
            printf("Error: malformed line in viruses.txt\n");
            exit(1);
        }

        strcpy(viruses[num_viruses].name, name);
        strcpy(viruses[num_viruses].signature, signature);
        num_viruses++;
    }

    fclose(fp);
}

bool scan_file(char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: could not open file %s\n", filename);
        return false;
    }

    char line[MAX_FILE_NAME_LEN];
    while (fgets(line, MAX_FILE_NAME_LEN, fp)!= NULL) {
        for (int i = 0; i < num_viruses; i++) {
            if (strstr(line, viruses[i].signature)!= NULL) {
                printf("Virus found in file %s: %s\n", filename, viruses[i].name);
                return true;
            }
        }
    }

    fclose(fp);
    return false;
}

int main() {
    load_viruses();

    char filename[MAX_FILE_NAME_LEN];
    printf("Enter filename to scan: ");
    scanf("%s", filename);

    if (scan_file(filename)) {
        return 1;
    } else {
        printf("No viruses found in file %s\n", filename);
        return 0;
    }
}
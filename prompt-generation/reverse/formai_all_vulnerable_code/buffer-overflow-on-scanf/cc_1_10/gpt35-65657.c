//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: single-threaded
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 50
#define MAX_FILENAME 20
#define MAX_VIRUS_SIGNATURE 50

typedef struct {
    char virus_signature[MAX_VIRUS_SIGNATURE];
} virus;

virus database[MAX_FILES];

bool scan_file(char *filename) {
    FILE *fp = fopen(filename, "r");
    char line[100];
    if (fp == NULL) {
        printf("Error opening file: %s\n", filename);
        return false;
    }
    while (fgets(line, sizeof(line), fp)) {
        for (int i = 0; i < MAX_FILES; i++) {
            if (strstr(line, database[i].virus_signature)) {
                printf("File '%s' is infected with virus: %s\n", filename, database[i].virus_signature);
                fclose(fp);
                return true;
            }
        }
    }
    fclose(fp);
    return false;
}

void load_database() {
    virus v1 = {"virus1"};
    virus v2 = {"virus2"};
    virus v3 = {"virus3"};
    virus v4 = {"virus4"};
    virus v5 = {"virus5"};
    
    database[0] = v1;
    database[1] = v2;
    database[2] = v3;
    database[3] = v4;
    database[4] = v5;
}

int main() {
    char filename[MAX_FILENAME];
    load_database();
    printf("Enter filename to be scanned: ");
    scanf("%s", filename);
    if (scan_file(filename)) {
        printf("Virus found in file '%s'\n", filename);
    } else {
        printf("File '%s' is clean\n", filename);
    }
    return 0;
}
//Falcon-180B DATASET v1.0 Category: Antivirus scanner ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_VIRUSES 100
#define MAX_VIRUS_NAME_LENGTH 100
#define MAX_FILE_NAME_LENGTH 100
#define MAX_FILE_PATH_LENGTH 1000

typedef struct {
    char name[MAX_VIRUS_NAME_LENGTH];
    char signature[MAX_FILE_NAME_LENGTH];
} virus_t;

int num_viruses = 0;
virus_t viruses[MAX_VIRUSES];

int load_viruses() {
    FILE *fp;
    char line[MAX_FILE_PATH_LENGTH];
    char *token;

    fp = fopen("viruses.txt", "r");
    if (fp == NULL) {
        printf("Error: could not open viruses.txt\n");
        return -1;
    }

    while (fgets(line, MAX_FILE_PATH_LENGTH, fp)!= NULL) {
        token = strtok(line, ",");
        strcpy(viruses[num_viruses].name, token);

        token = strtok(NULL, ",");
        strcpy(viruses[num_viruses].signature, token);

        num_viruses++;
    }

    fclose(fp);
    return 0;
}

int scan_file(char *file_path) {
    FILE *fp;
    char line[MAX_FILE_PATH_LENGTH];
    char *token;
    int i;

    fp = fopen(file_path, "r");
    if (fp == NULL) {
        printf("Error: could not open %s\n", file_path);
        return -1;
    }

    while (fgets(line, MAX_FILE_PATH_LENGTH, fp)!= NULL) {
        for (i = 0; i < num_viruses; i++) {
            token = strtok(line, ",");
            if (token!= NULL && strcmp(token, viruses[i].signature) == 0) {
                printf("Virus found: %s\n", viruses[i].name);
                return 1;
            }
        }
    }

    fclose(fp);
    return 0;
}

int main() {
    load_viruses();

    char file_path[MAX_FILE_PATH_LENGTH];
    printf("Enter file path to scan: ");
    scanf("%s", file_path);

    scan_file(file_path);

    return 0;
}
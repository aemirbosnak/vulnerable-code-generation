//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PATH_LEN 255         // Max length of file path
#define MAX_VIRUS_NUM 100        // Max number of viruses that can be stored in memory
#define MAX_VIRUS_LEN 1024       // Max length of virus signature

typedef struct virus {
    char signature[MAX_VIRUS_LEN];
    int length;
} virus;

virus virusDB[MAX_VIRUS_NUM];
int numViruses = 0;

void load_virus_database(char* database_path) {
    FILE *fp = fopen(database_path, "r");
    if (fp == NULL) {
        printf("Error: could not open virus database file %s\n", database_path);
        exit(1);
    }

    char signature[MAX_VIRUS_LEN];
    while (!feof(fp) && numViruses < MAX_VIRUS_NUM) {
        if (fgets(signature, MAX_VIRUS_LEN, fp) == NULL) {
            break;
        }

        int len = strlen(signature);
        // Remove linebreak at the end of the signature
        if (signature[len-1] == '\n') {
            signature[len-1] = '\0';
        }

        len = strlen(signature);
        virus new_virus;
        strcpy(new_virus.signature, signature);
        new_virus.length = len;
        virusDB[numViruses++] = new_virus;
    }
}

int scan_file(char* file_path) {
    FILE *fp = fopen(file_path, "r");
    if (fp == NULL) {
        printf("Error: could not open file %s\n", file_path);
        return -1;
    }

    unsigned char buffer[MAX_VIRUS_LEN];
    int bytes_read;
    int virus_num = 0;

    while ((bytes_read = fread(buffer, 1, MAX_VIRUS_LEN, fp)) != 0) {
        for (int i = 0; i < numViruses; i++) {
            if (bytes_read < virusDB[i].length) {
                continue;
            }

            if (strstr((char*)buffer, virusDB[i].signature) != NULL) {
                printf("Virus found in file %s: signature = %s\n", file_path, virusDB[i].signature);
                virus_num++;
            }
        }
    }

    fclose(fp);

    return virus_num;
}

int main(int argc, char* argv[]) {
    if (argc < 3) {
        printf("Usage: %s <virus_database_file> <file_to_scan> [<file_to_scan> ...]\n", argv[0]);
        return -1;
    }

    char* virus_database_path = argv[1];
    load_virus_database(virus_database_path);

    for (int i = 2; i < argc; i++) {
        scan_file(argv[i]);
    }

    printf("Scanning finished.\n");
    return 0;
}
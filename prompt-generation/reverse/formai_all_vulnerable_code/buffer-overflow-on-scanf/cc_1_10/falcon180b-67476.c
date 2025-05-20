//Falcon-180B DATASET v1.0 Category: Antivirus scanner ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function prototypes
int scan_file(char *filename);
int scan_memory(char *memory);

int main() {
    char filename[100];
    printf("Enter filename to scan: ");
    scanf("%s", filename);
    int result = scan_file(filename);
    if (result == 1) {
        printf("File is clean.\n");
    } else {
        printf("File is infected.\n");
    }
    return 0;
}

int scan_file(char *filename) {
    FILE *fp;
    char buffer[1000];
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: File not found.\n");
        return 0;
    }
    while (fgets(buffer, 1000, fp)!= NULL) {
        int i = 0;
        char *token = strtok(buffer, " ");
        while (token!= NULL) {
            if (strcmp(token, "virus") == 0) {
                printf("Virus found in file.\n");
                fclose(fp);
                return 1;
            }
            token = strtok(NULL, " ");
        }
    }
    fclose(fp);
    return 0;
}

int scan_memory(char *memory) {
    char *token = strtok(memory, " ");
    while (token!= NULL) {
        if (strcmp(token, "virus") == 0) {
            printf("Virus found in memory.\n");
            return 1;
        }
        token = strtok(NULL, " ");
    }
    return 0;
}
//Falcon-180B DATASET v1.0 Category: Antivirus scanner ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VIRUS_SIZE 100
#define MAX_FILE_SIZE 100000
#define VIRUS_SIGNATURE "ABCDEFGHIJKLMNOPQRSTUVWXYZ"

typedef struct {
    char name[MAX_FILE_SIZE];
    int size;
    char content[MAX_FILE_SIZE];
} File;

int main() {
    File file;
    char line[MAX_FILE_SIZE];
    FILE *fp;
    int i, j, k;
    int virusFound = 0;

    printf("Enter the name of the file to scan: ");
    scanf("%s", file.name);

    fp = fopen(file.name, "r");
    if (fp == NULL) {
        printf("Error: File not found.\n");
        exit(1);
    }

    while (fgets(line, MAX_FILE_SIZE, fp)!= NULL) {
        for (i = 0; i < strlen(line); i++) {
            for (j = 0; j < strlen(VIRUS_SIGNATURE); j++) {
                if (line[i] == VIRUS_SIGNATURE[j]) {
                    virusFound = 1;
                    printf("Virus found in file %s at line %d.\n", file.name, i+1);
                    break;
                }
            }
            if (virusFound == 1) {
                break;
            }
        }
        if (virusFound == 0) {
            printf("No virus found in file %s.\n", file.name);
        }
        virusFound = 0;
    }

    fclose(fp);
    return 0;
}
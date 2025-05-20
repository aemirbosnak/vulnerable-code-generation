//Falcon-180B DATASET v1.0 Category: Antivirus scanner ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VIRUSES 100
#define MAX_FILE_SIZE 1024 * 1024 * 10 // 10 MB

typedef struct {
    char *name;
    char *signature;
} Virus;

int loadViruses(Virus *viruses) {
    FILE *fp = fopen("viruses.txt", "r");
    if (fp == NULL) {
        printf("Error: could not open viruses.txt\n");
        return 1;
    }

    int count = 0;
    while (fscanf(fp, "%s %s\n", viruses[count].name, viruses[count].signature) == 2) {
        count++;
        if (count >= MAX_VIRUSES) {
            printf("Error: too many viruses in viruses.txt\n");
            fclose(fp);
            return 1;
        }
    }

    fclose(fp);
    return 0;
}

int scanFile(const char *filename, Virus *viruses) {
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error: could not open %s\n", filename);
        return 1;
    }

    char buffer[MAX_FILE_SIZE];
    int fileSize = fread(buffer, 1, MAX_FILE_SIZE, fp);
    fclose(fp);

    if (fileSize <= 0 || fileSize >= MAX_FILE_SIZE) {
        printf("Error: %s is too large or too small\n", filename);
        return 1;
    }

    int count = 0;
    for (int i = 0; i < count; i++) {
        if (memmem(buffer, fileSize, viruses[i].signature, strlen(viruses[i].signature))!= NULL) {
            printf("%s is infected with %s\n", filename, viruses[i].name);
            return 1;
        }
    }

    printf("%s is clean\n", filename);
    return 0;
}

int main() {
    Virus viruses[MAX_VIRUSES];
    if (loadViruses(viruses)!= 0) {
        return 1;
    }

    char filename[256];
    printf("Enter filename to scan: ");
    scanf("%s", filename);

    int result = scanFile(filename, viruses);
    if (result!= 0) {
        return result;
    }

    return 0;
}
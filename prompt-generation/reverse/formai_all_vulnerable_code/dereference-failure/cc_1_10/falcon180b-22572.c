//Falcon-180B DATASET v1.0 Category: Antivirus scanner ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VIRUSES 10

typedef struct {
    char name[50];
    char signature[100];
} virus;

virus viruses[MAX_VIRUSES] = {
    {"ILOVEYOU", "vbs"},
    {"MYDOOM", "exe"},
    {"STONED", "com"},
    {"SADMIN", "vbs"},
    {"SLAM", "vbs"},
    {"SQLSLAMMER", "sql"},
    {"BLADERUNNER", "vbs"},
    {"ANNAKOURNIKOVA", "vbs"},
    {"CME-24", "exe"},
    {"SASSER", "exe"}
};

int numViruses = sizeof(viruses) / sizeof(virus);

int isInfected(char* file, int fileSize) {
    int i;
    char* buffer = (char*) malloc(fileSize);
    fread(buffer, fileSize, 1, file);
    for(i=0; i<numViruses; i++) {
        if(strstr(buffer, viruses[i].signature)!= NULL) {
            printf("\n%s detected in file %s\n", viruses[i].name, file);
            return 1;
        }
    }
    printf("\nFile is clean.\n");
    return 0;
}

int main() {
    char file[100];
    printf("\nEnter the name of the file to scan: ");
    scanf("%s", file);
    FILE* fp = fopen(file, "rb");
    if(fp == NULL) {
        printf("\nFile not found.\n");
        exit(0);
    }
    fseek(fp, 0, SEEK_END);
    int fileSize = ftell(fp);
    rewind(fp);
    isInfected(fp, fileSize);
    fclose(fp);
    return 0;
}
//Falcon-180B DATASET v1.0 Category: Antivirus scanner ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE 1024 * 1024 * 10 // 10 MB

// Function to check if a file is infected
int isInfected(char* file) {
    FILE* fp = fopen(file, "rb");
    if (fp == NULL) {
        printf("Error opening file %s\n", file);
        exit(1);
    }

    char buffer[MAX_FILE_SIZE];
    fseek(fp, 0, SEEK_END);
    int fileSize = ftell(fp);
    rewind(fp);

    fread(buffer, 1, fileSize, fp);
    fclose(fp);

    int i = 0;
    while (i < fileSize - 2) {
        if (buffer[i] == 0x5A && buffer[i + 1] == 0x4D && buffer[i + 2] == 0x5A) { // MZ signature
            return 1;
        }
        i++;
    }

    return 0;
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Usage: %s [file]\n", argv[0]);
        exit(1);
    }

    char* file = argv[1];
    int isInfectedResult = isInfected(file);

    if (isInfectedResult == 1) {
        printf("File %s is infected!\n", file);
    } else {
        printf("File %s is clean.\n", file);
    }

    return 0;
}
//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

int main() {
    char filename[MAX_SIZE];
    char signature[10] = "CSE3313";
    FILE *fp;
    unsigned char buffer[MAX_SIZE];
    int i;
    int signatureCounter = 0;

    printf("Enter the name of the file to scan: ");
    scanf("%s", filename);

    fp = fopen(filename, "rb");
    
    if (fp == NULL) {
        printf("Error: Unable to open file\n");
        exit(1);
    }

    fseek(fp, 0, SEEK_END);
    int fileSize = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    if (fileSize > MAX_SIZE) {
        printf("Error: File too large to scan\n");
        exit(1);
    }
    else if (fileSize < sizeof(signature)) {
        printf("Error: File too small to contain virus signature\n");
        exit(1);
    }

    fread(buffer, fileSize, 1, fp);

    for (i = 0; i < fileSize; i++) {
        if (buffer[i] == signature[signatureCounter]) {
            signatureCounter++;
            if (signatureCounter == sizeof(signature)) {
                printf("Warning: Virus signature found in %s\n", filename);
                fclose(fp);
                exit(1);
            }
        }
        else {
            signatureCounter = 0;
        }
    }

    printf("File scanned successfully! No virus found.\n");
    fclose(fp);
    return 0;
}
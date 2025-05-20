//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_LEN 100000

int isVirus(unsigned char *signature, unsigned char *fileContents, int fileLength) {
    int i, j;
    int sigLen = strlen((const char *)signature);
    int matchCount = 0;

    for (i = 0; i < fileLength - sigLen; i++) {
        for (j = 0; j < sigLen; j++) {
            if (signature[j] != fileContents[i+j]) {
                break;
            }
            matchCount++;
            if (matchCount == sigLen) {
                return 1;
            }
        }
    }
    return 0;
}

int main(int argc, char **argv) {
    FILE *fp;
    unsigned char *fileContents;
    unsigned char *virusSignature = "InfectMe";
    int fileLength;

    if (argc != 2) {
        printf("Usage: antivirus <filename>");
        return 1;
    }

    fp = fopen(argv[1], "rb");
    if (!fp) {
        printf("Error: failed to open file '%s'", argv[1]);
        return 1;
    }

    fseek(fp, 0, SEEK_END);
    fileLength = ftell(fp);
    fseek(fp, 0, SEEK_SET);
    if (fileLength > MAX_FILE_LEN) {
        printf("Error: file is too large to scan");
        fclose(fp);
        return 1;
    }

    fileContents = (unsigned char *)malloc(sizeof(unsigned char) * fileLength);
    if (!fileContents) {
        printf("Error: failed to allocate memory for file contents");
        fclose(fp);
        return 1;
    }

    fread(fileContents, fileLength, 1, fp);
    fclose(fp);

    if (isVirus(virusSignature, fileContents, fileLength)) {
        printf("Virus detected in file '%s'", argv[1]);
    } else {
        printf("File '%s' is clean", argv[1]);
    }

    free(fileContents);
    return 0;
}
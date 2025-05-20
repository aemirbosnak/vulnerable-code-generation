//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char fileType[10];
    char fileSize[20];
    char author[30];
} Metadata;

int main() {
    char fileName[50];
    printf("Enter file name: ");
    scanf("%s", fileName);

    char command[100] = "file ";
    strcat(command, fileName);

    char result[200];
    FILE * fp = popen(command, "r");

    if (fp == NULL) {
        printf("Failed to run command\n");
        exit(1);
    }

    fgets(result, sizeof(result), fp);
    pclose(fp);

    Metadata metadata;
    if (strstr(result, "JPEG") != NULL) {
        strcpy(metadata.fileType, "JPEG");
    }
    else if (strstr(result, "PNG") != NULL) {
        strcpy(metadata.fileType, "PNG");
    }
    else {
        printf("Unknown file type\n");
        exit(1);
    }

    char fileSizeCommand[100] = "wc -c ";
    strcat(fileSizeCommand, fileName);

    fp = popen(fileSizeCommand, "r");

    if (fp == NULL) {
        printf("Failed to run command\n");
        exit(1);
    }

    char fileSizeResult[20];
    fgets(fileSizeResult, sizeof(fileSizeResult), fp);
    pclose(fp);

    strcpy(metadata.fileSize, fileSizeResult);
    metadata.fileSize[strlen(metadata.fileSize) - 1] = '\0';

    char author[30];
    printf("Enter author name: ");
    scanf("%s", author);
    strcpy(metadata.author, author);

    printf("FileType: %s\n", metadata.fileType);
    printf("FileSize: %s\n", metadata.fileSize);
    printf("Author: %s\n", metadata.author);

    return 0;
}
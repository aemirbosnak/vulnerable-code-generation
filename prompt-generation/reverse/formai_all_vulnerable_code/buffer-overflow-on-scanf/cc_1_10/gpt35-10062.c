//FormAI DATASET v1.0 Category: Data recovery tool ; Style: Dennis Ritchie
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct fileData {
    int fileId;
    char fileName[100];
    char fileType[50];
    long int fileSize;
};

int main() {
    FILE *fp;
    fp = fopen("data.bin", "rb");

    if(fp == NULL) {
        printf("Error: Could not open file");
        exit(1);
    }

    struct fileData fileArray[100];
    memset(fileArray, 0, sizeof(fileArray));
    int fileCount = 0;

    fread(&fileCount, sizeof(int), 1, fp); // read the number of entries in the file

    if(fileCount == 0) {
        printf("No files found!");
        fclose(fp);
        exit(0);
    }

    int i;
    for(i = 0; i < fileCount; i++) {
        fread(&fileArray[i], sizeof(struct fileData), 1, fp); // read each entry
    }

    printf("Following files were found:\n");
    for(i = 0; i < fileCount; i++) {
        printf("%d. %s (%s)\n", i+1, fileArray[i].fileName, fileArray[i].fileType);
    }

    int fileIdChoice;
    printf("Enter the file ID to recover: ");
    scanf("%d", &fileIdChoice);

    if(fileIdChoice <= 0 || fileIdChoice > fileCount) {
        printf("Invalid file ID!");
        fclose(fp);
        exit(0);
    }

    struct fileData fileToRecover = fileArray[fileIdChoice-1];
    printf("File to recover: %s.%s, size %ld bytes\n", fileToRecover.fileName, fileToRecover.fileType, fileToRecover.fileSize);

    char *recoveryBuffer = (char*)malloc(fileToRecover.fileSize);
    memset(recoveryBuffer, 0, fileToRecover.fileSize);

    fseek(fp, sizeof(int) + (fileIdChoice-1)*sizeof(struct fileData), SEEK_SET); // move the file pointer to the start of the chosen entry
    fread(recoveryBuffer, fileToRecover.fileSize, 1, fp); // read the data into the buffer

    char recoveryFileName[150];
    sprintf(recoveryFileName, "recovered_%s.%s", fileToRecover.fileName, fileToRecover.fileType);
    FILE *recoveryFile;
    recoveryFile = fopen(recoveryFileName, "wb");
    fwrite(recoveryBuffer, fileToRecover.fileSize, 1, recoveryFile); // write the data to a new file

    printf("\nFile successfully recovered as: %s\n", recoveryFileName);

    free(recoveryBuffer);
    fclose(fp);
    fclose(recoveryFile);
    return 0;
}
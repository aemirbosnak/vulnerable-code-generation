//Falcon-180B DATASET v1.0 Category: Data recovery tool ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_NAME_SIZE 100
#define MAX_FILE_CONTENT_SIZE 1000

// Structure to hold the file information
typedef struct {
    char fileName[MAX_FILE_NAME_SIZE];
    char fileContent[MAX_FILE_CONTENT_SIZE];
} File;

// Function to read the file content and store it in the File structure
void readFile(File *file) {
    FILE *fp;
    fp = fopen(file->fileName, "r");
    if (fp!= NULL) {
        fseek(fp, 0, SEEK_END);
        file->fileContent[MAX_FILE_CONTENT_SIZE - 1] = '\0';
        fseek(fp, 0, SEEK_SET);
        fread(file->fileContent, sizeof(char), MAX_FILE_CONTENT_SIZE, fp);
        fclose(fp);
    } else {
        printf("Error: File not found!\n");
    }
}

// Function to write the file content to a new file
void writeFile(File *file) {
    FILE *fp;
    fp = fopen(file->fileName, "w");
    if (fp!= NULL) {
        fprintf(fp, "%s", file->fileContent);
        fclose(fp);
    } else {
        printf("Error: Failed to write file!\n");
    }
}

// Function to recover the deleted file
void recoverFile(char *deletedFileName) {
    FILE *fp;
    char buffer[MAX_FILE_CONTENT_SIZE];
    fp = fopen(deletedFileName, "r");
    if (fp!= NULL) {
        while (fgets(buffer, sizeof(buffer), fp)!= NULL) {
            File file;
            strcpy(file.fileName, deletedFileName);
            strcpy(file.fileContent, buffer);
            writeFile(&file);
        }
        fclose(fp);
    } else {
        printf("Error: Failed to recover file!\n");
    }
}

int main() {
    File file;
    printf("Enter the name of the deleted file: ");
    scanf("%s", file.fileName);
    readFile(&file);
    recoverFile(file.fileName);
    return 0;
}
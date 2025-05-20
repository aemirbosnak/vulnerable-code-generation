//MISTRAL-7B DATASET v1.0 Category: File Backup System ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 10
#define MAX_FILE_NAME_LENGTH 50

typedef struct {
    char name[MAX_FILE_NAME_LENGTH];
    char content[1024];
} FileData;

FileData files[MAX_FILES];
int currentFileIndex = 0;

void saveFile(char *fileName, char *content) {
    strcpy(files[currentFileIndex].name, fileName);
    strcpy(files[currentFileIndex].content, content);
    currentFileIndex++;

    if (currentFileIndex >= MAX_FILES) {
        printf("Error: Maximum number of files reached.\n");
        exit(1);
    }
}

void loadFile(char *fileName, char *outputBuffer, int bufferSize) {
    int i;

    for (i = 0; i < currentFileIndex; i++) {
        if (strcmp(files[i].name, fileName) == 0) {
            strncpy(outputBuffer, files[i].content, bufferSize);
            return;
        }
    }

    printf("Error: File not found.\n");
}

int main() {
    char inputFileName[MAX_FILE_NAME_LENGTH];
    char inputContent[1024];
    char outputBuffer[1024];

    while (1) {
        printf("\nBackup System > ");
        scanf("%s", inputFileName);

        if (strcmp(inputFileName, "exit") == 0) {
            break;
        }

        printf("Enter file content: ");
        scanf("%s", inputContent);

        saveFile(inputFileName, inputContent);

        printf("File saved successfully.\n");
    }

    printf("\nBackup System > Load file: ");
    scanf("%s", inputFileName);

    loadFile(inputFileName, outputBuffer, sizeof(outputBuffer));

    printf("File content: %s\n", outputBuffer);

    return 0;
}
//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: active
#include <stdio.h>
#include <string.h>

#define MAX_FILE_NAME 100
#define MAX_BUFFER_SIZE 1024

void scanFile(FILE *file);

void scanFolder(char folderPath[MAX_FILE_NAME]);

int isInfected(char *buffer);

int main() {
    char filePath[MAX_FILE_NAME];
    printf("Enter a file path: ");
    scanf("%s", filePath);

    FILE *file = fopen(filePath, "r");

    if (file == NULL) {
        printf("Error opening file!");
    } else {
        scanFile(file);
        fclose(file);
    }

    char folderPath[MAX_FILE_NAME];
    printf("\nEnter a folder path: ");
    scanf("%s", folderPath);
    scanFolder(folderPath);

    return 0;
}

void scanFile(FILE *file) {
    char buffer[MAX_BUFFER_SIZE];

    while (fgets(buffer, MAX_BUFFER_SIZE, file) != NULL) {
        if (isInfected(buffer)) {
            printf("Antivirus Alert: File is infected!\n");
            return;
        }
    }

    printf("File is clean!\n");
}

void scanFolder(char folderPath[MAX_FILE_NAME]) {
    int fileCount = 0;
    char command[MAX_FILE_NAME + 10] = "ls ";
    strcat(command, folderPath);
    FILE *pipe = popen(command, "r");

    if (pipe == NULL) {
        printf("Error executing command!");
        return;
    }

    char fileName[MAX_FILE_NAME];

    while (fgets(fileName, MAX_FILE_NAME, pipe) != NULL) {
        char filePath[MAX_FILE_NAME];
        sprintf(filePath, "%s/%s", folderPath, fileName);
        FILE *file = fopen(filePath, "r");
        if (file != NULL) {
            scanFile(file);
            fclose(file);
            fileCount++;
        }
    }

    pclose(pipe);
    printf("\n%d files scanned in %s\n", fileCount, folderPath);
}

int isInfected(char *buffer) {
    char virus[] = "malware";
    if (strstr(buffer, virus) != NULL) {
        return 1;
    }
    return 0;
}
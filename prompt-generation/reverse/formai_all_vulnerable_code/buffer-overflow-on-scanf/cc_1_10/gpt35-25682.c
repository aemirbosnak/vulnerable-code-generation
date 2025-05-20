//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE 1024

// Struct to store file information
typedef struct FileInfo {
    char filename[20];
    char filecontent[MAX_FILE_SIZE];
} FileInfo;

void scanFile(FileInfo fileInfo) {
    int virusCount = 0;
    char* virusSignature[] = {"malware", "trojan", "virus", "ransomware", "spyware"};

    for (int i = 0; i < 5; i++) {
        if (strstr(fileInfo.filecontent, virusSignature[i])) {
            virusCount++;
        }
    }

    if (virusCount) {
        printf("Virus detected in file %s\n", fileInfo.filename);
    } else {
        printf("File %s is clean\n", fileInfo.filename);
    }
}

int main() {
    char filePath[100];
    FileInfo fileInfo;
    FILE* file;

    printf("Enter file path: ");
    scanf("%s", filePath);

    file = fopen(filePath, "r");

    if (!file) {
        printf("Unable to open file %s\n", filePath);
        exit(1);
    }

    // Read file name
    strcpy(fileInfo.filename, filePath);

    // Read file content
    char ch;
    int i = 0;
    while ((ch = fgetc(file)) != EOF) {
        fileInfo.filecontent[i] = ch;
        i++;
    }
    fileInfo.filecontent[i] = '\0';

    fclose(file);

    scanFile(fileInfo);

    return 0;
}
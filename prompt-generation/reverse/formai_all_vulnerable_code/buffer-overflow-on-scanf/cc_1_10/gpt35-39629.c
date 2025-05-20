//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: irregular
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void getAllFiles(char* directory, char* fileExtension, char** files, int* index);
void getFileSize(char* filePath, long int* size);

int main() {
    printf("Welcome to C Disk Space Analyzer!\n");
    printf("This program will analyze the disk space used by files in a directory.\n");

    // Get directory path
    char directory[100];
    printf("\nEnter the full path of the directory you want to analyze: ");
    scanf("%s", directory);

    // Get file extension
    char fileExtension[10];
    printf("\nEnter the file extension you want to analyze (e.g. txt, doc, pdf): ");
    scanf("%s", fileExtension);

    // Get all files in directory with specified extension
    char** files = (char**)malloc(100 * sizeof(char*));
    for (int i = 0; i < 100; i++) {
        files[i] = (char*)malloc(100 * sizeof(char));
    }
    int index = 0;
    getAllFiles(directory, fileExtension, files, &index);
    printf("\nFound %d files with extension %s in directory %s\n", index, fileExtension, directory);

    // Get file sizes and add up total disk space used
    long int totalSize = 0;
    printf("\nCalculating file sizes...\n");
    for (int i = 0; i < index; i++) {
        long int size;
        char filePath[200];
        sprintf(filePath, "%s/%s", directory, files[i]);
        getFileSize(filePath, &size);
        totalSize += size;
        printf("%s - %ld bytes\n", files[i], size);
    }

    // Print total disk space used
    printf("\nTotal disk space used by %d %s files in directory %s: %ld bytes\n", index, fileExtension, directory, totalSize);

    // Free memory
    for (int i = 0; i < 100; i++) {
        free(files[i]);
    }
    free(files);

    return 0;
}

void getAllFiles(char* directory, char* fileExtension, char** files, int* index) {
    FILE* fp;
    char command[200];
    sprintf(command, "find %s -name '*.%s' > fileList.txt", directory, fileExtension);
    system(command);

    fp = fopen("fileList.txt", "r");
    char fileName[100];
    while (fgets(fileName, 100, fp)) {
        int length = strlen(fileName) - 1;
        if (fileName[length] == '\n') {
            fileName[length] = '\0';
        }
        strcpy(files[*index], fileName);
        (*index)++;
    }

    fclose(fp);
    system("rm fileList.txt");
}

void getFileSize(char* filePath, long int* size) {
    FILE* fp = fopen(filePath, "r");
    fseek(fp, 0L, SEEK_END);
    *size = ftell(fp);
    fclose(fp);
}
//FormAI DATASET v1.0 Category: File system simulation ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_FILE_SYSTEM_SIZE 1024

// A struct to hold the information for a file
typedef struct {
    int startBlock;
    int length;
    char name[50];
} File;

// Function to initialize the file system blocks
void initializeBlockList(char* blocksList, int size) {
    memset(blocksList, '0', size);
}

int main() {
    // Initialize the file system with an array of characters
    char blocksList[MAX_FILE_SYSTEM_SIZE];
    initializeBlockList(blocksList, MAX_FILE_SYSTEM_SIZE);

    File file1 = { 0, 20, "file1.txt" };
    File file2 = { 20, 10, "file2.txt" };
    File file3 = { 30, 15, "file3.txt" };
    File file4 = { 45, 20, "file4.txt" };

    // Add files to the file system
    memcpy(&blocksList[file1.startBlock], file1.name, strlen(file1.name));
    memcpy(&blocksList[file2.startBlock], file2.name, strlen(file2.name));
    memcpy(&blocksList[file3.startBlock], file3.name, strlen(file3.name));
    memcpy(&blocksList[file4.startBlock], file4.name, strlen(file4.name));

    // Print the file system
    printf("File System Contents:\n");
    printf("%s\n", blocksList);

    // Prompt user for file to access
    char filename[50];
    printf("Enter filename: ");
    scanf("%s", filename);

    // Find the file in the file system
    File* file;
    if(strcmp(filename, file1.name) == 0) file = &file1;
    else if(strcmp(filename, file2.name) == 0) file = &file2;
    else if(strcmp(filename, file3.name) == 0) file = &file3;
    else if(strcmp(filename, file4.name) == 0) file = &file4;
    else {
        printf("File not found.\n");
        return 0;
    }

    // Print file information
    printf("File Information:\n");
    printf("Name: %s\n", file->name);
    printf("Start block: %d\n", file->startBlock);
    printf("Length: %d\n", file->length);

    return 0;
}
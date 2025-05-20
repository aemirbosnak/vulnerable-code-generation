//FormAI DATASET v1.0 Category: File system simulation ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 10
#define MAX_NAME_LENGTH 20
#define MAX_FILE_SIZE 1000

typedef struct file {
    char name[MAX_NAME_LENGTH];
    char data[MAX_FILE_SIZE];
    int size;
} File;

File files[MAX_FILES];
int numFiles = 0;

void createFile(char* name) {
    if (numFiles >= MAX_FILES) {
        printf("Error: maximum number of files reached.\n");
        return;
    }
    
    strcpy(files[numFiles].name, name);
    files[numFiles].size = 0;
    numFiles++;
    
    printf("File \"%s\" created successfully.\n", name);
}

void writeFile(char* name, char* data) {
    int i;
    
    for (i = 0; i < numFiles; i++) {
        if (strcmp(files[i].name, name) == 0) {
            strcpy(files[i].data, data);
            files[i].size = strlen(data);
            printf("File \"%s\" written successfully.\n", name);
            return;
        }
    }
    
    printf("Error: file \"%s\" not found.\n", name);
}

void readFile(char* name) {
    int i;
    
    for (i = 0; i < numFiles; i++) {
        if (strcmp(files[i].name, name) == 0) {
            printf("%s\n", files[i].data);
            return;
        }
    }
    
    printf("Error: file \"%s\" not found.\n", name);
}

void deleteFile(char* name) {
    int i, j;
    
    for (i = 0; i < numFiles; i++) {
        if (strcmp(files[i].name, name) == 0) {
            for (j = i; j < numFiles - 1; j++) {
                files[j] = files[j + 1];
            }
            numFiles--;
            printf("File \"%s\" deleted successfully.\n", name);
            return;
        }
    }
    
    printf("Error: file \"%s\" not found.\n", name);
}

int main() {
    char input[100];
    char command[10];
    char name[MAX_NAME_LENGTH];
    char data[MAX_FILE_SIZE];
    
    printf("Welcome to the C File System Simulator!\n");
    
    while (1) {
        printf("Enter a command (\"create\", \"write\", \"read\", \"delete\", or \"exit\"):\n");
        fgets(input, 100, stdin);
        sscanf(input, "%s %s", command, name);
        
        if (strcmp(command, "create") == 0) {
            createFile(name);
        } else if (strcmp(command, "write") == 0) {
            fgets(data, MAX_FILE_SIZE, stdin);
            writeFile(name, data);
        } else if (strcmp(command, "read") == 0) {
            readFile(name);
        } else if (strcmp(command, "delete") == 0) {
            deleteFile(name);
        } else if (strcmp(command, "exit") == 0) {
            printf("Exiting C File System Simulator...\n");
            break;
        } else {
            printf("Error: invalid command.\n");
        }
    }
    
    return 0;
}
//FormAI DATASET v1.0 Category: File system simulation ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 100
#define MAX_FILE_NAME 20
#define MAX_FILE_SIZE 100

typedef struct file {
    char name[MAX_FILE_NAME];
    int size;
    char data[MAX_FILE_SIZE];
} File;

File fileSystem[MAX_FILES];
int numFiles = 0;

void createFile(char *fileName) {
    if(numFiles == MAX_FILES) {
        printf("Error: No more space in file system\n");
        return;
    }
    
    for(int i=0; i<numFiles; i++) {
        if(strcmp(fileSystem[i].name, fileName) == 0) {
            printf("Error: File already exists with name %s\n", fileName);
            return;
        }
    }
    
    File newFile;
    strcpy(newFile.name, fileName);
    newFile.size = 0;
  
    fileSystem[numFiles] = newFile;
    
    printf("File %s created successfully!\n", fileName);
    
    numFiles++;
}

void writeFile(char *fileName, char *data) {
    int i;
    for(i=0; i<numFiles; i++) {
        if(strcmp(fileSystem[i].name, fileName) == 0) {
            break;
        }
    }
    
    if(i == numFiles) {
        printf("Error: No file found with name %s\n", fileName);
        return;
    }
    
    int dataSize = strlen(data);
    if(dataSize > MAX_FILE_SIZE) {
        printf("Error: File size too big to write\n");
        return;
    }
    
    strcpy(fileSystem[i].data, data);
    fileSystem[i].size = dataSize;
    
    printf("Data written to %s successfully!\n", fileName);
}

void readFile(char *fileName) {
    int i;
    for(i=0; i<numFiles; i++) {
        if(strcmp(fileSystem[i].name, fileName) == 0) {
            break;
        }
    }
    
    if(i == numFiles) {
        printf("Error: No file found with name %s\n", fileName);
        return;
    }
    
    printf("Name: %s\nSize: %d bytes\nData: %s\n", fileSystem[i].name, fileSystem[i].size, fileSystem[i].data);
}

void deleteFile(char *fileName) {
    int i;
    for(i=0; i<numFiles; i++) {
        if(strcmp(fileSystem[i].name, fileName) == 0) {
            break;
        }
    }
    
    if(i == numFiles) {
        printf("Error: No file found with name %s\n", fileName);
        return;
    }
    
    for(int j=i; j<numFiles-1; j++) {
        fileSystem[j] = fileSystem[j+1];
    }
    
    numFiles--;
    
    printf("File %s deleted successfully!\n", fileName);
}

int main() {
    char fileName[MAX_FILE_NAME];
    char data[MAX_FILE_SIZE];
    int choice;
    
    do {
        printf("1. Create new file\n2. Write to file\n3. Read file\n4. Delete file\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                printf("Enter file name: ");
                scanf("%s", fileName);
                createFile(fileName);
                break;
            case 2:
                printf("Enter file name: ");
                scanf("%s", fileName);
                printf("Enter data to write: ");
                scanf("%s", data);
                writeFile(fileName, data);
                break;
            case 3:
                printf("Enter file name: ");
                scanf("%s", fileName);
                readFile(fileName);
                break;
            case 4:
                printf("Enter file name: ");
                scanf("%s", fileName);
                deleteFile(fileName);
                break;
            case 5:
                printf("Exiting program...\n");
                break;
            default:
                printf("Enter a valid choice!\n");
        }
    } while(choice != 5);
    
    return 0;
}
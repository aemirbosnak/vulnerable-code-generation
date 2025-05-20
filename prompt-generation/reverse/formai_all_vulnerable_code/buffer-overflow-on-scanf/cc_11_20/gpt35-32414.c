//FormAI DATASET v1.0 Category: File system simulation ; Style: brave
#include <string.h> 
#include <stdio.h>

#define MAX_NAME 30
#define MAX_FILES 50

// file data structure
typedef struct {
    char fileName[MAX_NAME];
    int filePointer;
    int fileSize;
} file;

int main() {
    file fileSystem[MAX_FILES]; // file system with max. 50 files
    int numFiles = 0; // number of files in the file system
    int i, j, flag, filePos, numBytes;
    char fileName[MAX_NAME], data[MAX_NAME];

    while (1) { // loop to accept user commands
        flag = 0;
        printf("\nEnter command (add, delete, read, exit): ");
        scanf("%s", data);

        // add new file
        if (strcmp(data, "add") == 0) {
            if (numFiles == MAX_FILES) {
                printf("\nFile system full.\n");
                continue;
            }

            printf("\nEnter file name: ");
            scanf("%s", fileName);

            for (i = 0; i < numFiles; i++) { // check if file already exists
                if (strcmp(fileSystem[i].fileName, fileName) == 0) {
                    printf("\nFile already exists.\n");
                    flag = 1;
                    break;
                }
            }
            if (flag == 1) {
                continue;
            }

            fileSystem[numFiles].filePointer = 0; // set initial pointer to 0
            fileSystem[numFiles].fileSize = 0;
            strcpy(fileSystem[numFiles].fileName, fileName);
            printf("\nFile added.\n");
            numFiles++;
        }

        // delete file
        else if (strcmp(data, "delete") == 0) {
            printf("\nEnter file name: ");
            scanf("%s", fileName);

            for (i = 0; i < numFiles; i++) { // check if file exists
                if (strcmp(fileSystem[i].fileName, fileName) == 0) {
                    for (j = i; j < numFiles - 1; j++) {
                        strcpy(fileSystem[j].fileName, fileSystem[j + 1].fileName);
                        fileSystem[j].filePointer = fileSystem[j + 1].filePointer;
                        fileSystem[j].fileSize = fileSystem[j + 1].fileSize;
                    }
                    printf("\nFile deleted.\n");
                    numFiles--;
                    flag = 1;
                    break;
                }
            }
            if (flag == 0) {
                printf("\nFile not found.\n");
            }
        }

        // read file
        else if (strcmp(data, "read") == 0) {
            printf("\nEnter file name: ");
            scanf("%s", fileName);

            for (i = 0; i < numFiles; i++) { // check if file exists
                if (strcmp(fileSystem[i].fileName, fileName) == 0) {
                    printf("\nEnter number of bytes to read: ");
                    scanf("%d", &numBytes);

                    if (fileSystem[i].filePointer + numBytes > fileSystem[i].fileSize) {
                        numBytes = fileSystem[i].fileSize - fileSystem[i].filePointer;
                    }
                    filePos = fileSystem[i].filePointer;
                    fileSystem[i].filePointer += numBytes;

                    printf("\nData read:\n");
                    for (j = filePos; j < filePos + numBytes; j++) {
                        printf("%c", data[j]);
                    }
                    printf("\n");
                    flag = 1;
                }
            }
            if (flag == 0) {
                printf("\nFile not found.\n");
            }
        }

        // exit loop
        else if (strcmp(data, "exit") == 0) {
            printf("\nExiting program.\n");
            break;
        }

        else {
            printf("\nInvalid command.\n");
        }
    }

    return 0;
}
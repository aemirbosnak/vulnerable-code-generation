//Falcon-180B DATASET v1.0 Category: File system simulation ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 1000
#define MAX_FILE_NAME 100
#define MAX_DIR_NAME 100
#define MAX_PATH_NAME 200

typedef struct {
    char name[MAX_FILE_NAME];
    int size;
} File;

typedef struct {
    char name[MAX_DIR_NAME];
    int numFiles;
    File files[MAX_FILES];
} Directory;

Directory rootDir;

int createFile(char *path, int size) {
    int i;
    char *fileName;
    Directory *dir;

    fileName = strrchr(path, '/');
    if (fileName == NULL) {
        fileName = path;
    } else {
        fileName++;
    }

    dir = &rootDir;
    for (i = 0; i < dir->numFiles; i++) {
        if (strcmp(dir->files[i].name, fileName) == 0) {
            printf("File already exists.\n");
            return -1;
        }
    }

    strcpy(dir->files[dir->numFiles].name, fileName);
    dir->files[dir->numFiles].size = size;
    dir->numFiles++;

    return 0;
}

int deleteFile(char *path) {
    int i;
    char *fileName;
    Directory *dir;

    fileName = strrchr(path, '/');
    if (fileName == NULL) {
        fileName = path;
    } else {
        fileName++;
    }

    dir = &rootDir;
    for (i = 0; i < dir->numFiles; i++) {
        if (strcmp(dir->files[i].name, fileName) == 0) {
            memmove(&dir->files[i], &dir->files[i+1], sizeof(File) * (dir->numFiles - i - 1));
            dir->numFiles--;
            return 0;
        }
    }

    printf("File not found.\n");
    return -1;
}

int main() {
    char path[MAX_PATH_NAME];
    char command[MAX_PATH_NAME];

    printf("C File System Simulation\n");
    printf("Commands: create <file path>, delete <file path>\n");

    while (1) {
        printf("> ");
        scanf("%s", command);

        if (strcmp(command, "create") == 0) {
            scanf("%s", path);
            createFile(path, 0);
        } else if (strcmp(command, "delete") == 0) {
            scanf("%s", path);
            deleteFile(path);
        } else {
            printf("Invalid command.\n");
        }
    }

    return 0;
}
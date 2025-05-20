//GEMINI-pro DATASET v1.0 Category: File Backup System ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_FILES 100
#define MAX_FILE_NAME 256
#define MAX_FILE_SIZE 1024

typedef struct {
    char name[MAX_FILE_NAME];
    char data[MAX_FILE_SIZE];
    size_t size;
    time_t timestamp;
} File;

File files[MAX_FILES];

int numFiles = 0;

int addFile(char *name, char *data, size_t size) {
    if (numFiles >= MAX_FILES) {
        return -1;
    }

    strcpy(files[numFiles].name, name);
    strcpy(files[numFiles].data, data);
    files[numFiles].size = size;
    files[numFiles].timestamp = time(NULL);

    numFiles++;

    return 0;
}

int removeFile(char *name) {
    int i;

    for (i = 0; i < numFiles; i++) {
        if (strcmp(files[i].name, name) == 0) {
            break;
        }
    }

    if (i == numFiles) {
        return -1;
    }

    memmove(&files[i], &files[i + 1], (numFiles - i - 1) * sizeof(File));

    numFiles--;

    return 0;
}

int listFiles() {
    int i;

    for (i = 0; i < numFiles; i++) {
        printf("%s\t%ld\t%s\n", files[i].name, files[i].size, ctime(&files[i].timestamp));
    }

    return 0;
}

int main() {
    char buffer[MAX_FILE_SIZE];
    char command[MAX_FILE_NAME];
    char name[MAX_FILE_NAME];
    char data[MAX_FILE_SIZE];
    size_t size;
    int i;

    while (1) {
        printf("> ");

        fgets(buffer, MAX_FILE_SIZE, stdin);

        sscanf(buffer, "%s %s %s", command, name, data);

        if (strcmp(command, "add") == 0) {
            size = strlen(data);

            addFile(name, data, size);
        } else if (strcmp(command, "remove") == 0) {
            removeFile(name);
        } else if (strcmp(command, "list") == 0) {
            listFiles();
        } else if (strcmp(command, "quit") == 0) {
            break;
        } else {
            printf("Unknown command: %s\n", command);
        }
    }

    return 0;
}
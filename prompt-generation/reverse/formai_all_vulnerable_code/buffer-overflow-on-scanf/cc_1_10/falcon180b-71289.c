//Falcon-180B DATASET v1.0 Category: File system simulation ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 100

typedef struct {
    char name[20];
    int size;
} File;

void createFile(File *file, char *name, int size) {
    strcpy(file->name, name);
    file->size = size;
}

int main() {
    File files[MAX_FILES];
    int numFiles = 0;

    char command[50];
    while (1) {
        printf("Enter command: ");
        scanf("%s", command);

        if (strcmp(command, "create") == 0) {
            char filename[20];
            int filesize;
            printf("Enter filename: ");
            scanf("%s", filename);
            printf("Enter filesize: ");
            scanf("%d", &filesize);

            createFile(&files[numFiles], filename, filesize);
            numFiles++;
        } else if (strcmp(command, "delete") == 0) {
            char filename[20];
            printf("Enter filename to delete: ");
            scanf("%s", filename);

            for (int i = 0; i < numFiles; i++) {
                if (strcmp(files[i].name, filename) == 0) {
                    memset(&files[i], 0, sizeof(File));
                    numFiles--;
                    break;
                }
            }
        } else if (strcmp(command, "list") == 0) {
            printf("Files:\n");
            for (int i = 0; i < numFiles; i++) {
                printf("%s %d bytes\n", files[i].name, files[i].size);
            }
        } else if (strcmp(command, "exit") == 0) {
            break;
        } else {
            printf("Invalid command\n");
        }
    }

    return 0;
}
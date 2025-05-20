//GEMINI-pro DATASET v1.0 Category: File system simulation ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// File system structure
typedef struct {
    char name[32];      // File name
    int size;           // File size in bytes
    char data[1024];    // File data
} File;

// File system
File files[32];
int num_files = 0;

// File system commands
void ls() {
    for (int i = 0; i < num_files; i++) {
        printf("%s (%d bytes)\n", files[i].name, files[i].size);
    }
}

void cat(char *filename) {
    for (int i = 0; i < num_files; i++) {
        if (strcmp(files[i].name, filename) == 0) {
            printf("%s\n", files[i].data);
            return;
        }
    }
    printf("File not found\n");
}

void create(char *filename, char *data) {
    if (num_files == 32) {
        printf("File system full\n");
        return;
    }
    for (int i = 0; i < num_files; i++) {
        if (strcmp(files[i].name, filename) == 0) {
            printf("File already exists\n");
            return;
        }
    }
    strcpy(files[num_files].name, filename);
    files[num_files].size = strlen(data);
    strcpy(files[num_files].data, data);
    num_files++;
}

void delete(char *filename) {
    for (int i = 0; i < num_files; i++) {
        if (strcmp(files[i].name, filename) == 0) {
            for (int j = i; j < num_files - 1; j++) {
                files[j] = files[j + 1];
            }
            num_files--;
            return;
        }
    }
    printf("File not found\n");
}

int main() {
    char command[32];
    char filename[32];
    char data[1024];

    while (1) {
        printf("fs> ");
        scanf("%s", command);
        if (strcmp(command, "ls") == 0) {
            ls();
        } else if (strcmp(command, "cat") == 0) {
            scanf("%s", filename);
            cat(filename);
        } else if (strcmp(command, "create") == 0) {
            scanf("%s %s", filename, data);
            create(filename, data);
        } else if (strcmp(command, "delete") == 0) {
            scanf("%s", filename);
            delete(filename);
        } else if (strcmp(command, "quit") == 0) {
            break;
        } else {
            printf("Invalid command\n");
        }
    }

    return 0;
}
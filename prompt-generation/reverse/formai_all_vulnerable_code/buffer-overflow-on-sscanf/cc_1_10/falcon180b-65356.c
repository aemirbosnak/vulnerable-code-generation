//Falcon-180B DATASET v1.0 Category: File system simulation ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_FILES 100
#define MAX_PATH 100

typedef struct {
    char name[MAX_PATH];
    int size;
} File;

File files[MAX_FILES];
int num_files = 0;

void create_file(char* name, int size) {
    if (num_files >= MAX_FILES) {
        printf("Error: Too many files\n");
        return;
    }
    strcpy(files[num_files].name, name);
    files[num_files].size = size;
    num_files++;
}

void delete_file(char* name) {
    int i;
    for (i = 0; i < num_files; i++) {
        if (strcmp(files[i].name, name) == 0) {
            memmove(&files[i], &files[i+1], (num_files-i-1)*sizeof(File));
            num_files--;
            break;
        }
    }
}

void list_files() {
    int i;
    printf("Files:\n");
    for (i = 0; i < num_files; i++) {
        printf("%s (%d bytes)\n", files[i].name, files[i].size);
    }
}

int main() {
    char command[MAX_PATH];
    while (1) {
        printf("> ");
        fgets(command, MAX_PATH, stdin);
        if (strcasecmp(command, "quit") == 0) {
            break;
        } else if (strcasecmp(command, "create") == 0) {
            char name[MAX_PATH];
            int size;
            sscanf(command, "create %s %d", name, &size);
            create_file(name, size);
        } else if (strcasecmp(command, "delete") == 0) {
            char name[MAX_PATH];
            sscanf(command, "delete %s", name);
            delete_file(name);
        } else if (strcasecmp(command, "list") == 0) {
            list_files();
        } else {
            printf("Invalid command\n");
        }
    }
    return 0;
}
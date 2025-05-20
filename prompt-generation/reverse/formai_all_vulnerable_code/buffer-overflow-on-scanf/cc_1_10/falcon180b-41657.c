//Falcon-180B DATASET v1.0 Category: File system simulation ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 100
#define MAX_FILE_NAME 50

typedef struct {
    char name[MAX_FILE_NAME];
    int size;
} File;

File files[MAX_FILES];
int num_files = 0;

void create_file(char* name, int size) {
    if (num_files >= MAX_FILES) {
        printf("Error: maximum number of files reached\n");
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
            num_files--;
            memmove(&files[i], &files[i+1], sizeof(File) * (num_files - i));
            break;
        }
    }
}

void list_files() {
    int i;

    for (i = 0; i < num_files; i++) {
        printf("%s (%d bytes)\n", files[i].name, files[i].size);
    }
}

int main() {
    char cmd[100];
    int arg1, arg2;

    while (1) {
        printf("> ");
        scanf("%s", cmd);

        if (strcmp(cmd, "create") == 0) {
            scanf("%s %d", cmd, &arg1);
            create_file(cmd, arg1);
        } else if (strcmp(cmd, "delete") == 0) {
            scanf("%s", cmd);
            delete_file(cmd);
        } else if (strcmp(cmd, "list") == 0) {
            list_files();
        } else if (strcmp(cmd, "exit") == 0) {
            break;
        } else {
            printf("Invalid command\n");
        }
    }

    return 0;
}
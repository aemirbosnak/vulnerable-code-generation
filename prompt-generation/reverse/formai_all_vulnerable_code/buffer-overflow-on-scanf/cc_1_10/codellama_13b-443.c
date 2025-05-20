//Code Llama-13B DATASET v1.0 Category: File system simulation ; Style: Alan Turing
// Turing_Simulator.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *name;
    char *content;
} File;

File *files[100];
int num_files = 0;

void write_file(char *name, char *content) {
    File *file = (File *)malloc(sizeof(File));
    file->name = name;
    file->content = content;
    files[num_files] = file;
    num_files++;
}

void read_file(char *name) {
    int i;
    for (i = 0; i < num_files; i++) {
        if (strcmp(files[i]->name, name) == 0) {
            printf("File %s:\n%s\n", name, files[i]->content);
            return;
        }
    }
    printf("File not found.\n");
}

void delete_file(char *name) {
    int i;
    for (i = 0; i < num_files; i++) {
        if (strcmp(files[i]->name, name) == 0) {
            free(files[i]->name);
            free(files[i]->content);
            free(files[i]);
            files[i] = NULL;
            num_files--;
            return;
        }
    }
    printf("File not found.\n");
}

int main() {
    char command[100];
    while (1) {
        printf("Enter command: ");
        scanf("%s", command);
        if (strcmp(command, "write") == 0) {
            char name[100], content[100];
            scanf("%s", name);
            scanf("%s", content);
            write_file(name, content);
        } else if (strcmp(command, "read") == 0) {
            char name[100];
            scanf("%s", name);
            read_file(name);
        } else if (strcmp(command, "delete") == 0) {
            char name[100];
            scanf("%s", name);
            delete_file(name);
        } else if (strcmp(command, "exit") == 0) {
            break;
        } else {
            printf("Invalid command.\n");
        }
    }
    return 0;
}
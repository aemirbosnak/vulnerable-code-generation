//FormAI DATASET v1.0 Category: File system simulation ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_SIZE 20
#define MAX_FILE_SIZE 1000

typedef struct {
    char name[MAX_FILENAME_SIZE];
    int size;
    char data[MAX_FILE_SIZE];
} file_t;

typedef struct {
    file_t *files;
    int num_files;
} directory_t;

int main(void) {
    directory_t *root = malloc(sizeof(directory_t));
    root->num_files = 0;
    
    char input[100];
    do {
        printf("$ ");
        fgets(input, sizeof(input), stdin);
        char *command = strtok(input, " ");
        char *arg = strtok(NULL, "\n");
        
        if (strcmp(command, "ls") == 0) {
            for (int i = 0; i < root->num_files; i++) {
                printf("%s (%d bytes)\n", root->files[i].name, root->files[i].size);
            }
        } else if (strcmp(command, "touch") == 0) {
            if (root->num_files >= MAX_FILE_SIZE) {
                printf("Error: file system full\n");
            } else {
                file_t new_file;
                strcpy(new_file.name, arg);
                new_file.size = 0;
                root->files[root->num_files++] = new_file;
            }
        } else if (strcmp(command, "rm") == 0) {
            int file_index = -1;
            for (int i = 0; i < root->num_files; i++) {
                if (strcmp(root->files[i].name, arg) == 0) {
                    file_index = i;
                    break;
                }
            }
            if (file_index == -1) {
                printf("Error: file not found\n");
            } else {
                for (int i = file_index; i < root->num_files - 1; i++) {
                    root->files[i] = root->files[i + 1];
                }
                root->num_files--;
            }
        } else if (strcmp(command, "write") == 0) {
            int file_index = -1;
            for (int i = 0; i < root->num_files; i++) {
                if (strcmp(root->files[i].name, arg) == 0) {
                    file_index = i;
                    break;
                }
            }
            if (file_index == -1) {
                printf("Error: file not found\n");
            } else {
                fgets(root->files[file_index].data, MAX_FILE_SIZE, stdin);
                root->files[file_index].size = strlen(root->files[file_index].data);
            }
        } else if (strcmp(command, "read") == 0) {
            int file_index = -1;
            for (int i = 0; i < root->num_files; i++) {
                if (strcmp(root->files[i].name, arg) == 0) {
                    file_index = i;
                    break;
                }
            }
            if (file_index == -1) {
                printf("Error: file not found\n");
            } else {
                printf("%s\n", root->files[file_index].data);
            }
        } else if (strcmp(command, "exit") != 0) {
            printf("Error: invalid command\n");
        }
    } while (strcmp(input, "exit\n") != 0);
    
    free(root);
    return 0;
}
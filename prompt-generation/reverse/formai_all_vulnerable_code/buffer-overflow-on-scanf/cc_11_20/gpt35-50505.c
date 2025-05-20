//FormAI DATASET v1.0 Category: File Backup System ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 100
#define MAX_FILE_SIZE 1000

typedef struct {
    char filename[MAX_FILENAME_LENGTH];
    char content[MAX_FILE_SIZE];
} File;

File* file_list[10]; // maximum of 10 files in the system

int main() {
    int num_files = 0; // initially, there are no files in the system

    while(1) {
        printf("Enter command (backup, restore, list, quit): ");
        char command[10];
        scanf("%s", command);

        if(strcmp(command, "backup") == 0) {
            // backup command
            if(num_files < 10) {
                File* file = (File*) malloc(sizeof(File));
                printf("Enter filename: ");
                scanf("%s", file->filename);
                printf("Enter file content: ");
                getchar(); // consume the newline character from scanf
                fgets(file->content, MAX_FILE_SIZE, stdin);
                file_list[num_files++] = file;
                printf("File backed up successfully.\n");
            } else {
                printf("Max number of files reached. Please delete a file first.\n");
            }
        } else if(strcmp(command, "restore") == 0) {
            // restore command
            if(num_files > 0) {
                printf("Enter filename to restore: ");
                char filename[MAX_FILENAME_LENGTH];
                scanf("%s", filename);
                int found = 0;
                for(int i = 0; i < num_files; i++) {
                    if(strcmp(file_list[i]->filename, filename) == 0) {
                        printf("File content:\n%s", file_list[i]->content);
                        found = 1;
                        break;
                    }
                }
                if(!found)
                    printf("File not found.\n");
            } else {
                printf("No files to restore. Please backup a file first.\n");
            }
        } else if(strcmp(command, "list") == 0) {
            // list command
            if(num_files > 0) {
                printf("List of backed up files:\n");
                for(int i = 0; i < num_files; i++) {
                    printf("%s\n", file_list[i]->filename);
                }
            } else {
                printf("No files to list. Please backup a file first.\n");
            }
        } else if(strcmp(command, "quit") == 0) {
            // quit command
            for(int i = 0; i < num_files; i++) {
                free(file_list[i]);
            }
            printf("Exiting the program.");
            break;
        } else {
            // invalid command
            printf("Invalid command. Please try again.\n");
        }
    }

    return 0;
}
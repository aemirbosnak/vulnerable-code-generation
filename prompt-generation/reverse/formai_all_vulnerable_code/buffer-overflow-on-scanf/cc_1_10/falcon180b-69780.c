//Falcon-180B DATASET v1.0 Category: File system simulation ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_NAME_LENGTH 100
#define MAX_FILE_SIZE 1024

typedef struct {
    char filename[MAX_FILE_NAME_LENGTH];
    char content[MAX_FILE_SIZE];
    int size;
} File;

int main() {
    int choice, file_count = 0;
    char root_dir[MAX_FILE_NAME_LENGTH];
    File files[10];

    printf("Welcome to the file system simulation!\n");
    printf("Please enter the name of the root directory: ");
    scanf("%s", root_dir);

    while(1) {
        printf("\n");
        printf("1. Create a new file\n");
        printf("2. Open an existing file\n");
        printf("3. Delete a file\n");
        printf("4. List all files in the directory\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: {
                if(file_count >= 10) {
                    printf("Maximum number of files reached. Please delete an existing file first.\n");
                    break;
                }
                printf("Enter the name of the new file: ");
                scanf("%s", files[file_count].filename);
                strcpy(files[file_count].content, "");
                files[file_count].size = 0;
                file_count++;
                break;
            }
            case 2: {
                printf("Enter the name of the file to open: ");
                scanf("%s", files[file_count-1].filename);
                printf("File content:\n%s\n", files[file_count-1].content);
                break;
            }
            case 3: {
                printf("Enter the name of the file to delete: ");
                scanf("%s", files[file_count-1].filename);
                strcpy(files[file_count-1].filename, "");
                strcpy(files[file_count-1].content, "");
                files[file_count-1].size = 0;
                break;
            }
            case 4: {
                printf("Files in %s:\n", root_dir);
                for(int i=0; i<file_count; i++) {
                    printf("%s (%d bytes)\n", files[i].filename, files[i].size);
                }
                break;
            }
            case 5: {
                exit(0);
            }
            default: {
                printf("Invalid choice. Please try again.\n");
            }
        }
    }

    return 0;
}
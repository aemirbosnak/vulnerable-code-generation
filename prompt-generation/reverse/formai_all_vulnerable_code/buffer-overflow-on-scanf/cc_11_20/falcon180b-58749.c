//Falcon-180B DATASET v1.0 Category: File system simulation ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 100
#define MAX_FILE_NAME_LENGTH 50
#define MAX_FILE_SIZE 1000

typedef struct {
    char name[MAX_FILE_NAME_LENGTH];
    int size;
    char content[MAX_FILE_SIZE];
} File;

void main() {
    File files[MAX_FILES];
    int num_files = 0;
    char choice;

    do {
        printf("File System Simulation\n");
        printf("1. Create file\n");
        printf("2. Delete file\n");
        printf("3. Rename file\n");
        printf("4. View file contents\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%c", &choice);

        switch(choice) {
            case '1':
                printf("Enter file name: ");
                scanf("%s", files[num_files].name);
                printf("Enter file size: ");
                scanf("%d", &files[num_files].size);
                printf("Enter file content: ");
                scanf("%s", files[num_files].content);
                printf("File created successfully.\n");
                num_files++;
                break;
            case '2':
                printf("Enter file name to delete: ");
                scanf("%s", files[num_files].name);
                for(int i=0; i<num_files; i++) {
                    if(strcmp(files[i].name, files[num_files].name) == 0) {
                        printf("File deleted successfully.\n");
                        memmove(&files[i], &files[i+1], (num_files-i-1)*sizeof(File));
                        num_files--;
                        break;
                    }
                }
                break;
            case '3':
                printf("Enter old file name: ");
                scanf("%s", files[num_files].name);
                printf("Enter new file name: ");
                scanf("%s", files[num_files].name);
                printf("File renamed successfully.\n");
                break;
            case '4':
                printf("Enter file name to view: ");
                scanf("%s", files[num_files].name);
                for(int i=0; i<num_files; i++) {
                    if(strcmp(files[i].name, files[num_files].name) == 0) {
                        printf("File name: %s\n", files[i].name);
                        printf("File size: %d\n", files[i].size);
                        printf("File content: %s\n", files[i].content);
                        break;
                    }
                }
                break;
            case '5':
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while(choice!= '5');
}
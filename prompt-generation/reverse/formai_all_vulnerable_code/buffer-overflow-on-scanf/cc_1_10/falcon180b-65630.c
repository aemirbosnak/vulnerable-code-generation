//Falcon-180B DATASET v1.0 Category: File system simulation ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_NAME_LENGTH 50
#define MAX_FILE_SIZE 1000

typedef struct {
    char name[MAX_FILE_NAME_LENGTH];
    int size;
    char data[MAX_FILE_SIZE];
} File;

int main() {
    File *files = (File *)malloc(10 * sizeof(File));
    int num_files = 0;
    int choice;

    do {
        printf("File System Simulation\n");
        printf("1. Create a file\n");
        printf("2. Delete a file\n");
        printf("3. Rename a file\n");
        printf("4. Copy a file\n");
        printf("5. Move a file\n");
        printf("6. Display file contents\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter file name: ");
                scanf("%s", files[num_files].name);
                printf("Enter file size: ");
                scanf("%d", &files[num_files].size);
                printf("Enter file contents: ");
                scanf("%s", files[num_files].data);
                num_files++;
                break;
            case 2:
                printf("Enter file name to delete: ");
                scanf("%s", files[num_files-1].name);
                num_files--;
                break;
            case 3:
                printf("Enter old file name: ");
                scanf("%s", files[num_files-1].name);
                printf("Enter new file name: ");
                scanf("%s", files[num_files-1].name);
                break;
            case 4:
                printf("Enter source file name: ");
                scanf("%s", files[num_files-1].name);
                printf("Enter destination file name: ");
                scanf("%s", files[num_files].name);
                strcpy(files[num_files].data, files[num_files-1].data);
                num_files++;
                break;
            case 5:
                printf("Enter file name to move: ");
                scanf("%s", files[num_files-1].name);
                printf("Enter destination file name: ");
                scanf("%s", files[num_files].name);
                strcpy(files[num_files].data, files[num_files-1].data);
                num_files++;
                break;
            case 6:
                printf("Enter file name to display: ");
                scanf("%s", files[num_files-1].name);
                printf("File contents:\n%s", files[num_files-1].data);
                break;
            case 7:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    } while(1);

    return 0;
}
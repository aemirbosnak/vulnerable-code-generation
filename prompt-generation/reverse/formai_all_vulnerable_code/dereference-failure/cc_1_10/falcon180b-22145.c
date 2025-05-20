//Falcon-180B DATASET v1.0 Category: File system simulation ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_NAME 50
#define MAX_FILE_CONTENT 200

typedef struct {
    char name[MAX_FILE_NAME];
    char content[MAX_FILE_CONTENT];
    int size;
} File;

int main() {
    int choice;
    File *files = (File *)malloc(10 * sizeof(File));
    int num_files = 0;

    do {
        printf("File System Simulation\n");
        printf("1. Create File\n");
        printf("2. Delete File\n");
        printf("3. Rename File\n");
        printf("4. View File Content\n");
        printf("5. Exit\n");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter File Name: ");
                scanf("%s", files[num_files].name);
                printf("Enter File Content: ");
                scanf("%[^\n]", files[num_files].content);
                files[num_files].size = strlen(files[num_files].content);
                num_files++;
                break;
            case 2:
                printf("Enter File Name to Delete: ");
                scanf("%s", files[num_files-1].name);
                memset(files[num_files-1].content, 0, MAX_FILE_CONTENT);
                break;
            case 3:
                printf("Enter Old File Name: ");
                scanf("%s", files[num_files-1].name);
                printf("Enter New File Name: ");
                scanf("%s", files[num_files-1].name);
                break;
            case 4:
                printf("File Content: %s\n", files[num_files-1].content);
                break;
            case 5:
                free(files);
                exit(0);
            default:
                printf("Invalid Choice\n");
        }
    } while(1);

    return 0;
}
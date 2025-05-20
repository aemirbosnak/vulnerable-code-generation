//Falcon-180B DATASET v1.0 Category: File system simulation ; Style: standalone
#include <stdio.h>
#include <stdlib.h>

#define MAX_FILE_SIZE 1000
#define MAX_FILE_NAME_LENGTH 50
#define MAX_NUM_FILES 10

typedef struct {
    char file_name[MAX_FILE_NAME_LENGTH];
    char file_content[MAX_FILE_SIZE];
    int file_size;
} File;

File files[MAX_NUM_FILES];
int num_files = 0;

int main() {
    int choice;
    while(1) {
        printf("\nFile System Menu:\n");
        printf("1. Create File\n");
        printf("2. Open File\n");
        printf("3. Write to File\n");
        printf("4. Read from File\n");
        printf("5. Delete File\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                if(num_files >= MAX_NUM_FILES) {
                    printf("Maximum number of files reached!\n");
                } else {
                    printf("Enter file name: ");
                    scanf("%s", files[num_files].file_name);
                    files[num_files].file_size = 0;
                    num_files++;
                }
                break;

            case 2:
                printf("Enter file name: ");
                scanf("%s", files[num_files].file_name);
                break;

            case 3:
                printf("Enter file content: ");
                scanf("%s", files[num_files].file_content);
                break;

            case 4:
                printf("File content: %s\n", files[num_files].file_content);
                break;

            case 5:
                printf("File deleted!\n");
                break;

            case 6:
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}
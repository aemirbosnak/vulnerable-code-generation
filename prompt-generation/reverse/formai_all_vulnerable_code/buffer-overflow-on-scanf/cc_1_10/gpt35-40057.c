//FormAI DATASET v1.0 Category: File system simulation ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>

#define MAX_FILES 10
#define MAX_NAME_LEN 20
#define MAX_DATA_LEN 50

typedef struct {
    char name[MAX_NAME_LEN];
    char data[MAX_DATA_LEN];
    int size;
} file;

int num_files = 0;
file files[MAX_FILES];

void create_file() {
    if(num_files >= MAX_FILES) {
        printf("Error: File system full.\n");
        return;
    }

    file new_file;
    printf("Enter file name (max %d characters):\n", MAX_NAME_LEN);
    scanf("%s", new_file.name);

    printf("Enter file data (max %d characters):\n", MAX_DATA_LEN);
    scanf("%s", new_file.data);
    new_file.size = strlen(new_file.data);

    files[num_files] = new_file;
    num_files++;

    printf("File created successfully.\n");
}

void delete_file() {
    char name[MAX_NAME_LEN];
    printf("Enter name of file to delete:\n");
    scanf("%s", name);

    int found = 0;
    for(int i = 0; i < num_files; i++) {
        if(strcmp(files[i].name, name) == 0) {
            found = 1;
            for(int j = i; j < num_files-1; j++) {
                files[j] = files[j+1];
            }
            num_files--;
            printf("File deleted successfully.\n");
            break;
        }
    }
    if(!found) {
        printf("Error: File not found.\n");
    }
}

void list_files() {
    if(num_files == 0) {
        printf("No files found.\n");
        return;
    }

    printf("Files in file system:\n");
    for(int i = 0; i < num_files; i++) {
        printf("%s (%d bytes)\n", files[i].name, files[i].size);
    }
}

int main() {
    int choice;
    while(1) {
        printf("\nEnter choice:\n");
        printf("1. Create file\n");
        printf("2. Delete file\n");
        printf("3. List files\n");
        printf("4. Exit\n");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                create_file();
                break;
            case 2:
                delete_file();
                break;
            case 3:
                list_files();
                break;
            case 4:
                exit(0);
                break;
            default:
                printf("Invalid choice. Try again.\n");
                break;
        }
    }
    
    return 0;
}
//FormAI DATASET v1.0 Category: File system simulation ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 10
#define MAX_FILE_NAME_LEN 20

typedef struct{
    char name[MAX_FILE_NAME_LEN];
    int size;
} file_t;

typedef struct{
    file_t files[MAX_FILES];
    int num_files;
} directory_t;

directory_t root_dir;

void initialize_file_system(){
    root_dir.num_files = 0;
}

void list_files(){
    printf("Files in root directory:\n");
    for(int i=0;i<root_dir.num_files;i++){
        printf("- %s (%d bytes)\n",root_dir.files[i].name,root_dir.files[i].size);
    }
}

void add_file(){
    if(root_dir.num_files == MAX_FILES){
        printf("Error: Maximum number of files reached.\n");
        return;
    }
    file_t new_file;
    printf("Enter name of new file:\n");
    scanf("%s",new_file.name);
    printf("Enter size of new file (in bytes):\n");
    scanf("%d",&new_file.size);
    root_dir.files[root_dir.num_files++] = new_file;
    printf("%s added to root directory.\n",new_file.name);
}

void delete_file(){
    char file_name[MAX_FILE_NAME_LEN];
    printf("Enter name of file to delete:\n");
    scanf("%s",file_name);
    int file_index = -1;
    for(int i=0;i<root_dir.num_files;i++){
        if(strcmp(root_dir.files[i].name,file_name) == 0){
            file_index = i;
            break;
        }
    }
    if(file_index == -1){
        printf("Error: File %s not found.\n",file_name);
        return;
    }
    printf("%s deleted from root directory.\n",root_dir.files[file_index].name);
    for(int i=file_index;i<root_dir.num_files-1;i++){
        root_dir.files[i] = root_dir.files[i+1];
    }
    root_dir.num_files--;
}

int main(){
    initialize_file_system();
    printf("Welcome to the C File System Simulation!\n");
    while(1){
        printf("\nChoose an option:\n");
        printf("1. List files\n");
        printf("2. Add file\n");
        printf("3. Delete file\n");
        printf("4. Quit\n");
        int choice;
        scanf("%d",&choice);
        switch(choice){
            case 1:
                list_files();
                break;
            case 2:
                add_file();
                break;
            case 3:
                delete_file();
                break;
            case 4:
                printf("Thank you for using the C File System Simulation!\n");
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}
//FormAI DATASET v1.0 Category: Data recovery tool ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 10
#define MAX_FILE_NAME_LENGTH 50
#define MAX_FILE_SIZE 1024

typedef struct file{
    char file_name[MAX_FILE_NAME_LENGTH];
    char data[MAX_FILE_SIZE];
}File;

File files[MAX_FILES];
int num_files = 0;

void add_file(char *file_name, char *data){
    if(num_files >= MAX_FILES){
        printf("Maximum number of files reached!\n");
        return;
    }
    strcpy(files[num_files].file_name, file_name);
    strcpy(files[num_files].data, data);
    num_files++;
}

int find_file(char *file_name){
    for(int i=0; i<num_files; i++){
        if(strcmp(files[i].file_name, file_name) == 0){
            return i;
        }
    }
    return -1;
}

void delete_file(char *file_name){
    int index = find_file(file_name);
    if(index == -1){
        printf("File not found!\n");
        return;
    }
    for(int j=index; j<num_files-1; j++){
        strcpy(files[j].file_name, files[j+1].file_name);
        strcpy(files[j].data, files[j+1].data);
    }
    num_files--;
    printf("File deleted successfully!\n");
}

void display_all_files(){
    if(num_files == 0){
        printf("No files found!\n");
        return;
    }
    printf("%d files found:\n", num_files);
    for(int i=0; i<num_files; i++){
        printf("%s\n", files[i].file_name);
    }
}

void display_file_data(char *file_name){
    int index = find_file(file_name);
    if(index == -1){
        printf("File not found!\n");
        return;
    }
    printf("Data in the file %s:\n", file_name);
    printf("%s\n", files[index].data);
}

int main(){
    int choice;
    char file_name[MAX_FILE_NAME_LENGTH];
    char data[MAX_FILE_SIZE];
    while(1){
        printf("\nMenu:\n");
        printf("1. Add new file\n");
        printf("2. Delete a file\n");
        printf("3. Display all files\n");
        printf("4. Display data in a file\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("Enter the file name: ");
                scanf("%s", file_name);
                printf("Enter the file data: ");
                scanf("%s", data);
                add_file(file_name, data);
                break;
            case 2:
                printf("Enter the file name: ");
                scanf("%s", file_name);
                delete_file(file_name);
                break;
            case 3:
                display_all_files();
                break;
            case 4:
                printf("Enter the file name: ");
                scanf("%s", file_name);
                display_file_data(file_name);
                break;
            case 5:
                exit(0);
                break;
            default:
                printf("Invalid choice!\n");
                break;
        }
    }
    return 0;
}
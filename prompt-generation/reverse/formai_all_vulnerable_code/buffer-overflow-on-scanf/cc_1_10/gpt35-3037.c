//FormAI DATASET v1.0 Category: File system simulation ; Style: complex
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_FILE_NAME_LEN 20
#define MAX_FILE_SIZE 100
#define MAX_NUM_FILES 10

struct file{
    char name[MAX_FILE_NAME_LEN];
    int size;
    char data[MAX_FILE_SIZE];
};

struct file_system{
    struct file files[MAX_NUM_FILES];
    int num_files;
};

void create_file(struct file_system *fs, char* file_name, int file_size, char* file_data){
    if(fs->num_files >= MAX_NUM_FILES){
        printf("Error: File system is full. Cannot create file.\n");
        return;
    }
    for(int i=0; i<fs->num_files; i++){
        if(strcmp(fs->files[i].name, file_name) == 0){
            printf("Error: File with same name already exists. Cannot create file.\n");
            return;
        }
    }
    struct file new_file;
    strcpy(new_file.name, file_name);
    new_file.size = file_size;
    strcpy(new_file.data, file_data);
    fs->files[fs->num_files] = new_file;
    fs->num_files++;
    printf("File created successfully.\n");
}

void delete_file(struct file_system *fs, char* file_name){
    int found = 0;
    for(int i=0; i<fs->num_files; i++){
        if(strcmp(fs->files[i].name, file_name) == 0){
            found = 1;
            for(int j=i; j<fs->num_files-1; j++){
                fs->files[j] = fs->files[j+1];
            }
            fs->num_files--;
            printf("File deleted successfully.\n");
            break;
        }
    }
    if(!found){
        printf("Error: File not found. Cannot delete.\n");
    }
}

void list_files(struct file_system *fs){
    printf("Files in file system:\n");
    for(int i=0; i<fs->num_files; i++){
        printf("%s\n", fs->files[i].name);
    }
}

void read_file(struct file_system *fs, char* file_name){
    int found = 0;
    for(int i=0; i<fs->num_files; i++){
        if(strcmp(fs->files[i].name, file_name) == 0){
            found = 1;
            printf("File contents:\n%s\n", fs->files[i].data);
            break;
        }
    }
    if(!found){
        printf("Error: File not found. Cannot read.\n");
    }
}

void write_file(struct file_system *fs, char* file_name, char* file_data){
    int found = 0;
    for(int i=0; i<fs->num_files; i++){
        if(strcmp(fs->files[i].name, file_name) == 0){
            found = 1;
            strcpy(fs->files[i].data, file_data);
            printf("File updated successfully.\n");
            break;
        }
    }
    if(!found){
        printf("Error: File not found. Cannot write.\n");
    }
}

int main(){
    struct file_system fs;
    fs.num_files = 0;
    int choice, file_size;
    char file_name[MAX_FILE_NAME_LEN+1];
    char file_data[MAX_FILE_SIZE+1];
    do{
        printf("\n1. Create file\n2. Delete file\n3. List files\n4. Read file\n5. Write file\n0. Exit\n\nEnter choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("\nEnter file name: ");
                scanf("%s", file_name);
                printf("Enter file size: ");
                scanf("%d", &file_size);
                printf("Enter file data: ");
                scanf("%s", file_data);
                create_file(&fs, file_name, file_size, file_data);
                break;
            case 2:
                printf("\nEnter file name to be deleted: ");
                scanf("%s", file_name);
                delete_file(&fs, file_name);
                break;
            case 3:
                list_files(&fs);
                break;
            case 4:
                printf("\nEnter file name to be read: ");
                scanf("%s", file_name);
                read_file(&fs, file_name);
                break;
            case 5:
                printf("\nEnter file name to be updated: ");
                scanf("%s", file_name);
                printf("Enter file data: ");
                scanf("%s", file_data);
                write_file(&fs, file_name, file_data);
                break;
            case 0:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }while(choice != 0);
    return 0;
}
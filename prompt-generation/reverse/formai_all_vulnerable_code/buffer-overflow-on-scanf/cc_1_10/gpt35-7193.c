//FormAI DATASET v1.0 Category: File system simulation ; Style: funny
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct file{
    char *filename;
    char *content;
};

struct directory{
    char *dirname;
    struct directory *subdir;
    struct file *file_list;
};

struct directory *create_dir(){
    struct directory *new_dir;
    new_dir = (struct directory*) malloc(sizeof(struct directory));
    new_dir->subdir = NULL;
    new_dir->file_list = NULL;

    char name[20];
    printf("Enter the directory name: \n");
    scanf("%s",name);

    new_dir->dirname = (char*) malloc(strlen(name)+1);
    strcpy(new_dir->dirname,name);
    printf("Directory '%s' has been created successfully!\n",new_dir->dirname);
    return new_dir;
}

struct file *create_file(){
    struct file *new_file;
    new_file = (struct file*) malloc(sizeof(struct file));

    char name[20];
    printf("Enter the file name: \n");
    scanf("%s",name);

    new_file->filename = (char*) malloc(strlen(name)+1);
    strcpy(new_file->filename,name);

    char content[100];
    printf("Enter the file content: \n");
    scanf("%s",content);

    new_file->content = (char*) malloc(strlen(content)+1);
    strcpy(new_file->content,content);
    printf("File '%s' has been created successfully!\n",new_file->filename);
    return new_file;
}

void create_file_in_dir(struct directory *parent_dir){
    struct file *new_file;
    new_file = create_file();

    if (parent_dir->file_list == NULL) {
        parent_dir->file_list = new_file;
        printf("File '%s' has been added successfully to directory '%s'!\n",new_file->filename,parent_dir->dirname);
    }
    else {
        struct file *temp = parent_dir->file_list;
        while (temp->filename!=NULL){
            if (strcmp(temp->filename,new_file->filename)==0){
                printf("A file with the same name already exists in directory '%s'!\n",parent_dir->dirname);
                return;
            }
            if (temp->filename == NULL) {
                break;
            }
            temp++;
        }
        temp = new_file;
        printf("File '%s' has been added successfully to directory '%s'!\n",new_file->filename,parent_dir->dirname);
    }
}

void create_dir_in_dir(struct directory *parent_dir){
    struct directory *new_dir;
    new_dir = create_dir();

    if (parent_dir->subdir == NULL){
        parent_dir->subdir = new_dir;
        printf("Directory '%s' has been added successfully to directory '%s'!\n",new_dir->dirname,parent_dir->dirname);
    }
    else {
        struct directory *temp = parent_dir->subdir;
        while (temp->dirname!=NULL){
            if (strcmp(temp->dirname,new_dir->dirname)==0){
                printf("A directory with the same name already exists in directory '%s'!\n",parent_dir->dirname);
                return;
            }
            temp++;
        }
        temp = new_dir;
        printf("Directory '%s' has been added successfully to directory '%s'!\n",new_dir->dirname,parent_dir->dirname);
    }
}

void ls(struct directory *dir){
    printf("Directories:\n");

    if (dir->subdir == NULL) {
        printf("(No directories present!)\n");
    }
    else {
        struct directory *tempd = dir->subdir;
        while (tempd->dirname!=NULL){
            printf("%s\n",tempd->dirname);
            tempd++;
        }
    }

    printf("Files:\n");

    if (dir->file_list == NULL) {
        printf("(No files present!)\n");
    }
    else {
        struct file *tempf = dir->file_list;
        while (tempf->filename!=NULL){
            printf("%s\n",tempf->filename);
            tempf++;
        }
    }
}

int main(){
    printf("Welcome to the File System Simulation Program!\n");
    printf("At any point, type 'exit' to quit the program.\n\n");

    struct directory *root;
    root = create_dir();

    char command[10];
    while (1){
        printf("\nEnter a command: ");
        scanf("%s",command);

        if (strcmp(command,"exit")==0){
            printf("\nExiting the program...\n");
            break;
        }

        else if (strcmp(command,"mkdir")==0){
            create_dir_in_dir(root);
        }
        else if (strcmp(command,"touch")==0){
            create_file_in_dir(root);
        }
        else if (strcmp(command,"ls")==0){
            ls(root);
        }
        else {
            printf("Invalid command!\n");
        }
    }
    return 0;
}
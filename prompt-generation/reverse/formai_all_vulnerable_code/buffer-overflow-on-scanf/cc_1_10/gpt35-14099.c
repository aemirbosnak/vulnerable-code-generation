//FormAI DATASET v1.0 Category: File system simulation ; Style: safe
#include<stdio.h>
#include<stdlib.h>

#define MAX 1000

struct file {
    char *name;
    char *data;
    int size;
    struct file *next;
};

struct directory {
    char *name;
    struct directory *parent;
    struct directory *subdir[MAX];
    struct file *files[MAX];
};

typedef struct directory Directory;
typedef struct file File;

Directory *current;
char *fs_name;

Directory *create_directory(char *name, Directory *parent);
File *create_file(char *name);
void create_file_system();
void ls();
void mkdir(char *name);
void cd(char *name);
void touch(char *name);
void write(char *name, char *data);
void read(char *name);
void rm(char *name);

int main() {
    printf("Enter file system name: ");
    scanf("%ms", &fs_name);
    create_file_system();
    printf("Welcome to %s file system.\n", fs_name);
    while(1) {
        char command[50], name[50], data[1000];
        printf("\nCommand: ");
        scanf("%s", command);
        if(strcmp(command, "ls") == 0) ls();
        else if(strcmp(command, "mkdir") == 0) {
            scanf("%s", name);
            mkdir(name);
        }
        else if(strcmp(command, "cd") == 0) {
            scanf("%s", name);
            cd(name);
        }
        else if(strcmp(command, "touch") == 0) {
            scanf("%s", name);
            touch(name);
        }
        else if(strcmp(command, "write") == 0) {
            scanf("%s %[^\n]s", name, data);
            write(name, data);
        }
        else if(strcmp(command, "read") == 0) {
            scanf("%s", name);
            read(name);
        }
        else if(strcmp(command, "rm") == 0) {
            scanf("%s", name);
            rm(name);
        }
        else if(strcmp(command, "exit") == 0) break;
        else printf("Invalid command. Please try again.\n");
    }
    return 0;
}

Directory *create_directory(char *name, Directory *parent) {
    Directory *directory = (Directory*) malloc(sizeof(Directory));
    directory->name = (char*) malloc(strlen(name) + 1);
    strcpy(directory->name, name);
    directory->parent = parent;
    return directory;
}

File *create_file(char *name) {
    File *file = (File*) malloc(sizeof(File));
    file->name = (char*) malloc(strlen(name) + 1);
    strcpy(file->name, name);
    file->data = NULL;
    file->size = 0;
    file->next = NULL;
    return file;
}

void create_file_system() {
    current = create_directory("root", NULL);
}

void ls() {
    Directory *dir = current;
    int i;
    for(i = 0; i < MAX && dir->subdir[i] != NULL; i++) printf("%s/  ", dir->subdir[i]->name);
    for(i = 0; i < MAX && dir->files[i] != NULL; i++) printf("%s  ", dir->files[i]->name);
    printf("\n");
}

void mkdir(char *name) {
    Directory *dir = current;
    int i;
    for(i = 0; i < MAX && dir->subdir[i] != NULL; i++) {
        if(strcmp(name, dir->subdir[i]->name) == 0) {
            printf("Directory with the same name already exists.\n");
            return;
        }
    }
    dir->subdir[i] = create_directory(name, dir);
}

void cd(char *name) {
    Directory *dir = current;
    int i;
    for(i = 0; i < MAX && dir->subdir[i] != NULL; i++) {
        if(strcmp(name, dir->subdir[i]->name) == 0) {
            current = dir->subdir[i];
            return;
        }
    }
    printf("Directory does not exist.\n");
}

void touch(char *name) {
    Directory *dir = current;
    int i;
    for(i = 0; i < MAX && dir->files[i] != NULL; i++) {
        if(strcmp(name, dir->files[i]->name) == 0) {
            printf("File with the same name already exists.\n");
            return;
        }
    }
    dir->files[i] = create_file(name);
}

void write(char *name, char *data) {
    Directory *dir = current;
    File *file = NULL;
    int i;
    for(i = 0; i < MAX && dir->files[i] != NULL; i++) {
        if(strcmp(name, dir->files[i]->name) == 0) {
            file = dir->files[i];
            break;
        }
    }
    if(file == NULL) {
        printf("File does not exist.\n");
        return;
    }
    file->data = (char*) malloc(strlen(data) + 1);
    strcpy(file->data, data);
    file->size = strlen(data);
}

void read(char *name) {
    Directory *dir = current;
    File *file = NULL;
    int i;
    for(i = 0; i < MAX && dir->files[i] != NULL; i++) {
        if(strcmp(name, dir->files[i]->name) == 0) {
            file = dir->files[i];
            break;
        }
    }
    if(file == NULL) {
        printf("File does not exist.\n");
        return;
    }
    printf("%s: %s\n", file->name, file->data);
}

void rm(char *name) {
    Directory *dir = current;
    File *file = NULL;
    int i, j;
    for(i = 0; i < MAX && dir->files[i] != NULL; i++) {
        if(strcmp(name, dir->files[i]->name) == 0) {
            file = dir->files[i];
            for(j = i; j < MAX - 1 && dir->files[j + 1] != NULL; j++) dir->files[j] = dir->files[j + 1];
            dir->files[j] = NULL;
            break;
        }
    }
    if(file == NULL) {
        printf("File does not exist.\n");
        return;
    }
    free(file->name);
    free(file->data);
    free(file);
}
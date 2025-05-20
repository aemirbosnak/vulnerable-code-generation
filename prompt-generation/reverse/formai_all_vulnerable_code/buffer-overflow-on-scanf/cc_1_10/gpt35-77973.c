//FormAI DATASET v1.0 Category: File system simulation ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 20
#define MAX_FILE_SIZE 1024

typedef struct {
    char name[MAX_NAME_LENGTH];
    int size;
    char data[MAX_FILE_SIZE];
} File;

typedef struct {
    char name[MAX_NAME_LENGTH];
    int num_files;
    File *files;
} Directory;

typedef struct {
    char name[MAX_NAME_LENGTH];
    int num_directories;
    Directory *directories;
} FileSystem;

FileSystem *create_file_system() {
    FileSystem *fs = malloc(sizeof(FileSystem));
    if (fs == NULL) {
        printf("Error: failed to create file system\n");
        return NULL;
    }
    
    printf("What should we name the file system? ");
    scanf("%s", fs->name);
    
    printf("How many directories should there be? ");
    scanf("%d", &fs->num_directories);
    
    fs->directories = malloc(sizeof(Directory) * fs->num_directories);
    if (fs->directories == NULL) {
        printf("Error: failed to create directories\n");
        free(fs);
        return NULL;
    }
    
    for (int i = 0; i < fs->num_directories; i++) {
        printf("What should we name directory #%d? ", i+1);
        scanf("%s", fs->directories[i].name);
        
        printf("How many files should be in directory #%d? ", i+1);
        scanf("%d", &fs->directories[i].num_files);
        
        fs->directories[i].files = malloc(sizeof(File) * fs->directories[i].num_files);
        if (fs->directories[i].files == NULL) {
            printf("Error: failed to create files for directory #%d\n", i+1);
            for (int j = 0; j < i; j++) {
                free(fs->directories[j].files);
            }
            free(fs->directories);
            free(fs);
            return NULL;
        }
        
        for (int j = 0; j < fs->directories[i].num_files; j++) {
            printf("What should we name file #%d in directory #%d? ", j+1, i+1);
            scanf("%s", fs->directories[i].files[j].name);
            
            printf("What should the size of file #%d in directory #%d be? ", j+1, i+1);
            scanf("%d", &fs->directories[i].files[j].size);
            
            printf("What should the contents of file #%d in directory #%d be? ", j+1, i+1);
            scanf("%s", fs->directories[i].files[j].data);
        }
    }
    
    return fs;
}

void print_file(File f) {
    printf("File name: %s\n", f.name);
    printf("File size: %d\n", f.size);
    printf("File contents: %s\n", f.data);
}

void print_directory(Directory d) {
    printf("Directory name: %s\n", d.name);
    printf("Directory contents:\n");
    for (int i = 0; i < d.num_files; i++) {
        print_file(d.files[i]);
    }
}

void print_file_system(FileSystem *fs) {
    printf("File system name: %s\n", fs->name);
    printf("File system contents:\n");
    for (int i = 0; i < fs->num_directories; i++) {
        print_directory(fs->directories[i]);
    }
}

int main() {
    FileSystem *fs = create_file_system();
    if (fs == NULL) {
        printf("Could not create file system\n");
        return 1;
    }
    
    print_file_system(fs);
    
    // Clean up
    for (int i = 0; i < fs->num_directories; i++) {
        for (int j = 0; j < fs->directories[i].num_files; j++) {
            free(fs->directories[i].files[j].data);
        }
        free(fs->directories[i].files);
    }
    free(fs->directories);
    free(fs);
    
    return 0;
}
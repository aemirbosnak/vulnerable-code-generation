//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

typedef struct Folder {
    char name[256];
    long long size;
    struct Folder *next;
} Folder;

Folder *head = NULL; // head of linked list to store folders

// function to create a new folder node
Folder *createFolder(char *name, long long size) {
    Folder *newFolder = (Folder*) malloc(sizeof(Folder));
    strcpy(newFolder->name, name);
    newFolder->size = size;
    newFolder->next = NULL;
    return newFolder;
}

// function to add a new folder to the linked list
void addFolder(char *name, long long size) {
    Folder *newFolder = createFolder(name, size);
    if (head == NULL) {
        head = newFolder;
    } else {
        Folder *current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newFolder;
    }
}

// function to print the list of folders and their sizes
void printFolders() {
    Folder *current = head;
    printf("\n\n FOLDER NAME\t\tSIZE\n");
    printf("---------------------------------\n");
    while (current != NULL) {
        printf(" %s\t\t%lld bytes\n", current->name, current->size);
        current = current->next;
    }
    printf("---------------------------------\n");
}

// function to recursively scan a folder and its subfolders
void scanFolder(char *dirPath) {
    DIR *dir = opendir(dirPath); // open directory
    if (dir == NULL) {
        printf("\n Error: could not open directory '%s'\n", dirPath);
        return;
    }
    struct dirent *entry;
    struct stat st;
    char path[512];
    long long size = 0;
    while ((entry = readdir(dir)) != NULL) { // read directory contents
        sprintf(path, "%s/%s", dirPath, entry->d_name); // construct full path of file/folder
        if (entry->d_type == DT_DIR) { // folder
            if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) { // not current or parent folder
                scanFolder(path); // recursive call to scan subfolder
                stat(path, &st); // get size of folder
                size += st.st_size;
                addFolder(entry->d_name, st.st_size); // add folder to linked list
            }
        } else { // file
            stat(path, &st); // get size of file
            size += st.st_size;
        }
    }
    closedir(dir); // close directory
    addFolder(dirPath, size); // add folder to linked list
}

int main() {
    char dirPath[512];
    printf("\n Enter the path of the directory to analyze: ");
    scanf("%s", dirPath);
    scanFolder(dirPath); // scan directory and subfolders
    printFolders(); // print list of folders and their sizes
    return 0;
}
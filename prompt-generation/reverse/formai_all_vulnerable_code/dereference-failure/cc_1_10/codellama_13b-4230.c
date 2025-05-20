//Code Llama-13B DATASET v1.0 Category: File Backup System ; Style: immersive
// Immersive C File Backup System Example Program

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>

// Structure to hold file information
typedef struct {
    char *name;
    char *path;
    int size;
    time_t modified;
} FileInfo;

// Function to get the size of a file
int getFileSize(char *path) {
    struct stat st;
    if (stat(path, &st) == -1) {
        perror("Error getting file size");
        return -1;
    }
    return st.st_size;
}

// Function to get the modification time of a file
time_t getFileModified(char *path) {
    struct stat st;
    if (stat(path, &st) == -1) {
        perror("Error getting file modification time");
        return -1;
    }
    return st.st_mtime;
}

// Function to read the contents of a file
char *readFile(char *path) {
    FILE *fp = fopen(path, "r");
    if (fp == NULL) {
        perror("Error opening file");
        return NULL;
    }
    // Get file size
    int size = getFileSize(path);
    // Allocate memory for file contents
    char *buffer = malloc(size);
    if (buffer == NULL) {
        perror("Error allocating memory for file contents");
        fclose(fp);
        return NULL;
    }
    // Read file contents
    fread(buffer, 1, size, fp);
    fclose(fp);
    return buffer;
}

// Function to write the contents of a file
void writeFile(char *path, char *contents) {
    FILE *fp = fopen(path, "w");
    if (fp == NULL) {
        perror("Error opening file for writing");
        return;
    }
    // Write file contents
    fwrite(contents, 1, strlen(contents), fp);
    fclose(fp);
}

// Function to create a backup of a file
void backupFile(char *path) {
    // Get file size and modification time
    int size = getFileSize(path);
    time_t modified = getFileModified(path);
    // Read file contents
    char *contents = readFile(path);
    if (contents == NULL) {
        return;
    }
    // Create backup file path
    char *backupPath = malloc(strlen(path) + 10);
    strcpy(backupPath, path);
    strcat(backupPath, ".bak");
    // Write backup file
    writeFile(backupPath, contents);
    // Free memory
    free(contents);
    free(backupPath);
}

// Function to iterate over files in a directory
void backupFiles(char *path) {
    DIR *dir = opendir(path);
    if (dir == NULL) {
        perror("Error opening directory");
        return;
    }
    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        // Skip current and parent directories
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }
        // Get full path to file
        char *filePath = malloc(strlen(path) + strlen(entry->d_name) + 2);
        strcpy(filePath, path);
        strcat(filePath, "/");
        strcat(filePath, entry->d_name);
        // Backup file
        backupFile(filePath);
        // Free memory
        free(filePath);
    }
    closedir(dir);
}

// Main function
int main(int argc, char **argv) {
    // Check arguments
    if (argc != 2) {
        printf("Usage: %s <directory>\n", argv[0]);
        return 1;
    }
    // Backup files in directory
    backupFiles(argv[1]);
    return 0;
}
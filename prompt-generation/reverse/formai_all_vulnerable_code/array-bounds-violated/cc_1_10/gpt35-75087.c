//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: Alan Touring
/* Disk Space Analyzer */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/* Function to calculate the size of folder*/
long int calculateFolderSize(char *name, char *path) {
    char command[500];
    sprintf(command, "du -shc %s/%s | tail -n1 | awk '{print $1}'", path, name);
    FILE *f = popen(command, "r"); // execute command as a pipe and get the result
    if (f == NULL) {
        perror("Error: Unable to calculate folder size!");
        exit(1);
    }
    char output[50];
    fgets(output, sizeof(output), f);
    pclose(f);
    return atol(output);
}

/* Function to calculate the size of a file */
long int calculateFileSize(char *name, char *path) {
    char filename[200];
    sprintf(filename, "%s/%s", path, name);
    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        perror("Error: Unable to calculate file size!");
        exit(1);
    }
    fseek(file, 0L, SEEK_END);
    long int size = ftell(file);
    fclose(file);
    return size;
}

/* Function to print the size of a file or folder */
void printSize(char *name, char *path) {
    if (name[0] != '.') { // Do not calculate the size of hidden files/folders
        char fullname[200];
        sprintf(fullname, "%s/%s", path, name);
        if (fullname[strlen(fullname) - 1] == '/') { // It is a folder
            printf("%ldM %s\n", calculateFolderSize(name, path), name);
        } else { // It is a file
            printf("%ldK %s\n", calculateFileSize(name, path) / 1024, name);
        }
    }
}

/* Function to scan a folder */
void scanFolder(char *path) {
    char command[500];
    sprintf(command, "ls -la %s", path);
    FILE *f = popen(command, "r"); // execute command as pipe and get the result
    if (f == NULL) {
        perror("Error: Unable to scan folder!");
        exit(1);
    }
    char filename[200];
    char line[1000];
    fgets(line, sizeof(line), f); // ignore the first line
    fgets(line, sizeof(line), f); // ignore the second line
    while (fgets(line, sizeof(line), f)) {
        sscanf(line, "%*s %*d %*s %*s %*ld %*s %*s %*s %s", filename); // extract filename
        printSize(filename, path);
    }
    pclose(f);
}

int main() {
    char path[500];
    printf("Enter the path of the folder: ");
    fgets(path, sizeof(path), stdin);
    path[strlen(path) - 1] = '\0'; // remove the newline character
    printf("Size\tName\n");
    scanFolder(path);
    return 0;
}
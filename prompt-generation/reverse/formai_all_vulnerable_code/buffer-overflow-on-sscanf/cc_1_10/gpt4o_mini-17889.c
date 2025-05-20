//GPT-4o-mini DATASET v1.0 Category: System administration ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>
#include <dirent.h>

#define BUFFER_SIZE 256

void print_file_info(const char *filename) {
    struct stat fileStat;
    if (stat(filename, &fileStat) < 0) {
        perror("stat failed");
        return;
    }

    printf("File: %s\n", filename);
    printf("Size: %ld bytes\n", fileStat.st_size);
    printf("Owner: %s\n", getpwuid(fileStat.st_uid)->pw_name);
    printf("Group: %s\n", getgrgid(fileStat.st_gid)->gr_name);
    printf("Permissions: ");
    printf( (fileStat.st_mode & S_IRUSR) ? "r" : "-");
    printf( (fileStat.st_mode & S_IWUSR) ? "w" : "-");
    printf( (fileStat.st_mode & S_IXUSR) ? "x" : "-");
    printf( (fileStat.st_mode & S_IRGRP) ? "r" : "-");
    printf( (fileStat.st_mode & S_IWGRP) ? "w" : "-");
    printf( (fileStat.st_mode & S_IXGRP) ? "x" : "-");
    printf( (fileStat.st_mode & S_IROTH) ? "r" : "-");
    printf( (fileStat.st_mode & S_IWOTH) ? "w" : "-");
    printf( (fileStat.st_mode & S_IXOTH) ? "x" : "-");
    printf("\n");

    char timeBuf[80];
    struct tm *timeinfo;
    timeinfo = localtime(&fileStat.st_mtime);
    strftime(timeBuf, sizeof(timeBuf), "%Y-%m-%d %H:%M:%S", timeinfo);
    printf("Last modified: %s\n", timeBuf);
    printf("\n");
}

void list_directory(const char *directory) {
    DIR *dir;
    struct dirent *entry;

    if ((dir = opendir(directory)) == NULL) {
        perror("opendir failed");
        return;
    }

    printf("Listing directory: %s\n\n", directory);
    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_name[0] != '.') { // Skipping hidden files
            print_file_info(entry->d_name);
        }
    }
    closedir(dir);
}

void create_file(const char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        perror("File creation failed");
        return;
    }
    fprintf(file, "This is a sample file for system administration demo.\n");
    fclose(file);
    printf("File '%s' created successfully.\n\n", filename);
}

void delete_file(const char *filename) {
    if (remove(filename) == 0) {
        printf("File '%s' deleted successfully.\n\n", filename);
    } else {
        perror("File deletion failed");
    }
}

void usage() {
    printf("System Administration Demo Program\n");
    printf("Usage:\n");
    printf("  list <directory>: List files in a directory\n");
    printf("  create <filename>: Create a file\n");
    printf("  delete <filename>: Delete a file\n");
    printf("  exit: Exit the program\n");
}

int main(int argc, char *argv[]) {
    char command[BUFFER_SIZE];
    char arg[BUFFER_SIZE];

    usage();

    while (1) {
        printf("> ");
        fgets(command, sizeof(command), stdin);
        
        sscanf(command, "%s %s", command, arg);

        if (strcmp(command, "list") == 0) {
            list_directory(arg);
        } else if (strcmp(command, "create") == 0) {
            create_file(arg);
        } else if (strcmp(command, "delete") == 0) {
            delete_file(arg);
        } else if (strcmp(command, "exit") == 0) {
            printf("Exiting the program.\n");
            break;
        } else {
            printf("Invalid command. Please try again.\n");
        }
    }
    
    return 0;
}
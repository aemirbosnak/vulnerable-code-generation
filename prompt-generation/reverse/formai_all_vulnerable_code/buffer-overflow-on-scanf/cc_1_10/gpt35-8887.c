//FormAI DATASET v1.0 Category: File Backup System ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <dirent.h>
#include <time.h>

// function to create backup folder
void create_backup_folder(char* dir) {
    char backup_dir[100] = "Backup_";
    time_t rawtime;
    struct tm * timeinfo;
    time(&rawtime);
    timeinfo = localtime(&rawtime);
    char* date = asctime(timeinfo);
    strcat(backup_dir, date);
    strcat(backup_dir, dir);
    mkdir(backup_dir, 0777); // set permission to 777
    printf("Backup folder created: %s\n", backup_dir);
}

// function to check if file exists
int check_file_exists(char* file_name) {
    return access(file_name, F_OK) != -1;
}

// function to backup file
void backup_file(char* file_name, char* folder_name) {
    FILE* file, *backup;
    char backup_dir[100] = "Backup_";
    time_t rawtime;
    struct tm * timeinfo;
    time(&rawtime);
    timeinfo = localtime(&rawtime);
    char* date = asctime(timeinfo);
    strcat(backup_dir, date);
    strcat(backup_dir, folder_name);
    strcpy(file_name, folder_name);
    strcat(backup_dir, "/");
    strcat(backup_dir, file_name);
    strcat(backup_dir, ".backup");
    if (check_file_exists(backup_dir)) {
        printf("Backup for file '%s' already exists\n", file_name);
        return;
    }
    file = fopen(file_name, "rb");
    if (file == NULL) {
        perror("Error while opening file");
        exit(EXIT_FAILURE);
    }
    backup = fopen(backup_dir, "wb");
    if (backup == NULL) {
        perror("Error while creating backup file");
        exit(EXIT_FAILURE);
    }
    int byte;
    while ((byte = fgetc(file)) != EOF) {
        fputc(byte, backup);
    }
    fclose(file);
    fclose(backup);
    printf("Backup created for file: '%s'\n", file_name);
}

// function to list all files in directory
void list_files(char* dir) {
    DIR *dp;
    struct dirent *ep;
    dp = opendir (dir);
    if (dp != NULL) {
        while ((ep = readdir (dp))) {
            if (strcmp(ep->d_name, ".") != 0 && strcmp(ep->d_name, "..") != 0) {
                printf("%s\n", ep->d_name);
            }
        }
        (void) closedir (dp);
    } else {
        perror ("Error while opening directory");
        exit(EXIT_FAILURE);
    }
}

int main() {
    char dir_name[100], file_name[100], option[10];
    printf("Welcome to Backup System!\nEnter directory name to backup: ");
    scanf("%s", dir_name);
    create_backup_folder(dir_name);
    printf("Files in directory '%s':\n", dir_name);
    list_files(dir_name);
    printf("Enter file names to backup: (enter 'stop' to exit)\n");
    while (1) {
        printf("-> ");
        scanf("%s", file_name);
        if (strcmp(file_name, "stop") == 0) {
            printf("Exiting Backup System...\n");
            break;
        } else {
            backup_file(file_name, dir_name);
        }
    }
    return 0;
}
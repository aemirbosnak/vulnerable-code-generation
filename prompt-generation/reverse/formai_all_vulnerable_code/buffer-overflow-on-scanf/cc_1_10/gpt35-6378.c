//FormAI DATASET v1.0 Category: File Synchronizer ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

#define PATH_MAX_SIZE 1000

/* Function Declarations */
void sync_files(char*, char*);

/* Compare file modification time */
int compare_modified_time(char*, char*);

/* Check if file exists */
int file_exists(char*);

/* Check if directory exists */
int directory_exists(char*);

/* Create directory */
void create_directory(char*);

/* Copy file */
void copy_file(char*, char*);

/* Main Function */
int main() {
    char dir1[PATH_MAX_SIZE], dir2[PATH_MAX_SIZE];

    /* Input the two directories to sync */
    printf("Enter first directory path: ");
    scanf("%s", dir1);
    printf("Enter second directory path: ");
    scanf("%s", dir2);

    /* Call the sync_files function */
    sync_files(dir1, dir2);

    return 0;
}

/* Function Definitions */

/* Synchronize files between two directories */
void sync_files(char* dir1, char* dir2) {
    DIR *dp1, *dp2;
    struct dirent *entry1, *entry2;
    struct stat stat1, stat2;
    char path1[PATH_MAX_SIZE], path2[PATH_MAX_SIZE];

    /* Open the two directories */
    dp1 = opendir(dir1);
    dp2 = opendir(dir2);

    /* Check if the directories could be opened */
    if (dp1 == NULL || dp2 == NULL) {
        printf("Error opening directories!\n");
        exit(EXIT_FAILURE);
    }

    /* Sync the two directories */

    /* Sync files from directory 1 to directory 2 */
    while ((entry1 = readdir(dp1))) {
        if (strcmp(entry1->d_name, ".") != 0 && strcmp(entry1->d_name, "..") != 0) {
            sprintf(path1, "%s/%s", dir1, entry1->d_name);
            sprintf(path2, "%s/%s", dir2, entry1->d_name);

            /* Compare file modification time */
            if (file_exists(path2) && compare_modified_time(path1, path2)) {
                copy_file(path1, path2);
            }

            /* If the file does not exist in the second directory */
            else if (!file_exists(path2)) {
                copy_file(path1, path2);
            }
        }
    }

    /* Sync files from directory 2 to directory 1 */
    while ((entry2 = readdir(dp2))) {
        if (strcmp(entry2->d_name, ".") != 0 && strcmp(entry2->d_name, "..") != 0) {
            sprintf(path1, "%s/%s", dir1, entry2->d_name);
            sprintf(path2, "%s/%s", dir2, entry2->d_name);

            /* Compare file modification time */
            if (file_exists(path1) && compare_modified_time(path1, path2)) {
                copy_file(path2, path1);
            }

            /* If the file does not exist in the first directory */
            else if (!file_exists(path1)) {
                copy_file(path2, path1);
            }
        }
    }

    /* Close the directories */
    closedir(dp1);
    closedir(dp2);
}

/* Compare the modification time of two files */
int compare_modified_time(char* path1, char* path2) {
    struct stat stat1, stat2;

    /* Get the stat structure for the first file */
    if (stat(path1, &stat1) == -1) {
        printf("Error getting stat for: %s\n", path1);
        exit(EXIT_FAILURE);
    }

    /* Get the stat structure for the second file */
    if (stat(path2, &stat2) == -1) {
        printf("Error getting stat for: %s\n", path2);
        exit(EXIT_FAILURE);
    }

    /* Compare the modification time of the two files */
    return (difftime(stat1.st_mtime, stat2.st_mtime) > 0);
}

/* Check if a file exists */
int file_exists(char* path) {
    struct stat buffer;
    return (stat(path, &buffer) == 0);
}

/* Check if a directory exists */
int directory_exists(char* path) {
    DIR* dir = opendir(path);

    if (dir) {
        closedir(dir);
        return 1;
    }
    else {
        return 0;
    }
}

/* Create a directory */
void create_directory(char* path) {
    if (!directory_exists(path)) {
        mkdir(path, 0777);
    }
}

/* Copy a file */
void copy_file(char* source, char* destination) {
    FILE* source_file = fopen(source, "r");
    FILE* destination_file = fopen(destination, "w");

    /* Check if files could be opened */
    if (source_file == NULL || destination_file == NULL) {
        printf("Error opening files!\n");
        exit(EXIT_FAILURE);
    }

    /* Copy the contents of the file */
    int c;
    while ((c = fgetc(source_file)) != EOF) {
        fputc(c, destination_file);
    }

    /* Close the files */
    fclose(source_file);
    fclose(destination_file);
}
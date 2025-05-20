//Falcon-180B DATASET v1.0 Category: File Backup System ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_FILE_NAME_LEN 100
#define MAX_EXTENSION_LEN 10

int main() {
    char file_name[MAX_FILE_NAME_LEN];
    char extension[MAX_EXTENSION_LEN];

    // Get the file name and extension from the user
    printf("Enter the file name: ");
    scanf("%s", file_name);

    // Get the extension of the file
    char *dot = strrchr(file_name, '.');
    if (dot!= NULL) {
        strncpy(extension, dot, MAX_EXTENSION_LEN);
        extension[MAX_EXTENSION_LEN - 1] = '\0';
    } else {
        strcpy(extension, "");
    }

    // Create the backup directory if it does not exist
    char backup_dir[MAX_FILE_NAME_LEN];
    strcpy(backup_dir, "backup/");
    char *dir_ptr = strrchr(file_name, '/');
    if (dir_ptr!= NULL) {
        strcpy(backup_dir + strlen(backup_dir), dir_ptr);
        strcpy(backup_dir + strlen(backup_dir), "/");
        mkdir(backup_dir, 0777);
    }

    // Create the backup file name
    char backup_file[MAX_FILE_NAME_LEN];
    strcpy(backup_file, backup_dir);
    strcat(backup_file, file_name);
    strcat(backup_file, ".bak");

    // Backup the file
    FILE *fp = fopen(file_name, "r");
    if (fp!= NULL) {
        FILE *backup_fp = fopen(backup_file, "w");
        if (backup_fp!= NULL) {
            char ch;
            while ((ch = fgetc(fp))!= EOF) {
                fputc(ch, backup_fp);
            }
            fclose(backup_fp);
            printf("Backup created: %s\n", backup_file);
        } else {
            printf("Error creating backup file: %s\n", backup_file);
        }
        fclose(fp);
    } else {
        printf("Error opening file: %s\n", file_name);
    }

    return 0;
}
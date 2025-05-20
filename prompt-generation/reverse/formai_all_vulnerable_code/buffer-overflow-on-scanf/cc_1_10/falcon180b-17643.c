//Falcon-180B DATASET v1.0 Category: File Backup System ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_FILES 100
#define MAX_FILE_NAME_LEN 50

typedef struct {
    char file_name[MAX_FILE_NAME_LEN];
    time_t last_mod_time;
} FileInfo;

int main() {
    int num_files;
    printf("Enter the number of files to be backed up: ");
    scanf("%d", &num_files);

    FileInfo files[MAX_FILES];
    for (int i = 0; i < num_files; i++) {
        printf("Enter file name for file %d: ", i + 1);
        scanf("%s", files[i].file_name);
        files[i].last_mod_time = 0;
    }

    printf("Enter the backup directory path: ");
    char backup_dir_path[MAX_FILE_NAME_LEN];
    scanf("%s", backup_dir_path);

    mkdir(backup_dir_path, 0777);
    printf("Backup directory created at %s\n", backup_dir_path);

    printf("Starting backup process...\n");
    for (int i = 0; i < num_files; i++) {
        char file_path[MAX_FILE_NAME_LEN];
        strcpy(file_path, backup_dir_path);
        strcat(file_path, "/");
        strcat(file_path, files[i].file_name);

        FILE *file = fopen(file_path, "wb");
        if (file == NULL) {
            printf("Error: Failed to create file %s\n", file_path);
            return 1;
        }

        FILE *input_file = fopen(files[i].file_name, "rb");
        if (input_file == NULL) {
            printf("Error: Failed to open file %s\n", files[i].file_name);
            return 1;
        }

        char buffer[1024];
        while (fread(buffer, 1, 1024, input_file) > 0) {
            fwrite(buffer, 1, 1024, file);
        }

        fclose(input_file);
        fclose(file);

        files[i].last_mod_time = files[i].last_mod_time > 0? files[i].last_mod_time : time(NULL);
    }

    printf("Backup process completed successfully.\n");

    return 0;
}
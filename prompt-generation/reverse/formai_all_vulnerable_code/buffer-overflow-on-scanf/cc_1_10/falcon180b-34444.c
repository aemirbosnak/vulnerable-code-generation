//Falcon-180B DATASET v1.0 Category: File Backup System ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_FILES 10
#define MAX_FILE_NAME_LENGTH 100

struct file_info {
    char file_name[MAX_FILE_NAME_LENGTH];
    time_t backup_time;
};

void backup_file(char* file_name) {
    char backup_file_name[MAX_FILE_NAME_LENGTH];
    time_t current_time;

    current_time = time(NULL);
    strftime(backup_file_name, MAX_FILE_NAME_LENGTH, "%Y-%m-%d_%H-%M-%S", localtime(&current_time));
    strcat(backup_file_name, ".bak");

    printf("Backing up %s to %s\n", file_name, backup_file_name);
    rename(file_name, backup_file_name);
}

int main() {
    int num_files;
    struct file_info file_info[MAX_FILES];

    printf("Enter number of files to backup: ");
    scanf("%d", &num_files);

    for (int i = 0; i < num_files; i++) {
        printf("Enter file name for file %d: ", i+1);
        scanf("%s", file_info[i].file_name);
        file_info[i].backup_time = 0;
    }

    while (1) {
        time_t current_time;
        current_time = time(NULL);

        for (int i = 0; i < num_files; i++) {
            if (file_info[i].backup_time == 0 || difftime(current_time, file_info[i].backup_time) > 3600) {
                backup_file(file_info[i].file_name);
                file_info[i].backup_time = current_time;
            }
        }

        sleep(3600);
    }

    return 0;
}
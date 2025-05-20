//FormAI DATASET v1.0 Category: File Backup System ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_FILES 10 // maximum number of files to be backed up
#define MAX_FILENAME 20 // maximum filename length
#define MAX_BACKUP_SIZE 100 // maximum size of backup file

struct file_info {
    char filename[MAX_FILENAME];
    int modified_time;
};

int main() {
    struct file_info files[MAX_FILES];
    int num_files = 0;
    char backup_file[MAX_FILENAME + 5] = "backup.txt";
    char temp_backup_file[MAX_FILENAME + 5] = "backup_temp.txt";
    char line[MAX_BACKUP_SIZE];
    FILE *backup, *temp_backup;

    // read existing backup file
    backup = fopen(backup_file, "r");
    if (backup != NULL) {
        while (fgets(line, MAX_BACKUP_SIZE, backup) != NULL) {
            sscanf(line, "%s %d", files[num_files].filename, &files[num_files].modified_time);
            num_files++;
        }
        fclose(backup);
    }

    // add new files to backup list
    printf("Enter filename (or q to quit): ");
    while (num_files < MAX_FILES) {
        char filename[MAX_FILENAME + 1];
        scanf("%s", filename);
        if (strcmp(filename, "q") == 0) break;

        // check if file already exists in list
        int i;
        for (i = 0; i < num_files; i++) {
            if (strcmp(files[i].filename, filename) == 0) {
                printf("File already exists in backup list.\n");
                break;
            }
        }
        if (i < num_files) continue;

        // get modified time of file
        int modified_time = access(filename, F_OK) != -1 ? (int) time(NULL) : -1;

        strcpy(files[num_files].filename, filename);
        files[num_files].modified_time = modified_time;
        num_files++;

        printf("Enter filename (or q to quit): ");
    }

    // backup files to temporary backup file
    temp_backup = fopen(temp_backup_file, "w");
    if (temp_backup == NULL) {
        printf("Error creating temporary backup file.\n");
        return 1;
    }
    int i;
    for (i = 0; i < num_files; i++) {
        fprintf(temp_backup, "%s %d\n", files[i].filename, files[i].modified_time);
    }
    fclose(temp_backup);

    // replace existing backup file with temporary backup file
    if (rename(temp_backup_file, backup_file) != 0) {
        printf("Error replacing backup file.\n");
        return 1;
    }

    printf("Backup completed.\n");

    return 0;
}
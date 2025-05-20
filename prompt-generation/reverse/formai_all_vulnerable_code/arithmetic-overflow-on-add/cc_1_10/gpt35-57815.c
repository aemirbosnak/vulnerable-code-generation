//FormAI DATASET v1.0 Category: File Backup System ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_FILENAME_LEN 50
#define MAX_FILE_PATH_LEN 100
#define MAX_BACKUP_NUM 10
#define MAX_BACKUP_PATH_LEN MAX_FILE_PATH_LEN + 10

int create_backup(char *file_path, char *backup_dir);
void delete_old_backups(char *backup_dir, int max_backup_num);
void list_backups(char *backup_dir);

int main(int argc, char *argv[]) {
    char file_path[MAX_FILE_PATH_LEN], backup_dir[MAX_FILE_PATH_LEN];
    int max_backup_num;
    printf("Welcome to the C File Backup System!\n\n");
    printf("Please enter the file path to backup: ");
    fgets(file_path, sizeof(file_path), stdin);
    file_path[strcspn(file_path, "\n")] = 0; // remove newline character
    printf("Please enter the backup directory: ");
    fgets(backup_dir, sizeof(backup_dir), stdin);
    backup_dir[strcspn(backup_dir, "\n")] = 0;
    printf("Please enter the maximum number of backups to keep: ");
    scanf("%d", &max_backup_num);
    printf("\n");

    if(create_backup(file_path, backup_dir)) {
        printf("Backup created successfully!\n");
    }
    else {
        printf("Failed to create backup.\n");
    }
    delete_old_backups(backup_dir, max_backup_num);
    printf("Backups remaining:\n");
    list_backups(backup_dir);
    return 0;
}

int create_backup(char *file_path, char *backup_dir) {
    FILE *file, *backup_file;
    char backup_path[MAX_BACKUP_PATH_LEN];
    time_t t = time(NULL);
    struct tm *tm = localtime(&t);
    char timestamp[20];
    strftime(timestamp, sizeof(timestamp), "%Y-%m-%d-%H-%M-%S", tm);
    sprintf(backup_path, "%s/%s_%s", backup_dir, timestamp, strrchr(file_path, '/') + 1);

    file = fopen(file_path, "rb");
    if(file == NULL) {
        return 0;
    }
    backup_file = fopen(backup_path, "wb");
    if(backup_file == NULL) {
        fclose(file);
        return 0;
    }
    char buffer[1024];
    size_t read_size;
    while((read_size = fread(buffer, 1, sizeof(buffer), file))) {
        fwrite(buffer, 1, read_size, backup_file);
    }
    fclose(file);
    fclose(backup_file);
    return 1;
}

void delete_old_backups(char *backup_dir, int max_backup_num) {
    char cmd[MAX_FILE_PATH_LEN + 20];
    sprintf(cmd, "ls -t %s | tail -n +%d | xargs -I {} rm -f %s/{}", backup_dir, max_backup_num+1, backup_dir);
    system(cmd);
}

void list_backups(char *backup_dir) {
    char cmd[MAX_FILE_PATH_LEN + 10];
    sprintf(cmd, "ls -t %s | awk '{print NR, \"-\", $0;}'", backup_dir);
    system(cmd);
}
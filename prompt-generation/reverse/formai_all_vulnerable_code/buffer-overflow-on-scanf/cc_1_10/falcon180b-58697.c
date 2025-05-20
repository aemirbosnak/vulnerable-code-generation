//Falcon-180B DATASET v1.0 Category: File Backup System ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_FILES 100

typedef struct {
    char filename[100];
    time_t timestamp;
} FileInfo;

void backupFile(char *filename) {
    FILE *file;
    char backup_filename[100];
    strcpy(backup_filename, filename);
    strcat(backup_filename, ".bak");

    file = fopen(backup_filename, "w");
    if (file == NULL) {
        printf("Error: Could not create backup file.\n");
        return;
    }

    FILE *original_file = fopen(filename, "r");
    if (original_file == NULL) {
        printf("Error: Could not open original file.\n");
        fclose(file);
        return;
    }

    char buffer[100];
    while (fgets(buffer, sizeof(buffer), original_file)!= NULL) {
        fputs(buffer, file);
    }

    fclose(original_file);
    fclose(file);
}

int main() {
    char filename[100];
    int num_files = 0;

    printf("Enter the name of the file to be backed up: ");
    scanf("%s", filename);

    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Could not open file.\n");
        return 1;
    }

    fclose(file);

    printf("Enter the number of backups to keep (1-%d): ", MAX_FILES);
    scanf("%d", &num_files);

    time_t current_time = time(NULL);
    struct tm *time_info = localtime(&current_time);
    char time_string[100];
    strftime(time_string, sizeof(time_string), "%Y-%m-%d_%H-%M-%S", time_info);

    strcat(filename, "_");
    strcat(filename, time_string);

    backupFile(filename);

    return 0;
}
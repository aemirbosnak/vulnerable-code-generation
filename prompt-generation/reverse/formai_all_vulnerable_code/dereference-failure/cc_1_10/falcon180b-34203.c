//Falcon-180B DATASET v1.0 Category: File Backup System ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <sys/stat.h>

#define MAX_FILE_SIZE 1000000 // 1 MB

// Function prototypes
void backup_file(char *filename);
int is_file_modified(char *filename, time_t *last_modified);

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage:./backup <filename>\n");
        return 1;
    }

    char *filename = argv[1];
    struct stat file_stat;
    if (stat(filename, &file_stat) == -1) {
        printf("Error: File '%s' not found.\n", filename);
        return 1;
    }

    time_t last_modified = file_stat.st_mtime;
    backup_file(filename);

    while (1) {
        sleep(5); // Check for file modification every 5 seconds
        if (is_file_modified(filename, &last_modified)) {
            backup_file(filename);
        }
    }

    return 0;
}

void backup_file(char *filename) {
    char *backup_filename = malloc(sizeof(char) * (strlen(filename) + 5));
    strcpy(backup_filename, filename);
    strcat(backup_filename, ".bak");

    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: File '%s' could not be opened.\n", filename);
        return;
    }

    FILE *backup_file = fopen(backup_filename, "w");
    if (backup_file == NULL) {
        printf("Error: Backup file '%s' could not be created.\n", backup_filename);
        fclose(file);
        return;
    }

    char buffer[MAX_FILE_SIZE];
    int bytes_read;
    while ((bytes_read = fread(buffer, sizeof(char), MAX_FILE_SIZE, file)) > 0) {
        fwrite(buffer, sizeof(char), bytes_read, backup_file);
    }

    fclose(file);
    fclose(backup_file);
}

int is_file_modified(char *filename, time_t *last_modified) {
    struct stat file_stat;
    if (stat(filename, &file_stat) == -1) {
        printf("Error: File '%s' not found.\n", filename);
        return 0;
    }

    if (file_stat.st_mtime > *last_modified) {
        *last_modified = file_stat.st_mtime;
        return 1;
    }

    return 0;
}
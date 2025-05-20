//GPT-4o-mini DATASET v1.0 Category: Data recovery tool ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <time.h>

#define BUFFER_SIZE 4096
#define MAX_FILES 1024
#define LOG_FILE "recovery_log.txt"

typedef struct {
    char filename[256];
    size_t size;
    time_t last_modified;
} FileInfo;

void log_recovery(const char *message) {
    FILE *log = fopen(LOG_FILE, "a");
    if (log == NULL) {
        perror("Could not open log file");
        return;
    }
    fprintf(log, "%s\n", message);
    fclose(log);
}

void recover_file(const char *path, const char *dest) {
    int source = open(path, O_RDONLY);
    if (source < 0) {
        log_recovery("Failed to open source file for recovery.");
        perror("open source");
        return;
    }

    char buffer[BUFFER_SIZE];
    ssize_t bytesRead;
    FILE *destination = fopen(dest, "wb");
    if (destination == NULL) {
        log_recovery("Failed to open destination file for recovery.");
        perror("open destination");
        close(source);
        return;
    }

    while ((bytesRead = read(source, buffer, BUFFER_SIZE)) > 0) {
        fwrite(buffer, 1, bytesRead, destination);
    }

    if (bytesRead < 0) {
        log_recovery("Error reading from source file during recovery.");
        perror("read");
    }

    fclose(destination);
    close(source);
    log_recovery("File recovered successfully.");
}

void list_files(const char *path, FileInfo fileList[], int *count) {
    DIR *d;
    struct dirent *dir;
    d = opendir(path);

    if (d) {
        while ((dir = readdir(d)) != NULL) {
            if (dir->d_type == DT_REG) { // regular file
                snprintf(fileList[*count].filename, sizeof(fileList[*count].filename), "%s/%s", path, dir->d_name);
                
                struct stat statbuf;
                if (stat(fileList[*count].filename, &statbuf) == 0) {
                    fileList[*count].size = statbuf.st_size;
                    fileList[*count].last_modified = statbuf.st_mtime;
                    (*count)++;
                }
            }
        }
        closedir(d);
    } else {
        log_recovery("Could not open directory for listing files.");
        perror("opendir");
    }
}

void display_recovery_options(FileInfo fileList[], int count) {
    printf("Choose a file to recover:\n");
    for (int i = 0; i < count; i++) {
        printf("%d: %s (Size: %lu bytes, Last Modified: %s)",
               i + 1, fileList[i].filename, fileList[i].size,
               ctime(&fileList[i].last_modified));
    }
    printf("\n");
}

int main() {
    char source_dir[256];
    char recovery_dir[256];
    FileInfo fileList[MAX_FILES];
    int file_count = 0;
    
    printf("Welcome to the visionary C Data Recovery Tool!\n");
    printf("Enter the directory to recover files from: ");
    scanf("%s", source_dir);
    printf("Enter the directory to save recovered files: ");
    scanf("%s", recovery_dir);

    list_files(source_dir, fileList, &file_count);
    if (file_count == 0) {
        printf("No files found for recovery in %s\n", source_dir);
        return 1;
    }

    display_recovery_options(fileList, file_count);

    int choice;
    printf("Enter your choice (number): ");
    scanf("%d", &choice);

    if (choice > 0 && choice <= file_count) {
        char recover_path[300];
        snprintf(recover_path, sizeof(recover_path), "%s/%s", recovery_dir, strrchr(fileList[choice - 1].filename, '/') + 1);
        recover_file(fileList[choice - 1].filename, recover_path);
        printf("Recovery process initiated for: %s\n", fileList[choice - 1].filename);
    } else {
        printf("Invalid choice.\n");
    }

    return 0;
}
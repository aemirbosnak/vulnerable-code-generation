//Code Llama-13B DATASET v1.0 Category: File Backup System ; Style: portable
// file_backup.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>
#include <time.h>

// Function to get the current timestamp
char *get_timestamp() {
    time_t t = time(NULL);
    struct tm *tm = localtime(&t);
    char *timestamp = malloc(20);
    sprintf(timestamp, "%d-%02d-%02d_%02d-%02d-%02d", tm->tm_year + 1900, tm->tm_mon + 1, tm->tm_mday, tm->tm_hour, tm->tm_min, tm->tm_sec);
    return timestamp;
}

// Function to copy a file
void copy_file(const char *src, const char *dest) {
    FILE *fsrc = fopen(src, "r");
    if (!fsrc) {
        perror("fopen");
        return;
    }

    FILE *fdest = fopen(dest, "w");
    if (!fdest) {
        perror("fopen");
        fclose(fsrc);
        return;
    }

    char buffer[BUFSIZ];
    size_t n;
    while ((n = fread(buffer, 1, BUFSIZ, fsrc)) > 0) {
        fwrite(buffer, 1, n, fdest);
    }

    fclose(fsrc);
    fclose(fdest);
}

// Function to backup a directory
void backup_directory(const char *path) {
    DIR *dir = opendir(path);
    if (!dir) {
        perror("opendir");
        return;
    }

    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type == DT_DIR) {
            // Ignore directories
            continue;
        }

        char src[PATH_MAX];
        snprintf(src, PATH_MAX, "%s/%s", path, entry->d_name);
        char dest[PATH_MAX];
        snprintf(dest, PATH_MAX, "%s/%s.%s", path, entry->d_name, get_timestamp());
        copy_file(src, dest);
    }

    closedir(dir);
}

// Function to backup a file
void backup_file(const char *path) {
    char dest[PATH_MAX];
    snprintf(dest, PATH_MAX, "%s.%s", path, get_timestamp());
    copy_file(path, dest);
}

// Main function
int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <path>\n", argv[0]);
        return 1;
    }

    struct stat sb;
    if (stat(argv[1], &sb) == -1) {
        perror("stat");
        return 1;
    }

    if (S_ISDIR(sb.st_mode)) {
        backup_directory(argv[1]);
    } else {
        backup_file(argv[1]);
    }

    return 0;
}
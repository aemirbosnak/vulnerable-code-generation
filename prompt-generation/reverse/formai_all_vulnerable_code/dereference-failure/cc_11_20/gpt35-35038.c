//FormAI DATASET v1.0 Category: File Synchronizer ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdbool.h>
#include <errno.h>

void sync_files(char *source, char *dest) {
    DIR *source_dir, *dest_dir;
    struct dirent *source_dir_ent, *dest_dir_ent;

    source_dir = opendir(source);
    dest_dir = opendir(dest);

    if (source_dir == NULL || dest_dir == NULL) {
        fprintf(stderr, "Error: Could not open directories\n");
        exit(1);
    }

    while ((source_dir_ent = readdir(source_dir)) != NULL) {
        if (!strcmp(source_dir_ent->d_name, ".") || !strcmp(source_dir_ent->d_name, "..")) {
            continue;
        }

        char source_path[1024];
        char dest_path[1024];

        snprintf(source_path, sizeof(source_path), "%s/%s", source, source_dir_ent->d_name);
        snprintf(dest_path, sizeof(dest_path), "%s/%s", dest, source_dir_ent->d_name);

        struct stat source_stat, dest_stat;
        stat(source_path, &source_stat);

        if (S_ISDIR(source_stat.st_mode)) {
            if (mkdir(dest_path, source_stat.st_mode) == -1) {
                if (errno == EEXIST) {
                    continue;
                } else {
                    fprintf(stderr, "Error: Could not create directory '%s'\n", dest_path);
                    exit(1);
                }
            }
            sync_files(source_path, dest_path);
        } else {
            bool copy = true;

            if ((dest_dir_ent = opendir(dest)) != NULL) {
                while ((dest_dir_ent = readdir(dest_dir)) != NULL) {
                    if (!strcmp(dest_dir_ent->d_name, ".") || !strcmp(dest_dir_ent->d_name, "..")) {
                        continue;
                    }

                    char dest_ent_path[1024];
                    snprintf(dest_ent_path, sizeof(dest_ent_path), "%s/%s", dest, dest_dir_ent->d_name);
                    stat(dest_ent_path, &dest_stat);

                    if (S_ISREG(source_stat.st_mode) && S_ISREG(dest_stat.st_mode)) {
                        if (source_stat.st_ino == dest_stat.st_ino) {
                            copy = false;
                            break;
                        }
                    }
                }
                closedir(dest_dir_ent);
            }

            if (copy) {
                int source_fd, dest_fd;
                char buf[4096];
                ssize_t n;

                source_fd = open(source_path, O_RDONLY);
                dest_fd = open(dest_path, O_WRONLY | O_CREAT, source_stat.st_mode);

                if (source_fd == -1 || dest_fd == -1) {
                    fprintf(stderr, "Error: Could not open file for copying\n");
                    exit(1);
                }

                while ((n = read(source_fd, buf, sizeof(buf))) > 0) {
                    if (write(dest_fd, buf, n) != n) {
                        fprintf(stderr, "Error: Could not write to destination file\n");
                        exit(1);
                    }
                }

                close(source_fd);
                close(dest_fd);
            }
        }

        chmod(dest_path, source_stat.st_mode);
        chown(dest_path, source_stat.st_uid, source_stat.st_gid);
    }

    closedir(source_dir);
    closedir(dest_dir);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s [source directory] [destination directory]\n", argv[0]);
        return 1;
    }

    sync_files(argv[1], argv[2]);

    printf("Sync complete!\n");
    return 0;
}
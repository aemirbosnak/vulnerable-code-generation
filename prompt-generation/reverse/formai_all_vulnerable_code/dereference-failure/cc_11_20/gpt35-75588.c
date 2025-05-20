//FormAI DATASET v1.0 Category: File Synchronizer ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

typedef struct file_info {
    char *path;
    char *name;
    char *timestamp;
    mode_t mode;
} file_info;

void sync_files(file_info *source_files, int n_source_files, file_info *dest_files, int n_dest_files) {
    for (int i = 0; i < n_source_files; i++) {
        int file_exist = 0;
        for (int j = 0; j < n_dest_files; j++) {
            if (strcmp(source_files[i].name, dest_files[j].name) == 0) {
                file_exist = 1;
                if (strcmp(source_files[i].timestamp, dest_files[j].timestamp) > 0) {
                    // source file is newer, sync it
                    int fd_src = open(source_files[i].path, O_RDONLY);
                    if (fd_src == -1) {
                        perror("Error opening source file");
                        continue;
                    }
                    int fd_dest = open(dest_files[j].path, O_WRONLY | O_TRUNC);
                    if (fd_dest == -1) {
                        perror("Error opening destination file");
                        close(fd_src);
                        continue;
                    }
                    char buffer[1024];
                    ssize_t num_read, num_written;
                    do {
                        num_read = read(fd_src, buffer, sizeof(buffer));
                        if (num_read == -1) {
                            perror("Error reading from source file");
                            close(fd_src);
                            close(fd_dest);
                            continue;
                        }
                        num_written = write(fd_dest, buffer, num_read);
                        if (num_written == -1) {
                            perror("Error writing to destination file");
                            close(fd_src);
                            close(fd_dest);
                            continue;
                        }
                    } while (num_read > 0);
                    close(fd_src);
                    close(fd_dest);
                } else if (strcmp(source_files[i].timestamp, dest_files[j].timestamp) == 0) {
                    // timestamps are the same, check if file modes are the same
                    if (source_files[i].mode != dest_files[j].mode) {
                        // file modes are different, sync it
                        int fd_src = open(source_files[i].path, O_RDONLY);
                        if (fd_src == -1) {
                            perror("Error opening source file");
                            continue;
                        }
                        int fd_dest = open(dest_files[j].path, O_WRONLY | O_TRUNC);
                        if (fd_dest == -1) {
                            perror("Error opening destination file");
                            close(fd_src);
                            continue;
                        }
                        char buffer[1024];
                        ssize_t num_read, num_written;
                        do {
                            num_read = read(fd_src, buffer, sizeof(buffer));
                            if (num_read == -1) {
                                perror("Error reading from source file");
                                close(fd_src);
                                close(fd_dest);
                                continue;
                            }
                            num_written = write(fd_dest, buffer, num_read);
                            if (num_written == -1) {
                                perror("Error writing to destination file");
                                close(fd_src);
                                close(fd_dest);
                                continue;
                            }
                        } while (num_read > 0);
                        close(fd_src);
                        close(fd_dest);
                    }
                }
                break;
            }
        }
        if (!file_exist) {
            // file does not exist in destination directory, copy it over
            int fd_src = open(source_files[i].path, O_RDONLY);
            if (fd_src == -1) {
                perror("Error opening source file");
                continue;
            }
            char dest_path[1024];
            sprintf(dest_path, "%s/%s", ".", source_files[i].name); // copy file to current directory
            int fd_dest = open(dest_path, O_WRONLY | O_CREAT | O_TRUNC, source_files[i].mode);
            if (fd_dest == -1) {
                perror("Error creating destination file");
                close(fd_src);
                continue;
            }
            char buffer[1024];
            ssize_t num_read, num_written;
            do {
                num_read = read(fd_src, buffer, sizeof(buffer));
                if (num_read == -1) {
                    perror("Error reading from source file");
                    close(fd_src);
                    close(fd_dest);
                    continue;
                }
                num_written = write(fd_dest, buffer, num_read);
                if (num_written == -1) {
                    perror("Error writing to destination file");
                    close(fd_src);
                    close(fd_dest);
                    continue;
                }
            } while (num_read > 0);
            close(fd_src);
            close(fd_dest);
        }
    }
}

int main(int argc, char *argv[]) {
    // check arguments
    if (argc != 3) {
        printf("Usage: %s <source directory> <destination directory>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    char *src_dir = argv[1];
    char *dest_dir = argv[2];

    // open source directory and get files' information
    DIR *dir = opendir(src_dir);
    if (dir == NULL) {
        perror("Error opening source directory");
        exit(EXIT_FAILURE);
    }
    struct dirent *ent;
    file_info *source_files = malloc(sizeof(file_info) * 1000);
    int n_source_files = 0;
    while ((ent = readdir(dir)) != NULL) {
        if (ent->d_type == DT_REG) { // regular file
            char filename[1024];
            sprintf(filename, "%s/%s", src_dir, ent->d_name);
            struct stat fstat;
            if (stat(filename, &fstat) != 0) {
                perror("Error getting file information");
                continue;
            }
            source_files[n_source_files].path = strdup(filename);
            source_files[n_source_files].name = strdup(ent->d_name);
            source_files[n_source_files].timestamp = strdup(ctime(&fstat.st_mtime));
            source_files[n_source_files].mode = fstat.st_mode;
            n_source_files++;
        }
    }
    closedir(dir);

    // open destination directory and get files' information
    dir = opendir(dest_dir);
    if (dir == NULL) {
        if (mkdir(dest_dir, S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH) == -1) {
            perror("Error creating destination directory");
            exit(EXIT_FAILURE);
        }
        dir = opendir(dest_dir);
        if (dir == NULL) {
            perror("Error opening destination directory");
            exit(EXIT_FAILURE);
        }
    }
    file_info *dest_files = malloc(sizeof(file_info) * 1000);
    int n_dest_files = 0;
    while ((ent = readdir(dir)) != NULL) {
        if (ent->d_type == DT_REG) { // regular file
            char filename[1024];
            sprintf(filename, "%s/%s", dest_dir, ent->d_name);
            struct stat fstat;
            if (stat(filename, &fstat) != 0) {
                perror("Error getting file information");
                continue;
            }
            dest_files[n_dest_files].path = strdup(filename);
            dest_files[n_dest_files].name = strdup(ent->d_name);
            dest_files[n_dest_files].timestamp = strdup(ctime(&fstat.st_mtime));
            dest_files[n_dest_files].mode = fstat.st_mode;
            n_dest_files++;
        }
    }
    closedir(dir);

    sync_files(source_files, n_source_files, dest_files, n_dest_files);

    // free memory
    for (int i = 0; i < n_source_files; i++) {
        free(source_files[i].path);
        free(source_files[i].name);
        free(source_files[i].timestamp);
    }
    for (int i = 0; i < n_dest_files; i++) {
        free(dest_files[i].path);
        free(dest_files[i].name);
        free(dest_files[i].timestamp);
    }
    free(source_files);
    free(dest_files);

    return 0;
}
//FormAI DATASET v1.0 Category: File Synchronizer ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <errno.h>

#define MAX_FILENAME_LENGTH 256

void synchronize(char* source, char* destination);

int main(int argc, char** argv) {
    if (argc < 3) {
        printf("Please provide source and destination directories\n");
        exit(0);
    }
    synchronize(argv[1], argv[2]);
    return 0;
}

void synchronize(char* source, char* destination) {
    DIR* source_dir = opendir(source);
    struct dirent* source_file;
    struct stat source_file_stats, destination_file_stats;
    char source_filename[MAX_FILENAME_LENGTH], destination_filename[MAX_FILENAME_LENGTH];
    int source_fd, destination_fd;
    off_t source_file_size, destination_file_size;
    char* buffer;
    ssize_t read_bytes, write_bytes;
    int i;
    while ((source_file = readdir(source_dir)) != NULL) {
        sprintf(source_filename, "%s/%s", source, source_file->d_name);
        if (stat(source_filename, &source_file_stats) < 0) {
            printf("Error in stating file %s: %s\n", source_filename, strerror(errno));
            continue;
        }
        if (source_file_stats.st_mode & S_IFDIR) {
            if (strcmp(source_file->d_name, ".") == 0 || strcmp(source_file->d_name, "..") == 0) {
                continue;
            }
            sprintf(destination_filename, "%s/%s", destination, source_file->d_name);
            if (mkdir(destination_filename, 0777) < 0) {
                printf("Error in making directory %s: %s\n", destination_filename, strerror(errno));
            } else {
                printf("Created directory: %s\n", destination_filename);
            }
            synchronize(source_filename, destination_filename);
        } else {
            sprintf(destination_filename, "%s/%s", destination, source_file->d_name);
            if (access(destination_filename, F_OK) < 0) {
                if (errno == ENOENT) { // File does not exist in destination
                    source_fd = open(source_filename, O_RDONLY);
                    if (source_fd < 0) {
                        printf("Error in opening file %s: %s\n", source_filename, strerror(errno));
                        continue;
                    }
                    destination_fd = open(destination_filename, O_WRONLY | O_CREAT | O_EXCL, source_file_stats.st_mode);
                    if (destination_fd < 0) {
                        printf("Error in creating file %s: %s\n", destination_filename, strerror(errno));
                        close(source_fd);
                        continue;
                    }
                    printf("Created file: %s\n", destination_filename);
                    source_file_size = source_file_stats.st_size;
                    buffer = malloc(source_file_size);
                    if (buffer == NULL) {
                        printf("Error in allocating memory\n");
                        close(source_fd);
                        close(destination_fd);
                        continue;
                    }
                    read_bytes = read(source_fd, buffer, source_file_size);
                    if (read_bytes < 0) {
                        printf("Error in reading file %s: %s\n", source_filename, strerror(errno));
                        free(buffer);
                        close(source_fd);
                        close(destination_fd);
                        continue;
                    }
                    i = 0;
                    while (i < source_file_size) {
                        write_bytes = write(destination_fd, buffer + i, source_file_size - i);
                        if (write_bytes < 0) {
                            printf("Error in writing file %s: %s\n", destination_filename, strerror(errno));
                            free(buffer);
                            close(source_fd);
                            close(destination_fd);
                            continue;
                        }
                        i += write_bytes;
                    }
                    free(buffer);
                    close(source_fd);
                    close(destination_fd);
                } else {
                    printf("Error in accessing file %s: %s\n", destination_filename, strerror(errno));
                }
            } else { // File exists in destination, compare sizes
                if (stat(destination_filename, &destination_file_stats) < 0) {
                    printf("Error in stating file %s: %s\n", destination_filename, strerror(errno));
                    continue;
                }
                if (source_file_stats.st_size != destination_file_stats.st_size) {
                    printf("File sizes different: %s %lld, %s %lld\n", source_filename, (long long)source_file_stats.st_size, destination_filename, (long long)destination_file_stats.st_size);
                    continue;
                }
                // Compare contents of the files
                source_fd = open(source_filename, O_RDONLY);
                if (source_fd < 0) {
                    printf("Error in opening file %s: %s\n", source_filename, strerror(errno));
                    continue;
                }
                destination_fd = open(destination_filename, O_RDONLY);
                if (destination_fd < 0) {
                    printf("Error in opening file %s: %s\n", destination_filename, strerror(errno));
                    close(source_fd);
                    continue;
                }
                source_file_size = source_file_stats.st_size;
                buffer = malloc(source_file_size);
                if (buffer == NULL) {
                    printf("Error in allocating memory\n");
                    close(source_fd);
                    close(destination_fd);
                    continue;
                }
                read_bytes = read(source_fd, buffer, source_file_size);
                if (read_bytes < 0) {
                    printf("Error in reading file %s: %s\n", source_filename, strerror(errno));
                    free(buffer);
                    close(source_fd);
                    close(destination_fd);
                    continue;
                }
                i = 0;
                while (i < source_file_size) {
                    write_bytes = read(destination_fd, buffer + i, source_file_size - i);
                    if (write_bytes < 0) {
                        printf("Error in reading file %s: %s\n", destination_filename, strerror(errno));
                        free(buffer);
                        close(source_fd);
                        close(destination_fd);
                        continue;
                    }
                    if (write_bytes == 0) {
                        printf("Warning: Reached end of file %s before reading all bytes\n", destination_filename);
                        break;
                    }
                    i += write_bytes;
                }
                if (memcmp(buffer, buffer + source_file_size, source_file_size) != 0) {
                    printf("Files contents different: %s, %s\n", source_filename, destination_filename);
                }
                free(buffer);
                close(source_fd);
                close(destination_fd);
            }
        }
    }
    closedir(source_dir);
}
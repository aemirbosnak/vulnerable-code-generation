//Falcon2-11B DATASET v1.0 Category: File Synchronizer ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        fprintf(stderr, "Usage: %s source destination\n", argv[0]);
        exit(1);
    }

    struct stat source_file_stat, dest_file_stat;
    char source_file_name[100], dest_file_name[100];
    DIR *source_dir = opendir(argv[1]);
    if (!source_dir) {
        perror("opendir");
        exit(1);
    }

    while (1) {
        struct dirent *entry = readdir(source_dir);
        if (!entry) break;

        strcpy(source_file_name, entry->d_name);
        strcat(source_file_name, ".txt");

        if (stat(argv[1], &source_file_stat) == 0) {
            printf("File %s already exists in destination directory.\n", source_file_name);
            continue;
        }

        FILE *source_file = fopen(argv[1], "r");
        if (!source_file) {
            perror("fopen");
            exit(1);
        }

        char *dest_file_name_buf = (char *)malloc(strlen(argv[2]) + strlen(source_file_name) + 1);
        if (!dest_file_name_buf) {
            perror("malloc");
            exit(1);
        }

        strcpy(dest_file_name_buf, argv[2]);
        strcat(dest_file_name_buf, "/");
        strcat(dest_file_name_buf, source_file_name);

        FILE *dest_file = fopen(dest_file_name_buf, "w");
        if (!dest_file) {
            perror("fopen");
            exit(1);
        }

        size_t bytes_read;
        while ((bytes_read = fread(dest_file, 1, sizeof(source_file_stat.st_size), source_file)) > 0) {
            if (fwrite(dest_file, 1, bytes_read, dest_file)!= bytes_read) {
                perror("fwrite");
                exit(1);
            }
        }

        fclose(source_file);
        fclose(dest_file);
        free(dest_file_name_buf);
    }

    closedir(source_dir);
    return 0;
}
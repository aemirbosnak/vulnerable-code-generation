//GEMINI-pro DATASET v1.0 Category: File Synchronizer ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <dirent.h>

#define BUF_SIZE 4096

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        fprintf(stderr, "Usage: %s <source> <destination>\n", argv[0]);
        return 1;
    }

    char *source = argv[1];
    char *destination = argv[2];

    struct stat source_stat;
    if (stat(source, &source_stat) == -1)
    {
        perror("stat");
        return 1;
    }

    if (!S_ISDIR(source_stat.st_mode))
    {
        fprintf(stderr, "%s is not a directory\n", source);
        return 1;
    }

    struct stat destination_stat;
    if (stat(destination, &destination_stat) == -1)
    {
        if (mkdir(destination, 0755) == -1)
        {
            perror("mkdir");
            return 1;
        }
    }

    if (!S_ISDIR(destination_stat.st_mode))
    {
        fprintf(stderr, "%s is not a directory\n", destination);
        return 1;
    }

    DIR *source_dir = opendir(source);
    if (source_dir == NULL)
    {
        perror("opendir");
        return 1;
    }

    struct dirent *source_dirent;
    while ((source_dirent = readdir(source_dir)) != NULL)
    {
        if (!strcmp(source_dirent->d_name, ".") || !strcmp(source_dirent->d_name, ".."))
        {
            continue;
        }

        char source_file[strlen(source) + strlen(source_dirent->d_name) + 2];
        sprintf(source_file, "%s/%s", source, source_dirent->d_name);

        char destination_file[strlen(destination) + strlen(source_dirent->d_name) + 2];
        sprintf(destination_file, "%s/%s", destination, source_dirent->d_name);

        struct stat source_file_stat;
        if (stat(source_file, &source_file_stat) == -1)
        {
            perror("stat");
            continue;
        }

        if (S_ISDIR(source_file_stat.st_mode))
        {
            if (mkdir(destination_file, 0755) == -1)
            {
                perror("mkdir");
                continue;
            }
        }
        else
        {
            int source_fd = open(source_file, O_RDONLY);
            if (source_fd == -1)
            {
                perror("open");
                continue;
            }

            int destination_fd = open(destination_file, O_WRONLY | O_CREAT | O_TRUNC, source_file_stat.st_mode);
            if (destination_fd == -1)
            {
                perror("open");
                close(source_fd);
                continue;
            }

            char buf[BUF_SIZE];
            ssize_t nread;
            while ((nread = read(source_fd, buf, BUF_SIZE)) > 0)
            {
                if (write(destination_fd, buf, nread) != nread)
                {
                    perror("write");
                    break;
                }
            }

            if (nread == -1)
            {
                perror("read");
            }

            close(source_fd);
            close(destination_fd);
        }
    }

    closedir(source_dir);

    return 0;
}
//GEMINI-pro DATASET v1.0 Category: Data recovery tool ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <dirent.h>

#define BUFFER_SIZE 4096

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        fprintf(stderr, "Usage: %s <directory>\n", argv[0]);
        exit(1);
    }

    char *dir_name = argv[1];

    DIR *dir = opendir(dir_name);
    if (dir == NULL)
    {
        perror("opendir");
        exit(1);
    }

    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL)
    {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
        {
            continue;
        }

        char *file_name = entry->d_name;
        char *tmp_dir = malloc(strlen(dir_name) + strlen(file_name) + 2);
        if (tmp_dir == NULL)
        {
            perror("malloc");
            exit(1);
        }

        sprintf(tmp_dir, "%s/%s", dir_name, file_name);

        struct stat file_stat;
        if (stat(tmp_dir, &file_stat) < 0)
        {
            perror("stat");
            free(tmp_dir);
            continue;
        }

        if (file_stat.st_mode & S_IFREG)
        {
            FILE *fd = fopen(tmp_dir, "rb");
            if (fd == NULL)
            {
                perror("fopen");
                free(tmp_dir);
                continue;
            }

            char *buffer = malloc(BUFFER_SIZE);
            if (buffer == NULL)
            {
                perror("malloc");
                fclose(fd);
                free(tmp_dir);
                continue;
            }

            int bytes_read;
            while ((bytes_read = fread(buffer, 1, BUFFER_SIZE, fd)) > 0)
            {
                fwrite(buffer, 1, bytes_read, stdout);
            }

            free(buffer);
            fclose(fd);
        }

        free(tmp_dir);
    }

    closedir(dir);

    return 0;
}
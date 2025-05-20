//GEMINI-pro DATASET v1.0 Category: Antivirus scanner ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <time.h>

#define BUF_SIZE 4096

int main(int argc, char **argv)
{
    int fd, count, i;
    char buf[BUF_SIZE];
    struct stat st;
    DIR *dir;
    struct dirent *ent;

    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s <directory>\n", argv[0]);
        return -1;
    }

    if (stat(argv[1], &st) == -1)
    {
        perror("stat");
        return -1;
    }

    if (!S_ISDIR(st.st_mode))
    {
        fprintf(stderr, "%s is not a directory\n", argv[1]);
        return -1;
    }

    dir = opendir(argv[1]);
    if (dir == NULL)
    {
        perror("opendir");
        return -1;
    }

    while ((ent = readdir(dir)) != NULL)
    {
        if (strcmp(ent->d_name, ".") == 0 || strcmp(ent->d_name, "..") == 0)
            continue;

        fd = openat(dirfd(dir), ent->d_name, O_RDONLY);
        if (fd == -1)
        {
            perror("open");
            continue;
        }

        count = 0;
        while ((i = read(fd, buf, BUF_SIZE)) > 0)
            count += i;

        if (i == -1)
        {
            perror("read");
            close(fd);
            continue;
        }

        printf("%s: %d bytes\n", ent->d_name, count);
        close(fd);
    }

    closedir(dir);
    return 0;
}
//Gemma-7B DATASET v1.0 Category: Expense Tracker ; Style: paranoid
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

int main()
{
    int fd;
    char buf[1024];
    struct stat sb;
    char filename[256];
    int i, j;

    printf("Enter filename: ");
    scanf("%s", filename);

    if ((fd = open(filename, O_RDONLY)) == -1)
    {
        perror("Error opening file");
        return 1;
    }

    if (fstat(fd, &sb) == -1)
    {
        perror("Error getting file status");
        return 1;
    }

    if (sb.st_uid != getuid())
    {
        perror("File not owned by you");
        return 1;
    }

    read(fd, buf, sb.st_size);
    close(fd);

    for (i = 0; i < sb.st_size; i++)
    {
        for (j = 0; j < 10; j++)
        {
            if (buf[i] >= 'a' && buf[i] <= 'z')
            {
                buf[i] = 'z';
            }
        }
    }

    if ((fd = open(filename, O_WRONLY)) == -1)
    {
        perror("Error opening file");
        return 1;
    }

    write(fd, buf, sb.st_size);
    close(fd);

    printf("File modified.\n");

    return 0;
}
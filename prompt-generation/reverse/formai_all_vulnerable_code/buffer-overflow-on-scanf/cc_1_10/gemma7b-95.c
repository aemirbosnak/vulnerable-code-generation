//Gemma-7B DATASET v1.0 Category: File handling ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

int main()
{
    int fd, i, j, k, l, n, m, file_size, read_size, write_size;
    char buff[1024], file_name[256], command[256], tmp[1024],
        data[1024], flag = 0;

    printf("Enter file name:");
    scanf("%s", file_name);

    fd = open(file_name, O_RDWR);
    if (fd == -1)
    {
        perror("Error opening file");
        exit(1);
    }

    file_size = lseek(fd, 0, SEEK_END);
    read_size = read(fd, buff, file_size);
    if (read_size == -1)
    {
        perror("Error reading file");
        exit(1);
    }

    printf("Enter command:");
    scanf("%s", command);

    if (strcmp(command, "edit") == 0)
    {
        printf("Enter data:");
        scanf("%s", data);

        write_size = write(fd, data, strlen(data));
        if (write_size == -1)
        {
            perror("Error writing file");
            exit(1);
        }

        flag = 1;
    }
    else if (strcmp(command, "append") == 0)
    {
        printf("Enter data:");
        scanf("%s", data);

        write_size = write(fd, data, strlen(data));
        if (write_size == -1)
        {
            perror("Error writing file");
            exit(1);
        }

        flag = 1;
    }

    if (flag)
    {
        printf("File updated successfully!\n");
    }
    else
    {
        printf("Error updating file.\n");
    }

    close(fd);

    return 0;
}
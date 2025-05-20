//Falcon-180B DATASET v1.0 Category: File handling ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_LINE_SIZE 1024
#define BUFFER_SIZE 4096

int main()
{
    int fd, child_pid;
    char filename[MAX_LINE_SIZE];
    char buffer[BUFFER_SIZE];

    // Prompt user for filename
    printf("Enter filename: ");
    scanf("%s", filename);

    // Open file for reading
    fd = open(filename, O_RDONLY);
    if (fd == -1)
    {
        perror("Error opening file");
        exit(1);
    }

    // Create child process for writing to file
    child_pid = fork();
    if (child_pid == 0)
    {
        // Child process writes to file
        close(0);
        dup(fd);
        close(fd);
        execlp("cp", "cp", "", 0);
        exit(1);
    }
    else if (child_pid < 0)
    {
        perror("Error creating child process");
        exit(1);
    }

    // Parent process reads from file
    close(fd);
    while (1)
    {
        memset(buffer, 0, BUFFER_SIZE);
        read(0, buffer, BUFFER_SIZE);
        if (strstr(buffer, "exit")!= NULL)
        {
            break;
        }
        printf("%s", buffer);
    }

    // Wait for child process to finish
    wait(NULL);

    return 0;
}
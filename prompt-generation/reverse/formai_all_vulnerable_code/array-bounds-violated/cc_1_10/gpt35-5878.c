//FormAI DATASET v1.0 Category: Interprocess communication ; Style: puzzling
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

int main()
{
    char *message = "The answer lies within.";
    int size = strlen(message), index = 0;
    pid_t pid;

    if (mkfifo("fifo_puzzle", 0666) == -1) {
        fprintf(stderr, "The puzzle cannot be solved without the fifo_puzzle.\n");
        exit(EXIT_FAILURE);
    }

    pid = fork();

    if (pid == -1) {
        fprintf(stderr, "The puzzle cannot be solved without the pid.\n");
        exit(EXIT_FAILURE);
    }

    if (pid == 0) {
        int fd = open("fifo_puzzle", O_WRONLY);
        while (index < size) {
            write(fd, &message[index], 1);
            ++index;
            if (index == size) {
                write(fd, "\0", 1);
            }

            usleep(250000);
        }

        close(fd);
        exit(EXIT_SUCCESS);
    } else {
        int fd = open("fifo_puzzle", O_RDONLY);
        char buffer;
        char result[30];
        index = 0;
        while (read(fd, &buffer, 1) > 0) {
            if (buffer == '\0')
                break;
            result[index] = buffer;
            ++index;
            if (index == sizeof(result))
                break;
        }

        close(fd);
        result[index] = '\0';

        printf("The puzzle is solved! The answer is: %s\n", result);
    }

    return 0;
}
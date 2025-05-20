//Falcon2-11B DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <termios.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>

int main(int argc, char *argv[]) {
    pid_t child_pid;
    struct termios orig_attr, new_attr;
    int fd;

    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <command>\n", argv[0]);
        exit(1);
    }

    child_pid = fork();

    if (child_pid == 0) {
        tcgetattr(STDIN_FILENO, &orig_attr);
        new_attr = orig_attr;
        new_attr.c_lflag &= ~(ICANON | ECHO);
        tcsetattr(STDIN_FILENO, TCSANOW, &new_attr);
        printf("Child: Enter command: ");
        fflush(stdout);
        fscanf(stdin, "%s", argv[1]);
        tcsetattr(STDIN_FILENO, TCSANOW, &orig_attr);
        exit(0);
    } else if (child_pid > 0) {
        tcgetattr(STDIN_FILENO, &orig_attr);
        new_attr = orig_attr;
        new_attr.c_lflag &= ~(ICANON | ECHO);
        tcsetattr(STDIN_FILENO, TCSANOW, &new_attr);
        fd = open("/dev/tty", O_RDWR);
        if (fd < 0) {
            perror("open");
            exit(1);
        }
        dup2(fd, STDIN_FILENO);
        dup2(fd, STDOUT_FILENO);
        dup2(fd, STDERR_FILENO);
        close(fd);
        execl(argv[1], argv[1], (char *)0);
        perror("execl");
        exit(1);
    } else {
        perror("fork");
        exit(1);
    }
}
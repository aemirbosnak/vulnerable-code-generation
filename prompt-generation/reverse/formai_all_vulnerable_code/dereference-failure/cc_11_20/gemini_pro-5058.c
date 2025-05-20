//GEMINI-pro DATASET v1.0 Category: System boot optimizer ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char **argv) {
    struct stat st;

    if (argc < 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }

    if (stat(argv[1], &st) == -1) {
        perror("stat");
        return EXIT_FAILURE;
    }

    if (!S_ISREG(st.st_mode)) {
        fprintf(stderr, "%s is not a regular file\n", argv[1]);
        return EXIT_FAILURE;
    }

    if (access(argv[1], R_OK) == -1) {
        perror("access");
        return EXIT_FAILURE;
    }

    int fd = open(argv[1], O_RDONLY);
    if (fd == -1) {
        perror("open");
        return EXIT_FAILURE;
    }

    char *buf = malloc(st.st_size);
    if (buf == NULL) {
        perror("malloc");
        return EXIT_FAILURE;
    }

    if (read(fd, buf, st.st_size) == -1) {
        perror("read");
        return EXIT_FAILURE;
    }

    close(fd);

    int pipefd[2];
    if (pipe(pipefd) == -1) {
        perror("pipe");
        return EXIT_FAILURE;
    }

    pid_t pid = fork();
    if (pid == -1) {
        perror("fork");
        return EXIT_FAILURE;
    }

    if (pid == 0) {
        close(pipefd[0]);
        dup2(pipefd[1], STDOUT_FILENO);
        execlp("cat", "cat", NULL);
    } else {
        close(pipefd[1]);
        dup2(pipefd[0], STDIN_FILENO);
        execlp("grep", "grep", "main", NULL);
    }

    wait(NULL);

    free(buf);

    return EXIT_SUCCESS;
}
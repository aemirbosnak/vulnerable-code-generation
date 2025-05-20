//MISTRAL-7B DATASET v1.0 Category: Interprocess communication ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/wait.h>
#include <time.h>

#define PIPE_NAME "myfifo"
#define BUFFER_SIZE 1024

void producer(int fd) {
    int rand_num;
    clock_t start, end;

    start = clock();

    for (int i = 0; i < 10; i++) {
        rand_num = rand() % 100;
        write(fd, &rand_num, sizeof(rand_num));
        printf("Producer: Produced %d\n", rand_num);
        fflush(stdout);
        sleep(1);
    }

    end = clock();
    double time_taken = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Producer: Generated 10 random numbers in %.2f seconds.\n", time_taken);
}

void consumer(int fd) {
    int num;

    while ((read(fd, &num, sizeof(num))) > 0) {
        printf("Consumer: Received %d\n", num);
    }
}

int main() {
    int fd_pipe[2], status;
    pid_t pid;

    if (pipe(fd_pipe) < 0) {
        perror("Pipe creation failed");
        return 1;
    }

    pid = fork();

    if (pid < 0) {
        perror("Fork failed");
        return 1;
    }

    if (pid > 0) { // Parent process (consumer)
        close(fd_pipe[0]);
        consumer(fd_pipe[1]);
        close(fd_pipe[1]);
        wait(&status);
    } else { // Child process (producer)
        close(fd_pipe[1]);
        producer(fd_pipe[0]);
        close(fd_pipe[0]);
        exit(EXIT_SUCCESS);
    }

    return 0;
}
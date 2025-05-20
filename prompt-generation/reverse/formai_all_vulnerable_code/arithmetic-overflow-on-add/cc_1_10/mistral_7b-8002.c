//MISTRAL-7B DATASET v1.0 Category: Interprocess communication ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <time.h>

#define PIPE_NAME "num_pipe"
#define BUFFER_SIZE 1024

int main() {
    int fd[2]; // file descriptors for the pipe
    pid_t producer_pid, consumer_pid;

    if (pipe(fd) == -1) {
        perror("Error creating pipe");
        exit(EXIT_FAILURE);
    }

    consumer_pid = fork(); // create child process (consumer)

    if (consumer_pid < 0) { // error occurred
        perror("Error forking child process");
        close(fd[0]);
        close(fd[1]);
        exit(EXIT_FAILURE);
    } else if (consumer_pid > 0) { // parent process (producer)
        close(fd[0]); // close read end of the pipe in producer

        producer_pid = fork(); // create another child process (producer)

        if (producer_pid < 0) { // error occurred
            perror("Error forking child process");
            close(fd[1]);
            wait(NULL); // wait for child to terminate
            exit(EXIT_FAILURE);
        } else {
            close(fd[1]); // close write end of the pipe in producer

            // producer generates random numbers and sends them to the pipe
            srand(time(NULL));
            while (1) {
                int num = rand() % 100;
                write(STDOUT_FILENO, "Producer generates: ", strlen("Producer generates: "));
                write(STDOUT_FILENO, &num, sizeof(num));
                write(STDOUT_FILENO, "\n", 1);
                write(fd[0], &num, sizeof(num));
                sleep(1); // delay between generating numbers
            }
        }

        wait(NULL); // wait for child to terminate
        close(fd[0]);
        exit(EXIT_SUCCESS);
    } else { // child process (consumer)
        close(fd[1]); // close write end of the pipe in consumer

        // consumer reads numbers from the pipe and performs arithmetic operations
        while (1) {
            int num;
            ssize_t num_read;

            num_read = read(fd[0], &num, sizeof(num));
            if (num_read <= 0) { // error or end of pipe
                if (num_read == -1 && errno != EAGAIN) {
                    perror("Error reading from pipe");
                    exit(EXIT_FAILURE);
                }
                break;
            }

            write(STDOUT_FILENO, "Consumer reads: ", strlen("Consumer reads: "));
            write(STDOUT_FILENO, &num, sizeof(num));
            write(STDOUT_FILENO, " + 5 = ", strlen(" + 5 = "));

            int sum = num + 5;
            write(STDOUT_FILENO, &sum, sizeof(sum));
            write(STDOUT_FILENO, "\n", 1);
        }

        close(fd[0]);
        exit(EXIT_SUCCESS);
    }

    return EXIT_SUCCESS;
}
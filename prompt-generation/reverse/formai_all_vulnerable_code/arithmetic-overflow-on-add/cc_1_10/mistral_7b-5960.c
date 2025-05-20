//MISTRAL-7B DATASET v1.0 Category: Interprocess communication ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <time.h>
#include <math.h>
#include <errno.h>

#define PIPE_NAME "myfifo"

void producer(int pipefd_w) {
    int rand_num;
    while (1) {
        rand_num = rand() % 100;
        if (write(pipefd_w, &rand_num, sizeof(rand_num)) < 0) {
            perror("Write Error");
            exit(EXIT_FAILURE);
        }
        printf("Producer: Sent number %d to Consumer via pipe\n", rand_num);
        sleep(1);
    }
}

void consumer(int pipefd_r) {
    int num, sum = 0, sq_sum = 0;
    double avg, sq_avg;
    while (1) {
        if (read(pipefd_r, &num, sizeof(num)) < 0) {
            perror("Read Error");
            exit(EXIT_FAILURE);
        }
        sum += num;
        sq_sum += (num * num);
        printf("Consumer: Received number %d from Producer via pipe\n", num);
    }
    close(pipefd_r);
    wait(NULL); // Wait for producer to terminate
    avg = (double) sum / (double) (getpid() - getppid());
    sq_avg = (double) sq_sum / (double) (getpid() - getppid());
    printf("Consumer: Average = %.2f, Square Average = %.2f\n", avg, sq_avg);
}

int main() {
    pid_t pid;
    int pipefd[2], i;

    if (pipe(pipefd) < 0) {
        perror("Pipe");
        exit(EXIT_FAILURE);
    }

    pid = fork();

    if (pid < 0) { // Error occurred during forking
        perror("Fork Failed");
        exit(EXIT_FAILURE);
    } else if (pid > 0) { // Parent process
        close(pipefd[0]);
        producer(pipefd[1]);
    } else { // Child process
        close(pipefd[1]);
        consumer(pipefd[0]);
    }

    close(pipefd[0]);
    close(pipefd[1]);

    return 0;
}
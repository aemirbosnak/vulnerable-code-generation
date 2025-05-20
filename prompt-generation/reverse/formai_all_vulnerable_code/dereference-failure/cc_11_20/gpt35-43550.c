//FormAI DATASET v1.0 Category: Interprocess communication ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define BUFFER_SIZE 1024

struct shared_buffer {
    int written;
    char text[BUFFER_SIZE];
};

int main() {
    int shmid;
    key_t key;
    struct shared_buffer *shared_buf;
    pid_t pid;

    /* Generate unique key for shared memory */
    key = ftok("shared_memory_example", 'R');
    if (key == -1) {
        perror("ftok");
        exit(EXIT_FAILURE);
    }

    /* Create shared memory segment */
    shmid = shmget(key, sizeof(struct shared_buffer), 0666 | IPC_CREAT);
    if (shmid == -1) {
        perror("shmget");
        exit(EXIT_FAILURE);
    }

    /* Attach shared memory segment */
    shared_buf = (struct shared_buffer*) shmat(shmid, NULL, 0);
    if (shared_buf == (void*) -1) {
        perror("shmat");
        exit(EXIT_FAILURE);
    }

    /* Clear shared buffer */
    shared_buf->written = 0;

    /* Fork a child process */
    pid = fork();
    if (pid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (pid == 0) {
        /* Child process reads from shared buffer and prints to stdout */
        while (1) {
            if (shared_buf->written) {
                printf("Child process: %s", shared_buf->text);
                shared_buf->written = 0;    /* Mark buffer as read */
            }
            usleep(100000); /* Pause for 100ms */
        }
        exit(EXIT_SUCCESS);
    }

    /* Parent process reads input from user and writes to shared buffer */
    while (1) {
        char input[BUFFER_SIZE];
        fgets(input, BUFFER_SIZE, stdin);
        sprintf(shared_buf->text, "Parent process: %s", input);
        shared_buf->written = 1;            /* Mark buffer as written */
        usleep(100000); /* Pause for 100ms */
    }

    /* Detach shared memory segment */
    if (shmdt(shared_buf) == -1) {
        perror("shmdt");
        exit(EXIT_FAILURE);
    }

    /* Delete shared memory segment */
    if (shmctl(shmid, IPC_RMID, NULL) == -1) {
        perror("shmctl");
        exit(EXIT_FAILURE);
    }

    return 0;
}
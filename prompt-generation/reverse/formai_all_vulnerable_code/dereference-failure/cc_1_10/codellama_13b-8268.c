//Code Llama-13B DATASET v1.0 Category: RAM usage monitor ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/mman.h>

#define NUM_PROCESSES 4
#define PAGE_SIZE 4096

int main() {
    pid_t pids[NUM_PROCESSES];
    int i;

    for (i = 0; i < NUM_PROCESSES; i++) {
        pids[i] = fork();
        if (pids[i] == 0) {
            // Child process
            while (1) {
                void *mem = malloc(PAGE_SIZE);
                if (mem == NULL) {
                    perror("malloc");
                    exit(1);
                }
                memset(mem, 0, PAGE_SIZE);
                sleep(1);
            }
        } else if (pids[i] < 0) {
            perror("fork");
            exit(1);
        }
    }

    while (1) {
        int j;
        for (j = 0; j < NUM_PROCESSES; j++) {
            pid_t pid = pids[j];
            if (pid == 0) {
                // Child process
                continue;
            }
            int status;
            waitpid(pid, &status, 0);
            if (status == 0) {
                // Process exited normally
                printf("Process %d exited normally\n", pid);
            } else {
                // Process exited with error
                printf("Process %d exited with error\n", pid);
            }
        }
    }

    return 0;
}
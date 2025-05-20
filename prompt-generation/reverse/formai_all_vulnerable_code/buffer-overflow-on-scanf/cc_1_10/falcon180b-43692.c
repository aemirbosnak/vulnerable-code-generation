//Falcon-180B DATASET v1.0 Category: System process viewer ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

#define MAX_PROCESSES 100
#define MAX_LINE 100

typedef struct {
    int pid;
    char name[MAX_LINE];
    int status;
} process_t;

process_t processes[MAX_PROCESSES];

void *monitor(void *arg) {
    int i, status;
    char line[MAX_LINE];
    FILE *fp;

    fp = fopen("/proc/self/status", "r");
    if (fp == NULL) {
        printf("Error: Cannot open /proc/self/status\n");
        exit(1);
    }

    while (fgets(line, MAX_LINE, fp)!= NULL) {
        if (strncmp(line, "Name:", 5) == 0) {
            sscanf(&line[5], "%s", processes[0].name);
        } else if (strncmp(line, "State:", 6) == 0) {
            sscanf(&line[6], "%s", processes[0].name);
        }
    }

    fclose(fp);

    while (1) {
        for (i = 0; i < MAX_PROCESSES; i++) {
            if (processes[i].pid > 0) {
                waitpid(processes[i].pid, &status, WNOHANG);
            }
        }

        usleep(100000);
    }

    return NULL;
}

int main() {
    int i, num_processes;
    pthread_t threads[MAX_PROCESSES];

    printf("Enter number of processes: ");
    scanf("%d", &num_processes);

    for (i = 0; i < num_processes; i++) {
        processes[i].pid = fork();

        if (processes[i].pid == 0) {
            break;
        } else if (processes[i].pid < 0) {
            printf("Error: Fork failed\n");
            exit(1);
        }
    }

    if (processes[0].pid == 0) {
        printf("Child process started\n");
        exit(0);
    } else {
        printf("Parent process started\n");
    }

    for (i = 0; i < num_processes; i++) {
        pthread_create(&threads[i], NULL, monitor, (void *)&processes[i]);
    }

    for (i = 0; i < num_processes; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}
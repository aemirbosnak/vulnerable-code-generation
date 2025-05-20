//Falcon-180B DATASET v1.0 Category: CPU usage monitor ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/statvfs.h>
#include <sys/time.h>
#include <unistd.h>
#include <sys/wait.h>
#include <pthread.h>
#include <signal.h>

#define MAX_PROCESSES 1024

struct process {
    pid_t pid;
    char name[16];
    int cpu_percent;
    int memory_percent;
};

void *update_processes(void *arg) {
    struct process *processes = (struct process *)arg;
    int num_processes = 0;

    while (1) {
        sleep(5);

        num_processes = 0;

        FILE *fp;
        char cmd[1024];
        sprintf(cmd, "ps -eo pid,comm --no-headers | awk '{print $1, $2}'");
        fp = popen(cmd, "r");

        while (fscanf(fp, "%d %s", &processes[num_processes].pid, processes[num_processes].name)!= EOF) {
            num_processes++;
        }

        pclose(fp);

        for (int i = 0; i < num_processes; i++) {
            sprintf(cmd, "ps -p %d -o %%cpu --no-headers", processes[i].pid);
            fp = popen(cmd, "r");
            fscanf(fp, "%d", &processes[i].cpu_percent);
            pclose(fp);

            sprintf(cmd, "ps -p %d -o %%mem --no-headers", processes[i].pid);
            fp = popen(cmd, "r");
            fscanf(fp, "%d", &processes[i].memory_percent);
            pclose(fp);
        }
    }

    return NULL;
}

void print_processes(struct process *processes, int num_processes) {
    printf("PID\tName\tCPU\tMemory\n");

    for (int i = 0; i < num_processes; i++) {
        printf("%d\t%s\t%d%%\t%d%%\n", processes[i].pid, processes[i].name, processes[i].cpu_percent, processes[i].memory_percent);
    }
}

int main() {
    pthread_t thread_id;
    struct process processes[MAX_PROCESSES];
    int num_processes = 0;

    pthread_create(&thread_id, NULL, update_processes, (void *)processes);

    while (1) {
        sleep(1);

        num_processes = 0;

        for (int i = 0; i < MAX_PROCESSES; i++) {
            if (processes[i].pid > 0) {
                num_processes++;
            }
        }

        if (num_processes > 0) {
            print_processes(processes, num_processes);
        }
    }

    return 0;
}
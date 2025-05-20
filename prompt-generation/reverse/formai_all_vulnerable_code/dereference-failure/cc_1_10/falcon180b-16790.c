//Falcon-180B DATASET v1.0 Category: System process viewer ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define MAX_PROCESSES 1024

typedef struct process {
    int pid;
    char name[16];
} process_t;

process_t processes[MAX_PROCESSES];
int num_processes = 0;

void *monitor_processes(void *arg) {
    while (1) {
        sleep(1);
        system("ps -aux > /tmp/ps_output.txt");
        FILE *fp = fopen("/tmp/ps_output.txt", "r");
        char line[1024];
        while (fgets(line, sizeof(line), fp)!= NULL) {
            if (num_processes >= MAX_PROCESSES) {
                break;
            }
            int pid = atoi(strtok(line, " "));
            strcpy(processes[num_processes].name, strtok(NULL, " "));
            processes[num_processes].pid = pid;
            num_processes++;
        }
        fclose(fp);
        remove("/tmp/ps_output.txt");
    }
    return NULL;
}

int main() {
    pthread_t thread_id;
    pthread_create(&thread_id, NULL, monitor_processes, NULL);

    while (1) {
        system("clear");
        printf("Process List:\n");
        printf("---------------------\n");
        for (int i = 0; i < num_processes; i++) {
            printf("%d. %s\n", processes[i].pid, processes[i].name);
        }
        printf("\n");
        sleep(5);
    }

    return 0;
}
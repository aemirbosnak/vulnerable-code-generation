//Falcon-180B DATASET v1.0 Category: System process viewer ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <pthread.h>

#define MAX_PROCESSES 100

typedef struct {
    char name[20];
    int pid;
    int status;
} process_t;

process_t processes[MAX_PROCESSES];
int num_processes = 0;

void *monitor_processes(void *arg) {
    while (1) {
        for (int i = 0; i < num_processes; i++) {
            if (processes[i].status == 0) {
                int status;
                waitpid(processes[i].pid, &status, WNOHANG);
                if (status == 0) {
                    processes[i].status = 1;
                }
            }
        }
        sleep(1);
    }
    return NULL;
}

int main() {
    int choice;
    do {
        printf("1. Launch new process\n2. View processes\n3. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter process name: ");
                scanf("%s", processes[num_processes].name);
                processes[num_processes].pid = fork();
                if (processes[num_processes].pid == 0) {
                    execlp("./child_process", "child_process", NULL);
                    exit(1);
                }
                num_processes++;
                break;
            case 2:
                for (int i = 0; i < num_processes; i++) {
                    printf("%s (%d) - Status: %s\n", processes[i].name, processes[i].pid, processes[i].status? "Running" : "Not Running");
                }
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    } while (1);
    return 0;
}
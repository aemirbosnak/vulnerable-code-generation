//Falcon-180B DATASET v1.0 Category: CPU usage monitor ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <sys/resource.h>

#define MAX_PROCESSES 100
#define SLEEP_TIME 1

int main() {
    int num_processes = 0;
    int process_pids[MAX_PROCESSES];
    char process_names[MAX_PROCESSES][20];
    int i;
    struct rusage usage;

    while (1) {
        printf("\n");
        printf("Enter the number of processes you want to monitor (0 to stop):");
        scanf("%d", &num_processes);

        if (num_processes == 0) {
            break;
        }

        for (i = 0; i < num_processes; i++) {
            printf("Enter the PID of process %d: ", i+1);
            scanf("%d", &process_pids[i]);
            snprintf(process_names[i], sizeof(process_names[i]), "Process %d", process_pids[i]);
        }

        while (1) {
            getrusage(RUSAGE_SELF, &usage);
            printf("\n");
            printf("CPU Usage Monitor\n");
            printf("--------------------\n");

            for (i = 0; i < num_processes; i++) {
                if (kill(process_pids[i], 0) == -1) {
                    printf("Process %s (PID %d) is not running anymore.\n", process_names[i], process_pids[i]);
                    num_processes--;
                    i--;
                } else {
                    printf("Process %s (PID %d) CPU usage: %.2f%%\n", process_names[i], process_pids[i], (usage.ru_utime.tv_sec + usage.ru_stime.tv_sec) * 100.0 / (double)SLEEP_TIME);
                }
            }

            sleep(SLEEP_TIME);
        }
    }

    return 0;
}
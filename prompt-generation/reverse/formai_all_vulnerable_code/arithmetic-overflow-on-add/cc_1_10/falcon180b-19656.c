//Falcon-180B DATASET v1.0 Category: CPU usage monitor ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <unistd.h>

#define MAX_PROCESSES 1024
#define MAX_PROCESS_NAME_LENGTH 16

int main() {
    int num_processes = 0;
    int process_ids[MAX_PROCESSES];
    char process_names[MAX_PROCESSES][MAX_PROCESS_NAME_LENGTH];
    struct rusage usage;

    printf("CPU Usage Monitor\n");

    while (1) {
        getrusage(RUSAGE_SELF, &usage);

        printf("\n");
        printf("CPU Usage:\n");
        printf("  User Time: %ld\n", usage.ru_utime.tv_sec + usage.ru_utime.tv_usec / 1000000);
        printf("  System Time: %ld\n", usage.ru_stime.tv_sec + usage.ru_stime.tv_usec / 1000000);
        printf("  Total Time: %ld\n", usage.ru_utime.tv_sec + usage.ru_utime.tv_usec / 1000000 + usage.ru_stime.tv_sec + usage.ru_stime.tv_usec / 1000000);
        printf("  Number of Processes: %d\n", num_processes);

        if (num_processes == 0) {
            printf("  No processes found.\n");
        } else {
            printf("\n");
            printf("Process ID\tProcess Name\tCPU Usage\n");

            for (int i = 0; i < num_processes; i++) {
                snprintf(process_names[i], MAX_PROCESS_NAME_LENGTH, "%d", process_ids[i]);
                printf("%d\t%s\t", process_ids[i], process_names[i]);

                struct rusage process_usage;
                if (getrusage(process_ids[i], &process_usage) == -1) {
                    perror("getrusage");
                    exit(1);
                }

                printf("%ld\t%ld\t%ld\n", process_usage.ru_utime.tv_sec + process_usage.ru_utime.tv_usec / 1000000, process_usage.ru_stime.tv_sec + process_usage.ru_stime.tv_usec / 1000000, process_usage.ru_utime.tv_sec + process_usage.ru_utime.tv_usec / 1000000 + process_usage.ru_stime.tv_sec + process_usage.ru_stime.tv_usec / 1000000);
            }
        }

        printf("\nPress any key to refresh...\n");
        getchar();
    }

    return 0;
}
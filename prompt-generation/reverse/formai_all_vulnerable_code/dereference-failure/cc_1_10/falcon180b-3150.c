//Falcon-180B DATASET v1.0 Category: RAM usage monitor ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PROCESSES 100
#define MAX_PROCESS_NAME_LENGTH 50

typedef struct {
    char name[MAX_PROCESS_NAME_LENGTH];
    unsigned long long int ram_usage;
} Process;

unsigned long long int get_process_ram_usage(int pid) {
    FILE *fp;
    char filename[50];
    unsigned long long int ram_usage = 0;

    sprintf(filename, "/proc/%d/statm", pid);

    if ((fp = fopen(filename, "r"))!= NULL) {
        fscanf(fp, "%*d %*d %*d %*d %*d %*d %llu", &ram_usage);
        fclose(fp);
    }

    return ram_usage;
}

int compare_processes(const void *a, const void *b) {
    const Process *p1 = a;
    const Process *p2 = b;

    if (p1->ram_usage > p2->ram_usage) {
        return -1;
    } else if (p1->ram_usage < p2->ram_usage) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    Process processes[MAX_PROCESSES];
    int num_processes = 0;
    char input[100];
    char *token;

    while (fgets(input, sizeof(input), stdin)!= NULL) {
        token = strtok(input, " ");

        if (strcmp(token, "list") == 0) {
            system("ps -eo pid,comm --no-headers | awk '{print $1\" \"$2}'");
        } else if (strcmp(token, "ram") == 0) {
            num_processes = 0;

            while (fgets(input, sizeof(input), stdin)!= NULL) {
                token = strtok(input, " ");

                if (strcmp(token, "process") == 0) {
                    fgets(input, sizeof(input), stdin);
                    strcpy(processes[num_processes].name, input);
                    processes[num_processes].ram_usage = get_process_ram_usage(atoi(input));
                    num_processes++;
                }
            }

            qsort(processes, num_processes, sizeof(Process), compare_processes);

            for (int i = 0; i < num_processes; i++) {
                printf("%s: %llu\n", processes[i].name, processes[i].ram_usage);
            }
        }
    }

    return 0;
}
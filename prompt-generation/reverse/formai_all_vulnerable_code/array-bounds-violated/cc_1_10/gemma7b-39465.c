//Gemma-7B DATASET v1.0 Category: System process viewer ; Style: brave
#include <stdio.h>
#include <sys/sysinfo.h>
#include <stdlib.h>

#define MAX_PROCESSES 1024

typedef struct Process {
    char name[256];
    int pid;
    int cpu_usage;
    int memory_usage;
} Process;

Process processes[MAX_PROCESSES];

void get_process_info() {
    int i = 0;
    FILE *fp = fopen("/proc/stat", "r");
    char line[256];

    if (fp) {
        while (fgets(line, 256, fp) != NULL) {
            char *fields[] = {"", "", "", ""};
            char *p = line;

            // Parse the line to get process information
            for (int j = 0; *p; j++) {
                if (*p == ':') {
                    fields[j] = p + 1;
                }
            }

            // Create a Process structure
            Process process;
            strcpy(process.name, fields[0]);
            process.pid = atoi(fields[2]);
            process.cpu_usage = atoi(fields[3]);
            process.memory_usage = atoi(fields[4]);

            // Add the process to the array
            processes[i++] = process;
        }
    }

    fclose(fp);
}

int main() {
    get_process_info();

    // Print the process information
    for (int i = 0; processes[i].name[0] != '\0'; i++) {
        printf("%s (PID: %d) - CPU usage: %d%%, Memory usage: %dKB\n", processes[i].name, processes[i].pid, processes[i].cpu_usage, processes[i].memory_usage);
    }

    return 0;
}
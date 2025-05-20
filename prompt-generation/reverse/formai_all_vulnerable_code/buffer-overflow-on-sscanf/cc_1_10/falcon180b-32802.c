//Falcon-180B DATASET v1.0 Category: System process viewer ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <sys/utsname.h>
#include <sys/sysinfo.h>
#include <dirent.h>
#include <pwd.h>
#include <grp.h>
#include <errno.h>
#include <syslog.h>

#define LOG_FILE "/var/log/system_processes.log"
#define BUF_SIZE 1024

typedef struct {
    pid_t pid;
    char name[32];
    int ppid;
    int state;
    int cpu_usage;
    int mem_usage;
} process_t;

void log_process(process_t *process) {
    syslog(LOG_INFO, "PID: %d, Name: %s, PPID: %d, State: %d, CPU Usage: %d, Memory Usage: %d", process->pid, process->name, process->ppid, process->state, process->cpu_usage, process->mem_usage);
}

int compare_processes(const void *a, const void *b) {
    const process_t *proc_a = (const process_t *)a;
    const process_t *proc_b = (const process_t *)b;

    if (proc_a->cpu_usage > proc_b->cpu_usage) {
        return -1;
    } else if (proc_a->cpu_usage < proc_b->cpu_usage) {
        return 1;
    } else {
        return 0;
    }
}

void print_processes(process_t *processes, int count) {
    qsort(processes, count, sizeof(process_t), compare_processes);

    for (int i = 0; i < count; i++) {
        log_process(&processes[i]);
    }
}

int main() {
    FILE *log_file;
    char buffer[BUF_SIZE];
    process_t processes[100];
    int count = 0;

    log_file = fopen(LOG_FILE, "a");

    if (log_file == NULL) {
        fprintf(stderr, "Error opening log file: %s\n", strerror(errno));
        exit(1);
    }

    syslog(LOG_INFO, "Starting system process viewer...");

    while (count < 100) {
        if (fgets(buffer, BUF_SIZE, log_file) == NULL) {
            fprintf(stderr, "Error reading log file: %s\n", strerror(errno));
            exit(1);
        }

        if (sscanf(buffer, "PID: %d, Name: %s, PPID: %d, State: %d, CPU Usage: %d, Memory Usage: %d", &processes[count].pid, processes[count].name, &processes[count].ppid, &processes[count].state, &processes[count].cpu_usage, &processes[count].mem_usage)!= 6) {
            fprintf(stderr, "Invalid log entry: %s\n", buffer);
            continue;
        }

        count++;
    }

    fclose(log_file);

    print_processes(processes, count);

    return 0;
}
//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: protected
#include <stdio.h>
#include <stdbool.h>

#define MAX_PROC_NAME_LEN 16
#define MAX_PROCESSES 256

typedef struct {
    char proc_name[MAX_PROC_NAME_LEN];
    int pid;
    float cpu_usage;
} Process;

int read_cpu_stats(float *cpu_usage) {
    FILE *fp = fopen("/proc/stat", "r");
    if (fp == NULL) {
        perror("Error opening /proc/stat");
        return -1;
    }

    char cpu[5];
    unsigned long long user, nice, system, idle, iowait, irq, softirq, steal, guest, guest_nice;

    if (fscanf(fp, "%s %llu %llu %llu %llu %llu %llu %llu %llu %llu %llu", cpu, &user, &nice, &system, &idle, &iowait, &irq, &softirq, &steal, &guest, &guest_nice) != 11) {
        perror("Error reading /proc/stat");
        fclose(fp);
        return -1;
    }

    fclose(fp);

    unsigned long long total = user + nice + system + idle + iowait + irq + softirq + steal;
    unsigned long long busy = total - idle - iowait;

    *cpu_usage = ((float) busy / (float) total) * 100.0f;

    return 0;
}

int read_process_stats(Process processes[], int *n) {
    *n = 0;

    FILE *fp = fopen("/proc", "r");
    if (fp == NULL) {
        perror("Error opening /proc");
        return -1;
    }

    char filename[256];
    int pid;

    while (fgets(filename, sizeof(filename), fp)) {
        if (sscanf(filename, "/proc/%d", &pid) != 1) {
            continue;
        }

        sprintf(filename, "/proc/%d/stat", pid);
        FILE *stat_file = fopen(filename, "r");
        if (stat_file == NULL) {
            continue;
        }

        char comm[MAX_PROC_NAME_LEN];
        char state;
        int ppid, pgrp, session, tty_nr, tpgid;
        unsigned int flags, minflt, cminflt, majflt, cmajflt;
        unsigned long utime, stime, cutime, cstime, priority, nice, num_threads, itrealvalue, starttime;
        unsigned long vsize, rss;
        unsigned long long start_time_ns;

        if (fscanf(stat_file, "%d (%s %c %d %d %d %d %d %u %u %u %u %lu %lu %lu %lu %ld %ld %ld %ld %ld %llu", 
                    &pid, comm, &state, &ppid, &pgrp, &session, &tty_nr, &tpgid, &flags, &minflt, &cminflt, &majflt, 
                    &cmajflt, &utime, &stime, &cutime, &cstime, &priority, &nice, &num_threads, &itrealvalue, &starttime, &vsize, &rss, &start_time_ns) != 24) {
            fclose(stat_file);
            continue;
        }

        fclose(stat_file);

        float cpu_usage;
        if (read_cpu_stats(&cpu_usage) < 0) {
            continue;
        }

        Process process;
        process.pid = pid;
        process.cpu_usage = cpu_usage;

        int len = strlen(comm);
        strncpy(process.proc_name, comm, MAX_PROC_NAME_LEN - 1);
        process.proc_name[MAX_PROC_NAME_LEN - 1] = '\0';

        processes[*n] = process;
        *n = *n + 1;

        if (*n >= MAX_PROCESSES) {
            break;
        }
        
    }

    fclose(fp);

    return 0;
}

int compare_processes(const void *a, const void *b) {
    Process *process_a = (Process *) a;
    Process *process_b = (Process *) b;

    if (process_a->cpu_usage < process_b->cpu_usage) {
        return 1;
    } else if (process_a->cpu_usage > process_b->cpu_usage) {
        return -1;
    }

    return 0;
}

int main() {
    Process processes[MAX_PROCESSES];
    int n;

    while (true) {
        if (read_process_stats(processes, &n) < 0) {
            return -1;
        }

        qsort(processes, n, sizeof(Process), compare_processes);

        printf("\n%-6s%-16s%-8s\n", "PID", "PROCESS", "%CPU");
        printf("=============================\n");

        for (int i = 0; i < n; i++) {
            printf("%-6d%-16s%-8.2f\n", processes[i].pid, processes[i].proc_name, processes[i].cpu_usage);
        }

        sleep(1);
    }

    return 0;
}
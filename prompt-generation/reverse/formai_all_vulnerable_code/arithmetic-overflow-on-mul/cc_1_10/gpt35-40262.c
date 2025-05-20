//FormAI DATASET v1.0 Category: System process viewer ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <dirent.h>
#include <ctype.h>

#define PROC "/proc"
#define STAT "/stat"
#define STAT_FILE_LEN 128

struct process_info {
    int pid;
    char user[16];
    long cpu_time; // total time in milliseconds
    long memory; // virtual memory size in kilobytes
};

// convert time in ticks to milliseconds
long ticks_to_ms(long ticks) {
    long hz = sysconf(_SC_CLK_TCK);
    return ticks * 1000 / hz;
}

// parse the stat file to obtain process info
void parse_stat(char *stat_file, struct process_info *p) {
    char buf[STAT_FILE_LEN];
    FILE *f = fopen(stat_file, "r");
    if (f == NULL) {
        perror("fopen");
        return;
    }

    fgets(buf, STAT_FILE_LEN, f);
    // pid, comm, state, ppid, pgrp, session, tty_nr, tpgid, flags, minflt,
    // cminflt, majflt, cmajflt, utime, stime, cutime, cstime, priority, nice,
    // num_threads, itrealvalue, starttime, vsize
    sscanf(buf, "%d %*s %*c%s %*c%*d %*d %*d %*d %*d %*d %*d %*d %*d %*d %*d %*d %*d %*d %*d %*d %*d %*d %ld", &p->pid, p->user, &p->cpu_time, &p->memory);
    fclose(f);
}

// get a list of all currently running processes
void get_processes(struct process_info *procs, int *n_procs) {
    DIR *dir = opendir(PROC);
    struct dirent *entry;

    if (dir == NULL) {
        perror("opendir");
        return;
    }

    int num_procs = 0;
    while ((entry = readdir(dir)) != NULL) {
        char *name = entry->d_name;
        if (isdigit(*name)) {
            char stat_file[STAT_FILE_LEN];
            snprintf(stat_file, STAT_FILE_LEN, "%s/%s%s", PROC, name, STAT);

            struct process_info pi;
            parse_stat(stat_file, &pi);

            if (strlen(pi.user) > 0) {
                procs[num_procs++] = pi;
            }
        }
    }
    closedir(dir);

    *n_procs = num_procs;
}

// display a table of process information
void display_processes(struct process_info *procs, int n_procs) {
    printf("%-5s %-15s %-10s %-10s\n", "PID", "USER", "CPU", "MEMORY");
    for (int i = 0; i < n_procs; i++) {
        struct process_info p = procs[i];
        printf("%-5d %-15s %-10ld %-10ld\n", p.pid, p.user, ticks_to_ms(p.cpu_time), p.memory);
    }
}

int main() {
    struct process_info procs[1024];
    int n_procs;
    get_processes(procs, &n_procs);
    display_processes(procs, n_procs);
    return 0;
}
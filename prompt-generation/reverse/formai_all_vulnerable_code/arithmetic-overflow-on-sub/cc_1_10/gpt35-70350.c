//FormAI DATASET v1.0 Category: System process viewer ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>
#include <time.h>

#define PROC_DIR "/proc/"
#define MAX_BUFF_SIZE 1024

typedef struct {
    int pid;
    char name[MAX_BUFF_SIZE];
    char state[MAX_BUFF_SIZE];
    unsigned long int rss_kb;
    unsigned long long int utime_ms;
    unsigned long long int stime_ms;
} process_t;

void print_header() {
    printf("%-10s%-20s%-15s%-10s%-10s%-10s\n", "PID", "NAME", "STATE", "RSS (KB)", "UTIME (ms)", "STIME (ms)");
}

void print_process_info(process_t *process) {
    printf("%-10d%-20s%-15s%-10lu%-10llu%-10llu\n", 
            process->pid, process->name, process->state, process->rss_kb, process->utime_ms, process->stime_ms);
}

int get_pid_list(int *pid_list) {
    DIR *dir = opendir(PROC_DIR);
    struct dirent *dirent;
    int count = 0;

    if (dir) {
        while ((dirent = readdir(dir))) {
            if (dirent->d_type == DT_DIR) {
                char *endptr;
                int pid = strtol(dirent->d_name, &endptr, 10);
                if (*endptr == '\0') {
                    pid_list[count++] = pid;
                }
            }
        }
    }

    closedir(dir);
    return count;
}

void get_process_info(int pid, process_t *process) {
    char path[MAX_BUFF_SIZE];
    sprintf(path, "%s%d/stat", PROC_DIR, pid);

    FILE *file = fopen(path, "r");

    if (file) {
        fscanf(file, "%d %s %s", &process->pid, process->name, process->state);
        int i = 3;
        unsigned long int tmp;
        unsigned long long int utime_ticks, stime_ticks;

        for (; i <= 23; i++) {
            if (i == 22) {
                fscanf(file, " %lu", &tmp);
                process->rss_kb = tmp * getpagesize() / 1024;
            } else if (i == 14) {
                fscanf(file, " %llu %llu", &utime_ticks, &stime_ticks);
                process->utime_ms = utime_ticks * 1000 / sysconf(_SC_CLK_TCK);
                process->stime_ms = stime_ticks * 1000 / sysconf(_SC_CLK_TCK);
            } else {
                char buf[MAX_BUFF_SIZE];
                fscanf(file, " %s", buf);
            }
        }
    }

    fclose(file);
}

void get_processes_info(int *pid_list, int count, process_t *processes) {
    int i;

    for (i = 0; i < count; i++) {
        get_process_info(pid_list[i], &processes[i]);
    }
}

int main() {
    int pid_list[MAX_BUFF_SIZE];
    int count = get_pid_list(pid_list);
    process_t processes[MAX_BUFF_SIZE];

    get_processes_info(pid_list, count, processes);

    print_header();

    int i;
    for (i = 0; i < count; i++) {
        print_process_info(&processes[i]);
    }

    return 0;
}
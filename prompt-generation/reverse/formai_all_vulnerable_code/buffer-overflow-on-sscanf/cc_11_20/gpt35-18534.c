//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/times.h>

#define MAX_PROCESS_NAME_LENGTH 256
#define MAX_PROCESSES 1024

struct Process {
    char name[MAX_PROCESS_NAME_LENGTH];
    double cpu_time;
};

int main(int argc, char** argv) {
    printf("Grateful CPU Usage Monitor\n");

    struct Process processes[MAX_PROCESSES];
    int num_processes = 0;

    while (1) {
        FILE* file = fopen("/proc/stat", "r");
        if (file == NULL) {
            printf("Error: could not read /proc/stat\n");
            return 1;
        }

        char buffer[256];
        if (!fgets(buffer, sizeof(buffer), file)) {
            printf("Error: could not read first line of /proc/stat\n");
            fclose(file);
            return 1;
        }

        fclose(file);

        unsigned long long user_time = 0;
        unsigned long long nice_time = 0;
        unsigned long long system_time = 0;
        unsigned long long idle_time = 0;

        sscanf(buffer, "cpu %llu %llu %llu %llu", &user_time, &nice_time, &system_time, &idle_time);

        double total_time = user_time + nice_time + system_time + idle_time;

        printf("\nPROCESS NAME\tCPU USAGE\n");

        for (int i = 0; i < num_processes; i++) {
            struct tms time_buffer;
            clock_t start = times(&time_buffer);

            FILE* pid_file = fopen("/proc/self/stat", "r");
            if (pid_file == NULL) {
                printf("Error: could not read /proc/self/stat\n");
                return 1;
            }

            char pid_buffer[256];
            fgets(pid_buffer, sizeof(pid_buffer), pid_file);

            fclose(pid_file);

            long long pid;
            char name[MAX_PROCESS_NAME_LENGTH + 1];
            char state;
            long long ppid;
            long long pgrp;
            long long session;
            long long tty_nr;
            long long tpgid;
            unsigned long long flags;
            unsigned long long minflt;
            unsigned long long cminflt;
            unsigned long long majflt;
            unsigned long long cmajflt;
            unsigned long long utime;
            unsigned long long stime;
            long long cutime;
            long long cstime;
            long long priority;
            long long nice;
            long long num_threads;
            long long itrealvalue;
            unsigned long long starttime;
            unsigned long long vsize;

            sscanf(pid_buffer, "%lld %s %c %lld %lld %lld %lld %lld %llu %llu %llu %llu %llu %llu %lld %lld %lld %lld %lld %lld %lld %lld %llu %llu",
                   &pid, name, &state, &ppid, &pgrp, &session, &tty_nr, &tpgid, &flags, &minflt, &cminflt, &majflt, &cmajflt,
                   &utime, &stime, &cutime, &cstime, &priority, &nice, &num_threads, &itrealvalue, &starttime, &vsize);

            if (strcmp(processes[i].name, name) == 0) {
                double elapsed_time = (double)(times(&time_buffer) - start) / sysconf(_SC_CLK_TCK);
                processes[i].cpu_time += 100.0 * (double)(utime + stime) / (double)total_time * elapsed_time;
            }

            printf("%s\t%.2f%%\n", processes[i].name, processes[i].cpu_time);
        }

        sleep(1);

        FILE* process_file = fopen("/proc/", "r");
        if (process_file == NULL) {
            printf("Error: could not read /proc/\n");
            return 1;
        }

        char process_buffer[256];
        while (fgets(process_buffer, sizeof(process_buffer), process_file)) {
            if (strlen(process_buffer) < 6) {
                continue;
            }

            if (process_buffer[0] < '0' || process_buffer[0] > '9') {
                continue;
            }

            int pid;
            sscanf(process_buffer, "%d", &pid);

            sprintf(buffer, "/proc/%d/stat", pid);

            FILE* stat_file = fopen(buffer, "r");
            if (stat_file == NULL) {
                continue;
            }

            char stat_buffer[256];
            fgets(stat_buffer, sizeof(stat_buffer), stat_file);
            fclose(stat_file);

            char name[MAX_PROCESS_NAME_LENGTH + 1];
            int i = 0, j = 0;
            while (stat_buffer[i++] != '(');
            while (stat_buffer[i] != ')') {
                name[j++] = stat_buffer[i++];
            }
            name[j] = '\0';

            int found = 0;
            for (int i = 0; i < num_processes; i++) {
                if (strcmp(processes[i].name, name) == 0) {
                    struct tms time_buffer;
                    clock_t start = times(&time_buffer);

                    long long utime, stime;
                    sscanf(stat_buffer, "%*d %*s %*c %*d %*d %*d %*d %*d %*u %*u %*u %*u %*u %llu %llu",
                           &utime, &stime);

                    double elapsed_time = (double)(times(&time_buffer) - start) / sysconf(_SC_CLK_TCK);
                    processes[i].cpu_time += 100.0 * (double)(utime + stime) / (double)total_time * elapsed_time;
                    found = 1;
                    break;
                }
            }

            if (!found) {
                if (num_processes >= MAX_PROCESSES) {
                    printf("Error: too many processes, aborting...\n");
                    fclose(process_file);
                    return 1;
                }

                strncpy(processes[num_processes].name, name, MAX_PROCESS_NAME_LENGTH);
                processes[num_processes].cpu_time = 0;
                num_processes++;
            }
        }

        fclose(process_file);
    }

    return 0;
}
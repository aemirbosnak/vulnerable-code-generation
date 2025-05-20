//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

#define MAX_FILE_SIZE 1000000
#define MAX_PROC_DIR_SIZE 1000
#define MAX_LINE_SIZE 256
#define MAX_CPU_COUNT 64

int main(void) {
    int proc_stat_fd, cpu_count, i;
    char proc_stat_filename[MAX_FILE_SIZE];
    char proc_stat_file_content[MAX_FILE_SIZE];
    char proc_dir[MAX_PROC_DIR_SIZE];
    long long user_time[MAX_CPU_COUNT];
    long long nice_time[MAX_CPU_COUNT];
    long long sys_time[MAX_CPU_COUNT];
    long long idle_time[MAX_CPU_COUNT];
    long long iowait_time[MAX_CPU_COUNT];
    long long irq_time[MAX_CPU_COUNT];
    long long softirq_time[MAX_CPU_COUNT];
    long long steal_time[MAX_CPU_COUNT];
    long long guest_time[MAX_CPU_COUNT];
    long long guest_nice_time[MAX_CPU_COUNT];
    long long prev_total_time[MAX_CPU_COUNT];
    long long prev_idle_time[MAX_CPU_COUNT];
    long long cpu_usage[MAX_CPU_COUNT];
    float total_usage = 0.0;
    struct stat statbuf;

    // Get number of CPUs
    cpu_count = sysconf(_SC_NPROCESSORS_ONLN);
    if (cpu_count > MAX_CPU_COUNT) {
        printf("Error: Too many CPUs\n");
        return 1;
    }

    // Get the proc directory name
    snprintf(proc_dir, MAX_PROC_DIR_SIZE, "/proc");

    // Loop through each CPU and read the previous total and idle time
    for (i = 0; i < cpu_count; i++) {
        prev_total_time[i] = 0;
        prev_idle_time[i] = 0;
    }

    // Loop forever and continuously calculate the CPU usage percentage
    while (1) {
        // Read the /proc/stat file for each CPU
        for (i = 0; i < cpu_count; i++) {
            snprintf(proc_stat_filename, MAX_FILE_SIZE, "%s/%s%d/%s", proc_dir, "stat", i, "stat");
            proc_stat_fd = open(proc_stat_filename, O_RDONLY);      
            if (proc_stat_fd == -1) {
                printf("Error: Can't open file %s\n", proc_stat_filename);
                return 1;
            }
            if (fstat(proc_stat_fd, &statbuf) == -1) {
                printf("Error: Can't stat file %s\n", proc_stat_filename);
                return 1;
            }
            if (statbuf.st_size > MAX_FILE_SIZE) {
                printf("Error: File %s too big\n", proc_stat_filename);
                return 1;
            }
            if (read(proc_stat_fd, proc_stat_file_content, statbuf.st_size) == -1) {
                printf("Error: Can't read file %s\n", proc_stat_filename);
                return 1;
            }
            if (close(proc_stat_fd) == -1) {
                printf("Error: Can't close file %s\n", proc_stat_filename);
                return 1;
            }

            // Parse the /proc/stat file and calculate the CPU usage
            sscanf(proc_stat_file_content, "cpu %lld %lld %lld %lld %lld %lld %lld %lld %lld %lld",
                   &user_time[i], &nice_time[i], &sys_time[i], &idle_time[i], &iowait_time[i],
                   &irq_time[i], &softirq_time[i], &steal_time[i], &guest_time[i], &guest_nice_time[i]);
            long long curr_idle_time = idle_time[i] + iowait_time[i];
            long long curr_total_time = user_time[i] + nice_time[i] + sys_time[i] + idle_time[i] +
                                        iowait_time[i] + irq_time[i] + softirq_time[i] + steal_time[i];
            long long total_diff = curr_total_time - prev_total_time[i];
            long long idle_diff = curr_idle_time - prev_idle_time[i];
            prev_total_time[i] = curr_total_time;
            prev_idle_time[i] = curr_idle_time;
            cpu_usage[i] = 0;
            if (total_diff != 0) {
                cpu_usage[i] = (total_diff - idle_diff) * 100 / total_diff;
            }
            total_usage += cpu_usage[i];
        }

        // Print the CPU usage percentage for each CPU and the total usage percentage
        printf("CPU usage: ");
        for (i = 0; i < cpu_count; i++) {
            printf("CPU%d %lld%% ", i, cpu_usage[i]);
        }
        printf("Total %f%%\n", total_usage);
        fflush(stdout);

        // Reset the total usage percentage
        total_usage = 0.0;

        // Wait for one second
        sleep(1);
    }

    return 0;
}
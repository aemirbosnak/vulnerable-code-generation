//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#define MAX_PROCESS_NAME_LENGTH 20

// function to get current CPU usage percentage
float cpu_usage() {
    float cpu_usage;
    FILE *file_ptr;
    char file_buffer[1024];
    unsigned long long current_user, current_nice, current_sys, current_idle, current_iowait, current_irq, current_softirq, current_steal;
    unsigned long long prev_user, prev_nice, prev_sys, prev_idle, prev_iowait, prev_irq, prev_softirq, prev_steal;
    static unsigned int interval = 0;

    file_ptr = fopen("/proc/stat", "r");
    fgets(file_buffer, sizeof(file_buffer), file_ptr);
    sscanf(file_buffer, "cpu %llu %llu %llu %llu %llu %llu %llu %llu", &current_user, &current_nice, &current_sys, &current_idle, &current_iowait, &current_irq, &current_softirq, &current_steal);

    if(interval > 0) {
        cpu_usage = (((current_user + current_nice + current_sys + current_irq + current_softirq + current_steal) - (prev_user + prev_nice + prev_sys + prev_irq + prev_softirq + prev_steal)) * 100.0) / ((current_user + current_nice + current_sys + current_idle + current_iowait + current_irq + current_softirq + current_steal) - (prev_user + prev_nice + prev_sys + prev_idle + prev_iowait + prev_irq + prev_softirq + prev_steal));
    } else {
        cpu_usage = 0;
    }
    fclose(file_ptr);

    prev_user = current_user;
    prev_nice = current_nice;
    prev_sys = current_sys;
    prev_idle = current_idle;
    prev_iowait = current_iowait;
    prev_irq = current_irq;
    prev_softirq = current_softirq;
    prev_steal = current_steal;
    interval++;

    return cpu_usage;
}

int main() {
    char process_name[MAX_PROCESS_NAME_LENGTH];
    float cpu_usage_percentage;

    printf("Enter the name of the process: ");
    scanf("%s", process_name);

    while(1) {
        system("clear");

        printf("=== CPU Usage Monitor ===\n");
        printf("Process Name: %s\n", process_name);

        // get current CPU usage
        cpu_usage_percentage = cpu_usage();
        printf("CPU usage percentage: %.2f%%\n", cpu_usage_percentage);

        // check if the process is running and get its PID
        char command[100];
        sprintf(command, "pgrep %s > temp.txt", process_name);
        system(command);

        FILE *temp_file_ptr;
        temp_file_ptr = fopen("temp.txt", "r");

        if(temp_file_ptr == NULL) {
            printf("Error opening temp.txt file!");
            exit(0);
        }

        int process_pid;
        fscanf(temp_file_ptr, "%d", &process_pid);
        fclose(temp_file_ptr);

        if(process_pid == 0) {
            printf("Process not found!\n");
        } else {
            // get process CPU usage
            float process_cpu_usage_percentage;
            char process_status_file_name[100];
            sprintf(process_status_file_name, "/proc/%d/stat", process_pid);

            FILE *process_file_ptr;
            process_file_ptr = fopen(process_status_file_name, "r");

            if(process_file_ptr == NULL) {
                printf("Error opening the process status file!");
                exit(0);
            }

            unsigned long long utime, stime, cutime, cstime, start_time, uptime;
            int process_jiffies, total_jiffies;

            fscanf(process_file_ptr, "%*d %*s %*c %*d %*d %*d %*d %*d %*u %*u %*u %*u %lu %lu %lu %lu %*u %*u %*d %*d %*u %lu", &utime, &stime, &cutime, &cstime, &start_time);
            fclose(process_file_ptr);

            char uptime_file_name[100];
            sprintf(uptime_file_name, "/proc/uptime");

            FILE *uptime_file_ptr;
            uptime_file_ptr = fopen(uptime_file_name, "r");

            if(uptime_file_ptr == NULL) {
                printf("Error opening the uptime file!");
                exit(0);
            }

            fscanf(uptime_file_ptr, "%lu", &uptime);
            fclose(uptime_file_ptr);

            process_jiffies = (utime + stime);
            total_jiffies = (process_jiffies + cutime + cstime);

            // convert jiffies to seconds
            float process_cpu_seconds = ((process_jiffies * 100.0) / total_jiffies) / 100.0;
            float total_cpu_seconds = cpu_usage_percentage * uptime;

            process_cpu_usage_percentage = (process_cpu_seconds / total_cpu_seconds) * 100;

            printf("Process CPU usage percentage: %.2f%%\n", process_cpu_usage_percentage);
        }

        // wait for 1 second
        sleep(1);
    }

    return 0;
}
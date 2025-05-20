//GPT-4o-mini DATASET v1.0 Category: System process viewer ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <ctype.h>

#define BUFF_SIZE 256

void display_process_info(const char *pid_str) {
    char file_path[BUFF_SIZE];
    snprintf(file_path, sizeof(file_path), "/proc/%s/stat", pid_str);

    FILE *fp = fopen(file_path, "r");
    if (fp == NULL) {
        perror("Error opening stat file");
        return;
    }

    int pid, ppid;
    char comm[BUFF_SIZE];
    float cpu_usage;
    fscanf(fp, "%d %s %*s %d", &pid, comm, &ppid);
    fclose(fp);

    // Read CPU usage from /proc/stat
    const char *cpu_stat_file = "/proc/stat";
    FILE *cpu_fp = fopen(cpu_stat_file, "r");
    if (cpu_fp == NULL) {
        perror("Error opening cpu stat file");
        return;
    }

    long user, nice, system, idle;
    fscanf(cpu_fp, "cpu %ld %ld %ld %ld", &user, &nice, &system, &idle);
    fclose(cpu_fp);

    long total_cpu_time = user + nice + system + idle;
    cpu_usage = (float)(user + nice + system) / total_cpu_time * 100;

    printf("PID: %d | Command: %s | PPID: %d | CPU Usage: %.2f%%\n", pid, comm, ppid, cpu_usage);
}

int is_number(const char *str) {
    while (*str) {
        if (!isdigit(*str)) {
            return 0;
        }
        str++;
    }
    return 1;
}

void list_processes() {
    DIR *dir = opendir("/proc");
    struct dirent *entry;

    printf("\n--- Current Running Processes ---\n");

    if (dir == NULL) {
        perror("Error opening /proc directory");
        return;
    }

    while ((entry = readdir(dir)) != NULL) {
        if (is_number(entry->d_name)) {
            display_process_info(entry->d_name);
        }
    }

    closedir(dir);
}

int main(void) {
    while (1) {
        list_processes();
        printf("\nPress Ctrl+C to exit or wait for a few seconds for refresh...\n");
        sleep(5); // Wait for 5 seconds before refreshing the process list
        printf("\033[H\033[J"); // Clear the console
    }

    return 0;
}
//Falcon-180B DATASET v1.0 Category: System process viewer ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/sysinfo.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>

#define BUF_SIZE 1024

// Function to print system information
void print_sys_info() {
    struct sysinfo info;
    sysinfo(&info);

    printf("Total RAM: %ld MB\n", info.totalram / (1024 * 1024));
    printf("Free RAM: %ld MB\n", info.freeram / (1024 * 1024));
    printf("Total Swap: %ld MB\n", info.totalswap / (1024 * 1024));
    printf("Free Swap: %ld MB\n", info.freeswap / (1024 * 1024));
}

// Function to print CPU usage
void print_cpu_usage() {
    FILE *file;
    char filename[20];
    sprintf(filename, "/proc/%d/stat", getpid());
    file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error");
        exit(1);
    }

    char buf[BUF_SIZE];
    if (fgets(buf, BUF_SIZE, file) == NULL) {
        perror("Error");
        exit(1);
    }

    fclose(file);

    int total_time = 0, user_time = 0, system_time = 0;
    sscanf(buf, "%*d %*s %*c %*d %*d %*d %*d %*d %d %d %d", &total_time, &user_time, &system_time);

    float cpu_usage = ((float) (user_time + system_time) / total_time) * 100;

    printf("CPU usage: %.2f%%\n", cpu_usage);
}

// Function to print process information
void print_process_info(char *process_name) {
    FILE *file;
    DIR *dir;
    struct dirent *ent;
    char filename[50];

    dir = opendir("/proc");
    if (dir == NULL) {
        perror("Error");
        exit(1);
    }

    while ((ent = readdir(dir))!= NULL) {
        if (ent->d_type == DT_DIR) {
            sprintf(filename, "/proc/%s/stat", ent->d_name);
            file = fopen(filename, "r");
            if (file == NULL) {
                perror("Error");
                exit(1);
            }

            char buf[BUF_SIZE];
            if (fgets(buf, BUF_SIZE, file) == NULL) {
                perror("Error");
                exit(1);
            }

            fclose(file);

            int pid = 0;
            sscanf(ent->d_name, "%d", &pid);
            if (pid == getpid()) {
                printf("Process name: %s\n", process_name);
            }
        }
    }

    closedir(dir);
}

int main() {
    print_sys_info();
    print_cpu_usage();
    print_process_info("process_name");

    return 0;
}
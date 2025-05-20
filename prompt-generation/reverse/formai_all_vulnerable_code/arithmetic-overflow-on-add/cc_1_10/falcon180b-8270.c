//Falcon-180B DATASET v1.0 Category: CPU usage monitor ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <unistd.h>
#include <string.h>
#include <math.h>

struct proc_stat {
    unsigned long long cpu_time;
    unsigned long long user_time;
    unsigned long long system_time;
    unsigned long long idle_time;
};

int main() {
    int i;
    struct proc_stat proc_stat;
    struct rusage usage;

    if (getrusage(RUSAGE_SELF, &usage) == -1) {
        perror("getrusage");
        exit(EXIT_FAILURE);
    }

    proc_stat.cpu_time = usage.ru_utime.tv_sec + usage.ru_stime.tv_sec;
    proc_stat.user_time = usage.ru_utime.tv_sec;
    proc_stat.system_time = usage.ru_stime.tv_sec;
    proc_stat.idle_time = proc_stat.cpu_time - proc_stat.user_time - proc_stat.system_time;

    printf("CPU Usage Monitor\n");
    printf("-----------------\n");
    printf("Total CPU Time: %llu\n", proc_stat.cpu_time);
    printf("User CPU Time: %llu\n", proc_stat.user_time);
    printf("System CPU Time: %llu\n", proc_stat.system_time);
    printf("Idle CPU Time: %llu\n", proc_stat.idle_time);
    printf("\n");

    for (i = 0; i < 10; i++) {
        if (getrusage(RUSAGE_SELF, &usage) == -1) {
            perror("getrusage");
            exit(EXIT_FAILURE);
        }

        proc_stat.cpu_time = usage.ru_utime.tv_sec + usage.ru_stime.tv_sec;
        proc_stat.user_time = usage.ru_utime.tv_sec;
        proc_stat.system_time = usage.ru_stime.tv_sec;
        proc_stat.idle_time = proc_stat.cpu_time - proc_stat.user_time - proc_stat.system_time;

        printf("CPU Usage Monitor\n");
        printf("-----------------\n");
        printf("Total CPU Time: %llu\n", proc_stat.cpu_time);
        printf("User CPU Time: %llu\n", proc_stat.user_time);
        printf("System CPU Time: %llu\n", proc_stat.system_time);
        printf("Idle CPU Time: %llu\n", proc_stat.idle_time);
        printf("\n");

        sleep(1);
    }

    return 0;
}
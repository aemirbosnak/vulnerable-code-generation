//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/resource.h>
#include <sys/time.h>
#include <signal.h>
#include <time.h>

#define BUF_SIZE 1024

volatile sig_atomic_t sig = 0;

void sig_handler(int signo) {
    sig = 1;
}

int main(int argc, char *argv[]) {
    int interval = 1; // interval to monitor CPU usage in seconds
    struct timespec t_req = {0, interval*1000000000}; // interval in nanoseconds
    struct timespec t_rem = {0, 0}; // remaining time if interrupted by a signal
    struct sigaction sa;
    char buf[BUF_SIZE];
    FILE *fp;

    // Set up signal handler for SIGINT (Ctrl-C)
    sa.sa_handler = sig_handler;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;
    if (sigaction(SIGINT, &sa, NULL) == -1) {
        perror("sigaction");
        exit(EXIT_FAILURE);
    }

    // Get process ID
    pid_t pid = getpid();

    while (!sig) {
        // Get CPU usage for the process
        struct rusage usage;
        getrusage(RUSAGE_SELF, &usage);
        double user_cpu = ((double) usage.ru_utime.tv_sec + (double) usage.ru_utime.tv_usec/1000000);
        double sys_cpu = ((double) usage.ru_stime.tv_sec + (double) usage.ru_stime.tv_usec/1000000);
        double total_cpu = user_cpu + sys_cpu;

        // Open /proc/[PID]/stat file for additional information
        snprintf(buf, BUF_SIZE, "/proc/%d/stat", pid);
        fp = fopen(buf, "r");
        if (fp == NULL) {
            perror("fopen");
            exit(EXIT_FAILURE);
        }
        fgets(buf, BUF_SIZE, fp);
        fclose(fp);

        // Parse /proc/[PID]/stat file for additional information
        long unsigned int utime, stime, cutime, cstime;
        sscanf(buf, "%*d %*s %*c %*d %*d %*d %*d %*d %*u %*u %*u %lu %lu %lu %lu", &utime, &stime, &cutime, &cstime);

        // Calculate total CPU time in seconds
        double total_cpu_time = (utime + stime + cutime + cstime) / (double) sysconf(_SC_CLK_TCK);

        // Print CPU usage and additional information
        printf("CPU Usage: %.2f%%\n", total_cpu*100);
        printf("Total CPU Time: %.2fs\n", total_cpu_time);

        // Sleep for interval time
        nanosleep(&t_req, &t_rem);
    }

    return 0;
}
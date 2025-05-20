//GPT-4o-mini DATASET v1.0 Category: CPU usage monitor ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/sysinfo.h>
#include <time.h>
#include <signal.h>

#define SAMPLE_INTERVAL 1 // Interval to sample CPU usage in seconds
#define MAX_SAMPLES 100    // Maximum number of samples to capture

typedef struct {
    time_t timestamp;
    double cpu_usage;
} CPUSample;

CPUSample samples[MAX_SAMPLES];
int sample_count = 0;
volatile sig_atomic_t stop = 0;

// Signal handler to catch SIGINT (Ctrl+C)
void handle_sigint(int sig) {
    stop = 1;
}

// Function to calculate CPU usage
double get_cpu_usage() {
    FILE *fp;
    long double total_user, total_user_nice, total_sys, total_idle, total_iowait, total_steal;
    long double total;

    fp = fopen("/proc/stat", "r");
    if (fp == NULL) {
        perror("fopen");
        return -1;
    }

    fscanf(fp, "cpu %Lf %Lf %Lf %Lf %Lf %Lf %Lf",
           &total_user, 
           &total_user_nice, 
           &total_sys, 
           &total_idle, 
           &total_iowait, 
           &total_steal);

    total = total_user + total_user_nice + total_sys + total_idle + total_iowait + total_steal;

    fclose(fp);

    double usage = ((total - total_idle) / total) * 100.0;
    return usage;
}

// Function to log CPU usage samples
void log_cpu_usage() {
    while (!stop && sample_count < MAX_SAMPLES) {
        if (sample_count < MAX_SAMPLES) {
            samples[sample_count].timestamp = time(NULL);
            samples[sample_count].cpu_usage = get_cpu_usage();
            sample_count++;
        }
        sleep(SAMPLE_INTERVAL);
    }
}

// Function to display the logged CPU usage samples
void display_samples() {
    printf("Timestamp\t\tCPU Usage (%%)\n");
    printf("------------------------------\n");
    for (int i = 0; i < sample_count; i++) {
        char time_str[26];
        struct tm *tm_info;

        tm_info = localtime(&samples[i].timestamp);
        strftime(time_str, 26, "%Y-%m-%d %H:%M:%S", tm_info);

        printf("%s\t%.2f\n", time_str, samples[i].cpu_usage);
    }
}

int main() {
    signal(SIGINT, handle_sigint);

    printf("Starting CPU usage monitor...\n");
    log_cpu_usage();

    printf("Monitoring stopped. Logged %d samples.\n", sample_count);
    display_samples();

    return 0;
}
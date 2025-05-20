//GPT-4o-mini DATASET v1.0 Category: CPU usage monitor ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>

#define BUFFER_SIZE 256
#define CPU_COUNT 4

typedef struct {
    double user;
    double nice;
    double system;
    double idle;
    double iowait;
    double irq;
    double softirq;
    double steal;
} cpu_usage_t;

void read_cpu_usage(cpu_usage_t *usage) {
    FILE *fp;
    char buffer[BUFFER_SIZE];
    char *token;
    int cpu_index = 0;

    // Open the file that contains CPU usage information
    if ((fp = fopen("/proc/stat", "r")) == NULL) {
        perror("Failed to open /proc/stat");
        exit(EXIT_FAILURE);
    }

    // Read the first line containing total CPU usage (cpu)
    if (fgets(buffer, sizeof(buffer), fp) != NULL) {
        token = strtok(buffer, " ");
        // Skip the first token "cpu"
        while (token != NULL) {
            if (cpu_index == 1) usage->user = atof(token);
            else if (cpu_index == 2) usage->nice = atof(token);
            else if (cpu_index == 3) usage->system = atof(token);
            else if (cpu_index == 4) usage->idle = atof(token);
            else if (cpu_index == 5) usage->iowait = atof(token);
            else if (cpu_index == 6) usage->irq = atof(token);
            else if (cpu_index == 7) usage->softirq = atof(token);
            else if (cpu_index == 8) usage->steal = atof(token);
            cpu_index++;
            token = strtok(NULL, " ");
        }
    }

    fclose(fp);
}

void calculate_cpu_usage(cpu_usage_t *prev, cpu_usage_t *current, double *usage_percentage) {
    double prev_total = prev->user + prev->nice + prev->system + prev->idle + 
                        prev->iowait + prev->irq + prev->softirq + prev->steal;

    double current_total = current->user + current->nice + current->system + current->idle + 
                           current->iowait + current->irq + current->softirq + current->steal;

    double idle_diff = current->idle - prev->idle;
    double total_diff = current_total - prev_total;

    if (total_diff != 0) {
        *usage_percentage = 100.0 * (total_diff - idle_diff) / total_diff; // CPU usage as a percentage
    } else {
        *usage_percentage = 0.0; // To prevent division by zero
    }
}

void display_cpu_usage(double usage_percentage) {
    printf("CPU Usage: %.2f%%\n", usage_percentage);
}

void log_cpu_usage(double usage_percentage) {
    FILE *logfile;

    logfile = fopen("cpu_usage.log", "a");
    if (logfile == NULL) {
        perror("Failed to open log file");
        return;
    }

    time_t now;
    time(&now);
    fprintf(logfile, "[%s] CPU Usage: %.2f%%\n", ctime(&now), usage_percentage);
    fclose(logfile);
}

int main() {
    cpu_usage_t prev_usage, current_usage;
    double usage_percentage;

    // Initialize previous CPU usage
    read_cpu_usage(&prev_usage);

    while (1) {
        sleep(1); // Sleep for 1 second
        read_cpu_usage(&current_usage);
        calculate_cpu_usage(&prev_usage, &current_usage, &usage_percentage);
        display_cpu_usage(usage_percentage);
        log_cpu_usage(usage_percentage);
        prev_usage = current_usage; // Update previous usage for the next iteration
    }

    return 0;
}
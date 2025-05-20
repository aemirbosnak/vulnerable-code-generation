//GPT-4o-mini DATASET v1.0 Category: CPU usage monitor ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
#include <sys/types.h>
#include <sys/sysinfo.h>

#define SLEEP_DURATION 1
#define MAX_SAMPLES 10

void display_cpu_usage(float usage) {
    printf("\rCPU Usage: %.2f%%   ", usage);
    fflush(stdout);
}

float calculate_cpu_usage(long double *a, long double *b, long double *c, long double *d) {
    long double idle = *a;
    long double non_idle = *b + *c + *d;
    long double total = idle + non_idle;
    
    return (total - idle) / total * 100;
}

void get_cpu_times(long double *a, long double *b, long double *c, long double *d) {
    FILE *fp;
    char buffer[256];
    if ((fp = fopen("/proc/stat", "r")) == NULL) {
        perror("Failed to open /proc/stat");
        exit(1);
    }
    fgets(buffer, sizeof(buffer), fp);
    fclose(fp);
    
    sscanf(buffer, "cpu %Lf %Lf %Lf %Lf", a, b, c, d);
}

int main() {
    long double a, b, c, d;
    float previous_usage = 0.0f;
    
    printf("Welcome to the Peaceful CPU Usage Monitor!\n");
    printf("Monitoring CPU usage every %d seconds...\n", SLEEP_DURATION);
    
    // Sample CPU usage for a number of iterations.
    for (int i = 0; i < MAX_SAMPLES; i++) {
        long double idle_time, user_time, nice_time, system_time;
        
        get_cpu_times(&idle_time, &user_time, &nice_time, &system_time);
        
        // Brief pause to let CPU times update
        sleep(SLEEP_DURATION);
        
        long double new_idle_time, new_user_time, new_nice_time, new_system_time;
        get_cpu_times(&new_idle_time, &new_user_time, &new_nice_time, &new_system_time);
        
        // Calculate the differences
        long double a_diff = new_idle_time - idle_time;
        long double b_diff = new_user_time - user_time;
        long double c_diff = new_nice_time - nice_time;
        long double d_diff = new_system_time - system_time;
        
        // Calculate CPU usage
        float cpu_usage = calculate_cpu_usage(&a_diff, &b_diff, &c_diff, &d_diff);
        
        // Display the CPU usage
        display_cpu_usage(cpu_usage);
        
        // Peaceful waiting time before the next check
        sleep(SLEEP_DURATION);
    }

    printf("\n\nThank you for using the Peaceful CPU Usage Monitor. Have a serene day!\n");
    return 0;
}
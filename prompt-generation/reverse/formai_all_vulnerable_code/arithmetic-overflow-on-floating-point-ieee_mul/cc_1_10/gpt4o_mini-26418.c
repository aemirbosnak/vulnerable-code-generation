//GPT-4o-mini DATASET v1.0 Category: CPU usage monitor ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>

void spool_cpu_usage() {
    // Variables to hold usage values
    long double a[4], b[4], loadavg;
    char buf[1024];
    
    // Fetch the CPU usage
    FILE *fp;
    if ((fp = fopen("/proc/stat", "r")) == NULL) {
        perror("Failed to open /proc/stat");
        return;
    }
    
    // Read CPU line
    fgets(buf, sizeof(buf), fp);
    fclose(fp);

    // Parse the read values
    sscanf(buf, "cpu %Lf %Lf %Lf %Lf", &a[0], &a[1], &a[2], &a[3]);
    usleep(100000); // sleep a moment to compute difference
    if ((fp = fopen("/proc/stat", "r")) == NULL) {
        perror("Failed to open /proc/stat");
        return;
    }

    fgets(buf, sizeof(buf), fp);
    fclose(fp);
    sscanf(buf, "cpu %Lf %Lf %Lf %Lf", &b[0], &b[1], &b[2], &b[3]);
    
    // Calculate usage
    long double total = (b[0] + b[1] + b[2] + b[3]) - (a[0] + a[1] + a[2] + a[3]);
    long double idle = b[3] - a[3];
    long double CPU_load = 1.0 - (idle / total);
    
    // Output the result
    printf("O fair CPU! Thy usage is: %.2Lf%%\n", CPU_load * 100);
}

void display_time() {
    time_t now;
    struct tm *tm_info;
    char buffer[26];
    
    time(&now);
    tm_info = localtime(&now);
    
    strftime(buffer, 26, "%Y-%m-%d %H:%M:%S", tm_info);
    printf("Time now is: %s\n", buffer);
}

int main() {
    printf("Enter now, dear CPU monitor, to keep thine usage high\n");
    
    for(int i = 0; i < 5; i++) { // Let it run for a brief span
        display_time();
        spool_cpu_usage();
        printf("In yonder moment, let us gather our thoughts!\n\n");
        sleep(2); // Retain some space between wisdom
    }
    
    printf("Thus hath our tale come to an end, dear CPU, rest well!\n");

    return 0;
}
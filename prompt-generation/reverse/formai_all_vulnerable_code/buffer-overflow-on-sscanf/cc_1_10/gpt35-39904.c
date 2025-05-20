//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main() {
    printf("Welcome to the CPU usage monitor program!\n");
    printf("This program will display the current CPU usage of your system.\n");
    printf("Press CTRL + C anytime to exit the program.\n");

    // Fetching the number of cpu cores
    FILE* fp;
    char buffer[1024];
    double loadavg[3];
    int num_cores = 0;
    fp = fopen("/proc/loadavg", "r");
    if (fp != NULL) {
        fgets(buffer, sizeof(buffer), fp);
        sscanf(buffer, "%lf %lf %lf", &loadavg[0], &loadavg[1], &loadavg[2]);
        fclose(fp);

        // The average number of processes running in the past minute can give the number of CPU cores
        num_cores = (int) loadavg[0];
        printf("Number of CPU cores: %d\n", num_cores);
    } else {
        printf("Error: /proc/loadavg not found.\n");
        return 1;
    }

    while(1) {
        // Fetching current CPU usage time
        unsigned long long cpu_time[10];
        fp = fopen("/proc/stat", "r");
        if (fp != NULL) {
            char* token;
            fgets(buffer, sizeof(buffer), fp);
            token = strtok(buffer, " ");
            int i = 0;
            while(token) {
                token = strtok(NULL, " ");
                if (token != NULL) {
                    cpu_time[i] = atoll(token);
                    i++;
                }
            }
            fclose(fp);
        } else {
            printf("Error: /proc/stat not found.\n");
            return 1;
        }

        // Delay for 1 second        
        sleep(1);                

        // Fetching new CPU usage time after 1 second
        unsigned long long new_cpu_time[10];
        fp = fopen("/proc/stat", "r");
        if (fp != NULL) {
            char* token;
            fgets(buffer, sizeof(buffer), fp);
            token = strtok(buffer, " ");
            int i = 0;
            while(token) {
                token = strtok(NULL, " ");
                if (token != NULL) {
                    new_cpu_time[i] = atoll(token);
                    i++;
                }
            }
            fclose(fp);
        } else {
            printf("Error: /proc/stat not found.\n");
            return 1;
        }

        // Calculating the total CPU time
        unsigned long long total_cpu_time = 0, total_time_diff = 0;
        for (int i=0; i<10; i++) {
            total_cpu_time += new_cpu_time[i] - cpu_time[i];
        }
        // Calculating the CPU usage time
        double cpu_usage = (double)(total_cpu_time - (new_cpu_time[3] - cpu_time[3])) / total_cpu_time;

        // Displaying the CPU usage percentage
        printf("CPU usage: %.2lf%%\n", cpu_usage*100);
    }

    return 0;
}
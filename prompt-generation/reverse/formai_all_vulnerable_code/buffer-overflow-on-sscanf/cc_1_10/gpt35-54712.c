//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

#define MAX_CPU_UTILIZATION 100.0

// function to calculate CPU utilization
double current_cpu_utilization() {
    double cpu_util;
    FILE *fp1, *fp2;
    long double user1, nice1, sys1, idle1, user2, nice2, sys2, idle2;
    char cpu_line[256];

    // opening CPU file stats for current values
    fp1 = fopen("/proc/stat", "r");
    if (fp1 == NULL) {
        return -1;
    }
    fgets(cpu_line, 256, fp1);
    fclose(fp1);

    sscanf(cpu_line, "cpu %Lf %Lf %Lf %Lf", &user1, &nice1, &sys1, &idle1);

    // wait for 1 second to get next CPU values
    sleep(1);

    // opening CPU file stats for new values
    fp2 = fopen("/proc/stat", "r");
    if (fp2 == NULL) {
        return -1;
    }
    fgets(cpu_line, 256, fp2);
    fclose(fp2);

    sscanf(cpu_line, "cpu %Lf %Lf %Lf %Lf", &user2, &nice2, &sys2, &idle2);

    // calculate utilization percentage
    cpu_util = 100.0 - ((idle2 - idle1) * 100.0) / ((user2 + nice2 + sys2 + idle2) - (user1 + nice1 + sys1 + idle1));

    return cpu_util;
}

// function to display CPU utilization percentage
void display_cpu_utilization(double cpu_util) {
    int i, bar_length;
    bar_length = (int)(cpu_util / MAX_CPU_UTILIZATION * 50);
    printf("\nCPU Utilization : %.2lf%%\n", cpu_util);
    printf("[");
    for (i = 0; i < 50; i++) {
        if (i < bar_length) {
            printf("=");
        } else {
            printf(" ");
        }
    }
    printf("]\n");
}

int main() {
    double cpu_util;
    int status;

    while (1) {
        cpu_util = current_cpu_utilization();
        if (cpu_util < 0) {
            printf("Error in reading CPU utilization\n");
            exit(1);
        }
        display_cpu_utilization(cpu_util);
        // wait for a second before next iteration
        sleep(1);
        // clear the terminal
        system("clear");
    }

    return 0;
}
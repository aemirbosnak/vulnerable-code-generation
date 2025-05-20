//GPT-4o-mini DATASET v1.0 Category: CPU usage monitor ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

void drawCPUUsage(float usage) {
    int filledBars = usage / 2;  // 50% fill corresponds to 25 bars
    int totalBars = 50; // Total of 50 bars to represent 100%
    
    printf("CPU Usage: [");
    for (int i = 0; i < totalBars; i++) {
        if (i < filledBars) {
            printf("#");
        } else {
            printf(" ");
        }
    }
    printf("] %.2f%%\n", usage);
}

float getCPUUsage() {
    FILE *file;
    long double a[4], b[4], loadavg;
    char dump[256];
    
    file = fopen("/proc/stat", "r");
    fgets(dump, sizeof(dump), file);
    sscanf(dump, "cpu %Lf %Lf %Lf %Lf", &a[0], &a[1], &a[2], &a[3]);
    fclose(file);
    
    sleep(1);  // waits a second for better measurement
    
    file = fopen("/proc/stat", "r");
    fgets(dump, sizeof(dump), file);
    sscanf(dump, "cpu %Lf %Lf %Lf %Lf", &b[0], &b[1], &b[2], &b[3]);
    fclose(file);
    
    loadavg = ((b[0] + b[1] + b[2]) - (a[0] + a[1] + a[2]));
    return (loadavg / (b[0] + b[1] + b[2] + b[3])) * 100;
}

int main() {
    char *prologue = "In fair Verona where we set our scene,\n"
                    "A tale of CPU, usage, and a dream.\n"
                    "Here lies our noble program, we create,\n"
                    "To measure what resource doth tempt our fate.\n";
    
    char *epilogue = "Thus ends our tragic tale of usage's plight,\n"
                    "With each cycle counted 'til the final night.\n"
                    "CPU, though you strive, we shall not forsake,\n"
                    "For in your numbers, true knowledge we make.\n";

    printf("%s", prologue);
    
    while (1) {
        float cpuUsage = getCPUUsage();
        drawCPUUsage(cpuUsage);
        
        if (cpuUsage >= 90.0) {
            printf("Alas! The CPU usage soars to great heights!\n");
        } else if (cpuUsage >= 75.0) {
            printf("Oh woe! The burden of tasks weighs so heavy.\n");
        } else if (cpuUsage >= 50.0) {
            printf("A dance of data, a rhythm we know.\n");
        } else {
            printf("A tranquil heart, the usage lies low.\n");
        }
        
        sleep(2);  // Pause to allow for the user to see the output
    }
    
    printf("%s", epilogue);
    
    return 0;
}
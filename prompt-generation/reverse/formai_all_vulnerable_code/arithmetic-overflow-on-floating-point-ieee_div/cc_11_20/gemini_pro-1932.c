//GEMINI-pro DATASET v1.0 Category: CPU usage monitor ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    // Create a file to store the CPU usage data
    FILE *fp = fopen("/proc/stat", "r");
    if (fp == NULL) {
        perror("Error opening /proc/stat");
        return EXIT_FAILURE;
    }

    // Read the first line of the file, which contains the overall CPU usage
    char line[1024];
    if (fgets(line, sizeof(line), fp) == NULL) {
        perror("Error reading /proc/stat");
        return EXIT_FAILURE;
    }

    // Close the file
    fclose(fp);

    // Parse the CPU usage data
    char *token;
    token = strtok(line, " ");
    double user, nice, system, idle, iowait, irq, softirq;
    int i;
    for (i = 0; i < 7; i++) {
        token = strtok(NULL, " ");
        switch (i) {
            case 0:
                user = atof(token);
                break;
            case 1:
                nice = atof(token);
                break;
            case 2:
                system = atof(token);
                break;
            case 3:
                idle = atof(token);
                break;
            case 4:
                iowait = atof(token);
                break;
            case 5:
                irq = atof(token);
                break;
            case 6:
                softirq = atof(token);
                break;
        }
    }

    // Calculate the total CPU usage
    double total = user + nice + system + idle + iowait + irq + softirq;

    // Calculate the percentage of CPU usage
    double percentage = (total - idle) / total * 100;

    // Print the CPU usage
    printf("CPU usage: %.2f%%\n", percentage);

    // Generate a funny message based on the CPU usage
    if (percentage < 10) {
        printf("Your computer is a lazy bum!\n");
    } else if (percentage < 25) {
        printf("Your computer is working hard, but it's still not breaking a sweat.\n");
    } else if (percentage < 50) {
        printf("Your computer is working hard, but it's still got some gas in the tank.\n");
    } else if (percentage < 75) {
        printf("Your computer is working hard, but it's starting to get tired.\n");
    } else if (percentage < 90) {
        printf("Your computer is working hard, and it's starting to show.\n");
    } else {
        printf("Your computer is working hard, and it's about to blow a gasket!\n");
    }

    return EXIT_SUCCESS;
}
//Falcon-180B DATASET v1.0 Category: CPU usage monitor ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

// Function to calculate the CPU usage
float get_cpu_usage() {
    FILE *file;
    char buffer[1024];
    float idle, total;
    int count = 0;

    // Open the /proc/stat file
    file = fopen("/proc/stat", "r");
    if (file == NULL) {
        printf("Error opening /proc/stat file.\n");
        exit(1);
    }

    // Read the file and calculate the idle and total CPU usage
    while (fgets(buffer, sizeof(buffer), file)!= NULL) {
        if (count == 1) {
            sscanf(buffer, "cpu %*s %*s %*s %*s %f", &idle);
        } else if (count == 2) {
            sscanf(buffer, "cpu %*s %*s %*s %*s %f", &total);
            break;
        }
        count++;
    }

    // Close the file
    fclose(file);

    // Calculate the CPU usage
    float usage = (total - idle) / total;

    return usage;
}

// Function to print the CPU usage
void print_cpu_usage(float usage) {
    printf("CPU usage: %.2f%%\n", usage * 100);
}

// Main function
int main() {
    float usage;

    // Get the initial CPU usage
    usage = get_cpu_usage();

    // Print the initial CPU usage
    print_cpu_usage(usage);

    // Loop and print the CPU usage every second
    while (1) {
        sleep(1);
        usage = get_cpu_usage();
        print_cpu_usage(usage);
    }

    return 0;
}
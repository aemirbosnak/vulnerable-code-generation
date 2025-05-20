//Falcon-180B DATASET v1.0 Category: CPU usage monitor ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <unistd.h>

int main() {
    struct rusage usage;
    int i = 0;
    float cpu_percentage;

    while(1) {
        getrusage(RUSAGE_SELF, &usage);
        cpu_percentage = (float)usage.ru_utime.tv_sec + (float)usage.ru_utime.tv_usec / 1000000;
        cpu_percentage *= 100;
        cpu_percentage /= (float)(usage.ru_utime.tv_sec + usage.ru_utime.tv_usec / 1000000 + usage.ru_stime.tv_sec + usage.ru_stime.tv_usec / 1000000);

        printf("CPU Usage: %.2f%%\n", cpu_percentage);
        fflush(stdout);
        usleep(500000); // Sleep for 0.5 seconds before updating the CPU usage again

        // Add some fun ASCII art to spice things up!
        switch(i) {
            case 0:
                printf("\n");
                printf(" _____ \n");
                printf("|     | \n");
                printf("|     | \n");
                printf("|     | \n");
                printf("|     | \n");
                printf("|_____| \n");
                break;
            case 1:
                printf("\n");
                printf(" _____ \n");
                printf("|   | \n");
                printf("|   | \n");
                printf("|   | \n");
                printf("|   | \n");
                printf("|_____| \n");
                break;
            case 2:
                printf("\n");
                printf(" _____ \n");
                printf("|   | \n");
                printf("|   | \n");
                printf("|   | \n");
                printf("|   | \n");
                printf("|   | \n");
                break;
            default:
                i = 0;
        }
        i++;
    }
    return 0;
}
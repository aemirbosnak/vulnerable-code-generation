//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* struct to hold the CPU usage information */
struct cpu_usage {
    unsigned long long user;    /* user mode */
    unsigned long long nice;    /* user mode with nice priority */
    unsigned long long system;  /* kernel mode */
    unsigned long long idle;    /* idle */
    unsigned long long iowait;  /* waiting for I/O to complete */
    unsigned long long irq;     /* servicing interrupts */
    unsigned long long softirq; /* servicing softirqs */
};

/* function to read the CPU usage information */
struct cpu_usage read_cpu_usage(void) {
    FILE *file;
    char buffer[1024];
    struct cpu_usage usage = {0};

    /* open the /proc/stat file */
    file = fopen("/proc/stat", "r");
    if (!file) {
        perror("fopen");
        exit(EXIT_FAILURE);
    }

    /* read the first line, which contains the overall CPU statistics */
    if (!fgets(buffer, sizeof(buffer), file)) {
        perror("fgets");
        exit(EXIT_FAILURE);
    }

    /* parse the line */
    sscanf(buffer, "cpu %llu %llu %llu %llu %llu %llu %llu", &usage.user, &usage.nice,
           &usage.system, &usage.idle, &usage.iowait, &usage.irq, &usage.softirq);

    /* close the file */
    fclose(file);

    /* return the parsed CPU usage information */
    return usage;
}

int main(void) {
    struct cpu_usage usage1, usage2;
    float usage_percentage;

    /* print a friendly greeting */
    printf("Welcome to the CPU usage monitor!\n\n");

    /* loop forever */
    while (1) {
        /* read the CPU usage information */
        usage1 = read_cpu_usage();

        /* wait for one second */
        sleep(1);

        /* read the CPU usage information again */
        usage2 = read_cpu_usage();

        /* calculate the CPU usage percentage */
        usage_percentage = ((float)(usage2.user + usage2.nice + usage2.system - usage1.user - usage1.nice - usage1.system) /
                       (float)(usage2.user + usage2.nice + usage2.system + usage2.idle + usage2.iowait + usage2.irq + usage2.softirq - usage1.user - usage1.nice - usage1.system - usage1.idle - usage1.iowait - usage1.irq - usage1.softirq)) * 100.0f;

        /* print the CPU usage percentage */
        printf("CPU usage: %.2f%%\n", usage_percentage);

        /* check if the CPU usage is too high */
        if (usage_percentage > 80.0f) {
            printf("WARNING: CPU usage is too high!\n");
        }

        /* print a blank line */
        printf("\n");
    }

    /* we never get here, but it's good practice to include a return statement */
    return 0;
}
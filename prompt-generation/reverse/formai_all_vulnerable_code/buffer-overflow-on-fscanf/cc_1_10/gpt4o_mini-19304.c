//GPT-4o-mini DATASET v1.0 Category: CPU usage monitor ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/sysinfo.h>
#include <signal.h>
#include <time.h>

#define MAX_BARS 50
#define BAR_CHAR '#'

static volatile sig_atomic_t stop;

void intHandler(int dummy) {
    stop = 1;
}

void display_loading_bar(int cpu_usage) {
    int bars_to_draw = (cpu_usage * MAX_BARS) / 100;

    printf("\r[");
    for (int i = 0; i < MAX_BARS; i++) {
        if (i < bars_to_draw) {
            printf("%c", BAR_CHAR);
        } else {
            printf(" ");
        }
    }
    printf("] %d%% CPU Usage", cpu_usage);
    fflush(stdout);
}

int get_cpu_usage() {
    FILE *fp;
    long double a[4], b[4];
    double load;

    fp = fopen("/proc/stat", "r");
    if (fp == NULL) {
        perror("Failed to open /proc/stat");
        exit(EXIT_FAILURE);
    }

    fscanf(fp, "cpu %Lf %Lf %Lf %Lf", &a[0], &a[1], &a[2], &a[3]);
    fclose(fp);
    usleep(100000); // Sleep for 100 milliseconds

    fp = fopen("/proc/stat", "r");
    if (fp == NULL) {
        perror("Failed to open /proc/stat");
        exit(EXIT_FAILURE);
    }

    fscanf(fp, "cpu %Lf %Lf %Lf %Lf", &b[0], &b[1], &b[2], &b[3]);
    fclose(fp);

    load = ((b[0] + b[1] + b[2]) - (a[0] + a[1] + a[2])) / (b[0] + b[1] + b[2] + b[3]) * 100;
    return (int)load;
}

void neon_signals() {
    printf("=================================\n");
    printf("☣️ Cyberpunk CPU Monitor ☣️\n");
    printf("=================================\n");
    printf("⚡️ Monitoring the cores in the neon-lit digital underbelly... ⚡️\n");
}

int main() {
    signal(SIGINT, intHandler);
    neon_signals();

    while (!stop) {
        int cpu_usage = get_cpu_usage();
        display_loading_bar(cpu_usage);
        usleep(1000000); // Sleep for 1 second
    }

    printf("\n🌌 Powering down... 🌌\n");
    return 0;
}
//Falcon2-11B DATASET v1.0 Category: Temperature monitor ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <time.h>

#define TEMPERATURE_FILE "/sys/class/thermal/thermal_zone0/temp"

void read_temperature() {
    FILE *fp;
    char buf[256];
    ssize_t n;

    fp = fopen(TEMPERATURE_FILE, "r");
    if (fp == NULL) {
        perror("fopen");
        return;
    }

    n = fread(buf, sizeof(char), sizeof(buf), fp);
    fclose(fp);

    if (n == 0) {
        perror("fread");
        return;
    }

    printf("Current temperature: %ld.%02ld°C\n", buf[0], buf[1]);
}

int main() {
    struct timespec start_time;
    struct timespec end_time;

    clock_gettime(CLOCK_REALTIME, &start_time);

    while (1) {
        read_temperature();
        clock_gettime(CLOCK_REALTIME, &end_time);

        double elapsed_time = (end_time.tv_sec - start_time.tv_sec) +
            1e-9 * (end_time.tv_nsec - start_time.tv_nsec);

        printf("Elapsed time: %.3fs\n", elapsed_time);

        start_time.tv_sec = end_time.tv_sec;
        start_time.tv_nsec = end_time.tv_nsec;
    }

    return 0;
}
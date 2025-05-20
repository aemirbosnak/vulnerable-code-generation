//Falcon-180B DATASET v1.0 Category: CPU usage monitor ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <sys/resource.h>
#include <unistd.h>
#include <string.h>
#include <math.h>
#include <time.h>

FILE *fp;
char filename[20];
int count = 0;
struct rusage usage;

// Function to get CPU usage
void get_cpu_usage(double *cpu_percent) {
    if (getrusage(RUSAGE_SELF, &usage) == -1) {
        perror("getrusage");
        exit(EXIT_FAILURE);
    }

    *cpu_percent = ((double) usage.ru_utime.tv_sec + (double) usage.ru_stime.tv_sec) / (double) usage.ru_utime.tv_sec;
}

// Function to write CPU usage to file
void write_to_file(double cpu_percent) {
    time_t now = time(NULL);
    struct tm *t = localtime(&now);
    sprintf(filename, "cpu_usage_%d_%d_%d_%d_%d_%d.txt", t->tm_hour, t->tm_min, t->tm_sec, count++, cpu_percent, getpid());

    if ((fp = fopen(filename, "w")) == NULL) {
        fprintf(stderr, "Cannot create file %s\n", filename);
        exit(EXIT_FAILURE);
    }

    fprintf(fp, "CPU usage at %s: %.2f%%\n", asctime(t), cpu_percent);
    fclose(fp);
}

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <seconds>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    int seconds = atoi(argv[1]);
    double cpu_percent;

    while (seconds-- > 0) {
        get_cpu_usage(&cpu_percent);
        write_to_file(cpu_percent);
        sleep(1);
    }

    return 0;
}
//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/time.h>
#include <sys/resource.h>

#define MAX_BUFF_SIZE 256

int main(int argc, char *argv[]) {

    struct rusage usage;
    struct timeval start, end;

    if (argc < 2) {
        printf("Error: Need to provide a program name.\n");
        printf("Usage: %s [program]\n", argv[0]);
        exit(1);
    }

    if (gettimeofday(&start, NULL) < 0) {
        printf("Error: Failed to get start time.\n");
        exit(1);
    }

    int pid = fork();

    if (pid < 0) {
        printf("Error: Failed to fork.\n");
        exit(1);
    }

    if (!pid) {
        // Child process
        if (execvp(argv[1], &argv[1]) < 0) {
            printf("Error: Failed to execute %s.\n", argv[1]);
            exit(1);
        }
    }

    // Parent process
    int status;
    if (waitpid(pid, &status, 0) < 0) {
        printf("Error: Failed to wait for child process.\n");
        exit(1);
    }

    if (gettimeofday(&end, NULL) < 0) {
        printf("Error: Failed to get end time.\n");
        exit(1);
    }

    long elapsed_sec = end.tv_sec - start.tv_sec;
    long elapsed_usec = end.tv_usec - start.tv_usec;
    long total_elapsed = (elapsed_sec * 1000000) + elapsed_usec;

    getrusage(RUSAGE_CHILDREN, &usage);
    long total_cpu_time_sec = usage.ru_utime.tv_sec + usage.ru_stime.tv_sec;
    long total_cpu_time_usec = usage.ru_utime.tv_usec + usage.ru_stime.tv_usec;
    long total_cpu_time = (total_cpu_time_sec * 1000000) + total_cpu_time_usec;

    printf("\n");
    printf("Program Name: %s\n", argv[1]);
    printf("Elapsed Time: %ld microseconds\n", total_elapsed);
    printf("CPU Time: %ld microseconds\n", total_cpu_time);
    printf("\n");

    return 0;
}
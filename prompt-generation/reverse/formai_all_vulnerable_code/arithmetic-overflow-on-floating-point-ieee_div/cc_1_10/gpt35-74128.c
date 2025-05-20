//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/resource.h>

#define MAX_BUFF_SIZE 256

int main(int argc, char *argv[]) {
    struct timespec delay = {.tv_sec = 1, .tv_nsec = 0};
    int pid;
    FILE *infile;
    char filename[MAX_BUFF_SIZE];
    char buffer[MAX_BUFF_SIZE];
    float cpu_usage, user_time, sys_time;
    
    if (argc < 2) {
        printf("Usage: %s <PID>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    
    pid = atoi(argv[1]);
    
    while (1) {
        snprintf(filename, MAX_BUFF_SIZE, "/proc/%d/stat", pid);
        infile = fopen(filename, "r");
        if (!infile) {
            printf("Error: Could not open file %s.\n", filename);
            exit(EXIT_FAILURE);
        }
        
        if (!fgets(buffer, MAX_BUFF_SIZE, infile)) {
            printf("Error: Could not read file %s.\n", filename);
            exit(EXIT_FAILURE);
        }
        
        sscanf(buffer, "%*d %*s %*c %*d %*d %*d %*d %*d %*u %*u %*u %*u %f %f", &user_time, &sys_time);
        
        fclose(infile);
        
        cpu_usage = (user_time + sys_time) / sysconf(_SC_CLK_TCK);
        
        printf("Process with PID %d: CPU usage = %.2f%%\n", pid, cpu_usage);
        
        nanosleep(&delay, NULL);
    }
    
    return 0;
}
//Falcon-180B DATASET v1.0 Category: CPU usage monitor ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define PROC_FILE "/proc/self/stat"
#define CPU_USAGE_FILE "/proc/stat"
#define BUFFER_SIZE 1024

int main() {
    int fd;
    char buffer[BUFFER_SIZE];
    FILE *proc_file;
    FILE *cpu_usage_file;
    char *token;
    int i, j, n, line_num;
    float cpu_usage;

    // Open the /proc/self/stat file
    fd = open(PROC_FILE, O_RDONLY);
    if (fd == -1) {
        printf("Error opening %s\n", PROC_FILE);
        exit(1);
    }

    // Open the /proc/stat file
    cpu_usage_file = fopen(CPU_USAGE_FILE, "r");
    if (cpu_usage_file == NULL) {
        printf("Error opening %s\n", CPU_USAGE_FILE);
        exit(1);
    }

    // Read the CPU usage from the /proc/stat file
    if (fgets(buffer, BUFFER_SIZE, cpu_usage_file) == NULL) {
        printf("Error reading from %s\n", CPU_USAGE_FILE);
        exit(1);
    }

    // Close the /proc/stat file
    fclose(cpu_usage_file);

    // Parse the /proc/self/stat file
    proc_file = fdopen(fd, "r");
    line_num = 0;
    while (fgets(buffer, BUFFER_SIZE, proc_file)!= NULL) {
        line_num++;
        if (line_num == 1) {
            // Parse the CPU time used by the process
            token = strtok(buffer, " ");
            i = atoi(token);
            token = strtok(NULL, " ");
            j = atoi(token);
            cpu_usage = (float) (j - i) / (float) sysconf(_SC_CLK_TCK);
        }
    }

    // Close the /proc/self/stat file
    fclose(proc_file);

    // Print the CPU usage percentage
    printf("CPU usage: %.2f%%\n", cpu_usage * 100);

    return 0;
}
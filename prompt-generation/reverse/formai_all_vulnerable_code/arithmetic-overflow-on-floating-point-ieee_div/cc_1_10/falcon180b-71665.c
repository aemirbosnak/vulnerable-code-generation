//Falcon-180B DATASET v1.0 Category: CPU usage monitor ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <string.h>

#define PROC_SELF_STAT "/proc/self/stat"
#define PROC_SELF_STATM "/proc/self/statm"
#define PROC_SELF_STATUS "/proc/self/status"
#define PROC_SELF_LIMIT "/proc/self/limits"
#define PROC_SELF_CGROUP "/proc/self/cgroup"

int get_process_cpu_usage(char *process_name) {
    FILE *file;
    char line[1024];
    int cpu_usage = 0;

    file = fopen(PROC_SELF_STATUS, "r");

    if (file == NULL) {
        printf("Error: Failed to open %s\n", PROC_SELF_STATUS);
        return -1;
    }

    while (fgets(line, sizeof(line), file)!= NULL) {
        if (strstr(line, process_name)!= NULL) {
            sscanf(line, "%*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %d", &cpu_usage);
            break;
        }
    }

    fclose(file);

    return cpu_usage;
}

int main() {
    struct rusage usage;
    char buffer[1024];
    int cpu_usage;

    getrusage(RUSAGE_SELF, &usage);

    cpu_usage = (int) (((float) usage.ru_utime.tv_sec + (float) usage.ru_stime.tv_sec + (float) usage.ru_utime.tv_usec + (float) usage.ru_stime.tv_usec) / (float) sysconf(_SC_CLK_TCK));

    printf("CPU Usage: %d%%\n", cpu_usage);

    memset(buffer, 0, sizeof(buffer));
    snprintf(buffer, sizeof(buffer), "CPU Usage: %d%%", cpu_usage);

    system("echo -ne '\033]0;' && echo -ne $(tput setaf 2)$(tput setab 7)$buffer$(tput sgr0) && echo -ne '\007'");

    return 0;
}
//Falcon-180B DATASET v1.0 Category: CPU usage monitor ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define PROC_FILE "/proc/self/stat"

typedef struct {
    int cpu_usage;
    char process_name[16];
} process_info;

int get_cpu_usage(process_info *info) {
    FILE *fp;
    char line[1024];
    int found = 0;

    fp = fopen(PROC_FILE, "r");
    if (fp == NULL) {
        printf("Error: cannot open %s\n", PROC_FILE);
        exit(1);
    }

    while (fgets(line, sizeof(line), fp)!= NULL) {
        if (strncmp(line, "cpu ", 4) == 0) {
            sscanf(line, "cpu  %d", &info->cpu_usage);
            found = 1;
            break;
        }
    }

    fclose(fp);

    if (!found) {
        printf("Error: cannot find cpu usage in %s\n", PROC_FILE);
        exit(1);
    }

    return 0;
}

int get_process_name(process_info *info) {
    FILE *fp;
    char line[1024];
    int found = 0;

    fp = fopen("/proc/self/cmdline", "r");
    if (fp == NULL) {
        printf("Error: cannot open /proc/self/cmdline\n");
        exit(1);
    }

    while (fgets(line, sizeof(line), fp)!= NULL) {
        if (strlen(line) > 0 && line[strlen(line) - 1] == '\n') {
            line[strlen(line) - 1] = '\0';
        }

        if (strlen(line) > 0) {
            strncpy(info->process_name, line, sizeof(info->process_name) - 1);
            info->process_name[sizeof(info->process_name) - 1] = '\0';
            found = 1;
            break;
        }
    }

    fclose(fp);

    if (!found) {
        printf("Error: cannot find process name in /proc/self/cmdline\n");
        exit(1);
    }

    return 0;
}

void print_cpu_usage(process_info *info) {
    printf("CPU usage: %.2f%%\n", (float)info->cpu_usage / (float)sysconf(_SC_CLK_TCK) * 100.0);
    printf("Process name: %s\n", info->process_name);
}

int main() {
    process_info info;

    get_cpu_usage(&info);
    get_process_name(&info);

    print_cpu_usage(&info);

    return 0;
}
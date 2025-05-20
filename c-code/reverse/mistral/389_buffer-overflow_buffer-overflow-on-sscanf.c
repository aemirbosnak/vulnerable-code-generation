#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <string.h>
#include <time.h>

#define BUFFER_SIZE 4096

int main() {
    FILE *file;
    char buffer[BUFFER_SIZE];
    char line[BUFFER_SIZE];
    int mem_total = 0, mem_free = 0;
    double mem_used = 0.0;
    double mem_used_prev = 0.0;
    int status;

    while (1) {
        file = fopen("/proc/meminfo", "r");
        if (file == NULL) {
            perror("Error opening /proc/meminfo");
            continue;
        }

        while ((status = getline(&buffer, BUFFER_SIZE, file)) != -1) {
            if (strstr(buffer, "MemTotal:")) {
                mem_total = strtoul(strtok(buffer, ":") + 1, NULL, 10);
            }
            if (strstr(buffer, "MemFree:")) {
                mem_free = strtoul(strtok(buffer, ":") + 1, NULL, 10);
            }
        }

        fclose(file);

        mem_used = ((double) (mem_total - mem_free)) / (double) mem_total * 100.0;

        if (mem_used_prev != mem_used) {
            mem_used_prev = mem_used;
            time_t rawtime;
            struct tm *timeinfo;

            time(&rawtime);
            timeinfo = localtime(&rawtime);

            printf("%s: Memory usage: %.2f%%\n", asctime(timeinfo), mem_used);
        }

        sleep(1);
    }

    return 0;
}

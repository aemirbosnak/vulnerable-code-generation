#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_LINES 100
#define MAX_LINE_LENGTH 256

int main() {
    char buffer[MAX_LINE_LENGTH];
    int cpu_usage[MAX_LINES];
    int line_count = 0;

    while (1) {
        FILE *fp = popen("top -bn1 | grep 'Cpu(s)'", "r");
        if (fp == NULL) {
            perror("popen");
            exit(EXIT_FAILURE);
        }

        while (fgets(buffer, sizeof(buffer), fp) != NULL && line_count < MAX_LINES) {
            sscanf(buffer, "Cpu(s): %d.%d us, %d.%d sy, %d.%d ni, %d.%d id, %d.%d wa, %d.%d hi, %d.%d si, %d.%d st",
                   &cpu_usage[line_count], &cpu_usage[line_count + 1],
                   &cpu_usage[line_count + 2], &cpu_usage[line_count + 3],
                   &cpu_usage[line_count + 4], &cpu_usage[line_count + 5],
                   &cpu_usage[line_count + 6], &cpu_usage[line_count + 7],
                   &cpu_usage[line_count + 8], &cpu_usage[line_count + 9],
                   &cpu_usage[line_count + 10], &cpu_usage[line_count + 11],
                   &cpu_usage[line_count + 12], &cpu_usage[line_count + 13],
                   &cpu_usage[line_count + 14], &cpu_usage[line_count + 15]);
            line_count += 16;
        }

        pclose(fp);

        for (int i = 0; i < line_count; i++) {
            printf("\rCPU Usage: %d%%", cpu_usage[i]);
            fflush(stdout);
            usleep(100000);
        }

        printf("\n");
        sleep(1);
    }

    return 0;
}

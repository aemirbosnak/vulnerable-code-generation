#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define TOP_COMMAND "top -bn1 | grep 'Cpu(s)'"
#define GRAPH_WIDTH 50

void display_graph(float cpu_usage) {
    int bars = (int)(cpu_usage * GRAPH_WIDTH / 100);
    printf("CPU Usage: %.2f%%\n", cpu_usage);
    for (int i = 0; i < bars; ++i) {
        printf("#");
    }
    printf("\n");
}

int main() {
    FILE *fp;
    char buffer[128];
    float user_cpu, nice_cpu, system_cpu, idle_cpu;

    fp = popen(TOP_COMMAND, "r");
    if (fp == NULL) {
        perror("Failed to run top command");
        return EXIT_FAILURE;
    }

    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
        sscanf(buffer, "Cpu(s): %*f us, %*f ni, %f sy, %*f id", &system_cpu);
        idle_cpu = 100.0 - (user_cpu + nice_cpu + system_cpu);
    }

    pclose(fp);

    display_graph(system_cpu);

    return EXIT_SUCCESS;
}

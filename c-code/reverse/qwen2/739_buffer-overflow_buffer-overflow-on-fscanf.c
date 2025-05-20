#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_LINE_LENGTH 256

void read_cpu_usage(double *usage) {
    FILE *fp = popen("top -bn1 | grep 'Cpu(s)'", "r");
    if (fp == NULL) {
        perror("Failed to run top command");
        exit(EXIT_FAILURE);
    }
    char line[MAX_LINE_LENGTH];
    if (fgets(line, sizeof(line), fp) != NULL) {
        sscanf(line, "Cpu(s): %*f us, %*f sy, %*f ni, %*f id, %*f wa, %*f hi, %*f si, %*f st", usage);
    } else {
        fprintf(stderr, "Failed to parse top output\n");
        exit(EXIT_FAILURE);
    }
    pclose(fp);
}

void print_graph(double cpu_usage) {
    int bar_length = (int)(cpu_usage / 100.0 * 40);
    printf("\rCPU Usage: [");
    for (int i = 0; i < bar_length; i++) {
        putchar('#');
    }
    for (int i = bar_length; i < 40; i++) {
        putchar(' ');
    }
    printf("] %.2f%%\r", cpu_usage);
    fflush(stdout);
}

int main() {
    double cpu_usage;
    while (1) {
        read_cpu_usage(&cpu_usage);
        print_graph(cpu_usage);
        sleep(1);
    }
    return 0;
}

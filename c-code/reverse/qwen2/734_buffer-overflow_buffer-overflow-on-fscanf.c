#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define MAX_PROCESSES 100

int main() {
    FILE *fp;
    char line[256];
    int cpu_usage[MAX_PROCESSES];

    fp = popen("top -bn1 | awk '/Cpu(s):/ {print $2 + $4}'", "r");
    if (fp == NULL) {
        perror("popen");
        exit(EXIT_FAILURE);
    }

    while (fgets(line, sizeof(line), fp) != NULL) {
        for (int i = 0; i < MAX_PROCESSES; i++) {
            fscanf(fp, "%d", &cpu_usage[i]);
        }
    }

    pclose(fp);

    return 0;
}

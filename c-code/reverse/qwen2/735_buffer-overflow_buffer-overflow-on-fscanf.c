#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fp;
    char buffer[128];
    int cpu_usage;

    fp = popen("top -bn1 | grep 'Cpu(s)' | sed 's/.*, *\([0-9.]*\)%* id.*/\1/'", "r");
    if (fp == NULL) {
        perror("Failed to run command");
        return 1;
    }

    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
        sscanf(buffer, "%d", &cpu_usage);
        printf("CPU Usage: %d%%\n", 100 - cpu_usage);
    }

    pclose(fp);
    return 0;
}

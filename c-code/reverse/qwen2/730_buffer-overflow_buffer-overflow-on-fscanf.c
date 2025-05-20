#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define MAX_LINES 100
#define MAX_CHARS 256

int main() {
    FILE *fp;
    char buffer[MAX_CHARS];
    int cpu_usage[MAX_LINES] = {0};
    int line_count = 0;

    fp = popen("top -bn1 | grep 'Cpu(s)'", "r");
    if (fp == NULL) {
        printf("Failed to run command\n" );
        return 1;
    }

    while (fgets(buffer, sizeof(buffer), fp) != NULL && line_count < MAX_LINES) {
        sscanf(buffer, "Cpu(s): %d.0 us, %d.0 sy, %*s ni, %*s id, %*s wa, %*s hi, %*s si, %*s st", &cpu_usage[line_count], &cpu_usage[line_count]);
        line_count++;
    }

    pclose(fp);

    for (int i = 0; i < line_count; i++) {
        printf("%d%%\n", cpu_usage[i]);
    }

    return 0;
}

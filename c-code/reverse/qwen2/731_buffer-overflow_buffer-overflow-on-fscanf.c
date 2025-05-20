#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_LINES 100
#define MAX_LINE_LENGTH 256

int main() {
    FILE *fp;
    char buffer[MAX_LINE_LENGTH];
    int cpu_usage[MAX_LINES] = {0};
    int line_count = 0;

    while (1) {
        fp = popen("top -bn1 | grep 'Cpu(s)'", "r");
        if (fp == NULL) {
            printf("Failed to run command\n" );
            exit(1);
        }

        while (fgets(buffer, sizeof(buffer), fp) != NULL) {
            sscanf(buffer, "Cpu(s): %d.0 us, %d.0 sy, %*f ni, %*f id, %*f wa, %*f hi, %*f si, %*f st", &cpu_usage[line_count], &cpu_usage[line_count]);
            line_count++;
        }

        pclose(fp);

        for (int i = 0; i < line_count; i++) {
            printf("\rCPU Usage: ");
            for (int j = 0; j < cpu_usage[i]; j++) {
                printf("#");
            }
            printf(" %d%%", cpu_usage[i]);
            fflush(stdout);
            sleep(1);
        }

        line_count = 0;
        system("clear");
    }

    return 0;
}

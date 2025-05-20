#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_LINE_LENGTH 256
#define NUM_SAMPLES 64

int main() {
    FILE *fp;
    char line[MAX_LINE_LENGTH];
    int cpu_usage[NUM_SAMPLES] = {0};
    int index = 0;

    while (1) {
        fp = popen("top -bn1 | grep 'Cpu(s)'", "r");
        if (fp == NULL) {
            printf("Failed to run command\n" );
            exit(1);
        }

        fgets(line, sizeof(line), fp);
        pclose(fp);

        sscanf(line, "Cpu(s): %*d.0 us, %*d.0 sy, %*d.0 ni, %*d.0 id, %*d.0 wa, %*d.0 hi, %*d.0 si, %d.0 st", &cpu_usage[index]);

        for (int i = 0; i < NUM_SAMPLES; i++) {
            printf("\rCPU Usage: ");
            for (int j = 0; j < cpu_usage[i]; j += 2) {
                printf("#");
            }
            printf(" %d%%", cpu_usage[i]);
        }
        fflush(stdout);

        sleep(1);
        index = (index + 1) % NUM_SAMPLES;
    }

    return 0;
}

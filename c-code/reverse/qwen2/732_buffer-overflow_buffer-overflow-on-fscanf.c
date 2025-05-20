#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int main() {
    long double cpu_usage[BUFFER_SIZE];
    int count = 0;
    FILE *pipe = popen("top -bn1 | grep 'Cpu(s)' | sed 's/.*, *\([0-9.]*\)%* id.*/\\1/' | awk '{print 100 - $1}'", "r");
    
    if (!pipe) return -1;

    while (1) {
        if (count >= BUFFER_SIZE) count = 0;
        fscanf(pipe, "%Lf", &cpu_usage[count]);
        printf("\rCPU Usage: %.2Lf%%", cpu_usage[count]);
        fflush(stdout);
        sleep(1);
        count++;
    }

    pclose(pipe);
    return 0;
}

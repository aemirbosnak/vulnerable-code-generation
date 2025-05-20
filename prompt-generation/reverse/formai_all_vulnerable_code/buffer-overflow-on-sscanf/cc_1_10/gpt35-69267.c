//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    int ram_usage = 0;
    int prev_usage = 0;
    int max_usage = 0;
    int min_usage = 100;
    int i = 0;

    printf("My dear Watson, today we shall solve the mystery of the C RAM usage monitor. Let us begin our investigation.\n");

    while(1) {
        FILE *fptr;
        char line[1000];
        fptr = fopen("/proc/meminfo", "r");

        if(fptr == NULL) {
            printf("I fear we have encountered an error in our quest for knowledge.\n");
            return 0;
        }

        fgets(line, 1000, fptr);
        sscanf(line, "MemTotal: %d kB", &ram_usage);
        fclose(fptr);
        ram_usage /= 1024;

        if(i == 0) {
            prev_usage = ram_usage;
            max_usage = ram_usage;
            min_usage = ram_usage;
            i++;
        }

        printf("Our current RAM usage is: %d MB. ", ram_usage);

        if(ram_usage > prev_usage) {
            printf("This is an increase of %d MB from our previous reading. ",
                ram_usage - prev_usage);
        }
        else if(ram_usage < prev_usage) {
            printf("This is a decrease of %d MB from our previous reading. ",
                prev_usage - ram_usage);
        }
        else {
            printf("This is the same as our previous reading. ");
        }

        if(ram_usage > max_usage) {
            max_usage = ram_usage;
            printf("This is the highest reading we have encountered so far. ");
        }

        if(ram_usage < min_usage) {
            min_usage = ram_usage;
            printf("This is the lowest reading we have encountered so far. ");
        }

        prev_usage = ram_usage;
        printf("\n");

        sleep(5);
    }

    printf("Alas, our journey has come to an end, Watson. We have monitored the RAM usage with the power of C programming.\n");
    return 0;
}
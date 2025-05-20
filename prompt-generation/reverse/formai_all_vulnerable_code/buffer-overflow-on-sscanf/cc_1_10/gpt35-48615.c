//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: optimized
#include <stdio.h>
#include <unistd.h>     // for sleep function
#include <fcntl.h>      // for file operations
#include <stdlib.h>     // for exit function

const char* CPU_USAGE_FILE_PATH = "/proc/stat";

int main()
{
    FILE* file = fopen(CPU_USAGE_FILE_PATH, "r");     // opening file for read operation
    if (file == NULL) {
        printf("Unable to read file '\\/proc\\/stat\\'");
        exit(1);        // exit with non-zero status code
    }

    char read_buffer[1024];
    int fd = fileno(file);
    unsigned long long int total_previous_idle = 0, total_previous_time = 0;

    while (1) {
        lseek(fd, 0, SEEK_SET);     // reset file pointer to the beginning
        fgets(read_buffer, sizeof(read_buffer), file);      // read the first line

        unsigned long long int user, nice, system, idle, iowait, irq, softirq, steal, guest, guest_nice;
        // parsing the numbers from the line read from the file
        sscanf(read_buffer, "cpu  %llu %llu %llu %llu %llu %llu %llu %llu %llu %llu",
            &user, &nice, &system, &idle, &iowait, &irq, &softirq, &steal, &guest, &guest_nice);

        // computing the total CPU time and the total idle time
        unsigned long long int total_time = (user + nice + system + idle + iowait + irq + softirq + steal);
        unsigned long long int total_idle = idle;

        if (total_previous_idle != 0 && total_previous_time != 0) {
            // computing CPU usage based on the previous total CPU time and idle time
            unsigned long long int diff_total_time = (total_time - total_previous_time);
            unsigned long long int diff_idle_time = (total_idle - total_previous_idle);
            double cpu_usage = (((double)(diff_total_time - diff_idle_time)) / (double)diff_total_time) * 100.0;

            printf("CPU Usage: %.1f %%\n", cpu_usage);
        }

        // updating the total_previous_idle and total_previous_time
        total_previous_idle = total_idle;
        total_previous_time = total_time;

        sleep(1);       // wait for 1 second before next iteration
    }

    fclose(file);       // close the file
    return 0;           // exit with zero status code
}
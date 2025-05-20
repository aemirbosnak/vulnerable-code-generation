//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: Romeo and Juliet
// Romeo, O Romeo! Where art thou, O Romeo?
// Ah! I see thee now, but why dost thou look so sad?
// What troubles thee, my love, come, speak with me.
// For I am Juliet, and I shall listen to thy woes.

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/sysinfo.h>

// Declare function to get CPU usage
float get_cpu_usage() {
    FILE* fp;
    char buffer[1024];
    float cpu_usage;
    int user, nice, sys, idle, iowait, irq, softirq, steal, guest, guest_nice;
    fp = fopen("/proc/stat", "r");
    fgets(buffer, sizeof(buffer), fp);
    sscanf(buffer, "cpu %d %d %d %d %d %d %d %d %d %d", &user, &nice, &sys, &idle, &iowait, &irq, &softirq, &steal, &guest, &guest_nice);
    fclose(fp);

    cpu_usage = ((float)(user + nice + sys) / (float)(user + nice  + sys + idle + iowait + irq + softirq) * 100);
    return cpu_usage;
}

// Declare main function
int main() {
    float cpu_usage;
    struct sysinfo sys_info;
    unsigned long long total_ram_usage, free_ram_usage;

    while(1) {
        // Sleep for 1 second
        usleep(1000000);

        // Get CPU usage percentage
        cpu_usage = get_cpu_usage();

        // Get system information
        sysinfo(&sys_info);

        // Calculate total and free ram usage
        total_ram_usage = sys_info.totalram * sys_info.mem_unit;
        free_ram_usage = sys_info.freeram * sys_info.mem_unit;

        // Print CPU and RAM usage
        printf("CPU usage: %.2f%%\n", cpu_usage);
        printf("Total RAM usage: %llu bytes\n", total_ram_usage);
        printf("Free RAM usage: %llu bytes\n\n", free_ram_usage);
    }

    return 0;
}
// But soft! What code through yonder window breaks?
// It is the monitor, and it doth keep watch
// O'er the fair CPU and RAM of this land
// Forsooth, it doth calculate and measure
// The usage of these resources, and displayeth it clear
// For all to see, and thus make wise decisions
// Verily, it is a tool of great power and worth
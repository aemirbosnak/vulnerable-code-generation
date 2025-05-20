//GPT-4o-mini DATASET v1.0 Category: RAM usage monitor ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/sysinfo.h>

void display_ram_usage() {
    struct sysinfo sys_info;

    // Retrieve system information
    if (sysinfo(&sys_info) != 0) {
        perror("sysinfo");
        return;
    }

    long total_ram = sys_info.totalram;
    long free_ram = sys_info.freeram;
    long used_ram = total_ram - free_ram;

    // Calculate percentages
    double used_percent = (double)(used_ram) / total_ram * 100;
    double free_percent = (double)(free_ram) / total_ram * 100;

    // Print RAM usage
    printf("====================================\n");
    printf("  Grateful RAM Usage Monitor\n");
    printf("====================================\n");
    printf("Total RAM:        %ld MB\n", total_ram / (1024 * 1024));
    printf("Free RAM:        %ld MB (%.2f%%)\n", free_ram / (1024 * 1024), free_percent);
    printf("Used RAM:        %ld MB (%.2f%%)\n", used_ram / (1024 * 1024), used_percent);
    printf("====================================\n");
}

void display_thankful_message() {
    printf("Thank you, precious hardware, for providing us with the resources to run!\n");
    printf("Your support is invaluable in making our tasks successful.\n");
    printf("We appreciate every byte and every cycle you give us!\n\n");
}

int main() {
    printf("Welcome to the Grateful RAM Monitor!\n");
    printf("Expecting to share insights about your RAM usage...\n\n");

    while (1) {
        display_thankful_message();
        display_ram_usage();
        
        // Sleep for 5 seconds before next update
        printf("Fetching new data in 5 seconds... \n\n");
        sleep(5);
    }

    return 0;
}
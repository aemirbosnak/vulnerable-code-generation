//GPT-4o-mini DATASET v1.0 Category: RAM usage monitor ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/sysinfo.h>

void print_ram_usage() {
    struct sysinfo info;
    
    if (sysinfo(&info) != 0) {
        perror("sysinfo failed");
        return;
    }

    long total_ram = info.totalram / (1024 * 1024); // MB
    long free_ram = info.freeram / (1024 * 1024);   // MB
    long used_ram = total_ram - free_ram;

    printf("\033[1;32m"); // Set green color for RAM usage
    printf("        --- RAM Usage Monitor ---\n");
    printf("\033[0m"); // Reset color
    printf("   Total RAM: %ld MB\n", total_ram);
    printf("   Free RAM:  %ld MB\n", free_ram);
    printf("   Used RAM:  %ld MB\n", used_ram);
    printf("\033[1;34m"); // Set blue color for bar visual
    printf("   RAM Usage Bar: ");
    
    int bar_length = 50; // Length of the RAM usage bar
    int used_bar_length = (int)((double)used_ram / total_ram * bar_length);
    
    for (int i = 0; i < used_bar_length; i++)
        putchar('#');
    
    for (int i = used_bar_length; i < bar_length; i++)
        putchar('-');
    
    printf(" %d%%\n", (int)((double)used_ram / total_ram * 100));
    printf("\033[0m"); // Reset color
}

int main() {
    printf("\033[1;35m"); // Set purple color for starting message
    printf(":: Welcome to the Creative RAM Usage Monitor ::\n");
    printf("Gathering your RAM's secrets...\n");
    printf("\033[0m"); // Reset color

    while (1) {
        print_ram_usage();
        sleep(2); // Refresh every 2 seconds
        printf("\033[1;31m"); // Set red color for separation line
        printf("===========================================\n");
        printf("\033[0m"); // Reset color
    }

    return 0;
}
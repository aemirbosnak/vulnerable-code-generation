//GPT-4o-mini DATASET v1.0 Category: RAM usage monitor ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <sys/sysinfo.h>
#include <unistd.h>

void display_shape(int size, char shape) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (j == 0 || j == size-1 || i == 0 || i == size-1 || i == j) {
                printf("%c", shape);
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

void clear_console() {
    printf("\033[H\033[J");
}

void monitor_memory() {
    struct sysinfo sys_info;
    
    while (1) {
        if (sysinfo(&sys_info) != 0) {
            perror("sysinfo");
            return;
        }

        long total_ram = sys_info.totalram;
        long free_ram = sys_info.freeram;
        long used_ram = total_ram - free_ram;
        float used_ram_percentage = (used_ram * 100.0) / total_ram;

        clear_console();
        printf("Total RAM: %.2f GB\n", total_ram / (1024.0 * 1024.0 * 1024.0));
        printf("Free RAM: %.2f GB\n", free_ram / (1024.0 * 1024.0 * 1024.0));
        printf("Used RAM: %.2f GB (%.2f%%)\n", used_ram / (1024.0 * 1024.0 * 1024.0), used_ram_percentage);

        int shape_size = (used_ram_percentage / 10) + 1; // Shape size based on used RAM percentage
        char shape = '*';
        
        printf("\nCurrent Memory Usage Shape:\n");
        display_shape(shape_size, shape);
        
        sleep(2); // Update every 2 seconds
    }
}

int main() {
    printf("Welcome to the RAM Usage Monitor!\n");
    printf("Monitoring RAM usage with a shape-shifting display...\n");
    
    monitor_memory();

    return 0;
}
//GPT-4o-mini DATASET v1.0 Category: RAM usage monitor ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/sysinfo.h>

void get_memory_usage(float *total, float *free, float *used) {
    struct sysinfo info;
    sysinfo(&info);
    *total = info.totalram * info.mem_unit / (1024 * 1024);
    *free = info.freeram * info.mem_unit / (1024 * 1024);
    *used = *total - *free;
}

void display_memory_usage() {
    float total, free, used;

    get_memory_usage(&total, &free, &used);

    printf("Memory Usage:\n");
    printf("Total Memory: %.2f MB\n", total);
    printf("Free Memory: %.2f MB\n", free);
    printf("Used Memory: %.2f MB\n", used);

    // Display percentage of memory used
    float used_percentage = (used / total) * 100;
    printf("Used Memory Percentage: %.2f%%\n", used_percentage);
}

void display_memory_usage_in_loop(int interval) {
    while (1) {
        display_memory_usage();
        sleep(interval);
        printf("\n");
    }
}

void print_memory_bar(float used, float total) {
    int bar_width = 50; // Width of the progress bar
    int used_blocks = (int)((used / total) * bar_width);
    
    printf("Memory Usage Bar: [");
    for (int i = 0; i < bar_width; i++) {
        if (i < used_blocks) {
            printf("█");
        } else {
            printf(" ");
        }
    }
    printf("] %.2f MB / %.2f MB\n", used, total);
}

void show_interactive_menu() {
    int choice, interval;
    
    while (1) {
        printf("Memory Usage Monitor Menu:\n");
        printf("1. Display memory usage once\n");
        printf("2. Display memory usage continuously\n");
        printf("3. Show memory usage bar\n");
        printf("4. Exit\n");
        printf("Please make a choice: ");
        
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                display_memory_usage();
                break;
            case 2:
                printf("Enter the interval in seconds: ");
                scanf("%d", &interval);
                display_memory_usage_in_loop(interval);
                break;
            case 3: {
                float total, free, used;
                get_memory_usage(&total, &free, &used);
                print_memory_bar(used, total);
                break;
            }
            case 4:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
                break;
        }
        printf("\n");
    }
}

int main() {
    printf("Welcome to the RAM Usage Monitor!\n");
    show_interactive_menu();
    
    return 0;
}
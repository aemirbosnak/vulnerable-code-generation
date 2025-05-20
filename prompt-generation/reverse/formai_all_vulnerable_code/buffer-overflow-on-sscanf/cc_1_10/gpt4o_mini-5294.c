//GPT-4o-mini DATASET v1.0 Category: RAM usage monitor ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

void get_memory_usage(float *total, float *used, float *free) {
    FILE *fp = fopen("/proc/meminfo", "r");
    if (fp == NULL) {
        perror("Failed to open /proc/meminfo");
        return;
    }

    char line[256];
    while (fgets(line, sizeof(line), fp)) {
        if (sscanf(line, "MemTotal: %f kB", total) == 1) {
            *total /= 1024; // Convert to MB
        } else if (sscanf(line, "MemFree: %f kB", free) == 1) {
            *free /= 1024; // Convert to MB
        } else if (sscanf(line, "MemAvailable: %f kB", line) == 1) {
            *used = *total - *free; // Calculate used space
            *used /= 1024; // Convert to MB
            break;
        }
    }

    fclose(fp);
}

void display_memory_usage(float total, float used, float free) {
    printf("\n--- Memory Usage ---\n");
    printf("Total RAM: %.2f MB\n", total);
    printf("Used RAM:  %.2f MB\n", used);
    printf("Free RAM:  %.2f MB\n", free);
    printf("---------------------\n");
}

void puzzle_game(float total) {
    printf("Welcome to the Memory Maze!\n");
    printf("You have entered a realm of memory.\n");
    printf("Total available RAM is %.2f MB.\n", total);
    printf("But exploring this maze requires actions... and choices!\n");

    char response[10];
    while (1) {
        printf("\nDo you wish to continue exploring? (yes/no): ");
        scanf("%s", response);
        if (strcmp(response, "yes") == 0) {
            printf("You ventured deeper into the maze...\n");
            total -= 1.0; // Simulate memory usage decrease
            if (total <= 0) {
                printf("You've run out of memory!\n");
                break;
            }
        } else if (strcmp(response, "no") == 0) {
            printf("You chose to exit the maze... but did you utilize your memory wisely?\n");
            break;
        } else {
            printf("That choice is lost in the maze. Try 'yes' or 'no'.\n");
        }
    }
}

int main() {
    float total_memory = 0.0, used_memory = 0.0, free_memory = 0.0;

    get_memory_usage(&total_memory, &used_memory, &free_memory);

    display_memory_usage(total_memory, used_memory, free_memory);

    puzzle_game(total_memory);

    printf("Exiting the Memory Maze. Until next time...\n");
    return 0;
}
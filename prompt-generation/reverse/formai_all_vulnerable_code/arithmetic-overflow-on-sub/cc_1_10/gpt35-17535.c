//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>

#define MAX_CPU_USAGE 100
#define MAX_HISTORY_SIZE 10

typedef struct cpu_usage {
    int percentage;
    time_t timestamp;
} cpu_usage;

typedef struct cpu_history {
    cpu_usage usages[MAX_HISTORY_SIZE];
    int size;
} cpu_history;

void display_header() {
    system("clear"); // Clears the console
    printf("======== CPU USAGE MONITOR ========\n\n");
}

void display_usage(int usage) {
    printf("Current CPU Usage: %d%%\n\n", usage);
}

void display_history(cpu_history* history) {
    if (history->size == 0) {
        printf("No recent CPU usage history\n\n");
        return;
    }

    printf("Recent CPU Usage History:\n");

    for (int i = 0; i < history->size; i++) {
        time_t timestamp = history->usages[i].timestamp;
        char time_str[20];
        strftime(time_str, sizeof(time_str), "%m/%d/%Y %H:%M:%S", localtime(&timestamp));
        printf("%s - %d%%\n", time_str, history->usages[i].percentage);
    }

    printf("\n");
}

void add_usage_to_history(cpu_history* history, int usage) {
    if (history->size == MAX_HISTORY_SIZE) {
        for (int i = 0; i < MAX_HISTORY_SIZE - 1; i++) {
            history->usages[i] = history->usages[i+1];
        }
        history->size--;
    }

    cpu_usage new_usage;
    new_usage.percentage = usage;
    new_usage.timestamp = time(NULL);

    history->usages[history->size++] = new_usage;
}

int get_random_number(int min, int max) {
    return rand() % (max - min + 1) + min;
}

void simulate_cpu_usage(int duration, cpu_history* history) {
    time_t start_time = time(NULL);
    int current_usage = 0;

    while (time(NULL) - start_time < duration) {
        current_usage = get_random_number(0, MAX_CPU_USAGE);
        display_header();
        display_usage(current_usage);
        display_history(history);
        add_usage_to_history(history, current_usage);
        sleep(1);
    }
}

int main() {
    srand(time(NULL)); // Initializes random number generator
    cpu_history history = {0};

    int duration;
    printf("How long do you want to simulate CPU usage for (in seconds)? ");
    scanf("%d", &duration);

    simulate_cpu_usage(duration, &history);

    return 0;
}
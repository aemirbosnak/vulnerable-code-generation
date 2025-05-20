//GPT-4o-mini DATASET v1.0 Category: System event logger ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>

#define LOG_FILE "event_log.txt"
#define MAX_EVENT_LENGTH 256

void log_event(const char *event_message) {
    FILE *log_file = fopen(LOG_FILE, "a");
    if (log_file == NULL) {
        fprintf(stderr, "Error opening log file!\n");
        return;
    }
    
    time_t now;
    time(&now);
    struct tm *local_time = localtime(&now);
    
    char time_str[20];
    strftime(time_str, sizeof(time_str), "%Y-%m-%d %H:%M:%S", local_time);
    
    fprintf(log_file, "[%s] %s\n", time_str, event_message);
    fclose(log_file);
}

void simulate_events() {
    const char *events[] = {
        "System started successfully",
        "User logged in",
        "Data processed with ID: 1024",
        "User action: clicked on menu",
        "Error: file not found",
        "Database connection established",
        "User logged out",
        "System shut down initiated",
    };
    
    srand(time(NULL));  // Seed for random number generation

    for (int i = 0; i < 10; i++) {
        sleep(1);  // Simulate time delay between events
        
        // Randomly select an event
        const char *random_event = events[rand() % (sizeof(events) / sizeof(events[0]))];
        log_event(random_event);
    }
}

void read_logs() {
    FILE *log_file = fopen(LOG_FILE, "r");
    if (log_file == NULL) {
        fprintf(stderr, "No log file found!\n");
        return;
    }
    
    char line[MAX_EVENT_LENGTH];
    printf("=== Event Log ===\n");
    while (fgets(line, sizeof(line), log_file)) {
        printf("%s", line);
    }
    fclose(log_file);
}

void clear_log() {
    if (remove(LOG_FILE) == 0) {
        printf("Log file cleared successfully.\n");
    } else {
        fprintf(stderr, "Error clearing log file!\n");
    }
}

int main() {
    int choice;
    
    while (1) {
        printf("\n=== Event Logger Menu ===\n");
        printf("1. Simulate Events\n");
        printf("2. View Logs\n");
        printf("3. Clear Logs\n");
        printf("4. Exit\n");
        printf("Select an option: ");
        
        if (scanf("%d", &choice) != 1) {
            fprintf(stderr, "Invalid input!\n");
            while(getchar() != '\n'); // clear the input buffer
            continue;
        }
        
        switch (choice) {
            case 1:
                simulate_events();
                printf("Events simulated and logged.\n");
                break;
            case 2:
                read_logs();
                break;
            case 3:
                clear_log();
                break;
            case 4:
                printf("Exiting the logger.\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    
    return 0;
}
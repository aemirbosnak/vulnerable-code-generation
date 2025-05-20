//GPT-4o-mini DATASET v1.0 Category: System event logger ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#define LOG_FILE "event_log.txt"
#define BUFFER_SIZE 256

enum LogLevel {
    INFO,
    WARNING,
    ERROR
};

const char* log_level_strings[] = {
    "INFO",
    "WARNING",
    "ERROR"
};

void log_event(const char* message, enum LogLevel level) {
    FILE* file = fopen(LOG_FILE, "a");
    if (file == NULL) {
        perror("Failed to open log file");
        return;
    }

    time_t now = time(NULL);
    struct tm *tm_info = localtime(&now);
    char time_buffer[26];
    strftime(time_buffer, 26, "%Y-%m-%d %H:%M:%S", tm_info);

    const char* level_string = log_level_strings[level];
    
    char log_entry[BUFFER_SIZE];
    snprintf(log_entry, BUFFER_SIZE, "%s [%s] %s\n", time_buffer, level_string, message);
    
    fprintf(file, "%s", log_entry);
    fflush(file);
    fclose(file);

    // Also print to console
    printf("%s", log_entry);
}

void simulate_events() {
    const char* messages[] = {
        "User logged in.",
        "User logged out.",
        "File opened: example.txt",
        "File created: newfile.txt",
        "File deleted: oldfile.txt",
        "Disk space running low!",
        "Server is going down for maintenance.",
        "Unexpected error occurred in the system.",
        "Backup completed successfully.",
        "User has changed their password."
    };

    const enum LogLevel levels[] = {
        INFO,
        INFO,
        INFO,
        INFO,
        INFO,
        WARNING,
        INFO,
        ERROR,
        INFO,
        INFO
    };

    srand(time(NULL)); // Seed for randomness

    for (int i = 0; i < 10; ++i) {
        int random_index = rand() % 10; // Get a random index
        log_event(messages[random_index], levels[random_index]);
        sleep(1); // Sleep for a second to simulate time passing
    }
}

void show_menu() {
    printf("Welcome to the Event Logger!\n");
    printf("1. Start Logging Events\n");
    printf("2. Exit\n");
    printf("Choose an option: ");
}

int main(void) {
    int choice;
    do {
        show_menu();
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Starting event simulation...\n");
                simulate_events();
                break;
            case 2:
                printf("Exiting the logger. Goodbye!\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
        }
    } while (choice != 2);

    return 0;
}
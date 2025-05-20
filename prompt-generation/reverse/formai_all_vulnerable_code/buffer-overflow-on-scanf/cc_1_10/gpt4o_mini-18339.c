//GPT-4o-mini DATASET v1.0 Category: System event logger ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define LOG_FILE "event_log.txt"
#define MAX_EVENT_LEN 256

// Function to get the current time as a string
const char* get_current_time() {
    static char buffer[26];
    time_t timer;
    struct tm* tm_info;

    time(&timer);
    tm_info = localtime(&timer);
    strftime(buffer, 26, "%Y-%m-%d %H:%M:%S", tm_info);

    return buffer;
}

// Log levels
typedef enum {
    INFO,
    WARNING,
    ERROR
} LogLevel;

// Fun function to convert log levels to strings
const char* log_level_to_string(LogLevel level) {
    switch (level) {
        case INFO:    return "INFO";
        case WARNING: return "WARNING";
        case ERROR:   return "ERROR";
        default:      return "UNKNOWN";
    }
}

// Event logger function
void log_event(LogLevel level, const char* event_msg) {
    FILE* file = fopen(LOG_FILE, "a");
    if (file == NULL) {
        printf("Oops! Couldn't open the log file. Did we forget to eat? %s\n", event_msg);
        return;
    }

    fprintf(file, "[%s] [%s] %s\n", get_current_time(), log_level_to_string(level), event_msg);
    fclose(file);
}

// Show instructions
void show_instructions() {
    printf("Welcome to the Event Logger 3000!\n");
    printf("This program will log your events with flair!\n\n");
    printf("Instructions:\n");
    printf("1. Enter your event description.\n");
    printf("2. Choose a log level (1 = INFO, 2 = WARNING, 3 = ERROR).\n");
    printf("3. Watch as the magic happens!\n\n");
    printf("And remember: Logging is not just for wizards, it's for everyone! 🧙‍♂️✨\n");
}

// Main function
int main() {
    char event_msg[MAX_EVENT_LEN];
    int log_level_choice;

    show_instructions();

    while (1) {
        printf("Please enter your event description (or type 'exit' to quit): ");
        fgets(event_msg, MAX_EVENT_LEN, stdin);
        event_msg[strcspn(event_msg, "\n")] = 0; // Remove newline character

        if (strcmp(event_msg, "exit") == 0) {
            break;
        }

        printf("Choose a log level (1 = INFO, 2 = WARNING, 3 = ERROR): ");
        scanf("%d", &log_level_choice);
        getchar(); // consume newline

        if (log_level_choice < 1 || log_level_choice > 3) {
            printf("Invalid choice! Please pick a number between 1 and 3. Did you come out of a time machine?\n");
            continue;
        }

        // Log the event with the chosen log level
        log_event((LogLevel)(log_level_choice - 1), event_msg);
        printf("Logged: [%s] %s\n", log_level_to_string(log_level_choice - 1), event_msg);
    }

    printf("Thank you for using the Event Logger 3000! Goodbye! 🎉\n");
    return 0;
}
//GPT-4o-mini DATASET v1.0 Category: System event logger ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>

#define LOG_FILE "event_log.txt"
#define MAX_EVENT_LENGTH 256

typedef struct Event {
    char description[MAX_EVENT_LENGTH];
    time_t timestamp;
} Event;

void log_event(const char *event_description) {
    Event event;
    strncpy(event.description, event_description, MAX_EVENT_LENGTH - 1);
    event.description[MAX_EVENT_LENGTH - 1] = '\0';
    event.timestamp = time(NULL);

    FILE *file = fopen(LOG_FILE, "a");
    if (file == NULL) {
        perror("Error opening log file");
        return;
    }

    fprintf(file, "[%s] %s\n", ctime(&event.timestamp), event.description);
    fclose(file);
}

void display_log() {
    char line[512];
    FILE *file = fopen(LOG_FILE, "r");
    if (file == NULL) {
        perror("Error opening log file");
        return;
    }

    printf("\nEvent Log:\n=====================\n");
    while (fgets(line, sizeof(line), file)) {
        printf("%s", line);
    }
    fclose(file);
}

void generate_random_event() {
    const char *events[] = {
        "User logged in",
        "User logged out",
        "File created: important.txt",
        "File deleted: secret.pdf",
        "Configuration updated",
        "System rebooted",
        "User modified settings",
        "Service started: web_server",
        "Service stopped: db_service",
        "Network connection established",
        "Network connection lost",
        "Error report generated",
        "Backup completed successfully",
        "Update installed: version 2.1",
        "Virus scanner updated",
        "Malware detected: virus.exe",
        "System check passed",
        "Security alert triggered",
        "Disk space low on /home",
        "User account locked: unauthorised access",
        "Script executed: backup.sh"
    };

    int random_index = rand() % (sizeof(events) / sizeof(events[0]));
    log_event(events[random_index]);
}

void sleep_for_a_while(int seconds) {
    for (int i = 0; i < seconds; i++) {
        printf("Waiting... %d seconds left\n", seconds - i);
        sleep(1);
    }
}

int main() {
    srand(time(NULL)); // Seed the random number generator
    char command[10];
    
    printf("Welcome to the Mind-Bending Event Logger!\n");
    
    while (1) {
        printf("\nEnter a command (log, display, quit): ");
        scanf("%s", command);
        
        if (strcmp(command, "log") == 0) {
            generate_random_event();
            printf("Random event logged successfully!\n");
            sleep_for_a_while(2); // simulate waiting to increase tension
        } else if (strcmp(command, "display") == 0) {
            display_log();
            sleep_for_a_while(2);
        } else if (strcmp(command, "quit") == 0) {
            printf("Exiting the event logger. Stay safe in the chaos!\n");
            break;
        } else {
            printf("Unknown command. Type 'log' to log an event, 'display' to view logs, or 'quit' to exit.\n");
        }
    }

    return 0;
}
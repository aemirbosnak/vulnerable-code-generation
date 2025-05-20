//Falcon-180B DATASET v1.0 Category: System event logger ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LOG_FILE "event_log.txt"

typedef struct {
    time_t timestamp;
    int event_type;
    char message[1024];
} Event;

void log_event(int event_type, char* message) {
    Event event;
    event.event_type = event_type;
    strncpy(event.message, message, 1024);
    event.timestamp = time(NULL);

    FILE* log_file = fopen(LOG_FILE, "a");
    if (log_file == NULL) {
        printf("Error: could not open log file.\n");
        exit(1);
    }

    fprintf(log_file, "Event Type: %d\n", event_type);
    fprintf(log_file, "Message: %s\n", event.message);
    fprintf(log_file, "Timestamp: %s\n\n", ctime(&event.timestamp));

    fclose(log_file);
}

int main() {
    int choice;

    do {
        printf("Welcome to the Event Logger\n");
        printf("1. Log an event\n");
        printf("2. View log file\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter event type (1-10): ");
                int event_type;
                scanf("%d", &event_type);

                printf("Enter event message: ");
                char message[1024];
                scanf("%[^\n]", message);

                log_event(event_type, message);
                printf("Event logged successfully.\n");
                break;

            case 2:
                system("cat " LOG_FILE);
                break;

            case 3:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice.\n");
        }

    } while (choice!= 3);

    return 0;
}
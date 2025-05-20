//FormAI DATASET v1.0 Category: System event logger ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_LOG_ENTRIES 1000
#define MAX_MESSAGE_LENGTH 100

void log_event(char* event_message);

typedef struct {
    char message[MAX_MESSAGE_LENGTH];
    time_t timestamp;
} LogEntry;

LogEntry log_entry_array[MAX_LOG_ENTRIES];
int num_log_entries = 0;

int main() {
    char input_message[MAX_MESSAGE_LENGTH+1];
    memset(&input_message, 0, sizeof(input_message));

    printf("Welcome to the genius event logger!\n\n");

    while (1)
    {
        printf("Enter event message or 'exit' to quit: ");
        fgets(input_message, MAX_MESSAGE_LENGTH, stdin);
        input_message[strlen(input_message)-1] = '\0'; // remove newline character

        if (strcmp(input_message, "exit") == 0)
        {
            break;
        }
        else
        {
            log_event(input_message);
        }
    }

    printf("\nLog entries:\n");

    for (int i = 0; i < num_log_entries; i++)
    {
        char timestamp_str[25];
        strftime(timestamp_str, 25, "%Y-%m-%d %H:%M:%S", localtime(&log_entry_array[i].timestamp));
        printf("%s: %s\n", timestamp_str, log_entry_array[i].message);
    }

    return 0;
}

void log_event(char* event_message) {
    if (num_log_entries >= MAX_LOG_ENTRIES)
    {
        printf("Error: Maximum log entries exceeded!\n");
        return;
    }

    LogEntry new_entry;
    memset(&new_entry, 0, sizeof(new_entry));
    strncpy(new_entry.message, event_message, sizeof(new_entry.message) - 1);
    new_entry.timestamp = time(NULL);

    log_entry_array[num_log_entries] = new_entry;
    num_log_entries++;

    printf("Event logged: %s\n", event_message);
}
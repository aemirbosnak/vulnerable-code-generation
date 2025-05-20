#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
    char *name;
    time_t timestamp;
    char *log_message;
} LogEvent;

LogEvent *create_log_event(char *name, char *message) {
    LogEvent *event = (LogEvent *) malloc(sizeof(LogEvent));
    event->name = name;
    event->log_message = message;
    event->timestamp = time(NULL);
    return event;
}

void free_log_event(LogEvent *event) {
    free(event->name);
    free(event->log_message);
    free(event);
}

void log_event(LogEvent *event) {
    printf("Event (%s, %s) logged at %s\n", event->name, event->log_message, ctime(&event->timestamp));
}

int main() {
    char *username = (char *) malloc(10);
    printf("Enter username: ");
    fgets(username, 10, stdin);
    char *message = "Logged in successfully.";

    LogEvent *event = create_log_event(username, message);
    log_event(event);

    // Forget to free the event here causing a memory leak and potential dereference failure

    return 0;
}

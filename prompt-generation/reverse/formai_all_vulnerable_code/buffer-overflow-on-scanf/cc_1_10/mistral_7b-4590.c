//MISTRAL-7B DATASET v1.0 Category: System event logger ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_EVENTS 1000
#define EVENT_SIZE 256
#define LOG_FILE "event_log.txt"

typedef struct _event {
    char time[32];
    char description[EVENT_SIZE];
} event;

void log_event(char *description) {
    FILE *log_file;
    event new_event;
    time_t current_time;
    struct tm *time_info;

    log_file = fopen(LOG_FILE, "a");

    if (log_file == NULL) {
        printf("Could not open log file.\n");
        exit(1);
    }

    current_time = time(NULL);
    time_info = localtime(&current_time);

    strftime(new_event.time, sizeof(new_event.time), "%Y-%m-%d %H:%M:%S", time_info);

    strcpy(new_event.description, description);

    fwrite(&new_event, sizeof(event), 1, log_file);

    printf("Event logged: %s\n", description);

    fclose(log_file);
}

int main(void) {
    int i;

    for (i = 0; i < 10; i++) {
        char event_description[EVENT_SIZE];

        printf("Enter event %d description: ", i + 1);
        scanf("%s", event_description);

        log_event(event_description);
    }

    printf("\nEvent logging complete.\n");

    return 0;
}

#ifdef TEST
int main(void) {
    log_event("The universe was created.");
    log_event("First laws of physics were discovered.");
    log_event("Human civilization began.");
    log_event("Computers were invented.");
    log_event("C language was created.");
    log_event("This program was written.");
    log_event("You are reading this code.");

    return 0;
}
#endif
//Code Llama-13B DATASET v1.0 Category: System event logger ; Style: configurable
/*
 * A simple example of a C program that logs system events.
 *
 * The program is configured using a configuration file that specifies
 * the events to be logged and the output format.
 *
 * The program logs the events to a file, using a timestamp and the
 * event message.
 *
 * The configuration file format is:
 *
 * [event_type]
 * message_format
 *
 * Where event_type is the type of event to be logged (e.g. "error") and
 * message_format is the format of the event message (e.g. "Error: %s").
 *
 * The program logs the events to a file called "system_events.log" in the
 * current working directory.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_EVENT_TYPES 10
#define MAX_MESSAGE_LENGTH 100

typedef struct {
    char event_type[MAX_EVENT_TYPES];
    char message_format[MAX_MESSAGE_LENGTH];
} event_config_t;

event_config_t event_config[MAX_EVENT_TYPES];

void log_event(char *event_type, char *message) {
    time_t now;
    struct tm *timeinfo;
    char time_string[20];

    time(&now);
    timeinfo = localtime(&now);
    strftime(time_string, sizeof(time_string), "%Y-%m-%d %H:%M:%S", timeinfo);

    fprintf(stdout, "%s %s\n", time_string, message);

    FILE *log_file = fopen("system_events.log", "a");
    if (log_file == NULL) {
        perror("fopen");
        exit(EXIT_FAILURE);
    }

    fprintf(log_file, "%s %s\n", time_string, message);
    fclose(log_file);
}

int main(int argc, char *argv[]) {
    int i;

    // Load the configuration file
    FILE *config_file = fopen("event_config.txt", "r");
    if (config_file == NULL) {
        perror("fopen");
        exit(EXIT_FAILURE);
    }

    for (i = 0; i < MAX_EVENT_TYPES; i++) {
        fscanf(config_file, "%s %s\n", event_config[i].event_type, event_config[i].message_format);
    }
    fclose(config_file);

    // Log the events
    for (i = 0; i < MAX_EVENT_TYPES; i++) {
        log_event(event_config[i].event_type, event_config[i].message_format);
    }

    return 0;
}
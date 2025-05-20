//Falcon-180B DATASET v1.0 Category: System event logger ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_EVENTS 100
#define MAX_LOG_SIZE 1000
#define EVENT_TIME_FORMAT "%Y-%m-%d %H:%M:%S"

typedef struct {
    char event[MAX_EVENTS];
    char log[MAX_LOG_SIZE];
} event_t;

void event_logger(event_t* logger) {
    FILE* log_file = fopen("event_log.txt", "a");
    if (log_file == NULL) {
        printf("Error: Could not open event log file.\n");
        exit(1);
    }

    fprintf(log_file, "-----------------------------\n");
    fprintf(log_file, "Event: %s\n", logger->event);
    fprintf(log_file, "Log:\n%s\n", logger->log);

    fclose(log_file);
}

int main() {
    event_t logger;
    char input[MAX_LOG_SIZE];
    int input_size = 0;
    char event[MAX_EVENTS];
    int event_size = 0;
    char log[MAX_LOG_SIZE];
    int log_size = 0;

    memset(&logger, 0, sizeof(event_t));

    printf("Enter event name (max %d characters): ", MAX_EVENTS - 1);
    scanf("%s", event);
    event_size = strlen(event);

    printf("Enter log message (max %d characters): ", MAX_LOG_SIZE - 1);
    scanf("%[^\n]s", input);
    input_size = strlen(input);

    if (event_size > MAX_EVENTS || input_size > MAX_LOG_SIZE) {
        printf("Error: Input too long.\n");
        exit(1);
    }

    strcpy(logger.event, event);
    strcpy(logger.log, input);

    event_logger(&logger);

    return 0;
}
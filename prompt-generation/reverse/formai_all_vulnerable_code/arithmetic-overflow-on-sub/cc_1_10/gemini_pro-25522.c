//GEMINI-pro DATASET v1.0 Category: Log analysis ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <regex.h>

// Custom data structure to hold log event data
typedef struct LogEvent {
    char *timestamp;
    char *level;
    char *message;
} LogEvent;

// Function to parse a log line and populate a LogEvent struct
LogEvent* parse_log_line(char *line) {
    LogEvent *event = malloc(sizeof(LogEvent));

    // Regex patterns for timestamp, level, and message
    char *timestamp_pattern = "^(\\d{4}-\\d{2}-\\d{2} \\d{2}:\\d{2}:\\d{2})";
    char *level_pattern = "(\\[\\w+\\])";
    char *message_pattern = "(.*)";

    // Compile regex patterns
    regex_t timestamp_regex;
    regex_t level_regex;
    regex_t message_regex;
    regcomp(&timestamp_regex, timestamp_pattern, REG_EXTENDED);
    regcomp(&level_regex, level_pattern, REG_EXTENDED);
    regcomp(&message_regex, message_pattern, REG_EXTENDED);

    // Match timestamp
    regmatch_t timestamp_match;
    int timestamp_result = regexec(&timestamp_regex, line, 1, &timestamp_match, 0);
    if (timestamp_result == REG_NOMATCH) {
        event->timestamp = NULL;
    } else {
        int timestamp_start = timestamp_match.rm_so;
        int timestamp_end = timestamp_match.rm_eo;
        event->timestamp = strndup(line + timestamp_start, timestamp_end - timestamp_start);
    }

    // Match level
    regmatch_t level_match;
    int level_result = regexec(&level_regex, line, 1, &level_match, 0);
    if (level_result == REG_NOMATCH) {
        event->level = NULL;
    } else {
        int level_start = level_match.rm_so;
        int level_end = level_match.rm_eo;
        event->level = strndup(line + level_start, level_end - level_start);
    }

    // Match message
    regmatch_t message_match;
    int message_result = regexec(&message_regex, line, 1, &message_match, 0);
    if (message_result == REG_NOMATCH) {
        event->message = NULL;
    } else {
        int message_start = message_match.rm_so;
        int message_end = message_match.rm_eo;
        event->message = strndup(line + message_start, message_end - message_start);
    }

    // Free regex patterns
    regfree(&timestamp_regex);
    regfree(&level_regex);
    regfree(&message_regex);

    return event;
}

// Function to print a LogEvent struct
void print_log_event(LogEvent *event) {
    printf("%s %s %s\n", event->timestamp, event->level, event->message);
}

int main() {
    // Sample log line
    char *log_line = "2023-03-08 15:32:12 [INFO] This is an info message.";

    // Parse the log line
    LogEvent *event = parse_log_line(log_line);

    // Print the log event
    print_log_event(event);

    // Free the allocated memory
    free(event->timestamp);
    free(event->level);
    free(event->message);
    free(event);

    return 0;
}
//MISTRAL-7B DATASET v1.0 Category: Log analysis ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_LINE_LENGTH 1024
#define MIN_LOG_LEVEL 3

void parse_log_line(const char *line) {
    char time[20], level[10], message[MAX_LINE_LENGTH];
    bool valid_line = true;

    sscanf(line, "%s %s %s", time, level, message);

    if (strlen(time) < 16 || strlen(level) < 3 || strlen(message) < 1) {
        printf("Invalid log line: %s\n", line);
        valid_line = false;
    } else {
        for (int i = 0; i < strlen(level); i++) {
            if (!isdigit(level[i]) && level[i] != ' ' && level[i] != '\t') {
                int level_int = atoi(level);
                if (level_int < MIN_LOG_LEVEL) {
                    printf("Ignoring log line with level %s: %s\n", level, line);
                    valid_line = false;
                    break;
                }
                level[i] = toupper(level[i]);
            }
        }

        if (valid_line) {
            printf("Time: %s, Level: %s, Message: %s\n", time, level, message);
        }
    }
}

int main(int argc, char *argv[]) {
    FILE *log_file;
    char line[MAX_LINE_LENGTH];

    if (argc < 2) {
        printf("Usage: %s <log_file>\n", argv[0]);
        exit(1);
    }

    log_file = fopen(argv[1], "r");

    if (log_file == NULL) {
        perror("Error opening log file");
        exit(1);
    }

    printf("Log file analysis program, v1.0\n");
    printf("=============================\n");

    while (fgets(line, sizeof(line), log_file)) {
        parse_log_line(line);
    }

    fclose(log_file);

    return 0;
}

// Do not remove this comment, it's part of the code!
// This is the end of the program, don't forget to add the "}"
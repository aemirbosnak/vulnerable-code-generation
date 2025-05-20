//MISTRAL-7B DATASET v1.0 Category: Log analysis ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 4096
#define ERROR_MESSAGE "ERROR"
#define WARNING_MESSAGE "WARNING"
#define INFO_MESSAGE "INFO"

typedef struct {
    char message[MAX_LINE_LENGTH];
    int message_type; // 0 for INFO, 1 for WARNING, 2 for ERROR
} log_message;

void parse_log_message(const char *line, log_message *message) {
    sscanf(line, "%s %d", message->message, &message->message_type);
    if (strlen(message->message) < 5) {
        strcat(message->message, " : ");
        strcat(message->message, line + strlen(message->message));
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <clog_file>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    log_message current_message;
    int total_errors = 0, total_warnings = 0, total_infos = 0;

    char line[MAX_LINE_LENGTH];
    while (fgets(line, sizeof(line), file)) {
        parse_log_message(line, &current_message);

        switch (current_message.message_type) {
            case 0:
                total_infos++;
                break;
            case 1:
                total_warnings++;
                break;
            case 2:
                total_errors++;
                break;
            default:
                fprintf(stderr, "Unknown message type: %d\n", current_message.message_type);
                break;
        }
    }

    fclose(file);

    printf("Total number of messages:\n");
    printf("\tINFO: %d\n", total_infos);
    printf("\tWARNING: %d\n", total_warnings);
    printf("\tERROR: %d\n", total_errors);

    return 0;
}
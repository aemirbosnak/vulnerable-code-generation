//GPT-4o-mini DATASET v1.0 Category: Log analysis ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define LOG_FILE "logfile.txt"
#define MAX_LINE_LENGTH 256

void write_log(const char *level, const char *message) {
    FILE *file = fopen(LOG_FILE, "a");
    if (file == NULL) {
        perror("Unable to open log file");
        exit(EXIT_FAILURE);
    }

    time_t now = time(NULL);
    struct tm *tm_info = localtime(&now);
    char time_buffer[26];
    strftime(time_buffer, sizeof(time_buffer), "%Y-%m-%d %H:%M:%S", tm_info);

    fprintf(file, "[%s] [%s] %s\n", time_buffer, level, message);
    fclose(file);
}

void read_logs() {
    char buffer[MAX_LINE_LENGTH];
    FILE *file = fopen(LOG_FILE, "r");
    if (file == NULL) {
        perror("Unable to open log file");
        exit(EXIT_FAILURE);
    }

    printf("=== Log File Content ===\n");
    while (fgets(buffer, MAX_LINE_LENGTH, file) != NULL) {
        printf("%s", buffer);
    }
    fclose(file);
}

void filter_logs(const char *level) {
    char buffer[MAX_LINE_LENGTH];
    FILE *file = fopen(LOG_FILE, "r");
    if (file == NULL) {
        perror("Unable to open log file");
        exit(EXIT_FAILURE);
    }

    printf("=== Filtered Logs [%s] ===\n", level);
    while (fgets(buffer, MAX_LINE_LENGTH, file) != NULL) {
        if (strstr(buffer, level) != NULL) {
            printf("%s", buffer);
        }
    }
    fclose(file);
}

int main() {
    char command[20];
    char message[200];

    while (1) {
        printf("Enter log command (write/read/filter/exit): ");
        scanf("%s", command);

        if (strcmp(command, "write") == 0) {
            char level[10];
            printf("Enter log level (INFO, WARNING, ERROR): ");
            scanf("%s", level);

            printf("Enter log message: ");
            scanf(" %[^\n]", message);  // Taking input with spaces
            write_log(level, message);
            printf("Log entry written.\n");

        } else if (strcmp(command, "read") == 0) {
            read_logs();

        } else if (strcmp(command, "filter") == 0) {
            char level[10];
            printf("Enter log level to filter: ");
            scanf("%s", level);
            filter_logs(level);

        } else if (strcmp(command, "exit") == 0) {
            printf("Exiting logger.\n");
            break;

        } else {
            printf("Unknown command. Please try again.\n");
        }
    }

    return 0;
}
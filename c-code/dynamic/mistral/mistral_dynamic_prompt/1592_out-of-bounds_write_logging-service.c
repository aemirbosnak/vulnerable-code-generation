#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define BUFFER_SIZE 1024
#define LOG_FILE "log.txt"

typedef struct {
    char time[20];
    char level[10];
    char message[BUFFER_SIZE];
} LogEntry;

void log_entry(LogEntry *entry) {
    FILE *fp = fopen(LOG_FILE, "a");
    fprintf(fp, "%s %s %s\n", entry->time, entry->level, entry->message);
    fclose(fp);
}

int main() {
    char date[20], level[10], message[BUFFER_SIZE];
    time_t now = time(NULL);
    struct tm *tm_info = localtime(&now);
    strftime(date, 20, "%Y-%m-%d %H:%M:%S", tm_info);

    printf("Enter log level (DEBUG, INFO, WARNING, ERROR): ");
    scanf("%s", level);
    printf("Enter log message: ");
    fgets(message, BUFFER_SIZE, stdin);

    LogEntry entry = {date, level, message};
    if (strlen(message) + strlen(entry.level) + strlen(entry.time) > BUFFER_SIZE) {
        // In a real-world scenario, this should be handled with proper exception/error management.
        printf("Warning: Message and log level combined exceed buffer size.\n");
    } else {
        log_entry(&entry);
        printf("Log entry successfully recorded.\n");
    }

    return 0;
}

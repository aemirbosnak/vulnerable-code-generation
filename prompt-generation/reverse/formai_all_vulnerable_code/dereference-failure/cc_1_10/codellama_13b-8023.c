//Code Llama-13B DATASET v1.0 Category: System event logger ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LOG_LENGTH 256
#define MAX_FILE_NAME_LENGTH 64

typedef struct {
    char log_level;
    char log_message[MAX_LOG_LENGTH];
} LogMessage;

void log_message(LogMessage *msg) {
    FILE *log_file;
    char file_name[MAX_FILE_NAME_LENGTH];
    time_t rawtime;
    struct tm *timeinfo;

    // Get current time
    time(&rawtime);
    timeinfo = localtime(&rawtime);

    // Create log file name
    snprintf(file_name, MAX_FILE_NAME_LENGTH, "log_%d-%d-%d.txt", timeinfo->tm_year + 1900, timeinfo->tm_mon + 1, timeinfo->tm_mday);

    // Open log file
    log_file = fopen(file_name, "a");
    if (log_file == NULL) {
        printf("Error opening log file\n");
        return;
    }

    // Write log message to file
    fprintf(log_file, "[%c] %s\n", msg->log_level, msg->log_message);

    // Close log file
    fclose(log_file);
}

int main() {
    LogMessage msg;

    // Initialize log message
    msg.log_level = 'I';
    strcpy(msg.log_message, "Hello, World!");

    // Log message
    log_message(&msg);

    return 0;
}
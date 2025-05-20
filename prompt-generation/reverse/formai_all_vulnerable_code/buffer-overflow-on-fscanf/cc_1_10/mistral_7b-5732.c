//MISTRAL-7B DATASET v1.0 Category: System event logger ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LOG_LEVEL 5
#define LOG_FILE_NAME_LENGTH 100

typedef struct {
    int level;
    char fileName[LOG_FILE_NAME_LENGTH];
} LoggerConfig;

void log_message(int level, const char *message) {
    FILE *file;
    LoggerConfig config = {level, "event_log.txt"};

    if (level > config.level)
        return;

    if ((file = fopen(config.fileName, "a")) == NULL) {
        fprintf(stderr, "Error opening file: %s\n", config.fileName);
        return;
    }

    time_t now;
    char time_string[30];

    time(&now);
    strftime(time_string, sizeof(time_string), "%Y-%m-%d %H:%M:%S", localtime(&now));

    fprintf(file, "[%s] [Level %d] %s\n", time_string, level, message);
    fclose(file);
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <config_file>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        fprintf(stderr, "Error opening config file: %s\n", argv[1]);
        return 1;
    }

    LoggerConfig config;
    fscanf(file, "%d\n", &config.level);
    fgets(config.fileName, sizeof(config.fileName), file);
    config.fileName[strcspn(config.fileName, "\n")] = '\0';
    fclose(file);

    const char *events[] = {
        "[INFO] Event occurred.\n",
        "[WARNING] Potential issue.\n",
        "[ERROR] An error occurred.\n",
        "[CRITICAL] System failure.\n",
        "[ALERT] Urgent attention required.\n"
    };

    for (int i = 0; i < 5; i++) {
        log_message(i, events[i]);
    }

    return 0;
}
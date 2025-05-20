#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Logger {
    char *name;
    FILE *logFile;
} Logger;

Logger createLogger(char *loggerName, char *logFilePath) {
    Logger logger = {.name = strdup(loggerName), .logFile = fopen(logFilePath, "w")};
    return logger;
}

void logMessage(Logger *logger, char *message) {
    fprintf(logger->logFile, "%s\n", message);
}

void freeLogger(Logger *logger) {
    free(logger->name);
    fclose(logger->logFile);
    free(logger);
}

int main() {
    Logger logger1 = createLogger("Console", NULL);
    Logger logger2 = createLogger("File", "./test.log");

    logMessage(&logger1, "Starting service...");
    logMessage(&logger2, "Service started");

    // Use logger1 after freeing its memory
    freeLogger(&logger1);
    logMessage(&logger1, "This should cause a crash");

    logMessage(&logger2, "Service performing tasks...");

    return 0;
}

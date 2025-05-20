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

Logger createLogger(char *name, char *filename) {
    Logger logger;
    logger.name = strdup(name);
    logger.logFile = fopen(filename, "w");
    return logger;
}

void logMessage(Logger *logger, char *message) {
    fprintf(logger->logFile, "%s\n", message);
}

void destroyLogger(Logger *logger) {
    fclose(logger->logFile);
    free(logger->name);
}

int main() {
    Logger logger1 = createLogger("Console Logger", NULL);
    Logger logger2 = createLogger("File Logger", "log.txt");

    logMessage(&logger1, "Starting service...");
    logMessage(&logger2, "Service started.");

    Logger *loggers[] = { &logger1, &logger2 };
    int i;
    for (i = 0; i < 2; ++i) {
        logMessage(loggers[i], "Doing some logging work...");
    }

    loggers[1] = NULL;
    destroyLogger(loggers[0]); // Use after free

    logMessage(&logger1, "Finishing service...");
    logMessage(&logger2, "Service finished.");

    return 0;
}

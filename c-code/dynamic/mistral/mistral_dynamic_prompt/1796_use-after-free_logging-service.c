#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *name;
    FILE *file;
    size_t size;
    char *buffer;
} Log;

Log *create_logger(const char *filename) {
    Log *logger = malloc(sizeof(Log));
    logger->name = strdup(filename);
    logger->file = fopen(filename, "a+");
    logger->size = 1024;
    logger->buffer = malloc(logger->size);
    return logger;
}

void write_log(Log *logger, const char *message) {
    fseek(logger->file, 0, SEEK_END);
    strncat(logger->buffer, message, logger->size - strlen(logger->buffer) - 1);
    fwrite(logger->buffer, strlen(logger->buffer), 1, logger->file);
    free(logger->buffer);
    logger->buffer = NULL;
    logger->buffer = realloc(logger->buffer, logger->size * 2);
}

void destroy_logger(Log *logger) {
    free(logger->name);
    fclose(logger->file);
    free(logger->buffer);
    free(logger);
}

int main() {
    Log *logger1 = create_logger("log1.txt");
    Log *logger2 = create_logger("log2.txt");

    char *message1 = "This is the first log entry";
    write_log(logger1, message1);

    char *message2 = "This is the second log entry";
    write_log(logger2, message2);

    write_log(logger1, message2); // Use after free

    destroy_logger(logger1);

    write_log(logger2, NULL); // Write NULL to the log

    destroy_logger(logger2);

    return 0;
}

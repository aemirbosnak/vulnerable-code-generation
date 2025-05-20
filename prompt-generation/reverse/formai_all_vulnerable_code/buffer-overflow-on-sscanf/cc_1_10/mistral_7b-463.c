//MISTRAL-7B DATASET v1.0 Category: Error handling ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

typedef struct {
    char filepath[100];
    int line_number;
} error_context_t;

void custom_error_handler(const char *message, const error_context_t *error_context) {
    fprintf(stderr, "%s at %s:%d: %s\n", message, error_context->filepath, error_context->line_number, strerror(errno));
}

int read_config_file(const char *filepath, int *variable1, int *variable2) {
    FILE *config_file = fopen(filepath, "r");
    if (config_file == NULL) {
        error_context_t error_context = {filepath, __LINE__};
        custom_error_handler("Failed to open the file.", &error_context);
        return 1;
    }

    char line[100];
    int value1, value2;
    while (fgets(line, sizeof(line), config_file) != NULL) {
        sscanf(line, "%d %d", &value1, &value2);
        if (sscanf(line, "%d %d", &value1, &value2) != 2) {
            error_context_t error_context = {filepath, __LINE__};
            custom_error_handler("Invalid format in the line.", &error_context);
            fclose(config_file);
            return 1;
        }

        if (variable1)
            *variable1 = value1;
        if (variable2)
            *variable2 = value2;
    }

    fclose(config_file);
    return 0;
}

int main() {
    int var1, var2;
    if (read_config_file("config.txt", &var1, &var2) != 0) {
        custom_error_handler("Error while reading the config file.", NULL);
        return 1;
    }

    printf("Read config file successfully.\nVariable 1: %d, Variable 2: %d.\n", var1, var2);
    return 0;
}
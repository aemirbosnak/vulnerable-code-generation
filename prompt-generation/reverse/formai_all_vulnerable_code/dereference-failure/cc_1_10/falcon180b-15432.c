//Falcon-180B DATASET v1.0 Category: Error handling ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

typedef struct {
    char *message;
    int code;
} error_t;

void error_init(error_t *error) {
    error->message = NULL;
    error->code = 0;
}

void error_set(error_t *error, int code, const char *message) {
    if (error->message!= NULL) {
        free(error->message);
    }
    error->message = strdup(message);
    error->code = code;
}

const char *error_message(error_t *error) {
    return error->message;
}

int error_code(error_t *error) {
    return error->code;
}

void error_clear(error_t *error) {
    if (error->message!= NULL) {
        free(error->message);
    }
    error->message = NULL;
    error->code = 0;
}

int main() {
    error_t error;
    error_init(&error);

    FILE *file = fopen("nonexistent_file.txt", "r");
    if (file == NULL) {
        error_set(&error, errno, "Failed to open file");
        printf("Error: %s\n", error_message(&error));
        return 1;
    }

    char buffer[1024];
    size_t bytes_read = fread(buffer, sizeof(char), sizeof(buffer), file);
    if (bytes_read!= sizeof(buffer)) {
        error_set(&error, 0, "Failed to read file");
        printf("Error: %s\n", error_message(&error));
        return 1;
    }

    fclose(file);

    return 0;
}
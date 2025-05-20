//Falcon-180B DATASET v1.0 Category: Error handling ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <stdarg.h>

typedef struct {
    int code;
    char *message;
} error_t;

#define ERR_OK 0
#define ERR_UNKNOWN 1
#define ERR_INVALID_ARGUMENT 2
#define ERR_MEMORY_ERROR 3
#define ERR_FILE_ERROR 4
#define ERR_IO_ERROR 5
#define ERR_SYSTEM_ERROR 6

int error_code = ERR_OK;
char error_message[256] = {0};

void set_error(int code, const char *format,...) {
    va_list args;
    va_start(args, format);
    vsnprintf(error_message, sizeof(error_message), format, args);
    va_end(args);
    error_code = code;
}

const char *get_error_message() {
    return error_message;
}

int get_error_code() {
    return error_code;
}

void clear_error() {
    error_code = ERR_OK;
    memset(error_message, 0, sizeof(error_message));
}

int main() {
    FILE *file;
    char *buffer;
    size_t size;

    // Test file I/O error
    file = fopen("nonexistent.txt", "r");
    if (file == NULL) {
        set_error(ERR_FILE_ERROR, "Failed to open file: %s", strerror(errno));
        return 1;
    }
    fclose(file);

    // Test memory allocation error
    buffer = malloc(1000000000);
    if (buffer == NULL) {
        set_error(ERR_MEMORY_ERROR, "Failed to allocate memory");
        return 1;
    }
    free(buffer);

    // Test invalid argument error
    if (strcmp("invalid", "argument")!= 0) {
        set_error(ERR_INVALID_ARGUMENT, "Invalid argument");
        return 1;
    }

    // Test system error
    if (getuid()!= 0) {
        set_error(ERR_SYSTEM_ERROR, "Must be run as root");
        return 1;
    }

    clear_error();
    printf("No errors occurred.\n");
    return 0;
}
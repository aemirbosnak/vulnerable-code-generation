//GEMINI-pro DATASET v1.0 Category: Error handling ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef enum {
    SUCCESS,
    INVALID_ARGUMENT,
    OUT_OF_MEMORY,
    IO_ERROR
} ErrorType;

typedef struct {
    ErrorType error_type;
    const char *error_message;
} Error;

static Error create_error(ErrorType error_type, const char *error_message) {
    Error error;
    error.error_type = error_type;
    error.error_message = error_message;
    return error;
}

static void print_error(const Error *error) {
    switch (error->error_type) {
        case SUCCESS:
            printf("No error\n");
            break;
        case INVALID_ARGUMENT:
            printf("Invalid argument: %s\n", error->error_message);
            break;
        case OUT_OF_MEMORY:
            printf("Out of memory\n");
            break;
        case IO_ERROR:
            printf("IO error: %s\n", error->error_message);
            break;
    }
}

int main(int argc, char **argv) {
    Error error;

    if (argc != 2) {
        error = create_error(INVALID_ARGUMENT, "Invalid number of arguments");
        print_error(&error);
        return EXIT_FAILURE;
    }

    int number;
    if (sscanf(argv[1], "%d", &number) != 1) {
        error = create_error(INVALID_ARGUMENT, "Invalid integer argument");
        print_error(&error);
        return EXIT_FAILURE;
    }

    if (number < 0) {
        error = create_error(INVALID_ARGUMENT, "Negative number argument");
        print_error(&error);
        return EXIT_FAILURE;
    }

    int *array = malloc(number * sizeof(int));
    if (array == NULL) {
        error = create_error(OUT_OF_MEMORY, "Out of memory");
        print_error(&error);
        return EXIT_FAILURE;
    }

    for (int i = 0; i < number; i++) {
        array[i] = i;
    }

    FILE *file = fopen("output.txt", "w");
    if (file == NULL) {
        error = create_error(IO_ERROR, "Could not open output file");
        print_error(&error);
        free(array);
        return EXIT_FAILURE;
    }

    for (int i = 0; i < number; i++) {
        fprintf(file, "%d\n", array[i]);
    }

    fclose(file);
    free(array);

    return EXIT_SUCCESS;
}
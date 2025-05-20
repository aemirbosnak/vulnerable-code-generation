//Falcon-180B DATASET v1.0 Category: Error handling ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1000
#define MAX_ERROR_LENGTH 100

typedef struct {
    char *error_message;
    int line_number;
} Error;

void add_error(Error *errors, int count, char *error_message, int line_number) {
    if (count >= MAX_ERROR_LENGTH) {
        fprintf(stderr, "Error: too many errors\n");
        exit(1);
    }

    errors[count].error_message = strdup(error_message);
    errors[count].line_number = line_number;

    count++;
}

void print_errors(Error *errors, int count) {
    if (count == 0) {
        printf("No errors found\n");
        return;
    }

    printf("Errors found:\n");
    for (int i = 0; i < count; i++) {
        printf("%d: %s\n", errors[i].line_number, errors[i].error_message);
    }
}

int main() {
    // Example code to parse
    char *example_code =
        "int main() {\n"
        "    printf(\"Hello, world!\\n\");\n"
        "    return 0;\n"
        "}\n";

    // Initialize error list
    Error errors[MAX_ERROR_LENGTH];
    int error_count = 0;

    // Parse the code
    char *line = strtok(example_code, "\n");
    int line_number = 1;

    while (line!= NULL) {
        // Check for syntax errors
        if (strlen(line) > MAX_LINE_LENGTH) {
            char error_message[MAX_ERROR_LENGTH];
            snprintf(error_message, MAX_ERROR_LENGTH, "Line %d is too long", line_number);
            add_error(errors, error_count, error_message, line_number);
        }

        line_number++;
        line = strtok(NULL, "\n");
    }

    // Print any errors found
    print_errors(errors, error_count);

    return 0;
}
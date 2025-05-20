//Falcon-180B DATASET v1.0 Category: Error handling ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

typedef enum {
    NO_ERROR = 0,
    SYNTAX_ERROR,
    RUNTIME_ERROR
} error_t;

static error_t current_error = NO_ERROR;

static void print_error_message(error_t error) {
    switch(error) {
        case NO_ERROR:
            printf("No error\n");
            break;
        case SYNTAX_ERROR:
            printf("Syntax error\n");
            break;
        case RUNTIME_ERROR:
            printf("Runtime error\n");
            break;
    }
}

static void set_error(error_t error) {
    current_error = error;
}

static int is_error() {
    return current_error!= NO_ERROR;
}

static void clear_error() {
    current_error = NO_ERROR;
}

static void handle_error() {
    if(is_error()) {
        print_error_message(current_error);
        exit(1);
    }
}

static char* read_line(FILE* file) {
    char* line = malloc(MAX_LINE_LENGTH);
    if(fgets(line, MAX_LINE_LENGTH, file) == NULL) {
        set_error(RUNTIME_ERROR);
        return NULL;
    }
    return line;
}

static int parse_integer(char* str) {
    int value = 0;
    char* endptr = NULL;
    if(sscanf(str, "%d", &value)!= 1) {
        set_error(SYNTAX_ERROR);
        return -1;
    }
    return value;
}

int main() {
    FILE* file = fopen("example.txt", "r");
    if(file == NULL) {
        set_error(RUNTIME_ERROR);
        return 1;
    }

    char* line = read_line(file);
    if(line == NULL) {
        return 1;
    }

    int a = parse_integer(line);
    if(a == -1) {
        return 1;
    }

    int b = parse_integer(read_line(file));
    if(b == -1) {
        return 1;
    }

    int c = a + b;
    printf("Result: %d\n", c);

    clear_error();
    return 0;
}
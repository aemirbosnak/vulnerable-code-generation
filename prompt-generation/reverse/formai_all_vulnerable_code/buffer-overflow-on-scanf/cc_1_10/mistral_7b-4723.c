//MISTRAL-7B DATASET v1.0 Category: Error handling ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define MAX_LINE_LENGTH 1024

typedef struct error {
    int line_number;
    char error_message[MAX_LINE_LENGTH];
    struct error *next;
} Error;

Error *error_list = NULL;

void die(const char *message) {
    Error *error = (Error *) malloc(sizeof(Error));

    strncpy(error->error_message, message, MAX_LINE_LENGTH);
    error->line_number = __LINE__;
    error->next = error_list;
    error_list = error;

    fputs("Error: ", stderr);
    perror(": ");
    fputs(error->error_message, stderr);
    exit(EXIT_FAILURE);
}

void read_file(FILE *file) {
    char line[MAX_LINE_LENGTH];
    int i, j, number;
    char operator;

    while (fgets(line, MAX_LINE_LENGTH, file)) {
        sscanf(line, "%d%c%d%c", &number, &operator, &number);

        if (feof(file)) {
            break;
        }

        if (operator != '+' && operator != '-') {
            die("Invalid operator.");
        }

        for (i = 0; i < number; i++) {
            if (scanf("%d", &j) != 1) {
                die("Invalid number.");
            }

            number += j;
        }

        printf("Line %d: %d %c %d = %d\n", __LINE__, number, operator, number, number);
    }
}

int main(int argc, char *argv[]) {
    FILE *file;

    if (argc != 2) {
        die("Usage: ./program <filename>");
    }

    file = fopen(argv[1], "r");

    if (file == NULL) {
        die("Could not open file.");
    }

    read_file(file);

    fclose(file);

    Error *error = error_list;

    while (error != NULL) {
        printf("\nError on line %d: %s\n", error->line_number, error->error_message);
        error = error->next;
    }

    free(error_list);

    return EXIT_SUCCESS;
}
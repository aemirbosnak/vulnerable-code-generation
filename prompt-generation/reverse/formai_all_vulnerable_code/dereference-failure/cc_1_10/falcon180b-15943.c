//Falcon-180B DATASET v1.0 Category: Error handling ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#define MAX_LINE_LENGTH 1024
#define MAX_LINE_NUMBER 1000

int line_number = 0;
char current_line[MAX_LINE_LENGTH];

void print_error(const char* message) {
    fprintf(stderr, "Error: %s\n", message);
    exit(EXIT_FAILURE);
}

void print_line_number() {
    fprintf(stderr, "Error on line %d: ", line_number);
}

void read_file(FILE* file) {
    char ch;
    while ((ch = fgetc(file))!= EOF) {
        if (line_number >= MAX_LINE_NUMBER) {
            print_error("Too many lines in file");
        }
        if (strlen(current_line) >= MAX_LINE_LENGTH) {
            print_error("Line too long");
        }
        current_line[strlen(current_line)] = ch;
        line_number++;
    }
}

int main(int argc, char* argv[]) {
    if (argc!= 2) {
        print_error("Invalid number of arguments");
    }

    FILE* file = fopen(argv[1], "r");
    if (file == NULL) {
        if (errno == ENOENT) {
            print_error("File not found");
        } else {
            print_error("Error opening file");
        }
    } else {
        read_file(file);
        fclose(file);
    }

    return EXIT_SUCCESS;
}
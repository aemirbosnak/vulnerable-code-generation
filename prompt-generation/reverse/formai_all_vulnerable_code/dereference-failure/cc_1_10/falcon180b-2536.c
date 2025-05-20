//Falcon-180B DATASET v1.0 Category: HTML beautifier ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

// Function to remove leading and trailing whitespace from a string
char* trim(char* str) {
    int start = 0;
    int end = strlen(str) - 1;
    while (isspace(str[start])) {
        start++;
    }
    while (isspace(str[end])) {
        end--;
    }
    str[end+1] = '\0';
    return str;
}

// Function to remove leading and trailing whitespace from a line of text
char* process_line(char* line) {
    char* result = trim(line);
    if (result[0] == '\0') {
        return result;
    }
    char* new_line = malloc(MAX_LINE_LENGTH);
    snprintf(new_line, MAX_LINE_LENGTH, "<p>%s</p>", result);
    free(result);
    return new_line;
}

// Function to write an HTML header
void write_header(FILE* out) {
    fprintf(out, "<!DOCTYPE html>\n");
    fprintf(out, "<html>\n");
    fprintf(out, "<head>\n");
    fprintf(out, "<title>Beautified HTML</title>\n");
    fprintf(out, "</head>\n");
    fprintf(out, "<body>\n");
}

// Function to write an HTML footer
void write_footer(FILE* out) {
    fprintf(out, "</body>\n");
    fprintf(out, "</html>\n");
}

// Function to write a string to a file
void write_string(FILE* out, char* str) {
    fprintf(out, "%s", str);
}

// Function to write a line of text to a file
void write_line(FILE* out, char* line) {
    write_string(out, process_line(line));
    write_string(out, "\n");
}

// Function to read a line of text from a file
char* read_line(FILE* in) {
    char* line = NULL;
    size_t len = 0;
    ssize_t read;
    while ((read = getline(&line, &len, in))!= -1) {
        if (read > 0) {
            break;
        }
    }
    return line;
}

int main(int argc, char** argv) {
    if (argc!= 3) {
        fprintf(stderr, "Usage: %s input.txt output.html\n", argv[0]);
        return 1;
    }
    FILE* in = fopen(argv[1], "r");
    if (in == NULL) {
        fprintf(stderr, "Could not open input file: %s\n", argv[1]);
        return 1;
    }
    FILE* out = fopen(argv[2], "w");
    if (out == NULL) {
        fprintf(stderr, "Could not open output file: %s\n", argv[2]);
        return 1;
    }
    write_header(out);
    char* line;
    while ((line = read_line(in))!= NULL) {
        write_line(out, line);
    }
    write_footer(out);
    fclose(in);
    fclose(out);
    return 0;
}
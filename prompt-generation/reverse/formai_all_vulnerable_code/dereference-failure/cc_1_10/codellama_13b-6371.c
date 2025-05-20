//Code Llama-13B DATASET v1.0 Category: HTML beautifier ; Style: inquisitive
/*
 * HTML Beautifier Example Program
 *
 * This program takes an HTML file as input and outputs a beautified version of the HTML.
 * The beautified HTML is indented and formatted in a consistent manner.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 80
#define INDENT_SIZE 4

typedef struct {
    char *buffer;
    size_t capacity;
    size_t length;
} StringBuffer;

void init_string_buffer(StringBuffer *buffer, size_t capacity) {
    buffer->buffer = malloc(capacity);
    buffer->capacity = capacity;
    buffer->length = 0;
}

void destroy_string_buffer(StringBuffer *buffer) {
    free(buffer->buffer);
    buffer->buffer = NULL;
    buffer->capacity = 0;
    buffer->length = 0;
}

void append_string_buffer(StringBuffer *buffer, const char *str) {
    size_t len = strlen(str);
    if (buffer->length + len >= buffer->capacity) {
        buffer->capacity *= 2;
        buffer->buffer = realloc(buffer->buffer, buffer->capacity);
    }
    strcpy(buffer->buffer + buffer->length, str);
    buffer->length += len;
}

void beautify_html(const char *html, size_t html_len, StringBuffer *buffer) {
    size_t indent_level = 0;
    size_t line_length = 0;

    for (size_t i = 0; i < html_len; i++) {
        char c = html[i];
        if (c == '<') {
            indent_level++;
            append_string_buffer(buffer, "\n");
            for (size_t j = 0; j < indent_level * INDENT_SIZE; j++) {
                append_string_buffer(buffer, " ");
            }
        } else if (c == '>') {
            indent_level--;
        } else if (c == '\n') {
            line_length = 0;
        } else if (c != ' ') {
            line_length++;
            if (line_length > MAX_LINE_LENGTH) {
                append_string_buffer(buffer, "\n");
                for (size_t j = 0; j < indent_level * INDENT_SIZE; j++) {
                    append_string_buffer(buffer, " ");
                }
                line_length = 0;
            }
        }
        append_string_buffer(buffer, &c);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <html_file>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (!file) {
        fprintf(stderr, "Error opening file: %s\n", argv[1]);
        return 1;
    }

    fseek(file, 0, SEEK_END);
    size_t file_size = ftell(file);
    rewind(file);

    char *html = malloc(file_size);
    if (!html) {
        fprintf(stderr, "Error allocating memory for HTML file\n");
        return 1;
    }

    size_t read = fread(html, 1, file_size, file);
    if (read != file_size) {
        fprintf(stderr, "Error reading HTML file\n");
        return 1;
    }

    StringBuffer buffer;
    init_string_buffer(&buffer, file_size);

    beautify_html(html, file_size, &buffer);

    printf("%s", buffer.buffer);

    destroy_string_buffer(&buffer);

    fclose(file);
    free(html);

    return 0;
}
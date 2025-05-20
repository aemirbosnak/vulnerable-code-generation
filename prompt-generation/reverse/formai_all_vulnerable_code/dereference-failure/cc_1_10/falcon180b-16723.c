//Falcon-180B DATASET v1.0 Category: RAM usage monitor ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_NUM_LINES 100

typedef struct {
    char *line;
    size_t length;
} Line;

typedef struct {
    Line *lines;
    size_t num_lines;
} Buffer;

Buffer *create_buffer() {
    Buffer *buffer = malloc(sizeof(Buffer));
    if (buffer == NULL) {
        printf("Error: Failed to create buffer\n");
        exit(1);
    }
    buffer->lines = NULL;
    buffer->num_lines = 0;
    return buffer;
}

void destroy_buffer(Buffer *buffer) {
    if (buffer == NULL) {
        return;
    }
    for (size_t i = 0; i < buffer->num_lines; i++) {
        free(buffer->lines[i].line);
    }
    free(buffer->lines);
    free(buffer);
}

void add_line(Buffer *buffer, const char *line) {
    if (buffer->num_lines >= MAX_NUM_LINES) {
        printf("Error: Buffer is full\n");
        return;
    }
    Line *new_line = malloc(sizeof(Line));
    if (new_line == NULL) {
        printf("Error: Failed to add line\n");
        return;
    }
    new_line->line = strdup(line);
    new_line->length = strlen(line);
    buffer->lines = realloc(buffer->lines, sizeof(Line) * (buffer->num_lines + 1));
    if (buffer->lines == NULL) {
        printf("Error: Failed to realloc buffer\n");
        free(new_line->line);
        free(new_line);
        return;
    }
    buffer->lines[buffer->num_lines] = *new_line;
    buffer->num_lines++;
}

void print_buffer(const Buffer *buffer) {
    for (size_t i = 0; i < buffer->num_lines; i++) {
        printf("%s\n", buffer->lines[i].line);
    }
}

size_t get_buffer_size(const Buffer *buffer) {
    return buffer->num_lines;
}

int main() {
    Buffer *buffer = create_buffer();
    if (buffer == NULL) {
        return 1;
    }
    char input[MAX_LINE_LENGTH];
    while (fgets(input, MAX_LINE_LENGTH, stdin)!= NULL) {
        add_line(buffer, input);
    }
    print_buffer(buffer);
    destroy_buffer(buffer);
    return 0;
}
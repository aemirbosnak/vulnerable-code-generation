//GEMINI-pro DATASET v1.0 Category: HTML beautifier ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

typedef struct {
  char *line;
  int length;
  int capacity;
} Line;

typedef struct {
  Line *lines;
  int num_lines;
  int capacity;
} Buffer;

void buffer_init(Buffer *buffer) {
  buffer->lines = NULL;
  buffer->num_lines = 0;
  buffer->capacity = 0;
}

void buffer_free(Buffer *buffer) {
  for (int i = 0; i < buffer->num_lines; i++) {
    free(buffer->lines[i].line);
  }
  free(buffer->lines);
}

void buffer_add_line(Buffer *buffer, char *line) {
  if (buffer->num_lines == buffer->capacity) {
    buffer->capacity *= 2;
    buffer->lines = realloc(buffer->lines, buffer->capacity * sizeof(Line));
  }
  buffer->lines[buffer->num_lines].line = line;
  buffer->lines[buffer->num_lines].length = strlen(line);
  buffer->lines[buffer->num_lines].capacity = buffer->lines[buffer->num_lines].length + 1;
  buffer->num_lines++;
}

char *buffer_to_string(Buffer *buffer) {
  char *string = malloc(buffer->num_lines * MAX_LINE_LENGTH);
  int offset = 0;
  for (int i = 0; i < buffer->num_lines; i++) {
    memcpy(string + offset, buffer->lines[i].line, buffer->lines[i].length);
    offset += buffer->lines[i].length;
  }
  string[offset] = '\0';
  return string;
}

int main() {
  Buffer buffer;
  buffer_init(&buffer);

  FILE *file = fopen("input.html", "r");
  if (file == NULL) {
    perror("fopen");
    return EXIT_FAILURE;
  }

  char line[MAX_LINE_LENGTH];
  while (fgets(line, MAX_LINE_LENGTH, file) != NULL) {
    buffer_add_line(&buffer, strdup(line));
  }

  fclose(file);

  char *html = buffer_to_string(&buffer);
  printf("%s", html);
  free(html);

  buffer_free(&buffer);

  return EXIT_SUCCESS;
}